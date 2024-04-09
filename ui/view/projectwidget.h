#ifndef PROJECTWIDGET_H
#define PROJECTWIDGET_H

#include <QPushButton>
#include "models/projectmodel.h"
#include <QFrame>
#include <QWidget>

class ProjectWidget: public QWidget {
    Q_OBJECT

private:
    ProjectModel *model;
public:
    ProjectWidget(ProjectModel *desk);
    ~ProjectWidget();

signals:
    void projectSelected(ProjectModel* desk);

public slots:
    void buttonPressed();
};

#endif // PROJECTWIDGET_H
