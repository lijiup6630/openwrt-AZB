```
# 先配置通路
# HOST
ip netns add ns0
ip link add vpp0 type veth peer name vethns0
ip link set vethns0 netns ns0
ip netns exec ns0 ip link set lo up
ip netns exec ns0 ip link set vethns0 up
ip netns exec ns0 ip addr add 192.168.1.1/24 dev vethns0

# VPP
create host-interface name vpp0
set interface state host-vpp0 up
set interface ip addr host-vpp0 192.168.1.100/24

#配置ns vlan
ip netns exec ns0 ip link add link vethns0 name vethns0.100 type vlan id 100
ip netns exec ns0 ip a
ip netns exec ns0 ip link set vethns0.100 up
ip netns exec ns0 ip addr add 192.168.63.1/24 dev vethns0.100

# 配置VPP
create sub-interfaces host-vpp0 100
set interface ip address host-vpp0.100 192.168.63.100/24
set interface state host-vpp0.100 up

```



测试下：

```
#ns -> vpp
root@Kylin:~/vpp-space/build-root# ip netns exec ns0 ping 192.168.63.100
PING 192.168.63.100 (192.168.63.100) 56(84) bytes of data.
64 bytes from 192.168.63.100: icmp_seq=1 ttl=64 time=0.219 ms
64 bytes from 192.168.63.100: icmp_seq=2 ttl=64 time=0.083 ms
64 bytes from 192.168.63.100: icmp_seq=3 ttl=64 time=0.075 ms
64 bytes from 192.168.63.100: icmp_seq=4 ttl=64 time=0.068 ms
^C
--- 192.168.63.100 ping statistics ---

#vpp -> ns
vpp# ping 192.168.63.1
116 bytes from 192.168.63.1: icmp_seq=1 ttl=64 time=9.2008 ms
116 bytes from 192.168.63.1: icmp_seq=2 ttl=64 time=2.1389 ms
116 bytes from 192.168.63.1: icmp_seq=3 ttl=64 time=6.1580 ms
116 bytes from 192.168.63.1: icmp_seq=4 ttl=64 time=9.1552 ms
116 bytes from 192.168.63.1: icmp_seq=5 ttl=64 time=3.1452 ms

Statistics: 5 sent, 5 received, 0% packet loss
```

抓包验证：

```
# vpp
vpp# ping 192.168.63.1 repeat 1000
116 bytes from 192.168.63.1: icmp_seq=1 ttl=64 time=10.1697 ms

#ns
root@Kylin:~/vpp-space/build-root# ip netns exec ns0 tcpdump -i vethns0 -XXnvv
tcpdump: listening on vethns0, link-type EN10MB (Ethernet), capture size 262144 bytes
^C11:15:50.029654 IP (tos 0x0, ttl 254, id 0, offset 0, flags [none], proto ICMP (1), length 96)
    192.168.63.100 > 192.168.63.1: ICMP echo request, id 8728, seq 268, length 76
	0x0000:  9ed2 249a 884a 02fe 4ea4 de6a 8100 0064  ..$..J..N..j...d
	0x0010:  0800 4500 0060 0000 0000 fe01 bce6 c0a8  ..E..`..........
	0x0020:  3f64 c0a8 3f01 0800 9580 2218 010c 49f0  ?d..?....."...I.
	0x0030:  bddf ce03 0000 0001 0203 0405 0607 0809  ................
	0x0040:  0a0b 0c0d 0e0f 1011 1213 1415 1617 1819  ................
	0x0050:  1a1b 1c1d 1e1f 2021 2223 2425 2627 2829  .......!"#$%&'()
	0x0060:  2a2b 2c2d 2e2f 3031 3233 3435 3637 3839  *+,-./0123456789
	0x0070:  3a3b                                     :;
11:15:50.029692 IP (tos 0x0, ttl 64, id 54922, offset 0, flags [none], proto ICMP (1), length 96)
    192.168.63.1 > 192.168.63.100: ICMP echo reply, id 8728, seq 268, length 76
	0x0000:  02fe 4ea4 de6a 9ed2 249a 884a 8100 0064  ..N..j..$..J...d
	0x0010:  0800 4500 0060 d68a 0000 4001 a45c c0a8  ..E..`....@..\..
	0x0020:  3f01 c0a8 3f64 0000 9d80 2218 010c 49f0  ?...?d...."...I.
	0x0030:  bddf ce03 0000 0001 0203 0405 0607 0809  ................
	0x0040:  0a0b 0c0d 0e0f 1011 1213 1415 1617 1819  ................
	0x0050:  1a1b 1c1d 1e1f 2021 2223 2425 2627 2829  .......!"#$%&'()
	0x0060:  2a2b 2c2d 2e2f 3031 3233 3435 3637 3839  *+,-./0123456789
	0x0070:  3a3b                                     :;

2 packets captured
2 packets received by filter
0 packets dropped by kernel
```

8100 0064清晰可见，VLAN100配置生效。