#ifndef PROJECTREQUEST_H
#define PROJECTREQUEST_H

#include "dto/base/datatransferobject.h"

class ProjectRequest : public DataTransferObject
{
public:
    int projectId;
    QString name;
    QString description;
    int ownerId;
    int createdAt; // Поле, которое устанавливается на сервере

    ProjectRequest();
    ProjectRequest(const QJsonDocument &json);
    ProjectRequest(QString name, QString description, unsigned int ownerId, unsigned int createdAt);
    ProjectRequest(unsigned int id, QString name, QString description, unsigned int ownerId, unsigned int createdAt);

    void fromJson(const QJsonDocument& json) override;
};

#endif // PROJECTREQUEST_H
