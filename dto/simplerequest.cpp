#include "simplerequest.h"

SimpleRequest::SimpleRequest() {}

SimpleRequest::SimpleRequest(unsigned int id) : id(id) {}

QJsonObject SimpleRequest::toJsonObject() {
    return QJsonObject{
        {"id", id}
    };
}
