#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QJsonArray>

#include "../basepage.h"
#include "../dto/simplerequest.h"
#include "../model/task.h"

class HomePage: public BasePage
{
    Q_OBJECT
public:
    HomePage();

    Q_INVOKABLE void getTasks(unsigned int id);

    void notify(quint16 key, const QJsonDocument &response) override;

    void processOneTask(const QJsonDocument &object);
    void processManyTasks(const QJsonDocument &object);

signals:
    void displayTasks(QVariantList list);
    void appendTask(QVariantMap map);
    void replaceTask(int index, QVariantMap map);
};

#endif // HOMEPAGE_H
