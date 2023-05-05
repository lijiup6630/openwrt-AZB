### Traffic Analytics



#### 目的

用ndpi来进行流量分析。



#### 编译

首先下载nDPI的代码：

```
git clone https://gitee.com/codergeek/nDPI.git
```

在OpenWrt系统上编译，有关SDK的配置参考DPDK编译文档。

另外编译前需要提前准备HOST环境，如下所示：

```
# lib下
ln -s libpthread.so.0 libpthread.so
cp /usr/lib/gcc/x86_64-openwrt-linux-gnu/11.2.0/libmvec.so.1 /lib/
```

同时需要注意libtool工具，/usr/bin/libtoolize，需要复制一份为libtool。

同时编译nDPI需要libpcap的头文件，但是OpenWrt默认不会安装，需要从源码中复制：

```
cp pcap.h /usr/include/
cp -rf pcap /usr/include/
```

编译：

```
./autogen.sh
make
make install
```

这里可能会提示install-sh没有权限，直接chmod 777 install-sh即可。

编译完之后编译应用程序：

```
root@OpenWrt:/mnt/nDPI#cd example/
root@OpenWrt:/mnt/nDPI/example# make
gcc -fPIC -DPIC -I../src/include -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-address-of-packed-member  -O2   -pthread  -c reader_util.c -o reader_util.o
ar rsv libndpiReader.a reader_util.o
ar: creating libndpiReader.a
a - reader_util.o
gcc -fPIC -DPIC -I../src/include -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-address-of-packed-member  -O2   -pthread  -c ndpiReader.c -o ndpiReader.o
gcc -fPIC -DPIC -I../src/include -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-address-of-packed-member  -O2   -pthread  ndpiReader.o libndpiReader.a ../src/lib/libndpi.a -lpcap -lm   -pthread -o ndpiReader
root@OpenWrt:/mnt/nDPI/example# make install
```



#### 测试

PC上联OpenWrt的LAN，然后OpenWrt的WAN用于上网，然后执行：

```
ndpiReader -i eth0 -s 60
```

eth0是LAN口。对eth0的数据进行60秒抓包分析。

#### 现象

```
root@OpenWrt:/# ndpiReader -i eth0 -s 60

-----------------------------------------------------------
* NOTE: This is demo app to show *some* nDPI features.
* In this demo we have implemented only some basic features
* just to show you what you can do with the library. Feel 
* free to extend it and send us the patches for inclusion
------------------------------------------------------------

Using nDPI (3.4.0) [1 thread(s)]
Using libgcrypt version 1.8.7
Capturing live traffic from device eth0...
Capturing traffic up to 60 seconds
Running thread 0...
Error while reading pcap file: ''

nDPI Memory statistics:
	nDPI Memory (once):      223.89 KB    
	Flow Memory (per flow):  2.21 KB      
	Actual Memory:           46.80 MB     
	Peak Memory:             46.80 MB     
	Setup Time:              119 msec
	Packet Processing Time:  60669 msec

Traffic statistics:
	Ethernet bytes:        43261740      (includes ethernet CRC/IFC/trailer)
	Discarded bytes:       102          
	IP packets:            35138         of 35140 packets total
	IP bytes:              42418428      (avg pkt size 1207 bytes)
	Unique flows:          146          
	TCP Packets:           35014        
	UDP Packets:           112          
	VLAN Packets:          0            
	MPLS Packets:          0            
	PPPoE Packets:         0            
	Fragmented Packets:    0            
	Max Packet size:       1460         
	Packet Len < 64:       5441         
	Packet Len 64-128:     327          
	Packet Len 128-256:    273          
	Packet Len 256-1024:   1514         
	Packet Len 1024-1500:  27583        
	Packet Len > 1500:     0            
	nDPI throughput:       579.17 pps / 5.44 Mb/sec
	Analysis begin:        03/May/2022 02:26:50
	Analysis end:          03/May/2022 02:27:48
	Traffic throughput:    579.17 pps / 5.44 Mb/sec
	Traffic duration:      60.669 sec
	Guessed flow protos:   0            


Detected protocols:
	Unknown              packets: 24            bytes: 2734          flows: 4            
	DNS                  packets: 36            bytes: 5007          flows: 3            
	HTTP                 packets: 316           bytes: 82984         flows: 23           
	QQ                   packets: 361           bytes: 99815         flows: 20           
	IMAPS                packets: 3             bytes: 268           flows: 1            
	TLS                  packets: 34333         bytes: 42212186      flows: 108          
	ICMPV6               packets: 12            bytes: 1008          flows: 3            
	Google               packets: 24            bytes: 4211          flows: 1            
	HTTP_Proxy           packets: 11            bytes: 1863          flows: 2            
	Microsoft            packets: 18            bytes: 8352          flows: 1            


Protocol statistics:
	Safe                      42220806 bytes
	Acceptable                   90862 bytes
	Fun                          99815 bytes
	Unrated                       4211 bytes
	Unrated                       2734 bytes
root@OpenWrt:/# 
```

能做到对流量的简单分析，和统计。包括不同的协议，但是颗粒度有点粗。