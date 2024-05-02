#ifndef PROJECTSERVICE_H
#define PROJECTSERVICE_H

#include <QVector>
#include <QJsonArray>
#include <QString>

#include "base/service.h"
#include "repository/userrepository.h"
#include "repository/projectrepository.h"
#include "repository/userprojectrepository.h"
#include "repository/sessionrepository.h"
#include "dto/base/response.h"
#include "dto/request/getrequest.h"
#include "dto/request/joinrequest.h"
#include "dto/request/projectrequest.h"
#include "dto/response/projectresponse.h"

class ProjectService : public Service<ProjectService>
{
protected:
    UserRepository* userRepository = (UserRepository*)UserRepository::getInstance();
    ProjectRepository* projectRepository = (ProjectRepository*)ProjectRepository::getInstance();
    UserProjectRepository* userProjectRepository = (UserProjectRepository*)UserProjectRepository::getInstance();
    SessionRepository* sessionRepository = (SessionRepository*)SessionRepository::getInstance();

    ProjectService();

    friend class Singleton<ProjectService>;
public:
    Response joinProject(const JoinRequest& request);
    Response leaveProject(const JoinRequest& request);

    Response getProjectsByUserId(const GetRequest& request);
    Response getProject(const GetRequest& request);

    Response postProject(qintptr descriptor, const ProjectRequest& request);
    Response removeProject(const GetRequest& request);
    Response updateProject(qintptr descriptor, const ProjectRequest& request);

    Response redirectFromProject(const GetRequest& request);
    Response redirectToProject(const GetRequest& request);
};

#endif // PROJECTSERVICE_H
