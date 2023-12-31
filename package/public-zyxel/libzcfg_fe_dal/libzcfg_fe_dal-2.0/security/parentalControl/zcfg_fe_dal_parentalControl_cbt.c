#include <ctype.h>
#include <json/json.h>
//#include <json/json_object.h>
#include <time.h>

#include "zcfg_common.h"
#include "zcfg_fe_rdm_string.h"
#include "zcfg_fe_rdm_struct.h"
#include "zcfg_rdm_oid.h"
#include "zcfg_rdm_obj.h"
#include "zcfg_debug.h"
//#include "zcfg_eid.h"
#include "zcfg_msg.h"
#include "zcfg_fe_dal_common.h"

//#define JSON_OBJ_COPY(json_object) json_tokener_parse(json_object_to_json_string(json_object))

dal_param_t PAREN_CTL_param[]={
	//Parental Ctl
	{"PrentalCtlEnable",	dalType_boolean,	0,	0,	NULL, NULL, dal_Add_ignore},
	//Parental Ctl Profile
	{"Index",				dalType_int,	0,	0,	NULL, NULL, dal_Add_ignore|dal_Delete},
	{"pcpEnable",			dalType_boolean,	0,	0,	NULL},
	{"pcpName",				dalType_string,	1,	64,	NULL, NULL, dal_Add},
	//{"WebRedirect",			dalType_boolean,	0,	0,	NULL},
	//{"ServicePolicy",		dalType_string,	0,	0,	NULL, "Block|Allow"},
	//{"Type",		dalType_int,	0,	0,	NULL},
	//{"UrlPolicy",			dalType_string,	0,	0,	NULL, "Block|Allow"},
	{"MACAddressList",		dalType_MacAddrList,	1,	5,	NULL, "All", dal_Add},
	//{"ScheduleRuleList",	dalType_string,	0,	64,	NULL, NULL, dalcmd_Forbid},
	{"Days",				dalType_DayofWeek,	1,	3,	NULL, NULL, dal_Add},
	{"TimeRangeList",		dalType_TimeRangeList,	1,	3,	NULL, NULL, dal_Add},
	//{"URLFilter",			dalType_URLFilterList,	0,	580,	NULL, "Empty"},
	//{"NetworkServiceList",	dalType_ParenCtlServiceList,	1,	12,	NULL, "Empty"},
	//Schedule
#if 0
	{"Enable",				dalType_boolean,	0,	0,	NULL},
	{"Name",				dalType_string,	0,	0,	NULL},
	{"Description",			dalType_string,	0,	0,	NULL},
	{"Days",				dalType_int,	0,	0,	NULL},
	{"TimeStartHour",		dalType_int,	0,	0,	NULL},
	{"TimeStartMin",		dalType_int,	0,	0,	NULL},
	{"TimeStopHour",		dalType_int,	0,	0,	NULL},
	{"TimeStopMin",			dalType_int,	0,	0,	NULL},
#endif
	{NULL,		0,	0,	0,	NULL},
};

struct json_object *schTimeObj = NULL;
struct json_object *parCtlObj = NULL;
struct json_object *pcpObj = NULL;

struct json_object *onecntPCGObj = NULL;
struct json_object *onecntPCRObj = NULL;

objIndex_t schTimeObjIid = {0};
objIndex_t parCtlObjIid = {0};
objIndex_t pcpObjIid = {0};

objIndex_t onecntPCGObjIid = {0};
objIndex_t onecntPCRObjIid = {0};


//Parental Ctl Profile
bool pcpEnable;
const char* pcpName;
bool WebRedirect;
const char* ServicePolicy;
int Type;
const char* MACAddressList;
char ScheduleRuleList[512] = {0};
const char* URLFilter;
const char* NetworkServiceList;
//Parental Ctl
bool PrentalCtlEnable;

