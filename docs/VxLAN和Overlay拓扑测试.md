### VxLAN和Overlay的测试



测试均关闭了防火墙。因为测试其它功能使用的ip-full，所以这里的ip命令是iprouter2静态编译的程序。



#### 1. 拓扑结构

![image-20220406215720262](.\pic\image-20220406215720262-16492534416831.png)

PC1和PC2不在同一个LAN中，我们建立vxlan隧道，让PC1和PC2互通。



#### 2. PC配置

PC1设置ip为192.168.1.2，网关为192.168.1.1;

PC2设置ip为192.168.1.3，网关为192.168.1.100;

OpenWrt1的网关为192.168.100.200;

OpenWrt的网关为192.168.100.100。

在配置VxLAN之前PC1和PC2是不通的。我们通过配置VxLAN将PC1和PC2处于大二层，这样两台设备可以互通。



#### 3. OpenWRT配置：

```
# A
ip link add vxlan100 type vxlan id 100 remote 192.168.100.200 dstport 4789 dev eth1
ip link set vxlan100 up
brctl addif br-lan vxlan100
ip route add default via 192.168.100.200
#B
ip link add vxlan100 type vxlan id 100 remote 192.168.100.100 dstport 4789 dev eth1
ip link set vxlan100 up
brctl addif br-lan vxlan100
ip route add default via 192.168.100.100
```

此时PC1和PC2互通了。

我们在eth1处抓包可见vxlan包。

```
22:01:35.101885 IP 192.168.100.100.49404 > 192.168.100.200.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::4883:4dbb:c463:a97f.65142 > fe80::b14f:c4a6:edef:cbcc.5355: UDP, length 154
22:01:35.102249 IP 192.168.100.200.42097 > 192.168.100.100.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::b14f:c4a6:edef:cbcc.49566 > fe80::4883:4dbb:c463:a97f.5355: UDP, length 154
22:01:35.102451 IP 192.168.100.100.35434 > 192.168.100.200.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::4883:4dbb:c463:a97f.5355 > fe80::b14f:c4a6:edef:cbcc.53364: UDP, length 182
22:01:35.103300 IP 192.168.100.100.44159 > 192.168.100.200.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::4883:4dbb:c463:a97f.5355 > fe80::b14f:c4a6:edef:cbcc.49566: UDP, length 154
```



#### Overlay测试

在VxLAN隧道上进行IPSec加密。

我们在WAN侧上配置IPSec:

```
#A
ip xfrm state add src 192.168.100.100 dst 192.168.100.200 proto esp spi 0x00004005 mode tunnel auth md5 0xa87ff679a2f3e71d9181a67b7542122c enc des 0xa2f3e71d9181a67b
ip xfrm state add src 192.168.100.200 dst 192.168.100.100 proto esp spi 0x00005004 mode tunnel auth md5 0xa87ff679a2f3e71d9181a67b7542122c enc des 0xa2f3e71d9181a67b
ip xfrm policy add src 192.168.100.100 dst 192.168.100.200 dir out tmpl src 192.168.100.100 dst 192.168.100.200 proto esp mode tunnel
ip xfrm policy add src 192.168.100.200 dst 192.168.100.100 dir in tmpl src 192.168.100.200 dst 192.168.100.100 proto esp mode tunnel
#B
ip xfrm state add src 192.168.100.100 dst 192.168.100.200 proto esp spi 0x00004005 mode tunnel auth md5 0xa87ff679a2f3e71d9181a67b7542122c enc des 0xa2f3e71d9181a67b
ip xfrm state add src 192.168.100.200 dst 192.168.100.100 proto esp spi 0x00005004 mode tunnel auth md5 0xa87ff679a2f3e71d9181a67b7542122c enc des 0xa2f3e71d9181a67b
ip xfrm policy add src 192.168.100.100 dst 192.168.100.200 dir in tmpl src 192.168.100.100 dst 192.168.100.200 proto esp mode tunnel
ip xfrm policy add src 192.168.100.200 dst 192.168.100.100 dir out tmpl src 192.168.100.200 dst 192.168.100.100 proto esp mode tunnel
```

然后PC2->PC1，在A侧抓包eth1，应可以看到来的VxLAN包（到达时解密）和回的ESP包（VxLAN已加密）：

```
13:17:51.598171 IP 192.168.100.200.35123 > 192.168.100.100.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::b554:4f71:a395:d9fd.60402 > fe80::e836:ad8d:2419:be52.5355: UDP, length 210
13:17:51.598171 IP 192.168.100.200.42032 > 192.168.100.100.4789: VXLAN, flags [I] (0x08), vni 100
IP6 fe80::b554:4f71:a395:d9fd.5355 > fe80::e836:ad8d:2419:be52.58932: UDP, length 210
13:17:51.598605 IP 192.168.100.100 > 192.168.100.200: ESP(spi=0x00004005,seq=0x1719d), length 340
13:17:51.599544 IP 192.168.100.100 > 192.168.100.200: ESP(spi=0x00004005,seq=0x1719e), length 340
13:17:51.599786 IP 192.168.100.200.35218 > 192.168.100.100.4789: VXLAN, flags [I] (0x08), vni 100
```

