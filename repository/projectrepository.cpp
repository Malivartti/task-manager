#include "projectrepository.h"

ProjectRepository::ProjectRepository() {}

Project ProjectRepository::getById(unsigned int id) {
    qDebug() << "ProjectRepository::getById()";
    return getOne("Project", "projectId", id);
}

Project ProjectRepository::getByName(QString& name) {
    qDebug() << "ProjectRepository::getByName()";
    return getOne("Project", "name", name);
}

bool ProjectRepository::save(Project project) {
    QSqlQuery query;
    if (project.getId() == 0) {
        query.prepare(QString("INSERT INTO public.\"Project\" (name, description, \"ownerId\", \"createdId\") "
                              "VALUES (:name, :description, :ownerId, :createdId) "));
    }
    else {
        query.prepare(QString("UPDATE public.\"Project\" "
                              "SET name = :name, description = :description, ownerId = :ownerId, createdId = :createdId"
                              "WHERE \"projectId\" = :id "));
        query.bindValue(":id", project.getId());
    }
    query.bindValue(":name", project.getName());
    query.bindValue(":description", project.getDescription());
    query.bindValue(":ownerId", project.getOwnerId());
    query.bindValue(":createdId", project.getCreatedAt());
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
}

bool ProjectRepository::remove(Project project) {

}
