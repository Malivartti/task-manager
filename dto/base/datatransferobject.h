#ifndef DATATRANSFEROBJECT_H
#define DATATRANSFEROBJECT_H

#include <QJsonObject>
#include <QJsonDocument>

/**
 * @brief The Base Data Transfer Object.
 * @details DTOs are responsible for serializing and validating the objects. This class provides interface and common methods for descendants.
*/
class DataTransferObject
{
public:
    DataTransferObject();
    DataTransferObject(const QJsonDocument& json);

    /**
     * @brief The Method for creating Json from DTO.
    */
    virtual QJsonDocument toJson();

    /**
     * @brief The Method for creating Json Object from DTO.
    */
    virtual QJsonObject toJsonObject();

    /**
     * @brief The Method for constructing DTO from Json Document.
    */
    virtual void fromJson(const QJsonDocument& json);
};

#endif // DATATRANSFEROBJECT_H
