#ifndef SESSIONREPOSITORY_H
#define SESSIONREPOSITORY_H

#include <QString>

#include "model/session.h"
#include "base/repository.h"

class SessionRepository : public Repository<Session, SessionRepository>
{
protected:
    SessionRepository();

    friend class Singleton<SessionRepository>;

    void prepareQuery(QSqlQuery& query, const Session& session, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    Session getById(unsigned int id);
    Session getByDescriptor(qintptr descriptor);
    QVector<Session> getByUserId(unsigned int userId);
    QVector<Session> getByProjectId(unsigned int projectId);

    QVector<qintptr> getListeningDescriptors(qintptr descriptor);

    bool setProjectId(unsigned int sessionId, unsigned int projectId); // Добавить реализацию

    bool removeByDescriptor(qintptr descriptor);
};

#endif // SESSIONREPOSITORY_H
