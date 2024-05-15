#ifndef PROJECTRESPONSE_H
#define PROJECTRESPONSE_H

#include <QString>

#include "../base/datatransferobject.h"
#include "userresponse.h"

class ProjectResponse : public DataTransferObject
{
public:
    int projectId;
    QString name;
    QString description;
    UserResponse ownerId;
    int createdAt;

    ProjectResponse();
    ProjectResponse(unsigned int projectId, QString name, QString description, const UserResponse& ownerId, unsigned int createdAt);

    QJsonObject toJsonObject() override;
};

#endif // PROJECTRESPONSE_H
