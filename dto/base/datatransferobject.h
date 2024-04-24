#ifndef DATATRANSFEROBJECT_H
#define DATATRANSFEROBJECT_H

#include <QJsonDocument>

class DataTransferObject
{
public:
    DataTransferObject();

    virtual QJsonDocument toJson();
    virtual void fromJson(QJsonDocument& json);

    virtual void pol();
};

#endif // DATATRANSFEROBJECT_H
