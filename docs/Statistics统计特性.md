### Statistics统计特性



#### 1. 目的

OpenWrt应具备统计功能，并可通过简易的方式来查看。

#### 2. 支持的特性

OpenWrt提供了collected机制，并提供了几十种统计功能，以下以luci的统计试图来说明

##### （1）处理器

![image-20220502215403456](E:\openwrt-x86-文档\pic\image-20220502215403456.png)

##### （2）网口

![image-20220502215439923](E:\openwrt-x86-文档\pic\image-20220502215439923-16514996814211.png)

##### （3）系统负荷

![image-20220502215459093](E:\openwrt-x86-文档\pic\image-20220502215459093-16514997003622.png)

##### （4）内存

![image-20220502215525264](E:\openwrt-x86-文档\pic\image-20220502215525264-16514997264283.png)



#### 3. 统计全功能

```
# CONFIG_PACKAGE_COLLECTD_ENCRYPTED_NETWORK is not set
# CONFIG_PACKAGE_COLLECTD_DEBUG_OUTPUT_ENABLE is not set
# CONFIG_PACKAGE_collectd-mod-apache is not set
# CONFIG_PACKAGE_collectd-mod-apcups is not set
# CONFIG_PACKAGE_collectd-mod-ascent is not set
# CONFIG_PACKAGE_collectd-mod-bind is not set
# CONFIG_PACKAGE_collectd-mod-chrony is not set
# CONFIG_PACKAGE_collectd-mod-conntrack is not set
# CONFIG_PACKAGE_collectd-mod-contextswitch is not set
CONFIG_PACKAGE_collectd-mod-cpu=y
CONFIG_PACKAGE_collectd-mod-cpufreq=y
# CONFIG_PACKAGE_collectd-mod-csv is not set
# CONFIG_PACKAGE_collectd-mod-curl is not set
# CONFIG_PACKAGE_collectd-mod-df is not set
# CONFIG_PACKAGE_collectd-mod-dhcpleases is not set
# CONFIG_PACKAGE_collectd-mod-disk is not set
# CONFIG_PACKAGE_collectd-mod-dns is not set
# CONFIG_PACKAGE_collectd-mod-email is not set
# CONFIG_PACKAGE_collectd-mod-entropy is not set
CONFIG_PACKAGE_collectd-mod-ethstat=y
# CONFIG_PACKAGE_collectd-mod-exec is not set
# CONFIG_PACKAGE_collectd-mod-filecount is not set
# CONFIG_PACKAGE_collectd-mod-fscache is not set
CONFIG_PACKAGE_collectd-mod-interface=y
CONFIG_PACKAGE_collectd-mod-ipstatistics=y
# CONFIG_PACKAGE_collectd-mod-iptables is not set
CONFIG_PACKAGE_collectd-mod-irq=y
CONFIG_PACKAGE_collectd-mod-iwinfo=y
CONFIG_PACKAGE_collectd-mod-load=y
# CONFIG_PACKAGE_collectd-mod-logfile is not set
# CONFIG_PACKAGE_collectd-mod-lua is not set
# CONFIG_PACKAGE_collectd-mod-match-empty-counter is not set
# CONFIG_PACKAGE_collectd-mod-match-hashed is not set
# CONFIG_PACKAGE_collectd-mod-match-regex is not set
# CONFIG_PACKAGE_collectd-mod-match-timediff is not set
# CONFIG_PACKAGE_collectd-mod-match-value is not set
CONFIG_PACKAGE_collectd-mod-memory=y
# CONFIG_PACKAGE_collectd-mod-modbus is not set
# CONFIG_PACKAGE_collectd-mod-mqtt is not set
# CONFIG_PACKAGE_collectd-mod-mysql is not set
# CONFIG_PACKAGE_collectd-mod-netlink is not set
CONFIG_PACKAGE_collectd-mod-network=y
# CONFIG_PACKAGE_collectd-mod-nginx is not set
# CONFIG_PACKAGE_collectd-mod-ntpd is not set
# CONFIG_PACKAGE_collectd-mod-olsrd is not set
# CONFIG_PACKAGE_collectd-mod-openvpn is not set
CONFIG_PACKAGE_collectd-mod-ping=y
# CONFIG_PACKAGE_collectd-mod-postgresql is not set
CONFIG_PACKAGE_collectd-mod-powerdns=y
# CONFIG_PACKAGE_collectd-mod-processes is not set
# CONFIG_PACKAGE_collectd-mod-protocols is not set
# CONFIG_PACKAGE_collectd-mod-routeros is not set
CONFIG_PACKAGE_collectd-mod-rrdtool=y
# CONFIG_PACKAGE_collectd-mod-sensors is not set
# CONFIG_PACKAGE_collectd-mod-smart is not set
# CONFIG_PACKAGE_collectd-mod-snmp is not set
# CONFIG_PACKAGE_collectd-mod-snmp6 is not set
# CONFIG_PACKAGE_collectd-mod-sqm is not set
# CONFIG_PACKAGE_collectd-mod-swap is not set
# CONFIG_PACKAGE_collectd-mod-syslog is not set
# CONFIG_PACKAGE_collectd-mod-table is not set
# CONFIG_PACKAGE_collectd-mod-tail is not set
# CONFIG_PACKAGE_collectd-mod-tail-csv is not set
# CONFIG_PACKAGE_collectd-mod-tcpconns is not set
# CONFIG_PACKAGE_collectd-mod-teamspeak2 is not set
# CONFIG_PACKAGE_collectd-mod-ted is not set
CONFIG_PACKAGE_collectd-mod-thermal=y
# CONFIG_PACKAGE_collectd-mod-threshold is not set
# CONFIG_PACKAGE_collectd-mod-unixsock is not set
# CONFIG_PACKAGE_collectd-mod-uptime is not set
# CONFIG_PACKAGE_collectd-mod-users is not set
# CONFIG_PACKAGE_collectd-mod-vmem is not set
CONFIG_PACKAGE_collectd-mod-wireless=y
# CONFIG_PACKAGE_collectd-mod-write-graphite is not set
# CONFIG_PACKAGE_collectd-mod-write-http is not set
```

