#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QJsonDocument>

#include "base/dbconnection.h"
#include "controller/applicationcontroller.h"

class Server : public QTcpServer
{
    Q_OBJECT
protected:
    QTcpSocket* socket;
    QVector<QTcpSocket*> sockets;
    QByteArray data;

    ApplicationController* controller;
public:
    Server();

    void sendToClient(const quint16 key, const QJsonDocument& json);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void clientDisconnected();
    void slotReadyRead();

};

#endif // SERVER_H
