#include "registerrequest.h"

RegisterRequest::RegisterRequest() {}

RegisterRequest::RegisterRequest(const QJsonDocument &json) { fromJson(json); }

RegisterRequest::RegisterRequest(QString email, QString username, QString password)
    : email(email), username(username), password(password) {}

void RegisterRequest::fromJson(const QJsonDocument& json) {
    email = json["email"].toString();
    username = json["username"].toString();
    password = json["password"].toString();
}
