#
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=json-c
#PKG_VERSION:=0.13.1
PKG_VERSION:=$(call qstrip,$(CONFIG_LIBJSON_VERSION))
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=http://oss.metaparadigm.com/json-c/
PKG_SOURCE_URL:=@ZyXEL_SITE/opensource/libs

PATCH_DIR:=patches-$(PKG_VERSION)

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=COPYING

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_MAINTAINER:=Felix Fietkau <nbd@openwrt.org>

BCM_SDK_VER_CHK := $(findstring $(CONFIG_BRCM_SDK_VERSION),"416L05" "416L02A")

define Package/libjson/config
	source "$(SOURCE)/Config.in"
endef

include $(INCLUDE_DIR)/package.mk
TARGET_CFLAGS += $(FPIC)
#TARGET_CFLAGS += $(FPIC) -Wno-error=unused-but-set-variable

ifeq ($(CONFIG_ZYXEL_MEMORY_LEAK_DETECT),y)
TARGET_CFLAGS += -DZCFG_MEMORY_LEAK_DETECT
endif

ifeq ($(strip $(CONFIG_LIBJSON_VERSION)),"0.13.1")
ifeq ($(strip $(CONFIG_LIBC)),"uClibc")
CONFIGURE_ARGS += \
        ac_cv_func_uselocale=no
endif

ifeq ($(strip $(CONFIG_TOOLCHAIN_LIBC)),"uclibc")
CONFIGURE_ARGS += \
        ac_cv_func_uselocale=no
endif

ifeq ($(strip $(CONFIG_LIBC)),"glibc")
CONFIGURE_ARGS += \
        ac_cv_func_uselocale=yes
endif

ifeq ("$(strip ${ZCFG_PLATFORM})","BROADCOM")
ifneq ($(BCM_SDK_VER_CHK),)
ifeq ($(strip $(CONFIG_LIBC)),"uClibc")
ifeq ($(CONFIG_ARCH), "mips")
CONFIGURE_ARGS += \
        ac_cv___thread=no
endif
endif
endif
endif

endif

ifeq ("$(strip ${ZCFG_PLATFORM})","BROADCOM")
TARGET_CFLAGS += -Wno-error=unused-but-set-variable
endif

ifeq ("$(strip ${ZCFG_PLATFORM})","QUALCOMM")
CONFIGURE_ARGS += \
	ac_cv_func_strdup=yes \
	ac_cv_func_strncasecmp=yes \
	ac_cv_func_snprintf=yes
endif
define Package/libjson
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=javascript object notation
endef

define Package/libjson/description
 This package contains a library for javascript object notation backends.
endef

ifeq ("$(strip ${ZCFG_PLATFORM})","QUALCOMM")
define Package/libjson-c
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=javascript object notation
  URL:=http://oss.metaparadigm.com/json-c/
  ABI_VERSION:=4
endef

define Package/libjson-c/description
 This package contains a library for javascript object notation backends.
endef
endif

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
ifeq ($(shell test $(shell echo $(PKG_VERSION) | cut -d . -f 2) -gt 11; echo $$?),0)
	$(CP) $(PKG_INSTALL_DIR)/usr/include/json-c $(1)/usr/include/
	ln -s json-c $(1)/usr/include/json
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjson-c.{a,so*} $(1)/usr/lib/
	ln -s libjson-c.so $(1)/usr/lib/libjson.so
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/json-c.pc $(1)/usr/lib/pkgconfig/
else
	$(CP) $(PKG_INSTALL_DIR)/usr/include/json $(1)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjson.{a,so*} $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/json.pc $(1)/usr/lib/pkgconfig/
endif	
	
endef
ifeq ("$(strip ${ZCFG_PLATFORM})","QUALCOMM")
define Package/libjson-c/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjson-c.so.* $(1)/usr/lib/
endef
endif

define Package/libjson/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/lib
ifeq ($(shell test $(shell echo $(PKG_VERSION) | cut -d . -f 2) -gt 11; echo $$?),0)
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjson-c.so* $(1)/usr/lib/
	ln -s libjson-c.so $(1)/usr/lib/libjson.so
else	
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjson.so* $(1)/usr/lib/
endif  
ifeq ($(strip $(CONFIG_LIBJSON_VERSION)),"0.13.1")
	ln -s /usr/lib/libjson-c.so.4 $(1)/lib/libjson-c.so.4
endif
endef

$(eval $(call BuildPackage,libjson))
ifeq ("$(strip ${ZCFG_PLATFORM})","QUALCOMM")
$(eval $(call BuildPackage,libjson-c))
endif
