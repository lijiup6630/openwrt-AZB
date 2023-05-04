include $(TOPDIR)/rules.mk

PKG_NAME:=libsrpo
PKG_VERSION:=1.0.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/sartura/srpo.git
PKG_SOURCE_VERSION:=c7531f98b5d444cb9f7bb95be04453df2f6fef87
PKG_HASH:=skip

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libsrpo
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=libsrpo
  DEPENDS:=+libyang +libuci +libubox +libubus +libsysrepo +libblobmsg-json
endef


define Package/libsrpo/description
Sysrepo plugin Openwrt library for wrapping UCI and UBUS data operations.
endef


CMAKE_OPTIONS += \
	-DUCI_CONFIG_DIR="/etc/config"
	-DCMAKE_INSTALL_PREFIX=/usr

define Package/libsrpo/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libsrpo.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libsrpo))

