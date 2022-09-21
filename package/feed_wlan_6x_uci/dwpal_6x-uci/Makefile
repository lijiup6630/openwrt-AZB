include $(TOPDIR)/rules.mk

PKG_NAME:=dwpal_6x-uci
PKG_REV:=2154caf4c9b23e0f037ea70e14bb563fa273df30
PKG_VERSION:=1.0.0.1
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=ssh://git@ilbitbucket.phoenix.local:29418/sw_wave/dwpal.git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_PROTO:=git
PKG_MIRROR_HASH:=0468312807d9c8d3d74b0952e6e82187
PKG_BUILD_DIR:=$(BUILD_DIR)/dwpal_6x-uci-$(BUILD_VARIANT)/dwpal_6x-uci-$(PKG_VERSION)

PKG_BUILD_DEPENDS:=libnl ncurses safec3 libedit iwlwav-hostap-uci iwlwav-iw uci

PKG_LICENSE:=BSD 3-clause
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/package-version-override.mk
define Package/dwpal_6x-uci
  SECTION:=net
  CATEGORY:=Intel
  SUBMENU:=UGW Software
  TITLE:=D-WPAL Library
  URL:=http://www.intel.com
  MAINTAINER:=Intel Corporation
  DEPENDS:= +libnl +librt +libsafec3 +libncurses +libedit +iwlwav-hostap-uci
  MENU:=1
  VARIANT:=release
  PROVIDES:=libdwpal
endef

define Package/dwpal_6x-uci/description
	D-WPAL: Dynamic Wireless Platform Abstraction Layer
endef

define Package/dwpal_6x-uci-debug
$(call Package/dwpal_6x-uci)
VARIANT:=debug
DEPENDS:= +libnl +librt +libsafec3 +libncurses +libedit +iwlwav-hostap-uci-debug
TITLE += with debug information
endef

define Package/dwpal_6x-uci-debug/description
$(call Package/dwpal_6x-uci/description) with debug information
endef
define Package/dwpal_6x-uci/config
$(call Package/dwpal_6x-uci/override_version)
$(call Package/dwpal_6x-uci/override_source_path)
endef

define Package/dwpal_6x-uci-debug/config
$(call Package/dwpal_6x-uci-debug/override_version)
$(call Package/dwpal_6x-uci-debug/override_source_path)
endef

LIBNL_DIR:=$(wildcard $(BUILD_DIR)/libnl-3*)

IWLWAV_HOSTAP_DIR:=$(wildcard $(BUILD_DIR)/iwlwav-hostap-uci-$(BUILD_VARIANT)/iwlwav-hostap-uci-*)
IWLWAV_IW_DIR:=$(wildcard $(BUILD_DIR)/iwlwav-iw-$(BUILD_VARIANT)/iwlwav-iw-*)

IFX_CFLAGS += -I$(IWLWAV_IW_DIR) -I$(IWLWAV_HOSTAP_DIR)/src/common/ -I$(IWLWAV_HOSTAP_DIR)/src/utils/ -I$(LIBNL_DIR)/include -DHAVE_C99=1
IFX_LDFLAGS += -L$(STAGING_DIR)/usr/lib -L$(LIBNL_DIR)/lib/.libs -lnl-3 -lsafec-3.3
IFX_CFLAGS += -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -Wall -fPIC -Wl,-strip-debug
IFX_LDFLAGS += -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro
ifeq ($(BUILD_VARIANT),debug)
IFX_CFLAGS += -DCONFIG_WAVE_DEBUG
endif

define Build/Compile
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(PKG_BUILD_DIR) \
		CFLAGS="$(IFX_CFLAGS)" LDFLAGS="$(IFX_LDFLAGS)" IWLWAV_HOSTAP_DIR="$(IWLWAV_HOSTAP_DIR)" IWLWAV_IW_DIR="$(IWLWAV_IW_DIR)"
endef

define Package/dwpal_6x-uci/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/opt/intel/wave/scripts/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libdwpal.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dwpal_cli $(1)/usr/sbin
	chmod 555 $(1)/usr/sbin/dwpal_cli
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libwv_core.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libdwpald_client.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dwpal_daemon $(1)/usr/sbin
	chmod 555 $(1)/usr/sbin/dwpal_daemon

ifeq ($(BUILD_VARIANT),debug)
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dwpald_client_ref $(1)/usr/sbin
	chmod 555 $(1)/usr/sbin/dwpald_client_ref

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/test_lib_wv_ipc $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/test_dwpal $(1)/usr/sbin
	chmod 555 $(1)/usr/sbin/test_lib_wv_ipc
	chmod 555 $(1)/usr/sbin/test_dwpal
endif

endef

Package/dwpal_6x-uci-debug/install = $(Package/dwpal_6x-uci/install)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libdwpal.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libwv_core.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libdwpald_client.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/include/*.h $(1)/usr/include/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/daemon/dwpald_client.h $(1)/usr/include/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/daemon/dwpald_hostap_parse.h $(1)/usr/include/
	#$(INSTALL_BIN) $(PKG_BUILD_DIR)/*.h $(1)/usr/include/
endef

$(eval $(call BuildPackage,dwpal_6x-uci))
$(eval $(call BuildPackage,dwpal_6x-uci-debug))
