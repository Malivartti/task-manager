#ifndef PROJECTREPOSITORY_H
#define PROJECTREPOSITORY_H

#include <QString>

#include "model/project.h"
#include "base/repository.h"

class ProjectRepository : public Repository<Project>
{
protected:
    ProjectRepository();
public:
    Project getById(unsigned int id);
    Project getByName(const QString& name);

    bool save(const Project& project);
    bool remove(const Project& project);
};

#endif // PROJECTREPOSITORY_H
