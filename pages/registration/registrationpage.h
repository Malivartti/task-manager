#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include "basepage.h"
#include "dto/registerrequest.h"

class RegistrationPage : public BasePage
{
    Q_OBJECT
private:
    QString username;
    QString email;
    QString password;

public:
    RegistrationPage(QObject* parent = nullptr);
    Q_INVOKABLE void sendSignUpRequest();
    Q_PROPERTY(QString username READ getUsername WRITE setUsername);
    Q_PROPERTY(QString email READ getEmail WRITE setEmail);
    Q_PROPERTY(QString password READ getPassword WRITE setPassword);

    QString getUsername() const;
    void setUsername(const QString&);
    QString getEmail() const;
    void setEmail(const QString&);
    QString getPassword() const;
    void setPassword(const QString&);

    void notify(quint16 key, const QJsonDocument &object) override;

public slots:
    void signUp(const QJsonDocument& object);

signals:
    void accessIsAllowed(const unsigned int);
    void accessIsDenied();
};

#endif // REGISTRATIONPAGE_H
