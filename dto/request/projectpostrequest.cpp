#include "projectpostrequest.h"

ProjectPostRequest::ProjectPostRequest() {}

ProjectPostRequest::ProjectPostRequest(const QJsonDocument &json) { fromJson(json); }

ProjectPostRequest::ProjectPostRequest(QString name, QString description)
    : name(name), description(description) {}

void ProjectPostRequest::fromJson(const QJsonDocument& json) {
    name = json["name"].toString();
    description = json["description"].toString();
}

