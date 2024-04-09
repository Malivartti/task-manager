#ifndef LOGINFRAGMENT_H
#define LOGINFRAGMENT_H

#include <QDialog>
#include "base/basefragment.h"

namespace Ui {
class LoginFragment;
}

class LoginFragment : public BaseFragment
{
    Q_OBJECT

public:
    explicit LoginFragment(QWidget *parent = nullptr);
    ~LoginFragment();

private slots:
    void on_logIn_clicked();

private:
    Ui::LoginFragment *ui;
};

#endif // LOGINFRAGMENT_H
