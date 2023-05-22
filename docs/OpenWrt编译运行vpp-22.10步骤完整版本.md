#### OpenWrt编译运行VPP-22.10步骤完整版本



#### 1. 编译环境准备

使用OpenWrt的vmware虚拟机作为编译Host，其中vmware有两个硬盘，一个是OpenWrt的镜像，另一个是我们添加的用于存放和编译OpenWrt。

```
root@OpenWrt:~# ls /dev/sd*
/dev/sda     /dev/sda1    /dev/sda128  /dev/sda2    /dev/sdb     /dev/sdb1
root@OpenWrt:~# mount /dev/sdb1 /mnt/
root@OpenWrt:~# cd /mnt/
```

我们将工作目录设置为/mnt，全部的操作都在此目录下进行。将OpenWrt编译出来的SDK放到OpenWrt的/mnt下解压：

```
root@OpenWrt:/mnt# ls
openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar.xz
root@OpenWrt:/mnt# xz -d openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar.xz
root@OpenWrt:/mnt# tar xvf openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar 
root@OpenWrt:/mnt# ls
openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64      openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64.tar
```

设置环境变量：

```
export PATH=/mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/host/bin/:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/gcc/x86_64-openwrt-linux-gnu/11.2.0/
```

然后修复一些引用：

```
cd /usr/lib/ && ln -s libcrypto.so.1.1 libcrypto.so && cd -
cd /usr/lib/ && ln -s libm.so.6 libm.so && cd -

cp /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/libmvec.so.1 /lib/

cd /usr/lib/ && ln -s /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/librt.so.1 librt.so && cd -

cd /usr/lib/ && ln -s /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-11.2.0_glibc/lib/libdl.so.2 libdl.so && cd -

cp /mnt/openwrt-sdk-x86-64_gcc-11.2.0_glibc.Linux-x86_64/staging_dir/host/include/openssl /usr/include/ -rf

cd /lib && ln -s libpthread.so.0 libpthread.so && cd -
```



#### 2. 编译numa

**[第一种方式-直接在OpenWrt的vmware中编译]：**

```
./autogen.sh
./configure --disable-dependency-tracking
make
cp *.h /usr/include/
cp .libs/* /usr/lib/
```

**[第二种方式-交叉编译]：**

numa在非OpenWrt环境编译，我使用的是编译OpenWrt的Host。

在Host上解压SDK，解压过程同上，然后设置环境变量：

```
export PATH=<OpenWrt SDK>/glibc/openwrt-sdk-x86-64_gcc-8.3.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-8.3.0_glibc/bin/:$PATH
```

开始编译numa:

```
git clone https://gitee.com/aleelim/numactl.git -b v2.0.13
cd numactl
./autogen.sh
autoconf -i
./configure --host=arm-linux CC=x86_64-openwrt-linux-gnu-gcc --prefix=`pwd`/build
make 
make install
```

将生成的build目录下面的东西复制到OpenWrt的vmware编译机的/usr目录下。

```
# Host打包过程略,将生成的包压缩后放到vmware里面，然后解压到/usr
tar zxvf numa-2.0.13.tar.gz -C /usr/
```

然后执行：

```
cd /usr/lib && ln -s /usr/lib/libbpf.so.0 libbpf.so && cd -
```



#### 3. 编译DPDK

将dpdk-21.11.tar.xz放到OpenWrt的/mnt目录，然后解压后编译，如下：

```
root@OpenWrt:/mnt# xz -d dpdk-22.07.tar.xz
root@OpenWrt:/mnt# tar xvf dpdk-22.07.tar

root@OpenWrt:/mnt# pip install meson
root@OpenWrt:/mnt# pip install pyelftools

#执行源码前移除mlx的驱动，在drivers/net/meson.build文件的drivers数组

#meson --prefix=`pwd`/openwrt-dpdk -Dexamples=all build
meson --prefix=`pwd`/openwrt-dpdk build
ninja -C build 
ninja -C build install
```

运行完之后出现目录openwrt-dpdk，生成的文件在这里。

