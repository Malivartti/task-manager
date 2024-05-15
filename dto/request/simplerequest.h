#ifndef SIMPLEREQUEST_H
#define SIMPLEREQUEST_H

#include "dto/base/datatransferobject.h"

class SimpleRequest : public DataTransferObject
{
public:
    int id;

    SimpleRequest();
    SimpleRequest(const QJsonDocument& json);
    SimpleRequest(unsigned int id);

    void fromJson(const QJsonDocument& json) override;
};

#endif // SIMPLEREQUEST_H
