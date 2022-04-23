### Filesystem

测试OpenWrt对ext2,ext4,vfat和ntfs格式的支持情况。

#### 1. 建立映像和挂载点

```
root@OpenWrt:~# mkdir mount-temp
root@OpenWrt:~# dd if=/dev/zero of=a.img bs=1K count=1024
1024+0 records in
1024+0 records out
```

#### 2. 文件系统格式测试

##### (1) ext2

```
root@OpenWrt:~# mkfs.ext2 a.img 
mke2fs 1.46.5 (30-Dec-2021)
Discarding device blocks: done                            
Creating filesystem with 1024 1k blocks and 128 inodes

Allocating group tables: done                            
Writing inode tables: done                            
Writing superblocks and filesystem accounting information: done

root@OpenWrt:~# mount a.img mount-temp/
root@OpenWrt:~# ls
a.img       mount-temp  test
root@OpenWrt:~# echo test > mount-temp/test.txt
root@OpenWrt:~# ls mount-temp/
lost+found  test.txt
root@OpenWrt:~# umount mount-temp/
root@OpenWrt:~# ls mount-temp/
root@OpenWrt:~# 
```

##### (2) ext4

```
root@OpenWrt:~# mkfs.ext4 a.img 
mke2fs 1.46.5 (30-Dec-2021)
a.img contains a ext2 file system
	last mounted on /root/mount-temp on Sun Mar 20 15:33:31 2022
Proceed anyway? (y,N) y

Filesystem too small for a journal
Discarding device blocks: done                            
Creating filesystem with 1024 1k blocks and 128 inodes

Allocating group tables: done                            
Writing inode tables: done                            
Writing superblocks and filesystem accounting information: done

root@OpenWrt:~# mount a.img mount-temp/
root@OpenWrt:~# ls mount-temp/
lost+found
root@OpenWrt:~# echo test > mount-temp/test.txt
root@OpenWrt:~# ls mount-temp/
lost+found  test.txt
root@OpenWrt:~# umount mount-temp/
root@OpenWrt:~# ls mount-temp/
```

##### (3) vfat

```
root@OpenWrt:~# mkfs.vfat a.img 
root@OpenWrt:~# mount a.img mount-temp/
NTFS signature is missing.
Failed to mount '/dev/loop1': Invalid argument
The device '/dev/loop1' doesn't seem to have a valid NTFS.
Maybe the wrong device is used? Or the whole disk instead of a
partition (e.g. /dev/sda, not /dev/sda1)? Or the other way around?
root@OpenWrt:~# 
root@OpenWrt:~# umount mount-temp/
root@OpenWrt:~# 
root@OpenWrt:~# 
root@OpenWrt:~# mount -t vfat a.img mount-temp/
root@OpenWrt:~# echo test > mount-temp/test.txt
root@OpenWrt:~# ls mount-temp/
test.txt
root@OpenWrt:~# umount mount-temp/
root@OpenWrt:~# ls mount-temp/
root@OpenWrt:~# 
```

##### （4）ntfs

ntfs的测试通过外插U盘来测试。

```
root@OpenWrt:~# mount -t ntfs-3g /dev/sdb1 mount-temp/
The disk contains an unclean file system (0, 0).
The file system wasn't safely closed on Windows. Fixing.
root@OpenWrt:~# echo test > mount-temp/test.txt
root@OpenWrt:~# ls mount-temp/
test.txt
root@OpenWrt:~# umount mount-temp/
root@OpenWrt:~# ls mount-temp/
```

