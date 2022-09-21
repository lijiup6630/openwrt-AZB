#
# Openwrt Makefile for iw
#
# Simplify mode 1.0
#
#

#### Includes ###################################
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=iwlwav-iw
PKG_REV:=3fb98816deb2b186ea4aad94ad845aacdbd6ba6a
PKG_VERSION:=4.14
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=ssh://git@ilbitbucket.phoenix.local:29418/sw_wave/iwlwav-iw.git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_PROTO:=git
PKG_MIRROR_HASH:=3a164ffb7381f7da0bf8019e63daf16e
PKG_BUILD_DIR:=$(BUILD_DIR)/iwlwav-iw-$(BUILD_VARIANT)/iwlwav-iw-$(PKG_VERSION)
PKG_BUILD_DEPENDS:=libnl safec3 PACKAGE_iw:iw

PKG_LICENSE:=ISC
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk

define Package/iwlwav-iw
  SECTION:=net
  CATEGORY:=Network
  TITLE:=iw for Wave
  DEPENDS:=+libnl +libsafec3
  MENU:=1
  VARIANT:=release
endef

define Package/iwlwav-iw/description
  iw for Wave
endef

define Package/iwlwav-iw-debug
$(call Package/iwlwav-iw)
VARIANT:=debug
TITLE += with debug information
endef

define Package/iwlwav-iw-debug/description
$(call Package/iwlwav-iw/description) with debug information
endef

LIBNL_DIR:=$(wildcard $(BUILD_DIR)/libnl-3*)
USR_INC_DIR:=$(wildcard $(STAGING_DIR)/usr/include)

IFX_CFLAGS += -I$(USR_INC_DIR) -I$(LIBNL_DIR)/include -DHAVE_C99=1
IFX_LDFLAGS += -L$(STAGING_DIR)/usr/lib -L$(LIBNL_DIR)/lib/.libs -lnl-3 -lsafec-3.3
IFX_CFLAGS += -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -Wall -fPIC -Wl,-strip-debug
IFX_LDFLAGS += -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro
ifeq ($(BUILD_VARIANT),debug)
IFX_CFLAGS += -DCONFIG_WAVE_DEBUG
endif

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) clean
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(PKG_BUILD_DIR) \
		IFX_CFLAGS="$(IFX_CFLAGS)" IFX_LDFLAGS="$(IFX_LDFLAGS)"
endef

define Package/iwlwav-iw/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_DIR) -p $(1)/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/iw $(1)/usr/sbin/
	echo -e "iwlwav_iw_hash=\"$(PKG_REV)\"\niwlwav_iw_tag=\"$(PKG_REV)\"" > $(1)/etc/iwlwav_iw.ver
endef
Package/iwlwav-iw-debug/install = $(Package/iwlwav-iw/install)

$(eval $(call BuildPackage,iwlwav-iw))
$(eval $(call BuildPackage,iwlwav-iw-debug))
