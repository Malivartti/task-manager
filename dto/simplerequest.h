#ifndef SIMPLEREQUEST_H
#define SIMPLEREQUEST_H

#include <QJsonObject>

#include "dto/base/datatransferobject.h"

class SimpleRequest : public DataTransferObject
{
public:
    int id;

    SimpleRequest();
    SimpleRequest(unsigned int id);

    QJsonDocument toJson();
};

#endif // SIMPLEREQUEST_H
