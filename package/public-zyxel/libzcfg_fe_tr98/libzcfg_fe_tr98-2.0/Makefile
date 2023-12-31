CURRENT_DIR = $(shell pwd)
COMMON_ZCFG_INCLUDE_DIR = $(CURRENT_DIR)/../../../package/private/zyxel/zcfg/include
LIB_PATH = -L$(USRLIBDIR) -L$(INSTALL_DIR)/lib/public -L$(INSTALL_DIR)/lib/private
LINK_LIB = -ljson -lzcfg_msg -lzcfg_fe_rdm_access -lzcfg_fe_rdm_string -lzcfg_fe_rdm_struct -lzlog -lzos
INC_PATH = -I$(TOOLCHAIN)/include -I$(COMMON_ZCFG_INCLUDE_DIR) -I.
OBJ_FILES = wanDev.o wanDev_api.o zyExt.o diag.o devInfo.o \
				devTime.o root.o mgmtSrv.o lanDev.o l2bridge.o \
				l3fwd.o lanConfSec.o firewall.o schedule.o voice.o \
				ipv6Spec.o ispService.o



SSL_LIBS = -lssl -lcrypto
LINK_LIBS += $(SSL_LIBS)

ifeq ($(CONFIG_ZCFG_BE_MODULE_QOS),y)
OBJ_FILES += qos.o
endif

ifeq ($(CONFIG_ZCFG_BE_MODULE_GRE_TUNNEL),y)
ifeq ($(CONFIG_ZCFG_BE_MODULE_GRE_TUNNEL_IFACE),y)
OBJ_FILES += xgre.o
endif
endif

ifeq ($(CONFIG_ZYXEL_ONECONNECT),y)
LINK_LIB += -lsqlite3
ifeq ($(CONFIG_ZCFG_BE_MODULE_ZYXEL_ONECONNECT),y)
OBJ_FILES += oneConnect.o
endif
endif

ifeq ($(CONFIG_PACKAGE_zxmppc),y)
OBJ_FILES += xmpp.o
endif

ifeq ($(CONFIG_ZYXEL_MODSW_ZYEE),y)
OBJ_FILES += zcfg_fe_tr98_ZyEE.o
endif
OBJ_FILES += zcfg_fe_msg.o
OBJ_FILES += zcfg_fe_tr98.o

LDFLAGS += $(LIB_PATH) $(LINK_LIB)
CFLAGS += $(INC_PATH)
# -DZCFG_MAPPING_DEBUG_SYSLOG -DZCFG_MAPPING_DEBUG_STDLOG
CFLAGS += -DZCFG_DYNAMIC_NAMEMAPPING -DZCFG_MAPPING_DEBUG_SYSLOG -DZCFG_MAPPING_DEBUG_STDLOG
CFLAGS += -DIPV6INTERFACE_PROFILE -DDHCPV6CLIENT_PROFILE -DIPV6RD_PROFILE -DROUTERADVERTISEMENT_PROFILE -DIPV6SERVER_PROFILE
CFLAGS += -DZCFG_DYNAMIC_NAMEMAPPING -DZCFG_PARM_NAMEMAPPING -DL3IPV6FWD -DROUTEINFO_INTERFACE
CFLAGS += -DZYXEL_EXT=1
CFLAGS += -DZCFG_APPLY_MULTIOBJSET_ON_SESSIONCOMPLETE -DLANIPALIAS

ifeq ("$(strip ${ZCFG_PLATFORM})","ECONET")
CFLAGS += -DECONET_PLATFORM
endif

ifeq ("$(strip ${ZCFG_PLATFORM})","MTK")
CFLAGS += -DMTK_PLATFORM
endif

ifeq ($(CONFIG_ZYXEL_ECONET_OPERATION_MODE),y)
CFLAGS += -DZYXEL_ECONET_OPERATION_MODE
endif

ifeq ($(CONFIG_ZCFG_APPLY_RPC_METHOD_AND_SUBSEQUENT_ROUT),y)
CFLAGS += -DZCFG_APPLY_RPC_METHOD_AND_SUBSEQUENT_ROUT
endif

