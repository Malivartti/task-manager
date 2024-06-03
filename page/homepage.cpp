#include "homepage.h"

HomePage::HomePage()
{
    handler->addPage(this);
}

void HomePage::getTasks(unsigned int id)
{
    controller->sendToServer(202, SimpleRequest(id).toJson());
    qDebug() << "REQUESTED TASKS";
}

void HomePage::notify(quint16 key, const QJsonDocument &response)
{
    if (response["head"]["code"] == 0) return;
    if (key == 202) { processManyTasks(response); }
}

void HomePage::processManyTasks(const QJsonDocument &object)
{
    QVariantList list;
    QJsonArray array = object["body"].toArray();
    for (auto x : array) {
        list.append(Task(x).toVariantMap());
    }
    emit displayTasks(list);
}
