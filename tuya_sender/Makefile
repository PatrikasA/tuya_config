include $(TOPDIR)/rules.mk

PKG_NAME:=tuya_sender
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/tuya_sender
	DEPENDS:=
	CATEGORY:=Base system
	TITLE:=tuya_sender
endef


define Package/tuya_sender/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tuya_sender $(1)/usr/bin
endef

$(eval $(call BuildPackage,tuya_sender))