//Schedule
bool Enable;
const char* Name;
const char* Description;
int TimeStartHour;
int TimeStartMin;
int TimeStopHour;
int TimeStopMin;
//One Connect Parental Control General
bool pcgEnable;
int pcgCount;
//One Connect Parental Control Rule
bool pcrEnable;
const char* pcrName;
const char* pcrBlockMAC;
char* pcrDays;
int pcrStartHour;
int pcrStartMin;
int pcrStopHour;
int pcrStopMin;

char curScheduleRuleList[64] = {0};
time_t t1, t2;

zcfgRet_t freeAllPcpObjects(){
	zcfgRet_t ret = ZCFG_SUCCESS;
	if(schTimeObj) json_object_put(schTimeObj);
	if(parCtlObj) json_object_put(parCtlObj);
	if(pcpObj) json_object_put(pcpObj);
	if(onecntPCGObj) json_object_put(onecntPCGObj);
	if(onecntPCRObj) json_object_put(onecntPCRObj);

	return ret;
}

void getParCtlBasicInfo(struct json_object *Jobj){

	//Parental Ctl Profile
	pcpEnable = json_object_get_boolean(json_object_object_get(Jobj, "pcpEnable"));
	pcpName = json_object_get_string(json_object_object_get(Jobj, "pcpName"));
	WebRedirect = json_object_get_boolean(json_object_object_get(Jobj, "WebRedirect"));
	ServicePolicy = json_object_get_string(json_object_object_get(Jobj, "ServicePolicy"));
	Type = json_object_get_int(json_object_object_get(Jobj, "Type"));
	MACAddressList = json_object_get_string(json_object_object_get(Jobj, "MACAddressList"));
	URLFilter = json_object_get_string(json_object_object_get(Jobj, "URLFilter"));
	NetworkServiceList = json_object_get_string(json_object_object_get(Jobj, "NetworkServiceList"));

	//Parental Ctl
	PrentalCtlEnable = json_object_get_boolean(json_object_object_get(Jobj, "PrentalCtlEnable"));

	//One Connect Parental Control General
	pcgEnable = json_object_get_boolean(json_object_object_get(Jobj,"PrentalCtlEnable"));
	//One Connect Parental Control Rule
	pcrEnable = json_object_get_boolean(json_object_object_get(Jobj,"pcpEnable"));
	pcrName = json_object_get_string(json_object_object_get(Jobj,"pcpName"));
	pcrBlockMAC = json_object_get_string(json_object_object_get(Jobj,"MACAddressList"));
	return;
}


void initGlobalPcpObjects(){

	schTimeObj = NULL;
	parCtlObj = NULL;
	pcpObj = NULL;
	IID_INIT(schTimeObjIid);
	IID_INIT(parCtlObjIid);
	IID_INIT(pcpObjIid);

	onecntPCGObj = NULL;
	onecntPCRObj = NULL;
	IID_INIT(onecntPCGObjIid);
	IID_INIT(onecntPCRObjIid);
}

zcfgRet_t parsePcpObject(struct json_object *pramJobj, struct json_object *tr181Jobj){
	char timeRange[16] = {0};
	char timeRangeList[64] = {0};
	int pcrStartHour = 0, pcrStartMin = 0, pcrStopHour = 0, pcrStopMin = 0;

	replaceParam(pramJobj, "pcpName", tr181Jobj, "Name");
	replaceParam(pramJobj, "pcpEnable", tr181Jobj, "Enable");
	replaceParam(pramJobj, "MACAddressList", tr181Jobj, "BlockMAC");

	pcrStartHour = json_object_get_int(json_object_object_get(tr181Jobj,"StartHour"));
	pcrStartMin = json_object_get_int(json_object_object_get(tr181Jobj,"StartMin"));
	pcrStopHour = json_object_get_int(json_object_object_get(tr181Jobj,"StopHour"));
	pcrStopMin = json_object_get_int(json_object_object_get(tr181Jobj,"StopMin"));
	sprintf(timeRange, "%02d:%02d-%02d:%02d",pcrStartHour,pcrStartMin,pcrStopHour,pcrStopMin);
	strcat(timeRangeList, timeRange);
	strcat(timeRangeList, ",");

	if(strlen(timeRangeList)>0)
		timeRangeList[strlen(timeRangeList)-1]= '\0';

	json_object_object_add(pramJobj, "TimeRangeList", json_object_new_string(timeRangeList));

	replaceParam(pramJobj, "Days", tr181Jobj, "Days");

	return ZCFG_SUCCESS;
}

