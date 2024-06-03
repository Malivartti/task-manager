#include "userprojectrepository.h"

UserProjectRepository::UserProjectRepository() {}

void UserProjectRepository::prepareQuery(QSqlQuery &query, const UserProject &userProject, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (
            request == RequestType::InsUpd
            && getByUserIdAndProjectId(userProject.getUserId(), userProject.getProjectId()).getUserId() == 0)) {
        string = "INSERT INTO public.\"UserProject\" VALUES (:userId, :projectId, :role)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"UserProject\" "
                 "SET role = :role "
                 "WHERE \"userId\" = :userId AND \"projectId\" = :projectId";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"UserProject\" "
                 "WHERE \"userId\" = :userId AND \"projectId\" = :projectId";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":userId", userProject.getUserId());
    query.bindValue(":projectId", userProject.getProjectId());
    query.bindValue(":role", userProject.getRole());
}

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
    return executeQueryOne(query);
}
