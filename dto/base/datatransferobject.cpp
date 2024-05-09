#include "datatransferobject.h"

DataTransferObject::DataTransferObject() {}

DataTransferObject::DataTransferObject(const QJsonDocument &json) {}

QJsonDocument DataTransferObject::toJson()
{
    return QJsonDocument(
        toJsonObject()
    );
}

QJsonObject DataTransferObject::toJsonObject() { return {}; }

void DataTransferObject::fromJson(const QJsonDocument& json) {}
