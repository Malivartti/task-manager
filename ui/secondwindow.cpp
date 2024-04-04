#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QJsonValue>
#include <QLabel>
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QSettings>

SecondWindow::SecondWindow(QWidget *parent)
    : BaseFragment(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    qDebug("UI created");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
