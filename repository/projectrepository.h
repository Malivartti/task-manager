#ifndef PROJECTREPOSITORY_H
#define PROJECTREPOSITORY_H

#include <QString>

#include "../model/project.h"
#include "base/repository.h"

class ProjectRepository : public Repository<Project, ProjectRepository>
{
protected:
    ProjectRepository();

    friend class Singleton<ProjectRepository>;

    void prepareQuery(QSqlQuery& query, const Project& project, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    Project getById(unsigned int id);
    Project getByName(const QString& name);
};

#endif // PROJECTREPOSITORY_H
