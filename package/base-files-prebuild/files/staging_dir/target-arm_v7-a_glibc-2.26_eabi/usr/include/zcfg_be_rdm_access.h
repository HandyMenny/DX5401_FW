#ifndef _ZCFG_BE_RDM_ACCESS_H
#define _ZCFG_BE_RDM_ACCESS_H

#include "zos_api.h"

#define ZCMD_SET_NORMAL		0
#define ZCMD_SET_WITHOUT_APPLY		1
#define ZCMD_GET_NORMAL		1 << 1
#define ZCMD_GET_WITHOUT_UPDATE	1 << 2
#define ZCMD_ADD_NORMAL		1 << 3
#define ZCMD_ADD_WITHOUT_APPLY		1 << 4
#define ZCMD_PARTIAL_SET		1 << 5

#define ZCMD_QUERY_OBJ_EXIST		1 << 6

#define ZCMD_RPC_REQUEST_ADDITIONS	1 << 8

#define ZCMD_UTILIZE_DISTINCT_VALUE	1 << 11
#define ZCMD_RE_APPLY			1 << 12

#ifdef ZCFG_MEMORY_LEAK_DETECT

#define zcfgBeObjGetNext(oid, iid, obj) _zcfgBeObjGetNext(oid, iid, obj, __FILE__, __LINE__)
#define zcfgBeObjGetNextWithoutUpdate(oid, iid, obj) _zcfgBeObjGetNextWithoutUpdate(oid, iid, obj, __FILE__, __LINE__)
#define zcfgBeObjGet(oid, iid, obj) _zcfgBeObjGet(oid, iid, obj, __FILE__, __LINE__)
#define zcfgBeObjGetWithoutUpdate(oid, iid, obj) _zcfgBeObjGetWithoutUpdate(oid, iid, obj, __FILE__, __LINE__)
#define zcfgBeGetNextInSub(oid, iid, iid2, obj) _zcfgBeGetNextInSub(oid, iid, iid2, obj, __FILE__, __LINE__)
#define zcfgBeGetNextInSubWithoutUpdate(oid, iid, iid2, obj) _zcfgBeGetNextInSubWithoutUpdate(oid, iid, iid2, obj, __FILE__, __LINE__)

zcfgRet_t _zcfgBeObjGetNext(zcfg_offset_t, objIndex_t *, void **, const char *, int);
zcfgRet_t _zcfgBeObjGetNextWithoutUpdate(zcfg_offset_t, objIndex_t *, void **, const char *, int);
zcfgRet_t _zcfgBeObjGet(zcfg_offset_t, objIndex_t *, void **, const char *, int);
zcfgRet_t _zcfgBeObjGetWithoutUpdate(zcfg_offset_t, objIndex_t *, void **, const char *, int);
zcfgRet_t _zcfgBeGetNextInSub(zcfg_offset_t , objIndex_t *, objIndex_t *, void **, const char *, int);
zcfgRet_t _zcfgBeGetNextInSubWithoutUpdate(zcfg_offset_t, objIndex_t *, objIndex_t *, void **, const char *, int);

#else
	
zcfgRet_t zcfgBeObjGetNext(zcfg_offset_t, objIndex_t *, void **);
zcfgRet_t zcfgBeObjGetNextWithoutUpdate(zcfg_offset_t, objIndex_t *, void **);
zcfgRet_t zcfgBeObjGet(zcfg_offset_t, objIndex_t *, void **);
zcfgRet_t zcfgBeObjGetWithoutUpdate(zcfg_offset_t, objIndex_t *, void **);
zcfgRet_t zcfgBeGetNextInSub(zcfg_offset_t , objIndex_t *, objIndex_t *, void **);
zcfgRet_t zcfgBeGetNextInSubWithoutUpdate(zcfg_offset_t, objIndex_t *, objIndex_t *, void **);
#endif

zcfgRet_t zcfgBeObjQueryExist(zcfg_offset_t , objIndex_t *);


zcfgRet_t zcfgBeObjSetWithoutApply(zcfg_offset_t, objIndex_t *, void *, char *);
zcfgRet_t zcfgBeObjSet(zcfg_offset_t, objIndex_t *, void *, char *);
zcfgRet_t zcfgBeObjAdd(zcfg_offset_t, objIndex_t *);
zcfgRet_t zcfgBeObjAddWithoutApply(zcfg_offset_t, objIndex_t *);
zcfgRet_t zcfgBeObjDel(zcfg_offset_t, objIndex_t *, char *);
zcfgRet_t zcfgBeReqMsgSend(int, int, zcfg_offset_t, objIndex_t *, int, char *);
zcfgRet_t zcfgBeSaveParamValue(zcfg_offset_t, objIndex_t *, char *, void *);
zcfgRet_t zcfgBeObjIdToName(zcfg_offset_t , objIndex_t *, char *);
zcfgRet_t zcfgBeNameToObjId(const char *, objIndex_t *);
zcfgRet_t zcfgBeLowerLayerStatusGet(char *, char *);
#ifdef ZCFG_TR98_TR181_OBJECT_MAPPING_REBUILD
void zcfgBeReqMappingTableRebuild();
#else
#define zcfgBeReqMappingTableRebuild() {}
#endif

