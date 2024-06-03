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

QByteArray Controller::encode(const QByteArray &data)
{
    if (!isServerPublicKeySet) { return data; }
    return rsa->encode(data, serverPublicKey);
}

QByteArray Controller::decode(const QByteArray &data)
{
    if (!isServerPublicKeySet) { return data; }
    return rsa->decode(data, rsa->getPrivateKey());
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
            QByteArray data;
            in >> key >> data;
            if (key == 0) {
                qDebug() << "Server Public Key:" << data;

                serverPublicKey = data;

                qDebug() << "Client Public Key:" << rsa->getPublicKey();

                sendToServer(0, rsa->encode(rsa->getPublicKey(), serverPublicKey));

                isServerPublicKeySet = true;
            }
            else {
                QJsonDocument object = QJsonDocument::fromJson(decode(data));

                qDebug() << key << object;

                handler->mapRequest(key, object);
            }

            break;
        }
    }
}

void Controller::sendToServer(const quint16 key, const QByteArray &message)
{
    qDebug() << "Sending to server..." << key;

    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << encode(message);
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    socket->write(data);

    socket->flush();

    qDebug() << "Successfully sent data to server" << key;
}

void Controller::sendToServer(const quint16 key, const QJsonDocument &json)
{
    sendToServer(key, json.toJson());
}
