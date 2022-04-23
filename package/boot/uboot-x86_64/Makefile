#
# Copyright (C) 2022 Ji Li <liji6630@foxmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME=u-boot
PKG_VERSION:=2020.07-rc5
PKG_RELEASE:=1

PKG_HASH:=9b2864a74d9848e90dbfa1833c185866e81293860ba6cab7ca88daaee85581fe

include $(INCLUDE_DIR)/u-boot.mk
include $(INCLUDE_DIR)/package.mk

define U-Boot/Default
  BUILD_TARGET:=x86
  BUILD_SUBTARGET:=64
  BUILD_DEVICES:=$(1)
  UBOOT_IMAGE:=u-boot-payload.efi
endef

define U-Boot/intel-x86_64
  NAME:=INTEL x86_64 Boot 
  BUILD_SUBTARGET:=64
  UBOOT_CONFIG:=efi-x86_payload64
  UBOOT_IMAGE:=u-boot-payload.efi

endef

UBOOT_TARGETS := \
	intel-x86_64

STARTUP_TARGET_LOCATION := $(PKG_BUILD_DIR)/startup.nsh
export STARTUP_TARGET_LOCATION

UBOOT_MAKE_FLAGS += $(UBOOT_IMAGE)

Build/Exports:=$(Host/Exports)
define Build/InstallDev
	$(INSTALL_DIR) $(STAGING_DIR_IMAGE)
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(UBOOT_IMAGE) $(STAGING_DIR_IMAGE)/$(BUILD_VARIANT)-$(UBOOT_IMAGE)
endef

$(eval $(call BuildPackage/U-Boot)) 