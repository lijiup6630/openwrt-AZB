### OpenWrt的三层转发功能测试

#### 1. 说明

验证OpenWrt的三层转发功能

#### 2. 网络拓扑及测试说明
[![image-20220303151955.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed31043800a059507b43a02fd334c287bba/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed31043800a059507b43a02fd334c287bba/0.png)

如上图所示，PC1连入R1的LAN侧，R1和R2WAN口相连。
正常情况下，PC1可以ping通R2。

#### 3. 测试

（1）虚拟机R1的配置

将虚拟机R1配置双网卡，其中一个网卡作为WAN(映射到系统中是eth1)，另外一个网卡添加到虚拟机网桥LAN1中，虚拟机R0的网络配置如下所示：
[![image-20220303142921.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3ad44b92e16a491b26412d768984d8255/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3ad44b92e16a491b26412d768984d8255/0.png)

其中OpenWrt的配置如下所示：

```
root@OpenWrt:~# cat /etc/config/network 

config interface 'loopback'
	option device 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fd81:e072:031d::/48'

config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth0'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.1.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '192.168.129.135'
	option netmask '255.255.255.0'
	option dns '223.5.5.5'
	option gateway '192.168.129.2'

```

(2)虚拟机R2的配置

这里我们主要关心R2的WAN口

openwrt的配置如下所示：
```
root@OpenWrt:~# cat /etc/config/network 

config interface 'loopback'
	option device 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fd81:e072:031d::/48'

config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth0'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.2.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '192.168.129.131'
	option netmask '255.255.255.0'
	option dns '223.5.5.5'
	option gateway '192.168.129.2'

```

(3)虚拟机PC1的配置如下所示：

虚拟机PC1配置单网卡即可，将唯一的网卡添加到虚拟机网桥LAN1中，这样相当于PC1的eth0和R1的eth0在同一个私网中了。
[![image-20220303154535pc1.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3765b84c7bfa209d23e5ece64d0430715/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3765b84c7bfa209d23e5ece64d0430715/0.png)

openwrt配置如下所示：

[![imagelay3-20220303155712.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3f2d7be131342e54cb7bf42ad2301019f/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3f2d7be131342e54cb7bf42ad2301019f/0.png)

[![imagelay3-20220303155738.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed34330e771b1faf027dae2a95b6beb7e62/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed34330e771b1faf027dae2a95b6beb7e62/0.png)

在PC1上 ping R2 的 wan口：

[![imagelay2ping-20220303160044.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3c5fc630b9eb91148726b42d8e18748d1/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3c5fc630b9eb91148726b42d8e18748d1/0.png)

发现能够ping通，验证三层转发成功。