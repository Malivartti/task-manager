#include "project.h"

Project::Project() {}

Project::Project(int projectId, const QString &name, const QString &description, const User &owner, int createdAt)
    : projectId(projectId), name(std::move(name)),
    description(std::move(description)), owner(std::move(owner)),
    createdAt(createdAt) {}

Project::Project(const QJsonValue &object)
    : projectId(object["id"].toInt()), name(object["name"].toString()),
    description(object["description"].toString()), owner(object["ownerId"]),
    createdAt(object["createdAt"].toInt()) {}

QVariantMap Project::toVariantMap() const
{
    return  QVariantMap{
       {"id", projectId},
       {"name", name},
       {"description", description},
       {"owner", owner.toVariantMap()},
       {"createdAt", createdAt},
    };
}
