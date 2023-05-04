# Vxlan over IPsec
## 1.配置
### 设备A

``` 
cat /etc/swanctl/conf.d/swanctl_1.conf 
connections {
        host-host {
                local_addrs = 192.168.0.1
                remote_addrs = 192.168.0.2
                local {
                        auth = psk
                        id = moon.strongswan.org
                }
                remote {
                        auth = psk
                        id = sun.strongswan.org
                }
                children {
                        host-host {
								local_ts = 192.168.0.1/24[udp/4789-65535]
                                esp_proposals = aes128-sha1-modp2048
                                mode = transport
                        }
                }
                version = 2
                proposals = aes128-sha256-x25519
        }
}
secrets {
        ike-host-host {
                id = moon.strongswan.org
                secret = simplepsk
        }
}

# Include config snippets
include conf.d/*.conf

```
```
ip link add name vpp1out type veth peer name vpp1host
ip link set dev vpp1out up
ip link set dev vpp1host up
ip addr add 192.168.1.10/24 dev vpp1host
```
```
vppctl
lcp create eth1 host-if eth1
set interface state eth1 up
set interface ip address eth1 192.168.0.1/24
create host-interface name vpp1out
create bridge-domain 11 learn 1 forward 1 uu-flood 1 flood 1 arp-term 0
create vxlan tunnel src 192.168.0.1 dst 192.168.0.2 vni 11 decap-next l2
set interface l2 bridge vxlan_tunnel0 11
set interface l2 bridge vpp1out 11
set int state host-vpp1out up
set int state vxlan_tunnel0 up
```
```
ipsec restart
swanctl --load-all
```

## 设备B

``` 
connections {
        host-host {
                local_addrs = 192.168.0.2
                remote_addrs = 192.168.0.1
                local {
                        auth = psk
                        id = sun.strongswan.org
                }
                remote {
                        auth = psk
                        id = moon.strongswan.org
                }
                children {
                        host-host {
								local_ts = 192.168.0.2/24[udp/4789-65535]
                                esp_proposals = aes128-sha1-modp2048
								mode = transport
                        }
                }
                version = 2
                proposals = aes128-sha256-x25519
        }
}
secrets {
        ike-host-host {
                id = moon.strongswan.org
                secret = simplepsk
        }
}

# Include config snippets
include conf.d/*.conf
```
```
ip link add name vpp1out type veth peer name vpp1host
ip link set dev vpp1out up
ip link set dev vpp1host up
ip addr add 192.168.1.10/24 dev vpp1host
```
```
vppctl
lcp create eth1 host-if eth1
set interface state eth1 up
set interface ip address eth1 192.168.0.1/24
create host-interface name vpp1out
create bridge-domain 11 learn 1 forward 1 uu-flood 1 flood 1 arp-term 0
create vxlan tunnel src 192.168.0.1 dst 192.168.0.2 vni 11 decap-next l2
set interface l2 bridge vxlan_tunnel0 11
set interface l2 bridge vpp1out 11
set int state host-vpp1out up
set int state vxlan_tunnel0 up
```
```
ipsec restart
swanctl --load-all
ipsec up host-host
```

## 测试结果
设备A ping 设备B

``` 
ping 192.168.0.2
PING 192.168.0.2 (192.168.0.2) 56(84) bytes of data.
64 bytes from 192.168.0.2: icmp_seq=1 ttl=64 time=0.424 ms
64 bytes from 192.168.0.2: icmp_seq=2 ttl=64 time=0.185 ms
64 bytes from 192.168.0.2: icmp_seq=3 ttl=64 time=0.183 ms
64 bytes from 192.168.0.2: icmp_seq=4 ttl=64 time=0.190 ms
64 bytes from 192.168.0.2: icmp_seq=5 ttl=64 time=0.179 ms
```
抓包
[![i69y3y.png](https://i.328888.xyz/2023/04/19/i69y3y.png)](https://imgloc.com/i/i69y3y)






