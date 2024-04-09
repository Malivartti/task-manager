#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QObject>

class RegistrationPage : public QObject
{
    Q_OBJECT
public:
    RegistrationPage(QObject* parent = nullptr) {}
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
};

#endif // REGISTRATIONPAGE_H
