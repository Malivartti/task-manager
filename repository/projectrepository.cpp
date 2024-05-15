#include "projectrepository.h"

ProjectRepository::ProjectRepository() {}

void ProjectRepository::prepareQuery(QSqlQuery& query, const Project& project, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (request == RequestType::InsUpd && project.getId() == 0)) {
        string = "INSERT INTO public.\"Project\" (name, description, \"ownerId\", \"createdId\") "
                 "VALUES (:name, :description, :ownerId, :createdId)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"Project\" "
                 "SET name = :name, description = :description, ownerId = :ownerId, createdId = :createdId "
                 "WHERE \"projectId\" = :id";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"Project\" WHERE \"projectId\" = :id";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":id", project.getId());
    query.bindValue(":name", project.getName());
    query.bindValue(":description", project.getDescription());
    query.bindValue(":ownerId", project.getOwnerId());
    query.bindValue(":createdId", project.getCreatedAt());
}

Project ProjectRepository::getById(const unsigned int id) {
    qDebug() << "ProjectRepository::getById()";
    return getOne("Project", "projectId", id);
}

Project ProjectRepository::getByName(const QString& name) {
    qDebug() << "ProjectRepository::getByName()";
    return getOne("Project", "name", name);
}
