#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

DEVICE_TYPE=customer

BOARD:=brcm963xx
BOARDNAME:=Broadcom BCM963xx
FEATURES:=usb pci pcmcia

ifeq ($(shell grep CONFIG_BRCM963xx_SDK_VER_412L08 $(TOPDIR)/.config | cut -d'=' -f2),y)
LINUX_VERSION:=2.6.30
else
ifeq ($(shell grep CONFIG_BRCM963xx_SDK_VER_502L04 $(TOPDIR)/.config | cut -d'=' -f2),y)
LINUX_VERSION:=4.1.45
else ifeq ($(shell grep CONFIG_BRCM963xx_SDK_VER_502L05 $(TOPDIR)/.config | cut -d'=' -f2),y)
LINUX_VERSION:=4.1.51
else ifeq ($(shell grep CONFIG_BRCM963xx_SDK_VER_502L06 $(TOPDIR)/.config | cut -d'=' -f2),y)
LINUX_VERSION:=4.1.52
else ifeq ($(shell grep CONFIG_BRCM963xx_SDK_VER_502L07 $(TOPDIR)/.config | cut -d'=' -f2),y)
LINUX_VERSION:=4.1.52
else
LINUX_VERSION:=3.4.11
endif
endif

ifeq ($(CONFIG_BRCM_SDK_VERSION), "416L05")
ifeq ($(CONFIG_BCM416L05_WIFI_VER_7_14_164_23),y)
WIFI_DRIVER_VER:=7_14_164_23
else ifeq ($(CONFIG_BCM416L05_WIFI_VER_7_14_164_20),y)
WIFI_DRIVER_VER:=7_14_164_20_NEW
else ifeq ($(CONFIG_BCM416L05_WIFI_VER_7_14_164_303),y)
WIFI_DRIVER_VER:=7_14_164_303_NEW
else
WIFI_DRIVER_VER:=7_14_164_23
endif
endif

ifeq ($(CONFIG_BRCM_SDK_VERSION), "502L05")
IMPL=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BCM_WLIMPL))
ifeq ("$(IMPL)", "")
IMPL:=32
endif
ifeq ($(CONFIG_BCM502L05_WIFI_VER_7_14_170_36),y)
WIFI_DRIVER_VER:=7_14_170_36_NEW
WLAN_DHD_TARBALL_DOWNLOAD=n
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_7_14_170_42),y)
WIFI_DRIVER_VER:=7_14_170_42_Date_20191114
WLAN_DHD_TARBALL_DOWNLOAD=n
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_17_10_39_0),y)
WIFI_DRIVER_VER:=17_10_39_0
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_17_10_60_0),y)
WIFI_DRIVER_VER:=17_10_60_0
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_17_10_77_12),y)
WIFI_DRIVER_VER:=17_10_77_12_NEW
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_17_10_77_15),y)
WIFI_DRIVER_VER:=17_10_77_15
else ifeq ($(CONFIG_BCM502L05_WIFI_VER_17_10_99_1301),y)
WIFI_DRIVER_VER:=17_10_99_1301
else
WIFI_DRIVER_VER:=7_14_170_36_NEW
WLAN_DHD_TARBALL_DOWNLOAD=n
endif
endif

ifeq ($(CONFIG_BRCM_SDK_VERSION), "502L06")
IMPL=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BCM_WLIMPL))
ifeq ($(CONFIG_BCM502L06_WIFI_VER_17_10_60_0),y)
WIFI_DRIVER_VER:=17_10_60_0
else ifeq ($(CONFIG_BCM502L06_WIFI_VER_17_10_77_12),y)
WIFI_DRIVER_VER:=17_10_77_12
else
WIFI_DRIVER_VER:=17_10_60_0
endif
endif

ifeq ($(CONFIG_BRCM_SDK_VERSION), "502L07")
IMPL=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BCM_WLIMPL))
ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_99_7),y)
WIFI_DRIVER_VER:=17_10_99_7
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_99_1301),y)
WIFI_DRIVER_VER:=17_10_99_1301
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_99_17),y)
WIFI_DRIVER_VER:=17_10_99_17
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_99_27),y)
WIFI_DRIVER_VER:=17_10_99_27_DATE_20200903
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_117_0),y)
WIFI_DRIVER_VER:=17_10_117_0_Date_20191231
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_121_11),y)
WIFI_DRIVER_VER:=17_10_121_11
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_7_14_170_43),y)
ifeq ($(CONFIG_BRCM_SDK_PATCH_VERSION), "P2")
WIFI_DRIVER_VER:=7_14_170_43_P2_DATE_20220812
else
WIFI_DRIVER_VER:=7_14_170_43_DATE_20200903
endif
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_121_2004),y)
WIFI_DRIVER_VER:=17_10_121_2004
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_121_37),y)
WIFI_DRIVER_VER:=17_10_121_37
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_157_2805),y)
WIFI_DRIVER_VER:=17_10_157_2805_DATE_20220812
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_157_60),y)
WIFI_DRIVER_VER:=17_10_157_60_DATE_20220812
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_188_55),y)
WIFI_DRIVER_VER:=17_10_188_55
else ifeq ($(CONFIG_BCM502L07_WIFI_VER_17_10_188_75),y)
WIFI_DRIVER_VER:=17_10_188_75
else
WIFI_DRIVER_VER:=17_10_99_7
endif
endif