ifeq ($(CONFIG_ZCFG_TR098181_OBJECT_MAPPING_NUM_NAME_CONVERT),y)
CFLAGS += -DTR098181_OBJECT_MAPPING_NUM_NAME_CONVERT
endif

#ifeq ($(CONFIG_ZCFG_TR181_RPC_OBJECT_HANDLE_ROUT),y)
CFLAGS += -DZCFG_TR181_RPC_OBJECT_HANDLE_ROUT
#endif
#CFLAGS += -DCETIN

#Generic
ifneq ($(strip $(CONFIG_PACKAGE_ZyIMS)),)
CFLAGS += -DCONFIG_PACKAGE_ZyIMS
endif

ifeq ($(CONFIG_XPON_SUPPORT),y)
CFLAGS += -DCONFIG_XPON_SUPPORT
endif

ifeq ($(strip $(CONFIG_ABUU_CUSTOMIZATION_WLAN_SCHEDULER)),y)
CFLAGS += -DABUU_CUSTOMIZATION_WLAN_SCHEDULER
endif

ifeq ($(strip $(CONFIG_PACKAGE_tmsctl)),y)
CFLAGS += -DZYXEL_ETHOAM_TMSCTL
endif

ifeq ($(strip $(CONFIG_ZYXEL_DL_DIAG_CALCULATION)),y)
CFLAGS += -DZYXEL_DL_DIAG_CALCULATION
endif

ifeq ($(strip $(CONFIG_ZYXEL_DIAG_IPERF_SUPPORT)),y)
CFLAGS += -DZYXEL_DIAG_IPERF_SUPPORT
endif

ifeq ($(strip $(CONFIG_ZYXEL_TR69_SUPPLEMENTAL_ACS)),y)
CFLAGS += -DZYXEL_TR69_SUPPLEMENTAL_ACS
endif

#One Connect
ifeq ($(CONFIG_ZYXEL_ONECONNECT),y)
CFLAGS += -DONECONNECT
endif
ifeq ($(CONFIG_ZYXEL_HOSTPOLLING),y)
CFLAGS += -DHOSTPOLLING
endif

#Ap Steering
ifeq ($(CONFIG_ZYXEL_AP_STEERING),y)
CFLAGS += -DZYXEL_AP_STEERING
endif

#ACEN Greece
ifeq ($(CONFIG_WIND_Greece_DHCPv6_Client_NTP_Option),y)
CFLAGS += -DWIND_Greece_DHCPv6_Client_NTP_Option
endif

#Proximity Sensor
ifeq ($(CONFIG_PROXIMITY_SENSOR_SUPPORT),y)
CFLAGS += -DPROXIMITY_SENSOR_SUPPORT
endif

#support ZYXEL RUNNINGWAN interface for tr098 parameter
ifeq ($(CONFIG_ZYXEL_RUNNINGWAN_CUSTOMIZATION),y)
CFLAGS += -DZYXEL_RUNNINGWAN_CUSTOMIZATION
endif

#support SFP module
ifeq ($(CONFIG_ZYXEL_SFP_MODULE_SUPPORT),y)
CFLAGS += -DZYXEL_SFP_MODULE_SUPPORT
endif

ifeq ($(strip $(ZYXEL)),y)
CFLAGS += -DZYXEL_EXT=1
endif

ifeq ($(CONFIG_ZyXEL_IPP_PRINTSERVER),y)
CFLAGS += -DZyXEL_IPP_PRINTSERVER
endif

ifeq ($(CONFIG_ZyXEL_DHCP_OPTION125),y)
CFLAGS += -DZyXEL_DHCP_OPTION125
endif

ifeq ($(CONFIG_ZyXEL_Online_Firmware_Upgrade),y)
CFLAGS += -DZyXEL_Online_Firmware_Upgrade
endif

ifeq ($(CONFIG_ZYXEL_WEB_GUI_ONLINE_FW_UPGRADE_VIA_URL),y)
CFLAGS += -DZYXEL_WEB_GUI_ONLINE_FW_UPGRADE_VIA_URL
endif

#TR69 Data Usage
ifeq ($(CONFIG_ZYXEL_TR69_DATA_USAGE),y)
CFLAGS += -DZYXEL_TR69_DATA_USAGE
endif

