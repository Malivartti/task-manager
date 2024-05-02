#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QMap>
#include <QJsonDocument>

#include "base/baseserver.h"
#include "base/dbconnection.h"
#include "controller/applicationcontroller.h"

class Server : public BaseServer
{
    //Q_OBJECT
protected:
    QTcpSocket* socket;
    //QVector<QTcpSocket*> sockets;
    //QMap<qintptr, QTcpSocket*> sockets;
    QByteArray data;

    ApplicationController* controller;
    friend class ApplicationController;
public:
    Server();
    ~Server();

    void sendToClient(const quint16 key, const QJsonDocument& json) override;
    void sendToClient(QTcpSocket* socket, QByteArray& data) override;
    virtual void sendToClient(qintptr descriptor, quint16 key, const QJsonDocument& json) override;
    virtual void sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument& json) override;
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void clientDisconnected(); // DEPRECATED
    void slotReadyRead();

};

#endif // SERVER_H
