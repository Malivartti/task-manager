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
#include "service/authservice.h"
#include "security/encoder.h"

/**
 * @brief The TCP Server.
 * @details Provides functionality for processing Client's requests.
*/
class Server : public BaseServer
{
    //Q_OBJECT
protected:

    QTcpSocket* socket;
    QByteArray data;

    /**
     * @brief The RSA Encoder for encrypting and decrypting Client's requests.
    */
    RSAEncoder* rsa = RSAEncoder::getInstance();
    // AESEncoder* aes = AESEncoder::getInstance();

    QMap<qintptr, QByteArray> keys;

    AuthService* authService = AuthService::getInstance();
    FrontController* controller;

    void setClientPublicKey(qintptr descriptor, const QByteArray& key);

    friend class ApplicationController;
public:
    Server();
    ~Server();

    /**
     * @brief The Method for encrypting Client's requests.
    */
    QByteArray encode(qintptr descriptor, const QByteArray& data);

    /**
     * @brief The Method for decrypting Client's requests.
    */
    QByteArray decode(qintptr descriptor, const QByteArray& data);

    /**
     * @brief The Method for preparing (encrypting, for example) data before sending.
    */
    void prepareData(qintptr descriptor, quint16 key, const QByteArray& message);

    void sendToClient(qintptr descriptor, quint16 key, const QByteArray& message);

    /**
     * @brief The Method for sending response to Client.
    */
    void sendToClient(qintptr descriptor, quint16 key, const QJsonDocument& json) override;

    /**
     * @brief The Method for sending response to group of Clients.
    */
    void sendToClient(const QVector<qintptr>& descriptors, quint16 key, const QJsonDocument& json) override;
public slots:
    /**
     * @brief The Method (slot) for processing incoming connection.
    */
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // SERVER_H
