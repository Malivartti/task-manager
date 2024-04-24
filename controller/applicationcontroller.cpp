#include "applicationcontroller.h"

ApplicationController::ApplicationController() {}

QJsonDocument ApplicationController::mapRequest(quint16 key, QDataStream &in)
{
    QJsonDocument object;
    in >> object;
    if (key >= 1 && key <= 10) {} //auth
    else if (key >= 11 && key <= 20) {} //user
    else if (key >= 21 && key <= 30) {} //project

    switch(key) {
    case 1: {
        LoginRequest request;
        request.fromJson(object);

        AuthService* service = AuthService::getInstance();
        return service->login(request);
    }
    case 2: {
        RegisterRequest request;
        request.fromJson(object);

        AuthService* service = AuthService::getInstance();
        return service->reg(request);
    }
    case 3: {}
    default: { return {}; }
    }
}
