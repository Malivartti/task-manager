#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QObject>
#include "../../models/homeRecentProject/homerecentprojectmodel.h"
#include "../../models/homeTask/hometaskmodel.h"
#include <vector>

class HomePage : public QObject
{
    Q_OBJECT
public:
    HomePage();
    Q_INVOKABLE void getData();
    // Q_PROPERTY(std::vector<HomeRecentProjectModel*> recentProjects READ name WRITE setRecentProjects NOTIFY recentProjectsChanged FINAL);
    // Q_PROPERTY(std::vector<HomeTaskModel*> tasksInProgres READ name WRITE setTasksInProgres NOTIFY tasksInProgresChanged FINAL);
    // Q_PROPERTY(std::vector<HomeTaskModel*> tasksToDo READ name WRITE setTasksToDo NOTIFY tasksToDoChanged FINAL);

    std::vector<HomeRecentProjectModel*> recentProjects() const;
    std::vector<HomeTaskModel*> tasksInProgres() const;
    std::vector<HomeTaskModel*> tasksToDo() const;
private:
    // std::vector<HomeRecentProjectModel*> m_recentProjects;
    // std::vector<HomeTaskModel*> m_tasksInProgres;
    // std::vector<HomeTaskModel*> m_tasksToDo;
};

#endif // HOMEPAGE_H
