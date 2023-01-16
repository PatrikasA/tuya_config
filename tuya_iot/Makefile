include $(TOPDIR)/rules.mk

PKG_NAME:=tuya_iot
PKG_RELEASE:=1
PKG_VERSION:=1.0.0
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/tuya/tuya-iot-core-sdk.git
PKG_SOURCE_VERSION:=1ba26efe673d93da8b1e649b875f185ce0cbe09c	

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/tuya_iot
	DEPENDS:=
	CATEGORY:=Base system
	TITLE:=tuya_iot
endef

define Package/tuya_iot/install
	$(INSTALL_DIR) $(1)/usr/lib/include
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/*.a $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/subdevice_basic_demo $(1)/usr/bin
endef

$(eval $(call BuildPackage,tuya_iot))