#Support WiFi Security Mode WEP/WPA/WPA-MIXED/WPA2-PSK
ifeq ($(CONFIG_ZYXEL_WIFI_SUPPORT_WEP_WPA_MIXMODE),y)
CFLAGS += -DZYXEL_WIFI_SUPPORT_WEP_WPA_MIXMODE
endif

ifeq ($(CONFIG_ZYXEL_WIFI_SUPPORT_WPA_ONLY_MODE),y)
CFLAGS += -DZYXEL_WIFI_SUPPORT_WPA_ONLY_MODE
endif

#CAT/TOT
ifeq ($(CONFIG_ZYXEL_TR69_REMOTE_MANAGE_SEPARATE_PARAMETER),y)
CFLAGS += -DZYXEL_TR69_REMOTE_MANAGE_SEPARATE_PARAMETER
endif

#CBT
ifeq ($(CONFIG_CBT_CUSTOMIZATION),y)
CFLAGS += -DCBT_CUSTOMIZATION
endif

ifeq ($(CONFIG_ZYXEL_WEB_WIRELESS_NEW_VERSION_ONE),y)
CFLAGS += -DZYXEL_WEB_WIRELESS_NEW_VERSION_ONE
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_TR098_BRCM_BONDING_LINE),y)
CFLAGS += -DZYXEL_SUPPORT_TR098_BRCM_BONDING_LINE
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_TR98_LOGIN_ACCOUNT),y)
CFLAGS += -DZYXEL_SUPPORT_TR98_LOGIN_ACCOUNT
endif

ifeq ($(CONFIG_ZYXEL_BLACK_LIST_CHARACTERS_FOR_WIFI_PASSPHRASE),y)
CFLAGS += -DZYXEL_BLACK_LIST_CHARACTERS_FOR_WIFI_PASSPHRASE
endif

# TWAMP
ifeq ($(CONFIG_PACKAGE_OWAMP),y)
CFLAGS += -DCONFIG_PACKAGE_OWAMP
endif

#define EASYMESH
ifeq ($(CONFIG_ZYXEL_EASYMESH),y)
CFLAGS += -DZYXEL_EASYMESH
export CONFIG_ZYXEL_EASYMESH
endif
ifeq ($(CONFIG_ZYXEL_EASYMESH_R2),y)
CFLAGS += -DZYXEL_EASYMESH_R2
endif

#Sunrise
ifneq ($(strip $(CONFIG_SUNRISE_STB_PROVISION)),)
CFLAGS += -DSUNRISE_STB_PROVISION
endif
ifneq ($(strip $(CONFIG_SUNRISE_TR98_CUSTOMIZATION)),)
CFLAGS += -DSUNRISE_TR98_CUSTOMIZATION
endif
ifeq ($(CONFIG_SUNRISE_RANDOM_PASSWORD),y)
CFLAGS += -DSUNRISE_RANDOM_PASSWORD
endif
ifeq ($(CONFIG_SUNRISE_BRIDGE_INDEX_CUSTOMIZATION),y)
CFLAGS += -DSUNRISE_BRIDGE_INDEX_CUSTOMIZATION
endif
ifeq ($(CONFIG_ZCFG_RUNNING_WANDEV_INDEX_CUSTOMIZATION),y)
CFLAGS += -DZCFG_RUNNING_WANDEV_INDEX_CUSTOMIZATION
endif
ifeq ($(CONFIG_ABWW_STB_PROVISION_Y2020),y)
CFLAGS += -DABWW_STB_PROVISION_Y2020
endif
#SuperOnline
ifeq ($(CONFIG_SOL_TR69_AUTO_CHANGE_DHCP_POOL),y)
CFLAGS += -DSOL_TR69_AUTO_CHANGE_DHCP_POOL
endif
ifeq ($(CONFIG_SOL_TR69_FIREWALL_CONTROL),y)
CFLAGS += -DSOL_TR69_FIREWALL_CONTROL
endif
ifeq ($(CONFIG_SOL_TR69_3G_Backup),y)
CFLAGS += -DSOL_TR69_3G_Backup
endif
ifeq ($(CONFIG_SOL_TR69_TRUSTDOMAIN),y)
CFLAGS += -DSOL_TR69_TRUSTDOMAIN
endif
ifeq ($(CONFIG_SOL_TR69_LOGINACCOUNT),y)
CFLAGS += -DSOL_TR69_LOGINACCOUNT
endif
ifeq ($(CONFIG_SOL_TR69_NO_LAN_HOST),y)
CFLAGS += -DSOL_TR69_NO_LAN_HOST
endif

