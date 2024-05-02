#include "getrequest.h"

GetRequest::GetRequest() : id(0) {}

GetRequest::GetRequest(const QJsonDocument &json) { fromJson(json); }

GetRequest::GetRequest(unsigned int id) : id(id) {}

void GetRequest::fromJson(const QJsonDocument &json) {
    id = json["id"].toInt();
}
