#ifndef PROJECTSERVICETESTS_H
#define PROJECTSERVICETESTS_H

#include <QTest>
#include <QRandomGenerator>

#include "../service/authservice.h"
#include "../service/projectservice.h"

class ProjectServiceTests : public QObject
{
    Q_OBJECT
private:
    qintptr descriptor;
    unsigned int userId;

    AuthService* authService = AuthService::getInstance();
    ProjectService* projectService = ProjectService::getInstance();
public:
    ProjectServiceTests();

private slots:
    void getProject();
    void getProjectsByUserId();
    void joinLeaveProject();
    void postProject();
    void updateProject();

    void cleanupTestCase()
    {
        authService->logout(descriptor, {});
    }
};

#endif // PROJECTSERVICETESTS_H
