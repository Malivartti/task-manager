#include "registrationpage.h"

RegistrationPage::RegistrationPage(QObject *parent)
{
    connect(handler, &Handler::reg, this, &RegistrationPage::reg);
}

void RegistrationPage::sign_in() {
    qDebug() << m_email << m_nikname << m_password << RegisterRequest(m_email, m_nikname, m_password).toJson();
    controller->sendToServer(2, RegisterRequest(m_email, m_nikname, m_password).toJson());
}

QString RegistrationPage::nikname() const {
    return m_nikname;
}
void RegistrationPage::setNikname(const QString& text) {
    if (text != m_nikname) {
        m_nikname = text;
        emit niknameChanged(text);
    }
}

QString RegistrationPage::email() const {
    return m_email;
}
void RegistrationPage::setEmail(const QString& text) {
    if (text != m_email) {
        m_email = text;
        emit emailChanged(text);
    }
}

QString RegistrationPage::password() const {
    return m_password;
}
void RegistrationPage::setPassword(const QString& text) {
    if (text != m_password) {
        m_password = text;
        emit passwordChanged(text);
    }
}

void RegistrationPage::reg(const QJsonDocument &object)
{
    if (object["head"]["code"].toInt() == 0) {
        emit accessIsDenied();
    }
    else {
        emit accessIsAllowed(QString::number(object["body"]["id"].toInt()));
    }
}