```
root@OpenWrt:/mnt/dpdk-22.07# ls 
ABI_VERSION        Makefile           VERSION            build              config             doc                examples           lib                meson.build        openwrt-dpdk
MAINTAINERS        README             app                buildtools         devtools           drivers            kernel             license            meson_options.txt  usertools
```

然后进入openwrt-dpdk目录，复制头文件和库到系统

```
root@OpenWrt:/mnt/dpdk-22.07# cd openwrt-dpdk/
root@OpenWrt:/mnt/dpdk-22.07/openwrt-dpdk# ls
bin      include  lib      share
root@OpenWrt:/mnt/dpdk-22.07/openwrt-dpdk# cp include/* /usr/include/ -rf
root@OpenWrt:/mnt/dpdk-22.07/openwrt-dpdk# cp lib/* /usr/lib/ -rf
```

[重要]自己动手制作libdpdk.a:

```
# 进入到openwrt-dpdk/lib目录，然后执行
echo "GROUP ( $(ls librte*.a ) )" > libdpdk.a
cp libdpdk.a /lib/libdpdk.a
```





#### 4.编译vpp

-- 从openwrt的源码里面把bpf头文件复制到/usr/include下面（暂未使用）

--从openwrt的源码里面把libbpf.a复制到/lib下面（暂未使用）

```
#这里使用af_xdp编译报错，我暂时是没有执行这一步
[ 61%] Linking C shared library ../../../lib64/vpp_plugins/af_xdp_plugin.so
/usr/bin/ld: /usr/lib/libbpf.a(bpf.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(libbpf.o): relocation R_X86_64_32 against `.text' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(netlink.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(nlattr.o): relocation R_X86_64_32S against `.rodata' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(str_error.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(libbpf_probes.o): relocation R_X86_64_32S against `.rodata' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(xsk.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(gen_loader.o): relocation R_X86_64_32S against `.rodata' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(relo_core.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(btf.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(strset.o): relocation R_X86_64_32 against `.text' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /usr/lib/libbpf.a(btf.o): warning: relocation against `libbpf_mode' in read-only section `.text'
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/plugins/af_xdp/CMakeFiles/af_xdp_plugin.dir/build.make:257: lib64/vpp_plugins/af_xdp_plugin.so] Error 1
make[1]: *** [CMakeFiles/Makefile2:8487: CMakeFiles/plugins/af_xdp/CMakeFiles/af_xdp_plugin.dir/all] Error 2
make: *** [Makefile:136: all] Error 2

