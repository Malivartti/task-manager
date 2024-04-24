#ifndef USERPROJECT_H
#define USERPROJECT_H

#include <QString>

#include "base/model.h"

class UserProject : public Model
{
private:
    unsigned int userId;
    unsigned int projectId;
    QString role;
public:
    UserProject();
    UserProject(QSqlQuery& query);
    UserProject(unsigned int userId, unsigned int projectId, const QString &role);

    unsigned int getUserId() const;
    unsigned int getProjectId() const;
    QString getRole() const;

    void setUserId(unsigned int newUserId);
    void setProjectId(unsigned int newProjectId);
    void setRole(const QString &newRole);
};

#endif // USERPROJECT_H
