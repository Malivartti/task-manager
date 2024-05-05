#include "loginrequest.h"

LoginRequest::LoginRequest() {}

LoginRequest::LoginRequest(QString login, QString password) : login(login), password(password) {}

QJsonDocument LoginRequest::toJson() {
    return QJsonDocument(
        QJsonObject{
            {"login", login},
            {"password", password}
        }
    );
}
