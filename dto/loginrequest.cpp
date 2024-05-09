#include "loginrequest.h"

LoginRequest::LoginRequest() {}

LoginRequest::LoginRequest(QString login, QString password) : login(login), password(password) {}

QJsonObject LoginRequest::toJsonObject() {
    return QJsonObject{
        {"login", login},
        {"password", password}
    };
}
