#include "server.h"

Server::Server() {
    if (!this->listen(QHostAddress::Any, 23232)) {
        qDebug() << "Error";
    }
    else {
        qDebug() << "Server successfully started";
        DBConnection* connection = DBConnection::getInstance();
        connection->setDriver("QPSQL");
        connection->connect("db", "postgres", "postgres", "246224682");

        controller = FrontController::getInstance();
        controller->setServer(this);
    }
}

Server::~Server() {
    for (auto it = sockets.begin(); it != sockets.end(); it++) {
        it.value()->close();
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    qDebug() << "New client connected using descriptor" << socketDescriptor;

    //QTcpSocket* socket = new QTcpSocket;
    socket = new QTcpSocket; // Выше вариант, если этот не сработает

    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, [controller = this->controller, socket = this->socket, socketDescriptor]() {
        qDebug() << "Client sent data using descriptor" << socketDescriptor;
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
        if (in.status() != QDataStream::Ok) {
            qDebug() << "QDataStream Error Occured while Reading";
        }
        else {
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
                controller->mapRequest(socketDescriptor, key, object);

                break;
            }
        }
    });
    connect(socket, &QTcpSocket::disconnected, this, [&sockets = this->sockets, service = this->authService, socketDescriptor]() {

        sockets.take(socketDescriptor)->close();
        service->logout(socketDescriptor, {});

        qDebug() << "Client disconnected using descriptor" << socketDescriptor;
        qDebug() << "Current number of clients:" << sockets.size();
    });

    sockets[socketDescriptor] = socket;
    qDebug() << "Current number of clients:" << sockets.size();
}

void Server::sendToClient(qintptr descriptor, quint16 key, const QJsonDocument &json)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    QTcpSocket* socket = sockets[descriptor];
    if (socket == nullptr) { sockets.remove(descriptor); }
    else { socket->write(data); }

    qDebug() << "Successfully sent data to client with descriptor" << descriptor;
}

void Server::sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument &json)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    QTcpSocket* socket;
    for (qintptr x : descriptors) {
        socket = sockets[x];
        if (socket == nullptr) { sockets.remove(x); }
        else { socket->write(data); }
    }

    qDebug() << "Successfully sent data to clients";
}
