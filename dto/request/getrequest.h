#ifndef GETREQUEST_H
#define GETREQUEST_H

#include "dto/base/datatransferobject.h"

class GetRequest : public DataTransferObject
{
public:
    int id;
    GetRequest();
    GetRequest(const QJsonDocument& json);
    GetRequest(unsigned int id);

    void fromJson(const QJsonDocument& json) override;
};

#endif // GETREQUEST_H
