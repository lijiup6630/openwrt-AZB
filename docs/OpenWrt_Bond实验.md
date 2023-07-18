
OpenWrt需要预先使能：
```
CONFIG_PACKAGE_kmod-bonding=y
```

#### 1. 实现目的

将AZB板子上的两个口做BOND，模式配置为balance-rr。两个口分别上联交换机，并且和交换机ping通信。

来验证最基础的bond的能力。其中bond配置完后会出来bond网口，绑定下面两个真实的物理网口。

#### 2. 配置

选择eth3和eth4作为bond口。

首先是/etc/config/network中的配置：

```
# 添加eth3 eth4 as wan的配置
config interface 'WAN3'
	option proto 'dhcp'
	option device 'eth3'

config interface 'WAN4'
	option proto 'dhcp'
	option device 'eth4'
```

然后进行bond配置：

```
ip link add bond-wan type bond mode balance-rr
ip link set eth3 type bond_slave
ip link set eth4 type bond_slave

ip link set eth3 master bond-wan
ip link set eth3 master bond-wan

ip link set eth4 master bond-wan
ip link set bond-wan up
```



#### 3. 测试

执行udhcpc -i bond-wan获取到了IP，和交换机进行ping通。同时进行网线在两个端口上面的切换。

```
# ping 192.168.110.1 -I bond-wan
PING 192.168.110.1 (192.168.110.1): 56 data bytes
64 bytes from 192.168.110.1: seq=0 ttl=64 time=0.310 ms
64 bytes from 192.168.110.1: seq=1 ttl=64 time=0.210 ms
64 bytes from 192.168.110.1: seq=2 ttl=64 time=0.198 ms
64 bytes from 192.168.110.1: seq=3 ttl=64 time=0.223 ms
64 bytes from 192.168.110.1: seq=4 ttl=64 time=0.190 ms
64 bytes from 192.168.110.1: seq=5 ttl=64 time=0.182 ms
64 bytes from 192.168.110.1: seq=6 ttl=64 time=0.181 ms
64 bytes from 192.168.110.1: seq=7 ttl=64 time=0.204 ms
[ 1389.368537] igb 0000:03:00.0 eth3: igb: eth3 NIC Link is Down
[ 1389.439141] 8021q: adding VLAN 0 to HW filter on device eth3
[ 1391.848884] igb 0000:04:00.0 eth4: igb: eth4 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: RX/TX
64 bytes from 192.168.110.1: seq=13 ttl=64 time=0.216 ms
64 bytes from 192.168.110.1: seq=14 ttl=64 time=0.190 ms
64 bytes from 192.168.110.1: seq=15 ttl=64 time=0.273 ms
64 bytes from 192.168.110.1: seq=16 ttl=64 time=0.267 ms
[ 1398.288540] igb 0000:04:00.0 eth4: igb: eth4 NIC Link is Down
[ 1398.359096] 8021q: adding VLAN 0 to HW filter on device eth4
[ 1400.678885] igb 0000:03:00.0 eth3: igb: eth3 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: RX/TX
64 bytes from 192.168.110.1: seq=22 ttl=64 time=0.245 ms
64 bytes from 192.168.110.1: seq=23 ttl=64 time=0.269 ms
```

