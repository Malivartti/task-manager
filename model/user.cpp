#include "user.h"

User::User() : userId(0) {}

User::User(QSqlQuery& query)
    : userId(query.value(0).toUInt()), email(query.value(1).toString()),
    username(query.value(2).toString()), password(query.value(3).toString()) {}

User::User(QString email, QString username, QString password)
    : userId(0), email(std::move(email)),
    username(std::move(username)), password(std::move(password)) {}

User::User(unsigned int userId, QString email, QString username, QString password)
    : userId(userId), email(std::move(email)),
    username(std::move(username)), password(std::move(password)) {}

unsigned int User::getId() const { return userId; }
QString User::getEmail() const { return email; }
QString User::getUsername() const { return username; }
QString User::getPassword() const { return password; }

void User::setId(unsigned int newId) { userId = newId; }
void User::setEmail(const QString &newEmail) { email = newEmail; }
void User::setUsername(const QString &newUsername) { username = newUsername; }
void User::setPassword(const QString &newPassword) { password = newPassword; }
