#include "projectservice.h"

ProjectService::ProjectService() {}

Response ProjectService::joinProject(qintptr descriptor, const ParticipationRequest &request)
{
    unsigned int userId = sessionRepository->getByDescriptor(descriptor).getUserId();
    if (!userProjectRepository->insert(UserProject(userId, request.projectId, "Member"))) {
        return Response{Header{0, "Internal error"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        QJsonObject{
            {"id", request.projectId}
        }
    };
}

Response ProjectService::leaveProject(qintptr descriptor, const ParticipationRequest &request)
{
    unsigned int userId = sessionRepository->getByDescriptor(descriptor).getUserId();
    if (!userProjectRepository->remove(UserProject(userId, request.projectId, ""))) {
        return Response{Header{0, "Internal error"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        QJsonObject{
            {"id", request.projectId}
        }
    };
}

Response ProjectService::getProject(qintptr descriptor, const SimpleRequest &request)
{
    Project project = projectRepository->getById(request.id);
    if (project.getId() == 0) {
        return Response{
            Header{0, "Project with id " + QString::number(request.id) + " does not exist"}.toJsonObject(),
            ProjectResponse{}.toJsonObject()
        };
    }
    User user =  userRepository->getById(project.getOwnerId());
    return Response{
        Header{1, "OK"}.toJsonObject(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJsonObject()
    };
}

Response ProjectService::getProjectsByUserId(qintptr descriptor, const SimpleRequest& request)
{
    QVector<UserProject> vec = userProjectRepository->getByUserId(request.id);

    qDebug() << "User" << request.id << "has" << vec.size() << "projects";

    QJsonArray array;
    for (int i = 0; i < vec.size(); i++) {
        Project project = projectRepository->getById(vec[i].getProjectId());
        User user = userRepository->getById(project.getOwnerId());

        array.append(ProjectResponse(
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()).toJsonObject()
        );
    }

    return Response{Header{1, "OK"}.toJsonObject(), array};
}

Response ProjectService::postProject(qintptr descriptor, const ProjectPostRequest& request)
{
    if (projectRepository->getByName(request.name).getId() != 0) {
        return Response{Header{0, "Project name has already been taken"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    Project project = projectRepository->save(Project(request.name, request.description, sessionRepository->getByDescriptor(descriptor).getUserId(), QDateTime::currentSecsSinceEpoch()));
    if (project.getId() == 0) {
        return Response{Header{0, "Internal error"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(project.getOwnerId());

    return Response{
        Header{1, "OK"}.toJsonObject(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJsonObject()
    };
}

Response ProjectService::updateProject(qintptr descriptor, const ProjectUpdateRequest& request)  // TODO: fix save() and stuff
{
    UserProject userProject = userProjectRepository->getByUserIdAndProjectId(
        sessionRepository->getByDescriptor(descriptor).getUserId(),
        request.projectId);
    if (userProject.getUserId() == 0 || userProject.getRole() != "Admin" || userProject.getRole() != "Owner") { // TODO: Заменить на метод проверки прав для update
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    Project project = projectRepository->getById(request.projectId);
    if (project.getId() == 0) {
        return Response{Header{0, "Project does not exist"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    if (project.getOwnerId() != request.ownerId) {
        if (userProject.getRole() != "Owner") {
            return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
        }
    }

    if (project.getName() != request.name) {
        if (projectRepository->getByName(request.name).getId() != 0) {
            return Response{Header{0, "Project name has already been taken"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
        }
    }

    project = projectRepository->save(Project(request.projectId, request.name, request.description, request.ownerId, project.getCreatedAt()));
    if (project.getId() == 0) {
        return Response{Header{0, "Internal error"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(request.ownerId);

    return Response{
        Header{1, "OK"}.toJsonObject(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJsonObject()
    };
}

Response ProjectService::redirectToProject(qintptr descriptor, const SimpleRequest &request)
{
    Session session = sessionRepository->getByDescriptor(descriptor);
    if (request.id != 0 && userProjectRepository->getByUserIdAndProjectId(session.getUserId(), request.id).getUserId() == 0) {
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    session.setProjectId(request.id);
    if (!sessionRepository->update(session)) { // Можно использовать sessionRepository->setProjectId
        return Response{Header{0, "Internal error"}.toJsonObject(), ProjectResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        QJsonObject{
            {"id", request.id}
        }
    };
}
