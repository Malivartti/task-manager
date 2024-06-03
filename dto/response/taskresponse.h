#ifndef TASKRESPONSE_H
#define TASKRESPONSE_H

#include <QJsonObject>
#include <QJsonArray>

#include "../base/datatransferobject.h"
#include "userresponse.h"
#include "projectresponse.h"

class TaskResponse : public DataTransferObject
{
public:
    int taskId;
    QString name;
    QString description;
    ProjectResponse projectId;
    int sprintId;
    UserResponse creatorId;
    int startAt;
    int endAt;
    int resolvedAt;
    QString status;
    QJsonArray performers;

    TaskResponse();
    TaskResponse(unsigned int taskId, QString name, QString description,
                 ProjectResponse projectId, unsigned int sprintId,
                 UserResponse creatorId, unsigned int startAt,
                 unsigned int endAt, unsigned int resolvedAt, QString status, const QJsonArray& performers);

    QJsonObject toJsonObject() override;
};

#endif // TASKRESPONSE_H
