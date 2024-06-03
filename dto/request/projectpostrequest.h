#ifndef PROJECTPOSTREQUEST_H
#define PROJECTPOSTREQUEST_H

#include "../base/datatransferobject.h"

class ProjectPostRequest : public DataTransferObject
{
public:
    QString name;
    QString description;

    ProjectPostRequest();
    ProjectPostRequest(const QJsonDocument &json);
    ProjectPostRequest(QString name, QString description);

    void fromJson(const QJsonDocument& json);
};

#endif // PROJECTPOSTREQUEST_H
