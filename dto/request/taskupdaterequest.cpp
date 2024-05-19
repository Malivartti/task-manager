#include "taskupdaterequest.h"

TaskUpdateRequest::TaskUpdateRequest()
    : taskId(0), sprintId(0), startAt(0),
    endAt(0), resolvedAt(0) {}

TaskUpdateRequest::TaskUpdateRequest(unsigned int taskId, QString name, QString description,
                                     unsigned int sprintId,
                                     unsigned int startAt, unsigned int endAt,
                                     unsigned int resolvedAt)
    : taskId(taskId), name(name), description(description),
    sprintId(sprintId), startAt(startAt),
    endAt(endAt), resolvedAt(resolvedAt) {}

void TaskUpdateRequest::fromJson(const QJsonDocument &json)
{
    taskId = json["taskId"].toInt();
    name = json["name"].toString();
    description = json["description"].toString();
    sprintId = json["sprintId"].toInt();
    startAt = json["startAt"].toInt();
    endAt = json["endAt"].toInt();
    resolvedAt = json["resolvedAt"].toInt();
}
