#include "mainpage.h"

MainPage::MainPage()
{
    handler->addPage(this);
}

void MainPage::getProjects(unsigned int id)
{
    controller->sendToServer(104, SimpleRequest(id).toJson());
}

void MainPage::notify(quint16 key, const QJsonDocument &response)
{
    if (response["head"]["code"] == 0) return;
    if (key == 104) { processManyProjects(response); }
    if (key == 105) { processOneProject(response); }
}

void MainPage::processOneProject(const QJsonDocument &object)
{
    emit appendProject(Project(object["body"]).toVariantMap());
}

void MainPage::processManyProjects(const QJsonDocument &object)
{
    QVariantList list;
    QJsonArray array = object["body"].toArray();
    for (auto x : array) {
        Project project = Project(x);
        //projects.push_back(project);
        list.append(project.toVariantMap());
    }
    emit displayProjects(list);
}
