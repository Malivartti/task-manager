#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>

class Handler;

class Controller;

class BasePage : public QObject
{
    Q_OBJECT
protected:
    static inline Handler* handler = nullptr;
    static inline Controller* controller = nullptr;

public:
    BasePage();
    virtual void notify(quint16 key, const QJsonDocument &object) = 0;
};

class Handler : public QObject
{
    Q_OBJECT
private:
    static inline Handler* instance = nullptr;
    QSet<BasePage*> buffer;

protected:
    Handler();

public:
    static Handler* getInstance();
    void addPage(BasePage* page);
    void removePage(BasePage* page);
    void mapRequest(quint16 key, const QJsonDocument& object);
};

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

#endif // BASEPAGE_H
