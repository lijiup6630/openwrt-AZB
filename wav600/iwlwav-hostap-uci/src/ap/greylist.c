/*
 * hostapd / RADIUS Greylist Access Control
 * Copyright 2021 MaxLinear
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#define __USE_XOPEN
#define _GNU_SOURCE
#include <time.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "ap_config.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_drv_ops.h"
#include "greylist.h"

int hostapd_ctrl_iface_acl_add_mac(struct mac_acl_entry **acl, int *num,
					  const char *cmd);
int hostapd_ctrl_iface_acl_del_mac(struct mac_acl_entry **acl, int *num,
					  const char *txtaddr);

/* Timeout value from the client association time for deleting the
 * mac entry from greylist_mac.txt, and deleting the mac from access
 * control list of all greylist enabled vaps. */
#define GREYLIST_TIMEOUT_IN_SECONDS (24 * 60 * 60)

#define GREYLIST_MAX_NUM_OF_RECORDS 128

#define INDEX_MAX_LEN 5

#define LOC_SH_FILE(fd, iface) \
    flock(fd, LOCK_SH); \
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: got shared file lock\n", __func__, iface);

#define LOC_EX_FILE(fd, iface) \
    flock(fd, LOCK_EX); \
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: got exclusive file lock\n", __func__, iface);

#define UNLOC_FILE(fd, iface) \
    flock(fd, LOCK_UN); \
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: released file lock\n", __func__, iface);


struct greylist_data {
	struct hapd_interfaces *interfaces;
	char txtaddr[TXT_MAC_ADDR_LEN];
};

static struct hapd_interfaces *g_interfaces;

/******************
 * BEGIN HELP FUNCTIONS
 ******************/

/**
 * greylist_log_to_file - Add the log for telemetry usage
 */
static void greylist_log_to_file(char *filepath, char *fmt, ...)
{
    FILE *fp = NULL;
    va_list args;

    fp = fopen(filepath, "a+");
    if (fp == NULL) {
        return;
    }

    va_start(args, fmt);
    vfprintf(fp, fmt, args);
    va_end(args);

    fflush(fp);
    fclose(fp);
}

#if 0
/**
 * greylist_get_index_from_ifname - get index (rpc index) from ifname to store in greylist file
 */
static int greylist_get_index_from_ifname(const char *ifname, char *index, int size)
{
    FILE *fp;
    const char *cmd_template = "uci show | grep %s | head -n 1 | cut -d \".\" -f 2 | xargs -I _CONS_ uci show wireless._CONS_ | grep rpc_index | awk -F\\' '{printf($2+1)}'";
    char cmd[256] = {0};
	if (strnlen_s(ifname, IFNAMSIZ) > 10) {
		wpa_printf(MSG_ERROR, "GREYLIST: %s: ifname %s failed\n",__func__, ifname);
		return -1;
	}

    sprintf_s(cmd, 255, cmd_template, ifname);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: popen failed\n",__func__);
        return -1;
    }

    if (fgets(index, size, fp) == NULL) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: can not read index from command %s\n", __func__, cmd);
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return 0;
}
#endif

/**
 * greylist_delete_line - Delete the mac entry in memory
 */
static size_t greylist_delete_line(char *buffer, size_t size, const char *txtaddr)
{
	char *p = buffer, *q, *end = buffer + size;
	char *mac_in_buf;

	while (p < end) {
		q = p;
		while (q < end && *q != ' ') ++q; //skip date
		++q;

		while (q < end && *q != ' ') ++q; //skip time
			if (++q >= end)
				break;

		mac_in_buf = q;
        while (q < end && *q != ' ') ++q; //skip mac
        ++q;

		while (q < end && *q != '\n') ++q; //skip index
        ++q; //q now points to beginning of next line or end

		if (os_memcmp(mac_in_buf, txtaddr, TXT_MAC_ADDR_LEN - 1) == 0) { //found
            size_t line_size = q - p;
            size_t rest_size = buffer + size -  q;
			os_memmove(p, q, rest_size);
			return size - line_size;
        }
		 p = q;
    }

    return size;
}

/*
 * greylist_delete_from_file - Delete the mac entry from /nvram/greylist_mac.txt
 */
