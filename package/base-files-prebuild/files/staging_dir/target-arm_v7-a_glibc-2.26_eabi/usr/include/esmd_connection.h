#ifndef _ESMD_CONNECTION_H
#define _ESMD_CONNECTION_H
#include "zcfg_rdm_obj.h"

#include "esmd_wrapper.h"
/*
   For interface grouping filter
*/
#define ACT_CONTINUE 0
#define ACT_REDIRECT 1
#define ACT_ACCEPT 2

#ifdef ZYXEL_ECONET_OPERATION_MODE
#define ROUTERMODE 		0
#define APMODE			1
#define REPEATERMODE	2
#endif

#define MAX_MAC_NUM_LENGTH 6

#define cmp_mode_str(x, y) (strcmp((x), (y)) == 0)
#define is_exact_mode(x) cmp_mode_str(((x)->SourceMACFromVendorClassIDMode), "Exact")
#define is_substring_mode(x) cmp_mode_str(((x)->SourceMACFromVendorClassIDMode), "Substring")
#define is_prefix_mode(x) cmp_mode_str(((x)->SourceMACFromVendorClassIDMode), "Prefix")
#define is_suffix_mode(x) cmp_mode_str(((x)->SourceMACFromVendorClassIDMode), "Suffix")

#define have_option_srcmac_filter(x) (strcmp((x)->SourceMACAddressFilterList, "") != 0)
#define have_option_60_filter(x) (strcmp((x)->SourceMACFromVendorClassIDFilter, "") != 0)
#define have_option_61_filter(x) (strcmp((x)->SourceMACFromClientIDFilter, "") != 0)
#define have_option_125_filter(x) (strcmp((x)->X_ZYXEL_SourceMACFromVSIFilter, "") != 0)

#ifdef ZYXEL_SIP_DELAYTIMES
void SipDelayTimer(int startWaitTime);
#endif
bool checkSfpLinkUp (void);
int getSfpDelayTimes(int delayType);

//zcfgRet_t esmdWanIpConnectionUp(objIndex_t *, bool);
void esmdProcessPingMsg(char *);
void esmdProcessPingSvrsMsg(char *);
void esmdProcessTracertMsg(char *msg);
zcfgRet_t esmdWanIpConnectionUp(objIndex_t *);
#if 0   /* Bell, avoid zcmd apply config thread and esmd thread dead lock issue, 2017-12-01-13:36:15*/
zcfgRet_t esmdWanPppConnectionUp(objIndex_t *, bool);
#endif
zcfgRet_t esmdWanPppConnect(objIndex_t *, bool isConnect, uint8_t clientEid, uint32_t clientPid);
zcfgRet_t esmdWanIpRenew(objIndex_t *, bool isRenew, uint8_t clientEid, uint32_t clientPid);
#if 1 //ZyXEL, Renew add WAN release/renew command, Albert
zcfgRet_t esmdWanPppConnected(objIndex_t *, bool isConnect, uint8_t clientEid, uint32_t clientPid);
#endif
#if 1 //__ZYXEL__, Mark
zcfgRet_t processDhcpcMsg(char *msg, int type);
#else
zcfgRet_t processDhcpcMsg(char *msg);
#endif
zcfgRet_t restartDhcpc(char *msg);
zcfgRet_t processPppdMsg(char *msg);
#ifdef CONFIG_TT_CUSTOMIZATION_TR069 
zcfgRet_t processPppdUsernameMsg(char *msg);
#endif

zcfgRet_t processRaInfo(char *msg);
#ifdef OI_CUSTOMIZATION
zcfgRet_t processRaIPv6Lost();
#endif /* OI_CUSTOMIZATION */
zcfgRet_t processDhcp6cMsg(char *msg);
#if defined(ECONET_PLATFORM) && defined(ZYXEL_DHCPV6S_LEASE)
zcfgRet_t processDhcp6sMsg(char *msg);
#endif
#ifdef ZYXEL_DHCPV6C_OPTION 
zcfgRet_t processDhcp6cMsgClientServer(char *msg);
zcfgRet_t processDhcp6cMsgOption(char *msg);
#endif
void esmdProcessNslookupMsg(char *msg);
void esmdProcessAtmF5LoMsg(char *msg);
void esmdProcessAtmF4LoMsg(char *msg);

#ifdef ACEN_CUSTOMIZATION
void sipWanCheckHandle();
#endif

#ifdef ZYXEL_CUSTOMIZATION_SYSLOG	
void processSyslogUploadCompletion(zcfgMsg_t *msg);
void processSyslogUploadFail(zcfgMsg_t *msg);
void processSyslogTimeoutChange(zcfgMsg_t *msg);
void checksyslog(void);
void processSyslogTimeout(void);
#endif

void esmdSetDhcp6cObj(char *, bool , bool);

#ifdef MSTC_TTNET_MULTI_USER /*__MSTC__, Linda, CPE User Definitions and Rights. */
void processGetUserInfo(char *msg);
#endif	/*__MSTC__, Linda, CPE User Definitions and Rights_END. */

#ifdef ZYXEL_SP_DOMAIN_TIMER
void SPDomainTimerHandle(uint32_t msg_type);
#endif

#ifdef CONFIG_ZCFG_BE_MODULE_ZYXEL_SFP_POWER_MGMT
void esmdSFPMgmtTimerHandle(uint32_t msg_type);
#endif

#if ZYXEL_CONFIGURABLE_WWANBACKUP_WAIT_TIME
void cellularBackupTimerHandle(char *ipIfacePath, uint32_t msg_type);
#endif

zcfgRet_t esmdProcessDhcpdOption(const char *msg, uint8_t clientEid, uint32_t clientPid);
#ifdef ZYXEL_AUTO_REMOVE_INTFGUP_CRIT_OPT60_WIFI_INTF
zcfgRet_t esmdProcessDelIntfGupPort(const char *msg, uint8_t clientEid, uint32_t clientPid);
#endif

/* move to esmd_wrapper.h
void zyEnableWifiLED();
*/
void esmdDlDiagComplete(char *msg);
void esmdUlDiagComplete(char *msg);

#ifdef CONFIG_TT_CUSTOMIZATION
void esmdWanConnDiagComplete(char *msg);
#endif

/* Fakeroot for "sys atsh" */
#define ZCFG_CONFIG_DIR "/data"
#define ZCFG_CONFIG_FILE "zcfg_config.json"
#define ZCFG_CONFIG_FILE_PATH ZCFG_CONFIG_DIR"/"ZCFG_CONFIG_FILE

#ifdef ZYXEL_ROMFILE_CHECKSUM_DEFAULT_FILE
#define ZCFG_CONFIG_FILE_TMP_PATH "/tmp/zcfg_config.json"
#endif

#define ZCFG_DATA_FILE_NEME "zcfg_config.json" //used for zcmd, don't remove it.

unsigned short zyxelFileChecksum(const char *path);
void processAtshGetRomfileCksum(uint8_t clientEid, uint32_t clientPid);
void processFakeroot_Command_Reply(uint8_t clientEid, uint32_t clientPid);

#endif // _ESMD_CONNECTION_H
