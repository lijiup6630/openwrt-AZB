PPPoE



#### 1. 目的

OpenWrt作为PPPoE的客户端，HOST使用Ubuntu搭建一个PPPoE的模拟服务器，然后OpenWrt进行拨号。



#### 2. Ubuntu服务器PPPoE搭建

```
ubuntu:~$ sudo apt-get install pppoe
ubuntu:~$ pppoe-server -h
PPPoE-Server Version 3.12, Copyright (C) 2001-2009 Roaring Penguin Software Inc.
PPPoE-Server comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under the terms of the GNU General Public License, version 2
or (at your option) any later version.
http://www.roaringpenguin.com
```

