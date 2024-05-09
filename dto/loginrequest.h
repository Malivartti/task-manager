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

    QJsonObject toJsonObject() override;
};


#endif // LOGINREQUEST_H
