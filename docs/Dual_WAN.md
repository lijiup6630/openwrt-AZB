### Dual WAN



由于现在4/5G模组还没有，这里先测试双Ethernet的作为WAN的双上联情况。



#### 1. 环境

测试双WAN上联，双WAN分别为eth0,eth3。其中eth4划到br-lan中，作为远程监控口。

eth0和eth3分别作为WAN/WAN1，均为dhcp获取不同switch LAN的ip。当设备往外发包时，会按照网口的metric的设置进行发包。如果一方断开后另一方会继续，断开的一方恢复后会切换过来。我们模拟这个场景，并且抓包观察网口的包的数量进行判断。

#### 2. 测试拓扑图



#### 3. 测试

UCI的配置如下所示：

```
config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth4'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.100.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth0'
	option proto 'dhcp'
	option metric '60'

config interface 'wan1'
	option device 'eth3'
	option proto 'dhcp'
	option metric '80'
```

此时设备学习到了IP地址，分别为：

```
eth0      Link encap:Ethernet  HWaddr A0:36:9F:5D:14:04  
          inet addr:192.168.2.237  Bcast:192.168.2.255  Mask:255.255.255.0
          inet6 addr: fe80::a236:9fff:fe5d:1404/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:3234 errors:0 dropped:0 overruns:0 frame:0
          TX packets:2826 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:1781740 (1.6 MiB)  TX bytes:866587 (846.2 KiB)
          Memory:6c500000-6c5fffff 
eth3      Link encap:Ethernet  HWaddr A0:36:9F:5D:14:07  
          inet addr:192.168.1.21  Bcast:192.168.1.255  Mask:255.255.255.0
          inet6 addr: fe80::a236:9fff:fe5d:1407/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:260 errors:0 dropped:18 overruns:0 frame:0
          TX packets:197 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:29140 (28.4 KiB)  TX bytes:18093 (17.6 KiB)
          Memory:6c200000-6c2fffff 
```

由于wan的metric优先级高，所以默认优先走wan，当wan断开后走wan1。

向外ping包：

```
root@OpenWrt:/# ping 114.114.114.114
PING 114.114.114.114 (114.114.114.114): 56 data bytes
64 bytes from 114.114.114.114: seq=0 ttl=95 time=4.814 ms
64 bytes from 114.114.114.114: seq=1 ttl=73 time=4.656 ms
64 bytes from 114.114.114.114: seq=2 ttl=70 time=6.698 ms
64 bytes from 114.114.114.114: seq=3 ttl=88 time=5.231 ms
64 bytes from 114.114.114.114: seq=4 ttl=66 time=4.739 ms
64 bytes from 114.114.114.114: seq=5 ttl=65 time=5.417 ms
64 bytes from 114.114.114.114: seq=6 ttl=77 time=4.848 ms
64 bytes from 114.114.114.114: seq=7 ttl=83 time=4.845 ms
64 bytes from 114.114.114.114: seq=8 ttl=89 time=4.920 ms
[  384.605483] igb 0000:56:00.0 eth0: igb: eth0 NIC Link is Down
[  384.746676] 8021q: adding VLAN 0 to HW filter on device eth0
64 bytes from 114.114.114.114: seq=9 ttl=70 time=3.382 ms
64 bytes from 114.114.114.114: seq=10 ttl=71 time=3.527 ms
64 bytes from 114.114.114.114: seq=11 ttl=94 time=3.730 ms
64 bytes from 114.114.114.114: seq=12 ttl=88 time=3.620 ms
64 bytes from 114.114.114.114: seq=13 ttl=77 time=3.510 ms
64 bytes from 114.114.114.114: seq=14 ttl=80 time=3.185 ms
64 bytes from 114.114.114.114: seq=15 ttl=96 time=3.356 ms
64 bytes from 114.114.114.114: seq=16 ttl=84 time=3.460 ms
64 bytes from 114.114.114.114: seq=17 ttl=92 time=3.333 ms
64 bytes from 114.114.114.114: seq=18 ttl=74 time=3.748 ms
[  395.065444] igb 0000:56:00.0 eth0: igb: eth0 NIC Link is Up 100 Mbps Full Duplex, Flow Control: RX/TX
64 bytes from 11[  395.075925] IPv6: ADDRCONF(NETDEV_CHANGE): eth0: link becomes ready
4.114.114.114: seq=19 ttl=84 time=3.227 ms
64 bytes from 114.114.114.114: seq=20 ttl=83 time=5.219 ms
64 bytes from 114.114.114.114: seq=21 ttl=80 time=4.765 ms
```

