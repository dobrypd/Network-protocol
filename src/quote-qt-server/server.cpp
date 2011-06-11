#include "server.h"
#include <cmath>
#include <QtNetwork>
#include <QMessageBox>

void msg(QString msg){
    QMessageBox::information(0, ("Uwaga"),
        msg, QMessageBox::Ok);
}

Server::Server(QMainWindow* wnd, QSqlTableModel *model, int port, Log* log):
    model(model), wnd(wnd), port(port), log(log)
{
    //startuję serwer
    log->addLog(UTF("[---]Starting server..."));
    initSocket();
}

Server::~Server()
{
    //kończę pracę
    log->addLog("[---]Stopping server");

    delete udpSocket;
}

void Server::initSocket()
{
    log->addLog("[------]socket initialisation started...");

    udpSocket = new QUdpSocket(wnd);
    udpSocket->bind(QHostAddress("0.0.0.0"), port);

    log->addLog("[------]:socket binded host: 0.0.0.0"
                + QString(", port:") + QString::number(port)
                + ". Error string: " + udpSocket->errorString());

    udpSocket->connect(udpSocket, SIGNAL(readyRead()),
                 wnd, SLOT(readPendingDatagrams()));

    log->addLog("[------]socket initialisation done.");
}

QByteArray* Server::readQuotation()
{
    log->addLog("[$$$]starting: readQuotation CITE_REQUEST_MSG(key) : MSG_T ");

    int max = model->rowCount();
    int random = qrand() % max;
    QString temporary = model->record(random).value("QUOTATION").toString();

    QByteArray* quote = new QByteArray(temporary.toUtf8());

    log->addLog(QString("[$$$]quotation: ").append(quote->data()));
    return quote;
}

void Server::readPendingDatagrams()
{
    log->addLog("[$]starting readPendingDatagrams...");

    while (udpSocket->hasPendingDatagrams()) {
        log->addLog("[$]:socket has pending datagrams");

        MSG_T requestMsg;
        QByteArray buffer(udpSocket->pendingDatagramSize(), 0);
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        QDataStream stream(buffer);
        stream.setVersion(QDataStream::Qt_4_0);
        quint8 temp8 = 0;
        quint64 temp64 = 0;
        stream >> temp8;
        requestMsg.msg_id = temp8;
        stream >> temp64;
        requestMsg.key = temp64;

        if (requestMsg.msg_id != CITE_REQUEST_MSG)
            continue; //ignoruj

        log->addLog("[$]:new client: " + sender.toString() + ":" +QString::number(senderPort) + ". Key"
                    + QString::number(requestMsg.key) + ".");

        sendQuotation(requestMsg, sender, senderPort);
    }

    log->addLog("[$]no pending datagrams");
}

void Server::sendQuotation(MSG_T request, QHostAddress& host, quint16 port)
{
    log->addLog("[$$]starting sendQuotation to: "
                + host.toString() + ":" + QString::number(port) +".");

    CITE_MSG_T msg;
    msg.text.data = NULL;
    QByteArray *quot = readQuotation();
    quint16 parts = std::ceil((float)quot->size() / (float)MAX_PART_SIZE);

    if ((quot == NULL) || (parts == 0)){
        log->addLog("[$$]:has no quotation to send.");
        sendErrno(ENODATA, host, port);
        delete quot;
        return;
    }
    msg.msg_id = REPLY_MSG;
    msg.key = request.key;
    msg.parts = parts;

    log->addLog("[$$]:sending all " + QString::number(parts) + " parts.");
    for (quint16 index = 0; index < parts; index++){
        log->addLog("[$$]:sending part: " + QString::number(index) + ".");
        if (msg.text.data != NULL)
            delete msg.text.data;
        msg.text.data = nextPart(quot, index, msg.text.data_length);
        msg.index = index;
        sendPart(msg, host, port);
    }

    if (msg.text.data != NULL)
        delete msg.text.data;
    delete quot;

    log->addLog("[$$]finished sendQuotation to: "
                + host.toString() + ":" + QString::number(port) +".");
}

char* Server::nextPart(QByteArray* quote, quint16 index, quint16& size)
{
    size = std::min(int(MAX_PART_SIZE), quote->size() - MAX_PART_SIZE*index);
    char* ret = new char[size];
    for (quint16 i = 0; i < size; i++)
        ret[i] = quote->data()[MAX_PART_SIZE * index + i];
    return ret;
}

void Server::sendPart(CITE_MSG_T& msg, QHostAddress& host, quint16 port)
{
    quint64 datagramSize = sizeof(quint8) + sizeof(quint64) + 3* sizeof(quint16) + msg.text.data_length;
    QByteArray datagram(datagramSize, 0);
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_4_0);

    log->addLog("[$$$$]:starting send content: \"" + QString((QChar*)msg.text.data, (int)msg.text.data_length) + "\".");

    stream << msg.msg_id;
    stream << msg.key;
    stream << msg.index;
    stream << msg.parts;
    stream << msg.text.data_length;
    stream.writeRawData((const char*)(msg.text.data), msg.text.data_length);

    if (msg.index == msg.parts-1) //znaki konca
        stream << '\x4';
    else
        stream << '\x23';


    udpSocket->writeDatagram(datagram, host, port);

    log->addLog("[$$$$]: sent");
}

void Server::sendErrno(quint8 errno, QHostAddress& host, quint16 port)
{
    log->addLog("[%]:sending errno to "
                + host.toString()
                + ":"
                + QString::number(port)
                + ", errno:"
                + QString::number(errno));

    QByteArray datagram(sizeof(ERR_MSG_T), 0);
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_4_0);

    stream << SERVER_ERR_MSG << errno;

    udpSocket->writeDatagram(datagram, host, port);

    log->addLog("[%]errno sent.");
}
