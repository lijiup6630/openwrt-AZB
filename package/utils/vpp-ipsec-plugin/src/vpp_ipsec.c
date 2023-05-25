#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <sysrepo.h>
#include <sysrepo/xpath.h>
#include <sysrepo/values.h>

typedef struct ipsec_config_s ipsec_config_t;

struct ipsec_config_s
{
    char local_addr[32];
    char remote_addr[32];
    char min_child_lts[32];
    char max_child_lts[32];
    char min_child_rts[32];
    char max_child_rts[32];
    char interface_name[32];
    char ipip0_addr[32];
    char is_initiator[8];
};

static ipsec_config_t ipsec_config;

#define FREE_SAFE(x) \
    do               \
    {                \
        free(x);     \
        (x) = NULL;  \
    } while (0)

#define ARRAY_SIZE(X) (sizeof((X)) / sizeof((X)[0]))

#define IPSEC_YANG_MODEL "vpp-ipsec"
#define SYSREPOCFG_EMPTY_CHECK_COMMAND "sysrepocfg -X -d running -m " IPSEC_YANG_MODEL
#define IPSEC_YANG_PATH "/" IPSEC_YANG_MODEL ":ipsec"
#define LOCALADDR_YANG_PATH IPSEC_YANG_PATH "/localaddr"
#define REMOTEADDR_YANG_PATH IPSEC_YANG_PATH "/remoteaddr"
#define MIN_CHILDLOCALTS_YANG_PATH IPSEC_YANG_PATH "/min-childlocalts"
#define MAX_CHILDLOCALTS_YANG_PATH IPSEC_YANG_PATH "/max-childlocalts"
#define MIN_CHILDREMOTETS_YANG_PATH IPSEC_YANG_PATH "/min-childremotets"
#define MAX_CHILDREMOTETS_YANG_PATH IPSEC_YANG_PATH "/max-childremotets"
#define INTERFACE_NAME_YANG_PATH IPSEC_YANG_PATH "/interface-name"
#define IPIP0_ADDR_YANG_PATH IPSEC_YANG_PATH "/ipip0-addr"
#define IS_INITIATOR_YANG_PATH IPSEC_YANG_PATH "/is-initiator"

volatile int exit_application = 0;
static int execute_vppctl_cmd(void);
static int is_configure_legal(void);
static bool ipsec_running_datastore_is_empty_check(void);
static int ipsec_module_change_cb(sr_session_ctx_t *session, const char *module_name,
                                  const char *xpath, sr_event_t event, uint32_t request_id,
                                  void *private_data);
static int set_config_value(const struct lyd_node *node, const char *prev_value, sr_change_oper_t operation);

static bool ipsec_running_datastore_is_empty_check(void)
{
    FILE *sysrepocfg_DS_empty_check = NULL;
    bool is_empty = false;

    sysrepocfg_DS_empty_check = popen(SYSREPOCFG_EMPTY_CHECK_COMMAND, "r");

    if (sysrepocfg_DS_empty_check == NULL)
    {
        SRP_LOG_WRN("could not execute %s", SYSREPOCFG_EMPTY_CHECK_COMMAND);
        is_empty = true;
        goto out;
    }

    if (fgetc(sysrepocfg_DS_empty_check) == EOF)
    {
        is_empty = true;
    }

out:
    if (sysrepocfg_DS_empty_check)
    {
        pclose(sysrepocfg_DS_empty_check);
    }

    return is_empty;
}

static int is_configure_legal(void)
{
    if (strlen(ipsec_config.local_addr) == 0 || strlen(ipsec_config.remote_addr) == 0 || strlen(ipsec_config.min_child_lts) == 0 || strlen(ipsec_config.max_child_lts) == 0 || strlen(ipsec_config.min_child_rts) == 0 || strlen(ipsec_config.max_child_rts) == 0)
        return -1;
    else
        return 1;
}

