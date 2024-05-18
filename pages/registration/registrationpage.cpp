#include "registrationpage.h"

RegistrationPage::RegistrationPage(QObject *parent)
{
    handler->addPage(this);
}

void RegistrationPage::sendSignUpRequest() {
    controller->sendToServer(2, RegisterRequest(email, username, password).toJson());
}

QString RegistrationPage::getUsername() const {
    return username;
}
void RegistrationPage::setUsername(const QString& text) {
    if (text != username) {
        username = text;
    }
}

QString RegistrationPage::getEmail() const {
    return email;
}
void RegistrationPage::setEmail(const QString& text) {
    if (text != email) {
        email = text;
    }
}

QString RegistrationPage::getPassword() const {
    return password;
}
void RegistrationPage::setPassword(const QString& text) {
    if (text != password) {
        password = text;
    }
}

void RegistrationPage::notify(quint16 key, const QJsonDocument &object)
{
    if (key == 2) signUp(object);
}

void RegistrationPage::signUp(const QJsonDocument &object)
{
    qDebug() << "RegistrationPage::signUp()";
    if (object["head"]["code"].toInt() == 0) {
        emit accessIsDenied();
    }
    else {
        emit accessIsAllowed(object["body"]["id"].toInt());
    }
}
