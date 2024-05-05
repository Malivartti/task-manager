#ifndef AUTHORIZATIONPAGE_H
#define AUTHORIZATIONPAGE_H

#include <QObject>

#include "controller.h"
#include "dto/loginrequest.h"

class AuthorizationPage: public QObject
{
    Q_OBJECT
public:
    AuthorizationPage(QObject* parent = nullptr);
    Q_INVOKABLE void log_in();
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged);

    QString email() const;
    void setEmail(const QString&);
    QString password() const;
    void setPassword(const QString&);

public slots:
    void login(const QJsonDocument& object);

signals:
    void emailChanged(const QString&);
    void passwordChanged(const QString&);
    void accessIsAllowed(const QString& id);
    void accessIsDenied();
private:
    QString m_email;
    QString m_password;
    static inline Controller* controller = Controller::getInstance();
    static inline Handler* handler = Handler::getInstance();
};

#endif // AUTHORIZATIONPAGE_H
