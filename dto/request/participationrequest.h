#ifndef PARTICIPATIONREQUEST_H
#define PARTICIPATIONREQUEST_H

#include "../base/datatransferobject.h"

class ParticipationRequest : public DataTransferObject
{
public:
    int projectId;

    ParticipationRequest();
    ParticipationRequest(const QJsonDocument& json);
    ParticipationRequest(unsigned int projectId);

    void fromJson(const QJsonDocument& json) override;
};

#endif // PARTICIPATIONREQUEST_H
