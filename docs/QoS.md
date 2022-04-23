### QoS



测试OpenWrt的eth0，和对端对打iperf。使用的是SQM QoS工具。

OpenWrt作为client方，两方分别执行命令：

```
iperf3 -c 192.168.2.194 -u -b 1000M  -- client
iperf3 -s 							 --server
```



#### 1. 正常情况

在没有QoS限速的情况下，server数据为：

```
Server listening on 5201
-----------------------------------------------------------
Accepted connection from 192.168.2.237, port 43144
[  5] local 192.168.2.194 port 5201 connected to 192.168.2.237 port 42575
[ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
[  5]   0.00-1.00   sec  11.3 MBytes  95.1 Mbits/sec  0.134 ms  19/8228 (0.23%)  
[  5]   1.00-2.00   sec  11.4 MBytes  95.7 Mbits/sec  0.123 ms  0/8261 (0%)  
[  5]   2.00-3.00   sec  8.14 MBytes  68.3 Mbits/sec  1.156 ms  1857/7751 (24%)  
[  5]   3.00-4.00   sec  11.3 MBytes  95.2 Mbits/sec  0.160 ms  542/8759 (6.2%)  
[  5]   4.00-5.00   sec  11.4 MBytes  95.6 Mbits/sec  0.128 ms  0/8256 (0%)  
[  5]   5.00-6.00   sec  10.3 MBytes  86.7 Mbits/sec  0.107 ms  772/8256 (9.4%)  
[  5]   6.00-7.00   sec  11.2 MBytes  94.2 Mbits/sec  0.127 ms  126/8256 (1.5%)  
[  5]   7.00-8.00   sec  10.7 MBytes  89.8 Mbits/sec  0.137 ms  491/8246 (6%)  
[  5]   8.00-9.00   sec  8.87 MBytes  74.4 Mbits/sec  0.146 ms  1848/8268 (22%)  
[  5]   9.00-10.00  sec  3.17 MBytes  26.5 Mbits/sec  0.710 ms  5561/7857 (71%)  
- - - - - - - - - - - - - - - - - - - - - - - - -
[ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
[  5]   0.00-10.00  sec  97.9 MBytes  82.1 Mbits/sec  0.710 ms  11216/82138 (14%)  receiver
```

#### 2. QoS限速

配置如下：

```
root@OpenWrt:/# cat /etc/config/sqm 

config queue 'eth1'
	option qdisc 'cake'
	option script 'piece_of_cake.qos'
	option linklayer 'none'
	option interface 'eth0'
	option download '100'
	option upload '100'
	option debug_logging '0'
	option verbosity '5'
	option enabled '1'
```

也就是说我们把上传和下载都限制在100kbit/s上。

iperf性能如下：

```
Server listening on 5201
-----------------------------------------------------------
Accepted connection from 192.168.2.237, port 43146
[  5] local 192.168.2.194 port 5201 connected to 192.168.2.237 port 47808
[ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
[  5]   0.00-1.00   sec  11.3 KBytes  92.5 Kbits/sec  2475519.685 ms  2/10 (20%)  
[  5]   1.00-2.00   sec  11.3 KBytes  92.7 Kbits/sec  1477239.030 ms  6/14 (43%)  
[  5]   2.00-3.00   sec  12.7 KBytes   104 Kbits/sec  826457.555 ms  12/21 (57%)  
[  5]   3.00-4.00   sec  9.90 KBytes  81.1 Kbits/sec  526085.843 ms  13/20 (65%)  
[  5]   4.00-5.00   sec  12.7 KBytes   104 Kbits/sec  294328.918 ms  20/29 (69%)  
[  5]   5.00-6.00   sec  9.90 KBytes  81.0 Kbits/sec  187354.080 ms  20/27 (74%)  
[  5]   6.00-7.00   sec  11.3 KBytes  92.7 Kbits/sec  111807.590 ms  26/34 (76%)  
[  5]   7.00-8.00   sec  11.3 KBytes  92.8 Kbits/sec  66726.499 ms  29/37 (78%)  
[  5]   8.00-9.00   sec  11.3 KBytes  92.6 Kbits/sec  39835.276 ms  33/41 (80%)  
[  5]   9.00-10.00  sec  11.3 KBytes  92.8 Kbits/sec  23779.409 ms  38/46 (83%)  
- - - - - - - - - - - - - - - - - - - - - - - - -
[ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
[  5]   0.00-10.05  sec   113 KBytes  92.2 Kbits/sec  23779.409 ms  199/279 (71%)  receiver
```

server接收到的数据基本上为100左右。软件实现有点小误差。