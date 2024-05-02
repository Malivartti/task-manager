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
        controller->setServer(this);
    }
}

Server::~Server() {
    for (auto it = sockets.begin(); it != sockets.end(); it++) {
        it.value()->close();
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    //socket = new QTcpSocket;
    qDebug() << "New Connection Size: " << sockets.size();
    QTcpSocket* socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    //connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::readyRead, this, [controller = this->controller, socket, socketDescriptor]() {
        //QTcpSocket* socket = sockets[socketDescriptor];
        qDebug() << "SOCKET3:" << socketDescriptor;
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

                controller->mapRequest(socketDescriptor, in);

                break;
            }
        }
    });
    //connect(socket, &QTcpSocket::disconnected, this, &Server::clientDisconnected);
    connect(socket, &QTcpSocket::disconnected, this, [&sockets = this->sockets, socketDescriptor]() {
        qDebug() << "Size: " << sockets.size();

        // auto it = sockets.find(socketDescriptor);
        // if (it != sockets.end()) {
        //     it.value()->close();
        //     sockets.erase(it);
        // }

        sockets.take(socketDescriptor)->close();

        qDebug() << "Size: " << sockets.size();
        qDebug() << "Client with descriptor" << socketDescriptor << "disconnected";
    });
    //sockets.push_back(socket);
    sockets[socketDescriptor] = socket;
    qDebug() << "Client connected using descriptor " << socket->socketDescriptor();
    qDebug() << "Size of sockets: " << sockets.size();
}

// DEPRECATED
void Server::clientDisconnected() {
    // socket = (QTcpSocket*)sender();
    // sockets.erase(std::remove(sockets.begin(), sockets.end(), socket), sockets.end());
    // socket->close();
}

// DEPRECATED
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
            qDebug() << "Casted: " << key;
            //sendToClient(key, controller->mapRequest(socket->socketDescriptor(), key, in));

            break;
        }
    }
}

// DEPRECATED ?
void Server::sendToClient(const quint16 key, const QJsonDocument& json) {
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    for (auto it = sockets.begin(); it != sockets.end(); it++) {
        it.value()->write(data);
    }
}

// DEPRECATED
void Server::sendToClient(QTcpSocket *socket, QByteArray &data)
{
    socket->write(data);
}

void Server::sendToClient(qintptr descriptor, quint16 key, const QJsonDocument &json)
{
    // auto it = sockets.find(descriptor);
    // if (it == sockets.end()) return;

    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    QTcpSocket* socket = sockets[descriptor];
    if (socket == nullptr) { sockets.remove(descriptor); }
    else { socket->write(data); }
}

void Server::sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument &json)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    QTcpSocket* socket;
    for (qintptr x : descriptors) {
        socket = sockets[x];
        if (socket == nullptr) { sockets.remove(x); }
        else { socket->write(data); }
    }
}
