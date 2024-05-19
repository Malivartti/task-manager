#include "taskservice.h"

TaskService::TaskService() {}

Response TaskService::getTask(qintptr descriptor, const SimpleRequest &request)
{
    Task task = taskRepository->getById(request.id);
    if (task.getId() == 0) {
        return Response{
            Header{0, "Project with id " + QString::number(request.id) + " does not exist"}.toJsonObject(),
            TaskResponse{}.toJsonObject()
        };
    }
    Project project = projectRepository->getById(task.getProjectId());
    User user = userRepository->getById(task.getCreatorId());

    return Response{
        Header{1, "OK"}.toJsonObject(),
        TaskResponse{
            task.getId(),
            task.getName(),
            task.getDescription(),
            ProjectResponse{
                project.getId(),
                project.getName(),
                project.getDescription(),
                {},
                project.getCreatedAt()
            },
            task.getSprintId(),
            UserResponse{
                user.getId(),
                user.getUsername(),
                user.getEmail()
            },
            task.getStartAt(),
            task.getEndAt(),
            task.getResolvedAt()
        }.toJsonObject()
    };
}

Response TaskService::getTasksByUserId(qintptr descriptor, const SimpleRequest &request)
{
    QVector<UserTask> vec = userTaskRepository->getByUserId(request.id);

    qDebug() << "User" << request.id << "has" << vec.size() << "tasks";

    QJsonArray array;
    for (int i = 0; i < vec.size(); i++) {
        Task task = taskRepository->getById(vec[i].getTaskId());
        User user = userRepository->getById(vec[i].getUserId());
        Project project = projectRepository->getById(task.getProjectId());

        array.append(TaskResponse{
                task.getId(),
                task.getName(),
                task.getDescription(),
                ProjectResponse{
                    project.getId(),
                    project.getName(),
                    project.getDescription(),
                    {},
                    project.getCreatedAt()
                },
                task.getSprintId(),
                UserResponse{
                    user.getId(),
                    user.getUsername(),
                    user.getEmail()
                },
                task.getStartAt(),
                task.getEndAt(),
                task.getResolvedAt()
            }.toJsonObject()
        );
    }

    return Response{Header{1, "OK"}.toJsonObject(), array};
}

/*
 * Добавить проверку на существование спринта
 * Добавить проверки времени (>0, startAt < endAt) или в postgres, или сюда
*/
Response TaskService::postTask(qintptr descriptor, const TaskPostRequest &request)
{
    Project project = projectRepository->getById(request.projectId);
    if (project.getId() == 0) {
        return Response{Header{0, "Project does not exist"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    Session session = sessionRepository->getByDescriptor(descriptor);
    UserProject userProject = userProjectRepository->getByUserIdAndProjectId(session.getUserId(), project.getId());
    if (userProject.getRole() != "Admin" || userProject.getRole() != "Owner") {
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(session.getUserId());

    Task task = taskRepository->save(Task(
            request.name,
            request.description,
            project.getId(),
            request.sprintId,
            user.getId(),
            request.startAt,
            request.endAt,
            request.resolvedAt
        )
    );
    if (task.getId() == 0) {
        return Response{Header{0, "Internal error"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        TaskResponse{
            task.getId(),
            task.getName(),
            task.getDescription(),
            ProjectResponse{
                project.getId(),
                project.getName(),
                project.getDescription(),
                {},
                project.getCreatedAt()
            },
            task.getSprintId(),
            UserResponse{
                user.getId(),
                user.getUsername(),
                user.getEmail()
            },
            task.getStartAt(),
            task.getEndAt(),
            task.getResolvedAt()
        }.toJsonObject()
    };
}

Response TaskService::updateTask(qintptr descriptor, const TaskUpdateRequest &request)
{
    Task task = taskRepository->getById(request.taskId);
    if (task.getId() == 0) {
        return Response{Header{0, "Task does not exist"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    Session session = sessionRepository->getByDescriptor(descriptor);
    UserProject userProject = userProjectRepository->getByUserIdAndProjectId(session.getUserId(), task.getProjectId());
    if (userProject.getRole() != "Admin" || userProject.getRole() != "Owner") {
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    task = taskRepository->save(Task(
            request.taskId,
            request.name,
            request.description,
            task.getProjectId(),
            request.sprintId,
            task.getCreatorId(),
            request.startAt,
            request.endAt,
            request.resolvedAt
        )
    );
    if (task.getId() == 0) {
        return Response{Header{0, "Internal error"}.toJsonObject(), TaskResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(task.getCreatorId());
    Project project = projectRepository->getById(task.getProjectId());

    return Response{
        Header{1, "OK"}.toJsonObject(),
        TaskResponse{
            task.getId(),
            task.getName(),
            task.getDescription(),
            ProjectResponse{
                project.getId(),
                project.getName(),
                project.getDescription(),
                {},
                project.getCreatedAt()
            },
            task.getSprintId(),
            UserResponse{
                user.getId(),
                user.getUsername(),
                user.getEmail()
            },
            task.getStartAt(),
            task.getEndAt(),
            task.getResolvedAt()
        }.toJsonObject()
    };
}

Response TaskService::removeTask(qintptr descriptor, const SimpleRequest &request)
{

}
