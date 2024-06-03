#ifndef PROJECTSERVICE_H
#define PROJECTSERVICE_H

#include <QVector>
#include <QJsonArray>
#include <QString>

#include "base/service.h"
#include "../repository/userrepository.h"
#include "../repository/projectrepository.h"
#include "../repository/userprojectrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/participationrequest.h"
#include "../dto/request/projectrequest.h"
#include "../dto/request/projectpostrequest.h"
#include "../dto/request/projectupdaterequest.h"
#include "../dto/response/projectresponse.h"

/**
 * @brief The Service for projects.
 * @details Provides required functionality for manipulating projects.
*/
class ProjectService : public Service<ProjectService>
{
protected:
    UserRepository* userRepository = UserRepository::getInstance();
    ProjectRepository* projectRepository = ProjectRepository::getInstance();
    UserProjectRepository* userProjectRepository = UserProjectRepository::getInstance();
    SessionRepository* sessionRepository = SessionRepository::getInstance();

    ProjectService();

    friend class Singleton<ProjectService>;
public:
    /**
     * @brief The Method for joining project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for joining project.
     * @return Response to the participation request.
    */
    Response joinProject(qintptr descriptor, const ParticipationRequest& request);

    /**
     * @brief The Method for leaving project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for leaving project.
     * @return Response to the participation request.
    */
    Response leaveProject(qintptr descriptor, const ParticipationRequest& request);

    /**
     * @brief The Method for obtaining general information about project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for project's data.
     * @return Response to the participation request.
    */
    Response getProject(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for obtaining general information about project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for project's data.
     * @return Response to the participation request.
    */
    Response getProjectsByUserId(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for posting (creating) project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for creating project.
     * @return Response to the post request.
    */
    Response postProject(qintptr descriptor, const ProjectPostRequest& request);

    /**
     * @brief The Method for updating project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for updating project.
     * @return Response to the update request.
    */
    Response updateProject(qintptr descriptor, const ProjectUpdateRequest& request);

    /**
     * @brief The Method for deleting project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for deleting project.
     * @return Response to the delete request.
    */
    Response removeProject(qintptr descriptor, const SimpleRequest& request);

    /**
     * @brief The Method for redirecting to a project so as to recieve all updates with project.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for redirecting.
     * @return Response to the redirect request.
    */
    Response redirectToProject(qintptr descriptor, const SimpleRequest& request);
};

#endif // PROJECTSERVICE_H
