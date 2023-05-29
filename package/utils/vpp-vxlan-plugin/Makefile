include $(TOPDIR)/rules.mk

PKG_NAME:=vpp-vxlan-plugin
PKG_VERSION:=1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/vpp-vxlan-plugin
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=vpp vxlan plugin for openwrt
  DEPENDS:=+libsysrepo +libyang
endef

CMAKE_OPTIONS += \
	-DCMAKE_INSTALL_PREFIX=/usr \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)/yang
	cp -r ./src/* $(PKG_BUILD_DIR)/
	cp ./yang/* $(PKG_BUILD_DIR)/yang
endef

define Package/vpp-vxlan-plugin/install
    	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/vpp-vxlan-plugin $(1)/usr/bin/
        
	$(INSTALL_DIR) $(1)/etc/sysrepo/yang
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/yang/vpp-vxlan.yang $(1)/etc/sysrepo/yang/vpp-vxlan.yang
endef

$(eval $(call BuildPackage,vpp-vxlan-plugin))


