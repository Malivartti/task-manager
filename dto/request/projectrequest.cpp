#include "projectrequest.h"

ProjectRequest::ProjectRequest() : projectId(0), ownerId(0), createdAt(0) {}

ProjectRequest::ProjectRequest(const QJsonDocument &json) { fromJson(json); }

ProjectRequest::ProjectRequest(QString name, QString description, unsigned int ownerId, unsigned int createdAt)
    : projectId(0), name(name), description(description), ownerId(ownerId), createdAt(createdAt) {}

ProjectRequest::ProjectRequest(unsigned int projectId, QString name, QString description, unsigned int ownerId, unsigned int createdAt)
    : projectId(projectId), name(name), description(description), ownerId(ownerId), createdAt(createdAt) {}

void ProjectRequest::fromJson(const QJsonDocument& json) {
    projectId = json["id"].toInt();
    name = json["name"].toString();
    description = json["description"].toString();
    ownerId = json["ownerId"].toInt();
    createdAt = json["description"].toInt();
}

