### Traffic analytics



traffic analytics使用OpenWrt的Traffic Rules功能，功能的实现匹配：

Source address,Source port,Destination address,Destination port,Protocol。



#### No ICMP test

在/etc/config/firewall中添加以下配置：

```
config rule
	option name 'no-icmp'
	list proto 'icmp'
	option src 'lan'
	list src_ip '192.168.110.198'
	option dest 'wan'
	list dest_ip '192.168.1.5'
	option target 'DROP'
```

禁用了LAN侧下挂的设备192.168.110.198的ping 192.168.1.5的功能。

测试：

```
[C:\~]$ ping 192.168.1.5

正在 Ping 192.168.1.5 具有 32 字节的数据:
请求超时。

192.168.1.5 的 Ping 统计信息:
    数据包: 已发送 = 1，已接收 = 0，丢失 = 1 (100% 丢失)，
```

设备是可以正常的和192.168.1.5通的。

```
root@OpenWrt:/# ping 192.168.1.5
PING 192.168.1.5 (192.168.1.5): 56 data bytes
64 bytes from 192.168.1.5: seq=0 ttl=64 time=0.684 ms
64 bytes from 192.168.1.5: seq=1 ttl=64 time=0.589 ms
64 bytes from 192.168.1.5: seq=2 ttl=64 time=0.568 ms
64 bytes from 192.168.1.5: seq=3 ttl=64 time=0.572 ms
64 bytes from 192.168.1.5: seq=4 ttl=64 time=0.574 ms
```

LAN侧下挂设备192.168.110.200可以正常的和192.168.1.5 ping通的。

```
[C:\~]$ ping 192.168.1.5

正在 Ping 192.168.1.5 具有 32 字节的数据:
来自 192.168.1.5 的回复: 字节=32 时间=1ms TTL=63
来自 192.168.1.5 的回复: 字节=32 时间=2ms TTL=63
来自 192.168.1.5 的回复: 字节=32 时间=2ms TTL=63
来自 192.168.1.5 的回复: 字节=32 时间=1ms TTL=63

192.168.1.5 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 4，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 1ms，最长 = 2ms，平均 = 1ms
```



#### Port reject

设置LAN->WAN，端口为8888->9999可做如下配置

```
config rule
	option name 'no-8888-9999'
	option src 'lan'
	list src_ip '192.168.110.198'
	option src_port '8888'
	option dest 'wan'
	list dest_ip '192.168.1.5'
	option dest_port '9999'
	option target 'REJECT'
```

此配置表示从sport 8888到dprot 9999的数据报文将被REJECT。其余各种配置类似。