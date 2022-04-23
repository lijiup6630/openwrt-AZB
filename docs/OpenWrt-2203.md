### CPU OS KERNEL



#### 1. 编译

```
./scripts/feeds update -a
./scripts/feeds install -a
make x86_64_defconfig
make 
```

生成的目标镜像位于：bin/targets/x86/64-glibc。



#### 2. CPU

通过cat /proc/cpu查看当前CPU：

```
root@OpenWrt:/# cat /proc/cpuinfo 
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 154
model name	: 12th Gen Intel(R) Core(TM) i7-1250U
stepping	: 4
microcode	: 0x419
cpu MHz		: 496.516
cache size	: 12288 KB
physical id	: 0
siblings	: 12
core id		: 0
cpu cores	: 10
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 32
wp		: yes
....
....
processor	: 11
vendor_id	: GenuineIntel
cpu family	: 6
model		: 154
model name	: 12th Gen Intel(R) Core(TM) i7-1250U
stepping	: 4
microcode	: 0x419
cpu MHz		: 534.377
cache size	: 12288 KB
```

总共12个核。

#### 3. OS

查看系统OS版本：

```
BusyBox v1.35.0 (2022-03-31 13:42:59 UTC) built-in shell (ash)

  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 OpenWrt 22.03-SNAPSHOT, r19201-c3ed1d80e1
 -----------------------------------------------------

```

此版本为OpenWrt github 22.03分支，commit id为c3ed1d80e1。



#### 4. kernel

查看系统kernel版本：

```
root@OpenWrt:/# uname -a
Linux OpenWrt 5.10.108 #0 SMP Thu Mar 31 13:42:59 2022 x86_64 GNU/Linux
```



