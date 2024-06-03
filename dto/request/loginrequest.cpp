#include "loginrequest.h"

LoginRequest::LoginRequest() {}

LoginRequest::LoginRequest(const QJsonDocument &json) { fromJson(json); }

LoginRequest::LoginRequest(QString login, QString password)
    : login(login), password(password) {}

void LoginRequest::fromJson(const QJsonDocument &json) {
    login = json["login"].toString();
    password = json["password"].toString();
}
