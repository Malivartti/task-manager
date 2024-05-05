#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>

#include "handler.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    Handler* handler = Handler::getInstance();
    static inline QTcpSocket* socket = nullptr;
    QByteArray data;
    static inline Controller* instance = nullptr;
protected:
    Controller();
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;
    ~Controller() {};
public:
    static Controller* getInstance();
    void connectToServer();
    void sendToServer(const quint16 key, const QJsonDocument &json);
public slots:
    void slotReadyRead();
};

#endif // CONTROLLER_H
