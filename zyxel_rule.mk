#
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

ifneq ($(__zyxel_rules_inc),1)
__zyxel_rules_inc=1

########################################################################
###    init
########################################################################
#store Zyxel common cflags
ZYXEL_COMMON_CFLAGS:=

#specific for userspace "process" and inherit the setting in ZYXEL_COMMON_CFLAGS
ZYXEL_APP_CFLAGS:=
ZYXEL_APP_LDFLAGS:=

#specific for userspace "libraries" and inherit the setting in ZYXEL_COMMON_CFLAGS
ZYXEL_LIB_CFLAGS:=
ZYXEL_LIB_LDFLAGS:=


########################################################################
###    START: Zyxel common compile flags
########################################################################
ZYXEL=y
ZYXEL_RSA_FORMAT=y

########################################################################
# Broadcom Related
########################################################################
ifeq ("$(strip ${ZCFG_PLATFORM})","BROADCOM")

ZYXEL_COMMON_CFLAGS += -DBROADCOM_PLATFORM

ifneq ("$(CONFIG_BRCM_SDK_VERSION)","")
ZYXEL_COMMON_CFLAGS += -DBCM_SDK_$(CONFIG_BRCM_SDK_VERSION)
ZYXEL_COMMON_CFLAGS += -DNEW_MTD_DRIVER
endif

ifeq ($(CONFIG_ZYXEL_VMG8924_B10D_TISCALI_ISOLATE_DMZ),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_VMG8924_B10D_TISCALI_ISOLATE_DMZ
endif

ifeq ($(CONFIG_BRCMSDK416L05_SUPPORT_RTK_SWITCH),y)
ZYXEL_COMMON_CFLAGS += -DSUPPORT_RTK_SWITCH
endif

ifeq ($(CONFIG_ZYXEL_SFP_LINKUP_DELAYTIMES),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SFP_LINKUP_DELAYTIMES
endif

ifeq ($(CONFIG_KERNEL_ZYXEL_RS_TRY_5_TIMES),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_RS_TRY_5_TIMES
endif

ifeq ($(CONFIG_BRCM_CFE_CHIP_63178),y)
ZYXEL_COMMON_CFLAGS += -DBCM963178
endif

ifeq ($(CONFIG_BRCMSDK$(shell echo $(CONFIG_BRCM_SDK_VERSION))_BRCM_PHY_BONDING),y)
ZYXEL_COMMON_CFLAGS += -DSUPPORT_DSL_BONDING
endif

# LED enum in bcmdrivers/opensource/include/bcm963xx/board.h will use it
ifneq ($(findstring _$(strip $(shell echo $(CONFIG_BRCMSDK$(shell echo $(CONFIG_BRCM_SDK_VERSION))_BRCM_CHIP)))_,_6838_6848_6858_6846_6856_6878_),)
ZYXEL_COMMON_CFLAGS += -DCONFIG_BCM_PON=1
endif

endif
# End of Broadcom platform

########################################################################
# Econet Related
########################################################################
ifeq ("$(strip ${ZCFG_PLATFORM})","ECONET")

ifneq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_ZYXEL_LAN_WAN_WLAN_SHARE_THE_SAME_MAC),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_LAN_WAN_WLAN_SHARE_THE_SAME_MAC
endif

ifeq ($(CONFIG_ZYXEL_VMG8825_T50K_TISCALI_ISOLATE_DMZ),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_VMG8825_T50K_TISCALI_ISOLATE_DMZ
endif

ZYXEL_COMMON_CFLAGS += -DNEW_MTD_DRIVER

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7516)),)
ZYXEL_COMMON_CFLAGS += -DBOOTROM_LARGE_SIZE
endif
ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_BOOTROM_LARGE_SIZE)),)
ZYXEL_COMMON_CFLAGS += -DBOOTROM_LARGE_SIZE
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_MTD_ENCHANCEMENT)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_MTD_ENCHANCEMENT
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_RESERVEAREA_BLOCK)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_RESERVEAREA_BLOCK=$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_RESERVEAREA_BLOCK)
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CT)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CT
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_NAND_BMT)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_NAND_BMT
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_NAND_BADBLOCK_CHECK)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_NAND_BADBLOCK_CHECK
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_PRODUCTIONLINE)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_PRODUCTIONLINE
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7612E)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_WLAN_AC
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7615E)),)
ZYXEL_COMMON_CFLAGS += -DMT7615E
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_WLAN_MT7615_11N)),)
ZYXEL_COMMON_CFLAGS += -DMT7615_11N
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_WLAN_MT7615D)),)
ZYXEL_COMMON_CFLAGS += -DMT7615D -DMT7615_11N -DMT7615E -DTCSUPPORT_DUAL_WLAN -DTCSUPPORT_WLAN_AC
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_WLAN_MT7915D)),)
ZYXEL_COMMON_CFLAGS += -DMT7915D -DMT7915N -DMT7915E -DTCSUPPORT_DUAL_WLAN -DTCSUPPORT_WLAN_AC -DTCSUPPORT_WLAN_AX -DTCSUPPORT_WLAN_WPA3
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_WLAN_MT7915A)),)
ZYXEL_COMMON_CFLAGS += -DMT7915A -DMT7915E -DTCSUPPORT_DUAL_WLAN -DTCSUPPORT_WLAN_AC -DTCSUPPORT_WLAN_AX -DTCSUPPORT_WLAN_WPA3
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7570)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_MT7570
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CT_BOOTLOADER_UPGRADE)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CT_BOOTLOADER_UPGRADE
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_LITTLE_ENDIAN)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_BB_256KB
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7580)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_BB_256KB
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7523)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_BB_256KB
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_NAND_FLASH)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_NAND_FLASH
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CT_PON)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CT_PON
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7613E)),)
ZYXEL_COMMON_CFLAGS += -DMT7613E
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7615E)),)
ZYXEL_COMMON_CFLAGS += -DMT7615E
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7610E)),)
ZYXEL_COMMON_CFLAGS += -DMT7610E -DBBUTOWBU -DTCSUPPORT_DUAL_WLAN -DTCSUPPORT_WLAN_AC
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DUAL_WLAN_MT7612E)),)
ZYXEL_COMMON_CFLAGS += -DMT7612E -DBBUTOWBU -DTCSUPPORT_DUAL_WLAN -DTCSUPPORT_WLAN_AC
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7512)$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7516)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CPU_EN7512
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7521)$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7527)$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7528)$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7580)$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7523)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CPU_EN7521
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_RESERVEAREA_EXTEND)),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_RESERVEAREA_EXTEND
endif