zcfgRet_t editPcObject(struct json_object *Jobj){
	zcfgRet_t ret = ZCFG_SUCCESS;

	objIndex_t objIid;
	struct json_object *obj = NULL;
	int index = 0;
	int pcgCount = -1;//default
	IID_INIT(objIid);
	while(zcfgFeObjJsonGetNext(RDM_OID_ONE_CONNECT_P_C_RULE, &objIid, &obj) == ZCFG_SUCCESS){
		index++;
		zcfgFeJsonObjFree(obj);
	}
	if(index != 0)
		pcgCount = index;

	if((ret = zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_GENERAL, &onecntPCGObjIid, &onecntPCGObj)) != ZCFG_SUCCESS){
		return ret;
	}

	if(pcgEnable)
		json_object_object_add(onecntPCGObj, "Enable", json_object_new_boolean(true));
	else
		json_object_object_add(onecntPCGObj, "Enable", json_object_new_boolean(false));

	json_object_object_add(onecntPCGObj, "Count", json_object_new_int(pcgCount));

	if((ret = zcfgFeObjJsonSet(RDM_OID_ONE_CONNECT_P_C_GENERAL, &onecntPCGObjIid, onecntPCGObj, NULL)) != ZCFG_SUCCESS){
		return ret;
	}
	return ret;
}

zcfgRet_t addPcpObject(struct json_object *Jobj){
	zcfgRet_t ret = ZCFG_SUCCESS;
	struct json_object *reqSchRuleObjArray = NULL;
	uint8_t iidIdx =0;

	ScheduleRuleList[0] = '\0';
	reqSchRuleObjArray = json_object_object_get(Jobj, "reqSchRule");
	if(reqSchRuleObjArray != NULL){//request form GUI
		for(iidIdx = 0; iidIdx < json_object_array_length(reqSchRuleObjArray); iidIdx++){
			pcrEnable = json_object_get_boolean(json_object_object_get(Jobj, "pcpEnable"));
			pcrName = json_object_get_string(json_object_object_get(Jobj, "pcpName"));
			pcrBlockMAC = json_object_get_string(json_object_object_get(Jobj, "MACAddressList"));
			pcrDays = json_object_get_string(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "Days"));
			pcrStartHour = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StartHour"));
			pcrStartMin = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StartMin"));
			pcrStopHour = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StopHour"));
			pcrStopMin = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StopMin"));

			IID_INIT(onecntPCRObjIid);
			zcfgFeObjJsonAdd(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, NULL);
			if((ret = zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, &onecntPCRObj)) != ZCFG_SUCCESS){
				return ret;
			}
			json_object_object_add(onecntPCRObj, "Enable", json_object_new_boolean(pcrEnable));
			json_object_object_add(onecntPCRObj, "Name", json_object_new_string(pcrName));
			json_object_object_add(onecntPCRObj, "BlockMAC", json_object_new_string(pcrBlockMAC));
			json_object_object_add(onecntPCRObj, "Days", json_object_new_string(pcrDays));
			json_object_object_add(onecntPCRObj, "StartHour", json_object_new_int(pcrStartHour));
			json_object_object_add(onecntPCRObj, "StartMin", json_object_new_int(pcrStartMin));
			json_object_object_add(onecntPCRObj, "StopHour", json_object_new_int(pcrStopHour));
			json_object_object_add(onecntPCRObj, "StopMin", json_object_new_int(pcrStopMin));

			if((ret = zcfgFeObjJsonSet(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, onecntPCRObj, NULL)) != ZCFG_SUCCESS){
				return ret;
			}
		}
	}
