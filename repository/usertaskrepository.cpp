#include "usertaskrepository.h"

UserTaskRepository::UserTaskRepository() {}

void UserTaskRepository::prepareQuery(QSqlQuery &query, const UserTask &userTask, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (
            request == RequestType::InsUpd
            && getByUserIdAndTaskId(userTask.getUserId(), userTask.getTaskId()).getUserId() == 0)) {
        string = "INSERT INTO public.\"UserTask\" VALUES (:userId, :taskId)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"UserTask\" "
                 "WHERE \"userId\" = :userId AND \"taskId\" = :taskId";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"UserTask\" "
                 "WHERE \"userId\" = :userId AND \"taskId\" = :taskId";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":userId", userTask.getUserId());
    query.bindValue(":taskId", userTask.getTaskId());
}

QVector<UserTask> UserTaskRepository::getByUserId(unsigned int id)
{
    return getMany("UserTask", "userId", id);
}

QVector<UserTask> UserTaskRepository::getByTaskId(unsigned int id)
{
    return getMany("UserTask", "taskId", id);
}

UserTask UserTaskRepository::getByUserIdAndTaskId(unsigned int userId, unsigned int taskId)
{
    QSqlQuery query;

    query.prepare(QString("SELECT * FROM public.\"UserTask\" WHERE \"userId\" = :userId AND \"taskId\" = :taskId "));
    query.bindValue(":userId", userId);
    query.bindValue(":taskId", taskId);
    return executeQueryOne(query);
}
