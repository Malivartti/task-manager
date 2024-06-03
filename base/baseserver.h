#ifndef BASESERVER_H
#define BASESERVER_H

#include <QTcpServer>

class BaseServer: public QTcpServer
{
    Q_OBJECT
protected:
    QMap<qintptr, QTcpSocket*> sockets;

public:
    virtual void sendToClient(qintptr descriptor, quint16 key, const QJsonDocument& json) = 0;
    virtual void sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument& json) = 0;
    BaseServer();
};

#endif // BASESERVER_H
