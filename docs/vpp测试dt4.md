```
#拓扑
|-----------|         |------------|           |------------|		  |------------|
|    c1     |---------|    R1      |-----------|      R2    |---------|	   c2	   |
|-----------|         |------------|           |------------|		  |------------|
   10.10.0.2       10.10.0.1      cafe::1     cafe::2   10.11.0.1   10.11.0.2


# R1
vpp# set int state lan1 up
vpp# set int state wan0 up
vpp# ip table add 10
vpp# set int ip table lan1 10
vpp# set int ip addr wan0 cafe::1/64     
vpp# set int ip addr lan1 10.10.0.1/24     
vpp# ip route add f2::/64 via cafe::2
vpp# sr localsid address f1::10 behavior end
vpp# sr localsid address f1::11 behavior end.dt4 10
vpp# sr policy add bsid 1::0 next f2::10 next f2::11 fib-table 0
vpp# sr steer l3 10.11.0.0/24 via bsid 1::0 fib-table 10   

# R2
vpp# create interface vmxnet3 0000:0b:00.0 bind
vmxnet3-0/b/0/0
vpp# create interface vmxnet3 0000:13:00.0 bind
vmxnet3-0/13/0/0
vpp# set interface state vmxnet3-0/b/0/0 up
vpp# set interface state vmxnet3-0/13/0/0 up
vpp# set int state vmxnet3-0/b/0/0 up
vpp# set int state vmxnet3-0/13/0/0 up
vpp# ip table add 10
vpp# set int ip table vmxnet3-0/13/0/0 10
vpp# set int ip addr vmxnet3-0/b/0/0  cafe::2/64               
vpp# set int ip addr vmxnet3-0/13/0/0 10.11.0.1/24
vpp# ip route add f1::/64 via cafe::1 
vpp# sr localsid address f2::10 behavior end
vpp# sr localsid address f2::11 behavior end.dt4 10
vpp# set sr encaps source addr f2::0                                   
vpp# sr policy add bsid 1::0 next f1::10 next f1::11 fib-table 0
vpp# sr steer l3 10.10.0.0/24 via bsid 1::0 fib-table 10

#c1
ip addr add 10.10.0.2/24 dev ens192
ip route add 10.11.0.0/24 via 10.10.0.1

#c2
ip addr add 10.11.0.2/24 dev ens192
ip route add 10.10.0.0/24 via 10.11.0.1

```



测试下：

```
#c2 -> c1
root@ubuntu:~# ping 10.10.0.2
PING 10.10.0.2 (10.10.0.2) 56(84) bytes of data.
64 bytes from 10.10.0.2: icmp_seq=1 ttl=62 time=0.838 ms
64 bytes from 10.10.0.2: icmp_seq=2 ttl=62 time=0.269 ms
64 bytes from 10.10.0.2: icmp_seq=3 ttl=62 time=0.241 ms
64 bytes from 10.10.0.2: icmp_seq=4 ttl=62 time=0.280 ms

抓包验证：
在ping过程中抓包
Internet Protocol Version 6, Src: f2::, Dst: f1::10
    0110 .... = Version: 6
    .... 0000 0000 .... .... .... .... .... = Traffic Class: 0x00 (DSCP: CS0, ECN: Not-ECT)
    .... 0000 1101 0110 0100 0110 = Flow Label: 0x0d646
    Payload Length: 124
    Next Header: Routing Header for IPv6 (43)
    Hop Limit: 63
    Source Address: f2::
    Destination Address: f1::10
    Routing Header for IPv6 (Segment Routing)
        Next Header: IPIP (4)
        Length: 4
        [Length: 40 bytes]
        Type: Segment Routing (4)
        Segments Left: 1
        Last Entry: 1
        Flags: 0x00
        Tag: 0000
        Address[0]: f1::11
        Address[1]: f1::10

可见segment routing段
```
