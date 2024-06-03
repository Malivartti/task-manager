#ifndef USER_H
#define USER_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

class User
{
public:
    unsigned int userId;
    QString email;
    QString username;

    User();
    User(unsigned int userId, const QString& email, const QString& username);

    User(const QJsonValue& object);

    QVariantMap toVariantMap() const;
};

#endif // USER_H
