### uPNP



开启 UPnP （Universal Plug and Play，通用即插即用）功能后，局域网中的计算机可以请求路由器自动进行端口转换。这样，互联网上的计算机就能在需要时访问局域网计算机上的资源（如 MSN Messenger 或迅雷、BT、PPTV 等支持 UPnP 协议的应用程序），在观看在线视频或使用多点下载等方面的软件时，享受更加稳定的网络。

OpenWrt默认不使能uPNP功能，需要在Luci或者是uci config中添加。

开启uPNP的配置如下(推荐在luci中设置，比较直观)：

```
root@OpenWrt:/# cat /etc/config/upnpd 

config upnpd 'config'
	option download '1024'
	option upload '512'
	option internal_iface 'lan'
	option port '5000'
	option upnp_lease_file '/var/run/miniupnpd.leases'
	option igdv1 '1'
	option enabled '1'
	option uuid 'f26778fe-9cc3-4b39-a984-6995e86a856d'

config perm_rule
	option action 'allow'
	option ext_ports '1024-65535'
	option int_addr '0.0.0.0/0'
	option int_ports '1024-65535'
	option comment 'Allow high ports'

config perm_rule
	option action 'deny'
	option ext_ports '0-65535'
	option int_addr '0.0.0.0/0'
	option int_ports '0-65535'
	option comment 'Default deny'

```

在添加了uPNP功能后，能看到uPNP端口映射是自动添加的，不需要手工添加。

UPnP是自动的NAT，是设备和路由器之间安装UPnP协议，自动协商端口。即使内网设备重启，IP地址改变，二者之间都会重新协商获得新的UPnP端口号，即自动的NAT端口映射。



打开迅雷和其它类似在线视频之类的软件，过会可在/tmp/upnp.leases下面看到动态的映射（需要等大概两三分钟）。

```
cat /tmp/upnp.leases 
TCP:12592:192.168.1.178:16000:0:xxxxx
UDP:9573:192.168.1.178:5041:0:xxxxx
TCP:27523:192.168.1.178:54321:0:xxxxx
UDP:27523:192.168.1.178:12345:0:xxxxx
```

此显示信息会通过http协议反馈给web界面，可在luci的uPNP的Active UPNP Redirects中看到。

nPNP功能也可以通过nPNP探测器软件测试。