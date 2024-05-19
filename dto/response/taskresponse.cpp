#include "taskresponse.h"

TaskResponse::TaskResponse() {}

TaskResponse::TaskResponse(unsigned int taskId, QString name,
                           QString description, ProjectResponse projectId,
                           unsigned int sprintId, UserResponse creatorId,
                           unsigned int startAt, unsigned int endAt,
                           unsigned int resolvedAt)
    : taskId(taskId), name(std::move(name)),
    description(std::move(description)), projectId(std::move(projectId)),
    sprintId(sprintId), creatorId(std::move(creatorId)), startAt(startAt),
    endAt(endAt), resolvedAt(resolvedAt) {}

QJsonObject TaskResponse::toJsonObject()
{
    return QJsonObject{
        {"id", taskId},
        {"name", name},
        {"description", description},
        {"projectId", projectId.toJsonObject()},
        {"sprintId", sprintId},
        {"creatorId", creatorId.toJsonObject()},
        {"startAt", startAt},
        {"endAt", endAt},
        {"resolvedAt", resolvedAt}
    };
}