#ABNL
ifeq ($(CONFIG_ABNL_CUSTOMIZATION),y)
CFLAGS += -DCONFIG_ABNL_CUSTOMIZATION
endif

#ACEN
ifeq ($(CONFIG_BUILD_ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE),y)
CFLAGS += -DZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_WL_WPA2_EAP),y)
CFLAGS += -DSUPPORT_WL_WPA_EAP
CFLAGS += -DWIFISECURITY_AUTH_WITH_EAP
endif

## Wind ##
ifeq ($(CONFIG_ACEN_CUSTOMIZATION),y)
CFLAGS += -DZYXEL_ACEN_CUSTOMIZATION
endif

ifeq ($(CONFIG_ACEN_CUSTOMIZATION),y)
CFLAGS += -DACEN_CUSTOMIZATION=1
endif

# Bandwidth Improvement
ifeq ($(CONFIG_ZYXEL_BANDWIDTH_IMPROVEMENT),y)
CFLAGS += -DZYXEL_BANDWIDTH_IMPROVEMENT=1
endif

ifeq ($(CONFIG_ZYXEL_WEB_GUI_HOST_PRIORITY_STATICIP),y)
CFLAGS += -DZYXEL_WEB_GUI_HOST_PRIORITY_STATICIP=1
endif

#ISKON
ifeq ($(CONFIG_USE_OLD_VOIP_PREFIX),y)
CFLAGS += -DUSE_OLD_VOIP_PREFIX
endif
ifeq ($(CONFIG_ISKON_CUSTOMIZATION),y)
CFLAGS += -DISKON_CUSTOMIZATION
endif

#TISCALI	
ifeq ($(strip $(CONFIG_TISCALI_CUSTOMIZATION)),y)
CFLAGS += -DTISCALI_CUSTOMIZATION
endif

ifeq ($(CONFIG_ZYXEL_SP_DOMAIN_TIMER),y)
CFLAGS += -DZYXEL_SP_DOMAIN_TIMER
endif

#ELISA
ifeq ($(CONFIG_ELISA_TR69_WANDSL_CUSTOMIZATION),y)
CFLAGS += -DELISA_TR69_WANDSL_CUSTOMIZATION
endif

ifeq ($(CONFIG_ELISA_CUSTOMIZATION),y)
CFLAGS += -DELISA_CUSTOMIZATION
endif

#GFiber
ifeq ($(CONFIG_GFIBER_CUSTOMIZATION),y)
CFLAGS += -DGFIBER_CUSTOMIZATION
endif

#EasyMesh
ifeq ($(CONFIG_ZYXEL_EASYMESH),y)
    CFLAGS += -DZYXEL_EASYMESH
endif

#SONiQ used but for all projects
CFLAGS += -DTOTAL_INTERFACE_24G=$(CONFIG_ZYXEL_WIFI_NUM_OF_24G_SSID_INTERFACE)
CFLAGS += -DTOTAL_INTERFACE_5G=$(CONFIG_ZYXEL_WIFI_NUM_OF_5G_SSID_INTERFACE)

#ONESSID
ifeq ($(CONFIG_ZYXEL_ONESSID),y)
    CFLAGS += -DZYXEL_ONESSID
endif

#VMG1312-T20A for BRAZIL
ifeq ($(CONFIG_BRAZIL_CUSTOMIZATION),y)
CFLAGS += -DBRAZIL_CUSTOMIZATION=1
endif

#ZYXEL_WIFI_SingleSKU
ifeq ($(CONFIG_ZYXEL_WIFI_SingleSKU),y)
CFLAGS += -DZYXEL_WIFI_SingleSKU=1
endif

#VOICE
ifeq ($(strip $(CONFIG_BUILD_ZYXEL_VOICE_CONFIG_TR069_SIP_PHONE_MAPPING_BY_STD_PHY_REFERENCE_LIST)),y)
CFLAGS += -DZYXEL_VOICE_CONFIG_TR069_SIP_PHONE_MAPPING_BY_STD_PHY_REFERENCE_LIST=1
endif

