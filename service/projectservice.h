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
    Response joinProject(qintptr descriptor, const ParticipationRequest& request);
    Response leaveProject(qintptr descriptor, const ParticipationRequest& request);

    Response getProjectsByUserId(qintptr descriptor, const SimpleRequest& request);
    Response getProject(qintptr descriptor, const SimpleRequest& request);

    Response postProject(qintptr descriptor, const ProjectPostRequest& request);
    Response removeProject(qintptr descriptor, const SimpleRequest& request);
    Response updateProject(qintptr descriptor, const ProjectUpdateRequest& request);

    Response redirectToProject(qintptr descriptor, const SimpleRequest& request);
};

#endif // PROJECTSERVICE_H
