#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "dto/base/datatransferobject.h"

class LoginRequest : public DataTransferObject
{
public:
    QString login;
    QString password;

    LoginRequest();
    LoginRequest(const QJsonDocument& json);
    LoginRequest(QString login, QString password);

    void fromJson(const QJsonDocument& json) override;
};

#endif // LOGINREQUEST_H
