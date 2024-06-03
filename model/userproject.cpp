#include "userproject.h"

UserProject::UserProject() : userId(0), projectId(0), role("None") {}

UserProject::UserProject(QSqlQuery& query)
    : userId(query.value(0).toUInt()), projectId(query.value(1).toUInt()),
    role(query.value(2).toString()) {}

UserProject::UserProject(unsigned int userId, unsigned int projectId, const QString &role)
    : userId(userId), projectId(projectId), role(std::move(role)) {}

unsigned int UserProject::getUserId() const
{
    return userId;
}

unsigned int UserProject::getProjectId() const
{
    return projectId;
}

QString UserProject::getRole() const
{
    return role;
}

void UserProject::setUserId(unsigned int newUserId)
{
    userId = newUserId;
}

void UserProject::setProjectId(unsigned int newProjectId)
{
    projectId = newProjectId;
}

void UserProject::setRole(const QString &newRole)
{
    role = newRole;
}