static void greylist_delete_from_file(struct hapd_interfaces *interfaces, const char *txtaddr)
{
	struct stat st;
    int fd;
    char *buffer = NULL;
    struct hostapd_bss_config *conf = interfaces->iface[0]->bss[0]->conf;

    wpa_printf(MSG_DEBUG, "GREYLIST: %s delete %s from %s\n", __func__, txtaddr, conf->greylist_file);

    fd = open(conf->greylist_file, O_RDWR);
    if (fd < 0) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: fail to open %s\n", __func__, conf->greylist_file);
        return;
    }

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: trying to get file lock\n", __func__, conf->iface);
    LOC_EX_FILE(fd, conf->iface);

    if (fstat(fd, &st) != 0) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: fail to get size of %s\n",	__func__, conf->greylist_file);
        UNLOC_FILE(fd, conf->iface);
        close(fd);
        return;
    }

    buffer = os_malloc(st.st_size);
    if (!buffer) {
        wpa_printf(MSG_ERROR,"GREYLIST: %s: fail to allocate buffer\n", __func__);
        UNLOC_FILE(fd, conf->iface);
        close(fd);
        return;
    }

    if (read(fd, buffer, st.st_size) == st.st_size) {
        size_t new_size;

        new_size = greylist_delete_line(buffer, st.st_size, txtaddr);

        if (ftruncate(fd, 0) == 0) {
            if (write(fd, buffer, new_size) != new_size) {
                wpa_printf(MSG_ERROR,"GREYLIST: %s: fail to write to %s\n", __func__, conf->greylist_file);
            }
        }
        else {
            wpa_printf(MSG_ERROR,"GREYLIST: %s: fail to truncate %s\n", __func__, conf->greylist_file);
        }
    }
    else {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: fail to read %s\n", __func__, conf->greylist_file);
    }

    fsync(fd);
    UNLOC_FILE(fd, conf->iface);
    close(fd);
	os_free(buffer);
}


/**
 * greylist_timeout - Timeout handler to remove client's mac from greylist
 *
 * The function is used to delete the mac entry from greylist_mac.txt and
 * delete the mac from access control list of all greylist enabled vaps.
 */
static void greylist_timeout(void *eloop_ctx, void *timeout_ctx)
{
	struct greylist_data *data = eloop_ctx;
    struct hapd_interfaces *interfaces = g_interfaces;
    struct hostapd_iface *interface;
    struct hostapd_bss_config *conf;

    if (!data) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: invalid data\n", __func__);
        return;
    }

    wpa_printf(MSG_DEBUG, "GREYLIST: Timeout expires for client :%s\n", data->txtaddr);

    /* Delete the entry from /nvram/greylist_mac.txt file */
    greylist_delete_from_file(interfaces, data->txtaddr);

    for (size_t i = 0; i < interfaces->count; i++) {
        interface = interfaces->iface[i];
        for (size_t j = 0; j < interface->num_bss; j++) {
            conf = interface->bss[j]->conf;
            if (conf->greylist) {
                wpa_printf(MSG_DEBUG,
                        "GREYLIST: %s: remove %s on %s\n",
                        __func__,
                        data->txtaddr,
                        conf->iface);
				hostapd_ctrl_iface_acl_del_mac(
                            &conf->deny_mac,
                            &conf->num_deny_mac, data->txtaddr);

            }
        }
    }
    os_free(data);
}


/**
 * greylist_add_to_driver - Add mac to access control list of
 * all greylist enabled vaps.
 *
 * The parameter 'txtaddr' can be a list of mac strings separated by space.
 */
static void greylist_add_to_driver(const char *txtaddr)
{
    struct hostapd_iface *interface;
    struct hostapd_bss_config *conf;

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s\n",
            __func__, txtaddr);

    for (size_t i = 0; i < g_interfaces->count; i++) {
        interface = g_interfaces->iface[i];
        for (size_t j = 0; j < interface->num_bss; j++) {
            conf = interface->bss[j]->conf;
            if (conf->greylist) {
                wpa_printf(MSG_DEBUG, "GREYLIST: %s: add %s to %s\n", __func__, txtaddr, conf->iface);
				hostapd_ctrl_iface_acl_add_mac(
                            &conf->deny_mac,
                            &conf->num_deny_mac, txtaddr);

			}
		}
	}
}

/*
 * greylist_get_timeout - convert date and time strings in timeout
 * RETURNS:
 * -1 - in case of error
 *  0 - need to remove mac address from file immediately
 * >0 - timeout
 */
