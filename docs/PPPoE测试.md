### PPPoE测试



#### 1. 部署PPPoE服务器

PPPoE服务器用Ubuntu部署的。实际上用OpenWrt可能会更好一些。网口IP为192.168.31.247。

```
dpkg -i pppoe_3.12-1.2ubuntu2_amd64.deb
```

然后这样安装的话会缺少两个文件，pppoe.conf和pppoe-server-options文件可以从以下链接获取：

```
https://gitee.com/mirrors/rp-pppoe/tree/master/configs
```

配置都在/etc/ppp下面。

##### options文件的配置：

```
root@ubuntu:/etc/ppp# cat options
ms-dns 114.114.114.114
asyncmap 0
noauth
crtscts
local
lock
hide-password
modem
-pap
+chap
proxyarp
lcp-echo-interval 30
lcp-echo-failure 4
noipx
```

其中+chap表示使用chap这种认证方式，然后将pppoe.conf和pppoe-server-options文件复制到/etc/ppp目录下。



##### 设置pppoe-server-options

```
root@ubuntu:/etc/ppp# cat pppoe-server-options 
require-chap
auth
lcp-echo-interval 10
lcp-echo-failure 2
ms-dns 114.114.114.114
```

##### chap-secrets文件

```
root@ubuntu:/etc/ppp# cat chap-secrets 
# Secrets for authentication using CHAP
# client	server	secret			IP addresses
test * "123456" *
```

##### 启动server

```
pppoe-server -I ens38 -L 192.168.172.79 -R 192.168.172.5 -N 10
```

正常的话pppoe拨号成功后会拿到192.168.172.0/24段的IP

####  2. OpenWrt配置

OpenWrt配置如下：

```
root@OpenWrt:~# cat /etc/config/network 

config interface 'wan'
	option device 'eth1'
	option proto 'dhcp'

config interface 'wan1'
	option device 'eth0'
	option proto 'dhcp'

config interface 'pppoe0'
	option proto 'pppoe'
	option device 'eth0'
	option username 'test'
	option password '123456'
	option ipv6 'auto'
```

我是eth0和server在一个LAN下，所以能获得到同段的IP，然后PPPoE拨号成功：

```
pppoe-pppoe0 Link encap:Point-to-Point Protocol  
          inet addr:192.168.172.5  P-t-P:192.168.172.79  Mask:255.255.255.255
          UP POINTOPOINT RUNNING NOARP MULTICAST  MTU:1492  Metric:1
          RX packets:34 errors:0 dropped:0 overruns:0 frame:0
          TX packets:73 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:3 
          RX bytes:300 (300.0 B)  TX bytes:3140 (3.0 KiB)
```

IP和我的预设是一样的。