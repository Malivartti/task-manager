#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screensfactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    container = new QStackedWidget;
    container->setObjectName("ui");

    QString mainStyle = "QWidget#window {"
                        "background-color:#EFF5FC;"
                        "}";
    container->setStyleSheet(mainStyle);
    container->setObjectName("window");

    this->factory = new ScreensFactory;
    qDebug("ScreensFactory created");
    this->navigator = new Navigator(
        this->container,
        this->factory
    );

    this->setWindowTitle("MyTask");
    this->setCentralWidget(container);
    this->resize(400, 300);

    qDebug("MainWindow created");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete container;
    delete navigator;
    delete factory;
}
