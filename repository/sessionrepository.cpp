#include "sessionrepository.h"

SessionRepository::SessionRepository() {}

void SessionRepository::prepareQuery(QSqlQuery &query, const Session &session, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (request == RequestType::InsUpd && session.getId() == 0)) {
        string = "INSERT INTO public.\"Session\" (descriptor, \"userId\", \"startAt\", \"endAt\", \"projectId\") "
                 "VALUES (:descriptor, :userId, :startAt, :endAt, :projectId)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"Session\" "
                 "SET descriptor = :descriptor, \"userId\" = :userId, \"startAt\" = :startAt, \"endAt\" = :endAt, \"projectId\" = :projectId "
                 "WHERE \"sessionId\" = :id";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"Session\" WHERE \"sessionId\" = :id";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":id", session.getId());
    query.bindValue(":descriptor", session.getDescriptor());
    query.bindValue(":userId", session.getUserId());
    query.bindValue(":startAt", session.getStartAt());
    query.bindValue(":endAt", session.getEndAt());
    if (session.getProjectId() == 0) {
        query.bindValue(":projectId", QVariant(QMetaType::fromType<int>()));
    }
    else {
        query.bindValue(":projectId", session.getProjectId());
    }
}

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

bool SessionRepository::removeByDescriptor(qintptr descriptor)
{
    qDebug() << "SessionRepository::removeByDescriptor()";
    QSqlQuery query;
    query.prepare(QString("DELETE FROM public.\"Session\" WHERE descriptor = :descriptor"));
    query.bindValue(":descriptor", descriptor);
    return executeQueryBool(query);
}
