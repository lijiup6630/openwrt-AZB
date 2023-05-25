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

// 对应于yang模型中各个字段。仅作为测试用，字符串长度暂且写死
typedef struct sswan_config_s sswan_config_t;

struct sswan_config_s
{
    char name[32];
    char local_addr[32];
    char remote_addr[32];
    char mode[32];
    char child_lts[32];
    char child_rts[32];
    char secrets[32];
    char enable[8];
};

static sswan_config_t sswan_config;

#define FREE_SAFE(x) \
    do               \
    {                \
        free(x);     \
        (x) = NULL;  \
    } while (0)

#define ARRAY_SIZE(X) (sizeof((X)) / sizeof((X)[0]))
#define IPSEC_YANG_MODEL "ipsec-sswan"

#define SYSREPOCFG_EMPTY_CHECK_COMMAND "sysrepocfg -X -d running -m " IPSEC_YANG_MODEL
#define IPSEC_YANG_PATH "/" IPSEC_YANG_MODEL ":ipsec"
#define NAME_YANG_PATH IPSEC_YANG_MODEL "/name"
#define LOCALADDRS_YANG_PATH IPSEC_YANG_MODEL "/localaddrs"
#define REMOTEADDRS_YANG_PATH IPSEC_YANG_MODEL "/remoteaddrs"
#define CHILDLOCALTS_YANG_PATH IPSEC_YANG_MODEL "/childlocalts"
#define CHILDREMOTETS_YANG_PATH IPSEC_YANG_MODEL "/childremotets"
#define SECRETS_YANG_PATH IPSEC_YANG_MODEL "/secrets"
#define SWANCTL_CONFIG_PATH "/etc/swanctl/conf.d/swanctl.conf"

volatile int exit_application = 0;

int set_config_value(const struct lyd_node *node, sr_change_oper_t operation);
static bool ipsec_running_datastore_is_empty_check(void);
static int ipsec_module_change_cb(sr_session_ctx_t *session, const char *module_name,
                                  const char *xpath, sr_event_t event, uint32_t request_id,
                                  void *private_data);