#if 0	//Do not support in EMG3415-B10A-CBT, git branch: BCM63138_VMG4927_0b2_12252017
	else{//CLI
		strcpy(buf, Jgets(Jobj, "TimeRangeList"));
		count = 0;
		ptr = strtok_r(buf, ",", &tmp);
		while(ptr != NULL){
			parseTimeRange(ptr, &startHour, &startMin, &stopHour, &stopMin);
			count++;
			schRuleJobj = json_object_new_object();
			schRuleRetJarray = json_object_new_array();

			Jaddb(schRuleJobj, "Enable", true);
			sprintf(schRuleName, "%s_%d", Jgets(Jobj, "pcpName"), count);
			Jadds(schRuleJobj, "Name", schRuleName);
			Jadds(schRuleJobj, "Description", "ParentalControl");
			replaceParam(schRuleJobj, "Days", Jobj, "Days");
			Jaddi(schRuleJobj, "TimeStartHour", startHour);
			Jaddi(schRuleJobj, "TimeStartMin", startMin);
			Jaddi(schRuleJobj, "TimeStopHour", stopHour);
			Jaddi(schRuleJobj, "TimeStopMin", stopMin);
			if((ret = zcfgFeDalScheduleAdd(schRuleJobj, schRuleRetJarray, NULL)) != ZCFG_SUCCESS){
				json_object_put(schRuleJobj);
				json_object_put(schRuleRetJarray);
				return ret;
			}
			schRulePath = Jgets(json_object_array_get_idx(schRuleRetJarray, 0), "path");
			strcat(ScheduleRuleList, schRulePath);
			strcat(ScheduleRuleList, ",");
			ptr = strtok_r(NULL, ",", &tmp);
			json_object_put(schRuleJobj);
			json_object_put(schRuleRetJarray);
		}
		if(strlen(ScheduleRuleList)>0){
			ScheduleRuleList[strlen(ScheduleRuleList)-1]= '\0';
		}
	}
#endif
	return ret;
}

