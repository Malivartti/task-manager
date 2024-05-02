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

UserProject UserProjectRepository::getByUserIdAndProjectId(unsigned int userId, unsigned int projectId)
{
    QSqlQuery query;

    query.prepare(QString("SELECT * FROM public.\"UserProject\" WHERE \"userId\" = :userId AND \"projectId\" = :projectId "));
    query.bindValue(":userId", userId);
    query.bindValue(":projectId", projectId);
    if (!query.exec() || query.lastError().type() != QSqlError::NoError) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
    }
    else {
        while (query.next()) {
            return UserProject(query);
        }
    }
    return UserProject();
}


bool UserProjectRepository::save(const UserProject& userProject)
{
    QSqlQuery query;

    // query.prepare(QString("SELECT * FROM public.\"UserProject\" WHERE \"userId\" = :userId AND \"projectId\" = :projectId "));
    // query.bindValue(":userId", userProject.getUserId());
    // query.bindValue(":projectId", userProject.getProjectId());
    // if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
    //     qDebug() << "During executing a query error occured: " << query.lastError().text();
    //     return false;
    // }

    if (getByUserIdAndProjectId(userProject.getUserId(), userProject.getProjectId()).getUserId() == 0) {
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

bool UserProjectRepository::remove(const UserProject& userProject)
{

}
