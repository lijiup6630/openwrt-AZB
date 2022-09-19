#
# Openwrt Makefile for Wireless tools
#
# Simplify mode 1.0
#
#

#### Includes ###################################
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=iwlwav-tools
PKG_REV:=HEAD
PKG_VERSION:=6.1.0
PKG_RELEASE:=1
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=$(TOPDIR)/wav600/iwlwav-tools
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_PROTO:=git

PKG_VARIANT_SUFFIX=
ifeq ($(BUILD_VARIANT),debug)
  PKG_VARIANT_SUFFIX=-debug
endif

PKG_BUILD_DEPENDS:=libnl safec3 dwpal_6x-uci$(PKG_VARIANT_SUFFIX)
PKG_BUILD_DIR:=$(BUILD_DIR)/iwlwav-tools-$(BUILD_VARIANT)/iwlwav-tools-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
#include $(INCLUDE_DIR)/package-version-override.mk

define Package/iwlwav-tools
  SECTION:=net
  CATEGORY:=Network
  TITLE:=wave SW toolset
  URL:=http://www.intel.com/
  DEPENDS:=+libnl +libsafec3 +dwpal_6x-uci
  MENU:=1
  VARIANT:=release
endef

define Package/iwlwav-tools/description
  Intel toolset for wave HW
endef

define Package/$(PKG_NAME)-debug
$(call Package/$(PKG_NAME))
TITLE += with debug information
VARIANT:=debug
DEPENDS:=+libnl +libsafec3 +dwpal_6x-uci-debug
endef

define Package/$(PKG_NAME)-debug/description
$(call Package/$(PKG_NAME)/description) with debug information
endef

OUTPUT_DEST=opt/intel/bin/
UBIN_FOLDER=opt/intel/usr/bin/

CROSS_COMPILE=$(if $(CONFIG_EXTERNAL_TOOLCHAIN),$(CONFIG_TOOLCHAIN_ROOT)/bin/$(CONFIG_TOOLCHAIN_PREFIX)gcc,$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)gcc) # fix for non external toolchain!
CROSS_AR=$(if $(CONFIG_EXTERNAL_TOOLCHAIN),$(CONFIG_TOOLCHAIN_ROOT)/bin/$(CONFIG_TOOLCHAIN_PREFIX)ar,$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ar) # fix for non external toolchain!
CROSS_RANLIB=$(if $(CONFIG_EXTERNAL_TOOLCHAIN),$(CONFIG_TOOLCHAIN_ROOT)/bin/$(CONFIG_TOOLCHAIN_PREFIX)ranlib,$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ranlib) # fix for non external toolchain!
CROSS_LD=$(if $(CONFIG_EXTERNAL_TOOLCHAIN),$(CONFIG_TOOLCHAIN_ROOT)/bin/$(CONFIG_TOOLCHAIN_PREFIX)ld,$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ld) # fix for non external toolchain!

LIBNL_DIR:=$(wildcard $(STAGING_DIR)/usr/include/libnl3)

USR_INC_DIR:=$(wildcard $(STAGING_DIR)/usr/include)
TARGET_CFLAGS += -I$(USR_INC_DIR) -I$(LIBNL_DIR) -DHAVE_C99=1
LDFLAGS += -L$(TOOLCHAIN_DIR)/lib -L$(STAGING_DIR)/usr/lib -lnl-genl-3 -lnl-3 -pthread -lpthread -lsafec-3.4
CFLAGS += -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -Wall -fPIC -Wl,-strip-debug
LDFLAGS += -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro

ifeq ($(BUILD_VARIANT),debug)
TARGET_CFLAGS += -DCONFIG_WAVE_DEBUG
endif


define Build/Compile
	@echo LDFLAGS: "$(LDFLAGS)"
	$(MAKE) -C $(PKG_BUILD_DIR) clean
	$(MAKE) CC=$(CROSS_COMPILE) AR=$(CROSS_AR) RANLIB=$(CROSS_RANLIB) LD=$(CROSS_LD) -C $(PKG_BUILD_DIR) CFLAGS="$(TARGET_CFLAGS)" LDFLAGS="$(LDFLAGS)" $(BUILD_VARIANT)
endef

define Package/iwlwav-tools/install
	$(INSTALL_DIR) -p $(1)/$(OUTPUT_DEST)
	$(INSTALL_DIR) -p $(1)/$(UBIN_FOLDER)/
	$(INSTALL_DIR) -p $(1)/etc
	$(CP) $(PKG_BUILD_DIR)/tools/dutserver/linux/dutserver $(1)/$(OUTPUT_DEST)
	$(CP) $(PKG_BUILD_DIR)/tools/dump_handler/dump_handler $(1)/$(OUTPUT_DEST)
	$(CP) $(PKG_BUILD_DIR)/tools/whm_handler/whm_handler $(1)/$(OUTPUT_DEST)
	$(CP) $(PKG_BUILD_DIR)/tools/drvhlpr/drvhlpr $(1)/$(OUTPUT_DEST)
ifeq ($(BUILD_VARIANT),debug)
	$(CP) $(PKG_BUILD_DIR)/tools/rtlogger/logserver/linux/logserver $(1)/$(OUTPUT_DEST)
	$(CP) $(PKG_BUILD_DIR)/tools/BCLSockServer/BCLSockServer $(1)/$(OUTPUT_DEST)/BClSockServer
endif
	echo -e "iwlwav_tools_hash=\"$(PKG_REV)\"\niwlwav_tools_tag=\"$(PKG_REV)\"" > $(1)/etc/iwlwav_tools.ver
endef
Package/$(PKG_NAME)-debug/install = $(Package/iwlwav-tools/install)
$(eval $(call BuildPackage,iwlwav-tools))
$(eval $(call BuildPackage,iwlwav-tools-debug))