zcfgRet_t editPcpObject(struct json_object *Jobj, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;
	struct json_object *reqSchRuleObjArray = NULL;
	struct json_object *reqSchRuleIidArray = NULL;
	struct json_object *pcpIidArray = NULL;
	ScheduleRuleList[0] = '\0';
	const char *delschRules;
	uint8_t iidIdx =0;
	struct json_object *curJarray = NULL;

	pcpIidArray = json_object_object_get(Jobj, "iid");
	if(pcpIidArray != NULL){ //request form GUI
		for(iidIdx = 0; iidIdx < json_object_array_length(pcpIidArray); iidIdx++){
			onecntPCRObjIid.idx[iidIdx] = json_object_get_int(json_object_array_get_idx(pcpIidArray, iidIdx));
			if(onecntPCRObjIid.idx[iidIdx] != 0)
				onecntPCRObjIid.level = iidIdx+1;
		}
	}
#if 0
	else{//request form CLI
		if(!ISSET("Index")){
			if(replyMsg)
				strcpy(replyMsg, "Need specify --Index");
			return ZCFG_INVALID_ARGUMENTS;
		}
		IID_INIT(pcpObjIid);
		pcpObjIid.level = 1;
		pcpObjIid.idx[0] = Jgeti(Jobj, "Index");

		inputJobj = json_object_new_object();
		curJarray = json_object_new_array();
		Jaddi(inputJobj, "Index", pcpObjIid.idx[0]);
		if((ret = zcfgFeDalParentCtlGet(inputJobj, curJarray, NULL)) != ZCFG_SUCCESS){
			if(replyMsg) //for CLI
				sprintf(replyMsg, "Can't find --Index %d", pcpObjIid.idx[0]);
			json_object_put(inputJobj);
			return ret;
		}
		json_object_put(inputJobj);
		curJobj = json_object_array_get_idx(curJarray, 0);
	}
#endif
	if((ret = zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, &onecntPCRObj)) != ZCFG_SUCCESS){
		json_object_put(curJarray);
		if(replyMsg) //for CLI
			sprintf(replyMsg, "Can't find --Index %d", pcpObjIid.idx[0]);
		return ret;
	}

	reqSchRuleObjArray = json_object_object_get(Jobj, "reqSchRule");
	reqSchRuleIidArray = json_object_object_get(Jobj, "reqSchRuleIid");
	if(reqSchRuleObjArray != NULL){//request form GUI
		for(iidIdx = 0; iidIdx < json_object_array_length(reqSchRuleIidArray); iidIdx++){
			pcrEnable = json_object_get_boolean(json_object_object_get(Jobj, "pcpEnable"));
			pcrName = json_object_get_string(json_object_object_get(Jobj,"pcpName"));
			pcrBlockMAC = json_object_get_string(json_object_object_get(Jobj,"MACAddressList"));
			pcrDays = json_object_get_string(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "Days"));
			pcrStartHour = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StartHour"));
			pcrStartMin = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StartMin"));
			pcrStopHour = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StopHour"));
			pcrStopMin = json_object_get_int(json_object_object_get(json_object_array_get_idx(reqSchRuleObjArray, iidIdx), "StopMin"));

			if((ret = zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, &onecntPCRObj)) != ZCFG_SUCCESS){
				return ret;
			}
			json_object_object_add(onecntPCRObj, "Enable", json_object_new_boolean(pcrEnable));
			json_object_object_add(onecntPCRObj, "Name", json_object_new_string(pcrName));
			json_object_object_add(onecntPCRObj, "BlockMAC", json_object_new_string(pcrBlockMAC));
			json_object_object_add(onecntPCRObj, "Days", json_object_new_string(pcrDays));
			json_object_object_add(onecntPCRObj, "StartHour", json_object_new_int(pcrStartHour));
			json_object_object_add(onecntPCRObj, "StartMin", json_object_new_int(pcrStartMin));
			json_object_object_add(onecntPCRObj, "StopHour", json_object_new_int(pcrStopHour));
			json_object_object_add(onecntPCRObj, "StopMin", json_object_new_int(pcrStopMin));
			if((ret = zcfgFeObjJsonSet(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, onecntPCRObj, NULL)) != ZCFG_SUCCESS){
				return ret;
			}
		}
	}
#if 0
	else if(ISSET("TimeRangeList") || ISSET("Days")){//request form CLI
		memset(ScheduleRuleList, 0,sizeof(ScheduleRuleList));
		if(ISSET("TimeRangeList"))
			strcpy(buf, Jgets(Jobj, "TimeRangeList"));
		else{
			strcpy(buf, Jgets(curJobj, "TimeRangeList"));
		}

		count = 0;
		ptr = strtok_r(buf, ",", &tmp);
		while(ptr != NULL){
			parseTimeRange(ptr, &startHour, &startMin, &stopHour, &stopMin);
			count++;
			schRuleJobj = json_object_new_object();
			schRuleRetJarray = json_object_new_array();

			Jaddb(schRuleJobj, "Enable", true);
			if(ISSET("pcpName"))
				sprintf(schRuleName, "%s_%d", Jgets(Jobj, "pcpName"), count);
			else
				sprintf(schRuleName, "%s_%d", Jgets(curJobj, "pcpName"), count);

			Jadds(schRuleJobj, "Name", schRuleName);
			Jadds(schRuleJobj, "Description", "ParentalControl");
			if(ISSET("Days"))
				replaceParam(schRuleJobj, "Days", Jobj, "Days");
			else
				replaceParam(schRuleJobj, "Days", curJobj, "Days");
			Jaddi(schRuleJobj, "TimeStartHour", startHour);
			Jaddi(schRuleJobj, "TimeStartMin", startMin);
			Jaddi(schRuleJobj, "TimeStopHour", stopHour);
			Jaddi(schRuleJobj, "TimeStopMin", stopMin);
			Jaddb(schRuleJobj, "DontCheckDupName", true);
			if((ret = zcfgFeDalScheduleAdd(schRuleJobj, schRuleRetJarray, NULL)) != ZCFG_SUCCESS){
				json_object_put(schRuleJobj);
				json_object_put(schRuleRetJarray);
				return ret;
			}
			schRulePath = Jgets(json_object_array_get_idx(schRuleRetJarray, 0), "path");
			strcat(ScheduleRuleList, schRulePath);
			strcat(ScheduleRuleList, ",");
			ptr = strtok_r(NULL, ",", &tmp);
			json_object_put(schRuleJobj);
			json_object_put(schRuleRetJarray);
		}
		if(strlen(ScheduleRuleList)>0){
			ScheduleRuleList[strlen(ScheduleRuleList)-1]= '\0';
		}
	}
