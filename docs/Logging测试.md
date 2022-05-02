### Logging功能验证



#### 1. 目标

查看系统日志，包括本地日志，远端日志。



#### 2. 配置

OpenWrt设备IP为192.168.31.45，服务器IP为192.168.31.132.

OpenWrt产生的log将缓存至本地，同时上报到服务器。

OpenWrt的配置如下：

```
# cat /etc/config/system 

config system
	option hostname 'OpenWrt'
	option ttylogin '0'
	option log_size '64'
	option urandom_seed '0'
	option zonename 'UTC'
	option log_ip '192.168.31.132'
	option log_port '50789'
	option log_proto 'udp'
	option log_file '/tmp/system.log'
	option conloglevel '8'
	option cronloglevel '5'
```

这里设置的log ip为服务器IP。然后log_file为本机log缓存文件。

服务器监听udp协议的50789端口即可。



#### 3. 测试

执行以下命令，观察本地文件和服务器：

```
root@OpenWrt:~# ifconfig eth1 down
root@OpenWrt:~# ifconfig eth1 up
root@OpenWrt:~# ifconfig eth1 down
root@OpenWrt:~# ifconfig eth1 up
```

此时本地缓存文件：

```
root@OpenWrt:~# cat /tmp/system.log 
Mon May  2 12:14:02 2022 daemon.info logread[8913]: Logread connected to 192.168.31.132:50789 via udp
Mon May  2 12:15:20 2022 daemon.info ipsec: 07[KNL] interface eth1 deactivated
Mon May  2 12:15:20 2022 daemon.info ipsec: 14[KNL] interface eth1 deactivated
Mon May  2 12:15:20 2022 daemon.notice netifd: Network device 'eth1' link is down
Mon May  2 12:15:20 2022 daemon.notice netifd: bridge 'br-lan' link is down
Mon May  2 12:15:20 2022 daemon.notice netifd: Interface 'lan' has link connectivity loss
Mon May  2 12:15:20 2022 kern.info kernel: [  272.870532] br-lan: port 1(eth1) entered disabled state
Mon May  2 12:15:20 2022 daemon.info ipsec: 02[NET] using forecast interface eth0
Mon May  2 12:15:20 2022 daemon.info ipsec: 02[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:15:20 2022 daemon.info ipsec: 01[NET] using forecast interface eth0
Mon May  2 12:15:20 2022 daemon.info ipsec: 01[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:15:30 2022 daemon.info ipsec: 03[KNL] interface eth1 activated
Mon May  2 12:15:30 2022 daemon.info ipsec: 10[KNL] interface eth1 activated
Mon May  2 12:15:30 2022 kern.info kernel: [  283.172366] 8021q: adding VLAN 0 to HW filter on device eth1
Mon May  2 12:15:30 2022 kern.info kernel: [  283.183860] e1000: eth1 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: None
Mon May  2 12:15:31 2022 daemon.notice netifd: Network device 'eth1' link is up
Mon May  2 12:15:31 2022 daemon.notice netifd: bridge 'br-lan' link is up
Mon May  2 12:15:31 2022 daemon.notice netifd: Interface 'lan' has link connectivity
Mon May  2 12:15:31 2022 kern.info kernel: [  283.188104] br-lan: port 1(eth1) entered blocking state
Mon May  2 12:15:31 2022 kern.info kernel: [  283.190281] br-lan: port 1(eth1) entered forwarding state
Mon May  2 12:15:31 2022 daemon.info ipsec: 16[NET] using forecast interface eth0
Mon May  2 12:15:31 2022 daemon.info ipsec: 16[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:15:31 2022 daemon.info ipsec: 07[NET] using forecast interface eth0
Mon May  2 12:15:31 2022 daemon.info ipsec: 07[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:18:22 2022 daemon.info ipsec: 01[KNL] interface eth1 deactivated
Mon May  2 12:18:22 2022 daemon.info ipsec: 15[KNL] interface eth1 deactivated
Mon May  2 12:18:22 2022 daemon.notice netifd: Network device 'eth1' link is down
Mon May  2 12:18:22 2022 daemon.notice netifd: bridge 'br-lan' link is down
Mon May  2 12:18:22 2022 daemon.notice netifd: Interface 'lan' has link connectivity loss
Mon May  2 12:18:22 2022 kern.info kernel: [  454.317141] br-lan: port 1(eth1) entered disabled state
Mon May  2 12:18:22 2022 daemon.info ipsec: 04[NET] using forecast interface eth0
Mon May  2 12:18:22 2022 daemon.info ipsec: 13[NET] using forecast interface eth0
Mon May  2 12:18:22 2022 daemon.info ipsec: 13[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:18:22 2022 daemon.info ipsec: 04[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:18:27 2022 daemon.info ipsec: 05[KNL] interface eth1 activated
Mon May  2 12:18:27 2022 daemon.info ipsec: 12[KNL] interface eth1 activated
Mon May  2 12:18:27 2022 kern.info kernel: [  459.811222] 8021q: adding VLAN 0 to HW filter on device eth1
Mon May  2 12:18:27 2022 kern.info kernel: [  459.827135] e1000: eth1 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: None
Mon May  2 12:18:27 2022 kern.info kernel: [  459.831255] br-lan: port 1(eth1) entered blocking state
Mon May  2 12:18:27 2022 kern.info kernel: [  459.834219] br-lan: port 1(eth1) entered forwarding state
Mon May  2 12:18:27 2022 daemon.notice netifd: Network device 'eth1' link is up
Mon May  2 12:18:27 2022 daemon.notice netifd: bridge 'br-lan' link is up
Mon May  2 12:18:27 2022 daemon.notice netifd: Interface 'lan' has link connectivity
Mon May  2 12:18:27 2022 daemon.info ipsec: 02[NET] using forecast interface eth0
Mon May  2 12:18:27 2022 daemon.info ipsec: 02[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
Mon May  2 12:18:27 2022 daemon.info ipsec: 16[NET] using forecast interface eth0
Mon May  2 12:18:27 2022 daemon.info ipsec: 16[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
```

