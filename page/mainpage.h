#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QJsonArray>

#include "../basepage.h"
#include "../dto/simplerequest.h"
#include "../model/project.h"

class MainPage : public BasePage
{
    Q_OBJECT
public:
    MainPage();

    Q_INVOKABLE void getProjects(unsigned int id);

    void notify(quint16 key, const QJsonDocument &response) override;

    void processOneProject(const QJsonDocument &object);
    void processManyProjects(const QJsonDocument &object);

signals:
    void displayProjects(QVariantList list);
    void appendProject(QVariantMap map);
    void replaceProject(int index, QVariantMap map);
};

#endif // MAINPAGE_H
