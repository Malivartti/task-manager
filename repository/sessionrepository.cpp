#include "sessionrepository.h"

SessionRepository::SessionRepository() {}

Session SessionRepository::getById(unsigned int id)
{
    return getOne("Session", "sessionId", id);
}

Session SessionRepository::getByDescriptor(qintptr descriptor)
{
    return getOne("Session", "descriptor", descriptor);
}

QVector<Session> SessionRepository::getByUserId(unsigned int userId)
{
    qDebug() << "SessionRepository::getByUserId";
    return getMany("Session", "userId", userId);
}

QVector<Session> SessionRepository::getByProjectId(unsigned int projectId)
{
    return getMany("Session", "sessionId", projectId);
}

QVector<qintptr> SessionRepository::getListeningDescriptors(qintptr descriptor)
{
    QSqlQuery query;
    query.prepare(QString("SELECT descriptor FROM public.\"Session\" "
                          "WHERE \"projectId\" = (SELECT \"projectId\" FROM public.\"Session\" WHERE descriptor = :descriptor)"));
    query.bindValue(":descriptor", descriptor);

    QVector<qintptr> vec;
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
    }
    else {
        while (query.next()) {
            vec.append(query.value(0).toLongLong());
        }
    }
    return vec;
}

bool SessionRepository::save(const Session& session)
{
    qDebug() << "Inside SessionRepository::save()";
    QSqlQuery query;
    qDebug() << "Created query";
    if (session.getId() == 0) {
        qDebug() << "INSERT";
        query.prepare(QString("INSERT INTO public.\"Session\" (descriptor, \"userId\", \"startAt\", \"endAt\") "
                              "VALUES (:descriptor, :userId, :startAt, :endAt) "));
    }
    else {
        qDebug() << "UPDATE";
        query.prepare(QString("UPDATE public.\"Session\" "
                              "SET descriptor = :descriptor, \"userId\" = :userId, \"startAt\" = :startAt, \"endAt\" = :endAt, \"projectId\" = :projectId"
                              "WHERE \"sessionId\" = :id "));
        query.bindValue(":id", session.getId());
        query.bindValue(":projectId", session.getProjectId());
    }
    qDebug() << "CREATED";
    query.bindValue(":descriptor", session.getDescriptor());
    query.bindValue(":userId", session.getUserId());
    query.bindValue(":startAt", session.getStartAt());
    query.bindValue(":endAt", session.getEndAt());
    //query.bindValue(":projectId", session.getProjectId());
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
}

bool SessionRepository::remove(const Session& session)
{

}
