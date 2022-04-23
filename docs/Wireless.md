### Wireless



#### 1.说明

使用OpenWrt-22.03版本的OpenWrt，我们已经做好相应的固件适配工作。使用的固件版本为64。



#### 2.测试station模式

用iw wlan0 scan或者luci的wifi功能均能测试。

##### 2.1 扫描附近wifi

![image-20220401002923812](pic\image-20220401002923812-16487441675761.png)

```
root@OpenWrt:/# iw dev wlan0 scan
BSS 3c:cd:57:df:7d:eb(on wlan0)
	last seen: 153.884s [boottime]
	TSF: 1652365990737 usec (19d, 02:59:25)
	freq: 2422
	beacon interval: 100 TUs
	capability: ESS (0x1431)
	signal: -94.00 dBm
	last seen: 3470 ms ago
	Information elements from Probe Response frame:
	SSID: tinghexi
	HT capabilities:
		Capabilities: 0x1ad
			RX LDPC
			HT20
			SM Power Save disabled
			RX HT20 SGI
			TX STBC
			RX STBC 1-stream
......
......
```



##### 2.2 连接到网络

连接2.4G网络，如下所示：

![image-20220401012210601](pic\image-20220401012210601-16487473324682.png)

然后成功的连接上了：

![image-20220401012233568](pic\image-20220401012233568-16487473558783.png)

在设备上观察：

```
wlan0     Link encap:Ethernet  HWaddr 00:91:9E:3B:14:1F  
          inet addr:192.168.31.76  Bcast:192.168.31.255  Mask:255.255.255.0
          inet6 addr: fe80::291:9eff:fe3b:141f/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:7 errors:0 dropped:0 overruns:0 frame:0
          TX packets:12 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:1158 (1.1 KiB)  TX bytes:1960 (1.9 KiB)
```



#### 3. 测试AP模式

##### 3.1 开始Master模式

