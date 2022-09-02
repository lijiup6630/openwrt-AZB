### OpenWrt in Container



#### 1. 包需求

```
Target Images ->
	*** Root filesystem archives ***
	 [*] tar.gz
```

编译完之后会生成openwrt-x86-64-generic-rootfs.tar.gz这个文件。我们也是用它作为docker的文件系统。



#### 2. 导入镜像

```
liji@liji-pc:/tmp$ sudo docker import openwrt-x86-64-generic-rootfs.tar.gz openwrt-x86-generic-rootfs
[sudo] password for liji: 
sha256:0ef8832bc2bc5cda862db478949e7978196d80c9f155be26843a7f9e3655dcdf
liji@liji-pc:/tmp$ sudo docker images
REPOSITORY                   TAG       IMAGE ID       CREATED         SIZE
openwrt-x86-generic-rootfs   latest    0ef8832bc2bc   7 seconds ago   86.9MB
```



#### 3. 执行OpenWrt命令

```
liji@liji-pc:/tmp$ sudo docker run -i openwrt-x86-generic-rootfs cat /etc/banner
  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 OpenWrt 22.03-SNAPSHOT, r19220-998c17c118
 -----------------------------------------------------
liji@liji-pc:/tmp$ sudo docker run -i openwrt-x86-generic-rootfs ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
11: eth0@if12: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default 
    link/ether 02:42:ac:11:00:02 brd ff:ff:ff:ff:ff:ff link-netnsid 0
    inet 172.17.0.2/16 brd 172.17.255.255 scope global eth0
       valid_lft forever preferred_lft forever
```

或者是进入OpenWrt命令行

```
liji@liji-pc:/tmp$ sudo docker run -i -t openwrt-x86-generic-rootfs /bin/ash


BusyBox v1.35.0 (2022-06-26 04:10:00 UTC) built-in shell (ash)

/ # ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
13: eth0@if14: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default 
    link/ether 02:42:ac:11:00:02 brd ff:ff:ff:ff:ff:ff link-netnsid 0
    inet 172.17.0.2/16 brd 172.17.255.255 scope global eth0
       valid_lft forever preferred_lft forever
```



#### 4. Ubuntu20运行挂载pcie的OpenWrt

```
docker run -it -d --privileged -v /sys/bus/pci/drivers:/sys/bus/pci/drivers -v /sys/kernel/mm/hugepages:/sys/kernel/mm/hugepages -v /sys/devices/system/node:/sys/devices/system/node -v /dev:/dev openwrt-x86-generic-rootfs ash
docker attach [容器ID]
```

在docker中使用vpp和在host中使用vpp是一样的。
