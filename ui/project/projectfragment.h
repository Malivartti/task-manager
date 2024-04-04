#ifndef PROJECTFRAGMENT_H
#define PROJECTFRAGMENT_H

#include <QDialog>
#include "base/basefragment.h"
#include "models/projectmodel.h"

namespace Ui {
class ProjectFragment;
}

class ProjectFragment : public BaseFragment
{
    Q_OBJECT

public:
    ProjectModel *model;
    explicit ProjectFragment(QWidget *parent = nullptr);
    ~ProjectFragment();

    void setData(BaseModel* model) override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProjectFragment *ui;
};

#endif // PROJECTFRAGMENT_H
