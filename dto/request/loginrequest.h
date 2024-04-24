#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "dto/base/datatransferobject.h"

class LoginRequest : public DataTransferObject
{
public:
    QString login;
    QString password;

    LoginRequest();
    LoginRequest(QString login, QString password);

    void fromJson(QJsonDocument& json) override;
};

#endif // LOGINREQUEST_H
