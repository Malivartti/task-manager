#include "userrequest.h"

UserRequest::UserRequest() : userId(0) {}

UserRequest::UserRequest(const QJsonDocument &json) { fromJson(json); }

UserRequest::UserRequest(unsigned int id, QString email, QString username, QString password)
    : userId(id), email(email), username(username), password(password) {}

void UserRequest::fromJson(const QJsonDocument& json) {
    userId = json["id"].toInt();
    email = json["email"].toString();
    username = json["username"].toString();
    password = json["password"].toString();
}
