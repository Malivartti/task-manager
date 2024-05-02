#include "joinrequest.h"

JoinRequest::JoinRequest() : userId(0), projectId(0) {}

JoinRequest::JoinRequest(const QJsonDocument &json) { fromJson(json); }

JoinRequest::JoinRequest(unsigned int userId, unsigned int projectId)
    : userId(userId), projectId(projectId) {}

void JoinRequest::fromJson(const QJsonDocument &json) {
    userId = json["userId"].toInt();
    projectId = json["projectId"].toInt();
}
