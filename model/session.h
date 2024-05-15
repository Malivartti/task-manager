#ifndef SESSION_H
#define SESSION_H

#include <QString>
#include <QVariant>

#include "base/model.h"

class Session : public Model
{
private:
    unsigned int sessionId;
    qintptr descriptor;
    unsigned int userId;
    unsigned long long startAt;
    unsigned long long endAt;
    unsigned int projectId;

public:
    Session();
    Session(QSqlQuery& query);
    Session(qintptr descriptor, unsigned int userId,
            unsigned long long startAt, unsigned long long endAt, unsigned int projectId);
    Session(unsigned int sessionId, qintptr descriptor,
            unsigned int userId, unsigned long long startAt, unsigned long long endAt,
            unsigned int projectAt);

    unsigned int getId() const;
    qintptr getDescriptor() const;
    unsigned int getUserId() const;
    unsigned long long getStartAt() const;
    unsigned long long getEndAt() const;
    unsigned int getProjectId() const;

    void setId(unsigned int newId);
    void setDescriptor(qintptr newDescriptor);
    void setUserId(unsigned int newUserId);
    void setStartAt(unsigned long long newStartAt);
    void setEndAt(unsigned long long newEndAt);
    void setProjectId(unsigned int newProjectId);
};

#endif // SESSION_H
