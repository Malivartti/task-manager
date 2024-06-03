#ifndef DATATRANSFEROBJECT_H
#define DATATRANSFEROBJECT_H

#include <QJsonObject>
#include <QJsonDocument>

class DataTransferObject
{
public:
    DataTransferObject();
    DataTransferObject(const QJsonDocument& json);

    virtual QJsonDocument toJson();
    virtual QJsonObject toJsonObject();
    virtual void fromJson(const QJsonDocument& json);
};

#endif // DATATRANSFEROBJECT_H
