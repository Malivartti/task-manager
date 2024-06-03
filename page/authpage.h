#ifndef AUTHPAGE_H
#define AUTHPAGE_H

#include "../basepage.h"
#include "../dto/loginrequest.h"
#include "../model/user.h"

class AuthPage : public BasePage
{
    Q_OBJECT
private:
    // QString email;
    // QString password;
public:
    AuthPage();

    Q_INVOKABLE void sendLoginRequest(const QString& login, const QString& password);

    // Q_PROPERTY(QString email READ getEmail WRITE setEmail);
    // Q_PROPERTY(QString password READ getPassword WRITE setPassword);

    // QString getEmail() const;
    // void setEmail(const QString&);
    // QString getPassword() const;
    // void setPassword(const QString&);

    void notify(quint16 key, const QJsonDocument &response) override;

    void login(const QJsonDocument& response);

signals:
    void accessIsAllowed(QVariantMap);
    void accessIsDenied();
};

#endif // AUTHPAGE_H
