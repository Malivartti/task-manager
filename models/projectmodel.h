#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include "basemodel.h"
#include <QString>

class ProjectModel : public BaseModel
{
public:
    QString id;
    QString name;
    ProjectModel();
    ProjectModel(QString id, QString name);
};

#endif // PROJECTMODEL_H