static int execute_vppctl_cmd(void)
{
    char cmd[256] = {0};
    if (is_configure_legal() == -1)
        return 1;
    else
    {
        // 首先删除之前可能设置的ikev2
        system("vppctl ikev2 profile del vxlan");
        system("vppctl delete ipip tunnel sw_if_index 0");
        system("vppctl delete ipip tunnel sw_if_index 1");
        system("vppctl delete ipip tunnel sw_if_index 2");
        system("vppctl delete ipip tunnel sw_if_index 3");
        system("vppctl delete ipip tunnel sw_if_index 4");
        system("vppctl delete ipip tunnel sw_if_index 5");
        system("vppctl ikev2 profile add vxlan");
        system("vppctl ikev2 profile set vxlan auth shared-key-mic string vxlan");
        sprintf(cmd, "vppctl ikev2 profile set vxlan id local ip4-addr %s", ipsec_config.local_addr);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl ikev2 profile set vxlan id remote ip4-addr %s", ipsec_config.remote_addr);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl ikev2 profile set vxlan traffic-selector local ip-range %s - %s port-range 0 - 65535 protocol 0", ipsec_config.min_child_lts, ipsec_config.max_child_lts);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl ikev2 profile set vxlan traffic-selector remote ip-range %s - %s port-range 0 - 65535 protocol 0", ipsec_config.min_child_rts, ipsec_config.max_child_rts);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        system("vppctl ikev2 profile set vxlan ike-crypto-alg aes-cbc 256 ike-integ-alg sha1-96 ike-dh modp-2048");
        system("vppctl ikev2 profile set vxlan esp-crypto-alg aes-cbc 256 esp-integ-alg sha1-96 esp-dh ecp-256");

        sprintf(cmd, "vppctl ikev2 profile set vxlan responder %s %s", ipsec_config.interface_name, ipsec_config.remote_addr);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));
	
	sprintf(cmd, "vppctl set interface state %s up", ipsec_config.interface_name);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl create ipip tunnel src %s dst %s", ipsec_config.local_addr, ipsec_config.remote_addr);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        system("vppctl ikev2 profile set vxlan tunnel ipip0");

        sprintf(cmd, "vppctl set interface ip address ipip0 %s", ipsec_config.ipip0_addr);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        system("vppctl set interface state ipip0 up");
        if (strncmp(ipsec_config.is_initiator, "yes", sizeof("yes")) == 0 || strncmp(ipsec_config.is_initiator, "1", sizeof("1")) == 0 || strncmp(ipsec_config.is_initiator, "y", sizeof("y")) == 0 || strncmp(ipsec_config.is_initiator, "YES", sizeof("YES")) == 0)
        {
            system("vppctl ikev2 initiate sa-init vxlan");
        }

        return 0;
    }
}

