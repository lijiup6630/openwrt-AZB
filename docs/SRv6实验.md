### SRv6实验



#### 1. 拓扑图

![](https://img-blog.csdnimg.cn/93d4e7eda877466e962b96ad646b95db.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NjQ2NjcyMg==,size_16,color_FFFFFF,t_70)



#### 2. 环境说明

拓扑图中描述的CPE为我们使用的OpenWrt设备。其中WAN<->WAN使用ipv6技术，LAN下联终端ipv4。

终端1发送数据包后，由CPE1封装成SRv6数据包，通过IPv6地址发送至CPE2，CPE2收到此数据包后进行解封装，通过源数据包中的IPv4地址转发给终端2，由此实现远程两端在逻辑上的连通。

整个数据包的流程如下图所示：

![](https://img-blog.csdnimg.cn/016cd40064924c7cbe35e3a606c23b30.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NjQ2NjcyMg==,size_16,color_FFFFFF,t_70)



#### 3. 配置

网口的配置需注意的一点是，最好在WAN，LAN的配置中加入：

```
option ip6segmentrouting '1'
```

其余配置正常配即可。

##### CPE1的配置：

```
echo "100 SRv6" >> /etc/iproute2/rt_tables
echo "101 Recive" >> /etc/iproute2/rt_tables
echo "102 SID_IPv6" >> /etc/iproute2/rt_tables

ip route add 192.168.3.0/24 encap seg6 mode encap segs fc00::3 dev wan table 100
ip rule add to 192.168.3.0/24 table 100 pri 10

ip -6 route add fc00::1/128 encap seg6local action End.DX4 nh4 192.168.1.195 dev br-lan table 101
ip -6 route add fc00::3/128 via 2001:250:640b::a05:a84:130 table 102
ip -6 rule add table 101 pri 11
ip -6 rule add table 102 pri 12
```

##### CPE2的配置：

```
echo "100 SRv6" >> /etc/iproute2/rt_tables
echo "101 Recive" >> /etc/iproute2/rt_tables
echo "102 SID_IPv6" >> /etc/iproute2/rt_tables

ip route add 192.168.1.0/24 encap seg6 mode encap segs fc00::1 dev wan table 100
ip rule add to 192.168.1.0/24 table 100 pri 10

ip -6 route add fc00::3/128 encap seg6local action End.DX4 nh4 192.168.3.181 dev br-lan table 101
ip -6 route add fc00::1/128 via 2001:250:640b::a05:a84:110 table 102
ip -6 rule add table 101 pri 11
ip -6 rule add table 102 pri 12
```



#### 4. 测试

