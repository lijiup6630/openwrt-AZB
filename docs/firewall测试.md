#### FIREWALL测试



#### 1. firewall的测试说明

端口限制和IP限制：准备待测设备A和一台服务器，WAN侧IP为192.168.100.160，服务器IP为192.168.100.78，设备和服务器之间通过WAN口相连接。

其余：OpenWrt设备上联服务器，下联PC，用PC来访问设备和服务器做验证。LAN地址为192.168.110.1，上联路由器。

##### （1）端口限制

使用ACCEPT, REJECT, DROP对端口22进行规则设置，直接使用SSH来验证即可。

##### （2）IP限制

使用ACCEPT, REJECT, DROP对指定IP地址进行规则设置，使用SSH来验证。

##### （3）端口转发

端口转发，nat。

##### （4）转发规则限制

只允许开放端口和协议。

##### （5）黑白名单

通过设置允许IP和MAC访问。

##### （6）tcp/udp协议禁止



#### 2. port的ACCEPT/REJECT/DROP

防火墙配置如下：

```
# ACCEPT
# cat /etc/config/firewall
config rule
	option 	target		'ACCEPT'
	option	src			'wan'
	option	proto		'tcp'
	option	dest_port	'22'
	option	name		'ACCEPT-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录是可以的。

```
# REJECT
# cat /etc/config/firewall
config rule
	option 	target		'REJECT'
	option	src			'wan'
	option	proto		'tcp'
	option	dest_port	'22'
	option	name		'REJECT-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录，提示Connection refused.

```
# DROP
# cat /etc/config/firewall
config rule
	option 	target		'DROP'
	option	src			'wan'
	option	proto		'tcp'
	option	dest_port	'22'
	option	name		'DROP-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录，会提示timeout，因为包被drop掉了。



#### 3. IP的ACCEPT/REJECT/DROP

防火墙配置如下：

```
# ACCEPT
# cat /etc/config/firewall
config rule
	option 	target		'ACCEPT'
	option	src			'wan'
	option	family		'ipv4'
	option	proto		'tcp'
	option	src_ip		'192.168.100.78/24'
	option	dest_port	'22'
	option	name		'ACCEPT-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录是可以的。

```
# REJECT
# cat /etc/config/firewall
config rule
	option 	target		'REJECT'
	option	src			'wan'
	option	family		'ipv4'
	option	proto		'tcp'
	option	src_ip		'192.168.100.78/24'
	option	dest_port	'22'
	option	name		'REJECT-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录，提示Connection refused.

```
# DROP
# cat /etc/config/firewall
config rule
	option 	target		'DROP'
	option	src			'wan'
	option	family		'ipv4'
	option	proto		'tcp'
	option	src_ip		'192.168.100.78/24'
	option	dest_port	'22'
	option	name		'DROP-SSH-WAN-DEVICE'
	option	enabled		'1'
```

此时用PC去SSH登录，会提示timeout，因为包被drop掉了。



#### 4. 端口转发

NAT实际上不需要做过多的验证。通常OpenWrt默认开启NAT(SNAT和DNAT)。下联LAN侧设备能通过WAN口访问外部资源及可表示具备NAT功能。如果单独验证功能，可参考以下的配置：

DNAT:

```
config redirect
	option dest 'wan'
	option target 'DNAT'
	option name 'rule1'
	option src 'lan'
	option src_dport '8080'
	option dest_port '80'
	option dest_ip '192.168.63.1'
```

做如上配置，访问LAN侧IP，端口号为8080，会做dnat到dest_ip 192.168.63.1的80端口。设备上联路由器，此时如果访问192.168.110.1:8080，应能访问到上联路由器的管理页面。访问成功。

SNAT:

```
config nat
	option src 'wan'
	option src_ip '192.168.110.198'
	option snat_ip '192.168.63.1'
	option dest_port '50001'
	option target 'SNAT'
```

做如上配置。从192.168.110.198 IP出去的访问，会静态的将source IP写为192.168.63.1。192.168.110.198为PC地址。



#### 5. tcp/udp禁用

设置如下防火墙规则：

```
config rule
	option name 'notcp'
	list proto 'tcp'
	option src 'lan'
	list src_ip '192.168.110.198'
	option dest 'wan'
	list dest_ip '192.168.1.5'
	option target 'DROP'
```

从LAN侧192.168.110.198->192.168.1.5的tcp数据包会匹配DROP规则。

OpenWrt下挂另一台设备，IP自动获取为192.168.110.179。

此时198的表现为：

```
Connecting to 192.168.1.5:22...
Could not connect to '192.168.1.5' (port 22): Connection failed.

Type `help' to learn how to use Xshell prompt.
[C:\~]$ ping 192.168.1.5

正在 Ping 192.168.1.5 具有 32 字节的数据:
来自 192.168.1.5 的回复: 字节=32 时间=1ms TTL=63
来自 192.168.1.5 的回复: 字节=32 时间=1ms TTL=63

192.168.1.5 的 Ping 统计信息:
    数据包: 已发送 = 2，已接收 = 2，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 1ms，最长 = 1ms，平均 = 1ms
```

179的表现为：

```
root@localhost:~# ssh liji@192.168.1.5
liji@192.168.1.5's password: 
Welcome to Ubuntu 20.04.4 LTS (GNU/Linux 5.4.0-109-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

0 updates can be applied immediately.

Last login: Sun May  1 16:41:27 2022 from 192.168.1.19
liji@liji-pc:~$ 
```

因为SSH使用TCP，实际上198的tcp的访问被DROP，但是179是好好的。

UDP同理。



#### 6.黑白名单

黑名单：

把192.168.110.179加入黑名单，如下所示：

```
config rule
	option name 'disable179'
	option src 'lan'
	option dest 'wan'
	list dest_ip '192.168.1.5'
	option target 'DROP'
	list proto 'all'
	list src_ip '192.168.110.179'
```

未指定端口表示都被禁止了。也就是说192.168.110.179->192.168.1.5这条路被仅用了。

```
root@localhost:~# ping 192.168.1.5
PING 192.168.1.5 (192.168.1.5) 56(84) bytes of data.
^C
--- 192.168.1.5 ping statistics ---
4 packets transmitted, 0 received, 100% packet loss, time 3069ms

root@localhost:~# ssh liji@192.168.1.5
全部连不上。
```

白名单：

把192.168.110.198加入黑名单，如下所示：

```
config rule
	option src 'lan'
	option dest 'wan'
	list dest_ip '192.168.1.5'
	option name 'yes198'
	list proto 'all'
	list src_ip '192.168.110.198'
	option target 'ACCEPT'
```

参考此配置，192.168.110.198->192.168.1.5为畅通无阻状态。