当ping动作开始执行时，从eth0上可见抓包，eth3上未见：

```
root@OpenWrt:~# tcpdump -i eth0 -v dst 114.114.114.114
tcpdump: listening on eth0, link-type EN10MB (Ethernet), capture size 262144 bytes
06:40:17.516574 IP (tos 0x0, ttl 64, id 17075, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 0, length 64
06:40:18.516900 IP (tos 0x0, ttl 64, id 17085, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 1, length 64
06:40:19.517214 IP (tos 0x0, ttl 64, id 17140, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 2, length 64
06:40:20.517541 IP (tos 0x0, ttl 64, id 17237, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 3, length 64
06:40:21.517848 IP (tos 0x0, ttl 64, id 17303, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 4, length 64
06:40:22.518176 IP (tos 0x0, ttl 64, id 17310, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 5, length 64
06:40:23.518494 IP (tos 0x0, ttl 64, id 17359, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 6, length 64
06:40:24.518865 IP (tos 0x0, ttl 64, id 17445, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 7, length 64
06:40:25.519188 IP (tos 0x0, ttl 64, id 17457, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 8, length 64
```

此时断开eth0，观察到eth3有了抓包：

```
root@OpenWrt:~# tcpdump -i eth3 -v dst 114.114.114.114
tcpdump: listening on eth3, link-type EN10MB (Ethernet), capture size 262144 bytes
06:40:26.519518 IP (tos 0x0, ttl 64, id 37852, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 9, length 64
06:40:27.519853 IP (tos 0x0, ttl 64, id 37902, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 10, length 64
06:40:28.520189 IP (tos 0x0, ttl 64, id 37961, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 11, length 64
06:40:29.520514 IP (tos 0x0, ttl 64, id 37967, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 12, length 64
06:40:30.520836 IP (tos 0x0, ttl 64, id 38052, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 13, length 64
06:40:31.521151 IP (tos 0x0, ttl 64, id 38143, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 14, length 64
06:40:32.521499 IP (tos 0x0, ttl 64, id 38212, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 15, length 64
06:40:33.521836 IP (tos 0x0, ttl 64, id 38289, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 16, length 64
06:40:34.522161 IP (tos 0x0, ttl 64, id 38305, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 17, length 64
06:40:35.522478 IP (tos 0x0, ttl 64, id 38387, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 18, length 64
06:40:36.522630 IP (tos 0x0, ttl 64, id 38487, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.21 > 114.114.114.114: ICMP echo request, id 6733, seq 19, length 64
```

此时插上eth0，包又回去了。

```
06:40:37.523343 IP (tos 0x0, ttl 64, id 17528, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 20, length 64
06:40:38.523313 IP (tos 0x0, ttl 64, id 17621, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 21, length 64
06:40:39.523633 IP (tos 0x0, ttl 64, id 17660, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 22, length 64
06:40:40.523979 IP (tos 0x0, ttl 64, id 17726, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 23, length 64
06:40:41.524209 IP (tos 0x0, ttl 64, id 17739, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 24, length 64
06:40:42.524328 IP (tos 0x0, ttl 64, id 17831, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.2.237 > 114.114.114.114: ICMP echo request, id 6733, seq 25, length 64
```





