#include "projectservicetests.h"

#define GENERATOR QRandomGenerator::global()->bounded(10000, 200000)

ProjectServiceTests::ProjectServiceTests()
{
    descriptor = GENERATOR;
    userId = authService->login(descriptor, LoginRequest("MDxR", "12345")).body["userId"].toInt();
}

void ProjectServiceTests::getProject()
{
    QCOMPARE(projectService->getProject(descriptor, GENERATOR).head["code"].toInt(), 0);
    QCOMPARE(projectService->getProject(descriptor, 1).body["id"].toInt(), 1);
    QCOMPARE(projectService->getProject(descriptor, 2).body["id"].toInt(), 2);
}

void ProjectServiceTests::getProjectsByUserId()
{
    QCOMPARE(projectService->getProjectsByUserId(descriptor, GENERATOR).head["code"].toInt(), 1);
    QCOMPARE(projectService->getProjectsByUserId(descriptor, 1).head["code"].toInt(), 1);
    QCOMPARE(projectService->getProjectsByUserId(descriptor, 2).head["code"].toInt(), 1);
}

void ProjectServiceTests::joinLeaveProject()
{
    QCOMPARE(projectService->joinProject(descriptor, GENERATOR).head["code"].toInt(), 0);
    QCOMPARE(projectService->joinProject(descriptor, 1).head["code"].toInt(), 0);
    QCOMPARE(projectService->joinProject(descriptor, 2).head["code"].toInt(), 1);
    QCOMPARE(projectService->leaveProject(descriptor, 2).head["code"].toInt(), 1);
}

void ProjectServiceTests::postProject()
{
    ProjectPostRequest request(QString::number(GENERATOR), QString::number(GENERATOR));

    QCOMPARE(projectService->postProject(descriptor, request).head["code"].toInt(), 1);
    QCOMPARE(projectService->postProject(descriptor, request).head["code"].toInt(), 0);
    QCOMPARE(projectService->postProject(GENERATOR, {QString::number(GENERATOR), QString::number(GENERATOR)}).head["code"].toInt(), 0);
}

void ProjectServiceTests::updateProject()
{
    QCOMPARE(projectService->updateProject(descriptor, {2, "Project 2", "This is project 2.", 2}).head["code"].toInt(), 0);
    QCOMPARE(projectService->updateProject(descriptor, {1, "Project 1", "This is project 1.", 2}).head["code"].toInt(), 0);
    QCOMPARE(projectService->updateProject(descriptor, {1, "Project 1", "This is my project!", 1}).head["code"].toInt(), 1);
    QCOMPARE(projectService->updateProject(descriptor, {1, "Project 2", "This is my project!", 1}).head["code"].toInt(), 0);
    QCOMPARE(projectService->updateProject(descriptor, {unsigned(GENERATOR), "Project 1", "This is my project!", 1}).head["code"].toInt(), 0);
}