ifeq ($(strip $(CONFIG_BUILD_ZYXEL_VOICE_RFC3263_DNS_NAPTR_SUPPORT)),y)
CFLAGS += -DZYXEL_VOICE_RFC3263_DNS_NAPTR_SUPPORT
endif

ifeq ($(CONFIG_ZCFG_ABANDON_NO_TR181_MAPPING_PARM),y)
CFLAGS += -DZCFG_ABANDON_NO_TR181_MAPPING_PARM
endif

ifeq ($(CONFIG_PACKAGE_ztr64),y)
CFLAGS += -DZCFG_TR64
endif

#Landing Page
ifeq ($(CONFIG_ZYXEL_LANDING_PAGE_FEATURE),y)
CFLAGS += -DZYXEL_LANDING_PAGE_FEATURE
endif

ifeq ($(CONFIG_ZCFG_TR98_PARAM_GUARD),y)
CFLAGS += -DZCFG_TR98_PARAM_GUARD
endif

#DMZ Management
ifeq ($(CONFIG_ZYXEL_SUPPORT_DMZ_MANAGEMENT),y)
CFLAGS += -DZYXEL_SUPPORT_DMZ_MANAGEMENT
endif

ifeq ($(CONFIG_ZCFG_QUERY_TR98_PARM_ATTR_LIST),y)
CFLAGS += -DZCFG_QUERY_TR98_PARM_ATTR_LIST
endif

ifeq ($(CONFIG_ZCFG_LOG_USE_DEBUGCFG),y)
CFLAGS += -DZCFG_LOG_USE_DEBUGCFG
CFLAGS += -DZCFG_ZYUTIL_DEBUG_API
CFLAGS += -DZCFG_TR98_LOG_USE_DEBUGCFG
endif

ifeq ($(CONFIG_ZYXEL_ELIMINATE_DHCP_LEASE),y)
CFLAGS += -DZYXEL_ELIMINATE_DHCP_LEASE
endif

ifeq ($(CONFIG_ZYXEL_WLAN_MAXBITRATE),y)
CFLAGS += -DZYXEL_WLAN_MAXBITRATE
endif

#Support tr98 IPv6 MAP
ifeq ($(CONFIG_ZYXEL_IPV6_MAP),y)
CFLAGS += -DZYXEL_IPV6_MAP
endif

#Support tr98 Ipv6 Specific
ifeq ($(CONFIG_ZYXEL_TR98_IPV6SPECIFIC),y)
CFLAGS += -DZYXEL_IPV6SPEC
endif

#Support tr98 GRE
ifeq ($(CONFIG_ZYXEL_GRE),y)
CFLAGS += -DZYXEL_GRE_SUPPORT
endif

ifeq ($(CONFIG_ZCFG_RPC_REQUEST_ADDITIONS),y)
CFLAGS += -DZCFG_RPC_REQUEST_ADDITIONS
endif

ifeq ($(CONFIG_ZYXEL_ACS_WPS_ACTIVATION),y)
CFLAGS += -DZYXEL_ACS_WPS_ACTIVATION
endif

ifeq ($(CONFIG_ZYXEL_AVAST_AGENT_SUPPORT),y)
CFLAGS += -DAVAST_AGENT_PACKAGE
endif

ifeq ($(CONFIG_ZYXEL_SFP_POWER_MGMT),y)
CFLAGS += -DZYXEL_SFP_POWER_MGMT
endif

#XMPP
ifeq ($(CONFIG_PACKAGE_zxmppc),y)
CFLAGS += -DZYXEL_XMPP
endif

#ABWO
ifeq ($(strip $(CONFIG_ABWO_CUSTOMIZATION)),y)
    CFLAGS += -DABWO_CUSTOMIZATION
endif

#PPPoE Service
ifeq ($(CONFIG_ZYXEL_PPPoE_SERVICE_OPTION),y)
CFLAGS += -DZYXEL_PPPoE_SERVICE_OPTION
endif