static int greylist_get_timeout(char *date_str, char *time_str) {
    char time_buf[20] = {0};
    time_t cur_t, reboot_t, t;
    struct tm time_info;
    int timeout;
    FILE *fp;
    char str[256];
    const char *cmd = "last -F | grep reboot | cut -d\" \" -f8,9,10,12,11";

    os_memset(&time_info, 0, sizeof(time_info));
    sprintf_s(time_buf, sizeof(time_buf), "%s %s", date_str, time_str);
    strptime(time_buf, "%Y-%m-%d %H:%M:%S", &time_info);
    t = mktime(&time_info);
    if (t == (time_t)-1) {
        return -1;
    }
    //During boot the current time can be not update correctly yet
    //so we used now and reboot time and compare and use MAX(reboot_t, now_t)
    time(&cur_t);
    if ((fp = popen(cmd, "r")) != NULL) {
        if (fgets(str, sizeof(str), fp) != NULL) {
            strptime(str, "%a %b %d %H:%M:%S %Y", &time_info);
            reboot_t = mktime(&time_info);
            if (reboot_t > cur_t) {
                cur_t = reboot_t;
            }
        } else {
            wpa_printf(MSG_ERROR, "GREYLIST: %s, fgets failed from command %s\n", __func__, cmd);
        }
        pclose(fp);
    } else {
        wpa_printf(MSG_ERROR, "GREYLIST: %s, popen failed with command %s\n", __func__, cmd);
    }

    if ((t > cur_t) || (cur_t - t > GREYLIST_TIMEOUT_IN_SECONDS)) {
        timeout = 0;
    }
    else {
        timeout = GREYLIST_TIMEOUT_IN_SECONDS - (cur_t - t);
    }
    wpa_printf(MSG_DEBUG, "GREYLIST: %s from %s %s to %d\n", __func__, date_str, time_str, timeout);
    return timeout;
}
#if 0
/**
 * greylist_add_to_other_hostapd - Add the client to other hostapd's greylist
 *
 * This function is used to add the client mac to greylist of other hostapd
 * instance(s) running for other radio(s), so other hostapd instance(s) will
 * add the client's mac to all greylist enabled vaps controlled by it,
 * and create a 24 hour timeout to delete the mac entry from driver
 */
static int greylist_add_to_other_hostapd(const char *txtaddr)
{

    int fd;
    char str[256];
    char *iface;
    char *file_name = "/proc/self/cmdline";

    fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: %s failed\n",__func__, file_name);
        return -1;
    }
    int size = read(fd, str, sizeof(str));
    if (size <= 1) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: can not read from file %s\n",__func__, file_name);
        close(fd);
        return -1;
    }
    close(fd);
    //cmdline is list of strings, separated with \0 bytes, so replace \0 with ' '
    for (int i = 0; i<size-1; i++) if(str[i] == 0) str[i] = ' ';
    //phy1 is wlan0 and phy0 is wlan2
    //we need to call another hostapd
    if (strstr(str, "-phy0")) {
        iface = "wlan0";
    } else if (strstr(str, "-phy1")) {
        iface = "wlan2";
    } else {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: unexpected config file %s\n",__func__, str);
        return -1;
    }

    snprintf(str, sizeof(str),"hostapd_cli -i %s ADD_TO_GREYLIST %s dummy", iface, txtaddr);
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s\n", __func__, str);
    SYSTEM(str);

    return 0;
}
#endif
/******************
 *  END HELP FUNCTIONS
 ******************/


/**
 * greylist_load - Read /nvram/greylist_mac.txt and handle each mac entry
 *
 * This function is used to parse /nvram/greylist_mac.txt at init time,
 * add each mac to driver's acl, and register the timeout.
 *
 * The timeout handler removes the mac from driver's acl and greylist_mac.txt.
 * The timeout value is 24 hour from the client's association time.
 */
