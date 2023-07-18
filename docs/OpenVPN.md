### OpenVPN测试

openVPN的基础选项应至少满足：
```
CONFIG_PACKAGE_openvpn-openssl=y
CONFIG_OPENVPN_openssl_ENABLE_LZO=y
CONFIG_OPENVPN_openssl_ENABLE_LZ4=y
CONFIG_OPENVPN_openssl_ENABLE_FRAGMENT=y
CONFIG_OPENVPN_openssl_ENABLE_MULTIHOME=y
CONFIG_OPENVPN_openssl_ENABLE_PORT_SHARE=y
CONFIG_OPENVPN_openssl_ENABLE_DEF_AUTH=y
CONFIG_OPENVPN_openssl_ENABLE_PF=y
CONFIG_OPENVPN_openssl_ENABLE_SMALL=y

```

#### 1.搭建环境

![](https://openwrt.org/_media/docs/guide-user/network/openvpn.jpeg?w=800&tok=2265b0)

#### 2. openvpn认证生成

包含client和server。我是在Ubuntu机器上生成的。生成文件后设备的配置需要，然后按照配置把对应的文件放到/etc/openvpn下面。

```
URL="https://openwrt.org/_export/code/docs/guide-user/services/vpn/openvpn"
cat << EOF > ovpn.sh
OVPN_DIR="openvpn"
OVPN_PKI="\${OVPN_DIR}/pki"
OVPN_PORT="1194"
OVPN_PROTO="udp"
OVPN_POOL="192.168.8.0 255.255.255.0"
OVPN_DNS="\${OVPN_POOL%.* *}.1"
OVPN_DOMAIN="lan"
FETCHIP_URL="http://v4.ipv6-test.com/api/myip.php"
OVPN_SERV="\$(curl "\${FETCHIP_URL}")"
EASYRSA_URL="https://github.com/OpenVPN/easy-rsa/releases/download/v3.0.6/EasyRSA-unix-v3.0.6.tgz"
if [ ! -f "EasyRSA.tgz" ]
then
wget -O EasyRSA.tgz "\${EASYRSA_URL}"
tar -z -x -f EasyRSA.tgz
fi
alias easyrsa="EasyRSA-v3.0.6/easyrsa"
$(curl "${URL}/server?codeblock=1")
$(curl "${URL}/server?codeblock=3" \
| sed -e "/^\/etc\/init\.d\//d")
ls \${OVPN_DIR}/*.conf
EOF
sh ovpn.sh
```

正确的执行完应该生成如下文件：

```
root@ubuntu:/home/liji/openvpn-test# tree
.
├── EasyRSA.tgz
├── EasyRSA-v3.0.6
│   ├── ChangeLog
│   ├── COPYING.md
│   ├── doc
│   │   ├── EasyRSA-Advanced.md
│   │   ├── EasyRSA-Readme.md
│   │   ├── EasyRSA-Upgrade-Notes.md
│   │   ├── Hacking.md
│   │   └── Intro-To-PKI.md
│   ├── easyrsa
│   ├── gpl-2.0.txt
│   ├── mktemp.txt
│   ├── openssl-easyrsa.cnf
│   ├── README.md
│   ├── README.quickstart.md
│   ├── vars.example
│   └── x509-types
│       ├── ca
│       ├── client
│       ├── code-signing
│       ├── COMMON
│       ├── server
│       └── serverClient
├── openvpn
│   ├── client.ovpn
│   ├── pki
│   │   ├── ca.crt
│   │   ├── certs_by_serial
│   │   │   ├── D033FC4DB375A5D2869B3930A167D9AD.pem
│   │   │   └── F128975AB3A2F6F1E203EC368A8881DA.pem
│   │   ├── dh.pem
│   │   ├── extensions.temp
│   │   ├── index.txt
│   │   ├── index.txt.attr
│   │   ├── index.txt.attr.old
│   │   ├── index.txt.old
│   │   ├── issued
│   │   │   ├── client.crt
│   │   │   └── server.crt
│   │   ├── openssl-easyrsa.cnf
│   │   ├── private
│   │   │   ├── ca.key
│   │   │   ├── client.key
│   │   │   └── server.key
│   │   ├── renewed
│   │   │   ├── certs_by_serial
│   │   │   ├── private_by_serial
│   │   │   └── reqs_by_serial
│   │   ├── reqs
│   │   │   ├── client.req
│   │   │   └── server.req
│   │   ├── revoked
│   │   │   ├── certs_by_serial
│   │   │   ├── private_by_serial
│   │   │   └── reqs_by_serial
│   │   ├── safessl-easyrsa.cnf
│   │   ├── serial
│   │   └── serial.old
│   └── server.conf
├── openvpn.sh
└── ovpn.sh
```



#### 3. R1配置

```
# /etc/config/network
 
config interface 'lan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '172.16.1.1'
	option netmask '255.255.255.0'
 
config interface 'wan'
	option device 'eth0'
	option proto 'static'
	option ipaddr '10.1.1.1'
	option netmask '255.255.255.252'
	option gateway '10.1.1.2'
 
# /etc/config/openvpn
 
uci import openvpn < /dev/null
uci set openvpn.myvpn=openvpn
uci set openvpn.myvpn.enabled=1
uci set openvpn.myvpn.dev=tun
uci set openvpn.myvpn.proto=udp
uci set openvpn.myvpn.verb=3
uci set openvpn.myvpn.ca=/etc/openvpn/ca.crt
uci set openvpn.myvpn.cert=/etc/openvpn/client.crt
uci set openvpn.myvpn.key=/etc/openvpn/client.key
uci set openvpn.myvpn.client=1
uci set openvpn.myvpn.remote_cert_tls=server
uci set openvpn.myvpn.remote="SERVER_IP_ADDRESS 1194"
uci commit openvpn
```



#### 4. R2配置

```
# /etc/config/network
 
config interface 'lan'
	option device 'eth1'
	option proto 'static'
	option ipaddr '172.16.2.1'
	option netmask '255.255.255.0'
 
config interface 'wan'
	option device 'eth0'
	option proto 'static'
	option ipaddr '10.2.2.1'
	option netmask '255.255.255.252'
	option gateway '10.2.2.2'
 
# /etc/config/openvpn
 
uci import openvpn < /dev/null
uci set openvpn.myvpn=openvpn
uci set openvpn.myvpn.enabled=1
uci set openvpn.myvpn.verb=3
uci set openvpn.myvpn.port=1194
uci set openvpn.myvpn.proto=udp
uci set openvpn.myvpn.dev=tun
uci set openvpn.myvpn.server='10.8.0.0 255.255.255.0'
uci set openvpn.myvpn.keepalive='10 120'
uci set openvpn.myvpn.ca=/etc/openvpn/ca.crt
uci set openvpn.myvpn.cert=/etc/openvpn/server.crt
uci set openvpn.myvpn.key=/etc/openvpn/server.key
uci set openvpn.myvpn.dh=/etc/openvpn/dh.pem
uci commit openvpn
```



#### 5. R0配置

```
# /etc/config/network
 
config interface 'lan1'
	option device 'eth0'
	option proto 'static'
	option ipaddr '10.1.1.2'
	option netmask '255.255.255.252'
 
config interface 'lan2'
	option device 'eth1'
	option proto 'static'
	option ipaddr '10.2.2.2'
	option netmask '255.255.255.252'
 
config route 'net1'
	option interface 'lan1'
	option target '172.16.1.0'
	option netmask '255.255.255.0'
	option gateway '10.1.1.1'
 
config route 'net2'
	option interface 'lan2'
	option target '172.16.2.0'
	option netmask '255.255.255.0'
	option gateway '10.2.2.1'
```


更改完配置后重启下vpn服务，如下所示：
```
/etc/init.d/openvpn restart
```

#### 6. Client PCs

```
# PC1
address 172.16.1.3/24
gateway 172.16.1.1
 
# PC2 
address 172.16.2.3/24
gateway 172.16.2.1 
```

