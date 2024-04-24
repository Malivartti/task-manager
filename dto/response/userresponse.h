#ifndef USERRESPONSE_H
#define USERRESPONSE_H

#include <QJsonObject>

#include "dto/base/datatransferobject.h"

class UserResponse : public DataTransferObject
{
public:
    int userId;
    QString email;
    QString username;

    UserResponse();
    UserResponse(unsigned int userId, QString email, QString username);

    QJsonDocument toJson() override;
};

#endif // USERRESPONSE_H
