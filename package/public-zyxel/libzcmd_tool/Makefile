# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# $Id$
	
include $(TOPDIR)/rules.mk

#These lines concatanate the package name and list the URL location from which the package source code is to be downloaded
PKG_NAME:=libzcmd_tool
PKG_VERSION:=2.0
PKG_RELEASE:=1

PKG_NAME_VER  := $(PKG_NAME)-$(PKG_VERSION)

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=http://www.cs.uh.edu/~vivekian/downloads/

#PKG_SOURCE_URL:=@ZyXEL_SITE/public/ZyXEL
DL_DIR:=$(TOPDIR)/dl/public/zyxel

PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

export CONFIG_ZYXEL_MEMORY_LEAK_DETECT

#These lines describe what your package does and its place in the menu config

PKG_BUILD_DEPENDS:=zcfg

ifeq ($(CONFIG_ZYXEL_OPENWRT_14),y)
LIBJSON=libjson
else
LIBJSON=libjson-c
endif


define Package/libzcmd_tool
	SECTION:=net
	CATEGORY:=Zyxel Packages
	TITLE:= ZyXEL Configuration Management Daemon Tool
	DESCRIPTION:=
	####DEPENDS:=+zcfg
	###DEPENDS:=+zcfg +libjson
	##DEPENDS:=zcfg +libjson
	#DEPENDS:=zcfg
	DEPENDS:=+libzos +$(LIBJSON)
endef

define Package/libzcmd_tool/config
	select PACKAGE_$(LIBJSON) if PACKAGE_zcfg
	select PACKAGE_libzos if PACKAGE_zcfg
endef

#Disable Dependencies Check
define CheckDependencies
endef

#For the compile rules you need to specify the cross compiler which needs to be used :


#These lines describe where your binary images are to be installed �V its the equivalent to make install

# This particular package is a library and the installation rules reflect it

define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	$$(call link_files,$(PKG_NAME_VER),$(BUILD_DIR))
endef

define Package/libzcmd_tool/compile
	$(MAKE) -C $(PKG_BUILD_DIR)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_BUILD_DIR)/*.h $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libzcmd_tool.so $(1)/usr/lib/
endef

define Package/libzcmd_tool/install
	$(INSTALL_DIR) $(1)/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME).so $(1)/lib
#	$(INSTALL_DIR) $(1)/lib/public
#	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libzcmd_tool.so $(1)/lib/public
#	ln -s /lib/public/libzcmd_tool.so $(1)/lib/libzcmd_tool.so
endef

$(eval $(call BuildPackage,libzcmd_tool))

