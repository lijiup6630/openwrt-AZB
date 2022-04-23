### OpenWrt Compile Test DPDK



#### 1. OpenWrt交叉编译环境

首先我们需要将OpenWrt的交叉编译环境准备好，主要是使用OpenWrt SDK工具:

```
openwrt-crosscompile$ cp ../openwrt/bin/targets/x86/64-glibc/openwrt-sdk-x86-64_gcc-8.4.0_glibc.Linux-x86_64.tar.xz ./
openwrt-crosscompile$ xz -d openwrt-sdk-x86-64_gcc-8.4.0_glibc.Linux-x86_64.tar.xz
openwrt-crosscompile$ tar xvf openwrt-sdk-x86-64_gcc-8.4.0_glibc.Linux-x86_64.tar
#设置环境变量,按照你的实际路径设置
export PATH=<OpenWrt SDK>/glibc/openwrt-sdk-x86-64_gcc-8.3.0_glibc.Linux-x86_64/staging_dir/toolchain-x86_64_gcc-8.3.0_glibc/bin/:$PATH
#设置STAGING_DIR
export STAGING_DIR=<Your OpenWrt staging direction>
```



#### 2. 编译安装numactl

```
sudo apt-get install libtool
git clone https://github.com/numactl/numactl.git
cd numactl
git checkout v2.0.13 -b v2.0.13
./autogen.sh
autoconf -i
# 注意这里安装的路径是SDK toolchain
./configure CC=x86_64-openwrt-linux-gnu-gcc --prefix=<OpenWrt SDK toolchain dir>
make install
```

#### 3. 编译dpdk

首先安装必须的工具:

```
sudo apt install python3-pip
sudo pip3 install pyelftools
```

我们编译的dpdk版本为21.08.

```
git clone https://github.com/DPDK/dpdk.git -b v21.08
```

目录中生成编译配置文件openwrt-cross，其内容为:

```
[binaries]
c = 'x86_64-openwrt-linux-gcc'
cpp = 'x86_64-openwrt-linux-cpp'
ar = 'x86_64-openwrt-linux-ar'
strip = 'x86_64-openwrt-linux-strip'

[host_machine]
system = 'linux'
cpu_family = 'x86_64'
cpu = 'native'
endian = 'little'
```

然后在目录下执行命令:

```
dpdk-vpp$ meson openwrt-build-gcc cross-file openwrt-cross
dpdk-vpp$ ninja -C openwrt-build-gcc
[2685/2685] Linking target app/dpdk-test-regex.
```

OK，这样就把DPDK按照默认的配置编译了出来。

暂未发现编译dpdk example的方法，以后继续研究。



#### 4. 测试DPDK

