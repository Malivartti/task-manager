#ifndef TASKSERVICETESTS_H
#define TASKSERVICETESTS_H

#include <QTest>
#include <QRandomGenerator>

#include "../service/authservice.h"
#include "../service/taskservice.h"

class TaskServiceTests : public QObject
{
    Q_OBJECT
private:
    qintptr descriptor;
    unsigned int userId;

    AuthService* authService = AuthService::getInstance();
    TaskService* taskService = TaskService::getInstance();
public:
    TaskServiceTests();

private slots:
    void getTask();
    void getTasksByUserId();
    void getTasksByProjectId();
    void postTask();
    void updateTask();

    void cleanupTestCase()
    {
        authService->logout(descriptor, {});
    }
};

#endif // TASKSERVICETESTS_H
