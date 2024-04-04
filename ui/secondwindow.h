#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

#include "base/basefragment.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public BaseFragment
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private:
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
