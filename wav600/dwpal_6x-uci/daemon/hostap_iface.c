/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

#include "hostap_iface.h"
#include "dwpal_daemon.h"
#include "dwpal_ext.h"
#include "linked_list.h"
#include "logs.h"

#include <stdlib.h>

#if defined YOCTO
#include <slibc/string.h>
#else
#include <stddef.h>
#include "libsafec/safe_str_lib.h"
#include "libsafec/safe_mem_lib.h"
#endif

#ifdef YOCTO
// Under YOCTO/DRKB dwpal daemon automatically adds hostapd interfaces to bridge
#define DWPALD_ADD_TO_BRIDGE
#endif

#ifdef DWPALD_ADD_TO_BRIDGE
#include <uci_wrapper.h>
#endif

typedef struct _hostap_event {
	char op_code[64];
	l_list *registered_stations;
} hostap_event;

typedef struct _hostap_extra_info {
	uint16_t msg_ofs;
	uint16_t msg_len;
	char data[];
} hostap_extra_info;

static iface_manager *__manager = NULL;

#ifdef DWPALD_ADD_TO_BRIDGE

static int bridgeInterfaceAdd(const char *radioName, const char *vapName)
{
	char cmd[128] = "";

	if (!strncmp(radioName, vapName, DWPAL_VAP_NAME_STRING_LENGTH))
		return DWPAL_SUCCESS;

	sprintf_s(cmd, sizeof(cmd), "sysevent set if_%s-status ready", vapName);
	LOG(0, "DWPALD (bridge add): vapName='%s'; cmd='%s'", vapName, cmd);
	if (uci_converter_system(cmd) != RETURN_OK) {
		ELOG("failed to perform 'sysevent set if_%s-status ready'", vapName);
		return DWPAL_FAILURE;
	}

	return DWPAL_SUCCESS;
}

/* Set interface MTU if network config file has an MTU set for this interface */
static int setMtuIfRequired(const char *radioName, const char *vapName)
{
	int    uciVapIndex, res;
	int    mtu = 1500;
	char   cmd[128] = "";
	char   path[MAX_UCI_BUF_LEN] = "";
	char   mtu_value[MAX_UCI_BUF_LEN] = "";

	if (!strncmp(radioName, vapName, DWPAL_VAP_NAME_STRING_LENGTH))
		return DWPAL_SUCCESS;

	if (uci_getIndexFromInterface(vapName, &uciVapIndex)) {
		ELOG("%s: failed to get interface index", vapName);
		return DWPAL_FAILURE;
	}

	res = sprintf_s(path, sizeof(path), "network.default_radio%d.mtu", uciVapIndex);
	if (res <= 0) {
		ELOG("failed sprintf_s(). UCI index=%d param=mtu", uciVapIndex);
		return DWPAL_FAILURE;
	}

	if (uci_converter_get(path, mtu_value, sizeof(mtu_value)) == RETURN_OK)
	{
		res = sscanf_s(mtu_value, "%d", &mtu);
		if (res != 1){
			ELOG("Invalid MTU (%s) for interface %s", mtu_value, vapName);
			return DWPAL_FAILURE;
		}
		if (mtu < 68 || mtu > 65535){
			ELOG("Invalid MTU (%d) for interface %s", mtu, vapName);
			return DWPAL_FAILURE;
		}

		sprintf_s(cmd, sizeof(cmd), "ip link set dev %s mtu %d", vapName, mtu);
		LOG(0, "DWPALD (set mtu): vapName='%s'; cmd='%s'", vapName, cmd);
		if (uci_converter_system(cmd) != RETURN_OK) {
			DLOG("failed to perform 'ip link set dev %s mtu %d' ==> probably 'AP-ENABLED' was not issued yet", vapName, mtu);
			return DWPAL_FAILURE;
		}
	}
	return DWPAL_SUCCESS;
}