static int ipsec_module_change_cb(sr_session_ctx_t *session, const char *module_name,
                                  const char *xpath, sr_event_t event, uint32_t request_id,
                                  void *private_data)
{
    int error = 0;
    FILE *fp = NULL;
    sr_session_ctx_t *startup_session = (sr_session_ctx_t *)private_data;
    sr_change_iter_t *ipsec_server_change_iter = NULL;
    sr_change_oper_t operation = SR_OP_CREATED;
    const struct lyd_node *node = NULL;
    const char *prev_value = NULL;
    const char *prev_list = NULL;
    bool prev_default = false;
    char *node_xpath = NULL;
    char sswan_file_content[1024] = {0};
    char swanctl_cmd[64] = {0};

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
        fp = fopen(SWANCTL_CONFIG_PATH, "w");
        if (fp == NULL)
        {
            error = -1;
            goto error_out;
        }
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
                error = set_config_value(node, operation);
                if (error)
                {
                    SRP_LOG_ERR("set_config_value error (%d)", error);
                    goto error_out;
                }
            }
        }
        // 写入配置文件
        if (strlen(sswan_config.child_rts) == 0 || strncmp(sswan_config.child_rts, "0", sizeof("0")) == 0 || strncmp(sswan_config.child_rts, "null", sizeof("null")) == 0 || strncmp(sswan_config.child_rts, "NULL", sizeof("NULL")) == 0)
        {
            sprintf(sswan_file_content, "connections {\n"
                                        "   %s {\n"
                                        "       local_addrs = %s\n"
                                        "       remote_addrs = %s\n"

                                        "       local {\n"
                                        "           auth = psk\n"
                                        "       }\n"
                                        "       remote {\n"
                                        "           auth = psk\n"
                                        "       }\n"
                                        "       children {\n"
                                        "           %s {\n"
                                        "               local_ts = %s\n"
                                        "               esp_proposals = aes128-sha1-modp2048\n"
                                        "               mode = %s\n"
                                        "           }\n"
					"	}\n"
                                        "       version = 2\n"
                                        "       proposals = aes128-sha256-x25519\n"
                                        "   }\n"
                                        "}\n"
                                        "secrets{\n"
                                        "   ike {\n"
                                        "       secret = %s\n"
                                        "   }\n"
                                        "}",
                    sswan_config.name, sswan_config.local_addr, sswan_config.remote_addr, sswan_config.name, sswan_config.child_lts, sswan_config.mode, sswan_config.secrets);
        }
        else
        {
            sprintf(sswan_file_content, "connections {\n"
                                        "   %s {\n"
                                        "       local_addrs = %s\n"
                                        "       remote_addrs = %s\n"
                                        "       local {\n"
                                        "           auth = psk\n"
                                        "       }\n"
                                        "       remote {\n"
                                        "           auth = psk\n"
                                        "       }\n"
                                        "       children {\n"
                                        "           %s {\n"
                                        "               local_ts = %s\n"
                                        "               remote_ts = %s\n"
                                        "               esp_proposals = aes128-sha1-modp2048\n"
                                        "               mode = %s\n"
                                        "           }\n"
					"	}\n"
                                        "       version = 2\n"
                                        "       proposals = aes128-sha256-x25519\n"
                                        "   }\n"
                                        "}\n"
                                        "secrets{\n"
                                        "   ike {\n"
                                        "       secret = %s\n"
                                        "   }\n"
                                        "}",
                    sswan_config.name, sswan_config.local_addr, sswan_config.remote_addr, sswan_config.name, sswan_config.child_lts, sswan_config.child_rts, sswan_config.mode, sswan_config.secrets);
        }
        fwrite(sswan_file_content, strlen(sswan_file_content), 1, fp);
        if (strncmp(sswan_config.enable, "1", sizeof("1")) == 0 ||strncmp(sswan_config.enable, "yes", sizeof("yes")) == 0 || strncmp(sswan_config.child_rts, "y", sizeof("y")) == 0 || strncmp(sswan_config.child_rts, "Y", sizeof("Y")) == 0 || strncmp(sswan_config.child_rts, "YES", sizeof("YES")) == 0)
        {
            sprintf(swanctl_cmd, "ipsec up %s", sswan_config.name);
            system("ipsec restart");
            system("swanctl --load-all");
	    sleep(10);
            system(swanctl_cmd);
        }
        else
        {
            sprintf(swanctl_cmd, "ipsec down %s", sswan_config.name);
            system("ipsec stop");
	    system(swanctl_cmd);
        }
    }
    goto out;