SUBTARGETS:=96858GWOV 96838GWOV 963158GW 963138ref 963269bhr 963178GWV 962118GWV $(filter fmg% vmg% xmg% emg% pm% px% dx% mx% ex% wx%,$(shell find * -maxdepth 0 -type d))

include $(INCLUDE_DIR)/target.mk

DEFAULT_PACKAGES=libc libgcc busybox dropbear mtd opkg 

define Target/Description
	Build firmware images for Broadcom based xDSL/routers
	currently supports BCM63138, BCM63168, BCM63268 BCM63169 and BCM63269 based devices.
endef

ifneq ($(call qstrip,$(CONFIG_BRCM_SDK_PATCH_VERSION)),)
BROADCOM_SDK_PACKAGE:=broadcom_sdk_$(shell echo $(CONFIG_BRCM_SDK_VERSION))$(shell echo $(CONFIG_BRCM_SDK_PATCH_VERSION))$(shell echo $(CONFIG_BRCM_SDK_PACKAGE_SUFFIX))_pkg.tar.xz
else
BROADCOM_SDK_PACKAGE:=broadcom_sdk_$(shell echo $(CONFIG_BRCM_SDK_VERSION))$(shell echo $(CONFIG_BRCM_SDK_PACKAGE_SUFFIX))_pkg.tar.xz
endif

BROADCOM_SDK_DIR:=$(KERNEL_BUILD_DIR)/broadcom-sdk-$(shell echo $(CONFIG_BRCM_SDK_VERSION))

# __zy_bsp__ >>>
ZYBSP_BCM_SDK_VER_CHK := $(findstring $(CONFIG_BRCM_SDK_VERSION),"502L04" "502L05" "502L06" "502L07")
ifneq ($(ZYBSP_BCM_SDK_VER_CHK),)
ZYBSP_BCM_SDK_VER=502L0X
CONFIG_BRCM963xx_SDK_VER_502L0X=y
endif
# __zy_bsp__ <<<

define genMRDinfo
	mkdir -p $(BROADCOM_SDK_DIR)/shared/zyxel
	echo -e "/*\n * This file is auto-generated by OpenWRT if compile BRCM963xx platform.\n * !!! Don't edit it !!!\n */\n" > $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo -e "#ifndef _ZYXEL_MRD_H_\n#define _ZYXEL_MRD_H_" >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define VENDORNAME       $(CONFIG_MRD_VENDOR_NAME)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define PRODUCTNAME      $(CONFIG_MRD_PRODUCT_NAME)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define SERIALNUMBER     $(CONFIG_MRD_SERIAL_NO)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define MAINFEATUREBIT   $(CONFIG_MRD_MAIN_FEATURE_BIT)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define ZYXEL_MODEL_ID   $(CONFIG_MRD_MODEL_ID)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define DEBUGBIT         $(CONFIG_MRD_DEBUG_BIT)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define COUNTRYCODE      $(CONFIG_MRD_COUNTRY_CODE)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo '#define FIRMWARE_VERSION $(CONFIG_ZYXEL_FIRMWARE_VERSION)' >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
	echo "#endif" >> $(BROADCOM_SDK_DIR)/shared/zyxel/MRD.h
endef

# Special action to support RTK switch
define Kernel/Prepare/RTKSW


endef



ifeq ("$(CONFIG_BRCM963xx_SDK_VER_502L0X)", "y")
INC_DIR:=include/uapi
else
INC_DIR:=include
endif

KERNEL_INCLUDE_LINK_NAME := bcm_local_kernel_include
KERNEL_MIPS_INCLUDE_LINK_NAME := bcm_local_kernel_mips_include
KERNEL_ARM_INCLUDE_LINK_NAME := bcm_local_kernel_arm_include
KERNEL_INCLUDE_LINK := $(KERNEL_BUILD_DIR)/$(KERNEL_INCLUDE_LINK_NAME)
KERNEL_MIPS_INCLUDE_LINK := $(KERNEL_BUILD_DIR)/$(KERNEL_MIPS_INCLUDE_LINK_NAME)
KERNEL_ARM_INCLUDE_LINK := $(KERNEL_BUILD_DIR)/$(KERNEL_ARM_INCLUDE_LINK_NAME)

define Kernel/Prepare/BCM
	xzcat $(DL_DIR)/$(BROADCOM_SDK_PACKAGE) | /bin/tar -C $(KERNEL_BUILD_DIR)/ -xf -
endef

