#include "authorizationpage.h"

AuthorizationPage::AuthorizationPage(QObject *parent)
{
    connect(handler, &Handler::login, this, &AuthorizationPage::login);
}

void AuthorizationPage::log_in() {
    // if (m_email == "user@mail.com" && m_password == "123") {
    //     emit accessIsAllowed("id_user");
    // } else {
    //     emit accessIsDenied();
    // }

    controller->sendToServer(1, LoginRequest(m_email, m_password).toJson());
}

QString AuthorizationPage::email() const {
    return m_email;
}
void AuthorizationPage::setEmail(const QString& text) {
    if (text != m_email) {
        m_email = text;
        emit emailChanged(text);
    }
}

QString AuthorizationPage::password() const {
    return m_password;
}
void AuthorizationPage::setPassword(const QString& text) {
    if (text != m_password) {
        m_password = text;
        emit passwordChanged(text);
    }
}

void AuthorizationPage::login(const QJsonDocument &object)
{
    qDebug() << "AuthorizationPage::login()";
    if (object["head"]["code"].toInt() == 0) {
        emit accessIsDenied();
    }
    else {
        //qDebug() << "id: " << object["body"]["id"].toInt() << object["body"]["id"].toString() << QString::number(object["body"]["id"].toInt());
        emit accessIsAllowed(QString::number(object["body"]["id"].toInt()));
    }
}
