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
#在先测试下未限速前的速度

#Host-B
root@ubuntu:~# iperf3 -s
-----------------------------------------------------------
Server listening on 5201
-----------------------------------------------------------

#Host-A
root@vagrant:~# iperf3 -c 192.168.1.2
Connecting to host 192.168.1.2, port 5201
[  5] local 50.1.1.2 port 55610 connected to 192.168.1.2 port 5201
[ ID] Interval           Transfer     Bitrate         Retr  Cwnd
[  5]   0.00-1.00   sec   656 MBytes  5.50 Gbits/sec   55   1.32 MBytes       
[  5]   1.00-2.00   sec   845 MBytes  7.09 Gbits/sec    6   1.35 MBytes       
[  5]   2.00-3.00   sec   814 MBytes  6.83 Gbits/sec    7   1.34 MBytes       
[  5]   3.00-4.00   sec   856 MBytes  7.18 Gbits/sec   18   1.32 MBytes       
[  5]   4.00-5.00   sec   840 MBytes  7.05 Gbits/sec    1   1.27 MBytes       
[  5]   5.00-6.00   sec   858 MBytes  7.19 Gbits/sec   14   1.27 MBytes       
[  5]   6.00-7.00   sec   871 MBytes  7.31 Gbits/sec    4   1.26 MBytes       
[  5]   7.00-8.00   sec   851 MBytes  7.14 Gbits/sec   27   1.25 MBytes       
[  5]   8.00-9.00   sec   879 MBytes  7.37 Gbits/sec   10   1.25 MBytes       
[  5]   9.00-10.00  sec   884 MBytes  7.41 Gbits/sec   64   1.24 MBytes       
- - - - - - - - - - - - - - - - - - - - - - - - -
[ ID] Interval           Transfer     Bitrate         Retr
[  5]   0.00-10.00  sec  8.16 GBytes  7.01 Gbits/sec  206             sender
[  5]   0.00-10.00  sec  8.16 GBytes  7.00 Gbits/sec                  receiver

iperf Done.

#配置VPP对源ip为50.1.1.2的ip进行限速
vpp# configure policer name policy1 cir 800 cb 90000 rate kbps round closest type 1r2c conform-action transmit exceed-action drop
vpp# classify table mask l3 ip4 src
vpp# classify session policer-hit-next policy1 exceed-color table-index 0 match l3 ip4 src 50.1.1.2   
vpp# set policer classify interface lan1 ip4-table 0 

#继续测速
root@vagrant:~# iperf3 -c 192.168.1.2
Connecting to host 192.168.1.2, port 5201
[  5] local 50.1.1.2 port 42552 connected to 192.168.1.2 port 5201
[ ID] Interval           Transfer     Bitrate         Retr  Cwnd
[  5]   0.00-1.00   sec   643 KBytes  5.27 Mbits/sec   93   5.66 KBytes       
[  5]   1.00-2.00   sec  0.00 Bytes  0.00 bits/sec   25   1.41 KBytes       
[  5]   2.00-3.00   sec   191 KBytes  1.56 Mbits/sec   12   1.41 KBytes       
[  5]   3.00-4.00   sec  0.00 Bytes  0.00 bits/sec   15   1.41 KBytes       
[  5]   4.00-5.00   sec   191 KBytes  1.56 Mbits/sec   13   1.41 KBytes       
[  5]   5.00-6.00   sec  0.00 Bytes  0.00 bits/sec   15   1.41 KBytes       
[  5]   6.00-7.00   sec   191 KBytes  1.56 Mbits/sec   12   1.41 KBytes       
[  5]   7.00-8.00   sec  0.00 Bytes  0.00 bits/sec   14   2.83 KBytes       
[  5]   8.00-9.00   sec   191 KBytes  1.56 Mbits/sec   14   1.41 KBytes       
[  5]   9.00-10.00  sec  0.00 Bytes  0.00 bits/sec   12   1.41 KBytes       
- - - - - - - - - - - - - - - - - - - - - - - - -
[ ID] Interval           Transfer     Bitrate         Retr
[  5]   0.00-10.00  sec  1.37 MBytes  1.15 Mbits/sec  225             sender
[  5]   0.00-10.00  sec  1007 KBytes   825 Kbits/sec                  receiver

iperf Done.

发现限速成功
```
