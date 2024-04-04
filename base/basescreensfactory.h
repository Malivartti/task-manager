#ifndef BASESCREENSFACTORY_H
#define BASESCREENSFACTORY_H

#include "basefragment.h"
#include <QString>

class BaseScreensFactory {
public:
    BaseScreensFactory();
    ~BaseScreensFactory();

    virtual BaseFragment* create(QString tag); //создает экран по его идентификатору
    virtual QString createStart(); //возвращает стартовый экран
};

#endif // BASESCREENSFACTORY_H
