include $(TOPDIR)/rules.mk

PKG_NAME:=tuya_iot
PKG_RELEASE:=1
PKG_VERSION:=1.0.0
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/tuya/tuya-iot-core-sdk
PKG_SOURCE_VERSION:=1ba26efe673d93da8b1e649b875f185ce0cbe09c
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/tuya_iot
	DEPENDS:=
	CATEGORY:=Base system
	TITLE:=tuya_iot
endef


define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/include
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/*.h $(1)/usr/include
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/*.h $(1)/usr/include
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/lib/*.a $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/*.h $(1)/usr/include
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/examples/subdevice_basic_demo/tuya_cacert.h $(1)/usr/include
endef

define Package/tuya_iot/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/*.a $(1)/usr/lib
endef

$(eval $(call BuildPackage,tuya_iot))
