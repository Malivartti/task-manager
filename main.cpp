#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "pages/authorization/authorizationpage.h"
#include "pages/registration/registrationpage.h"
#include "pages/main/mainpage.h"
#include "pages/home/homepage.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<AuthorizationPage>("Authorization", 1, 0, "AuthorizationControl");
    qmlRegisterType<RegistrationPage>("Registration", 1, 0, "RegistrationControl");
    qmlRegisterType<MainPage>("Main", 1, 0, "MainControl");
    qmlRegisterType<HomePage>("Home", 1, 0, "HomeControl");

    const QUrl url(u"qrc:/task-manager/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    Controller* controller = Controller::getInstance();
    controller->connectToServer();

    return app.exec();
}
