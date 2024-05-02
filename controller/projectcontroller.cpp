#include "projectcontroller.h"

QVector<QString> userIdAlliases = {"id", "userId", "ownerId", "creatorId"};

static unsigned int getId(const QJsonDocument& object) {
    unsigned int id = 0;
    for (QString x : userIdAlliases) {
        if (id == 0) id = object[x].toInt();
        else return id;
    }

    return id;
}

ProjectController::ProjectController() {}

void ProjectController::mapRequest(qintptr descriptor, quint16 key, const QJsonDocument& object)
{
    //if (key) server->sendToClient(descriptor, key, method[key](object).toJson());
    //else server->sendToClient(authService->getListeningDescriptors(descriptor), key, method[key](object).toJson());

    switch(key) {
    case 101: { // join project
        JoinRequest request;
        request.fromJson(object);

        server->sendToClient(authService->getListeningDescriptors(descriptor), key, projectService->joinProject(request).toJson()); // Все участники проекта получают это
        return;
    }
    case 102: { // leave project
        JoinRequest request;
        request.fromJson(object);

        server->sendToClient(authService->getListeningDescriptors(descriptor), key, projectService->leaveProject(request).toJson()); // Все участники проекта получают это
        return;
    }
    case 103: { // get project
        GetRequest request;
        request.fromJson(object);

        server->sendToClient(descriptor, key, projectService->getProject(request).toJson());
        return;
    }
    case 104: { // get projects
        GetRequest request;
        request.fromJson(object);

        server->sendToClient(descriptor, key, projectService->getProjectsByUserId(request).toJson());
        return;
    }
    case 105: { // post project
        ProjectRequest request;
        request.fromJson(object);

        server->sendToClient(descriptor, key, projectService->postProject(descriptor, request).toJson());
        return;
    }
    case 106: { // update project
        ProjectRequest request;
        request.fromJson(object);

        server->sendToClient(authService->getListeningDescriptors(descriptor), key, projectService->updateProject(descriptor, request).toJson()); // Все участники проекта получают это
        return;
    }
    case 199: { // redirect from project

    }
    case 200: { // redirect to project

    }
    default: return; // TODO
    }
}
