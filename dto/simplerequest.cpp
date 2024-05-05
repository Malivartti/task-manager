#include "simplerequest.h"

SimpleRequest::SimpleRequest() {}

SimpleRequest::SimpleRequest(unsigned int id) : id(id) {}

QJsonDocument SimpleRequest::toJson() {
    return QJsonDocument(
        QJsonObject{
            {"id", id}
        }
    );
}
