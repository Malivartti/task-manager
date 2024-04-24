#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QJsonDocument>

#include "base/component.h"
#include "service/authservice.h"

class ApplicationController : public Component<ApplicationController>
{
protected:
    ApplicationController();

    friend class Singleton<ApplicationController>;
public:
    QJsonDocument mapRequest(quint16 key, QDataStream& in);
};

#endif // APPLICATIONCONTROLLER_H
