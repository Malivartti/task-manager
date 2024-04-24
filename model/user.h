#ifndef USER_H
#define USER_H

#include <QString>

#include "base/model.h"

class User : public Model
{
private:
    unsigned int userId;
    QString email;
    QString username;
    QString password;

public:
    User();
    User(QSqlQuery& query);
    User(QString email, QString username, QString password);
    User(unsigned int userId, QString email, QString username, QString password);

    unsigned int getId() const;
    QString getEmail() const;
    QString getUsername() const;
    QString getPassword() const;

    void setId(unsigned int newId);
    void setEmail(const QString &newEmail);
    void setUsername(const QString &newUsername);
    void setPassword(const QString &newPassword);
};

#endif // USER_H
