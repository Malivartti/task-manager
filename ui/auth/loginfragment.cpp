#include "loginfragment.h"
#include "ui_loginfragment.h"
#include <string>
#include <QMessageBox>

#include "screensfactory.h"

std::string username = "MDxR";
std::string password = "12345";

LoginFragment::LoginFragment(QWidget *parent)
    : BaseFragment(parent)
    , ui(new Ui::LoginFragment)
{
    ui->setupUi(this);
    qDebug("Login UI created");
}

LoginFragment::~LoginFragment()
{
    delete ui;
}

void LoginFragment::on_logIn_clicked()
{
    if (ui->login->text().toStdString() == username && ui->password->text().toStdString() == password) navigateTo(screens::MAIN_TAG);
    else QMessageBox::information(this, "Status", "Invalid Password or Username");
}

