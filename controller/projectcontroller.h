#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include "base/controller.h"
#include "../service/projectservice.h"
#include "../service/taskservice.h"

/**
 * @brief The Controller for processing project related request (request for project's service, task's service, etc).
 * @details The Controller validates Client' requests, dispatches them to specific commands provided by related services to trigger behavior associated with the request.
*/
class ProjectController : public Controller<ProjectController>
{
protected:
    ProjectController();

    ProjectService* projectService = ProjectService::getInstance();
    TaskService* taskService = TaskService::getInstance();

    friend class Singleton<ProjectController>;
public:
    // Project
    Response joinProject(qintptr descriptor, const ParticipationRequest& request);
    Response leaveProject(qintptr descriptor, const ParticipationRequest& request);
    Response getProject(qintptr descriptor, const SimpleRequest& request);
    Response getProjectsByUserId(qintptr descriptor, const SimpleRequest& request);
    Response postProject(qintptr descriptor, const ProjectPostRequest& request);
    Response updateProject(qintptr descriptor, const ProjectUpdateRequest& request);
    Response redirectToProject(qintptr descriptor, const SimpleRequest& request);

    // Task
    Response getTask(qintptr descriptor, const SimpleRequest& request);
    Response getTasksByUserId(qintptr descriptor, const SimpleRequest& request);
    Response getTasksByProjectId(qintptr descriptor, const SimpleRequest& request);
    Response postTask(qintptr descriptor, const TaskPostRequest& request);
    Response updateTask(qintptr descriptor, const TaskUpdateRequest& request);
};

#endif // PROJECTCONTROLLER_H
