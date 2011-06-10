#include "server.h"

#include <QtNetwork>

/*debug*/
#include <QMessageBox>
void msg(QString msg){
    QMessageBox::information(0, ("Uwaga"),
        msg, QMessageBox::Ok);
}
/******/

Server::Server(QMainWindow* wnd, QSqlTableModel *model, int port, Log* log):
    model(model), wnd(wnd), port(port), log(log)
{
    //startuję serwer
    log->addLog("Serwer startuje");
    initSocket();
}

Server::~Server()
{
    //kończę pracę
    log->addLog("Serwer konczy dzialanie");
    delete udpSocket;
}

QByteArray* Server::readQuotation()
{
    log->addLog("rozpoczynam procedure readQuotation CITE_REQUEST_MSG(key) : MSG_T ");

    QString temporary = "to jest tekst";
    QByteArray* quote = new QByteArray(temporary.toUtf8());

    log->addLog(QString("koncze procedure readQuotation wyrzucam cytat: ").append(quote->data()));
    return quote;
}

void Server::initSocket()
{
    log->addLog("rozpoczynam initSocket");

    udpSocket = new QUdpSocket(wnd);
    udpSocket->bind(QHostAddress::LocalHost, port);

    log->addLog("Lacze sygnal ze slotem - rozpoczynam nasluchiwanie");
    udpSocket->connect(udpSocket, SIGNAL(readyRead()),
                 wnd, SLOT(readPendingDatagrams()));

    log->addLog("koncze initSocket");
}

void Server::readPendingDatagrams()
{
    log->addLog("rozpoczynam readPendingDatagrams");

    while (udpSocket->hasPendingDatagrams()) {
        log->addLog("pobieram dane z gniazda");

        MSG_T requestMsg;
        quint64 requestMsgSize = sizeof(MSG_T);
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram((char*)&requestMsg, requestMsgSize,
                                &sender, &senderPort);

        if (requestMsg.msg_id != CITE_REQUEST_MSG)
            continue;

        //zmieniam stan na SEND_PART_STATE
        log->addLog("Wysle cytat temu: " + sender.toString() + ":" +QString::number(senderPort));
        sendQuotation(requestMsg, sender, senderPort);
    }

    log->addLog("koncze readPendingDatagrams");
}

void Server::sendQuotation(MSG_T request, QHostAddress& host, quint16 port)
{
    log->addLog("rozpoczynam sendQuotation dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port));

    CITE_MSG_T msg;
    CITE_PART_T part;
    quint16 part_size = MAX_PART_SIZE;
    QByteArray *quot = readQuotation();//w UTF8
    QByteArray datagram(part_size, 0);
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion( QDataStream::Qt_4_0 );
    quint16 parts = (quot->size() + sizeof(msg) + sizeof(quint16)) / MAX_PART_SIZE;
    ::msg(QString::number(parts));
    quint16 index = 0;

    if (quot == NULL){
        sendErrno(request, ENODATA, host, port);
        return;
    }

    msg.parts = parts;
    msg.msg_id = REPLY_MSG;
    msg.key = request.key;
    msg.text = part;

    /*wysylaj czesci*/
    for (index = 0; index < parts; index++){
        msg.index = index;
        part_size = std::min(MAX_PART_SIZE, (quint16)quot->size());
        part.data_length = part_size;
        part.data = ((char*) quot->data()) + index * MAX_PART_SIZE;
        stream << msg.msg_id << msg.key << msg.index << msg.parts << msg.text.data_length;
        //stream.writeBytes(, 100);//todo
        udpSocket->writeDatagram(datagram, host, port);
        datagram.clear();
    }

    delete quot;

    log->addLog("koncze sendQuotation dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port));
}

void Server::sendErrno(MSG_T request, quint8 errno, QHostAddress& host, quint16 port)
{
    log->addLog("rozpoczynam sendErrno dla hosta: "
                + host.toString()
                + ":"
                + QString::number(port)
                + ", errno:"
                + QString::number(errno));

    log->addLog("koncze sendErrno dla hosta:");
}
