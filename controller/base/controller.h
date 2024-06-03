#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../../base/component.h"

/**
 * @brief The Base Controller.
 * @details Controllers are responsible for:
 * 1. Listening to requests.
 * 2. Deserializing the input from the incoming request.
 * 3. Validating the Deserialized objects.
 * 4. Calling business logic (services).
 * 5. Serializing the output of the controller function if necessary.
 * 6. Handling exceptions.
 * @details This class provides interface for descendants and specifies that the descendant is a controller.
*/
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
