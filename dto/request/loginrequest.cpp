#include "loginrequest.h"

LoginRequest::LoginRequest() {}

LoginRequest::LoginRequest(QString login, QString password)
    : login(login), password(password) {}

void LoginRequest::fromJson(QJsonDocument &json) {
    login = json["login"].toString();
    password = json["password"].toString();
}
