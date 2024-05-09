#ifndef REGISTERREQUEST_H
#define REGISTERREQUEST_H

#include "dto/base/datatransferobject.h"

class RegisterRequest : public DataTransferObject
{
public:
    QString email;
    QString username;
    QString password;

    RegisterRequest();
    RegisterRequest(const QJsonDocument &json);
    RegisterRequest(QString email, QString username, QString password);

    QJsonObject toJsonObject() override;
};

#endif // REGISTERREQUEST_H
