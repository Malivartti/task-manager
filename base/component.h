#ifndef COMPONENT_H
#define COMPONENT_H

#include "singleton.h"

template <class T>
class Component : public Singleton<T>
{
protected:
    Component() {};

    //virtual void pol() = 0; // Запрет на создание Component
    friend class Singleton<T>;
};

#endif // COMPONENT_H
