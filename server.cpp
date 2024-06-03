#include "server.h"

void Server::setClientPublicKey(qintptr descriptor, const QByteArray &key) { keys.insert(descriptor, key); }

Server::Server() {
    if (!this->listen(QHostAddress::Any, 23232)) {
        qDebug() << "Error";
    }
    else {
        qDebug() << "Server successfully started";
        DBConnection* connection = DBConnection::getInstance();
        connection->setDriver("QPSQL");
        connection->connect("localhost", "postgres", "postgres", "246224682");

        controller = FrontController::getInstance();
        controller->setServer(this);
    }
}

Server::~Server() {
    for (auto it = sockets.begin(); it != sockets.end(); it++) {
        it.value()->close();
    }
}

QByteArray Server::encode(qintptr descriptor, const QByteArray &data)
{
    auto it = keys.find(descriptor);
    if (it == keys.end()) { return data; }
    return rsa->encode(data, it.value());
}

QByteArray Server::decode(qintptr descriptor, const QByteArray &data)
{
    if (!keys.contains(descriptor)) { return data; }
    return rsa->decode(data, rsa->getPrivateKey());
}

void Server::incomingConnection(qintptr socketDescriptor) {
    qDebug() << "New client connected using descriptor" << socketDescriptor;

    //QTcpSocket* socket = new QTcpSocket;
    socket = new QTcpSocket; // Выше вариант, если этот не сработает

    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, [server = this, controller = this->controller, socket = this->socket, socketDescriptor, this]() {
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
                QByteArray data;
                in >> key >> data;
                if (key == 0) { // Процесс рукопожатия: получение ключа от клиента для шифрования

                    qDebug() << "Encoded: " << data;

                    data = rsa->decode(data, rsa->getPrivateKey());

                    qDebug() << "Decoded: " << data;

                    server->setClientPublicKey(socketDescriptor, data);
                }
                else { // Обработка зашифрованных запросов
                    QJsonDocument object = QJsonDocument::fromJson(decode(socketDescriptor, data));

                    qDebug() << key << object;

                    controller->mapRequest(socketDescriptor, key, object);
                }

                break;
            }
        }
    });
    connect(socket, &QTcpSocket::disconnected, this, [&sockets = this->sockets, service = this->authService, socketDescriptor, this]() {
        sockets.take(socketDescriptor)->close();
        keys.take(socketDescriptor);
        service->logout(socketDescriptor, {});

        qDebug() << "Client disconnected using descriptor" << socketDescriptor;
        qDebug() << "Current number of clients:" << sockets.size();
    });

    sockets[socketDescriptor] = socket;

    qDebug() << "Server Public Key:" << rsa->getPublicKey();

    sendToClient(socketDescriptor, 0, rsa->getPublicKey()); // Отправка клиенту публичного ключа для шифрования данных

    qDebug() << "Current number of clients:" << sockets.size();
}

void Server::prepareData(qintptr descriptor, quint16 key, const QByteArray &message)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    out << quint16(0) << key << encode(descriptor, message);
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));
}

void Server::sendToClient(qintptr descriptor, quint16 key, const QByteArray &message)
{
    qDebug() << "Sending to client...";

    prepareData(descriptor, key, message);

    QTcpSocket* socket = sockets[descriptor];
    if (socket == nullptr) { sockets.remove(descriptor); }
    else {
        socket->write(data);
        socket->flush();
    }

    qDebug() << "Successfully sent data to client with descriptor" << descriptor;
}

void Server::sendToClient(qintptr descriptor, quint16 key, const QJsonDocument &json)
{
    sendToClient(descriptor, key, json.toJson());
}

void Server::sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument &json) // TODO: единный ключ шифрования для всех запросов, чтобы не шифровать каждый запрос ассиметричным ключем клиента?
{
    qDebug() << "Sending to client...";

    QTcpSocket* socket;
    for (qintptr x : descriptors) {
        socket = sockets[x];
        if (socket == nullptr) { sockets.remove(x); }
        else {
            prepareData(x, key, json.toJson());
            socket->write(data);

            socket->flush();
        }
    }

    qDebug() << "Successfully sent data to clients";
}
