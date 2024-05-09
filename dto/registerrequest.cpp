#include "registerrequest.h"

RegisterRequest::RegisterRequest() {}

RegisterRequest::RegisterRequest(const QJsonDocument &json) { fromJson(json); }

RegisterRequest::RegisterRequest(QString email, QString username, QString password)
    : email(email), username(username), password(password) {}

QJsonObject RegisterRequest::toJsonObject() {
    return QJsonObject{
        {"email", email},
        {"username", username},
        {"password", password}
    };
}
