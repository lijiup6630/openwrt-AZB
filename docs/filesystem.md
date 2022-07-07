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

#### 3. 测试在SSD上的支持

##### (1) ext4

```
root@OpenWrt:/# mkfs.ext4 /dev/nvme0n1p3 
mke2fs 1.46.5 (30-Dec-2021)
/dev/nvme0n1p3 contains a LVM2_member file system
Proceed anyway? (y,N) y
Discarding device blocks: done                            
Creating filesystem with 249657344 4k blocks and 62414848 inodes
Filesystem UUID: 3095e49e-2002-4d8c-a7f7-a182240776a3
Superblock backups stored on blocks: 
        32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
        4096000, 7962624, 11239424, 20480000, 23887872, 71663616, 78675968, 
        102400000, 214990848

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (262144 blocks): done
Writing superblocks and filesystem accounting information: done     

root@OpenWrt:/# mount -t ext4 /dev/nvme0n1p3 /mnt/
[ 1188.580176] EXT4-fs (nvme0n1p3): mounted filesystem with ordered data mode. Opts: (null)
root@OpenWrt:/# touch /mnt/a.c
root@OpenWrt:/# ls /mnt/
a.c         lost+found
```

##### (2) vFAT

```
root@OpenWrt:/# mkfs.fat /dev/nvme0n1p3 
mkfs.fat 4.2 (2021-01-31)
Cannot initialize conversion from codepage 850 to ANSI_X3.4-1968: Success
Cannot initialize conversion from ANSI_X3.4-1968 to codepage 850: Success
Using internal CP850 conversion table
root@OpenWrt:/# mount -t vfat /dev/nvme0n1p3 /mnt/
root@OpenWrt:/# touch /mnt/a.c
root@OpenWrt:/# ls /mnt
a.c
```