```



--从openwrt的源码里面把libelf库复制到/usr/lib下面，并且ln -s libelf.so.* libelf.so，建立软链接。

--移除VPP源代码的部分plugin:

```
mv src/plugins/tlsopenssl/ ../
mv src/plugins/wireguard/ ../
```



VPP的配置命令:

```
root@OpenWrt:/mnt/vpp/src/build# cmake -DCMAKE_INSTALL_PREFIX=`pwd`/vpp-build ..
-- The C compiler identification is GNU 11.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test compiler_flag_march_haswell
-- Performing Test compiler_flag_march_haswell - Success
-- Performing Test compiler_flag_mtune_haswell
-- Performing Test compiler_flag_mtune_haswell - Success
-- Performing Test compiler_flag_march_tremont
-- Performing Test compiler_flag_march_tremont - Success
-- Performing Test compiler_flag_mtune_tremont
-- Performing Test compiler_flag_mtune_tremont - Success
-- Performing Test compiler_flag_march_skylake_avx512
-- Performing Test compiler_flag_march_skylake_avx512 - Success
-- Performing Test compiler_flag_mtune_skylake_avx512
-- Performing Test compiler_flag_mtune_skylake_avx512 - Success
-- Performing Test compiler_flag_mprefer_vector_width_256
-- Performing Test compiler_flag_mprefer_vector_width_256 - Success
-- Performing Test compiler_flag_march_icelake_client
-- Performing Test compiler_flag_march_icelake_client - Success
-- Performing Test compiler_flag_mtune_icelake_client
-- Performing Test compiler_flag_mtune_icelake_client - Success
-- Performing Test compiler_flag_mprefer_vector_width_512
-- Performing Test compiler_flag_mprefer_vector_width_512 - Success
-- Looking for ccache
-- Looking for ccache - found
-- Performing Test compiler_flag_no_address_of_packed_member
-- Performing Test compiler_flag_no_address_of_packed_member - Success
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE  
-- Performing Test HAVE_FCNTL64
-- Performing Test HAVE_FCNTL64 - Success
-- Found OpenSSL: /usr/lib/libcrypto.so (found version "2.0.0")  
-- The ASM compiler identification is GNU
-- Found assembler: /usr/bin/gcc
-- Looking for libuuid
-- -- libuuid not found - vmbus support disabled
-- subunit library not found - vapi tests disabled
-- Found Python3: /usr/bin/python3.10 (found version "3.10.7") found components: Interpreter 
-- af_xdp plugin needs libbpf.a library - found at /usr/lib/libbpf.a
-- af_xdp plugin needs elf library - found at /usr/lib/libelf.so
-- af_xdp plugin needs z library - found at /usr/lib/libz.so
-- Performing Test BPF_COMPILES_CHECK
-- Performing Test BPF_COMPILES_CHECK - Success
-- Intel IPSecMB not found
-- dpdk plugin needs libdpdk.a library - found at /lib/libdpdk.a
-- Found DPDK 22.7.0 in /usr/include
-- dpdk plugin needs numa library - found at /usr/lib/libnuma.so
-- -- libnl3 headers not found - linux-cp plugin disabled
-- -- quicly headers not found - QUIC plugin disabled
-- -- rdma headers not found - rdma plugin disabled
-- -- libdaq headers not found - snort3 DAQ disabled
-- -- libsrtp2.a library not found - srtp plugin disabled
-- -- mbedtls headers not found - tlsmbedtls plugin disabled
-- Looking for SSL_set_async_callback
-- Looking for SSL_set_async_callback - not found
-- -- picotls not found - tlspicotls plugin disabled
-- Configuration:
VPP version         : 22.10-release
VPP library version : 22.10
GIT toplevel dir    : /mnt/vpp
Build type          : 
C compiler          : /usr/bin/gcc (GNU 11.2.0)
C flags             : 
Linker flags (apps) : 
Linker flags (libs) : 
Host processor      : x86_64
Target processor    : x86_64
Prefix path         : 
Install prefix      : /mnt/vpp/src/build/vpp-build
Library dir         : lib64
Multiarch variants  : hsw skx icl
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/vpp/src/build
```

然后执行：

```
make install
```



#### 5. 运行VPP

[可选]先设置内存大小及大页挂载：

```
echo 1024 > /sys/kernel/mm/hugepages/hugepages-2048kB/nr_hugepages
mkdir /mnt/huge
mount -t hugetlbfs nodev /mnt/huge
```

运行正确：

```
root@OpenWrt:/mnt/vpp/src/build/vpp-build/bin#./vpp -c /etc/startup.conf
unix_config:472: couldn't open log '/var/log/vpp/vpp.log'
vpp[101891]: perfmon: skipping source 'intel-uncore' - intel_uncore_init: failed to discover numa topology
vpp[101891]: pci: Skipping PCI device 0000:02:01.0 as host interface eth0 is up
vpp[101891]: pci: Skipping PCI device 0000:02:04.0 as host interface eth1 is up
vpp# show int
              Name               Idx    State  MTU (L3/IP4/IP6/MPLS)     Counter          Count     
GigabitEthernet2/5/0              1     down         9000/0/0/0     
local0                            0     down          0/0/0/0       
vpp# set interface state GigabitEthernet2/5/0 up
vpp# show interface 
              Name               Idx    State  MTU (L3/IP4/IP6/MPLS)     Counter          Count     
GigabitEthernet2/5/0              1      up          9000/0/0/0     
local0                            0     down          0/0/0/0       
vpp# 
```

