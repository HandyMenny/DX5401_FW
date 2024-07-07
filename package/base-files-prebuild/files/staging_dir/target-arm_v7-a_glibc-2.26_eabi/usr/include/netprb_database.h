#ifndef _NETPRB_DATABASE_H
#define _NETPRB_DATABASE_H

enum dev_db_column_index {
    DEV_TYPE = 0,
    DEV_NAME,
    IP_ADDR,
    AL_MAC,
    DEV_MAC,
    SIGNAL_STRENGTH,
    LINK_RATE,
    OS_TYPE,
    ALIVE,
    halfLIFE,
    NEIGHBOR,
    HOST_TYPE,
    HOST_NAME,
	N_NOT_ALIVE,
    RSSI,
    SNR,
    EXTRA_INFO,
    MANUFACTURE,
	CONN_GUEST,
	TX_DATA,
	RX_DATA,
	MEDIA_TYPE,
	DATA_UP_RATE,
	DATA_DL_RATE,
	CHANNEL,
	CURRENT_BAND,
	SUPPORT_BAND,
	COL_NUM
};

enum dev_db_hosttype {
	UNKNOWN = 0,
	DESKTOP,
	LAPTOP,
	AP,
	NAS,
	POWERLINE,
	REPEATER,
	SMART_PHONE,
	CAMERA,
	TABLET,
	ROUTER,
	WATCH,
	GAME,
	WIRED_CLIENT,
	WIFI_CLIENT
};

#define DB_WIFI_BAND_24G (1 << 0)
#define DB_WIFI_BAND_5G  (1 << 1)

#endif