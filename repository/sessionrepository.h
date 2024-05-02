#ifndef SESSIONREPOSITORY_H
#define SESSIONREPOSITORY_H

#include <QString>

#include "model/session.h"
#include "base/repository.h"

class SessionRepository : public Repository<Session>
{
protected:
    SessionRepository();
public:
    Session getById(unsigned int id);
    Session getByDescriptor(qintptr descriptor);
    QVector<Session> getByUserId(unsigned int userId);
    QVector<Session> getByProjectId(unsigned int projectId);

    QVector<qintptr> getListeningDescriptors(qintptr descriptor);

    bool save(const Session& session);
    bool remove(const Session& session);
};

#endif // SESSIONREPOSITORY_H
