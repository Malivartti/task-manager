#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QMap>
#include <QJsonDocument>

#include "base/baseserver.h"
#include "base/dbconnection.h"
#include "controller/frontcontroller.h"

class Server : public BaseServer
{
    //Q_OBJECT
protected:
    QTcpSocket* socket;
    QByteArray data;

    AuthService* authService = AuthService::getInstance();
    FrontController* controller;
    friend class ApplicationController;
public:
    Server();
    ~Server();

    virtual void sendToClient(qintptr descriptor, quint16 key, const QJsonDocument& json) override;
    virtual void sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument& json) override;
public slots:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // SERVER_H
