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

    bool save(UserProject userProject) override;
    bool remove(UserProject userProject) override;
};

#endif // USERPROJECTREPOSITORY_H