static void hostap_process_interface_reconnected(const char* ifname, char* msg, size_t len)
{
	LOG(2, "Reconnected: vap=%s, msg=%s", ifname, msg);
	char *vaps = strstr(msg, "vaps= ");
	char *vap_name, *next_token;
	size_t strmax = len;

	if (!vaps) return;
	vaps += (sizeof("vaps= ")-1);

	/* Need to optimize access to UCI DB */
	if (uci_converter_alloc_local_uci_context()) {
		ELOG("alloc local UCI context returned err!");
		return;
	}

	/* Loop over all vaps in list */
	vap_name = strtok_s(vaps, &strmax, " ", &next_token);
	while (vap_name) {
		DLOG("interfaceName='%s', radioName='%s'", vap_name, ifname);

		/* Add VAP interface to bridge and change MTU size */
		do {
			if (bridgeInterfaceAdd(ifname, vap_name) != DWPAL_SUCCESS) {
				ELOG("bridgeInterfaceAdd() returned error\n");
				break;
			}

			if (setMtuIfRequired(ifname, vap_name) != DWPAL_SUCCESS) {
				ELOG("setMtuIfRequired() returned error\n");
				break;
			}
		} while (0);

		vap_name = strtok_s(NULL, &strmax, " ", &next_token);
	}

	uci_converter_free_local_uci_context();
}

static inline void hostap_process_interface_connected(const char* ifname, char* msg, size_t len)
{
	LOG(2, "Connected: vap=%s, msg=%s", ifname, msg);
	return hostap_process_interface_reconnected(ifname, msg, len);
}

static void hostap_process_ap_enabled(const char* ifname, char* msg, size_t len)
{
	char vapName[DWPAL_VAP_NAME_STRING_LENGTH + 1] = "";
	size_t numOfValidArgs[2];
	FieldsToParse fieldsToParse[] = {
		{ NULL    /*opCode */, &numOfValidArgs[0],  DWPAL_STR_PARAM, NULL, 0 },
		{ vapName /*VAPName*/, &numOfValidArgs[1],  DWPAL_STR_PARAM, NULL, sizeof(vapName) },
		{ NULL, NULL, DWPAL_NUM_OF_PARSING_TYPES, NULL, 0 }
	};

	LOG(2, "AP-ENABLED: vap=%s, msg=%s", ifname, msg);
	if (DWPAL_FAILURE == dwpal_string_to_struct_parse(msg, len, fieldsToParse, sizeof(vapName))) {
		ELOG("dwpal_string_to_struct_parse() ERROR ==> Abort!");
		return;
	}

	if (bridgeInterfaceAdd(ifname, vapName) != DWPAL_SUCCESS) {
		ELOG("bridgeInterfaceAdd() returned error\n");
		return;
	}

	if (setMtuIfRequired(ifname, vapName) != DWPAL_SUCCESS) {
		ELOG("setMtuIfRequired() returned error\n");
		return;
	}
}

#else // DWPALD_ADD_TO_BRIDGE

static inline void hostap_process_interface_reconnected(const char* ifname, char* msg, size_t len) {
	(void)ifname; (void)msg; (void)len;
}
static inline void hostap_process_interface_connected(const char* ifname, char* msg, size_t len) {
	(void)ifname; (void)msg; (void)len;
}
static inline void hostap_process_ap_enabled(const char* ifname, char* msg, size_t len) {
	(void)ifname; (void)msg; (void)len;
}

#endif // DWPALD_ADD_TO_BRIDGE

/****/