#endif
	if(curJarray != NULL)
		json_object_put(curJarray);

	return ret;
}

void zcfgFeDalShowParentCtl(struct json_object *Jarray){// CLI
	int i, j, firstTime, len = 0;
	char *dayString = NULL;
	int index = 0, startHour = 0, startMin = 0, stopHour = 0, stopMin = 0, startPort, endPort;
	char buf[1024] = {0};
	char *ptr, *tmp;
	struct json_object *Jobj;
	char serviceDesc[32], protocol[1024], tmpProtocol[1024];

	if(json_object_get_type(Jarray) != json_type_array){
		printf("wrong Jobj format!\n");
		return;
	}

	if((Jobj = json_object_array_get_idx(Jarray, 0)) == NULL)
		return;

	if(Jget(Jobj, "PrentalCtlEnable") != NULL){//get all case
		printf("Parental Control             %s\n", Jgetb(Jobj, "PrentalCtlEnable")?"Enabled":"Disabled");
		printf("\n");
		printf("%-6s %-12s %-30s %-20s\n", "Index", "Status", "PCP Name", "Home Network User MAC");
		printf("------------------------------------------------------------------------\n");

		len = json_object_array_length(Jarray);
		for(i=1;i<len;i++){
			Jobj = json_object_array_get_idx(Jarray, i);
			if(Jobj!=NULL){
				printf("%-6lld ", Jgeti(Jobj, "Index"));
				printf("%-12s ", Jgetb(Jobj, "pcpEnable")?"Enabled":"Disabled");
				printf("%-30s ", Jgets(Jobj, "pcpName"));
				strcpy(buf, Jgets(Jobj, "MACAddressList"));
				ptr = strtok_r(buf, ",", &tmp);
				firstTime = 1;
			  while(ptr != NULL){
			  if(firstTime){
				printf("%-20s\n", ptr);
				firstTime=0;
			  }
			  else{
			  	printf("%-50s %-20s\n", "", ptr);
			  }
				ptr = strtok_r(NULL, ",", &tmp);
			  }
				printf("\n");
			}
		}
	}
	else{//get the specified index
		printf("%-35s %s\n", "Active", Jgetb(Jobj, "pcpEnable")?"Enabled":"Disabled");
		printf("%-35s %s\n", "Parental Control Profile Name", Jgets(Jobj, "pcpName"));
		printf("User MAC Address\n");
		strcpy(buf, Jgets(Jobj, "MACAddressList"));
		ptr = strtok_r(buf, ",", &tmp);
	  while(ptr != NULL){
		printf("%-35s %s\n", "", ptr);
		ptr = strtok_r(NULL, ",", &tmp);
	  }
	  	printf("\n");
	  	printf("%-35s %s\n", "Day", Jgets(Jobj, "Days"));
		printf("Time (Start - End)\n");
		strcpy(buf, Jgets(Jobj, "TimeRangeList"));
		ptr = strtok_r(buf, ",", &tmp);
	  while(ptr != NULL){
		printf("%-35s %s\n", "", ptr);
		ptr = strtok_r(NULL, ",", &tmp);
	  }
		printf("\n");
		printf("%-35s %s\n", "Network Service Setting", Jgets(Jobj, "ServicePolicy"));
#if 1
		strcpy(buf, Jgets(Jobj, "NetworkServiceList"));
		ptr = strtok_r(buf, "/", &tmp);
		printf("%-35s %-15s %s\n", "", "Service Name", "Protocol:Port");
	  while(ptr != NULL){
	  	if(sscanf(ptr, "%*[^[][%[^@]@%s", serviceDesc, tmpProtocol) !=2)
			continue;
		i=0;
		j=0;
		firstTime =1;
		memset(protocol,0,sizeof(protocol));
		if(!strncmp(&(tmpProtocol[i]), "BOTH", 3)){
			strcpy(protocol, "TCP&UDP");
			i=i+4;
			j=j+7;
		}
		while(tmpProtocol[i] != '\0'){
			if(firstTime && tmpProtocol[i]=='#'){
				protocol[j] = ':';
				i++;
				j++;
			}
			else if(!strncmp(&(tmpProtocol[i]), ":-1", 3)){
				i=i+3;
			}
			else if(!strncmp(&(tmpProtocol[i]), "@TCP#", 5) || !strncmp(&(tmpProtocol[i]), "@UDP#", 5)){
				i=i+5;
				protocol[j] = ',';
				j++;
			}
			else if(!strncmp(&(tmpProtocol[i]), "@BOTH#", 6)){
				i=i+6;
				protocol[j] = ',';
				j++;
			}
			else{
				protocol[j] = tmpProtocol[i];
				i++;
				j++;
			}
		}
		printf("%-35s %-15s %s\n", "", serviceDesc, protocol);
		ptr = strtok_r(NULL, "/", &tmp);
	  }
#endif
		printf("\n");

		printf("%-35s %s\n", "Block or Allow the Web Site", Jgets(Jobj, "UrlPolicy"));
		printf("%-35s %s\n", "", "webSite");
		strcpy(buf, Jgets(Jobj, "URLFilter"));
		ptr = strtok_r(buf, ",", &tmp);
	  while(ptr != NULL){
		printf("%-35s %s\n", "", ptr);
		ptr = strtok_r(NULL, ",", &tmp);
	  }
	}
}

