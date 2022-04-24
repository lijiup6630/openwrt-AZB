#### FIREWALL测试



#### 1. firewall的测试说明

准备待测设备A和一台服务器，WAN侧IP为192.168.100.160，服务器IP为192.168.100.78，设备和服务器之间通过WAN口相连接。

##### （1）port

使用ACCEPT, REJECT, DROP对端口22进行规则设置，直接使用SSH来验证即可。

##### （2）IP

使用ACCEPT, REJECT, DROP对指定IP地址进行规则设置，使用SSH来验证。



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