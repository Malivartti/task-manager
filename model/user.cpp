#include "user.h"

User::User() {}

User::User(unsigned int userId, const QString& email, const QString& username)
    : userId(userId), email(std::move(email)), username(std::move(username)) {}

User::User(const QJsonValue &object)
    : userId(object["id"].toInt()), email(object["email"].toString()),
    username(object["username"].toString()) {}

QVariantMap User::toVariantMap() const
{
    return  QVariantMap{
        {"id", userId},
        {"email", email},
        {"username", username}
    };
}