error_out:
out:
    if (node_xpath != NULL)
    {
        FREE_SAFE(node_xpath);
    }
    if (fp != NULL)
    {
        fclose(fp);
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
        // SRP_LOG_INFMSG("running DS is not empty.");

        // 读取running数据库中的值到结构体中
        sr_get_item(startup_session, "/ipsec-sswan:ipsec/name", 0, &value);
        sr_val_to_buff(value, sswan_config.name, sizeof(sswan_config.name));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/localaddrs", 0, &value);
        sr_val_to_buff(value, sswan_config.local_addr, sizeof(sswan_config.local_addr));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/remoteaddrs", 0, &value);
        sr_val_to_buff(value, sswan_config.remote_addr, sizeof(sswan_config.remote_addr));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/mode", 0, &value);
        sr_val_to_buff(value, sswan_config.mode, sizeof(sswan_config.mode));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/childlocalts", 0, &value);
        sr_val_to_buff(value, sswan_config.child_lts, sizeof(sswan_config.child_lts));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/childremotets", 0, &value);
        sr_val_to_buff(value, sswan_config.child_rts, sizeof(sswan_config.child_rts));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/secrets", 0, &value);
        sr_val_to_buff(value, sswan_config.secrets, sizeof(sswan_config.secrets));
        sr_free_val(value);

        sr_get_item(startup_session, "/ipsec-sswan:ipsec/enable", 0, &value);
        sr_val_to_buff(value, sswan_config.enable, sizeof(sswan_config.enable));
        sr_free_val(value);
        //     error = sr_get_item(startup_session, "/ipsec-sswan:ipsec/localaddrs", 0, &value);
        //     if (SR_ERR_OK != error)
        //     {
        //         strncpy(sswan_config.local_addr, (char *)value.data, strlen((char *)value.data) + 1);
        //         goto error_out;
        //     }
        //     sr_free_val(value);

        //     error = sr_get_item(startup_session, "/ipsec-sswan:ipsec/remoteaddrs", 0, &value);
        //     if (SR_ERR_OK != error)
        //     {
        //         strncpy(sswan_config.remote_addr, (char *)value.data, strlen((char *)value.data) + 1);
        //         goto error_out;
        //     }
        //     sr_free_val(value);

        //     error = sr_get_item(startup_session, "/ipsec-sswan:ipsec/childlocalts", 0, &value);
        //     if (SR_ERR_OK != error)
        //     {
        //         strncpy(sswan_config.child_lts, (char *)value.data, strlen((char *)value.data) + 1);
        //         goto error_out;
        //     }
        //     sr_free_val(value);

        //     error = sr_get_item(startup_session, "/ipsec-sswan:ipsec/childremotets", 0, &value);
        //     if (SR_ERR_OK != error)
        //     {
        //         strncpy(sswan_config.child_rts, (char *)value.data, strlen((char *)value.data) + 1);
        //         goto error_out;
        //     }
        //     sr_free_val(value);

        //     error = sr_get_item(startup_session, "/ipsec-sswan:ipsec/secrets", 0, &value);
        //     if (SR_ERR_OK != error)
        //     {
        //         strncpy(sswan_config.child_rts, (char *)value.data, strlen((char *)value.data) + 1);
        //         goto error_out;
        //     }
        //     sr_free_val(value);
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
    if (value != NULL)
        sr_free_val(value);
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

int set_config_value(const struct lyd_node *node, sr_change_oper_t operation)
{
    int error = SR_ERR_OK;
    struct lyd_node_leaf_list *node_list = NULL;
    const char *node_name = NULL;

    node_name = node->schema->name;

    node_list = (struct lyd_node_leaf_list *)node;

    if (strncmp(node_name, "name", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.name, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "localaddrs", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.local_addr, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "remoteaddrs", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.remote_addr, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "mode", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.mode, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "childlocalts", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.child_lts, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "childremotets", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        if (operation == SR_OP_DELETED)
        {
            memset(sswan_config.child_rts, 0, sizeof(sswan_config.child_rts));
        }
        else
        {
            strncpy(sswan_config.child_rts, node_list->value_str, strlen(node_list->value_str));
        }
    }

    if (strncmp(node_name, "secrets", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.secrets, node_list->value_str, strlen(node_list->value_str));
    }

    if (strncmp(node_name, "enable", strlen(node_name)) == 0 &&
        node_list->value_type == LY_TYPE_STRING)
    {
        strncpy(sswan_config.enable, node_list->value_str, strlen(node_list->value_str));
    }

    // printf("name: %s\nlocaladdrs: %s\nremoteaddrs: %s\nmode: %s\nchildlocalts: %s\nchildremotets: %s\nsecrets: %s\n", sswan_config.name, sswan_config.local_addr, sswan_config.remote_addr, sswan_config.mode, sswan_config.child_lts, sswan_config.child_rts, sswan_config.secrets);
    // printf("key: %s,value %s\n", node_name, node_list->value_str);
    //     int error = SR_ERR_OK;

    //     if (strcmp(xpath, NAME_YANG_PATH) == 0)
    //     {
    //         strncpy(sswan_config.name, value, strlen(value));
    //     }
    //     else if (strcmp(xpath, LOCALADDRS_YANG_PATH) == 0)
    //     {
    //         strncpy(sswan_config.local_addr, value, strlen(value));
    //     }
    //     else if (strcmp(xpath, REMOTEADDRS_YANG_PATH) == 0)
    //     {
    //         strncpy(sswan_config.remote_addr, value, strlen(value));
    //     }
    //     else if (strcmp(xpath, CHILDLOCALTS_YANG_PATH) == 0)
    //     {
    //         strncpy(sswan_config.child_lts, value, strlen(value));
    //     }
    //     else if (strcmp(xpath, CHILDREMOTETS_YANG_PATH) == 0)
    //     {
    //         if (operation == SR_OP_DELETED)
    //         {
    //             memset(sswan_config.child_rts, 0, sizeof(value));
    //         }
    //         else
    //         {
    //             strncpy(sswan_config.child_rts, value, strlen(value));
    //         }
    //     }
    //     else if (strcmp(xpath, SECRETS_YANG_PATH) == 0)
    //     {
    //         strncpy(sswan_config.secrets, value, strlen(value));
    //     }

    return error;
}

#ifndef PLUGIN
#include <signal.h>
#include <unistd.h>

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
