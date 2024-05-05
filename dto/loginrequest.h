#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include <QJsonObject>

#include "dto/base/datatransferobject.h"

class LoginRequest : public DataTransferObject
{
public:
    QString login;
    QString password;

    LoginRequest();
    LoginRequest(QString login, QString password);

    QJsonDocument toJson();
};


#endif // LOGINREQUEST_H
