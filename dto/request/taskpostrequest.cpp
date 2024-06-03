#include "taskpostrequest.h"

TaskPostRequest::TaskPostRequest()
    : projectId(0), sprintId(0), startAt(0),
    endAt(0), resolvedAt(0) {}

TaskPostRequest::TaskPostRequest(const QJsonDocument &json) { fromJson(json); }

TaskPostRequest::TaskPostRequest(QString name, QString description,
                                 unsigned int projectId, unsigned int sprintId,
                                 unsigned int startAt, unsigned int endAt,
                                 unsigned int resolvedAt, QString status)
    : name(name), description(description), projectId(projectId),
    sprintId(sprintId), startAt(startAt),
    endAt(endAt), resolvedAt(resolvedAt), status(status) {}

void TaskPostRequest::fromJson(const QJsonDocument &json)
{
    name = json["name"].toString();
    description = json["description"].toString();
    projectId = json["projectId"].toInt();
    sprintId = json["sprintId"].toInt();
    startAt = json["startAt"].toInt();
    endAt = json["endAt"].toInt();
    resolvedAt = json["resolvedAt"].toInt();
    status = json["status"].toString();
}