void greylist_load(struct hapd_interfaces *interfaces)
{
	FILE *fp;
    int fd, size = 0, max_size = GREYLIST_MAX_NUM_OF_RECORDS * TXT_MAC_ADDR_LEN;
    char record_date[11] = {0}, record_time[9] = {0}, record_mac[TXT_MAC_ADDR_LEN] = {0}, record_ifname[IFNAMSIZ]={0};
    char *macstr_list;
    struct greylist_data *data;
    int timeout;
    struct hostapd_bss_config *conf = interfaces->iface[0]->bss[0]->conf;
    g_interfaces = interfaces; //save for future use (don't need to pass it in every function)

    wpa_printf(MSG_DEBUG, "GREYLIST: %s\n", __func__);

    /* each mac is speparated by space */
    macstr_list = os_zalloc(max_size);
    if (macstr_list == NULL) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: allocate %d bytes memory for macstrlist failed\n", __func__, max_size);
        return;
    }

    if ((fp = fopen(conf->greylist_file, "r")) == NULL) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: %s does not exist\n",__func__, conf->greylist_file);
		free(macstr_list);
        return;
    }
    fd = fileno(fp);
    if (fd == -1) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: fail to get fd\n", __func__);
		free(macstr_list);
        fclose(fp);
        return;
    }

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: trying to get file lock\n", __func__, conf->iface);
    LOC_SH_FILE(fd, conf->iface);

    while ((fscanf(fp, "%10s %8s %17s %16s", record_date, record_time, record_mac, record_ifname)) == 4) {
        wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s %s %s %s\n",__func__, record_date, record_time, record_mac, record_ifname);

        data = os_zalloc(sizeof(*data));
        if (data == NULL) {
            wpa_printf(MSG_ERROR, "GREYLIST: %s: %s: allocate memory for eloop data failed\n", __func__, record_mac);
            continue;
        }

        timeout = greylist_get_timeout(record_date, record_time);
        if (timeout < 0) {
            wpa_printf(MSG_ERROR, "GREYLIST: %s: %s %s %s: time convert failed\n", __func__, record_date, record_time, record_mac);
            //delete this item from list?
			free(data);
            continue;
        }

        memcpy_s(data->txtaddr, sizeof(data->txtaddr), record_mac, sizeof(data->txtaddr));
        wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: timeout=%u\n", __func__, record_mac, timeout);
        eloop_register_timeout(timeout, 0, greylist_timeout, data, NULL);
        if (timeout != 0) { // don't need to add in filter list if timeout already expired
            size += sprintf_s(macstr_list + size, max_size - size, "%s ", record_mac);
        }
    }
    UNLOC_FILE(fd, conf->iface);

    if (size > 0)
        greylist_add_to_driver(macstr_list);
    free(macstr_list);
    fclose(fp);
}


/**
 * greylist_add - Add client's mac to greylist
 *
 * This function is used to add a client's mac to /nvram/greylist_mac.txt
 * and acl of all greylist enabled vaps, and register a 24 hour timeout.
 * The timeout handler removes the mac from greylist.
 */

int greylist_add(struct hapd_interfaces *interfaces, const char *txtaddr, const char *ifname)
{
	FILE *fp;
    int fd, num_of_records = 0;
    char record_date[11] = {0}, record_time[9] = {0}, record_mac[TXT_MAC_ADDR_LEN] = {0}, record_ifname[IFNAMSIZ]={0};
    char time_str[20] = {0};
    time_t t_now;
    struct tm time_info;
    struct hostapd_bss_config *conf = interfaces->iface[0]->bss[0]->conf;

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s\n", __func__, txtaddr);

    if ((fp = fopen(conf->greylist_file, "a+")) == NULL) {
        wpa_printf(MSG_DEBUG, "GREYLIST: %s: fail to open %s\n", __func__, conf->greylist_file);
        return -1;
    }
    fd = fileno(fp);
    if (fd == -1) {
        wpa_printf(MSG_DEBUG, "GREYLIST: %s: fail to get fd\n", __func__);
        fclose(fp);
        return -1;
    }

    /* When the client is rejected by the other hostapd instance
     * running on the other radio, this hostapd instance will
     * receive a message to add the client to greylist sent from
     * the other hostapd instance. We will do that through another function
     *
     * Also, in any unexpected case if we receive multiple reject messages
     * from the server for the same client, no need to
     * add the mac again to the file */
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: trying to get file lock\n",__func__, conf->iface);
    LOC_SH_FILE(fd, conf->iface);

    while ((fscanf(fp, "%10s %8s %17s %16s", record_date, record_time, record_mac, record_ifname) == 4)) {
        num_of_records++;
        if (strcmp(record_mac, txtaddr) == 0) {
            wpa_printf(MSG_ERROR, "GREYLIST: %s: %s already exists in file\n",__func__, txtaddr);
            UNLOC_FILE(fd, conf->iface);
            fclose(fp);
            //we should do nothing here. The mac address is in file
            //so there is registered timeout and mac is added in filter
            return 0;
        }
    }
    UNLOC_FILE(fd, conf->iface);

    if (num_of_records >= GREYLIST_MAX_NUM_OF_RECORDS) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: greylist is full\n", __func__);
        fclose(fp);
        return -1;
    }


    /* Get the current time and ifname and add the client mac, ifname  and current time to the file */
    time(&t_now);
    os_memset(&time_info, 0, sizeof(time_info));
    localtime_r(&t_now, &time_info);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &time_info);
