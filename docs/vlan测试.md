#### VLAN测试

配置eth0为WAN。

#### 设备A

#### 1. 创建vlan子接口

```
ip link add link eth0 name eth0.5 type vlan id 5
ip link
ip -d link show eth0.5
```
#### 2. 分配IP并设置启动
```
ip addr add 192.168.1.200/24 brd 192.168.1.255 dev eth0.5
ip link set dev eth0.5 up
```

#### 设备B

#### 1. 创建vlan子接口
```
ip link add link eth0 name eth0.5 type vlan id 5
ip link
ip -d link show eth0.5
```
#### 2. 分配IP并设置启动
```
ip addr add 192.168.1.100/24 brd 192.168.1.255 dev eth0.5
ip link set dev eth0.5 up
```
设备A ping 设备B。抓包查看vlan标签。

#### 四、 删除vlan

```
ip link set dev eth0.5 down
ip link delete eth0.5
```