static int set_config_value(const struct lyd_node *node, const char *prev_value, sr_change_oper_t operation)
{
    int error = SR_ERR_OK;
    struct lyd_node_leaf_list *node_list = NULL;
    const char *node_name = NULL;
    const char *node_value = NULL;

    node_name = node->schema->name;
    node_list = (struct lyd_node_leaf_list *)node;
    node_value = node_list->value_str;

    SRP_LOG_DBG("prev_val: %s; node_val: %s; operation: %d", prev_value, node_value, operation);

    if (strncmp(node_name, "localaddr", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.local_addr, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "remoteaddr", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.remote_addr, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "min-childlocalts", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.min_child_lts, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "max-childlocalts", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.max_child_lts, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "min-childremotets", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.min_child_rts, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "max-childremotets", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.max_child_rts, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "ipip0-addr", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.ipip0_addr, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "interface-name", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.interface_name, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "is-initiator", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(ipsec_config.is_initiator, node_list->value_str, strlen(node_list->value_str));
    }
    return error;
}

static int ipsec_module_change_cb(sr_session_ctx_t *session, const char *module_name,
                                  const char *xpath, sr_event_t event, uint32_t request_id,
                                  void *private_data)
{
    int error = 0;
    sr_session_ctx_t *startup_session = (sr_session_ctx_t *)private_data;
    sr_change_iter_t *ipsec_server_change_iter = NULL;
    sr_change_oper_t operation = SR_OP_CREATED;
    const struct lyd_node *node = NULL;
    const char *prev_value = NULL;
    const char *prev_list = NULL;
    bool prev_default = false;
    char *node_xpath = NULL;

    SRP_LOG_INF("module_name: %s, xpath: %s, event: %d, request_id: %" PRIu32, module_name, xpath, event, request_id);

    if (event == SR_EV_ABORT)
    {
        SRP_LOG_ERR("aborting changes for: %s", xpath);
        error = -1;
        goto error_out;
    }

    if (event == SR_EV_DONE)
    {
        error = sr_copy_config(startup_session, IPSEC_YANG_MODEL, SR_DS_RUNNING, 0, 0);
        if (error)
        {
            SRP_LOG_ERR("sr_copy_config error (%d): %s", error, sr_strerror(error));
            goto error_out;
        }
    }

    if (event == SR_EV_CHANGE)
    {
        error = sr_get_changes_iter(session, xpath, &ipsec_server_change_iter);
        if (error)
        {
            SRP_LOG_ERR("sr_get_changes_iter error (%d): %s", error, sr_strerror(error));
            goto error_out;
        }

        while (sr_get_change_tree_next(session, ipsec_server_change_iter, &operation, &node,
                                       &prev_value, &prev_list, &prev_default) == SR_ERR_OK)
        {
            node_xpath = lyd_path(node);

            if (node->schema->nodetype == LYS_LEAF || node->schema->nodetype == LYS_LEAFLIST)
            {
                error = set_config_value(node, prev_value, operation);
                if (error)
                {
                    SRP_LOG_ERR("set_config_value error (%d)", error);
                    goto error_out;
                }
            }
        }
	execute_vppctl_cmd();
    }

    goto out;

error_out:
out:
    if (node_xpath != NULL)
    {
        FREE_SAFE(node_xpath);
    }

    sr_free_change_iter(ipsec_server_change_iter);

    return error ? SR_ERR_CALLBACK_FAILED : SR_ERR_OK;
}

int sr_plugin_init_cb(sr_session_ctx_t *session, void **private_data)
{
    int error = 0;
    sr_conn_ctx_t *connection = NULL;
    sr_session_ctx_t *startup_session = NULL;
    sr_subscription_ctx_t *subscription = NULL;
    sr_val_t *value = NULL;
    *private_data = NULL;

    SRP_LOG_INFMSG("start session to startup datastore");

    connection = sr_session_get_connection(session);
    error = sr_session_start(connection, SR_DS_STARTUP, &startup_session);

    if (error)
    {
        SRP_LOG_ERR("sr_session_start error (%d): %s", error, sr_strerror(error));
        goto error_out;
    }

    *private_data = startup_session;

    if (ipsec_running_datastore_is_empty_check() == true)
    {
        SRP_LOG_INFMSG("running DS is empty.");
    }
    else
    {

        sr_get_item(startup_session, LOCALADDR_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.local_addr, sizeof(ipsec_config.local_addr));
        sr_free_val(value);

        sr_get_item(startup_session, REMOTEADDR_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.remote_addr, sizeof(ipsec_config.remote_addr));
        sr_free_val(value);

        sr_get_item(startup_session, MIN_CHILDLOCALTS_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.min_child_lts, sizeof(ipsec_config.min_child_lts));
        sr_free_val(value);

        sr_get_item(startup_session, MAX_CHILDLOCALTS_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.max_child_lts, sizeof(ipsec_config.max_child_lts));
        sr_free_val(value);

        sr_get_item(startup_session, MIN_CHILDREMOTETS_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.min_child_rts, sizeof(ipsec_config.min_child_rts));
        sr_free_val(value);

        sr_get_item(startup_session, MAX_CHILDREMOTETS_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.max_child_rts, sizeof(ipsec_config.max_child_rts));
        sr_free_val(value);

        sr_get_item(startup_session, INTERFACE_NAME_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.interface_name, sizeof(ipsec_config.interface_name));
        sr_free_val(value);

        sr_get_item(startup_session, IPIP0_ADDR_YANG_PATH, 0, &value);
        sr_val_to_buff(value, ipsec_config.ipip0_addr, sizeof(ipsec_config.ipip0_addr));
        sr_free_val(value);

        error = execute_vppctl_cmd();
        if (error)
        {
            SRP_LOG_INFMSG("The data in the running datastore is illeagl,please resume load again.");
        }
    }
    SRP_LOG_INFMSG("subscribing to module change");
    error = sr_module_change_subscribe(session, IPSEC_YANG_MODEL, "/" IPSEC_YANG_MODEL ":*//*",
                                       ipsec_module_change_cb, *private_data, 0, SR_SUBSCR_DEFAULT, &subscription);

    if (error)
    {
        SRP_LOG_ERR("sr_module_change_subscribe error (%d): %s", error, sr_strerror(error));
        goto error_out;
    }

    SRP_LOG_INFMSG("plugin init done");
    goto out;

error_out:
    if (subscription != NULL)
        sr_unsubscribe(subscription);
    if (connection != NULL)
        sr_disconnect(connection);
out:
    return error ? SR_ERR_CALLBACK_FAILED : SR_ERR_OK;
}

void sr_plugin_cleanup_cb(sr_session_ctx_t *session, void *private_data)
{
    sr_session_ctx_t *startup_session = (sr_session_ctx_t *)private_data;

    if (startup_session)
    {
        sr_session_stop(startup_session);
    }

    SRP_LOG_INFMSG("plugin cleanup finished");
}

#ifndef PLUGIN
#include <signal.h>

static void sigint_handler(__attribute__((unused)) int signum);
int main(void)
{
    int error = SR_ERR_OK;
    sr_conn_ctx_t *connection = NULL;
    sr_session_ctx_t *session = NULL;
    void *private_data = NULL;

    sr_log_stderr(SR_LL_DBG);

    /* connect to sysrepo */
    error = sr_connect(SR_CONN_DEFAULT, &connection);
    if (error)
    {
        SRP_LOG_ERR("sr_connect error (%d): %s", error, sr_strerror(error));
        goto out;
    }

    error = sr_session_start(connection, SR_DS_RUNNING, &session);
    if (error)
    {
        SRP_LOG_ERR("sr_session_start error (%d): %s", error, sr_strerror(error));
        goto out;
    }

    error = sr_plugin_init_cb(session, &private_data);
    if (error)
    {
        SRP_LOG_ERRMSG("sr_plugin_init_cb error");
        goto out;
    }

    /*  loop until ctrl-c is pressed / SIGINT is received */
    signal(SIGINT, sigint_handler);
    signal(SIGPIPE, SIG_IGN);
    while (!exit_application)
    {
        sleep(1);
    }

out:
    sr_plugin_cleanup_cb(session, private_data);
    sr_disconnect(connection);
    return error ? -1 : 0;
}

static void sigint_handler(__attribute__((unused)) int signum)
{
    SRP_LOG_INFMSG("Sigint called, exiting...");
    exit_application = 1;
}

#endif
