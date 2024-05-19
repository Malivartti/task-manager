#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include <QVector>
#include <QJsonArray>
#include <QString>

#include "base/service.h"
#include "../repository/taskrepository.h"
#include "../repository/usertaskrepository.h"
#include "../repository/userrepository.h"
#include "../repository/projectrepository.h"
#include "../repository/userprojectrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/taskpostrequest.h"
#include "../dto/request/taskupdaterequest.h"
#include "../dto/response/taskresponse.h"

class TaskService : public Service<TaskService>
{
protected:
    TaskRepository* taskRepository = TaskRepository::getInstance();
    UserTaskRepository* userTaskRepository = UserTaskRepository::getInstance();
    UserRepository* userRepository = UserRepository::getInstance();
    ProjectRepository* projectRepository = ProjectRepository::getInstance();
    UserProjectRepository* userProjectRepository = UserProjectRepository::getInstance();
    SessionRepository* sessionRepository = SessionRepository::getInstance();

    TaskService();

    friend class Singleton<TaskService>;
public:
    Response getTask(qintptr descriptor, const SimpleRequest& request);
    Response getTasksByUserId(qintptr descriptor, const SimpleRequest& request);

    Response postTask(qintptr descriptor, const TaskPostRequest& request);
    Response updateTask(qintptr descriptor, const TaskUpdateRequest& request);
    Response removeTask(qintptr descriptor, const SimpleRequest& request);
};

#endif // TASKSERVICE_H
