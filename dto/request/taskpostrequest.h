#ifndef TASKPOSTREQUEST_H
#define TASKPOSTREQUEST_H

#include "../base/datatransferobject.h"

class TaskPostRequest : public DataTransferObject
{
public:
    QString name;
    QString description;
    int projectId;
    int sprintId;
    int startAt;
    int endAt;
    int resolvedAt;

    TaskPostRequest();
    TaskPostRequest(const QJsonDocument &json);
    TaskPostRequest(QString name, QString description, unsigned int projectId, unsigned int sprintId, unsigned int startAt, unsigned int endAt, unsigned int resolvedAt);

    void fromJson(const QJsonDocument& json) override;
};

#endif // TASKPOSTREQUEST_H
