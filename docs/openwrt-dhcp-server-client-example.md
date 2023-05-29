### OpenWrt的DHCP功能测试

#### 1. 说明



#### 2. 网络拓扑及测试说明

图暂时略。

如上图所示，我们的PC1连入R0的LAN侧，R0的WAN侧上行，正常情况下：

（1）R0应能正常通过dhcp获取IP

（2）PC1应能获取R0的LAN侧的IP

#### 3. 测试

（1）虚拟机R0的配置

将虚拟机R0配置双网卡，其中一个网卡作为WAN(映射到系统中是eth0)，另外一个网卡添加到虚拟机网桥LAN1中，虚拟机R0的配置如下所示：

![](\pic\DHCP1.png)

其中OpenWrt的配置如下所示：

```
root@OpenWrt:~# cat /etc/config/network 

config interface 'loopback'
	option device 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fdb9:0938:6210::/48'

config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth1'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.110.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth0'
	option proto 'dhcp'

config interface 'wan6'
	option device 'eth1'
	option proto 'dhcpv6'

```

设置LAN侧的网段为192.168.110.0/24，重启网络服务后，这时候我们的PC1应能获取到此网段的IP。



（2）虚拟机PC1的配置

虚拟机PC1配置单网卡即可，将唯一的网卡添加到虚拟机网桥LAN1中，这样相当于PC1的eth0和R0的eth1在同一个私网中了。虚拟机PC1的配置如下所示：

![](\pic\DHCP1.png)

其中OpenWrt的配置如下所示：

```
root@OpenWrt:~# cat /etc/config/network 

config interface 'loopback'
	option device 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fd46:a123:6a1c::/48'

config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth1'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.1.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth0'
	option proto 'dhcp'

```

重启网络服务后，在PC1中执行ifconfig查看eth0的IP，结果如下所示：

```
root@OpenWrt:~# ifconfig 
eth0      Link encap:Ethernet  HWaddr 00:0C:29:8B:42:51  
          inet addr:192.168.110.177  Bcast:192.168.110.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe8b:4251/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:701 errors:0 dropped:0 overruns:0 frame:0
          TX packets:1184 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:88609 (86.5 KiB)  TX bytes:121801 (118.9 KiB)
          Interrupt:19 Base address:0x2000 

```

OK！测试证明此系统拥有dhcp server和dhcp client的能力。

