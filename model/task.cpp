#include "task.h"

Task::Task() : taskId(0), projectId(0),
    sprintId(0), creatorId(0),
    startAt(0), endAt(0),
    resolvedAt(0) {}

Task::Task(QSqlQuery &query)
    : taskId(query.value(0).toUInt()), name(query.value(1).toString()),
    description(query.value(2).toString()), projectId(query.value(3).toUInt()),
    sprintId(query.value(4).toUInt()), creatorId(query.value(5).toUInt()),
    startAt(query.value(6).toUInt()), endAt(query.value(7).toUInt()),
    resolvedAt(query.value(8).toUInt()) {}

Task::Task(const QString &name,
           const QString &description, unsigned int projectId,
           unsigned int sprintId, unsigned int creatorId,
           unsigned int startAt, unsigned int endAt,
           unsigned int resolvedAt)
    : taskId(0), name(name),
    description(description), projectId(projectId),
    sprintId(sprintId), creatorId(creatorId),
    startAt(startAt), endAt(endAt),
    resolvedAt(resolvedAt) {}

Task::Task(unsigned int taskId, const QString &name,
           const QString &description, unsigned int projectId,
           unsigned int sprintId, unsigned int creatorId,
           unsigned int startAt, unsigned int endAt,
           unsigned int resolvedAt)
    : taskId(taskId), name(name),
    description(description), projectId(projectId),
    sprintId(sprintId), creatorId(creatorId),
    startAt(startAt), endAt(endAt),
    resolvedAt(resolvedAt) {}

unsigned int Task::getId() const
{
    return taskId;
}

QString Task::getName() const
{
    return name;
}

QString Task::getDescription() const
{
    return description;
}

unsigned int Task::getProjectId() const
{
    return projectId;
}

unsigned int Task::getSprintId() const
{
    return sprintId;
}

unsigned int Task::getCreatorId() const
{
    return creatorId;
}

unsigned int Task::getStartAt() const
{
    return startAt;
}

unsigned int Task::getEndAt() const
{
    return endAt;
}

unsigned int Task::getResolvedAt() const
{
    return resolvedAt;
}

void Task::setId(unsigned int newId)
{
    taskId = newId;
}

void Task::setName(const QString &newName)
{
    name = newName;
}

void Task::setDescription(const QString &newDescription)
{
    description = newDescription;
}

void Task::setProjectId(unsigned int newProjectId)
{
    projectId = newProjectId;
}

void Task::setSprintId(unsigned int newSprintId)
{
    sprintId = newSprintId;
}

void Task::setCreatorId(unsigned int newCreatorId)
{
    creatorId = newCreatorId;
}

void Task::setStartAt(unsigned int newStartAt)
{
    startAt = newStartAt;
}

void Task::setEndAt(unsigned int newEndAt)
{
    endAt = newEndAt;
}

void Task::setResolvedAt(unsigned int newtResolvedAt)
{
    resolvedAt = newtResolvedAt;
}
