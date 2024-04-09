#ifndef MAINFRAGMENT_H
#define MAINFRAGMENT_H

#include <QDialog>

#include "base/basefragment.h"
#include "models/projectmodel.h"

namespace Ui {
class MainFragment;
}

class MainFragment : public BaseFragment
{
    Q_OBJECT

public:
    explicit MainFragment(QWidget *parent = nullptr);
    ~MainFragment();

public slots:
    void projectSelected(ProjectModel* project);

private:
    Ui::MainFragment *ui;
};

#endif // MAINFRAGMENT_H
