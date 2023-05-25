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

typedef struct vxlan_config_s vxlan_config_t;

struct vxlan_config_s
{
    char src[32];
    char dst[32];
    char vni[32];
    char name[32];
};

static vxlan_config_t vxlan_config;

#define FREE_SAFE(x) \
    do               \
    {                \
        free(x);     \
        (x) = NULL;  \
    } while (0)

#define ARRAY_SIZE(X) (sizeof((X)) / sizeof((X)[0]))

#define VXLAN_YANG_MODEL "vpp-vxlan"
#define SYSREPOCFG_EMPTY_CHECK_COMMAND "sysrepocfg -X -d running -m " VXLAN_YANG_MODEL
#define VXLAN_YANG_PATH "/" VXLAN_YANG_MODEL ":vxlan"
#define SRC_YANG_PATH VXLAN_YANG_PATH "/src"
#define DST_YANG_PATH VXLAN_YANG_PATH "/dst"
#define VNI_YANG_PATH VXLAN_YANG_PATH "/vni"
#define NAME_YANG_PATH VXLAN_YANG_PATH "/bri-InterfaceName"

volatile int exit_application = 0;
static int execute_vppctl_cmd(void);
static int is_configure_legal(void);
static bool vxlan_running_datastore_is_empty_check(void);
static int set_config_value(const struct lyd_node *node, const char *prev_value, sr_change_oper_t operation);
static int vxlan_module_change_cb(sr_session_ctx_t *session, const char *module_name,
                                  const char *xpath, sr_event_t event, uint32_t request_id,
                                  void *private_data);

static bool vxlan_running_datastore_is_empty_check(void)
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

    if (strncmp(node_name, "src", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(vxlan_config.src, node_list->value_str, strlen(node_list->value_str));
    }
    else if (strncmp(node_name, "dst", strlen(node_name)) == 0 &&
             node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(vxlan_config.dst, node_list->value_str, strlen(node_list->value_str));
    }

    else if (strncmp(node_name, "vni", strlen(node_name)) == 0 &&
             node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(vxlan_config.vni, node_list->value_str, strlen(node_list->value_str));
    }

    else if (strncmp(node_name, "bri-InterfaceName", strlen(node_name)) == 0 &&
             node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(vxlan_config.name, node_list->value_str, strlen(node_list->value_str));
    }

    return error;
}

static int is_configure_legal(void)
{
    if (strlen(vxlan_config.src) == 0 || strlen(vxlan_config.dst) == 0 || strlen(vxlan_config.vni) == 0 || strlen(vxlan_config.name) == 0)
        return 1;
    else
        return 0;
}

static int execute_vppctl_cmd(void)
{
    char cmd[256] = {0};
    if (is_configure_legal())
        return 1;
    else
    {
        sprintf(cmd, "vppctl create bridge-domain %s learn 1 forward 1 uu-flood 1 flood 1 arp-term 0", vxlan_config.vni);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl create vxlan tunnel src %s dst %s vni %s decap-next l2", vxlan_config.src, vxlan_config.dst, vxlan_config.vni);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl set interface l2 bridge vxlan_tunnel0 %s", vxlan_config.vni);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));

        sprintf(cmd, "vppctl set interface l2 bridge %s %s bvi", vxlan_config.name, vxlan_config.vni);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));
 	
	sprintf(cmd, "vppctl set interface state %s up", vxlan_config.name);
        system(cmd);
        memset(cmd, 0, sizeof(cmd));
        return 0;
    }
}

static int vxlan_module_change_cb(sr_session_ctx_t *session, const char *module_name,
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
        error = sr_copy_config(startup_session, VXLAN_YANG_MODEL, SR_DS_RUNNING, 0, 0);
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

    if (vxlan_running_datastore_is_empty_check() == true)
    {
        SRP_LOG_INFMSG("running DS is empty.");
    }
    else
    {
        sr_get_item(startup_session, SRC_YANG_PATH, 0, &value);
        sr_val_to_buff(value, vxlan_config.src, sizeof(vxlan_config.src));
        sr_free_val(value);

        sr_get_item(startup_session, DST_YANG_PATH, 0, &value);
        sr_val_to_buff(value, vxlan_config.dst, sizeof(vxlan_config.dst));
        sr_free_val(value);

        sr_get_item(startup_session, VNI_YANG_PATH, 0, &value);
        sr_val_to_buff(value, vxlan_config.vni, sizeof(vxlan_config.vni));
        sr_free_val(value);

        sr_get_item(startup_session, NAME_YANG_PATH, 0, &value);
        sr_val_to_buff(value, vxlan_config.name, sizeof(vxlan_config.name));
        sr_free_val(value);

        error = execute_vppctl_cmd();
        if (error)
        {
            SRP_LOG_INFMSG("The data in the running datastore is illeagl,please resume load again.");
        }
    }
    SRP_LOG_INFMSG("subscribing to module change");
    error = sr_module_change_subscribe(session, VXLAN_YANG_MODEL, "/" VXLAN_YANG_MODEL ":*//*",
                                           vxlan_module_change_cb, *private_data, 0, SR_SUBSCR_DEFAULT, &subscription);

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
