#include "authorizationpage.h"

AuthorizationPage::AuthorizationPage(QObject *parent)
{
    handler->addPage(this);
}

void AuthorizationPage::sendLoginRequest() {
    controller->sendToServer(1, LoginRequest(email, password).toJson());
}

QString AuthorizationPage::getEmail() const {
    return email;
}
void AuthorizationPage::setEmail(const QString& text) {
    if (text != email) {
        email = text;
    }
}

QString AuthorizationPage::getPassword() const {
    return password;
}

void AuthorizationPage::setPassword(const QString& text) {
    if (text != password) {
        password = text;
    }
}

void AuthorizationPage::notify(quint16 key, const QJsonDocument &object)
{
    if (key == 1) login(object);
}

void AuthorizationPage::login(const QJsonDocument &object)
{
    qDebug() << "AuthorizationPage::login()";
    if (object["head"]["code"].toInt() == 0) {
        emit accessIsDenied();
    }
    else {
        emit accessIsAllowed(object["body"]["id"].toInt());
    }
}
