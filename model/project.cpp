#include "project.h"

Project::Project() : projectId(0), ownerId(0), createdAt(0) {}

Project::Project(QSqlQuery& query)
    : projectId(query.value(0).toUInt()), name(query.value(1).toString()),
    description(query.value(2).toString()), ownerId(query.value(3).toUInt()),
    createdAt(query.value(4).toUInt()) {}

Project::Project(QString name, QString description, unsigned int ownerId, unsigned int createdAt)
    : projectId(0), name(std::move(name)),
    description(std::move(description)), ownerId(ownerId),
    createdAt(createdAt) {}

Project::Project(unsigned int projectId, QString name, QString description, unsigned int ownerId, unsigned int createdAt)
    : projectId(projectId), name(std::move(name)),
    description(std::move(description)), ownerId(ownerId),
    createdAt(createdAt) {}

unsigned int Project::getId() const
{
    return projectId;
}

QString Project::getName() const
{
    return name;
}

QString Project::getDescription() const
{
    return description;
}

unsigned int Project::getOwnerId() const
{
    return ownerId;
}

unsigned int Project::getCreatedAt() const
{
    return createdAt;
}

void Project::setId(unsigned int newId)
{
    projectId = newId;
}

void Project::setName(const QString &newName)
{
    name = newName;
}

void Project::setDescription(const QString &newDescription)
{
    description = newDescription;
}

void Project::setOwnerId(unsigned int newOwnerId)
{
    ownerId = newOwnerId;
}

void Project::setCreatedAt(unsigned int newCreatedAt)
{
    createdAt = newCreatedAt;
}
