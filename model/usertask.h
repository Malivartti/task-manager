#ifndef USERTASK_H
#define USERTASK_H

#include <QString>
#include <QVariant>

#include "base/model.h"

class UserTask : public Model
{
private:
    unsigned int userId;
    unsigned int taskId;
public:
    UserTask();
    UserTask(QSqlQuery& query);
    UserTask(unsigned int userId, unsigned int taskId);

    unsigned int getUserId() const;
    unsigned int getTaskId() const;

    void setUserId(unsigned int newUserId);
    void setTaskId(unsigned int newTaskId);
};

#endif // USERTASK_H
