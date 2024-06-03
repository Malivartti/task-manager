#include "session.h"

unsigned int Session::getId() const
{
    return sessionId;
}

qintptr Session::getDescriptor() const
{
    return descriptor;
}

unsigned int Session::getUserId() const
{
    return userId;
}

unsigned long long Session::getStartAt() const
{
    return startAt;
}

unsigned long long Session::getEndAt() const
{
    return endAt;
}

unsigned int Session::getProjectId() const
{
    return projectId;
}

void Session::setId(unsigned int newId)
{
    sessionId = newId;
}

void Session::setDescriptor(qintptr newDescriptor)
{
    descriptor = newDescriptor;
}

void Session::setUserId(unsigned int newUserId)
{
    userId = newUserId;
}

void Session::setStartAt(unsigned long long newStartAt)
{
    startAt = newStartAt;
}

void Session::setEndAt(unsigned long long newEndAt)
{
    endAt = newEndAt;
}

void Session::setProjectId(unsigned int newProjectId)
{
    projectId = newProjectId;
}

Session::Session() : sessionId(0), descriptor(0), userId(0),
    startAt(0), endAt(0), projectId(0) {}

Session::Session(QSqlQuery& query) : sessionId(query.value(0).toUInt()), descriptor(query.value(1).toLongLong()), userId(query.value(2).toUInt()),
    startAt(query.value(3).toUInt()), endAt(query.value(4).toUInt()), projectId(query.value(5).toUInt()) {}


Session::Session(qintptr descriptor, unsigned int userId, unsigned long long startAt, unsigned long long endAt, unsigned int projectId)
    : sessionId(0), descriptor(descriptor), userId(userId),
    startAt(startAt), endAt(endAt), projectId(projectId) {}

Session::Session(unsigned int sessionId, qintptr descriptor, unsigned int userId, unsigned long long startAt, unsigned long long endAt, unsigned int projectId)
    : sessionId(sessionId), descriptor(descriptor), userId(userId),
    startAt(startAt), endAt(endAt), projectId(projectId) {}
