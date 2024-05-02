#include "applicationcontroller.h"

static bool isMethodValid(const QString& method) {
    return true;
}

ApplicationController::ApplicationController() {}

/*
 * KEYS:
 *  [1, 10] AUTH
 *  [11, 100] USER
 *  [101, 200] PROJECT
 *      199 IS RESERVED FOR REDIRECT FROM PROJECT
 *      200 IS RESERVED FOR REDIRECT TO PROJECT
 *  [201, 300] TASK
*/

void ApplicationController::mapRequest(qintptr descriptor, QDataStream &in) // Перенести key, method и object на сервер
{
    quint16 key;
    in >> key;

    qDebug() << "Casted: " << key;
    if (key == 0) {

    }
    else {
        QJsonDocument object;
        in >> object;
        if (!authService->isAuthorized(descriptor)) {
            qDebug() << "Unauthorized socket with descriptor: " << descriptor;
            switch(key) {
            case 1: { // login
                LoginRequest request;
                request.fromJson(object);

                server->sendToClient(descriptor, key, authService->login(descriptor, request).toJson());
                return;
            }
            case 2: { // register
                RegisterRequest request;
                request.fromJson(object);

                server->sendToClient(descriptor, key, authService->reg(descriptor, request).toJson());
                return;
            }
            default: { server->sendToClient(descriptor, key, authService->getUnauthorizedAccess().toJson()); return; }
            }
        }
        else {
            qDebug() << "Authorized socket with descriptor: " << descriptor;
            if (11 <= key && key <= 100) // UserController
            {

            }
            if (101 <= key && key <= 200) // ProjectController
            {
                projectController->mapRequest(descriptor, key, object);
            }
            if (201 <= key && key <= 300) // TaskController
            {

            }
        }
    }
}
