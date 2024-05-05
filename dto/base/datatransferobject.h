#ifndef DATATRANSFEROBJECT_H
#define DATATRANSFEROBJECT_H

#include <QJsonDocument>

class DataTransferObject
{
public:
    DataTransferObject();
    DataTransferObject(const QJsonDocument& json);

    virtual QJsonDocument toJson();
    virtual void fromJson(const QJsonDocument& json);

    virtual void pol();
};

#endif // DATATRANSFEROBJECT_H
