#include "projectfragment.h"
#include "ui_projectfragment.h"

ProjectFragment::ProjectFragment(QWidget *parent)
    : BaseFragment(parent)
    , ui(new Ui::ProjectFragment)
{
    ui->setupUi(this);
    //ui->label->setText(model->name);
    qDebug("Login UI created");
}

void ProjectFragment::setData(BaseModel *model)
{
    ProjectModel *project = dynamic_cast<ProjectModel*>(model);
    this->model = project;
    ui->label->setText(this->model->name);
    qDebug("Login UI set");
}

ProjectFragment::~ProjectFragment()
{
    delete ui;
}

void ProjectFragment::on_pushButton_clicked()
{
    back();
}

