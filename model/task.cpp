#include "task.h"

Task::Task() {}

Task::Task(
    unsigned int taskId, QString name, QString description,
    Project project, unsigned int sprint, User creator,
    unsigned int startAt, unsigned int endAt, unsigned int resolvedAt,
    QString status, QVariantList performers)
    : taskId(taskId), name(std::move(name)),
    description(std::move(description)), project(std::move(project)),
    sprint(sprint), creator(std::move(creator)), startAt(startAt),
    endAt(endAt), resolvedAt(resolvedAt), status(std::move(status)),
    performers(std::move(performers)) {}

Task::Task(const QJsonValue &object)
    : taskId(object["id"].toInt()), name(object["name"].toString()),
    description(object["description"].toString()), project(object["projectId"]),
    sprint(object["sprintId"].toInt()), creator(object["creatorId"]),
    startAt(object["startAt"].toInt()),  endAt(object["endAt"].toInt()),
    resolvedAt(object["resolvedAt"].toInt()), status(object["status"].toString())
{
    QJsonArray array = object["performers"].toArray();
    for (auto x : array) {
        performers.append(User(x).toVariantMap());
    }
}

QVariantMap Task::toVariantMap() const
{
    return  QVariantMap{
        {"id", taskId},
        {"name", name},
        {"description", description},
        {"project", project.toVariantMap()},
        {"sprint", sprint},
        {"creator", creator.toVariantMap()},
        {"startAt", startAt},
        {"endAt", endAt},
        {"resolvedAt", resolvedAt},
        {"status", status},
        {"performers", performers}
    };
}
