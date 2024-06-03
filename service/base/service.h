#ifndef SERVICE_H
#define SERVICE_H

#include "../../base/component.h"

/**
 * @brief The Base Service.
 * @details Services are responsible for buisness logic of the application. This class provides interface for descendants and specifies that the descendant is a service.
*/
template <class T>
class Service : public Component<T>
{
protected:
    Service() {};
};

#endif // SERVICE_H
