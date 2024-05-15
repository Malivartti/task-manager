#ifndef PROJECTUPDATEREQUEST_H
#define PROJECTUPDATEREQUEST_H

#include "../base/datatransferobject.h"

class ProjectUpdateRequest : public DataTransferObject
{
public:
    int projectId;
    QString name;
    QString description;
    int ownerId;

    ProjectUpdateRequest();
    ProjectUpdateRequest(const QJsonDocument &json);
    ProjectUpdateRequest(QString name, QString description, unsigned int ownerId);
    ProjectUpdateRequest(unsigned int id, QString name, QString description, unsigned int ownerId);

    void fromJson(const QJsonDocument& json) override;
};

#endif // PROJECTUPDATEREQUEST_H
