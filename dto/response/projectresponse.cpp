#include "projectresponse.h"

ProjectResponse::ProjectResponse() : projectId(0), createdAt(0) {}

ProjectResponse::ProjectResponse(unsigned int projectId, QString name,
                                 QString description, const UserResponse& ownerId, unsigned int createdAt)
    : projectId(projectId), name(std::move(name)), description(std::move(description)),
    ownerId(ownerId), createdAt(createdAt) {}

QJsonObject ProjectResponse::toJsonObject()
{
    return QJsonObject{
        {"id", projectId},
        {"name", name},
        {"description", description},
        {"ownerId", ownerId.toJsonObject()},
        {"createdAt", createdAt}
    };
}
