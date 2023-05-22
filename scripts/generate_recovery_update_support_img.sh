#!/bin/bash

ROOT_PATH=`pwd`

#backup efi file
mkdir -p "${ROOT_PATH}"/.os_temp/efi_folder/
sudo mount -o loop,offset=262144 "${ROOT_PATH}"/bin/targets/x86/64-glibc/openwrt-x86-64-generic-ext4-combined-efi.img .os_temp/efi_folder/
sudo tar zcvf "${ROOT_PATH}"/.os_temp/efi.tar.gz "${ROOT_PATH}"/.os_temp/efi_folder/*
sudo umount "${ROOT_PATH}"/.os_temp/efi_folder/

#change efi part fat->ext4
mount_point=`losetup -f`
sudo losetup -o $((512*512)) "${mount_point}" "${ROOT_PATH}"/bin/targets/x86/64-glibc/openwrt-x86-64-generic-ext4-combined-efi.img
echo -e "y" | sudo mkfs.ext4 "${mount_point}"
sudo losetup -d "${mount_point}"

#filter with new file
sudo mount -o loop,offset=262144 "${ROOT_PATH}"/bin/targets/x86/64-glibc/openwrt-x86-64-generic-ext4-combined-efi.img "${ROOT_PATH}"/.os_temp/efi_folder/
sudo tar zxvf "${ROOT_PATH}"/.os_temp/efi.tar.gz -C "${ROOT_PATH}"/.os_temp/efi_folder/ > /dev/null
sudo tar zxvf "${ROOT_PATH}"/tinyos/ramdisk-x86.tar.gz -C "${ROOT_PATH}"/.os_temp/efi_folder/ > /dev/null
sudo umount "${ROOT_PATH}"/.os_temp/efi_folder/

rm -rf "${ROOT_PATH}"/.os_temp/
echo "Now you have a img which support update or recovery when boot from slimbootloader with grub..."
