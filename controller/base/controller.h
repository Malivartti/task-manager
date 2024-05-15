#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "base/component.h"

enum class KEY {LOGIN = 1, REG, JOIN_PROJECT = 101, LEAVE_PROJECT};

template <class T>
class Controller : public Component<T>
{
protected:
    Controller() {};
    // virtual ~Controller() = 0;
};

// template <class T>
// Controller<T>::~Controller() {}

#endif // CONTROLLER_H
