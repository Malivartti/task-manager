#ifndef PROJECTRESPONSE_H
#define PROJECTRESPONSE_H

#include <QString>

#include "dto/base/datatransferobject.h"
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
    ProjectResponse(unsigned int projectId, QString name, QString description, UserResponse ownerId, unsigned int createdAt);
    ProjectResponse(unsigned int projectId, QString name, QString description, UserResponse& ownerId,unsigned int createdAt);

    QJsonDocument toJson();
};

#endif // PROJECTRESPONSE_H