static int hostap_execute_command(wv_ipserver *ipserv, wv_ipc_msg *cmd,
				  wv_ipstation *ipsta, uint8_t seq_num)
{
	wv_ipc_msg *response;
	char *reply;
	size_t reply_len = 4096 * 4;
	dwpald_header resp_hdr = { 0 }, cmd_hdr;
	DWPAL_Ret dpal_ret;
	wv_ipc_ret ipc_ret;
	char vap_name[IFNAMSIZ + 1] = { 0 };
	char *cmd_data = wave_ipc_msg_get_data(cmd);
	size_t cmd_data_size = wave_ipc_msg_get_size(cmd);

	LOG(2, "executing hostapd command from serializer ctx");

	dwpald_header_pop(cmd, &cmd_hdr);

	if (cmd_data_size < cmd_hdr.header[2] ||
	    cmd_hdr.header[2] >= sizeof(vap_name) ||
	    !cmd_data || !cmd_hdr.header[2]) {
		BUG("cmd_data_size=%zu, hdr[2]=%hhu, cmd_data=%p",
		    cmd_data_size, cmd_hdr.header[2], cmd_data);
		return 1;
	}

	memcpy_s(vap_name, sizeof(vap_name), cmd_data, cmd_hdr.header[2]);
	cmd_data += cmd_hdr.header[2];
	cmd_data_size -= cmd_hdr.header[2];

	if ((response = wave_ipc_msg_alloc()) == NULL)
		return 1;

	if (wave_ipc_msg_reserve_data(response, reply_len + 1)) {
		BUG("failed to reserve data for hostap response");
		wave_ipc_msg_put(response);
		return 1;
	}

	if ((reply = wave_ipc_msg_get_data(response)) == NULL) {
		BUG("get data returned NULL");
		wave_ipc_msg_put(response);
		return 1;
	}

	WV_TIMER_START
	dpal_ret = dwpal_ext_hostap_cmd_send(vap_name, cmd_data, NULL,
					     reply, &reply_len);
	WV_TIMER_ACTION_TOOK_LONGER_THAN(0, 200, "vap_name: '%s' cmd: '%s' dpal_ret=%d",
					 vap_name, cmd_data, dpal_ret)
	if (dpal_ret == DWPAL_SUCCESS) {
		wave_ipc_msg_shrink_data(response, reply_len + 1);
		reply[reply_len] = '\0';
	} else {
		ELOG("dwpal returned err on hostap command %s from sta %s (dpal_ret=%d)",
		     cmd_data, wave_ipcs_sta_name(ipsta), dpal_ret);
		wave_ipc_msg_shrink_data(response, 0);
	}

	resp_hdr.header[0] = DWPALD_CMD_RESP;
	resp_hdr.header[1] = DWPALD_IF_TYPE_HOSTAP;
	resp_hdr.header[2] = dpal_ret;
	dwpald_header_push(response, &resp_hdr);

	ipc_ret = wave_ipcs_send_response_to(ipserv, ipsta, seq_num, response, 0);
	wave_ipc_msg_put(response);
	if (ipc_ret != WAVE_IPC_SUCCESS) {
		ELOG("send response to returned err (ret=%d)", ipc_ret);
		return 1;
	}

	return 0;
}

static int dwpal_ext_hostap_event_callback(char *vap_name, char *op_code,
					   char *msg, size_t msg_len)
{
	wv_ipc_msg *e_msg;
	dwpald_header hdr = { 0 };
	char *event_data;
	size_t total_msg_size = 0, reserve_size;
	uint16_t msg_len_16bit;
	hostap_extra_info *extra_info = NULL;

	if (vap_name == NULL || op_code == NULL || (msg == NULL && msg_len))
		return DWPAL_FAILURE;

	LOG(2, "received hostap event '%s' from iface '%s' (len=%zu)",
	    op_code, vap_name, msg_len);

	e_msg = wave_ipc_msg_alloc();
	if (e_msg == NULL)
		return DWPAL_FAILURE;

	if (msg && msg_len)
		msg_len++; /* for '\0' */
	msg_len_16bit = (uint16_t)msg_len;
	if ((size_t)msg_len_16bit != msg_len)
		return DWPAL_FAILURE;

	hdr.header[0] = DWPALD_EVENT;
	hdr.header[1] = DWPALD_IF_TYPE_HOSTAP;
	hdr.header[2] = strlen(vap_name);
	hdr.header[3] = strlen(op_code);
	wv_aligned_16_bit_assign(&hdr.header[4], msg_len_16bit);
	dwpald_header_push(e_msg, &hdr);

	reserve_size = hdr.header[2] + hdr.header[3] + msg_len_16bit;
	if (wave_ipc_msg_reserve_data(e_msg, reserve_size) != WAVE_IPC_SUCCESS) {
		ELOG("could not reserve %zu data in ipc msg", reserve_size);
		wave_ipc_msg_put(e_msg);
		return DWPAL_FAILURE;
	}

	if ((event_data = wave_ipc_msg_get_data(e_msg)) == NULL) {
		wave_ipc_msg_put(e_msg);
		return DWPAL_FAILURE;
	}

	memcpy_s(event_data, reserve_size, vap_name, hdr.header[2]);
	total_msg_size += hdr.header[2];

	memcpy_s(event_data + total_msg_size, reserve_size - total_msg_size,
			op_code, hdr.header[3]);
	total_msg_size += hdr.header[3];

	if (msg && msg_len_16bit) {
		memcpy_s(event_data + total_msg_size, reserve_size - total_msg_size,
			msg, msg_len_16bit - 1);
		event_data[total_msg_size + (msg_len_16bit - 1)] = '\0';
	}

	if (reserve_size != total_msg_size + msg_len_16bit) {
		BUG("resrv = %zu, placed 0 at %zu", reserve_size, (total_msg_size + msg_len_16bit));
	}

	wave_ipcs_push_event_header(e_msg);

	/* Put opcode and msg to extra info */
	extra_info = (hostap_extra_info*)calloc(sizeof(hostap_extra_info) +
		sizeof(char) * (hdr.header[3] + 1 + msg_len_16bit + 1), 1);
	if (!extra_info) {
		wave_ipc_msg_put(e_msg);
		return DWPAL_FAILURE;
	}

	extra_info->msg_ofs = hdr.header[3] + 1;
	extra_info->msg_len = msg_len_16bit;
	strncpy_s(extra_info->data, hdr.header[3] + 1, op_code, hdr.header[3]);
	if (msg_len_16bit && msg) {
		strncpy_s(extra_info->data + extra_info->msg_ofs, msg_len_16bit + 1, msg, msg_len_16bit);
	}

	iface_manager_event_received(__manager, e_msg, vap_name, IFNAMSIZ + 1, extra_info);

	return DWPAL_SUCCESS;
}

