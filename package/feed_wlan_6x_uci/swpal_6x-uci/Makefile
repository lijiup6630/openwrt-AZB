#
# Openwrt Makefile for swpal_6x-uci
#
#

#### Includes ###################################
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

#### Package Info ############################### 
PKG_NAME:=swpal_6x-uci
PKG_REV:=HEAD
PKG_VERSION:=1.0.0.1
PKG_RELEASE:=$(PKG_REV)
PKG_BASE_NAME:=$(PKG_NAME)
PKG_SOURCE:=$(PKG_BASE_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=$(TOPDIR)/wav600/swpal_6x-uci
PKG_SOURCE_SUBDIR:=$(PKG_BASE_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_PROTO:=git
#PKG_MIRROR_HASH:=e847f541a9a6aac59276623bdc7011a0
#PKG_MD5SUM:=40b89c61036add0c2dd1fc10767d3b5f

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_BASE_NAME)-$(PKG_VERSION)
PKG_DEFAULT_CUSTOM_SOURCE_DIR:=$(shell pwd)

PKG_BUILD_DEPENDS:= uci safec3

include $(INCLUDE_DIR)/package.mk
#include $(INCLUDE_DIR)/package-version-override.mk
## don't remove '-' in the next line - this is part of the Makefile syntax ##
#-include $(STAGING_DIR)/mk/ugw-loglevel.mk

define Package/$(PKG_NAME)
  SECTION:=utils
  CATEGORY:=Intel
  SUBMENU:=Static WLAN Platform abstraction layer - SWPAL
  TITLE:=Intel SWPAL
  URL:=http://www.intel.com
  MAINTAINER:=Intel Corporation
  DEPENDS:= +uci +libsafec3
  MENU:=1
  VARIANT:=release
  PROVIDES:=libspal
endef

define Package/$(PKG_NAME)/description
	Intel SWPAL for WLAN Support
endef

define Package/$(PKG_NAME)-debug
$(call Package/$(PKG_NAME))
  DEPENDS+= +$(PKG_NAME)
  TITLE:=Intel SWPAL DEBUG
  VARIANT:=debug
endef

define Package/$(PKG_NAME)-debug/description
	Intel SWPAL for WLAN DEBUG Support
endef


### Menuconfig ##################################
define Package/$(PKG_NAME)/config
$(call Package/$(PKG_NAME)/override_version)
$(call Package/$(PKG_NAME)/override_source_path)
$(call Package/$(PKG_NAME)/config_debug_level)
endef

define Package/$(PKG_NAME)-debug/config
$(call Package/$(PKG_NAME)-debug/override_version)
$(call Package/$(PKG_NAME)-debug/override_source_path)
$(call Package/$(PKG_NAME)-debug/config_debug_level)
endef

ifeq ($(CONFIG_USE_MUSL),y)
  TARGET_CFLAGS += -DCONFIG_USE_MUSL
endif
  
TARGET_CFLAGS += -DCONFIG_RPCD -DHAVE_C99=1
IFX_LDFLAGS += -lsafec-3.4
IFX_CFLAGS += -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -Wall -fPIC -Wl,-strip-debug
IFX_LDFLAGS += -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro

ifeq ($(BUILD_VARIANT),debug)
TARGET_CFLAGS += -DCONFIG_WAVE_DEBUG
define Build/Compile
	$(TARGET_CC) ${TARGET_CFLAGS} ${TARGET_LDFLAGS} $(PKG_BUILD_DIR)/src/lite_nc/nc_lite.c $(PKG_BUILD_DIR)/src/lite_nc/nc_help_lite.c $(PKG_BUILD_DIR)/src/lite_nc/nc_help_lite.h -o $(PKG_BUILD_DIR)/src/lite_nc/lite_nc
	$(call Build/Compile/Default)
endef
endif

# To ipkg / Rootfs
define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/$(VENDOR_PATH)/usr/lib
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/hotplug.d/ieee80211
	$(INSTALL_DIR) $(1)/lib/config
	$(INSTALL_DIR) $(1)/lib/functions
	$(INSTALL_DIR) $(1)/lib/wifi
	$(INSTALL_DIR) $(1)/lib/netifd
	$(INSTALL_DIR) $(1)/lib/netifd/wireless
	$(INSTALL_DIR) $(1)/lib/config
	$(INSTALL_DIR) $(1)/opt/intel/wave/db
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/ugw
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/11n
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/he
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/he_testbed
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/mbo
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/vht
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/wpa2
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/wpa3
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/wps2
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/wps2/case_4_1_2
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/wps2/case_4_3_2
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/d2_pdxp
	$(INSTALL_DIR) $(1)/opt/intel/wave/db/d2_fpga
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_DIR) $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libspal.so $(1)/$(VENDOR_PATH)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/hotplug.d/ieee80211/mac80211.hotplug $(1)/etc/hotplug.d/ieee80211/10-wifi-detect
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libspal_utils.so $(1)/$(VENDOR_PATH)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/netifd-wireless.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/functions.sh $(1)/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/config/uci.sh $(1)/lib/config
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/functions/network.sh $(1)/lib/functions
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/hostapd.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/wireless/* $(1)/lib/netifd/wireless/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/sigma-ap.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/sigma-start.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/sigmaManagerDaemon.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/sigma_mbo_daemon.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/6ghz_rnr.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/update_rnr.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/update_rnr_uci.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/lgm_radio_map $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/sigmaManagerDaemon_static.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/terminate_radio_after.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/config/uci.sh $(1)/lib/config/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/wifi/mac80211.sh $(1)/lib/wifi/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/wifi/platform_dependent_ugw.sh $(1)/lib/wifi/platform_dependent.sh
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/sbin/wifi $(1)/sbin/

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/load_dut.sh $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/flash_file_saver.sh $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/wave_factory_reset.sh $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/common_utils.sh $(1)/opt/intel/wave/scripts/

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/meta-factory $(1)/opt/intel/wave/db/
	echo "		option prog 'ugw'" >> $(1)/opt/intel/wave/db/meta-factory
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/ugw/* $(1)/opt/intel/wave/db/ugw/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/11n/* $(1)/opt/intel/wave/db/11n
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/he/* $(1)/opt/intel/wave/db/he
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/he_testbed/* $(1)/opt/intel/wave/db/he_testbed
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/mbo/* $(1)/opt/intel/wave/db/mbo
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/vht/* $(1)/opt/intel/wave/db/vht
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/wpa2/* $(1)/opt/intel/wave/db/wpa2
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/wpa3/* $(1)/opt/intel/wave/db/wpa3
	$(CP) -r $(PKG_BUILD_DIR)/files/db/etc/wave/db/wps2/* $(1)/opt/intel/wave/db/wps2
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/d2_pdxp/* $(1)/opt/intel/wave/db/d2_pdxp
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/db/etc/wave/db/d2_fpga/* $(1)/opt/intel/wave/db/d2_fpga
	echo "		option checksum '`cat $(1)/opt/intel/wave/db/ugw/* | md5sum | cut -f1 -d ' '`'" >> $(1)/opt/intel/wave/db/meta-factory
	chmod +x $(1)/lib/wifi/mac80211.sh
	ln -s /opt/intel/wave/scripts/wave_factory_reset.sh $(1)/sbin/wavFactoryReset
	ln -s /opt/intel/wave/scripts/debug_toolbox.sh $(1)/sbin/wavToolBox
endef

define Package/$(PKG_NAME)-debug/install
	$(INSTALL_DIR) $(1)/$(VENDOR_PATH)/usr/lib
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/lib/wifi
	$(INSTALL_DIR) $(1)/lib/netifd
	$(INSTALL_DIR) $(1)/lib/netifd/wireless
	$(INSTALL_DIR) $(1)/lib/config
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_DIR) $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/lite_nc/lite_nc $(1)/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/debug_infrastructure.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/lib/netifd/debug_post_iw_up.sh $(1)/lib/netifd/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/debug_toolbox.sh $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/files/scripts/etc/wave/scripts/wave_collect_debug.sh $(1)/opt/intel/wave/scripts/
	ln -s /opt/intel/wave/scripts/debug_toolbox.sh $(1)/sbin/wavToolBox
	ln -s /opt/intel/wave/scripts/wave_factory_reset.sh $(1)/sbin/wavFactoryReset
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libspal.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libspal_utils.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/include/uci_wrapper.h $(1)/usr/include/
endef

define Build/Clean
	if [ -d $(PKG_BUILD_DIR) ]; then $(MAKE) -C $(PKG_BUILD_DIR) clean; \
	$(RM) -r $(PKG_BUILD_DIR)/ipkg-$(BOARD); fi
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
$(eval $(call BuildPackage,$(PKG_NAME)-debug))
