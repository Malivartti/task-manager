#ifndef SIMPLEREQUEST_H
#define SIMPLEREQUEST_H

#include "base/datatransferobject.h"

class SimpleRequest : public DataTransferObject
{
public:
    int id;

    SimpleRequest();
    SimpleRequest(unsigned int id);

    QJsonObject toJsonObject() override;
};

#endif // SIMPLEREQUEST_H
