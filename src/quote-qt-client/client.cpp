#include "client.h"
#include <QMessageBox>

void msg(QString msg){
    QMessageBox::information(0, ("Uwaga"),
        msg, QMessageBox::Ok);
}

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
    if ((!udpSocket->bind(QHostAddress("0.0.0.0"), 0)) || (addr.isNull()))
        msg(UTF("Niepoprawny adres... sprawdź"));
}

QString Client::getQuote(progressSetT prSet) throw(errnoException&)
{
    if (udpSocket->error() != QUdpSocket::UnknownSocketError)
        throw errnoException(ESRVERR);
    prSet(0);
    quint64 quoteID = r.next();
    QByteArray buffer(sizeof(MSG_T), 0);
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_4_0);

    stream << CITE_REQUEST_MSG << quoteID; //MSG_T
    quint64 size = udpSocket->writeDatagram(buffer , buffer.size(),  addr, port);

    if (size < sizeof(MSG_T))
        throw errnoException(EAGAIN);

    QString quote;  //calosc po zlaczeniu
    QByteArray rawQuote; //po zlaczeniu
    QByteArray* qparts;  //aktualnie pobierane
    quint16 parts = 0;

    downloadParts(&qparts, parts, quoteID, prSet);    //moze wyrzucic wyjatek

    for(int i = 0; i < parts; ++i)
        rawQuote.append(qparts[i]);

    quote = QString::fromUtf8(rawQuote);

    delete [] qparts;

    return quote;
}

void Client::downloadParts(QByteArray** qparts,quint16& parts, quint64& quoteID, progressSetT prSet) throw(errnoException&)
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
               delete [] (*qparts);
           }
           /*jezeli juz cos mial to moze wyslac te informacje*/
           throw errnoException(err);
        }
        if(first){
            part_downloaded = new bool[parts];
            *qparts = new QByteArray[parts];
            if ((part_downloaded == NULL) || (qparts == NULL))
                throw E_USR2;
            for(int i = 0; i < parts; ++i){
                part_downloaded[i] = false;
                (*qparts)[i] = NULL;
            }
            first = false;
        }
        if (!part_downloaded[index]){
            //pobieram tylko te co niedoszly
            downloaded++;
            part_downloaded[index] = true;
            (*qparts)[index].append(current);
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
    quint8 msg_id = 5;
    quint8 errno = 0;
    QByteArray buffer(udpSocket->pendingDatagramSize(), 0);

    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);  //pobierz datagram
    if ((sender != addr) || (senderPort != port)) {
        msg(UTF("Inny serwer próbuje wysyłać Ci komunikaty"));
        return 0; //ignoruj
    }

    QDataStream stream(buffer);   //strumień
    stream.setVersion(QDataStream::Qt_4_0);
    stream >> msg_id;

    switch (msg_id){
    case REPLY_MSG:
        cite_msg = cite_msgFromStream(stream);
        cite_msg->msg_id = msg_id;
        break;
    case SERVER_ERR_MSG:
        stream >> errno;
        return errno;
    default: //pozostale sa ignorowane
        return 0;
    }

    parts = cite_msg->parts;
    index = cite_msg->index;

    //sprawdz klucz
    if (quoteID == cite_msg->key)
        current = QByteArray(cite_msg->text.data, cite_msg->text.data_length);
    else
        return 0; //ignoruj ESRVERR;

    delete cite_msg->text.data;
    delete cite_msg;

    return 0;
}

CITE_MSG_T* Client::cite_msgFromStream(QDataStream& stream)
{
    quint64 temp64;
    quint16 temp16;
    char*   tempcc;

    CITE_MSG_T* cite_msg = new CITE_MSG_T;
    stream >> temp64;
    cite_msg->key = temp64;
    stream >> temp16;
    cite_msg->index = temp16;
    stream >> temp16;
    cite_msg->parts = temp16;

    stream >> temp16;
    cite_msg->text.data_length = temp16;
    tempcc = new char[cite_msg->text.data_length];
    stream.readRawData(tempcc, cite_msg->text.data_length); //ignoruję ostatni znak (ETB/EOT)
    cite_msg->text.data = tempcc;

    return cite_msg;
}
