#include "frontcontroller.h"

#define REGISTER(key, controller, command) \
    commands.insert(key, [&c = this->controller] (qintptr descriptor, const QJsonDocument& object) { return c->command(descriptor, object); }) \

FrontController::FrontController() {
    // authKeys = {};
    // publicKeys = {};
    multicastKeys = {101, 102, 106};
    REGISTER(1, authController, login);
    REGISTER(2, authController, reg);
    REGISTER(3, authController, logout);
    REGISTER(101, projectController, joinProject);
    REGISTER(102, projectController, leaveProject);
    REGISTER(103, projectController, getProject);
    REGISTER(104, projectController, getProjectsByUserId);
    REGISTER(105, projectController, postProject);
    REGISTER(106, projectController, updateProject);
    REGISTER(199, projectController, redirectToProject);
    REGISTER(201, projectController, getTask);
    REGISTER(202, projectController, getTasksByUserId);
    REGISTER(203, projectController, getTasksByProjectId);
    REGISTER(204, projectController, postTask);
    REGISTER(205, projectController, updateTask);
}

// bool FrontController::isAuth(quint16 key)
// {
//     return authKeys.contains(key);
// }

// bool FrontController::isPublic(quint16 key)
// {
//     return publicKeys.contains(key);
// }

bool FrontController::isMulticast(quint16 key)
{
    return multicastKeys.contains(key);
}

bool FrontController::isRegistred(quint16 key)
{
    return commands.contains(key);
}

bool FrontController::isSuccessful(const QJsonDocument &object)
{
    return object["head"]["code"] == 1 ? true : false;
}

void FrontController::setServer(BaseServer *server)
{
    if (this->server == nullptr) this->server = server;
}

void FrontController::mapRequest(qintptr descriptor, quint16 key, const QJsonDocument &object)
{
    if (!authService->isAuthorized(descriptor)) { // Не авторизован
        if (key > END_AUTH || key < START_AUTH) { // NOT OK
            qDebug() << "key > END_AUTH || key < START_AUTH";
            server->sendToClient(descriptor, key, authService->getUnauthorizedAccess().toJson());
            return;
        }
        // OK
    }
    else { // Авторизован
        if (key <= END_AUTH) { // NOT OK
            qDebug() << "key <= END_AUTH";
            server->sendToClient(descriptor, key, authService->getForbiddenAccess().toJson());
            return;
        }
        // OK
    }
    if (!isRegistred(key)) { // Ключа не существует
        qDebug() << "!isRegistred(key)";
        server->sendToClient(descriptor, key, authService->getForbiddenAccess().toJson()); // Другая ошибка
        return;
    }

    QJsonDocument response = commands[key](descriptor, object).toJson();
    if (!isMulticast(key) || !isSuccessful(response)) {
        server->sendToClient(descriptor, key, response);
    }
    else {
        server->sendToClient(authService->getListeningDescriptors(descriptor), key, response);
    }
}
