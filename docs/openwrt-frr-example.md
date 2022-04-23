### OpenWrt的frr功能测试

#### 1. 说明

#### 2.网络拓扑及测试说明

R1和R2的WAN口是直连的。

R1的WAN口IP为192.168.234.137/24，LAN侧为192.168.1.1；

R2的WAN口IP为192.168.234.138/24，LAN侧为192.168.10.1；

这里我的LAN口并没有建桥，使用的是实际的独立的物理网卡。我们的目的是通过frr进行一个动态路由学习，让R1和R2的LAN侧都可以学习到到对端的路由。

我的R1此刻的状态：

```
root@OpenWrt:~# ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:77:32:5a brd ff:ff:ff:ff:ff:ff
    inet 192.168.234.137/24 brd 192.168.234.255 scope global eth0
       valid_lft forever preferred_lft forever
    inet6 fe80::20c:29ff:fe77:325a/64 scope link 
       valid_lft forever preferred_lft forever
3: eth1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:77:32:64 brd ff:ff:ff:ff:ff:ff
    inet 192.168.1.1/24 brd 192.168.1.255 scope global eth1
       valid_lft forever preferred_lft forever
    inet6 fe80::20c:29ff:fe77:3264/64 scope link 
       valid_lft forever preferred_lft forever
root@OpenWrt:~# ip r
default via 192.168.234.2 dev eth0 proto static src 192.168.234.137 
192.168.1.0/24 dev eth1 proto kernel scope link src 192.168.1.1 
192.168.234.0/24 dev eth0 proto kernel scope link src 192.168.234.137 
```

我的R2此刻的状态：

```
root@OpenWrt:~# ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:b6:f7:ea brd ff:ff:ff:ff:ff:ff
    inet 192.168.234.138/24 brd 192.168.234.255 scope global eth0
       valid_lft forever preferred_lft forever
    inet6 fe80::20c:29ff:feb6:f7ea/64 scope link 
       valid_lft forever preferred_lft forever
3: eth1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:b6:f7:f4 brd ff:ff:ff:ff:ff:ff
    inet 192.168.10.1/24 brd 192.168.10.255 scope global eth1
       valid_lft forever preferred_lft forever
    inet6 fe80::20c:29ff:feb6:f7f4/64 scope link 
       valid_lft forever preferred_lft forever
root@OpenWrt:~# ip r
default via 192.168.234.2 dev eth0 proto static src 192.168.234.138 
192.168.10.0/24 dev eth1 proto kernel scope link src 192.168.10.1 
192.168.234.0/24 dev eth0 proto kernel scope link src 192.168.234.138 

```



#### 3. 配置

我的R1的frr配置：

```
root@OpenWrt:~# vim /etc/frr/daemons 

# The staticd,watchfrr and zebra daemons are always started.
#
bgpd=yes
ospfd=no
#ospfd_instances=1,20
ospf6d=no

root@OpenWrt:~# /etc/init.d/frr restart
Stopped zebra
Stopped watchfrr
cannot start staticd: daemon binary not installed
Started watchfrr
```

R1的vtysh配置：

```
root@OpenWrt:~# vtysh 

Hello, this is FRRouting (version 8.2).
Copyright 1996-2005 Kunihiro Ishiguro, et al.

OpenWrt# conf t
OpenWrt(config)# ip router-id 1.1.1.1
OpenWrt(config)# router bgp 100
OpenWrt(config-router)# neighbor 192.168.234.138 remote-as 100
OpenWrt(config-router)# network 192.168.1.0/24
OpenWrt(config-router)# end
```

这时候可以通过show running-config来查看下R1配置：

```
ip router-id 1.1.1.1
!
router bgp 100
 neighbor 192.168.234.138 remote-as 100
 !
 address-family ipv4 unicast
  network 192.168.1.0/24
 exit-address-family
exit
```

我的R2的frr配置同R1，但是vtysh配置不同：

```
root@OpenWrt:~# vim /etc/frr/daemons 
root@OpenWrt:~# /etc/init.d/frr restart
Stopped zebra
Stopped watchfrr
cannot start staticd: daemon binary not installed
Started watchfrr
```

vtysh的设置：

```
root@OpenWrt:~# vtysh 

Hello, this is FRRouting (version 8.2).
Copyright 1996-2005 Kunihiro Ishiguro, et al.

OpenWrt# conf t
OpenWrt(config)# ip router-id 1.1.1.2
OpenWrt(config)# router bgp 100
OpenWrt(config-router)# neighbor 192.168.234.137 remote-as 100
OpenWrt(config-router)# network 192.168.10.0/24
OpenWrt(config-router)# 
OpenWrt(config-router)# end
```

这时候可以通过show running-config来查看下R2配置：

```
OpenWrt# show running-config 
Building configuration...

Current configuration:
!
frr version 8.2
frr defaults traditional
hostname OpenWrt
log syslog
!
password zebra
!
ip router-id 1.1.1.2
!
router bgp 100
 neighbor 192.168.234.137 remote-as 100
 !
 address-family ipv4 unicast
  network 192.168.10.0/24
 exit-address-family
exit
```



#### 3.测试

由于我没有启用BFD功能，所以广播完子网后可能会有个timeout的时间来获取路由，这里需要注意一下。

此时vtysh查看R1的frr中的路由：

```
OpenWrt# show bgp neighbors 
BGP neighbor is 192.168.234.138, remote AS 100, local AS 100, internal link
Hostname: OpenWrt
  BGP version 4, remote router ID 1.1.1.2, local router ID 1.1.1.1
  BGP state = Established, up for 00:02:49
  Last read 00:00:49, Last write 00:00:49
  Hold time is 180, keepalive interval is 60 seconds
  Neighbor capabilities:
```

OK，已经和对端建立好了连接。继续查看frr中学到的路由：

```
OpenWrt# show ip fib
Codes: K - kernel route, C - connected, S - static, T - Table,
       > - selected route, * - FIB route, q - queued, r - rejected, b - backup
       t - trapped, o - offload failure

K>* 0.0.0.0/0 [0/0] via 192.168.234.2, eth0, src 192.168.234.137, 00:05:26
C>* 192.168.1.0/24 is directly connected, eth1, 00:05:26
B>* 192.168.10.0/24 [200/0] via 192.168.234.138, eth0, weight 1, 00:03:13
C>* 192.168.234.0/24 is directly connected, eth0, 00:05:26
OpenWrt# 
```

此时我们发现已经学习到了192.168.10.0/24的路由。然后我们查看OpenWrt的路由表：

```
root@OpenWrt:~# ip r
default via 192.168.234.2 dev eth0 proto static src 192.168.234.137 
192.168.1.0/24 dev eth1 proto kernel scope link src 192.168.1.1 
192.168.10.0/24 nhid 45 via 192.168.234.138 dev eth0 proto bgp metric 20 
192.168.234.0/24 dev eth0 proto kernel scope link src 192.168.234.137 
```

发现此时路由已经同步过来了。此时R1和R2的子网也就可以正常的通信了。

```
root@OpenWrt:~# ping 192.168.10.1 
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=64 time=1.203 ms
64 bytes from 192.168.10.1: seq=1 ttl=64 time=1.920 ms
```

同样的配置可以在R2上查看。
