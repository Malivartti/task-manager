#ifndef HOMERECENTPROJECTMODEL_H
#define HOMERECENTPROJECTMODEL_H

#include <QObject>
#include "../owner/ownermodel.h"

class HomeRecentProjectModel : public QObject
{
    Q_OBJECT
public:
    HomeRecentProjectModel(unsigned int id, QString name, OwnerModel* owner, unsigned int completedTasksNumber, unsigned int assignedTasksNumber);
    unsigned int id;
    QString name;
    OwnerModel* owner;
    unsigned int completedTasksNumber;
    unsigned int assignedTasksNumber;
};

#endif // HOMERECENTPROJECTMODEL_H
