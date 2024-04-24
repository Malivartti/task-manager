#include "userprojectrepository.h"

UserProjectRepository::UserProjectRepository() {}

QVector<UserProject> UserProjectRepository::getByUserId(unsigned int id)
{
    return getMany("UserProject", "userId", id);
}

QVector<UserProject> UserProjectRepository::getByProjectId(unsigned int id)
{
    return getMany("UserProject", "projectId", id);
}

bool UserProjectRepository::save(UserProject userProject)
{
    QSqlQuery query;
    //prepareQuery(query, model, field, value);
    query.prepare(QString("SELECT * FROM public.\"UserProject\" WHERE \"userId\" = :userId AND \"projectId\" = :projectId "));
    query.bindValue(":userId", userProject.getUserId());
    query.bindValue(":projectId", userProject.getProjectId());
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
        return false;
    }

    if (query.size() == 0) {
        query.prepare(QString("INSERT INTO public.\"UserProject\" VALUES (:userId, :projectId, :role)"));
    }
    else {
        query.prepare(QString("UPDATE public.\"UserProject\""
                              "SET role = :role"
                              "WHERE \"userId\" = :userId AND \"projectId\" = :projectId"));
    }
    query.bindValue(":userId", userProject.getUserId());
    query.bindValue(":projectId", userProject.getProjectId());
    query.bindValue(":role", userProject.getRole());
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
        return false;
    }
    return true;
}

bool UserProjectRepository::remove(UserProject userProject)
{

}
