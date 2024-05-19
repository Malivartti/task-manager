#ifndef TASKUPDATEREQUEST_H
#define TASKUPDATEREQUEST_H

#include "../base/datatransferobject.h"

class TaskUpdateRequest : public DataTransferObject
{
public:
    int taskId;
    QString name;
    QString description;
    int sprintId;
    int startAt;
    int endAt;
    int resolvedAt;

    TaskUpdateRequest();
    TaskUpdateRequest(const QJsonDocument &json);
    TaskUpdateRequest(unsigned int taskId, QString name, QString description, unsigned int sprintId, unsigned int startAt, unsigned int endAt, unsigned int resolvedAt);

    void fromJson(const QJsonDocument& json) override;
};

#endif // TASKUPDATEREQUEST_H