#if 0
    /* rpc_index is platform specific, hence removing, will add ifanme to the file */
    greylist_get_index_from_ifname(ifname, index, INDEX_MAX_LEN);
#endif
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: %s: trying to get file lock\n",__func__, conf->iface);
    LOC_EX_FILE(fd, conf->iface);

    fseek(fp, 0, SEEK_END); //In case file position is updated by other processes
#if 0
    /* rpc_index is platform specific, hence removing */
    fprintf(fp, "%s %s %s\n", time_str, txtaddr, index);
#endif
    fprintf(fp, "%s %s %s\n", time_str, txtaddr, ifname);

    fflush(fp);
    UNLOC_FILE(fd, conf->iface);
    fclose(fp);

    greylist_add_filter_only(txtaddr);
	greylist_log_to_file("%s Client added to grey list from RADIUS: %s\n", time_str, txtaddr);
#if 0
	/* this is not needed for single hostapd */
    greylist_add_to_other_hostapd(txtaddr);
#endif

    return 0;
}

/*
 *  greylist_add_filter_only  - add mac address in driver and start timer only
 * 
 *  This function is used to add a client's mac to driver and register a 24h timeout 
 *  The timeout handler removes the mac from greylist.
 */
int greylist_add_filter_only(const char *txtaddr) {
    u32 timeout = GREYLIST_TIMEOUT_IN_SECONDS;
    struct greylist_data *data;

    data = os_zalloc(sizeof(*data));
    if (data == NULL) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: allocate memory failed\n", __func__);
        return -1;
    }

    /* add mac address to filters and start timer to remove it */
    greylist_add_to_driver(txtaddr);

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: register %u seconds timeout for %s\n", __func__, timeout, txtaddr);
    memcpy_s(data->txtaddr, sizeof(data->txtaddr), txtaddr, sizeof(data->txtaddr));
    eloop_register_timeout(timeout, 0, greylist_timeout, data, NULL);

    return 0;
}

/**
 * greylist_get_client_snr - Get SNR of a client
 * @hapd - hostapd BSS data
 * @addr - station addr
 */
u8 greylist_get_client_snr(struct hostapd_data *hapd, struct sta_info *sta)
{
	struct intel_vendor_sta_info sta_info;
    u8 snr = 0;

    if (!sta) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: station is invalid\n", __func__);
        return 0;
    }

    wpa_printf(MSG_DEBUG, "GREYLIST: %s: Client MAC is " MACSTR,
            __func__, MAC2STR(sta->addr));

    /* Use hostapd_drv_get_sta_measurements to fill intel_vendor_sta_info structure */
    if(hostapd_drv_get_sta_measurements(hapd, sta->addr, &sta_info)) {
        wpa_printf(MSG_ERROR, "GREYLIST: %s: hostapd_drv_get_sta_measurements failed\n",
                __func__);
        return 0;
    }

    snr = (u8)sta_info.snr[0];
    wpa_printf(MSG_DEBUG, "GREYLIST: %s: snr=%u\n",
            __func__, snr);
    return snr;
}
/**
 * greylist_clear_all - remove all greylist mac from filtering, stop all timers and cleanup greylist file
 *
 */
int greylist_clear_all(struct hostapd_data *hapd) {
    wpa_printf(MSG_DEBUG, "GREYLIST: %s\n", __func__);
    //this call will cause a samll memory leak. eloop interface doesn't provide api
    //to get data pointes provided with eloop_register_timeout calls
    //we can store those pointers locally but that will require more rework
    eloop_cancel_timeout(greylist_timeout, ELOOP_ALL_CTX, ELOOP_ALL_CTX);
    unlink(hapd->conf->greylist_file);
    return 0;
}
