#ifndef TASKREPOSITORY_H
#define TASKREPOSITORY_H

#include <QString>

#include "../model/task.h"
#include "base/repository.h"

class TaskRepository : public Repository<Task, TaskRepository>
{
protected:


    TaskRepository();

    friend class Singleton<TaskRepository>;

    void prepareQuery(QSqlQuery& query, const Task& task, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    Task getById(unsigned int id);
    QVector<Task> getByProjectId(unsigned int id);
};

#endif // TASKREPOSITORY_H
