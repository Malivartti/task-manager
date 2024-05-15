#ifndef USERPROJECTREPOSITORY_H
#define USERPROJECTREPOSITORY_H

#include <QString>
#include <QVector>

#include "model/userproject.h"
#include "base/repository.h"

class UserProjectRepository : public Repository<UserProject, UserProjectRepository>
{
protected:
    UserProjectRepository();

    friend class Singleton<UserProjectRepository>;

    void prepareQuery(QSqlQuery& query, const UserProject& userProject, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    QVector<UserProject> getByUserId(unsigned int id);
    QVector<UserProject> getByProjectId(unsigned int id);
    UserProject getByUserIdAndProjectId(unsigned int userId, unsigned int projectId);
};

#endif // USERPROJECTREPOSITORY_H
