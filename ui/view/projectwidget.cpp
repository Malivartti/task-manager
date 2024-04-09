#include "projectwidget.h"
#include <QVBoxLayout>

ProjectWidget::ProjectWidget(ProjectModel *model) {
    this->model = model;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPushButton *openButton = new QPushButton(model->name);

    connect(openButton, &QPushButton::clicked, this, &ProjectWidget::buttonPressed);

    mainLayout->setContentsMargins(0,0,0,0);

    mainLayout->addWidget(openButton);
    this->setLayout(mainLayout);
}

ProjectWidget::~ProjectWidget() {
    //delete model;
}

void ProjectWidget::buttonPressed() {
    projectSelected(model);
}
