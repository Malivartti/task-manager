#include "response.h"

Header::Header() {}
Header::Header(int code, QString description) : code(code), description(description) {}

QJsonDocument Header::toJson() {
    return QJsonDocument(
            QJsonObject{
                {"code", code},
                {"description", description}
            }
        );
}

Response::Response() {}

Response::Response(QJsonObject head, QJsonObject body) : head(head), body(body) {}
Response::Response(QJsonObject head, QJsonArray array) : head(head), array(array) {}

QJsonDocument Response::toJson() {
    if (array.size() == 0){
        return QJsonDocument(
            QJsonObject{
                {"head", head},
                {"body", body}
            }
        );
    }
    else {
        return QJsonDocument(
            QJsonObject{
                {"head", head},
                {"body", array[0]}
            }
        );
    }
}
