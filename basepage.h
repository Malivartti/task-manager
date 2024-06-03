#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>

#include "security/encoder.h"
#include "model/project.h"

class Handler;

class Controller;

class BasePage : public QObject
{
    Q_OBJECT
protected:
    //static inline QVector<Project> projects;

    static inline unsigned int userId = 0;
    static inline Handler* handler = nullptr;
    static inline Controller* controller = nullptr;

signals:
    void userIdChanged();

public:
    BasePage();
    Q_PROPERTY(unsigned int userId READ getUserId WRITE setUserId NOTIFY userIdChanged);

    unsigned int getUserId() const;
    void setUserId(const unsigned int);

    virtual void notify(quint16 key, const QJsonDocument &response) = 0;
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
    RSAEncoder* rsa = RSAEncoder::getInstance();
    // AESEncoder* aes = AESEncoder::getInstance();

    QByteArray serverPublicKey;
    bool isServerPublicKeySet = false;

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

    QByteArray encode(const QByteArray& data);
    QByteArray decode(const QByteArray& data);

    void sendToServer(const quint16 key, const QByteArray &message);
    void sendToServer(const quint16 key, const QJsonDocument &json);
public slots:
    void slotReadyRead();
};

#endif // BASEPAGE_H
