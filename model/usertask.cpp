#include "usertask.h"

unsigned int UserTask::getUserId() const
{
    return userId;
}

unsigned int UserTask::getTaskId() const
{
    return taskId;
}

void UserTask::setUserId(unsigned int newUserId)
{
    userId = newUserId;
}

void UserTask::setTaskId(unsigned int newTaskId)
{
    taskId = newTaskId;
}

UserTask::UserTask() : userId(0), taskId(0) {}

UserTask::UserTask(QSqlQuery &query)
    : userId(query.value(0).toUInt()), taskId(query.value(1).toUInt()) {}

UserTask::UserTask(unsigned int userId, unsigned int taskId)
    : userId(userId), taskId(taskId) {}
