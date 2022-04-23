### OpenWrt Host Compile



#### 1. 编译前准备

本次编译OpenWrt-21.02的宿主机为Ubuntu20.04。在编译之前需要安装如下工具：

```
sudo apt-get install vim bison gcc g++ gawk meson git make autoconf tree libncurses5-dev qemu-utils
```

#### 

#### 2. 编译

```
./script/feeds/update -a
./script/feeds/install -a

#加载配置文件，配置文件在openwrt-configs里面
make menuconfig

#编译
make V=s -j4
```



#### 3. 生成

在bin/targets/x86/64-glibc可以看到我们编译生成的：

```
$ ls
config.buildinfo           openwrt-x86-64-generic-squashfs-combined-efi.vmdk
feeds.buildinfo            openwrt-x86-64-generic-squashfs-combined.img.gz
openwrt-sdk-x86-64_gcc-8.4.0_glibc.Linux-x86_64.tar.xz  
openwrt-x86-64-generic-squashfs-combined.vmdk
openwrt-x86-64-generic-kernel.bin   openwrt-x86-64-generic-squashfs-rootfs.img.gz
openwrt-x86-64-generic.manifest                         packages
openwrt-x86-64-generic-rootfs.tar.gz                    sha256sums
openwrt-x86-64-generic-squashfs-combined-efi.img.gz     version.buildinfo
```

