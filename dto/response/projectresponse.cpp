#include "projectresponse.h"

ProjectResponse::ProjectResponse() : projectId(0), createdAt(0) {}

ProjectResponse::ProjectResponse(unsigned int projectId, QString name,
                                 QString description, UserResponse ownerId,
                                 unsigned int createdAt)
    : projectId(projectId), name(name), description(description),
    ownerId(ownerId), createdAt(createdAt) {}

ProjectResponse::ProjectResponse(unsigned int projectId, QString name,
                                 QString description, UserResponse& ownerId, unsigned int createdAt)
    : projectId(projectId), name(name), description(description),
    ownerId(ownerId), createdAt(createdAt) {}

QJsonDocument ProjectResponse::toJson() {
    return QJsonDocument(
        QJsonObject{
            {"id", projectId},
            {"name", name},
            {"description", description},
            {"ownerId", ownerId.toJson().object()},
            {"createdAt", createdAt},
        }
    );
}