static int hostap_iface_attach(iface_manager *manager, char *ifname, uint8_t *state)
{
	DWPAL_Ret dwpal_ret;

	__manager = manager;

	dwpal_ret = dwpal_ext_hostap_interface_attach(ifname, dwpal_ext_hostap_event_callback);
	if (dwpal_ret == DWPAL_FAILURE) {
		BUG("attaching to hostap iface '%s' via dwpal_ext failed", ifname);
		return 1;
	} else if (dwpal_ret != DWPAL_SUCCESS) {
		LOG(1, "attached to hostap iface '%s' via dwpal_ext but it's disconnected", ifname);
		*state = INTERFACE_DWPAL_STATE_DISCONNECTED;
	} else {
		LOG(1, "successfully attached to hostap iface '%s' via dwpal_ext", ifname);
		*state = INTERFACE_DWPAL_STATE_CONNECTED;
	}

	return 0;
}

static int hostap_iface_detach(char *ifname)
{
	LOG(1, "detaching from hostap iface '%s' via dwpal_ext", ifname);
	dwpal_ext_hostap_interface_detach(ifname);
	return 0;
}

static int hostap_register_sta_to_event(l_list *events, wv_ipstation *ipsta,
					const char *op_code)
{
	hostap_event *event = NULL;

	list_foreach_start(events, tmp, hostap_event)
		if (!strncmp(op_code, tmp->op_code, sizeof(tmp->op_code))) {
			event = tmp;
			break;
		}
	list_foreach_end

	if (event) {
		list_remove(event->registered_stations, ipsta);
		list_push_front(event->registered_stations, ipsta);
		LOG(2, "registered %s to existing hostap event %s",
		    wave_ipcs_sta_name(ipsta), op_code);
	} else {
		event = (hostap_event*)malloc(sizeof(hostap_event));
		if (!event)
			return 1;

		if (!(event->registered_stations = list_init())) {
			free(event);
			return 1;
		}

		strncpy_s(event->op_code, sizeof(event->op_code),
			  op_code, sizeof(event->op_code) - 1);
		list_push_front(event->registered_stations, ipsta);
		list_push_front(events, event);
		LOG(2, "registered %s to newly created hostap event %s",
		    wave_ipcs_sta_name(ipsta), op_code);
	}

	return 0;
}