#lifemote
ifeq ($(CONFIG_ZYXEL_SUPPORT_LIFEMOTE),y)
CFLAGS += -DZYXEL_SUPPORT_LIFEMOTE
endif

ifeq ($(CONFIG_X_ZYXEL_SUPPORT_LIFEMOTE),y)
CFLAGS += -DX_ZYXEL_SUPPORT_LIFEMOTE
endif

#OPAL Extender
ifeq ($(CONFIG_ZYXEL_OPAL_EXTENDER),y)
CFLAGS += -DZYXEL_OPAL_EXTENDER
endif

ifeq ($(CONFIG_TT_CUSTOMIZATION_V6),y)
CFLAGS += -DTT_CUSTOMIZATION_V6
endif

ifeq ($(CONFIG_TT_CUSTOMIZATION_V6_TTNET),y)
CFLAGS += -DTT_CUSTOMIZATION_V6_TTNET
endif

# bridge parameters hidden
ifeq ($(CONFIG_ZYXEL_OPAL_BRIDGE_ACSPARAMETERS_HIDDEN),y)
CFLAGS += -DZYXEL_OPAL_BRIDGE_ACSPARAMETERS_HIDDEN
endif

#TT
ifeq ($(CONFIG_TT_DSL_BINDING),y)
CFLAGS += -DCONFIG_TT_DSL_BINDING
endif

ifeq ($(CONFIG_MSTC_TTNET_MULTI_USER),y)
CFLAGS += -DMSTC_TTNET_MULTI_USER
endif

ifeq ($(CONFIG_MSTC_RETAIL_MULTI_USER),y)
CFLAGS += -DMSTC_RETAIL_MULTI_USER
endif

ifeq ($(CONFIG_TT_PORTMIRROR),y)
CFLAGS += -DCONFIG_TT_PORTMIRROR
endif

ifeq ($(CONFIG_TT_PORTMIRROR_E),y)
CFLAGS += -DCONFIG_TT_PORTMIRROR_E
endif

ifeq ($(CONFIG_TT_PACKETCAPTURE),y)
CFLAGS += -DCONFIG_TT_PACKETCAPTURE
endif

ifeq ($(CONFIG_TENDER_TT_FEATURE),y)
CFLAGS += -DTENDER_TT_FEATURE
endif

ifeq ($(CONFIG_ZYXEL_TTNET_TR69ALG),y)
CFLAGS += -DZYXEL_TTNET_TR69ALG
endif

ifeq ($(CONFIG_ZYXEL_HOMEPLUG_DEVICE_DISCOVER),y)
CFLAGS += -DZYXEL_HOMEPLUG_DEVICE_DISCOVER
endif

ifeq ($(CONFIG_TT_CUSTOMIZATION_TR069),y)
CFLAGS += -DCONFIG_TT_CUSTOMIZATION_TR069
endif

ifeq ($(CONFIG_ZYXEL_TT_WPSSETUPLOCK),y)
CFLAGS += -DZYXEL_TT_WPSSETUPLOCK
endif

ifeq ($(CONFIG_ZYXEL_SUPPORT_QUANTWIFI),y)
CFLAGS += -DZYXEL_SUPPORT_QUANTWIFI
endif

ifeq ($(CONFIG_ZYXEL_WLAN_BLOCK_OPEN),y)
CFLAGS += -DZYXEL_WLAN_BLOCK_OPEN
endif

ifeq ($(CONFIG_ZYXEL_CUSTOMIZATION_DEVICELOG),y)
CFLAGS += -DCONFIG_ZYXEL_CUSTOMIZATION_DEVICELOG
endif

ifeq ($(CONFIG_ZYXEL_CONFIG_MAX_WLAN_CLIENT),y)
CFLAGS += -DZYXEL_CONFIG_MAX_WLAN_CLIENT
endif

ifeq ($(CONFIG_TT_CUSTOMIZATION),y)
CFLAGS += -DCONFIG_TT_CUSTOMIZATION
endif

ifeq ($(CONFIG_ZYXEL_TR140),y)
CFLAGS += -DCONFIG_ZYXEL_TR140
endif

ifeq ($(CONFIG_ZYXEL_MODSW_ZYEE),y)
CFLAGS += -DCONFIG_ZYXEL_MODSW_ZYEE
endif

