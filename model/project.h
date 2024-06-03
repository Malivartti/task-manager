#ifndef PROJECT_H
#define PROJECT_H

#include <QJsonObject>
#include <QJsonDocument>

#include "user.h"

class Task;

class Project
{
public:
    int projectId;
    QString name;
    QString description;
    User owner;
    int createdAt;

    // QVector<User> members;
    // QVector<Task> tasks;

    Project();
    Project(int projectId, const QString& name, const QString& description, const User& owner,
            int createdAt);

    Project(const QJsonValue& object);

    QVariantMap toVariantMap() const;
};

#endif // PROJECT_H
