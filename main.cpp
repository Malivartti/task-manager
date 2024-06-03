#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "controller.h"
#include "page/authpage.h"
#include "page/mainpage.h"
#include "page/homepage.h"
#include "page/backlogpage.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Controller* controller = Controller::getInstance();
    controller->connectToServer();

    QQuickStyle::setStyle("Basic");

    QQmlApplicationEngine engine;

    qmlRegisterType<AuthPage>("AuthPage", 1, 0, "AuthControl");
    qmlRegisterType<MainPage>("MainPage", 1, 0, "MainControl");
    qmlRegisterType<HomePage>("HomePage", 1, 0, "HomeControl");
    qmlRegisterType<BacklogPage>("BacklogPage", 1, 0, "BacklogControl");

    const QUrl url(QStringLiteral("qrc:/MainClient/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