服务器收到信息：

```
<30>May  2 12:14:02 OpenWrt logread[8913]: Logread connected to 192.168.31.132:50789 via udp
<30>May  2 12:15:20 OpenWrt ipsec: 07[KNL] interface eth1 deactivated<6>May  2 12:15:20 OpenWrt kernel: [  272.870532] br-lan: port 1(eth1) entered disabled state<30>May  2 12:15:20 OpenWrt ipsec: 02[NET] using forecast interface eth0
<30>May  2 12:15:20 OpenWrt ipsec: 01[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
<30>May  2 12:15:30 OpenWrt ipsec: 03[KNL] interface eth1 activated
<30>May  2 12:15:30 OpenWrt ipsec: 10[KNL] interface eth1 activated
<6>May  2 12:15:30 OpenWrt kernel: [  283.183860] e1000: eth1 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: None<29>May  2 12:15:31 OpenWrt netifd: Network device 'eth1' link is up<6>May  2 12:15:31 OpenWrt kernel: [  283.190281] br-lan: port 1(eth1) entered forwarding state<30>May  2 12:15:31 OpenWrt ipsec: 16[NET] using forecast interface eth0<30>May  2 12:15:31 OpenWrt ipsec: 07[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250<30>May  2 12:18:22 OpenWrt ipsec: 01[KNL] interface eth1 deactivated<6>May  2 12:18:22 OpenWrt kernel: [  454.317141] br-lan: port 1(eth1) entered disabled state<30>May  2 12:18:22 OpenWrt ipsec: 04[NET] using forecast interface eth0<30>May  2 12:18:22 OpenWrt ipsec: 04[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250<30>May  2 12:18:27 OpenWrt ipsec: 05[KNL] interface eth1 activated<6>May  2 12:18:27 OpenWrt kernel: [  459.811222] 8021q: adding VLAN 0 to HW filter on device eth1<29>May  2 12:18:27 OpenWrt netifd: Interface 'lan' has link connectivity<30>May  2 12:18:27 OpenWrt ipsec: 02[NET] using forecast interface eth0<30>May  2 12:18:27 OpenWrt ipsec: 16[CFG] joining forecast multicast groups: 224.0.0.1,224.0.0.22,224.0.0.251,224.0.0.252,239.255.255.250
```

