#ifndef USERTASKREPOSITORY_H
#define USERTASKREPOSITORY_H

#include <QString>
#include <QVector>

#include "../model/usertask.h"
#include "base/repository.h"

class UserTaskRepository : public Repository<UserTask, UserTaskRepository>
{
protected:
    UserTaskRepository();

    friend class Singleton<UserTaskRepository>;

    void prepareQuery(QSqlQuery& query, const UserTask& userTask, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    QVector<UserTask> getByUserId(unsigned int id);
    QVector<UserTask> getByTaskId(unsigned int id);
    UserTask getByUserIdAndTaskId(unsigned int userId, unsigned int taskId);
};

#endif // USERTASKREPOSITORY_H
