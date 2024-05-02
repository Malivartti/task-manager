#ifndef JOINREQUEST_H
#define JOINREQUEST_H

#include "dto/base/datatransferobject.h"

class JoinRequest : public DataTransferObject
{
public:
    int userId;
    int projectId;
    JoinRequest();
    JoinRequest(const QJsonDocument& json);
    JoinRequest(unsigned int userId, unsigned int projectId);

    void fromJson(const QJsonDocument& json) override;
};

#endif // JOINREQUEST_H
