#ifndef SCREENSFACTORY_H
#define SCREENSFACTORY_H

#include "base/basescreensfactory.h"

namespace screens {
    static const QString SPLASH_TAG = "splash"; //идентификатор стартового экрана
    static const QString LOGIN_TAG = "login";
    static const QString MAIN_TAG = "main";
    static const QString PROJECT_TAG = "project";
};

class ScreensFactory: public BaseScreensFactory {
public:
    ScreensFactory();
    ~ScreensFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // SCREENSFACTORY_H
