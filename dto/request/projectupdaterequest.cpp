#include "projectupdaterequest.h"

ProjectUpdateRequest::ProjectUpdateRequest() : projectId(0), ownerId(0) {}

ProjectUpdateRequest::ProjectUpdateRequest(const QJsonDocument &json) { fromJson(json); }

ProjectUpdateRequest::ProjectUpdateRequest(QString name, QString description, unsigned int ownerId)
    : projectId(0), name(name), description(description), ownerId(ownerId) {}

ProjectUpdateRequest::ProjectUpdateRequest(unsigned int projectId, QString name, QString description, unsigned int ownerId)
    : projectId(projectId), name(name), description(description), ownerId(ownerId) {}

void ProjectUpdateRequest::fromJson(const QJsonDocument& json) {
    projectId = json["id"].toInt();
    name = json["name"].toString();
    description = json["description"].toString();
    ownerId = json["ownerId"].toInt();
}

