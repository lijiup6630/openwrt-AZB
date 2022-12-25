#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RNDIS_KEY_STRING "dmesg | grep -i rndis_host"
#define CONN_FM350_CMD0 "atcmdtool -d /dev/ttyUSB0 AT+CPIN?" //确保sim卡就绪
#define CONN_FM350_CMD1 "atcmdtool -d /dev/ttyUSB0 AT+CSQ" //确保模块能接收到信号
#define CONN_FM350_CMD2 "atcmdtool -d /dev/ttyUSB0 AT+COPS?" //确保模块注册上运营商网络
#define CONN_FM350_CMD3 "atcmdtool -d /dev/ttyUSB0 AT+CGREG?" //模块附着数据网络
#define CONN_FM350_CMD4 "atcmdtool -d /dev/ttyUSB0 AT+CGDCONT?" //查询接入点信息
#define CONN_FM350_CMD5 "atcmdtool -d /dev/ttyUSB0 AT+CGACT=1,0" //激活pdn
#define CONN_FM350_CMD6 "atcmdtool -d /dev/ttyUSB0 AT+CGPADDR=0" //拨号开启

int get_shell_output(char *cmd, char *buffer, int length)
{
    FILE *fp;   

    fp = popen(cmd, "r"); 
    fgets(buffer, length, fp); 
    pclose(fp);
    //printf("%s",buffer);
}

/*获取fm350 rndis生成的eth网口*/
void get_rndis_ethport(char *ethport)
{
    char buffer[80] = {0};
    char *ret;
    get_shell_output(RNDIS_KEY_STRING, buffer, sizeof(buffer));
    ret = strstr(buffer, "eth");
    strncpy(ethport, ret, 4);
}


/*查询可用的network的wan配置，并配置fm350作为其中一个wan*/
void set_fm350_to_wan(char *ethport)
{
    char get_wan_cmd0[100] = "uci set network.wan10=interface";
    char get_wan_cmd1[100];
    sprintf(get_wan_cmd1, "%s%s", "uci set network.wan10.device=", ethport);
    char get_wan_cmd2[100] = "uci set network.wan10.proto=static";
    char get_wan_cmd3[100] = "uci set network.wan10.netmask=255.255.255.0";

    system(get_wan_cmd0);
    system(get_wan_cmd1);
    system(get_wan_cmd2);
    system(get_wan_cmd3);
    system("uci commit");
}

int check_sim_card_ready()
{
    char *ret;
    char buffer[80] = {0};
    get_shell_output(CONN_FM350_CMD0" | grep +CPIN:", buffer, sizeof(buffer));
    ret = strstr(buffer, "READY");
    if(ret != NULL)
        return 1;
    else 
        return 0;
    return 0;
}

void set_fm350_module_info_to_uci()
{
    char set_fm350_cmd0[100] = "uci set lte5g.fm350=module";
    char set_fm350_cmd1[100] = "uci set lte5g.fm350.apn=0,\"IPV4V6\",\"CMNET\"";
    system(set_fm350_cmd0);
    system(set_fm350_cmd1);
    /*写入SIM卡就绪的状态*/
    if(1 == check_sim_card_ready())
        system("uci set lte5g.fm350.sim=1");
    else
        system("uci set lte5g.fm350.sim=0");

    system("uci commit");

}

int get_ip_func(char* source, char* buf)
{
    int i=0,j=0,flag=0;
    while(source[i]!='\0')
    {
        if(flag==0 && source[i]=='\"')
        {
            flag=1;
        }
        else if(flag==1 && source[i]=='\"')
        {
            buf[j]='\0';
            return 1;
        }
        else if(flag==1 && source[i]!='\"')
        {
            buf[j++]=source[i];
        }
        i++;
    }
    return 0;
}

/*拨号*/
void set_fm350_connect()
{
    /*获取和设置apn*/
    char fm350_apn[80] = {0};
    char set_fm350_apn_cmd[200] = {0};
    get_shell_output("uci get lte5g.fm350.apn", fm350_apn, sizeof(fm350_apn));
    sprintf(set_fm350_apn_cmd, "%s%s", "atcmdtool -d /dev/ttyUSB0 AT+CGDCONT=", fm350_apn);
    system(set_fm350_apn_cmd);
    
    /*激活pdn*/
    system("atcmdtool -d /dev/ttyUSB0 AT+CGACT=1,0");

    /*获取IP*/
    char fm350_ip[80] = {0};
    char ip_act[20] = {0};
    char *ret;
    int index = 0, start = 0, end = 0;
    get_shell_output(CONN_FM350_CMD6" | grep +CGPADDR:", fm350_ip, sizeof(fm350_ip));
    if(strlen(fm350_ip) < 5)
    {
        printf("Get IP ERROR!\n");
        /*UCI写个状态，表示拨号失败*/
        system("uci set lte5g.fm350.connstatus=0");
        system("uci commit");
        exit(0);
    } 
    /*解析IP*/
    get_ip_func(fm350_ip, ip_act);
    /*将IP设置到UCI中*/
    char uci_fm350_set_ip_cmd[80] = {0};
    sprintf(uci_fm350_set_ip_cmd, "%s%s", "uci set network.wan10.ipaddr=", ip_act);
    system(uci_fm350_set_ip_cmd);
}

int main(int argc, char **argv)
{
    /*获取rndis网络节点名称*/
    char ethport[5] = {0};
    get_rndis_ethport(ethport);
    ethport[sizeof(ethport) - 1] = 0;
    
    /*配置uci将rndis网口作为wan口*/
    set_fm350_to_wan(ethport);

    /*读取模组信息并写入lte5g uci文件*/
    set_fm350_module_info_to_uci();

    /*拨号*/
    set_fm350_connect();

    return 0;
}