static int hostap_register_sta_to_events(l_list *events, wv_ipstation *ipsta,
					 const char *reg_str, size_t len)
{
	size_t i = 0;
	char op_code[64];

	while (i < len && reg_str[i]) {
		uint8_t op_code_len = reg_str[i];

		if (op_code_len >= sizeof(op_code)) {
			ELOG("op_len(%hhu) >= %zu", op_code_len, sizeof(op_code));
			return 1;
		}

		memcpy_s(op_code, sizeof(op_code), &reg_str[i + 1], op_code_len);
		op_code[op_code_len] = '\0';
		LOG(2, "register req for %s by %s", op_code, wave_ipcs_sta_name(ipsta));
		if (hostap_register_sta_to_event(events, ipsta, op_code)) {
			ELOG("failed to register sta %s to event %s (len=%hhu)",
			     wave_ipcs_sta_name(ipsta), op_code, op_code_len);
			return 1;
		}

		i += 1 + op_code_len;
	}

	return 0;
}

static int hostap_unregister_sta_from_events(l_list *events, wv_ipstation *ipsta)
{
	list_foreach_start(events, event, hostap_event)
		list_remove(event->registered_stations, ipsta);
		if (!list_get_size(event->registered_stations)) {
			list_foreach_remove_current_entry();
			LOG(2, "hostap event %s is deleted due to no stations left",
			    event->op_code);

			list_free(event->registered_stations);
			free(event);
		}
	list_foreach_end

	return 0;
}

static int hostap_send_event(wv_ipserver *ipserv, char *ifname, wv_ipc_msg *event,
			     void *info, l_list *events, uint8_t *state)
{
	hostap_extra_info *extra_info = (hostap_extra_info*)info;
	char *op_code = extra_info->data;
	char *msg = extra_info->data + extra_info->msg_ofs;
	hostap_event *hap_event = NULL;

	if (!strncmp(op_code, "INTERFACE_RECONNECTED_OK",
		     sizeof("INTERFACE_RECONNECTED_OK") - 1)) {
		*state = INTERFACE_DWPAL_STATE_CONNECTED;
		LOG(1, "state of iface %s changed to %d", ifname, *state);
		hostap_process_interface_reconnected(ifname, msg, extra_info->msg_len);
	} else if (!strncmp(op_code, "INTERFACE_DISCONNECTED",
			    sizeof("INTERFACE_DISCONNECTED") - 1)) {
		*state = INTERFACE_DWPAL_STATE_DISCONNECTED;
		LOG(1, "state of iface %s changed to %d", ifname, *state);
	} else if (!strncmp(op_code, "INTERFACE_CONNECTED_OK",
			    sizeof("INTERFACE_CONNECTED_OK") - 1)) {
		/* dwpald client will generate this event */
		*state = INTERFACE_DWPAL_STATE_CONNECTED;
		hostap_process_interface_connected(ifname, msg, extra_info->msg_len);
		return 0;
	}
#ifdef DWPALD_ADD_TO_BRIDGE
	else if (!strncmp(op_code, "AP-ENABLED", sizeof("AP-ENABLED") - 1)) {
		hostap_process_ap_enabled(ifname, msg, extra_info->msg_len);
	}
#endif

	list_foreach_start(events, tmp, hostap_event)
		if (!strncmp(op_code, tmp->op_code, sizeof(tmp->op_code))) {
			hap_event = tmp;
			break;
		}
	list_foreach_end

	if (hap_event == NULL) {
		LOG(2, "no station registered to '%s' event", op_code);
		return 0;
	}

	list_foreach_start(hap_event->registered_stations, ipsta, wv_ipstation)
		wv_ipc_ret ret;

		ret = wave_ipcs_send_to(ipserv, event, ipsta);
		if (ret != WAVE_IPC_SUCCESS) {
			LOG(2, "failed to send this event to %s",
				wave_ipcs_sta_name(ipsta));
		}
	list_foreach_end

	return 0;
}

static manager_apis apis = {
	.execute_command = hostap_execute_command,
	.iface_attach = hostap_iface_attach,
	.iface_detach = hostap_iface_detach,
	.register_sta_to_events = hostap_register_sta_to_events,
	.unregister_sta_from_events = hostap_unregister_sta_from_events,
	.send_event = hostap_send_event,
};

manager_apis * hostap_man_apis_get(void)
{
	return &apis;
}
