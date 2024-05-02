#ifndef USERPROJECTREPOSITORY_H
#define USERPROJECTREPOSITORY_H

#include <QString>
#include <QVector>

#include "model/userproject.h"
#include "base/repository.h"

class UserProjectRepository : public Repository<UserProject>
{
protected:
    UserProjectRepository();
public:
    QVector<UserProject> getByUserId(unsigned int id);
    QVector<UserProject> getByProjectId(unsigned int id);
    UserProject getByUserIdAndProjectId(unsigned int userId, unsigned int projectId);

    bool save(const UserProject& userProject);
    bool remove(const UserProject& userProject);
};

#endif // USERPROJECTREPOSITORY_H
