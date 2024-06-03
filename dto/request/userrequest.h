#ifndef USERREQUEST_H
#define USERREQUEST_H

#include "../base/datatransferobject.h"

class UserRequest : public DataTransferObject
{
public:
    int userId;
    QString email;
    QString username;
    QString password;

    UserRequest();
    UserRequest(const QJsonDocument &json);
    UserRequest(unsigned int id, QString email, QString username, QString password);

    void fromJson(const QJsonDocument& json) override;
};

#endif // USERREQUEST_H
