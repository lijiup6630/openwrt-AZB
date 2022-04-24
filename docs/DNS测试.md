#### DNS测试

OpenWrt自带功能，将下联设备接入LAN侧并自动获取IP，能ping通外网域名即可。表示设备将本机的DNS请求转向给指定的DNS服务器。

dns测试比较简单。主要是OpenWRT的LAN侧下联设备。下联设备（也是OpenWrt）dhcp获取到ip地址。

```
#下联设备
4: eth1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 00:0c:29:42:43:51 brd ff:ff:ff:ff:ff:ff
    inet 192.168.1.211/24 brd 192.168.1.255 scope global eth1
       valid_lft forever preferred_lft forever
    inet6 fdc3:6de2:8b24:2:20c:29ff:fe42:4351/64 scope global dynamic noprefixroute 
       valid_lft 42922sec preferred_lft 42922sec
    inet6 fdc3:6de2:8b24:2::36d/128 scope global dynamic noprefixroute 
       valid_lft 42922sec preferred_lft 42922sec
    inet6 fdc3:6de2:8b24::36d/128 scope global dynamic noprefixroute 
       valid_lft 42922sec preferred_lft 42922sec
    inet6 fe80::20c:29ff:fe42:4351/64 scope link 
       valid_lft forever preferred_lft forever

```

下联设备默认resolv.conf：

```
root@OpenWrt:~# cat /etc/resolv.conf 
search lan
nameserver 127.0.0.1
nameserver ::1
```

将其设置为上联LAN的地址：

```
root@OpenWrt:~# echo nameserver 192.168.1.1 > /etc/resolv.conf
root@OpenWrt:~# cat /etc/resolv.conf 
nameserver 192.168.1.1
```

ping下百度：

```
root@OpenWrt:~# ping www.baidu.com
PING www.baidu.com (110.242.68.4): 56 data bytes
64 bytes from 110.242.68.4: seq=0 ttl=127 time=25.392 ms
64 bytes from 110.242.68.4: seq=1 ttl=127 time=26.718 ms
64 bytes from 110.242.68.4: seq=2 ttl=127 time=26.547 ms
64 bytes from 110.242.68.4: seq=3 ttl=127 time=26.541 ms
^C
--- www.baidu.com ping statistics ---
4 packets transmitted, 4 packets received, 0% packet loss
round-trip min/avg/max = 25.392/26.299/26.718 ms
```

