#ifndef AUTHORIZATIONPAGE_H
#define AUTHORIZATIONPAGE_H

#include <QObject>

#include "dto/loginrequest.h"
#include "basepage.h"

class AuthorizationPage: public BasePage
{
    Q_OBJECT
private:
    QString email;
    QString password;

public:
    AuthorizationPage(QObject* parent = nullptr);
    Q_INVOKABLE void sendLoginRequest();
    Q_PROPERTY(QString email READ getEmail WRITE setEmail);
    Q_PROPERTY(QString password READ getPassword WRITE setPassword);

    QString getEmail() const;
    void setEmail(const QString&);
    QString getPassword() const;
    void setPassword(const QString&);

    void notify(quint16 key, const QJsonDocument &object) override;

public slots:
    void login(const QJsonDocument& object);

signals:
    void accessIsAllowed(const unsigned int);
    void accessIsDenied();
};

#endif // AUTHORIZATIONPAGE_H
