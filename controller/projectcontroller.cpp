#include "projectcontroller.h"

ProjectController::ProjectController() {}

// KEY: 101
Response ProjectController::joinProject(qintptr descriptor, const ParticipationRequest &request)
{
    if (request.projectId <= 0) {}
    return projectService->joinProject(descriptor, request);
}

// KEY: 102
Response ProjectController::leaveProject(qintptr descriptor, const ParticipationRequest &request)
{
    if (request.projectId <= 0) {}
    return projectService->leaveProject(descriptor, request);
}

// KEY: 103
Response ProjectController::getProject(qintptr descriptor, const SimpleRequest &request)
{
    if (request.id <= 0) {}
    return projectService->getProject(descriptor, request);
}

// KEY: 104
Response ProjectController::getProjectsByUserId(qintptr descriptor, const SimpleRequest &request)
{
    if (request.id <= 0) {}
    return projectService->getProjectsByUserId(descriptor, request);
}

// KEY: 105
Response ProjectController::postProject(qintptr descriptor, const ProjectPostRequest &request)
{
    return projectService->postProject(descriptor, request);
}

// KEY: 106
Response ProjectController::updateProject(qintptr descriptor, const ProjectUpdateRequest &request)
{
    if (request.projectId <= 0 || request.ownerId <= 0) {}
    return projectService->updateProject(descriptor, request);
}

// KEY: 199
Response ProjectController::redirectToProject(qintptr descriptor, const SimpleRequest &request)
{
    if (request.id < 0) {}
    return projectService->redirectToProject(descriptor, request);
}
