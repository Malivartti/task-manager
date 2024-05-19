#include "taskrepository.h"

TaskRepository::TaskRepository() {}

void TaskRepository::prepareQuery(QSqlQuery& query, const Task& task, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (request == RequestType::InsUpd && task.getId() == 0)) {
        string = "INSERT INTO public.\"Task\" (name, description, \"projectId\", \"sprintId\", \"creatorId\", \"startAt\", \"endAt\", \"resolvedAt\") "
                 "VALUES (:name, :description, :projectId, :sprintId, :creatorId, :startAt, :endAt, :resolvedAt)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"Task\" "
                 "SET name = :name, description = :description, projectId = :projectId, sprintId = :sprintId, "
                 "creatorId = :creatorId, startAt = :startAt, endAt = :endAt, resolvedAt = :resolvedAt "
                 "WHERE \"taskId\" = :id";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"Task\" WHERE \"taskId\" = :id";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":id", task.getId());
    query.bindValue(":name", task.getName());
    query.bindValue(":description", task.getDescription());
    query.bindValue(":projectId", task.getProjectId());
    if (task.getSprintId() == 0) {
        query.bindValue(":sprintId", QVariant(QMetaType::fromType<int>()));
    }
    else {
        query.bindValue(":sprintId", task.getSprintId());
    }
    query.bindValue(":creatorId", task.getCreatorId());
    query.bindValue(":startAt", task.getStartAt());
    query.bindValue(":endAt", task.getEndAt());
    query.bindValue(":resolvedAt", task.getResolvedAt());
}

Task TaskRepository::getById(unsigned int id)
{
    qDebug() << "TaskRepository::getById()";
    return getOne("Task", "taskId", id);
}
