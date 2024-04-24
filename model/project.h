#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

#include "base/model.h"

class Project : public Model
{
private:
    unsigned int projectId;
    QString name;
    QString description;
    unsigned int ownerId;
    unsigned int createdAt;

public:
    Project();
    Project(QSqlQuery& query);
    Project(QString name, QString description, unsigned int ownerId,
            unsigned int createdAt);
    Project(unsigned int projectId, QString name, QString description,
            unsigned int ownerId, unsigned int createdAt);

    unsigned int getId() const;
    QString getName() const;
    QString getDescription() const;
    unsigned int getOwnerId() const;
    unsigned int getCreatedAt() const;

    void setId(unsigned int newId);
    void setName(const QString &newName);
    void setDescription(const QString &newDescription);
    void setOwnerId(unsigned int newOwnerId);
    void setCreatedAt(unsigned int newCreatedAt);
};

#endif // PROJECT_H
