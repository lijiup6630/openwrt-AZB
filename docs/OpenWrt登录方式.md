#### OpenWrt登录方式

三种，串口，telnet，ssh。并不是很推荐telnet，强烈的建议禁用它。



串口，不再说明。

SSH:

```
[C:\~]$ ssh root@192.168.31.55


Connecting to 192.168.31.55:22...
Connection established.
To escape to local shell, press 'Ctrl+Alt+]'.



BusyBox v1.35.0 (2022-04-24 17:06:32 UTC) built-in shell (ash)

  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 OpenWrt 22.03-SNAPSHOT, r19211-bfbe4e45a6
 -----------------------------------------------------
=== WARNING! =====================================
There is no root password defined on this device!
Use the "passwd" command to set up a new password
in order to prevent unauthorized SSH logins.
--------------------------------------------------

```



TELNET:

```
[C:\~]$ telnet root@192.168.31.55


Connecting to 192.168.31.55:23...
Connection established.
To escape to local shell, press 'Ctrl+Alt+]'.

OpenWrt login: root


BusyBox v1.35.0 (2022-04-24 17:06:32 UTC) built-in shell (ash)

  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 OpenWrt 22.03-SNAPSHOT, r19211-bfbe4e45a6
 -----------------------------------------------------
=== WARNING! =====================================
There is no root password defined on this device!
Use the "passwd" command to set up a new password
in order to prevent unauthorized SSH logins.
--------------------------------------------------

```

