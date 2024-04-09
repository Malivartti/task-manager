#ifndef LOGINFRAGMENT_OLD_H
#define LOGINFRAGMENT_OLD_H

#include <QLineEdit>
#include <QPushButton>

#include "base/basefragment.h"

class LoginFragment_old: public BaseFragment {
public:
    LoginFragment_old();
private:
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
};

#endif // LOGINFRAGMENT_OLD_H
