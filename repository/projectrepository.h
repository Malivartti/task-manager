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
    Project getByName(QString& name);

    bool save(Project project) override;
    bool remove(Project project) override;
};

#endif // PROJECTREPOSITORY_H
