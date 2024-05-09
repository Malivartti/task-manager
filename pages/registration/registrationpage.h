#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QObject>

#include "controller.h"
#include "dto/registerrequest.h"

class RegistrationPage : public QObject
{
    Q_OBJECT
public:
    RegistrationPage(QObject* parent = nullptr);
    Q_INVOKABLE void sign_in();
    Q_PROPERTY(QString nikname READ nikname WRITE setNikname NOTIFY niknameChanged);
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged);

    QString nikname() const;
    void setNikname(const QString&);
    QString email() const;
    void setEmail(const QString&);
    QString password() const;
    void setPassword(const QString&);

public slots:
    void reg(const QJsonDocument& object);

signals:
    void niknameChanged(const QString&);
    void emailChanged(const QString&);
    void passwordChanged(const QString&);
    void accessIsAllowed(const QString id_user);
    void accessIsDenied();
private:
    QString m_nikname;
    QString m_email;
    QString m_password;
    static inline Controller* controller = Controller::getInstance();
    static inline Handler* handler = Handler::getInstance();
};

#endif // REGISTRATIONPAGE_H
