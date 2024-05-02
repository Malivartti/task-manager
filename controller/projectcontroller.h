#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include "controller/base/controller.h"
#include "service/projectservice.h"

class ProjectController : public Controller<ProjectController>
{
private:
    // QMap<quint16, std::function<Response(const QJsonDocument&)>> method = {
    //     { 101, [&service = this->projectService] (const QJsonDocument& object) { return service->joinProject(object); } },
    //     { 102, [&service = this->projectService] (const QJsonDocument& object) { return service->leaveProject(object); } },
    //     { 103, [&service = this->projectService] (const QJsonDocument& object) { return service->getProject(object); } }
    // };
protected:
    ProjectController();

    ProjectService* projectService = ProjectService::getInstance();

    friend class Singleton<ProjectController>;
public:
    void mapRequest(qintptr descriptor, quint16 key, const QJsonDocument& object);
};

#endif // PROJECTCONTROLLER_H
