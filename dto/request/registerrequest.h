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
    RegisterRequest(QString email, QString username, QString password);

    void fromJson(QJsonDocument& json) override;
};

#endif // REGISTERREQUEST_H
