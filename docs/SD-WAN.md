# Netopeer使用说明
## 环境
使用的config为sdwan.config，正常编译即可
在使用前需要先加载network相关的yang模型

``` 
cd /etc/sysrepo/yang/
sysrepoctl -i ietf-interfaces.yang
sysrepoctl -i iana-if-type.yang
sysrepoctl -i ietf-ip.yang
```
另外此功能验证需要root密码

``` 
passwd root
```


##测试
关闭firewall

``` 
service firewall stop
```
启动openwrt网络功能sysrepo插件

``` 
sysrepo-plugin-network 
```
启动netopeer-server
``` 
netopeer2-server -d -v 0
```
打开另一终端或者在其他装有cli的设备上启动netopeer-cli
``` 
netopeer2-cli
> connect localhost
Interactive SSH Authentication
Type your password:
Password: 
> 
```
获取当前网络配置

``` 
> get-config --source running --filter-xpath /ietf-interfaces:*
DATA
<interfaces xmlns="urn:ietf:params:xml:ns:yang:ietf-interfaces">
  <interface>
    <name>loopback</name>
    <type xmlns:ianaift="urn:ietf:params:xml:ns:yang:iana-if-type">ianaift:ethernetCsmacd</type>
    <ipv4 xmlns="urn:ietf:params:xml:ns:yang:ietf-ip">
      <ip>127.0.0.1</ip>
      <prefix-length>8</prefix-length>
    </ipv4>
  </interface>
  <interface>
    <name>lan</name>
    <type xmlns:ianaift="urn:ietf:params:xml:ns:yang:iana-if-type">ianaift:ethernetCsmacd</type>
    <ipv4 xmlns="urn:ietf:params:xml:ns:yang:ietf-ip">
      <ip>192.168.1.1</ip>
      <prefix-length>24</prefix-length>
    </ipv4>
  </interface>
  <interface>
    <name>wan</name>
    <type xmlns:ianaift="urn:ietf:params:xml:ns:yang:iana-if-type">ianaift:ethernetCsmacd</type>
  </interface>
  <interface>
    <name>wan6</name>
    <type xmlns:ianaift="urn:ietf:params:xml:ns:yang:iana-if-type">ianaift:ethernetCsmacd</type>
  </interface>
</interfaces>
```
更改网络配置
创建xml配置文件 将桥的ip和子网掩码分别改为1.2和8
``` 
vi /root/test.xml
<interfaces xmlns="urn:ietf:params:xml:ns:yang:ietf-interfaces">
  <interface>                                                                                   
    <name>lan</name>                                                                            
    <type xmlns:ianaift="urn:ietf:params:xml:ns:yang:iana-if-type">ianaift:ethernetCsmacd</type>
    <ipv4 xmlns="urn:ietf:params:xml:ns:yang:ietf-ip">                                          
      <ip>192.168.1.2</ip>                                                                      
      <prefix-length>8</prefix-length>                                                          
    </ipv4>                                                                                     
  </interface>                                                                                  
</interfaces>
```

``` 
> edit-config --target running --config=/root/test.xml
OK
```
查看uci文件

``` 
cat /etc/config/network
...
config interface 'lan'
	option device 'br-lan'
	option proto 'static'
	option ip6assign '60'
	option ipaddr '192.168.1.2'
	option netmask '255.0.0.0'
...
```
查看网络配置
``` 
ifconfig br-lan
br-lan    Link encap:Ethernet  HWaddr 00:0C:29:99:26:15  
          inet addr:192.168.1.2  Bcast:192.255.255.255  Mask:255.0.0.0
          inet6 addr: fd58:848c:1b79::1/60 Scope:Global
          inet6 addr: fe80::20c:29ff:fe99:2615/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:10 errors:0 dropped:0 overruns:0 frame:0
          TX packets:20 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:1292 (1.2 KiB)  TX bytes:2356 (2.3 KiB)

```
验证成功
