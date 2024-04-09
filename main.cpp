#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "pages/authorization/authorizationpage.h"
#include "pages/registration/registrationpage.h"
#include "pages/main/mainpage.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<AuthorizationPage>("Authorization", 1, 0, "AuthorizationControl");
    qmlRegisterType<RegistrationPage>("Registration", 1, 0, "RegistrationControl");
    qmlRegisterType<MainPage>("Main", 1, 0, "MainControl");

    const QUrl url(u"qrc:/main.qml"_qs);
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

    return app.exec();
}
