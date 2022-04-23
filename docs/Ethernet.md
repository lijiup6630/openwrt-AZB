### Ethernet



以I350为例，基于pci接口的板卡，出了四个网口。



#### 1. 硬件可见性

在OpenWrt下查看对应的pcie接口：

```
root@OpenWrt:/# lspci
...
56:00.0 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
56:00.1 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
56:00.2 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
56:00.3 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
```

I350在硬件接口上是可见的。

#### 2. 网口识别

在OpenWrt上执行ip a查看I350生成的网络节点，按照硬件可见性的描述，应生成四个节点，由于设备上只有这一个网卡，所以命令默认应为eth0,eth1,eth2,eth3：

```
root@OpenWrt:/# ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq master br-lan state DOWN group default qlen 1000
    link/ether a0:36:9f:5d:14:04 brd ff:ff:ff:ff:ff:ff
3: eth1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether a0:36:9f:5d:14:05 brd ff:ff:ff:ff:ff:ff
4: eth2: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether a0:36:9f:5d:14:06 brd ff:ff:ff:ff:ff:ff
5: eth3: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether a0:36:9f:5d:14:07 brd ff:ff:ff:ff:ff:ff
```



#### 3. 网口连通性

测试各网口是否连通，一是测试单独网口的连通性，和对端通信，二是将各网口加到一个bridge domain中，查看是否正常和对端通信。

##### （1）单独

设置四个网口的ip地址分别为：

```
eth0: 192.168.10.2 -> 192.168.10.1
eth1: 192.168.11.2 -> 192.168.11.1
eth2: 192.168.12.2 -> 192.168.12.1
eth3: 192.168.13.2 -> 192.168.13.1
```

eth0测试结果：

```
root@OpenWrt:/# ping 192.168.10.1
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=128 time=2.644 ms
64 bytes from 192.168.10.1: seq=1 ttl=128 time=2.631 ms
64 bytes from 192.168.10.1: seq=2 ttl=128 time=2.481 ms
64 bytes from 192.168.10.1: seq=3 ttl=128 time=1.190 ms
```

eth1测试结果:

```
root@OpenWrt:/# ping 192.168.11.1
PING 192.168.11.1 (192.168.11.1): 56 data bytes
64 bytes from 192.168.11.1: seq=0 ttl=128 time=3.055 ms
64 bytes from 192.168.11.1: seq=1 ttl=128 time=0.971 ms
64 bytes from 192.168.11.1: seq=2 ttl=128 time=1.630 ms
64 bytes from 192.168.11.1: seq=3 ttl=128 time=1.746 ms
```

eth2测试结果：

```
root@OpenWrt:/# ping 192.168.12.1
PING 192.168.12.1 (192.168.12.1): 56 data bytes
64 bytes from 192.168.12.1: seq=0 ttl=128 time=0.927 ms
64 bytes from 192.168.12.1: seq=1 ttl=128 time=1.630 ms
64 bytes from 192.168.12.1: seq=2 ttl=128 time=1.544 ms
64 bytes from 192.168.12.1: seq=3 ttl=128 time=1.740 ms
```

eth3测试结果：

```
root@OpenWrt:/# ping 192.168.13.1
PING 192.168.13.1 (192.168.13.1): 56 data bytes
64 bytes from 192.168.13.1: seq=0 ttl=128 time=2.660 ms
64 bytes from 192.168.13.1: seq=1 ttl=128 time=1.475 ms
64 bytes from 192.168.13.1: seq=2 ttl=128 time=2.407 ms
64 bytes from 192.168.13.1: seq=3 ttl=128 time=2.349 ms
```



##### (2) bridge domain测试

将四个网口放入一个桥中，并给桥IP为192.168.10.2，测试和192.168.10.1的连通性：

eth0:

```
root@OpenWrt:/# ping 192.168.10.1
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=128 time=2.775 ms
64 bytes from 192.168.10.1: seq=1 ttl=128 time=1.475 ms
64 bytes from 192.168.10.1: seq=2 ttl=128 time=2.497 ms
64 bytes from 192.168.10.1: seq=3 ttl=128 time=2.663 ms
```

eth1:

```
root@OpenWrt:/# ping 192.168.10.1
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=128 time=2.802 ms
64 bytes from 192.168.10.1: seq=1 ttl=128 time=1.849 ms
64 bytes from 192.168.10.1: seq=2 ttl=128 time=1.503 ms
64 bytes from 192.168.10.1: seq=3 ttl=128 time=1.792 ms
```

eth2:

```
root@OpenWrt:/# ping 192.168.10.1
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=128 time=3.902 ms
64 bytes from 192.168.10.1: seq=1 ttl=128 time=1.511 ms
64 bytes from 192.168.10.1: seq=2 ttl=128 time=2.431 ms
64 bytes from 192.168.10.1: seq=3 ttl=128 time=2.357 ms
```

eth3:

```
root@OpenWrt:/# ping 192.168.10.1
PING 192.168.10.1 (192.168.10.1): 56 data bytes
64 bytes from 192.168.10.1: seq=0 ttl=128 time=3.184 ms
64 bytes from 192.168.10.1: seq=1 ttl=128 time=2.513 ms
64 bytes from 192.168.10.1: seq=2 ttl=128 time=2.320 ms
64 bytes from 192.168.10.1: seq=3 ttl=128 time=2.461 ms
```



