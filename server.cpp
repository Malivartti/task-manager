#include "server.h"

Server::Server() {
    if (!this->listen(QHostAddress::Any, 23232)) {
        qDebug() << "Error";
    }
    else {
        qDebug() << "Server successfully started";
        DBConnection* connection = DBConnection::getInstance();
        connection->setDriver("QPSQL");
        connection->connect("localhost", "postgres", "postgres", "246224682");

        controller = ApplicationController::getInstance();
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::clientDisconnected);

    sockets.push_back(socket);
    qDebug() << "Client connected using descriptor " << socketDescriptor;
}

void Server::clientDisconnected() {
    socket = (QTcpSocket*)sender();
    sockets.erase(std::remove(sockets.begin(), sockets.end(), socket), sockets.end());
    socket->close();
}

void Server::slotReadyRead() {
    socket = (QTcpSocket*)sender();
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
            in >> key;
            sendToClient(key, controller->mapRequest(key, in));

            break;
        }
    }
}

void Server::sendToClient(const quint16 key, const QJsonDocument& json) {
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    for (int i = 0; i < sockets.size(); i++) {
        sockets[i]->write(data);
    }
}
