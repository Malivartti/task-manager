#include "userresponse.h"

UserResponse::UserResponse() : userId(0) {}
UserResponse::UserResponse(unsigned int userId, QString email, QString username)
    : userId(userId), email(email), username(username) {}

QJsonObject UserResponse::toJsonObject()
{
    return QJsonObject{
        {"id", userId},
        {"email", email},
        {"username", username}
    };
}
