#### OpenWrt编译DPDK VPP-22.02



#### 1. 编译环境准备

我们将工作目录设置为/mnt，全部的操作都在此目录下进行。

将OpenWrt编译出来的SDK放到OpenWrt的/mnt下解压：

```
xz -d openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar.xz
tar xvf openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar
```

设置环境变量：

```
export PATH=/mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/host/bin/:$PATH
```

然后修复一些引用：

```
cd /usr/lib/ && ln -s libcrypto.so.1.1 libcrypto.so && cd -
cd /usr/lib/ && ln -s libm.so.6 libm.so && cd -

cp /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/libmvec.so.1 /lib/

cd /usr/lib/ && ln -s /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/librt.so.1 librt.so && cd -

cd /usr/lib/ && ln -s /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/libdl.so.2 libdl.so && cd -

cp /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/host/include/openssl /usr/include/ -rf
```



#### 2. 编译DPDK

将dpdk-21.11.tar.xz放到OpenWrt的/mnt目录，然后解压后编译，如下：

```
xz -d dpdk-21.11.tar.xz
tar xvf dpdk-21.11.tar

pip install meson
pip install pyelftools

cd dpdk-21.11
meson --prefix=`pwd`/openwrt-dpdk -Dexamples=all build
ninja -C build 
ninja -C build install
```

运行完之后出现目录openwrt-dpdk，生成的文件在这里。



#### 3. 编译numa

numa源码下载下来需要在host上交叉编译，我们只用生成的文件即可。

HOST toolchain搭建：

```
#我的cross compile路径
/home/liji/work-project/INTEL/sdk/openwrt-toolchain-x86-64_gcc-11.2.0_glibc.Linux-x86_64/toolchain-x86_64_gcc-11.2.0_glibc/bin
#我的staging目录的路径
/home/liji/work-project/INTEL/openwrt-AZB/staging_dir

#设置当前环境变量
export PATH=/home/liji/work-project/INTEL/sdk/openwrt-toolchain-x86-64_gcc-11.2.0_glibc.Linux-x86_64/toolchain-x86_64_gcc-11.2.0_glibc/bin:$PATH
export STAGING_DIR=/home/liji/work-project/INTEL/openwrt-AZB/staging_dir
```

HOST交叉编译numa:

```
git clone https://gitee.com/aleelim/numactl.git
#这里host指定仅仅是为了声明交叉编译，没有其它意义，只要合法都可以
./configure --prefix=`pwd`/build --host=arm-linux CC=x86_64-openwrt-linux-gnu-gcc
make
make install
```



#### 4. 编译VPP

预先准备：

-- 把ubuntu的libdpdk.a放到/usr/lib下面

-- 把dpdk编译生成的openwrt-dpdk目录下的include和lib复制到/usr/include和/usr/lib下面。

-- 把numa生成的文件也放到openwrt的相关位置

```
git clone https://gitee.com/linux-fun/vpp.git
cd vpp && git checkout v22.02
cd src && mkdir build && cd build

rm ../plugins/tlsopenssl/ -rf
rm ../plugins/wireguard/ -rf

cmake -DCMAKE_INSTALL_PREFIX=`pwd`/vpp-build ..
make install
```

启动vpp:

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/vpp/src/build/vpp-build/
lib64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/openwrt-sdk-x86-64_gcc-11.2.
0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib

root@OpenWrt:/mnt/vpp/src/build/vpp-build# ./bin/vpp -c etc/vpp/startup.conf 
unix_config:476: couldn't open log '/var/log/vpp/vpp.log'
./bin/vpp[1204]: clib_sysfs_prealloc_hugepages:261: pre-allocating 1 additional 2048K hugepages on numa node 0
./bin/vpp[1204]: perfmon: skipping source 'intel-uncore' - intel_uncore_init: failed to discover numa topology
./bin/vpp[1204]: clib_sysfs_prealloc_hugepages:261: pre-allocating 8 additional 2048K hugepages on numa node 0
./bin/vpp[1204]: pci: Skipping PCI device 0000:72:00.0 as host interface eth0 is up
./bin/vpp[1204]: pci: Skipping PCI device 0000:72:00.3 as host interface eth3 is up

root@OpenWrt:/mnt/vpp/src/build/vpp-build/bin# ./vppctl 
    _______    _        _   _____  ___ 
 __/ __/ _ \  (_)__    | | / / _ \/ _ \
 _/ _// // / / / _ \   | |/ / ___/ ___/
 /_/ /____(_)_/\___/   |___/_/  /_/    

vpp# show int
              Name               Idx    State  MTU (L3/IP4/IP6/MPLS)     Counter          Count     
GigabitEthernet72/0/1             1     down         9000/0/0/0     
GigabitEthernet72/0/2             2     down         9000/0/0/0     
local0                            0     down          0/0/0/0       
vpp# 

root@OpenWrt:/mnt/vpp/src/build/bin# ./vppctl 
    _______    _        _   _____  ___ 
 __/ __/ _ \  (_)__    | | / / _ \/ _ \
 _/ _// // / / / _ \   | |/ / ___/ ___/
 /_/ /____(_)_/\___/   |___/_/  /_/    

vpp# 
vpp# 
vpp# show interface 
              Name               Idx    State  MTU (L3/IP4/IP6/MPLS)     Counter          Count     
GigabitEthernet72/0/1             1     down         9000/0/0/0     
GigabitEthernet72/0/2             2     down         9000/0/0/0     
local0                            0     down          0/0/0/0       
vpp# set interface state GigabitEthernet72/0/1 up
vpp# set interface ip address GigabitEthernet72/0/1 192.168.110.234/24
vpp# 
vpp# 
vpp# 
vpp# ping 192.168.110.1
116 bytes from 192.168.110.1: icmp_seq=2 ttl=64 time=.2616 ms
116 bytes from 192.168.110.1: icmp_seq=3 ttl=64 time=.1968 ms
116 bytes from 192.168.110.1: icmp_seq=4 ttl=64 time=.2224 ms
116 bytes from 192.168.110.1: icmp_seq=5 ttl=64 time=.2553 ms

Statistics: 5 sent, 4 received, 20% packet loss
vpp# 

```