int zcfgBeRdmMode();


#ifdef ZCFG_MEMORY_LEAK_DETECT
#define zcfgBeRdmReqGet(rdmObjId, objIid, jstr, op) _zcfgBeRdmReqGet(rdmObjId, objIid, jstr, op, __FILE__, __LINE__)
#define zcfgBeRdmReqGetNext(rdmObjId, objIid, jstr, op) _zcfgBeRdmReqGetNext(rdmObjId, objIid, jstr, op, __FILE__, __LINE__)

zcfgRet_t _zcfgBeRdmReqGet(zcfg_offset_t rdmObjId, objIndex_t *objIid, char **jstr, uint8_t op, const char *, int);
zcfgRet_t _zcfgBeRdmReqGetNext(zcfg_offset_t rdmObjId, objIndex_t *objIid, char **jstr, uint8_t op, const char *, int);

#else
zcfgRet_t zcfgBeRdmReqGet(zcfg_offset_t rdmObjId, objIndex_t *objIid, char **jstr, uint8_t op);
zcfgRet_t zcfgBeRdmReqGetNext(zcfg_offset_t rdmObjId, objIndex_t *objIid, char **jstr, uint8_t op);
#endif
zcfgRet_t zcfgBeRdmReqSet(zcfg_offset_t , objIndex_t *, void *, uint32_t , char *);
zcfgRet_t zcfgBeRdmReqSetWitoutApply(zcfg_offset_t , objIndex_t *, void *, uint32_t , char *);

zcfgRet_t zcfgBeRdmModuleSet(zcfg_offset_t , objIndex_t *, struct json_object *, uint32_t );
void zcfgBeCheckWifiDiagRunning(uint32_t , int);

#ifdef ZYXEL_TT_CUSTOMIZATION_V6
void zcfgSlaacAddrSetAddTimer(void *);
void zcfgDhcp6cAddTimer(void *);
void zcfgPppResetAddTimer(void *);
int zcmdIpIfaceApplyParms(objIndex_t *, void *, uint32_t );
#endif
zcfgRet_t zcfgBeLanAppySyncDhcp4Server();
zcfgRet_t zcfgBeApplySyncBrSetMacAddrLearning();
#ifdef ZYXEL_TT_CUSTOMIZATION
zcfgRet_t zcmdQuickBridgingApplyParms(uint32_t oid, void *arg, uint32_t op);
#endif
struct json_object *zcfgBeApplyObjRetrievePartialObj(void *obj);

zcfgRet_t zcfgBeClearAllTr98WANConnectNumParam(const char *wanConnectNumParam);
zcfgRet_t zcfgBeSyncTr98WANConnectNum(uint32_t oid, objIndex_t *objIid, const char *wanConnectNumParam, struct json_object **replyNotifyObj, int num);
zcfgRet_t zcfgBeNotifyMsgSend(struct json_object *notify);

void zcfgBeCreateConfigSymLink(char *);
void zcfgBeRemoveConfigSymLink(char *);

zcfgRet_t zcfgBeJobjSet(zcfg_offset_t rdmObjId, objIndex_t *objIid, struct json_object *jobj, uint32_t op, char *fbkMsg);

#define zcfgBeObjFree(obj) ZOS_FREE(obj)

#if defined(ABZQ_CUSTOMIZATION_SUPPORT_WIFI_CHANNEL_HOPPING)
#define SUPPORT_FORCE_WIFI_CHANNEL_HOPPING	1
zcfgRet_t zcfgBeWifiChannelHopping (int index, uint8_t iInterval);
#endif

typedef int (*object_sync_config_cb)(zcfg_offset_t rdmObjId,objIndex_t *pobjIid,char *pobject_path,void *pobject_struct,void* pParam);
zcfgRet_t zcfgBeObjConfig(char *obj_path,object_sync_config_cb obj_sync_conf_cb,void* pParam);

typedef void (*compare_set_cb)(zcfg_offset_t rdmObjId,char *pobject_path, char *pobject_param_name,char *pobject_param_value);
zcfgRet_t zcfgBeObjCompareSet(zcfg_offset_t rdmObjId,void *newObj, void *curObj, objIndex_t *objIid,compare_set_cb comp_set_cb);

void zcfgBePrintObjectInfo(zcfg_offset_t rdmObjId,void *Obj,objIndex_t *objIid);


#endif
