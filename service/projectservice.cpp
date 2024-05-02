#include "projectservice.h"

ProjectService::ProjectService() {}

Response ProjectService::joinProject(const JoinRequest &request)
{
    qDebug() << "User" << request.userId << "has joined project with ID" << request.projectId;

    if (!userProjectRepository->save(UserProject(request.userId, request.projectId, "Member"))) {
        return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        QJsonObject{
            {"userId", request.userId},
            {"projectId", request.projectId}
        }
    };
}

Response ProjectService::leaveProject(const JoinRequest &request)
{
    qDebug() << "User" << request.userId << "has left project with ID" << request.projectId;

    if (!userProjectRepository->remove(UserProject(request.userId, request.projectId, ""))) {
        return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        QJsonObject{
            {"userId", request.userId},
            {"projectId", request.projectId}
        }
    };
}

Response ProjectService::getProjectsByUserId(const GetRequest& request) {
    QVector<UserProject> vec = userProjectRepository->getByUserId(request.id);

    qDebug() << "User" << request.id << "has " << vec.size() << "projects";

    QJsonArray array;
    for (int i = 0; i < vec.size(); i++) {
        Project project = projectRepository->getById(vec[i].getProjectId());
        User user = userRepository->getById(project.getOwnerId());

        array.append(ProjectResponse(
                        project.getId(),
                        project.getName(),
                        project.getDescription(),
                        UserResponse{user.getId(), user.getUsername(), user.getEmail()},
                        project.getCreatedAt()).toJson().object()
                    );
    }
    //for (auto x : array) qDebug() << x;

    return Response{Header{1, "OK"}.toJson().object(), array};
}

Response ProjectService::getProject(const GetRequest &request)
{
    Project project = projectRepository->getById(request.id);
    if (project.getId() == 0) {
        return Response{
            Header{0, "Project with id " + QString::number(request.id) + " does not exist"}.toJson().object(),
            ProjectResponse{}.toJson().object()
        };
    }
    User user =  userRepository->getById(project.getOwnerId());
    return Response{
        Header{1, "OK"}.toJson().object(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJson().object()
    };
}

/*
 * Добавить проверку на существование имени проекта
 * Добавить проверку на наличие прав для выполения действия
*/
Response ProjectService::postProject(qintptr descriptor, const ProjectRequest& request) {
    if (sessionRepository->getByDescriptor(descriptor).getUserId() != request.ownerId) {
        return Response{Header{0, "Access to perform this action has been denied"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (request.projectId != 0) {
        return Response{Header{0, "Project ID can not be specified for creation"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (projectRepository->getByName(request.name).getId() != 0) {
        return Response{Header{0, "Project name has already been taken"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (!projectRepository->save(Project(request.name, request.description, request.ownerId, request.createdAt))) {
        return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    Project project = projectRepository->getByName(request.name); // necessary
    User user = userRepository->getById(project.getOwnerId());

    if (!userProjectRepository->save(UserProject(user.getId(), project.getId(), "Owner"))) { // TODO: Добавить транзакции
        return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJson().object()
    };
}

/* descriptor userId can update -> id != 0 -> get project ->
 *      old createdAt == new createdAt
 *      old name != new name:
 *          new name not in database
 *      old ownerId != new ownerId:
 *          descriptor userId == old ownerId -> new ownerId in project -> user save
 *      project save
 *
*/
Response ProjectService::updateProject(qintptr descriptor, const ProjectRequest& request) { // TODO: fix save() and stuff
    UserProject userProject = userProjectRepository->getByUserIdAndProjectId(
        sessionRepository->getByDescriptor(descriptor).getUserId(),
        request.projectId);
    if (userProject.getUserId() == 0 || userProject.getRole() != "Admin" || userProject.getRole() != "Owner") { // TODO: Заменить на метод проверки прав для update
        return Response{Header{0, "Access to perform this action has been denied"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (request.projectId <= 0) {
        return Response{Header{0, "Invalid project ID"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    Project project = projectRepository->getById(request.projectId);
    if (project.getId() == 0) {
        return Response{Header{0, "Project does not exist"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (project.getName() != request.name) {
        if (projectRepository->getByName(request.name).getId() != 0) {
            return Response{Header{0, "Project name has already been taken"}.toJson().object(), ProjectResponse{}.toJson().object()};
        }
    }

    if (project.getCreatedAt() != request.createdAt) {
        return Response{Header{0, "Creation date can not be changed"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    if (project.getOwnerId() != request.ownerId) {
        if (userProject.getRole() != "Owner") {
            return Response{Header{0, "Access to perform this action has been denied"}.toJson().object(), ProjectResponse{}.toJson().object()};
        }
        if (userProjectRepository->getByUserIdAndProjectId(request.ownerId, request.projectId).getUserId() == 0) {
            return Response{Header{0, "User must be a member of the project"}.toJson().object(), ProjectResponse{}.toJson().object()};
        }
        if (!userProjectRepository->save(UserProject(project.getOwnerId(), project.getId(), "Admin"))
            || !userProjectRepository->save(UserProject(request.ownerId, project.getId(), "Owner"))) { // TODO: Добавить транзакции
            return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
        }
    }

    if (!projectRepository->save(Project(request.projectId, request.name, request.description, request.ownerId, request.createdAt))) {
        return Response{Header{0, "Internal error"}.toJson().object(), ProjectResponse{}.toJson().object()};
    }

    project = projectRepository->getById(request.projectId); // unnecessary
    User user = userRepository->getById(request.ownerId);

    return Response{
        Header{1, "OK"}.toJson().object(),
        ProjectResponse{
            project.getId(),
            project.getName(),
            project.getDescription(),
            UserResponse{user.getId(), user.getUsername(), user.getEmail()},
            project.getCreatedAt()
        }.toJson().object()
    };
}
