#include "mainfragment.h"
#include "ui_mainfragment.h"
#include <vector>
#include <QString>
#include "ui/view/projectwidget.h"

#include "screensfactory.h"

std::vector<QString> projects = {"Project 10", "Project 2", "Project 3"};

MainFragment::MainFragment(QWidget *parent)
    : BaseFragment(parent)
    , ui(new Ui::MainFragment)
{
    ui->setupUi(this);
    qDebug("Main UI created");
    for (auto x : projects) {
        ProjectModel *projectModel = new ProjectModel(0, x);
        ProjectWidget *projectWidget = new ProjectWidget(projectModel);
        connect(projectWidget, &ProjectWidget::projectSelected, this, &MainFragment::projectSelected);
        ui->verticalLayout->addWidget(projectWidget);
    }
}

MainFragment::~MainFragment()
{
    delete ui;
}

void MainFragment::projectSelected(ProjectModel* project) {
    qDebug("Main Fragment navigateWithData");
    navigateWithData(screens::PROJECT_TAG, project);
}
