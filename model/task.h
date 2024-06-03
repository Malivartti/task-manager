#ifndef TASK_H
#define TASK_H

#include <QJsonArray>

#include "user.h"
#include "project.h"

class Task
{
public:
    unsigned int taskId;
    QString name;
    QString description;
    Project project;
    unsigned int sprint;
    User creator;
    unsigned int startAt;
    unsigned int endAt;
    unsigned int resolvedAt;
    QString status;
    QVariantList performers;

    Task();
    Task(unsigned int taskId, QString name, QString description,
         Project project, unsigned int sprint, User user,
         unsigned int startAt, unsigned int endAt, unsigned int resolvedAt,
         QString status, QVariantList performers);

    Task(const QJsonValue& object);

    QVariantMap toVariantMap() const;
};

#endif // TASK_H
