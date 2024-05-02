#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QJsonDocument>
#include <QTcpSocket>

#include "controller/base/controller.h"
#include "controller/projectcontroller.h"

class ApplicationController : public Controller<ApplicationController>
{
protected:
    ApplicationController();

    ProjectController* projectController = ProjectController::getInstance();

    friend class Singleton<ApplicationController>;
public:
    void mapRequest(qintptr descriptor, QDataStream& in);
};

#endif // APPLICATIONCONTROLLER_H
