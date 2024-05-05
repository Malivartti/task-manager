#include "homepage.h"
#include "../../models/owner/ownermodel.h"
#include "../../models/homeRecentProject/homerecentprojectmodel.h"
#include "../../models/homeTask/hometaskmodel.h"

HomePage::HomePage() {
    getData();
}

void HomePage::getData() {
    OwnerModel o1 {1, "malivartty"};
    OwnerModel o2 {2, "MdxR"};

    HomeRecentProjectModel p1 {1, "Project 1", &o1, 2, 1};
    HomeRecentProjectModel p2 {2, "Project 2", &o2, 4, 1};
    HomeRecentProjectModel p3 {3, "Project 3", &o1, 0, 1};
    HomeRecentProjectModel p4 {4, "Project 4", &o2, 0, 0};

    HomeTaskModel t1 {1, "Taks 1", "Project 1", "In Progress"};
    HomeTaskModel t2 {2, "Taks 2", "Project 2", "In Progress"};
    HomeTaskModel t3 {3, "Taks 3", "Project 2", "In Progress"};

    HomeTaskModel t4 {4, "Taks 4", "Project 3", "In Do"};
    HomeTaskModel t5 {5, "Taks 5", "Project 3", "In Do"};
    HomeTaskModel t6 {6, "Taks 6", "Project 1", "In Do"};

    // m_recentProjects.push_back(&p1);
    // m_recentProjects.push_back(&p2);
    // m_recentProjects.push_back(&p3);
    // m_recentProjects.push_back(&p4);

    // m_tasksInProgres.push_back(&t1);
    // m_tasksInProgres.push_back(&t2);
    // m_tasksInProgres.push_back(&t3);

    // m_tasksToDo.push_back(&t4);
    // m_tasksToDo.push_back(&t5);
    // m_tasksToDo.push_back(&t6);
}

// std::vector<HomeRecentProjectModel*> HomePage::recentProjects() const {
//     return m_recentProjects;
// }

// std::vector<HomeTaskModel*> HomePage::tasksInProgres() const {
//     return m_tasksInProgres;
// }

// std::vector<HomeTaskModel*> HomePage::tasksToDo() const {
//     return m_tasksToDo;
// }

//     Q_PROPERTY(type recentProjects READ name WRITE setRecentProjects NOTIFY recentProjectsChanged FINAL);
// Q_PROPERTY(type tasksInProgres READ name WRITE setTasksInProgres NOTIFY tasksInProgresChanged FINAL);
// Q_PROPERTY(type tasksToDo READ name WRITE setTasksToDo NOTIFY tasksToDoChanged FINAL);
