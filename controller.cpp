#include "controller.h"

Controller::Controller() {}

Controller *Controller::getInstance()
{
    if (!instance) {
        instance = new Controller();
    }
    return instance;
}

void Controller::connectToServer()
{
    if (!socket) {
        socket = new QTcpSocket();
    }
    connect(socket, &QTcpSocket::readyRead, this, &Controller::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &QTcpSocket::deleteLater);

    socket->connectToHost("127.0.0.1", 23232);
}

void Controller::sendToServer(const quint16 key, const QJsonDocument &json)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    socket->write(data);
}

void Controller::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_7);
    if (in.status() != QDataStream::Ok) {
        qDebug() << "QDataStream Error";
    }
    else {
        qDebug() << "Reading...";
        quint16 nextBlockSize{};
        for (;;) {
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable() < 2) {
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) {
                qDebug() << "Invalid stream";
                break;
            }
            quint16 key;
            QJsonDocument object;
            in >> key >> object;
            qDebug() << key << object;

            handler->mapRequest(key, object);

            break;
        }
    }
}
