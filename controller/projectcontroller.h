#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include "base/controller.h"
#include "../service/projectservice.h"

class ProjectController : public Controller<ProjectController>
{
protected:
    ProjectController();

    ProjectService* projectService = ProjectService::getInstance();

    friend class Singleton<ProjectController>;
public:
    Response joinProject(qintptr descriptor, const ParticipationRequest& request);
    Response leaveProject(qintptr descriptor, const ParticipationRequest& request);
    Response getProject(qintptr descriptor, const SimpleRequest& request);
    Response getProjectsByUserId(qintptr descriptor, const SimpleRequest& request);
    Response postProject(qintptr descriptor, const ProjectPostRequest& request);
    Response updateProject(qintptr descriptor, const ProjectUpdateRequest& request);
    Response redirectToProject(qintptr descriptor, const SimpleRequest& request);
};

#endif // PROJECTCONTROLLER_H
