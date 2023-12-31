#ifndef ZYEE_MSG_H
#define ZYEE_MSG_H

#include "zcfg_common.h"

typedef enum {
    ZYEE_MSG_SYSCMD=0,
    ZYEE_MSG_INSTALL,
    ZYEE_MSG_UNINSTALL,
    ZYEE_MSG_START,
    ZYEE_MSG_STOP,
    ZYEE_MSG_ZCFG_RELOAD,
} zyee_msgtype_t;

typedef enum {
    ZYEE_MSG_ERR_SOCK_INVALID_LENGTH=-10,
    ZYEE_MSG_ERR_SOCK_OPEN_ERROR,
    ZYEE_MSG_ERR_SOCK_CONNECT_ERROR,
    ZYEE_MSG_ERR_SOCK_WRITE_ERROR,
    ZYEE_MSG_ERR_ACCEPT_ERROR,
    ZYEE_MSG_ERR_MEMORY_ALLOC_ERROR,
    ZYEE_MSG_ERR_READ_PAYLOAD_ERROR,
    ZYEE_MSG_ERR_OPKG_CONTORL_NONEXIST,
    ZYEE_MSG_ERR_OPKG_LIST_NONEXIST,

} zyee_err_t;

typedef struct zyee_msghdr_s
{
    unsigned int    type;
    unsigned int    msglen;
    unsigned int    timeout;
    unsigned int    eid;
    unsigned int    oid;
    objIndex_t      objIid[1]; // 7 bytes
    char            reserve[1];
    unsigned int    newlen;
    unsigned int    oldlen;
    time_t          stime;
    time_t          etime;
    int             errcode;
} zyee_msghdr_t;

int zyee_msg_send(char *sockaddr, void *p_mbuf, const unsigned int mlen, const int timeout);
int zyee_msg_receive(int fd, zyee_msghdr_t **msghdr);

#endif
