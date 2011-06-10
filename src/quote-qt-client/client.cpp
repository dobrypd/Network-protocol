#include "client.h"

/*debug*/
#include <QMessageBox>
void msg(QString msg){
    QMessageBox::information(0, ("Uwaga"),
        msg, QMessageBox::Ok);
}
/******/

Client::Client(QString addr, int port): addr(QHostAddress(addr)), port(port)
{
    initSocket();
}

Client::~Client()
{
    delete udpSocket;
}

void Client::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind((const QHostAddress&)QHostAddress::LocalHost, 0);
}

QString Client::getQuote(progressSetT prSet) throw(errnoException&)
{
    prSet(0);

    quint64 quoteID = r.next();

    QByteArray buffer(sizeof(MSG_T), 0);
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_4_0);

    MSG_T request;
    request.key = quoteID;
    request.msg_id = CITE_REQUEST_MSG;

    stream << request.msg_id << request.key;

    //int size = udpSocket->writeDatagram((const char*) &request , sizeof(request),  addr, port);
    int size = udpSocket->writeDatagram(buffer , buffer.size(),  addr, port);

    if (size < sizeof(request))
        throw errnoException(EAGAIN);

    QString quote;  //calosc po zlaczeniu
    QByteArray rawQuote;
    QByteArray* qparts;    //tablica aktualnie pobieranych
    quint16 parts = 0;

    downloadParts(qparts, parts, quoteID, prSet);    //moze wyrzucic wyjatek

    for(int i = 0; i < parts; ++i)
        rawQuote.append(qparts[i]);

    quote = QString::fromUtf8(rawQuote);

    delete [] qparts;

    return quote;
}

void Client::downloadParts(QByteArray*& qparts,quint16& parts, quint64& quoteID, progressSetT prSet) throw(errnoException&)
{
    quint16 index = 0;
    quint16 downloaded = 0;
    bool* part_downloaded;
    bool first = true;
    int err = 0;
    QByteArray current;

    do {
        if(err = getNext(current, index, parts, quoteID)){
           if (!first){
               delete [] part_downloaded;
               delete [] qparts;
           }
           /*jezeli juz cos mial to moze wyslac te informacje*/
           throw errnoException(err);
        }
        if(first){
            part_downloaded = new bool[parts];
            qparts = new QByteArray[parts];
            if ((part_downloaded == NULL) || (qparts == NULL))
                throw E_USR2;
            for(int i = 0; i < parts; ++i){
                part_downloaded[i] = false;
                qparts[i] = NULL;
            }
            first = false;
        }
        if (!part_downloaded[index]){
            //pobieram tylko te co niedoszly
            downloaded++;
            part_downloaded[index] = true;
            qparts[index].append(current);
            prSet((int)((float)downloaded * (float)100 / (float)parts));
        }

    } while (downloaded < parts);

    delete [] part_downloaded;
}

//return errno or 0
quint8 Client::getNext(QByteArray& current, quint16& index, quint16& parts, quint64& quoteID)
{
    if (!udpSocket->waitForReadyRead(MAX_INTERVAL_TIME * 1000)) //interval
        return ETIMEOUT;

    CITE_MSG_T* cite_msg;
    QHostAddress sender;
    quint16 senderPort;
    quint8 msg_id = 1000;
    quint8 errno = 0;
    QByteArray buffer(udpSocket->pendingDatagramSize(), 0);

    udpSocket->readDatagram(buffer.data(), buffer.size());  //pobierz datagram

    QDataStream stream( buffer );   //strumień
    stream.setVersion( QDataStream::Qt_4_0 );
    stream >> msg_id;

    quint64 temp64; //tymczasowe zmienne różnych rozmiarów (dla strumienia)
    quint16 temp16;
    quint8  temp8;
    char*   tempcc;

    switch (msg_id){
    case REPLY_MSG:
        cite_msg = new CITE_MSG_T;
        cite_msg->msg_id = msg_id;
        stream >> temp64; cite_msg->key = temp64;
        stream >> temp16; cite_msg->index = temp16;
        stream >> temp16; cite_msg->parts = temp16;
        stream >> temp16;
        cite_msg->text.data_length = temp16;
        tempcc = new char[cite_msg->text.data_length];
        stream.readRawData(tempcc, cite_msg->text.data_length); //ignoruję ostatni znak (ETB/EOT)
        cite_msg->text.data = tempcc;
        break;
    case SERVER_ERR_MSG:
        stream >> errno;
        return errno;
    default: //pozostale sa ignorowane
        msg("nierozpoznaje msg_id=" + QString::number(msg_id));
        return 0;
    }

    parts = cite_msg->parts;
    index = cite_msg->index;
    current = QByteArray(cite_msg->text.data, cite_msg->text.data_length);

    return 0;
}