zcfgRet_t zcfgFeDalParentCtlGet(struct json_object *Jobj, struct json_object *Jarray, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;

	objIndex_t objIid;
	struct json_object *obj = NULL;
	struct json_object *pramJobj = NULL;

	if((Jobj != NULL) && (Jget(Jobj, "Index")!=NULL)){
		IID_INIT(objIid);
		objIid.level = 1;
		objIid.idx[0] = Jgeti(Jobj, "Index");
		if(zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_RULE, &objIid, &obj) == ZCFG_SUCCESS){
			pramJobj = json_object_new_object();
			json_object_object_add(pramJobj, "Index", json_object_new_int(objIid.idx[0]));

			parsePcpObject(pramJobj, obj);

			json_object_array_add(Jarray, pramJobj);
			zcfgFeJsonObjFree(obj);
		}
	}
	else{
		IID_INIT(objIid);
		if(zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_GENERAL, &objIid, &obj) == ZCFG_SUCCESS){
			pramJobj = json_object_new_object();
			replaceParam(pramJobj, "PrentalCtlEnable", obj, "Enable");
			json_object_array_add(Jarray, pramJobj);
			zcfgFeJsonObjFree(obj);
		}
		IID_INIT(objIid);
		while(zcfgFeObjJsonGetNext(RDM_OID_ONE_CONNECT_P_C_RULE, &objIid, &obj) == ZCFG_SUCCESS){
			pramJobj = json_object_new_object();
			json_object_object_add(pramJobj, "Index", json_object_new_int(objIid.idx[0]));

			parsePcpObject(pramJobj, obj);

			json_object_array_add(Jarray, pramJobj);
			zcfgFeJsonObjFree(obj);
		}
	}
	return ret;
}

