#include "authpage.h"

AuthPage::AuthPage() {}

void AuthPage::sendLoginRequest(const QString& login, const QString& password)
{
    controller->sendToServer(1, LoginRequest(login, password).toJson());
}

void AuthPage::notify(quint16 key, const QJsonDocument &response)
{
    if (key == 1) { login(response); }
}

void AuthPage::login(const QJsonDocument &response)
{
    if (response["head"]["code"] == 0) { emit accessIsDenied(); }
    else if (response["head"]["code"] == 1) {
        emit accessIsAllowed(
            User(response["body"]).toVariantMap()
        );
    }
}


