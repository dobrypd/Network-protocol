#ifndef PROTOCOLCONSTS_H
#define PROTOCOLCONSTS_H

/*static*/
/*server constants*/
const quint16 DEFAULT_SERVER_PORT   = 44444;
const quint16 MAX_PART_SIZE         = 1024;
const quint8 MAX_INTERVAL_TIME      = 5;

/*errors constants*/
const quint8 EAGAIN      = 11;
const quint8 ENODATA     = 61;
const quint8 EBADMSG     = 74;
const quint8 EREMOTEIO   = 121;
const quint8 E_USR1      = 254;
const quint8 E_USR2      = 255;

/*datatypes*/
typedef struct {
    quint16 data_length;
    char* data;
} CITE_PART_T;

typedef struct {
    quint8  msg_id;
    quint64 key;
} MSG_T;

typedef struct {
    quint8  msg_id;
    quint64 key;
    quint16 index;
    quint16 parts;
    CITE_PART_T text;
} CITE_MSG_T;

typedef struct {
    uint8   msg_id;
    uint8   errno;
} ERR_MSG_T;

#endif // PROTOCOLCONSTS_H
