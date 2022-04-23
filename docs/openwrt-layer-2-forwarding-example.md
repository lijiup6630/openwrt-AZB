### OpenWrt的三层转发功能测试

#### 1. 说明

验证OpenWrt的二层转发功能

#### 2. 网络拓扑及测试说明

[![image-20220303161939.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed32548eecaf08f3ddfa99259eafbaef5df/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed32548eecaf08f3ddfa99259eafbaef5df/0.png)

如上图所示，PC1和PC2连入R1的LAN侧，正常情况下，PC1和PC2能够互相ping通。

#### 3. 测试

（1）虚拟机R1的配置
将虚拟机R1的两张网卡eth0和eth2分别放到LAN1和LAN3中，目的是避免PC1和PC2直接访问而不经过R1。

[![qq图片20220303163729.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3a91ce5505b26757842425d6d06a5ade8/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3a91ce5505b26757842425d6d06a5ade8/0.png)

[![qq图片20220303163724.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed35c8c83aa7d114c7545d4126826636368/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed35c8c83aa7d114c7545d4126826636368/0.png)

openwrt配置如下：
```
root@OpenWrt:~# cat /etc/config/network 

config interface 'loopback'
	option device 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fd81:e072:031d::/48'

config device
	option name 'br-lan'
	option type 'bridge'
	list ports 'eth0'
	list ports 'eth2'

config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ipaddr '192.168.1.1'
	option netmask '255.255.255.0'
	option ip6assign '60'

config interface 'wan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '192.168.129.135'
	option netmask '255.255.255.0'
	option dns '223.5.5.5'
	option gateway '192.168.129.2'
```

（2）虚拟机PC1配置：

虚拟机PC1配置单网卡，将唯一的网卡添加到虚拟机网桥LAN1中，这样相当于PC1的eth0和R1的eth0在同一个私网中了。
[![qq图片20220303164552.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3d30c4b398535132c08df6b39ccbcb8f7/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3d30c4b398535132c08df6b39ccbcb8f7/0.png)

openwrt设置如下所示：

[![qq图片20220303165014.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed318fa996bfdb502b00c51919e89a55924/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed318fa996bfdb502b00c51919e89a55924/0.png)

[![qq图片20220303164505.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed329435f16f09ddc1f62b161a2a8c1d5c1/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed329435f16f09ddc1f62b161a2a8c1d5c1/0.png)

（3）虚拟机PC2配置：

虚拟机PC2配置单网卡，将唯一的网卡添加到虚拟机网桥LAN3中，这样相当于PC2的eth0和R1的eth2在同一个私网中了。

[![qq图片20220303163724.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed305c5944a9a34e8d596387c7c6c6e6e80/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed305c5944a9a34e8d596387c7c6c6e6e80/0.png)

openwrt设置如下：

[![qq图片20220303165309.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3a09de442bd2a89bb175a34ed9819eb65/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3a09de442bd2a89bb175a34ed9819eb65/0.png)

[![qq图片20220303165305.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3805cfb0bee48590fe68508d454621374/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3805cfb0bee48590fe68508d454621374/0.png)


此时PC1 ping PC 2，结果如下图所示：

[![qq图片20220303165839.png](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3dadbeee27f4525b1bf60f047f165a04d/0.png)](https://p.qlogo.cn/hy_personal/3e28f14aa05168427911cdb028a18ed3dadbeee27f4525b1bf60f047f165a04d/0.png)

可ping通，且PC1的arp表中记录下了PC2的mac地址，验证成功。