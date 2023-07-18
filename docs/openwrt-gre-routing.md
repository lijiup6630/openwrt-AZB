### OpenWrt GRE Routing(未写完)



#### 1. 说明
OpenWrt应至少使能以下选项：
```
CONFIG_PACKAGE_kmod-gre=y
CONFIG_PACKAGE_kmod-gre6=y
CONFIG_PACKAGE_gre=y
CONFIG_PACKAGE_grep=y
```

#### 2. 网络拓扑及说明

![](https://openwrt.org/_media/docs/guide-user/network/gre.jpeg?w=800&tok=2b4dbd)



#### 3. 配置说明

（1）R1的配置

```
# /etc/config/network
 
config interface 'lan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '172.16.1.1'
	option netmask '255.255.255.0'
	option ip6assign '60'
 
config interface 'wan'
	option device 'eth0'
	option proto 'static'
	option ipaddr '10.1.1.1'
	option netmask '255.255.255.252'
	option gateway '10.1.1.2'
 
config interface 'mygre'
	option ipaddr '10.1.1.1'
	option peeraddr '10.2.2.1'
	option proto 'gre'
 
config interface 'mygre_static'
	option proto 'static'
	option device '@mygre'
	option ipaddr '172.16.12.1'
	option netmask '255.255.255.252'
 
config route 'tunnel'
	option interface 'mygre_static'
	option target '172.16.2.0'
	option netmask '255.255.255.0'
	option gateway '172.16.12.2'
```

(2) R2的配置

```
# /etc/config/network
 
config interface 'lan'
	option device 'eth0'
	option proto 'static'
	option ipaddr '172.16.2.1'
	option netmask '255.255.255.0'
 
config interface 'wan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '10.2.2.1'
	option netmask '255.255.255.252'
	option gateway '10.2.2.2'
 
config interface 'mygre'
	option ipaddr '10.2.2.1'
	option peeraddr '10.1.1.1'
	option proto 'gre'
 
config interface 'mygre_static'
	option proto 'static'
	option device '@mygre'
	option ipaddr '172.16.12.2'
	option netmask '255.255.255.252'
 
config route 'tunnel'
	option interface 'mygre_static'
	option target '172.16.1.0'
	option netmask '255.255.255.0'
	option gateway '172.16.12.1'
```

(3) WAN的配置

```
# /etc/config/network
 
config interface 'lan1'
	option device 'eth0'
	option proto 'static'
	option ipaddr '10.1.1.2'
	option netmask '255.255.255.252'
 
config interface 'lan2'
	option device 'eth1'
	option proto 'static'
	option ipaddr '10.2.2.2'
	option netmask '255.255.255.252'
 
config route 'net1'
	option interface 'lan1'	
	option target '172.16.1.0'
	option netmask '255.255.255.0'
	option gateway '10.1.1.1'
 
config route 'net2'
	option interface 'lan2'
	option target '172.16.2.0'
	option netmask '255.255.255.0'
	option gateway '10.2.2.1'
```



(4) PC1的配置

```
# PC1
address 172.16.1.3/24
gateway 172.16.1.1
```

(5)PC2的配置

```
# PC2
address 172.16.2.3/24
gateway 172.16.2.1
```

