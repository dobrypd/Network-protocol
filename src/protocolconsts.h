#ifndef PROTOCOLCONSTS_H
#define PROTOCOLCONSTS_H

#include <exception>
#include <QString>
#define UTF(X) QString::fromUtf8(X)


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
    quint8   msg_id;
    quint8   errno;
} ERR_MSG_T;


/*msg_id*/
const quint8 SERVER_ERR_MSG = 0;
const quint8 CITE_REQUEST_MSG = 1;
const quint8 REPLY_MSG = 2;

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

const quint8 ETIMEOUT      = 1001;


/*exceptions*/
class errnoException: public std::exception
{
private:
    quint8 errno;
public:
    errnoException(quint8 errno): errno(errno) { }

   virtual const QString to_str() const throw()
    {
        switch(errno){
        case EAGAIN:
            return UTF("Tymczasowy brak dostępu");
            break;
        case ENODATA:
            return UTF("Brak cytatów w bazie serwera");
            break;
        case EBADMSG:
            return UTF("Brak wiadomości z danymi");
            break;
        case EREMOTEIO:
            return UTF("Serwer nie ma dostępu do bazy danych");
            break;
        case E_USR1:
            return UTF("Ta funkcja nie została zaimplementowana w Twojej wersji programu");
            break;
        case E_USR2:
            return UTF("Wystąlił błąd wewnętrzny programu.");
            break;
        case ETIMEOUT:
            return UTF("Serwer nie odpowiada.");
            break;
        default:
            return UTF("Niezidentyfikowany błąd!");
        }
    }

    virtual const char* what() const throw()
    {
       return "ERRNO exception: " + QString::number(errno).toAscii();
    }

    quint8 getErrno() { return errno; }
};


#endif // PROTOCOLCONSTS_H
