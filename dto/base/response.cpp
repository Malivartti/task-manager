#include "response.h"

Header::Header() : code(0) {}
Header::Header(int code, QString description) : code(code), description(description) {}

QJsonObject Header::toJsonObject()
{
    return QJsonObject{
        {"code", code},
        {"description", description}
    };
}

Response::Response() {}

Response::Response(QJsonObject head, QJsonObject body) : head(head), body(body) {}
Response::Response(QJsonObject head, QJsonArray array) : head(head), array(array) {}

QJsonObject Response::toJsonObject()
{
    if (array.size() == 0){
        return QJsonObject{
            {"head", head},
            {"body", body}
        };
    }
    else {
        return QJsonObject{
            {"head", head},
            {"body", array}
        };
    }
}
