#include "backlogpage.h"

BacklogPage::BacklogPage()
{
    handler->addPage(this);
}

void BacklogPage::getTasks(unsigned int id)
{
    controller->sendToServer(203, SimpleRequest(id).toJson());
}

void BacklogPage::notify(quint16 key, const QJsonDocument &response)
{
    if (response["head"]["code"] == 0) return;
    if (key == 203) { processManyTasks(response); }
}

void BacklogPage::processManyTasks(const QJsonDocument &object)
{
    QVariantList list;
    QJsonArray array = object["body"].toArray();
    for (auto x : array) {
        list.append(Task(x).toVariantMap());
    }
    emit displayTasks(list);
}
