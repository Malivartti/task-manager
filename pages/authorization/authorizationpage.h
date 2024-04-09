#ifndef AUTHORIZATIONPAGE_H
#define AUTHORIZATIONPAGE_H

#include <QObject>

class AuthorizationPage: public QObject
{
    Q_OBJECT
public:
    AuthorizationPage(QObject* parent = nullptr) {}
    Q_INVOKABLE void log_in();
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged);

    QString email() const;
    void setEmail(const QString&);
    QString password() const;
    void setPassword(const QString&);

signals:
    void emailChanged(const QString&);
    void passwordChanged(const QString&);
    void accessIsAllowed(const QString id_user);
    void accessIsDenied();
private:
    QString m_email;
    QString m_password;
};

#endif // AUTHORIZATIONPAGE_H
