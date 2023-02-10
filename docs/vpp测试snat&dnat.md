```
#拓扑
|-----------|         |------------|           |---------------|
| 50.1.1.2  |---------|    vpp     |-----------|  192.168.1.2  |
|-----------|         |------------|           |---------------|
   Host-A           lan1         wan0               Host-B
```

```
#配置VPP
root@vagrant:/opt# vppctl -s /run/vpp/cli.sock 
    _______    _        _   _____  ___ 
 __/ __/ _ \  (_)__    | | / / _ \/ _ \
 _/ _// // / / / _ \   | |/ / ___/ ___/
 /_/ /____(_)_/\___/   |___/_/  /_/    

vpp# show int
              Name               Idx    State  MTU (L3/IP4/IP6/MPLS)     Counter          Count     
lan1                              2     down         9000/0/0/0     
local0                            0     down          0/0/0/0       
wan0                              1     down         9000/0/0/0     
vpp# set interface state lan1 up
vpp# set interface state wan0 up
vpp# set int ip addr lan1 50.1.1.1/24
vpp# set int ip addr wan0 192.168.1.1/24

vpp# nat44 plugin enable
vpp# set interface nat44 in lan1 out wan0
vpp# nat44 add int address wan0

#配置Host-A
root@vagrant:~# ifconfig ens192 up
root@vagrant:~# ip addr add 50.1.1.2/24 dev ens192
ip route add 192.168.1.0/24 via 50.1.1.1

#配置Host-B
root@ubuntu:~# ifconfig ens192 up
root@ubuntu:~# ip addr add 192.168.1.2/24 dev ens192
ip route add 50.1.1.0/24 via 192.168.1.1
```

```
#测试SNAT
Host-A ping Host-B
root@vagrant:~# ping 192.168.1.2 -I ens192
PING 192.168.1.2 (192.168.1.2) from 50.1.1.2 ens192: 56(84) bytes of data.
64 bytes from 192.168.1.2: icmp_seq=1 ttl=63 time=0.332 ms
64 bytes from 192.168.1.2: icmp_seq=2 ttl=63 time=0.194 ms
64 bytes from 192.168.1.2: icmp_seq=3 ttl=63 time=0.178 ms

#在Host-B抓包可以看到ip已经修改为192.168.1.1
root@ubuntu:~# tcpdump -i ens192 icmp -vv
tcpdump: listening on ens192, link-type EN10MB (Ethernet), capture size 262144 bytes
01:51:11.704609 IP (tos 0x0, ttl 63, id 50786, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.1 > ubuntu: ICMP echo request, id 11570, seq 3, length 64
01:51:11.704641 IP (tos 0x0, ttl 64, id 23615, offset 0, flags [none], proto ICMP (1), length 84)
    ubuntu > 192.168.1.1: ICMP echo reply, id 11570, seq 3, length 64
01:51:12.728682 IP (tos 0x0, ttl 63, id 50842, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.1 > ubuntu: ICMP echo request, id 11570, seq 4, length 64
01:51:12.728710 IP (tos 0x0, ttl 64, id 23797, offset 0, flags [none], proto ICMP (1), length 84)
    ubuntu > 192.168.1.1: ICMP echo reply, id 11570, seq 4, length 64
```


```
#继续测试dnat

#配置VPP
vpp# nat44 add static mapping tcp local 50.1.1.2 external wan0
vpp# set int nat44 out wan0

#测试DNAT
#在Host-B ping wan0
root@ubuntu:~# ping 192.168.1.1
PING 192.168.1.1 (192.168.1.1) 56(84) bytes of data.
64 bytes from 192.168.1.1: icmp_seq=1 ttl=63 time=0.324 ms
64 bytes from 192.168.1.1: icmp_seq=2 ttl=63 time=0.166 ms
64 bytes from 192.168.1.1: icmp_seq=3 ttl=63 time=0.147 ms
64 bytes from 192.168.1.1: icmp_seq=4 ttl=63 time=0.167 ms

#在Host-A 可抓到包 
root@vagrant:~# tcpdump -i ens192 icmp -vv
tcpdump: listening on ens192, link-type EN10MB (Ethernet), capture size 262144 bytes
01:54:12.920564 IP (tos 0x0, ttl 63, id 35664, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.2 > vagrant: ICMP echo request, id 4, seq 18, length 64
01:54:12.920590 IP (tos 0x0, ttl 64, id 11282, offset 0, flags [none], proto ICMP (1), length 84)
    vagrant > 192.168.1.2: ICMP echo reply, id 4, seq 18, length 64
01:54:13.944513 IP (tos 0x0, ttl 63, id 35756, offset 0, flags [DF], proto ICMP (1), length 84)
    192.168.1.2 > vagrant: ICMP echo request, id 4, seq 19, length 64
01:54:13.944541 IP (tos 0x0, ttl 64, id 11464, offset 0, flags [none], proto ICMP (1), length 84)
    vagrant > 192.168.1.2: ICMP echo reply, id 4, seq 19, length 64
```