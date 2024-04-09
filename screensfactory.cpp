#include "screensfactory.h"
#include "ui/auth/loginfragment.h"
#include "ui/secondwindow.h"
#include "ui/mainfragment.h"
#include "ui/project/projectfragment.h"

using namespace screens;

ScreensFactory::ScreensFactory() {}

ScreensFactory::~ScreensFactory() {}

BaseFragment* ScreensFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new LoginFragment; //Splash на LoginFragment и RegisterFragment
    } else if (tag == LOGIN_TAG) {
        return new LoginFragment;
    }
    else if (tag == MAIN_TAG) {
        return new MainFragment;
    }
    else if (tag == PROJECT_TAG) {
        return new ProjectFragment;
    }
}

QString ScreensFactory::createStart() {
    qDebug("Start screen created");
    return SPLASH_TAG; //идентификатор стартового экрана.
}
