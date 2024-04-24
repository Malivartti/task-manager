#include "userresponse.h"

UserResponse::UserResponse() : userId(0) {}
UserResponse::UserResponse(unsigned int userId, QString email, QString username)
    : userId(userId), email(email), username(username) {}

QJsonDocument UserResponse::toJson() {
    return QJsonDocument(
        QJsonObject{
            {"id", userId},
            {"email", email},
            {"username", username}
        }
    );
}
