#ifndef SERVICE_H
#define SERVICE_H

#include "../../base/component.h"

template <class T>
class Service : public Component<T>
{
protected:
    Service() {};
};

#endif // SERVICE_H