define Kernel/Prepare
	$(call Kernel/Prepare/BCM)
	$(call Kernel/Prepare/RTKSW)
	if [ ! -f  $(BROADCOM_SDK_DIR)/targets/$(BCM_PROFILE)/$(BCM_PROFILE) ]; then mkdir -p $(BROADCOM_SDK_DIR)/targets/$(BCM_PROFILE)/ ; fi
	$(TOPDIR)/scripts/genBrcmProfile.sh $(TOPDIR)/.config $(BROADCOM_SDK_DIR)/targets/$(BCM_PROFILE)/$(BCM_PROFILE) $(CONFIG_BRCM_SDK_VERSION)
	echo "$(BCM_PROFILE)" > $(BROADCOM_SDK_DIR)/.last_profile
	$(call genMRDinfo)
	ln -s -f $(LINUX_DIR)/$(INC_DIR) $(KERNEL_INCLUDE_LINK);
ifneq ($(CONFIG_mips),)
	ln -s -f $(LINUX_DIR)/arch/mips/$(INC_DIR) $(KERNEL_MIPS_INCLUDE_LINK);
else
	ln -s -f $(LINUX_DIR)/arch/arm/$(INC_DIR) $(KERNEL_ARM_INCLUDE_LINK);
endif
	$(call Kernel/Prepare/Default)
endef

#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
BRCM_DRIVER_WIRELESS=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BRCM_DRIVER_WIRELESS))
BCM_WL_IMPL=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BCM_WLIMPL))
VISUALIZATION=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_WLVISUALIZATION))
WBD=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_WBD))
BUILD_CPEROUTER=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_BRCM_CPEROUTER))
BUILD_HOSTAPD=$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_BRCM_HOSTAPD))
WL_BUILD_DIR=$(BROADCOM_SDK_DIR)/bcmdrivers/broadcom/net/wl/
PERLIB_DIR=$(STAGING_DIR_HOST)/bin/$(shell echo $(CONFIG_BRCM_SDK_VERSION))/PerlLib
PROFILEDIRSTR=$(BROADCOM_SDK_DIR)/targets/$(BCM_PROFILE)/$(BCM_PROFILE)

ifeq ($(BCM_WL_IMPL), 53)
# router directory changes from wifi driver 17.10.39.0
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 61)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 55)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 63)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 69)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 71)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else ifeq ($(BCM_WL_IMPL), 87)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/components/router/
else
#SDK 502L05p1 modify bcmdrivers\broadcom\net\wl\cperouter_init_config.pl and need to have two additional parameters.
PERLIB_DIR=$(STAGING_DIR_HOST)/bin/$(shell echo $(CONFIG_BRCM_SDK_VERSION))/PerlLib
PROFILEDIRSTR=$(BROADCOM_SDK_DIR)/targets/$(BCM_PROFILE)/$(BCM_PROFILE)
CPE_WL_ROUTER_BUILD_DIR=$(WL_BUILD_DIR)/impl$(BCM_WL_IMPL)/main/src/router/
endif

ifeq ($(BUILD_CPEROUTER),y)
CPE_ROUTER_FILE=$(CPE_WL_ROUTER_BUILD_DIR)/config/defconfig-4.1-vista-dhdap-router
CPE_ROUTER_CONF=$(CPE_WL_ROUTER_BUILD_DIR)/config/defconfig-4.1-vista-dhdap-bca-cperouter
else
CPE_ROUTER_CONF=$(CPE_WL_ROUTER_BUILD_DIR)/config/defconfig-2.6-vista-dhdap-router-atlas
endif
HOSTTOOLS_PERL_LIB = $(TOPDIR)/tools/private/broadcom/brcm-imageutil-$(shell echo $(CONFIG_BRCM_SDK_VERSION))/files/$(shell echo $(CONFIG_BRCM_SDK_VERSION))/PerlLib
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


ifeq ("$(BRCM_DRIVER_WIRELESS)", "")
define prepareWlConfig
	@echo "No need to config wl when wl driver disabled."
endef
else
define prepareWlConfig

ifeq ("$(BUILD_CPEROUTER)","y")
	cp $(CPE_ROUTER_FILE) $(CPE_ROUTER_CONF)
endif

endef
endif

define Kernel/Configure
	$(call Kernel/Configure/Default)
ifeq ("$(CONFIG_BRCM963xx_SDK_VER_502L0X)", "y")
	make -C $(BROADCOM_SDK_DIR) create_install
	make -C $(BROADCOM_SDK_DIR) bcmdrivers_autogen
	make -C $(BROADCOM_SDK_DIR) rdp_link
	make -C $(BROADCOM_SDK_DIR) generate_cms_dmp_flags_h
	make -C $(BROADCOM_SDK_DIR) dtbs
	$(call prepareWlConfig)
ifeq ("$(BUILD_CPEROUTER)","y")
	make -C $(BROADCOM_SDK_DIR) hnd_dongle
endif
endif

endef

$(eval $(call BuildTarget))