ifneq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_POWERSAVE_ENABLE),)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_POWERSAVE_ENABLE
endif

ifeq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_CPU_EN7516),y)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_CPU_EN7516
endif

ifeq ($(CONFIG_ZYXEL_ECONET_OPERATION_MODE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ECONET_OPERATION_MODE
endif

ifeq ($(CONFIG_ZY_ECN_NO_MESH_CUSTOM),y)
ZYXEL_COMMON_CFLAGS += -DZY_ECN_NO_MESH_CUSTOM
endif

ifeq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_DMT_MCT),y)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_DMT_MCT
endif

ifeq ($(CONFIG_EN7516SDK_TCSUPPORT_ECNT_MAP),y)
ZYXEL_COMMON_CFLAGS += -DTCSUPPORT_ECNT_MAP
endif

ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.235.200")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_235_200
endif
ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.257.150")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_257_150
endif
ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.245.300")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_245_300
endif
ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.251.900")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_251_900
endif
ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.267.0")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_267_0
endif
ifeq ($(CONFIG_TC_SDK_VERSION),"7.3.267.750")
ZYXEL_COMMON_CFLAGS += -DCONFIG_TC_SDK_7_3_267_750
endif

ifeq ($(CONFIG_ZYXEL_ECONET_STANDALONE_BAND_STEERING),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_ECONET_STANDALONE_BAND_STEERING
endif

ifeq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_ZYXEL_DETECT_PRODUCT_TYPE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DETECT_PRODUCT_TYPE
endif

ifneq ($(CONFIG_ECN_MT7615_DRIVER_VER),"")
ZYXEL_COMMON_CFLAGS += -DECONET_WIFI_DRIVER_VERSION="'\"$(CONFIG_ECN_MT7615_DRIVER_VER)\"'"
else
ZYXEL_COMMON_CFLAGS += -DECONET_WIFI_DRIVER_VERSION="'\"\"'"
endif

endif
# End of Econet platform

########################################################################
# Zyxel Customization
########################################################################
ifeq ($(CONFIG_ABUE_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABUE_CUSTOMIZATION
endif

ifeq ($(CONFIG_ABOG_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABOG_CUSTOMIZATION
endif

#ISKON
ifeq ($(CONFIG_ISKON_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DISKON_CUSTOMIZATION
endif

ifeq ($(CONFIG_ISKON_CUSTOMIZATION_Motorola_VIP1003),y)
ZYXEL_COMMON_CFLAGS += -DISKON_CUSTOMIZATION_Motorola_VIP1003
endif

#TSF
ifeq ($(CONFIG_TSF_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DTSF_CUSTOMIZATION
endif

#ACEN
ifeq ($(CONFIG_ACEN_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DZYPRJ_CUSTOMER_ACEN
endif

ifeq ($(CONFIG_ACEN_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DACEN_CUSTOMIZATION
endif

#TT
ifeq ($(CONFIG_TT_CUSTOMIZATION_TR069),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_CUSTOMIZATION_TR069
endif

ifeq ($(CONFIG_TT_DSL_BINDING),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_DSL_BINDING
endif

ifeq ($(CONFIG_TT_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_CUSTOMIZATION
endif

ifeq ($(CONFIG_ZYXEL_TT_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TT_CUSTOMIZATION
endif

ifeq ($(CONFIG_TT_PORTMIRROR),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_PORTMIRROR
endif

ifeq ($(CONFIG_TT_PORTMIRROR_E),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_PORTMIRROR_E
endif

ifeq ($(CONFIG_TT_PACKETCAPTURE),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_TT_PACKETCAPTURE
endif

ifeq ($(CONFIG_MSTC_TTNET_MULTI_USER),y)
ZYXEL_COMMON_CFLAGS += -DMSTC_TTNET_MULTI_USER
endif

ifeq ($(CONFIG_ZYXEL_TTNET_EDNS),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TTNET_EDNS
endif

ifeq ($(CONFIG_ZYXEL_TTNET_FIREWALL_WANINTERFACE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TTNET_FIREWALL_WANINTERFACE
endif

# always set APP_AGENT_SUPPORT ???
ifeq ($(filter y,$(CONFIG_CBT_CUSTOMIZATION)),)
ZYXEL_COMMON_CFLAGS += -DAPP_AGENT_SUPPORT
endif

ifeq ($(CONFIG_CBT_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCBT_CUSTOMIZATION
endif

#Codetel
ifeq ($(CONFIG_CODETEL_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCODETEL_CUSTOMIZATION
endif

#Claro
ifeq ($(CONFIG_CLARO_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCLARO_CUSTOMIZATION
endif

#Starry
ifeq ($(CONFIG_STARRY_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DSTARRY_CUSTOMIZATION
endif

#ABUU
ifeq ($(CONFIG_ABUU_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABUU_CUSTOMIZATION
endif

ifeq ($(CONFIG_ABXA_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABXA_CUSTOMIZATION
endif

ifeq ($(CONFIG_ABUU_CUSTOMIZATION_MULTIPLE_CONFIG),y)
ZYXEL_COMMON_CFLAGS += -DABUU_CUSTOMIZATION_MULTIPLE_CONFIG
endif

ifeq ($(CONFIG_ABUU_CUSTOMIZATION_WLAN_SCHEDULER),y)
ZYXEL_COMMON_CFLAGS += -DABUU_CUSTOMIZATION_WLAN_SCHEDULER
endif

#Sunrise
ifneq ($(strip $(CONFIG_SUNRISE_TR98_CUSTOMIZATION)),)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_TR98_CUSTOMIZATION
endif

ifeq ($(CONFIG_SUNRISE_TR69_WAN_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_TR69_WAN_CUSTOMIZATION
endif

ifeq ($(CONFIG_SUNRISE_VLANHUNT_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_VLANHUNT_CUSTOMIZATION
endif

ifeq ($(CONFIG_SUNRISE_WAN_AUTO_DETECT_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_WAN_AUTO_DETECT_CUSTOMIZATION
endif

#Tiscali
ifeq ($(CONFIG_TISCALI_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TISCALI_CUSTOMIZATION
endif

#Elisa
ifeq ($(CONFIG_ELISA_CLEAN_ROMD_EVERYTIME_DURING_BOOT_UP),y)
ZYXEL_COMMON_CFLAGS += -DELISA_CLEAN_ROMD_EVERYTIME_DURING_BOOT_UP
endif
ifeq ($(CONFIG_ELISA_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DELISA_CUSTOMIZATION
endif
ifeq ($(CONFIG_ELISA_WAN_AUTO_DETECT),y)
ZYXEL_COMMON_CFLAGS += -DELISA_WAN_AUTO_DETECT
endif

#Oi
ifeq ($(CONFIG_OI_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DOI_CUSTOMIZATION
endif

#ACAU
ifeq ($(CONFIG_ACAU_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DACAU_CUSTOMIZATION
endif

#ABZQ
ifeq ($(CONFIG_ABZQ_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ABZQ_CUSTOMIZATION
endif

ifeq ($(CONFIG_ABZQ_CUSTOMIZATION_SUPPORT_WIFI_COUNTER_PER_SSID),y)
ZYXEL_COMMON_CFLAGS += -DABZQ_CUSTOMIZATION_SUPPORT_WIFI_COUNTER_PER_SSID
endif


ifeq ($(CONFIG_ABZQ_CUSTOMIZATION_SUPPORT_WIFI_CHANNEL_HOPPING),y)
ZYXEL_COMMON_CFLAGS += -DABZQ_CUSTOMIZATION_SUPPORT_WIFI_CHANNEL_HOPPING
endif

ifeq ($(CONFIG_ABZQ_CUSTOMIZATION_SUPPORT_FIREWALL_MAC_DEST_FILTER),y)
ZYXEL_COMMON_CFLAGS += -DABZQ_CUSTOMIZATION_SUPPORT_FIREWALL_MAC_DEST_FILTER
endif

ifeq ($(CONFIG_ABZQ_CUSTOMIZATION_SUPPORT_TR69_PRIVATE_NAME_HEADER),y)
ZYXEL_COMMON_CFLAGS += -DABZQ_CUSTOMIZATION_SUPPORT_TR69_PRIVATE_NAME_HEADER
endif

ifeq ($(CONFIG_ABZQ_CUSTOMIZATION_SUPPORT_ABZQ_ACS_SERVER),y)
ZYXEL_COMMON_CFLAGS += -DABZQ_CUSTOMIZATION_SUPPORT_ABZQ_ACS_SERVER
endif

#ABPY
ifeq ($(CONFIG_ABPY_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABPY_CUSTOMIZATION
endif

#ABQA
ifeq ($(CONFIG_ABQA_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DABQA_CUSTOMIZATION
endif
# End of Zyxel Customization

########################################################################
# Zyxel Features
########################################################################
ZYXEL_COMMON_CFLAGS += -D$(ZCFG_PLATFORM)_PLATFORM

ifeq ($(CONFIG_ZYXEL_FEATURE_BITS),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_FEATURE_BITS
endif

ifeq ($(CONFIG_ZYXEL_SFP_MODULE_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SFP_MODULE_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_SIP_DELAYTIMES),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SIP_DELAYTIMES
endif

ifeq ($(CONFIG_ZYXEL_AP_STEERING),y)
ZYXEL_COMMON_CFLAGS += -DAPSTEERING
endif

ifeq ($(CONFIG_ZyXEL_WEB_REDIRECT),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_WEB_REDIRECT
endif

ifeq ($(CONFIG_ZyXEL_PCP_WEB_REDIRECT),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_PCP_WEB_REDIRECT
endif

ifeq ($(CONFIG_ZYXEL_DL_DIAG_CALCULATION),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DL_DIAG_CALCULATION
endif

ifeq ($(CONFIG_DSL_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DSUPPORT_DSL
endif

ifeq ($(CONFIG_ZCFG_LOG_USE_DEBUGCFG),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_LOG_USE_DEBUGCFG
ZYXEL_COMMON_CFLAGS += -DZCFG_ZYUTIL_DEBUG_API
endif

ifeq ($(CONFIG_TARGET_ROOTFS_UBIFS),y)
ZYXEL_COMMON_CFLAGS += -DTARGET_ROOTFS_UBIFS
endif

ifeq ($(CONFIG_ZYXEL_AT_SET_KEY),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_AT_SET_KEY
ifeq ($(CONFIG_ZYXEL_AT_SET_SUPERVISOR_KEY),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_AT_SET_SUPERVISOR_KEY
endif
endif

ifeq ($(CONFIG_ZYXEL_YAD_SET_FIXED_PSK),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_YAD_SET_FIXED_PSK
endif

ifeq ($(CONFIG_ZYXEL_DNS_TRAFFIC_ROUTE_FUZZY_COMPARE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DNS_TRAFFIC_ROUTE_FUZZY_COMPARE
endif

ifeq ($(CONFIG_ZYXEL_OPAL_EXTENDER_WITH_NPACK),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_OPAL_EXTENDER_WITH_NPACK
endif

ifneq ($(strip $(CONFIG_ZYXEL_RMA_FW_SUPPORT)),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_RMA_FW_SUPPORT
endif

ifneq ($(strip $(CONFIG_ZYXEL_IPV6_UPLOAD_DIAG_ENABLE)),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IPV6_UPLOAD_DIAG_ENABLE
endif

ifeq ($(CONFIG_LTE_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DLTE_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_NEW_ATSN),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_NEW_ATSN
endif

ifneq ($(strip $(CONFIG_ZYXEL_FIRMWARE_VERSION_EXT)), "")
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_EXT_FW_VER
endif

ifeq ($(CONFIG_ZYXEL_MEMORY_LEAK_DETECT),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_MEMORY_LEAK_DETECT
endif

#define the number of interface for 2.4G and 5G
ifneq ($(strip $(CONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE)),)
ZYXEL_COMMON_CFLAGS += -DTOTAL_INTERFACE_24G=$(CONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE)
endif
ifneq ($(strip $(CONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE)),)
ZYXEL_COMMON_CFLAGS += -DTOTAL_INTERFACE_5G=$(CONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE)
endif

# F-secure Home Cyber Security
ifeq ($(CONFIG_ZYXEL_HOME_CYBER_SECURITY_FSECURE),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_HOME_CYBER_SECURITY_FSECURE
endif

ifeq ($(CONFIG_KERNEL_ZYXEL_RS_TRY_5_TIMES),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_RS_TRY_5_TIMES
endif

ifeq ($(CONFIG_WIND_Greece_DHCPv6_Client_NTP_Option),y)
ZYXEL_COMMON_CFLAGS += -DWIND_Greece_DHCPv6_Client_NTP_Option
endif

ifeq ($(CONFIG_ZYXEL_USA_PRODUCT),y)
ZYXEL_COMMON_CFLAGS += -DUSA_PRODUCT
endif

ifeq ($(CONFIG_ZYXEL_WLAN_SCHEDULER),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WLAN_SCHEDULER
endif

ifeq ($(CONFIG_ZYXEL_SP_DOMAIN_TIMER),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SP_DOMAIN_TIMER
endif

ifeq ($(CONFIG_SEND_PADT_BEFORE_DISCOVERY),y)
ZYXEL_COMMON_CFLAGS += -DSEND_PADT_BEFORE_DISCOVERY
endif

ifeq ($(CONFIG_WAN_AUTO_DETECT),y)
ZYXEL_COMMON_CFLAGS += -DWAN_AUTO_DETECT
endif

ifeq ($(CONFIG_ZYXEL_SYS_FWUR_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SYS_FWUR_SUPPORT=y
endif

ifeq ($(CONFIG_BRCMSDK$(shell echo $(CONFIG_BRCM_SDK_VERSION))_ZYXEL_SUPPORT_3G_LED_GREEN_AND_RED),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_3G_LED_GREEN_AND_RED
endif

ifeq ($(CONFIG_INTERNET_LED_DEPEND_ON_DEFAULT_GW),y)
ZYXEL_COMMON_CFLAGS += -DINTERNET_LED_DEPEND_ON_DEFAULT_GW
endif

ifeq ($(CONFIG_BRCMSDK$(shell echo $(CONFIG_BRCM_SDK_VERSION))_ZYXEL_FW_UPGRADE_POWER_LED_BLINK),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_FW_UPGRADE_POWER_LED_BLINK
endif

ifeq ($(CONFIG_BRCMSDK$(shell echo $(CONFIG_BRCM_SDK_VERSION))_ZYXEL_LED_ERROR_INDICATION_FOR_100M),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_LED_ERROR_INDICATION_FOR_100M
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_ZYXEL_FW_UPGRADE_POWER_LED_BLINK)),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_FW_UPGRADE_POWER_LED_BLINK
endif

ifeq ($(strip ${CONFIG_ZYXEL_WPS_SPOTLIGHT}),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WPS_SPOTLIGHT
endif

ZYXEL_COMMON_CFLAGS += -DZYXEL_ESMD_UTILIZE_TIMER_THREAD

# Support ONECONNECT
ifeq ($(CONFIG_ZYXEL_ONECONNECT),y)
ZYXEL_COMMON_CFLAGS += -DONECONNECT
endif

ifeq ($(CONFIG_ZYXEL_ONECONNECT_EU),y)
ZYXEL_COMMON_CFLAGS += -DONECONNECT_EU
endif

# Easy Mesh
ifeq ($(CONFIG_ZYXEL_EASYMESH),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_EASYMESH
ZYXEL_COMMON_CFLAGS += -DBUILD_EASYMESH
endif

ifeq ($(CONFIG_ZYXEL_EASYMESH_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DEASYMESH_ROM_CONVERT
ZYXEL_COMMON_CFLAGS += -DZYXEL_EASYMESH_ROM_CONVERT
endif

## PCP
ifeq ($(CONFIG_ZYXEL_PCP),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_PCP_SUPPORT
endif

ifeq ($(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_ZYXEL_SUPPORT_LAN_AS_ETHWAN),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_LAN_AS_ETHWAN
ifeq ("$(strip ${ZCFG_PLATFORM})","ECONET")
ZYXEL_COMMON_CFLAGS += -DLAN4_PORTID=$(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_TCSUPPORT_LAN3_PORT)
endif
endif

#Ethernet UNI feature
ifeq ($(CONFIG_ZYXEL_WEB_GUI_ETH_UNI),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WEB_GUI_ETH_UNI
endif

ifeq ($(CONFIG_ZyXEL_PPP_LCP_ECHO),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_PPP_LCP_ECHO
endif

ifeq ($(CONFIG_ZYXEL_DHCP_OPTION15),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DHCP_OPTION15
endif

ifeq ($(CONFIG_ZyXEL_DHCP_OPTION125),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_DHCP_OPTION125
endif

ifeq ($(CONFIG_ZYXEL_POWER_MANAGEMENT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_POWER_MGMT
endif

ifeq ($(CONFIG_PROXIMITY_SENSOR_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DSUPPORT_PROXIMITY_SENSOR
endif

ifeq ($(CONFIG_ZYXEL_LED_SWITCH_ACTIVE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_LED_SWITCH_ACTIVE
endif

ifeq ($(CONFIG_ZYXEL_ZYCLI_SUPERVISOR_IPTABLES),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZYCLI_SUPERVISOR_IPTABLES
endif

ifeq ($(CONFIG_ZYXEL_ZYCLI_SUPERVISOR_TCPDUMP),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZYCLI_SUPERVISOR_TCPDUMP
endif

#CONFIG_ZYXEL_IPV6_IANA_IAPD
ifeq ($(CONFIG_ZYXEL_IPV6_IANA_IAPD),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IPV6_IANA_IAPD
endif

ifeq ($(CONFIG_ZYXEL_IPV6_MAP),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IPV6_MAP
endif

ifeq ($(CONFIG_HAWAIIAN_TELCOM),y)
ZYXEL_COMMON_CFLAGS += -DHAWAIIAN_TELCOM
endif

#IPv6 Ready Logo Conformance
ifeq ($(CONFIG_ZYXEL_IPV6_READYLOGO_CONFORMANCE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IPV6_READYLOGO_CONFORMANCE
endif

## TR98 Global Ipv6 Enable
ifeq ($(CONFIG_ZYXEL_IPV6_GLOBAL_ENABLE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IPV6_GLOBAL_ENABLE_SUPPORT
endif

#DHCPv6s
ifeq ($(CONFIG_ZYXEL_DHCPV6S_LEASE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DHCPV6S_LEASE
endif

#DHCPv6c option
ifeq ($(CONFIG_ZYXEL_DHCPV6C_OPTION),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DHCPV6C_OPTION
endif

ifeq ($(CONFIG_ZYXEL_DHCPV6C_LAUNCH_WITH_SCRIPT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DHCPV6C_LAUNCH_WITH_SCRIPT
endif

#zigbee
ifeq ($(CONFIG_ZYXEL_ZIGBEE_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZIGBEE_SUPPORT
endif

#Avast agent support
ifeq ($(CONFIG_ZYXEL_AVAST_AGENT_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DAVAST_AGENT_PACKAGE
ZYXEL_COMMON_CFLAGS += -DZYXEL_AVAST_AGENT_SUPPORT
endif

ifeq ($(CONFIG_KERNEL_ZYXEL_SUPPORT_USB_FALL_BACK_2_0),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_USB_FALL_BACK_2_0
endif

ifeq ($(CONFIG_ZYXEL_WWAN),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WWAN
endif

ifeq ($(CONFIG_ZYXEL_AUTO_REMOVE_INTFGUP_CRIT_OPT60_WIFI_INTF),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_AUTO_REMOVE_INTFGUP_CRIT_OPT60_WIFI_INTF
endif

ifeq ($(CONFIG_ZYXEL_WAN_DHCPV6_MODE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WAN_DHCPV6_MODE
endif

ifeq ($(CONFIG_ZYXEL_PD_TYPE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_PD_TYPE
endif

#CO-FW
ifeq ($(CONFIG_ZYXEL_BOARD_DETECT_BY_GPIO),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_BOARD_DETECT_BY_GPIO
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_RDPAWAN_CONFIGURE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_RDPAWAN_CONFIGURE
endif

ifeq ($(CONFIG_SAME_FW_FOR_TWO_BOARD),y)
ZYXEL_COMMON_CFLAGS += -DSAME_FW_FOR_TWO_BOARD
endif

ifeq ($(CONFIG_SAME_FW_FOR_PROJECTS),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SAME_FW_FOR_PROJECTS
ZYXEL_COMMON_CFLAGS += -DSAME_FW_FOR_PROJECTS
endif

ifeq ($(CONFIG_ZYXEL_SFP_POWER_MGMT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SFP_POWER_MGMT
endif

#Extender
ifeq ($(CONFIG_ZYXEL_OPAL_EXTENDER),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_OPAL_EXTENDER
endif

ifeq ($(CONFIG_ZYXEL_DETECT_WAN_IP_CONFLICT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DETECT_WAN_IP_CONFLICT
endif

ifeq ($(CONFIG_ZCFG_MODULE_DEBUG),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZCFG_MODULE_DEBUG
endif

ifeq ($(CONFIG_ZYXEL_WIFI_KEY_REMINDER),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WIFI_KEY_REMINDER
endif

ifeq ($(CONFIG_ZYXEL_WIFI_DELAY_INIT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_WIFI_DELAY_INIT
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_SAS_CBSD),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_SAS_CBSD
endif

ifeq ($(CONFIG_ABNL_CUSTOMIZATION),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ABNL_CUSTOMIZATION
endif

#QoS fq-codel
ifeq ($(CONFIG_ZYXEL_FQ_CODEL),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_FQ_CODEL
endif

#CELLWAN support
ifeq ($(CONFIG_ZYXEL_CELLWAN_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_CELLWAN_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_SEND_NEW_CONNECTION_NOTIFICATION),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SEND_NEW_CONNECTION_NOTIFICATION
endif

ifeq ($(CONFIG_ZYXEL_WLAN_BLOCK_OPEN),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WLAN_BLOCK_OPEN
endif

ifeq ($(CONFIG_ZCFG_CONFIG_ENCRYPT),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_CONFIG_ENCRYPT
endif

ifeq ($(CONFIG_ZYXEL_FW_SIGNATURE_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DFW_SIGNATURE_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_INDEPENDENT_WPS_METHODS),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_INDEPENDENT_WPS_METHODS
endif

ifeq ($(CONFIG_ZYXEL_FWUPGRADE_DHCP_SUB_OPTION43),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_FWUPGRADE_DHCP_SUB_OPTION43
endif

ifeq ($(CONFIG_ZYXEL_DOWNGRADE_CHECK_GUI_ACCOUNT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DOWNGRADE_CHECK_GUI_ACCOUNT
endif

ifeq ($(CONFIG_ZYXEL_SONIQ),y)
ZYXEL_COMMON_CFLAGS += -DBUILD_SONIQ
endif

ifeq ($(CONFIG_ZYXEL_SONIQ_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DSONIQ_ROM_CONVERT
endif

#ONESSID
ifeq ($(CONFIG_ZYXEL_ONESSID),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ONESSID
endif

ifeq ($(CONFIG_ZYXEL_ELIMINATE_DHCP_LEASE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ELIMINATE_DHCP_LEASE
endif

ifneq ($(strip $(CONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE)),)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE=$(CONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE)
endif

ifneq ($(strip $(CONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE)),)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE=$(CONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE)
endif

ifeq ($(CONFIG_TARGET_ROOTFS_JFFS2),y)
ZYXEL_COMMON_CFLAGS += -DTARGET_ROOTFS_JFFS2
endif

ifeq ($(CONFIG_BIG_ENDIAN),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_B_ENDIAN
else
ZYXEL_COMMON_CFLAGS += -DZYXEL_L_ENDIAN
endif

ifeq ($(CONFIG_MSTC_RETAIL_MULTI_USER),y)
ZYXEL_COMMON_CFLAGS += -DMSTC_RETAIL_MULTI_USER
endif

ifeq ($(CONFIG_TENDER_TT_FEATURE),y)
ZYXEL_COMMON_CFLAGS += -DTENDER_TT_FEATURE
endif

ifeq ($(CONFIG_TT_HGW),y)
ZYXEL_COMMON_CFLAGS += -DTT_HGW
endif

ifeq ($(CONFIG_ZYXEL_TTNET_TR69ALG),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TTNET_TR69ALG
endif

ifeq ($(CONFIG_ZYXEL_WLAN_WORK_24_HOURS),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WLAN_WORK_24_HOURS
endif

ifeq ($(CONFIG_ZYXEL_TR140),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_TR140
endif

ifeq ($(CONFIG_ZYXEL_IGMPDIAG),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IGMPDIAG
endif

ifeq ($(CONFIG_ZYXEL_TT_PARTIAL_RESTORE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TT_PARTIAL_RESTORE
endif

# Fixed WAN MAC address sequence arrangement
ifeq ($(CONFIG_ZYXEL_FIX_WAN_MAC),y)
ZYXEL_COMMON_CFLAGS += -DFIX_WAN_MAC
endif

ifeq ($(CONFIG_ZYXEL_ENCRYPTKEY_USE_AT_KEY),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ENCRYPTKEY_USE_AT_KEY
endif

ifeq ($(CONFIG_ZYXEL_GRE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_GRE_SUPPORT -DZYXEL_X_GRE
endif

ifeq ($(CONFIG_ZYXEL_ECONET_CALA_DATA_RE_WRITE_TO_FLASH),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ECONET_CALA_DATA_RE_WRITE_TO_FLASH
endif

ifeq ($(CONFIG_ZYXEL_MULTI_ROM_FILE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_MULTI_ROM_FILE
endif

ifeq ($(CONFIG_ZYXEL_IPTV_SSID_PRIORITY_WPS_PBC),y)
ZYXEL_COMMON_CFLAGS += -DGUEST_SSID_WPS_PBC
ZYXEL_COMMON_CFLAGS += -DWPS_IPTV_GUEST_NUM=$(CONFIG_ZYXEL_WPS_IPTV_GUEST_WIFI_NUM)
endif

#lifemote
ifeq ($(CONFIG_ZYXEL_SUPPORT_LIFEMOTE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_LIFEMOTE
endif

ifeq ($(CONFIG_X_ZYXEL_SUPPORT_LIFEMOTE),y)
ZYXEL_COMMON_CFLAGS += -DX_ZYXEL_SUPPORT_LIFEMOTE
endif

ifeq ($(CONFIG_OPENSSL_VERSION_1_0_2n),y)
ZYXEL_COMMON_CFLAGS += -DOPENSSL_VERSION_1_0_2n
endif

ifneq ($(strip $(CONFIG_ZYXEL_FLASH_ID_CHECK_PREVENT_DOWNGRADE)), "")
ZYXEL_COMMON_CFLAGS += -DFLASH_ID_CHECK_PREVENT_DOWNGRADE="'\"$(CONFIG_ZYXEL_FLASH_ID_CHECK_PREVENT_DOWNGRADE)\"'"
endif

ifneq ($(strip $(CONFIG_ZYXEL_WIFI_CHIP_ID_CHECK_PREVENT_DOWNGRADE)), "")
ZYXEL_COMMON_CFLAGS += -DWIFI_CHIP_ID_CHECK_PREVENT_DOWNGRADE="'\"$(CONFIG_ZYXEL_WIFI_CHIP_ID_CHECK_PREVENT_DOWNGRADE)\"'"
endif

ifeq ($(CONFIG_ZYXEL_REMOTE_ACCESS_PRIVILEGE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_REMOTE_ACCESS_PRIVILEGE
ifeq ($(CONFIG_ZYXEL_REMOTE_ACCESS_PRIVILEGE_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_REMOTE_ACCESS_PRIVILEGE_ROM_CONVERT
endif
endif

ifeq ($(strip $(CONFIG_ZYXEL_LANDING_PAGE_FEATURE)),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_LANDING_PAGE_FEATURE
endif

ifneq ($(strip $(CONFIG_$(shell echo $(CONFIG_CUSTOM_SDK_PREFIX))_ZYXEL_SUPPORT_DEFCFG)),)
ZYXEL_COMMON_CFLAGS+=-DZYXEL_SUPPORT_DEFCFG
endif

#ifeq ($(CONFIG_ZCFG_QUERY_TR98_PARM_ATTR_LIST),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_UTILIZE_TR98_OBJ_ALIAS_ON_TR181
#endif

ifeq ($(CONFIG_ZCFG_QUERY_TR98_PARM_ATTR_LIST),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_QUERY_TR98_PARM_ATTR_LIST
endif

ifeq ($(CONFIG_ZYXEL_REMOVE_VALUECHANGE_FROM_BOOTSTRAP_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_REMOVE_VALUECHANGE_FROM_BOOTSTRAP_ROM_CONVERT
endif

ifeq ($(CONFIG_ZCFG_TR098181_OBJECT_MAPPING_NUM_NAME_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DTR098181_OBJECT_MAPPING_NUM_NAME_CONVERT
endif

ifeq ($(CONFIG_CORE_DUMP_ZCMD),y)
ZYXEL_COMMON_CFLAGS += -DCORE_DUMP_ZCMD
endif

ifeq ($(CONFIG_ZYXEL_FW_ID_CHECK_FW_UPGRADE),y)
ZYXEL_COMMON_CFLAGS += -DFW_ID_CHECK_FW_UPGRADE
endif

ifeq ($(CONFIG_ZYXEL_NO_UPGRADE_SAME_FW),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_NO_UPGRADE_SAME_FW
endif

ifeq ($(CONFIG_ZYXEL_FW_ID_CHECK_PREVENT_DOWNGRADE),y)
ZYXEL_COMMON_CFLAGS += -DFW_ID_CHECK_PREVENT_DOWNGRADE
endif

ifeq ($(CONFIG_ZYXEL_MODEL_ID_CHECK_FW_UPGRADE),y)
ZYXEL_COMMON_CFLAGS += -DMODEL_ID_CHECK_FW_UPGRADE
endif

ifeq ($(CONFIG_ZyXEL_Online_Firmware_Upgrade),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_Online_Firmware_Upgrade
endif

ifeq ($(CONFIG_ZYXEL_WEB_GUI_ONLINE_FW_UPGRADE_VIA_URL),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WEB_GUI_ONLINE_FW_UPGRADE_VIA_URL
endif

ifeq ($(CONFIG_XPON_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_XPON_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_RESET_WATCHDOG),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_RESET_WATCHDOG
endif

ifneq ($(strip $(CONFIG_BUILD_ZYXEL_PHONE_DECT_SUPPORT)),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_PHONE_DECT_SUPPORT=1
endif

ifeq ($(CONFIG_ZyXEL_IPP_PRINTSERVER),y)
ZYXEL_COMMON_CFLAGS += -DZyXEL_IPP_PRINTSERVER
endif

ifeq ($(CONFIG_ZYXEL_SAVE_LOG_TO_FLASH),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SAVE_LOG_TO_FLASH
endif

ifneq ($(strip $(CONFIG_SUNRISE_RELEASE_DHCP_PPP_BEFORE_IFDOWN)),)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_RELEASE_DHCP_PPP_BEFORE_IFDOWN
endif

ifeq ($(CONFIG_SUNRISE_RANDOM_PASSWORD),y)
ZYXEL_COMMON_CFLAGS += -DSUNRISE_RANDOM_PASSWORD
endif

ifeq ($(CONFIG_ZCFG_VMG8825_B50B_Generic),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZCFG_VMG8825_B50B_Generic
endif

ifeq ($(CONFIG_ACEN_ENCRYPTED_IMAGE),y)
ZYXEL_COMMON_CFLAGS += -DACEN_ENCRYPTED_IMAGE
endif

ifeq ($(CONFIG_ZCFG_VMG8825_B50B_Altibox),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZCFG_VMG8825_B50B_Altibox
endif

#SHA512 Password
ifeq ($(CONFIG_ZYXEL_HASH_ACCOUNT_PASSWORD_BY_SHA512), y)
ZYXEL_COMMON_CFLAGS += -DSHA512_PASSWD
ifneq ($(CONFIG_ZYXEL_HASH_ACCOUNT_PASSWORD_BY_SHA512_START_VER),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_HASH_ACCOUNT_PASSWORD_BY_SHA512_START_VER=$(CONFIG_ZYXEL_HASH_ACCOUNT_PASSWORD_BY_SHA512_START_VER)
endif
endif

#SuperOnline
ifeq ($(CONFIG_SOL_TR69_3G_Backup),y)
ZYXEL_COMMON_CFLAGS += -DSOL_TR69_3G_Backup
endif
ifeq ($(CONFIG_SOL_TR69_TRUSTDOMAIN),y)
ZYXEL_COMMON_CFLAGS += -DSOL_TR69_TRUSTDOMAIN
endif
ifeq ($(CONFIG_SOL_TR69_LOGINACCOUNT),y)
ZYXEL_COMMON_CFLAGS += -DSOL_TR69_LOGINACCOUNT
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_TR98_LOGIN_ACCOUNT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_TR98_LOGIN_ACCOUNT
endif

ifeq ($(CONFIG_ZYXEL_WEB_WIRELESS_NEW_VERSION_ONE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WEB_WIRELESS_NEW_VERSION_ONE
endif

#Support WiFi Security Mode WEP/WPA/WPA-MIXED/WPA2-PSK
ifeq ($(CONFIG_ZYXEL_WIFI_SUPPORT_WEP_WPA_MIXMODE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WIFI_SUPPORT_WEP_WPA_MIXMODE
endif

ifeq ($(CONFIG_ZYXEL_CONFIG_IGNORE_OWNER_CHECK),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_CONFIG_IGNORE_OWNER_CHECK
endif

## Misc partition
ifeq ($(CONFIG_ZYXEL_SUPPORT_MISC),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SUPPORT_MISC
ifneq ($(strip ${CONFIG_ZYXEL_CUSTOMISED_MISC_NAME}),)
ZYXEL_COMMON_CFLAGS += -DZYXEL_CUSTOMISED_MISC_NAME="'\"$(CONFIG_ZYXEL_CUSTOMISED_MISC_NAME)\"'"
endif
endif

#PPTP Support
ifeq ($(CONFIG_KERNEL_ZYXEL_PPTP_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_PPTP_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_G729_AND_LOGIN_PRIVILEGE_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_G729_AND_LOGIN_PRIVILEGE_CONVERT
endif

ifeq ($(CONFIG_ZYXEL_DISABLE_PMF_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DISABLE_PMF_ROM_CONVERT
endif

#VOICE
ifeq ($(CONFIG_BUILD_ZYXEL_VOICE_CODEC_G729_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_VOICE_CODEC_G729_SUPPORT=1
endif

ifeq ($(CONFIG_ZYXEL_HIDE_USB_PAGE_IN_GUI),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_HIDE_USB_PAGE_IN_GUI
endif

ifeq ($(CONFIG_ZYXEL_ROMCONVERT_GUI_VOIP_SHOW_IOP_FLAGS_IGNORE_CHECK_CONTACT_URL_IN_REGISTER_200OK),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ROMCONVERT_GUI_VOIP_SHOW_IOP_FLAGS_IGNORE_CHECK_CONTACT_URL_IN_REGISTER_200OK
endif

# tr69 data usage
ifeq ($(CONFIG_ZYXEL_TR69_DATA_USAGE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TR69_DATA_USAGE
endif

ifeq ($(CONFIG_ZYXEL_TR69_RELAUNCH),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_TR69_RELAUNCH
endif

ifeq ($(CONFIG_ZYXEL_CHANNEL_SKIP_LIST_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_CHANNEL_SKIP_LIST_ROM_CONVERT
endif

# Fsecure related compiler flag
ifeq ($(CONFIG_ZYXEL_SKIP_IPV6_DNS_ROMCONV_FSECURE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_SKIP_IPV6_DNS_ROMCONV_FSECURE
endif

ifneq ($($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_ZYXEL_PRODUCT)),"")
ZYXEL_COMMON_CFLAGS += -DZYPRJ_$($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_ZYXEL_PRODUCT))=1
endif

# support RDPA
ifeq ($($(shell echo CONFIG_BRCMSDK$(CONFIG_BRCM_SDK_VERSION)_BUILD_RDPA)),y)
ZYXEL_COMMON_CFLAGS += -DSUPPORT_RDPA -DCHIP_$(BRCM_CHIP)
endif

ifeq ($(CONFIG_ZYXEL_CUSTOMIZATION_DEVICELOG),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_CUSTOMIZATION_DEVICELOG
endif

ifeq ($(CONFIG_ZYXEL_CUSTOMIZATION_SYSLOG),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_CUSTOMIZATION_SYSLOG
endif

ifeq ($(ZYXEL),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL=1
endif

ifeq ($(strip ${ZYXEL_RSA_FORMAT}),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_RSA_FORMAT=1
endif

ifeq ($(CONFIG_ZYXEL_MODSW_ZYEE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_MODSW_ZYEE
endif

ifeq ($(CONFIG_ZYXEL_WEB_GUI_SHOW_ZYEE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_WEB_GUI_SHOW_ZYEE
endif

# It is not proper to use package name as the condition
# Should modify in future

#zyinetled
ifeq ($(CONFIG_PACKAGE_kmod-zyinetled),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZYINETLED
endif

# zupnp
ifeq ($(CONFIG_PACKAGE_zupnp),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_PACKAGE_zupnp
endif

# miniupnpd
ifeq ($(CONFIG_PACKAGE_miniupnpd),y)
ZYXEL_COMMON_CFLAGS += -DMINIUPNPD
endif

# RESTful API Server
ifeq ($(CONFIG_PACKAGE_zhttpd_rest),y)
ZYXEL_COMMON_CFLAGS += -DPACKAGE_zhttpd_rest
endif

ifeq ($(CONFIG_PACKAGE_kmod-usb-core),y)
ZYXEL_COMMON_CFLAGS += -DBUILD_PACKAGE_USB
endif

ifeq ($(CONFIG_PACKAGE_zhotplugd),y)
ZYXEL_COMMON_CFLAGS += -DBUILD_PACKAGE_zhotplugd
endif

ifeq ($(CONFIG_PACKAGE_ZyIMS),y)
ZYXEL_COMMON_CFLAGS += -DBUILD_PACKAGE_ZyIMS
ZYXEL_COMMON_CFLAGS += -DCONFIG_PACKAGE_ZyIMS
ZYXEL_COMMON_CFLAGS += -DZYIMS_SUPPORT=1
endif
ifeq ($(CONFIG_ZYXEL_CELLWAN_SUPPORT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_CELLWAN_SUPPORT
endif

ifneq ($(strip $(CONFIG_PACKAGE_zycfgfilter)),)
ZYXEL_COMMON_CFLAGS += -DZYCFGFILTER_SUPPORT
endif

ifeq ($(strip $(CONFIG_PACKAGE_tmsctl)),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ETHOAM_TMSCTL
endif

ifeq ($(CONFIG_PACKAGE_ztr64),y)
ZYXEL_COMMON_CFLAGS += -DZCFG_TR64
endif

ifeq ($(CONFIG_ZYXEL_IGNORE_PASSWORD_CHK_IN_SECURITY_FILTER_TBL),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_IGNORE_PASSWORD_CHK_IN_SECURITY_FILTER_TBL
endif

ifeq ($(CONFIG_ZYXEL_MULTI_WAN),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_MULTI_WAN
endif

ifeq ($(CONFIG_ZYXEL_DEFAULT_ENVRAM_VALUE_RECOMMIT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_DEFAULT_ENVRAM_VALUE_RECOMMIT
endif

#L2TP VPN
ifeq ($(CONFIG_ZYXEL_VPN_CLIENT),y)
ZYXEL_COMMON_CFLAGS += -DCONFIG_ZYXEL_VPN_CLIENT
endif

## MOS ##
ifeq ($(CONFIG_PACKAGE_mos),y)
ZYXEL_COMMON_CFLAGS += -DMOS_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_CONFIG_MAX_WLAN_CLIENT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_CONFIG_MAX_WLAN_CLIENT
endif

#HWDep rom convert
ifeq ($(CONFIG_ZYXEL_HWDEP_ROM_CONVERT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_HWDEP_ROM_CONVERT
endif

ifeq ($(CONFIG_ZYXEL_LED_BLINKING_DEFAULT_DISABLE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_LED_BLINKING_DEFAULT_DISABLE
endif

ifeq ($(CONFIG_ZYXEL_ZY1905_VER_30_SUPPORT_FWUPGRADE),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZY1905_VER_30_SUPPORT_FWUPGRADE
endif

ifeq ($(CONFIG_ZYXEL_ZY1905_VER_30_SUPPORT_RESET_TO_DEFAULT),y)
ZYXEL_COMMON_CFLAGS += -DZYXEL_ZY1905_VER_30_SUPPORT_RESET_TO_DEFAULT
endif

# End of Zyxel Features
########################################################################
###    END: Zyxel common compile flags
########################################################################
ZYXEL_APP_CFLAGS += $(ZYXEL_COMMON_CFLAGS)
ZYXEL_APP_LDFLAGS += $(ZYXEL_COMMON_LDFLAGS)
ZYXEL_LIB_CFLAGS += $(ZYXEL_COMMON_CFLAGS)
ZYXEL_LIB_LDFLAGS += $(ZYXEL_COMMON_LDFLAGS)

########################################################################
###    Enhance compile options
########################################################################
# SECURITY: Support Stack Canaries
# -fstack-protector and -fstack-protector-all are support start from gcc 4.2
# -fstack-protector-strong only support after gcc 4.9
# Econet SDK use gcc 4.6.3
# Broadcom SDK 4.16L.05 use gcc 4.6.2
# Broadcom SDK 5.02L.05 and latter use 5.5.0
# when use -fstack-protector, we may also use --param=ssp-buffer-size=n, default is 8, to control functions with char arrays of at least n(8) bytes
# it means the default setting for "char tmp[2]" will result compile error "stack protector not protecting function: all local arrays are less than 4 bytes long"
ZYXEL_ENHANCE_COMPILE_FLAGS:=
# Check whether .support_ssp exists to assure whether the toolchain supports stack protector
ifneq ("$(wildcard $(TMP_DIR)/.support_ssp)","")
  ifeq ("$(strip ${ZCFG_PLATFORM})","ECONET")
  ZYXEL_ENHANCE_COMPILE_FLAGS += -fstack-protector -Wstack-protector --param=ssp-buffer-size=1
  endif
  ifeq ("$(strip ${ZCFG_PLATFORM})","BROADCOM")
    ifeq ("$(CONFIG_BRCM963xx_SDK_VER_502L07)","y")
    ZYXEL_ENHANCE_COMPILE_FLAGS += -fstack-protector-strong -Wstack-protector
    else
    ZYXEL_ENHANCE_COMPILE_FLAGS += -fstack-protector -Wstack-protector --param=ssp-buffer-size=1
    endif
  endif
endif
#end of ifneq ("$(wildcard $(TMP_DIR)/.support_libssp)","")
# end of Support Stack Canaries

# SECURITY: FORTIFY_SOURCE
ZYXEL_ENHANCE_COMPILE_FLAGS += -D_FORTIFY_SOURCE=1 -O1

# SECURITY:  RELRO (read only relocation)
# Partial RELRO, gcc default have this setting
#ZYXEL_COMMON_CFLAGS += -Wl,-z,relro
# Full RELRO
ZYXEL_ENHANCE_COMPILE_FLAGS += -Wl,-z,relro,-z,now

# SECURITY: PIE (Position Independent Executable)
# use PIE with level 1
#ZYXEL_ENHANCE_COMPILE_FLAGS += -fpie -pie
# use PIE with level 2
ZYXEL_APP_CFLAGS += $(ZYXEL_ENHANCE_COMPILE_FLAGS) -fPIE -pie
ZYXEL_APP_LDFLAGS += $(ZYXEL_ENHANCE_COMPILE_FLAGS) -fPIE -pie
# libraries use PIC, not PIE
ZYXEL_LIB_CFLAGS += $(ZYXEL_ENHANCE_COMPILE_FLAGS)
ZYXEL_LIB_LDFLAGS += $(ZYXEL_ENHANCE_COMPILE_FLAGS)

endif #__zyxel_rules_inc
