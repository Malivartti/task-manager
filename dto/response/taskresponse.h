#ifndef TASKRESPONSE_H
#define TASKRESPONSE_H

#include <QJsonObject>

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

    TaskResponse();
    TaskResponse(unsigned int taskId, QString name, QString description,
                 ProjectResponse projectId, unsigned int sprintId,
                 UserResponse creatorId, unsigned int startAt,
                 unsigned int endAt, unsigned int resolvedAt);

    QJsonObject toJsonObject() override;
};

#endif // TASKRESPONSE_H
