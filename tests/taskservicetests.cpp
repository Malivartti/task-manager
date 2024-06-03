#include "taskservicetests.h"

#define GENERATOR QRandomGenerator::global()->bounded(10000, 200000)

TaskServiceTests::TaskServiceTests()
{
    descriptor = GENERATOR;
    userId = authService->login(descriptor, LoginRequest("MDxR", "12345")).body["userId"].toInt();
}

void TaskServiceTests::getTask()
{
    QCOMPARE(taskService->getTask(descriptor, GENERATOR).head["code"].toInt(), 0);
    QCOMPARE(taskService->getTask(descriptor, 1).body["id"].toInt(), 1);
    QCOMPARE(taskService->getTask(descriptor, 2).body["id"].toInt(), 2);
}

void TaskServiceTests::getTasksByUserId()
{
    QCOMPARE(taskService->getTasksByUserId(descriptor, GENERATOR).head["code"].toInt(), 1);
    QCOMPARE(taskService->getTasksByUserId(descriptor, 1).head["code"].toInt(), 1);
    QCOMPARE(taskService->getTasksByUserId(descriptor, 2).head["code"].toInt(), 1);
}

void TaskServiceTests::getTasksByProjectId()
{
    QCOMPARE(taskService->getTasksByProjectId(descriptor, GENERATOR).head["code"].toInt(), 1);
    QCOMPARE(taskService->getTasksByProjectId(descriptor, 1).head["code"].toInt(), 1);
    QCOMPARE(taskService->getTasksByProjectId(descriptor, 2).head["code"].toInt(), 1);
}

void TaskServiceTests::postTask()
{
    TaskPostRequest request(QString::number(GENERATOR), QString::number(GENERATOR), 1, 0, 0, 0, 0, "Not started");

    QCOMPARE(taskService->postTask(descriptor, request).head["code"].toInt(), 1);
    QCOMPARE(taskService->postTask(descriptor, request).head["code"].toInt(), 1);
    QCOMPARE(taskService->postTask(descriptor, {QString::number(GENERATOR), QString::number(GENERATOR), 2, 0, 0, 0, 0, "Not started"}).head["code"].toInt(), 0);
}

void TaskServiceTests::updateTask()
{
    QCOMPARE(taskService->updateTask(descriptor, {1, "Task 1", "This is my task!", 0, 0, 0, 0, "Not started"}).head["code"].toInt(), 1);
    QCOMPARE(taskService->updateTask(descriptor, {2, "Task 2", "This is my task!", 0, 0, 0, 0, "Not started"}).head["code"].toInt(), 0);
}
