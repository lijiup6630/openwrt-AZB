用于启动ramdisk及内核相关的组件，已集成到OpenWrt中。

启动menu如下所示：

```
menuentry "@TITLE@" {
	linux /boot/vmlinuz @GPT_ROOTPART@ @CMDLINE@ noinitrd
}

menuentry "@TITLE@ (failsafe)" {
	linux /boot/vmlinuz failsafe=true @GPT_ROOTPART@ @CMDLINE@ noinitrd
}

menuentry "@TITLE@ (ramdisk)" {
	linux /boot/vmlinuz-initramfs @GPT_ROOTPART@ @CMDLINE@ 
}
```



所以当系统挂掉后可以选择ramdisk模式进入，此时系统都会加载到内存中去。在ramdisk操作重新往存储介质中写入系统。



ramdisk验证如下,选择ramdisk进入，然后查看根文件系统挂载路径：

```
root@OpenWrt:/# cat /proc/mounts 
tmpfs / tmpfs rw,relatime 0 0
proc /proc proc rw,nosuid,nodev,noexec,noatime 0 0
sysfs /sys sysfs rw,nosuid,nodev,noexec,noatime 0 0
cgroup2 /sys/fs/cgroup cgroup2 rw,nosuid,nodev,noexec,relatime,nsdelegate 0 0
tmpfs /tmp tmpfs rw,nosuid,nodev,noatime 0 0
tmpfs /dev tmpfs rw,nosuid,noexec,noatime,size=512k,mode=755 0 0
devpts /dev/pts devpts rw,nosuid,noexec,noatime,mode=600,ptmxmode=000 0 0
debugfs /sys/kernel/debug debugfs rw,noatime 0 0
none /sys/fs/bpf bpf rw,nosuid,nodev,noexec,noatime,mode=700 0 0
```



