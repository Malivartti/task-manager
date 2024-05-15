#include "participationrequest.h"

ParticipationRequest::ParticipationRequest() : projectId(0) {}

ParticipationRequest::ParticipationRequest(const QJsonDocument &json) { fromJson(json); }

ParticipationRequest::ParticipationRequest(unsigned int projectId)
    : projectId(projectId) {}

void ParticipationRequest::fromJson(const QJsonDocument &json) {
    projectId = json["id"].toInt();
}
