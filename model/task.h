#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QVariant>

#include "base/model.h"

class Task : public Model
{
private:
    unsigned int taskId;
    QString name; // отдельный метод для обновления ?
    QString description; // отдельный метод для обновления
    unsigned int projectId;
    unsigned int sprintId; // отдельный метод для обновления
    unsigned int creatorId;
    unsigned int startAt; // отдельный метод для обновления
    unsigned int endAt; // отдельный метод для обновления
    unsigned int resolvedAt;
    QString status; // отдельный метод для обновления
public:
    Task();
    Task(QSqlQuery& query);
    Task(const QString &name, const QString &description, unsigned int projectId, unsigned int sprintId, unsigned int creatorId, unsigned int startAt, unsigned int endAt, unsigned int resolvedAt, const QString &status);
    Task(unsigned int taskId, const QString &name, const QString &description, unsigned int projectId, unsigned int sprintId, unsigned int creatorId, unsigned int startAt, unsigned int endAt, unsigned int resolvedAt, const QString &status);

    unsigned int getId() const;
    QString getName() const;
    QString getDescription() const;
    unsigned int getProjectId() const;
    unsigned int getSprintId() const;
    unsigned int getCreatorId() const;
    unsigned int getStartAt() const;
    unsigned int getEndAt() const;
    unsigned int getResolvedAt() const;

    void setId(unsigned int newId);
    void setName(const QString &newName);
    void setDescription(const QString &newDescription);
    void setProjectId(unsigned int newProjectId);
    void setSprintId(unsigned int newSprintId);
    void setCreatorId(unsigned int newCreatorId);
    void setStartAt(unsigned int newStartAt);
    void setEndAt(unsigned int newEndAt);
    void setResolvedAt(unsigned int newtResolvedAt);
    QString getStatus() const;
    void setStatus(const QString &newStatus);
};

#endif // TASK_H
