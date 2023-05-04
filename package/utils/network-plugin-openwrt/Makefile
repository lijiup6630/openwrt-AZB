include $(TOPDIR)/rules.mk

PKG_NAME:=network-plugin-openwrt
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/sartura/network-plugin-openwrt.git
PKG_SOURCE_VERSION:=48f11662588830faf33b82e2cec30e91d7882f23
PKG_HASH:=skip

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/network-plugin-openwrt
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=network plugin for openwrt
  DEPENDS:=+libsysrepo +libyang +libubox +libubus +libsrpo +libsysrepo +libuci
endef

CMAKE_OPTIONS += \
	-DCMAKE_INSTALL_PREFIX=/usr \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON

define Package/network-plugin-openwrt/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/sysrepo-plugin-network $(1)/usr/bin/
        
	$(INSTALL_DIR) $(1)/etc/sysrepo/yang
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/yang/iana-if-type@2014-05-08.yang $(1)/etc/sysrepo/yang/iana-if-type.yang
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/yang/ietf-interfaces@2014-05-08.yang $(1)/etc/sysrepo/yang/ietf-interfaces.yang
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/yang/ietf-ip@2014-06-16.yang $(1)/etc/sysrepo/yang/ietf-ip.yang
endef

$(eval $(call BuildPackage,network-plugin-openwrt))
