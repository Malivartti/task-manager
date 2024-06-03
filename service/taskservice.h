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

/**
 * @brief The Service for tasks.
 * @details Provides required functionality for manipulating tasks.
*/
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

    /**
     * @brief The Method for obtaining all task's performers.
     * @param id Task's id.
     * @return QJsonArray which contains task's performers.
    */
    QJsonArray getPerformersByTaskId(unsigned int id);
public:
    /**
     * @brief The Method for obtaining complete information about task.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for task's data.
     * @return Response to the request.
    */
    Response getTask(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for obtaining all user's tasks.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for user's tasks.
     * @return Response to the request.
    */
    Response getTasksByUserId(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for obtaining all project's tasks.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for project's tasks.
     * @return Response to the request.
    */
    Response getTasksByProjectId(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for verifying where user is allowed to update task or not.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request which contains task's ID.
     * @return Response to the request.
    */
    Response isAllowedToUpdateTask(qintptr descriptor, const SimpleRequest& request); // добавить реализациию

    /**
     * @brief The Method for posting (creating) task.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for creating task.
     * @return Response to the post request.
    */
    Response postTask(qintptr descriptor, const TaskPostRequest& request);

    /**
     * @brief The Method for updating task.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for updating task.
     * @return Response to the update request.
    */
    Response updateTask(qintptr descriptor, const TaskUpdateRequest& request);

    /**
     * @brief The Method for deleting task.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for deleting task.
     * @return Response to the delete request.
    */
    Response removeTask(qintptr descriptor, const SimpleRequest& request);
};

#endif // TASKSERVICE_H