ifeq ($(CONFIG_ZYXEL_IGMPDIAG),y)
CFLAGS += -DZYXEL_IGMPDIAG
endif

ifeq ($(CONFIG_ZYXEL_TTNET_EDNS),y)
CFLAGS += -DZYXEL_TTNET_EDNS
endif

ifeq ($(CONFIG_ZYXEL_TT_WAN_CONN_DIAG),y)
CFLAGS += -DZYXEL_TT_WAN_CONN_DIAG
endif

ifeq ($(CONFIG_ZYXEL_CUSTOMIZATION_SYSLOG),y)
CFLAGS += -DZYXEL_CUSTOMIZATION_SYSLOG
endif

#ABUU
ifeq ($(CONFIG_ABUU_CUSTOMIZATION),y)
CFLAGS += -DABUU_CUSTOMIZATION
endif

#ABPY
ifeq ($(CONFIG_ABPY_CUSTOMIZATION),y)
CFLAGS += -DABPY_CUSTOMIZATION
endif

ifeq ($(CONFIG_ABUU_CUSTOMIZATION_MULTIPLE_CONFIG),y)
CFLAGS += -DABUU_CUSTOMIZATION_MULTIPLE_CONFIG
endif

ifeq ($(CONFIG_ZYXEL_DISABLE_WIFI_HW_BTN),y)
CFLAGS += -DZY_DISABLE_WIFI_HW_BTN
endif

ifeq ($(CONFIG_ZYXEL_WIFI_HW_BUTTON_SWITCH),y)
CFLAGS += -DZYXEL_WIFI_HW_BUTTON_SWITCH
endif

ifeq ($(CONFIG_ZYXEL_CELLWAN_SUPPORT),y)
CFLAGS += -DCONFIG_ZYXEL_CELLWAN_SUPPORT
endif

ifeq ($(CONFIG_ZYXEL_MULTI_WAN),y)
CFLAGS += -DCONFIG_ZYXEL_MULTI_WAN
endif

ifeq ($(CONFIG_ZYXEL_MEMORY_LEAK_DETECT),y)
CFLAGS += -DZCFG_MEMORY_LEAK_DETECT
endif

ifeq ($(CONFIG_ZYXEL_TTNET_FIREWALL_WANINTERFACE),y)
CFLAGS += -DZYXEL_TTNET_FIREWALL_WANINTERFACE
endif


ifeq ($(CONFIG_TT_HGW),y)
CFLAGS += -DTT_HGW
endif

CFLAGS += $(ZFLAGS)

#ABZQ
ifeq ($(CONFIG_ABZQ_CUSTOMIZATION),y)
CFLAGS += -DABZQ_CUSTOMIZATION_WLAN_INFO
endif

ifeq ($(CONFIG_PACKAGE_ipk-pkg),y)
CFLAGS += -DCONFIG_IPK_PKG
endif

CHK_CFLAGS = $(CFLAGS)
CHK_CFLAGS:=$(filter -D%,$(CHK_CFLAGS))


.PHONY : libzcfg_fe_tr98

all: clean tr98_mapping_tb_chk libzcfg_fe_tr98

.c.o:
	$(CC) $(CFLAGS) -fPIC -Wall -std=gnu99 -c $< -o $@

tr98_mapping_tb_chk:
	gcc $(CHK_CFLAGS) -I./ tr98_handle_tb_tran.c -o tr98_handle_tb_tran
	./tr98_handle_tb_tran
	gcc $(CHK_CFLAGS) $(INC_PATH) -I$(STAGING_DIR)/usr/include tr98_handle_tb_chk.c -o tr98_handle_tb_chk
	./tr98_handle_tb_chk

libzcfg_fe_tr98: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -shared -o libzcfg_fe_tr98.so $(OBJ_FILES)

install:
	install -m 755 libzcfg_fe_tr98.so $(INSTALL_DIR)/lib/public
	install -m 666 zcfg_fe_tr98.h $(COMMON_ZCFG_INCLUDE_DIR)

clean:
	rm -rf *.o
	rm -rf *.so
	rm -rf $(COMMON_ZCFG_INCLUDE_DIR)/zcfg_fe_tr98.h