zcfgRet_t zcfgFeDalParentCtlEdit(struct json_object *Jobj, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;
	initGlobalPcpObjects();
	getParCtlBasicInfo(Jobj);
	t2 = time(NULL);

	if(!ISSET("PrentalCtlEnable")){
		if((ret = editPcpObject(Jobj, replyMsg)) != ZCFG_SUCCESS){
			goto dalPcp_edit_fail;
		}
	}
	else{
		if((ret = editPcObject(Jobj)) != ZCFG_SUCCESS){
			goto dalPcp_edit_fail;
		}
	}

	t2 = time(NULL);

	dalPcp_edit_fail:
		freeAllPcpObjects();

	return ret;
}

zcfgRet_t zcfgFeDalParentCtlAdd(struct json_object *Jobj, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;
	initGlobalPcpObjects();
	getParCtlBasicInfo(Jobj);

	if((ret = addPcpObject(Jobj)) != ZCFG_SUCCESS)
		goto dalPcp_add_fail;

	dalPcp_add_fail:
		freeAllPcpObjects();

	return ret;
}

zcfgRet_t zcfgFeDalParentCtlDelete(struct json_object *Jobj, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;
	struct json_object *pctlObjIidArray = NULL;
	uint8_t iidIdx =0;
	// const char * scheduleRules = NULL;
	//char* buffer = NULL;

	pctlObjIidArray = json_object_object_get(Jobj, "PctlObjIid");

	if(pctlObjIidArray != NULL){//request form GUI
		for(iidIdx=0; iidIdx < json_object_array_length(pctlObjIidArray); iidIdx++){
			onecntPCRObjIid.idx[iidIdx] = json_object_get_int( json_object_array_get_idx(pctlObjIidArray, iidIdx));
			if(onecntPCRObjIid.idx[iidIdx] != 0)
				onecntPCRObjIid.level = iidIdx+1;
		}
	}
	// else{//request form CLI
	// 	IID_INIT(pcpObjIid);
	// 	pcpObjIid.level = 1;
	// 	pcpObjIid.idx[0] = Jgeti(Jobj, "Index");
	// }
	if((ret = zcfgFeObjJsonGetWithoutUpdate(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, &onecntPCRObj)) != ZCFG_SUCCESS){
		// if(replyMsg)
		// 	sprintf(replyMsg, "Can't find --Index %d", pcpObjIid.idx[0]);
		return ret;
	}

	if((ret = zcfgFeObjJsonDel(RDM_OID_ONE_CONNECT_P_C_RULE, &onecntPCRObjIid, NULL)) != ZCFG_SUCCESS)
		return ret;
	return ret;
}

zcfgRet_t zcfgFeDalParentCtl(const char *method, struct json_object *Jobj, struct json_object *Jarray, char *replyMsg){
	zcfgRet_t ret = ZCFG_SUCCESS;

	if(!strcmp(method, "POST"))
		ret = zcfgFeDalParentCtlAdd(Jobj, replyMsg);
	else if(!strcmp(method, "DELETE"))
	   ret = zcfgFeDalParentCtlDelete(Jobj, replyMsg);
	else if(!strcmp(method, "PUT"))
		ret = zcfgFeDalParentCtlEdit(Jobj, replyMsg);
	else if(!strcmp(method, "GET"))
		ret = zcfgFeDalParentCtlGet(Jobj, Jarray, NULL);
	else
		printf("Unknown method:%s\n", method);

	return ret;
}
