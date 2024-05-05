#include "homerecentprojectmodel.h"

HomeRecentProjectModel::HomeRecentProjectModel(unsigned int id, QString name, OwnerModel* owner, unsigned int completedTasksNumber, unsigned int assignedTasksNumber):
    id{id}, name{name}, owner{owner}, completedTasksNumber{completedTasksNumber}, assignedTasksNumber{assignedTasksNumber} {};
