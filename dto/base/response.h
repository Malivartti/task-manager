#ifndef RESPONSE_H
#define RESPONSE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QString>

#include "datatransferobject.h"

class Header : public DataTransferObject {
public:
    int code;
    QString description;

    Header();
    Header(int code, QString description);

    QJsonObject toJsonObject() override;
};

class Response : public DataTransferObject
{
public:
    QJsonObject head;
    QJsonObject body;
    QJsonArray array;

    Response();
    Response(QJsonObject head, QJsonObject body);
    Response(QJsonObject head, QJsonArray array);

    QJsonObject toJsonObject() override;
};

#endif // RESPONSE_H
