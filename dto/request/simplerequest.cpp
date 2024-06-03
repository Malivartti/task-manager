#include "simplerequest.h"

SimpleRequest::SimpleRequest() : id(0) {}

SimpleRequest::SimpleRequest(const QJsonDocument &json) { fromJson(json); }

SimpleRequest::SimpleRequest(unsigned int id) : id(id) {}

void SimpleRequest::fromJson(const QJsonDocument &json) {
    id = json["id"].toInt();
}
