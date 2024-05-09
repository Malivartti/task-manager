#include "handler.h"

Handler::Handler() {}

Handler *Handler::getInstance()
{
    if (!instance) {
        instance = new Handler();
    }
    return instance;
}

void Handler::mapRequest(quint16 key, const QJsonDocument &object)
{
    if (key == 1) {
        emit login(object);
    }
    if (key == 2) {
        emit reg(object);
    }
}
