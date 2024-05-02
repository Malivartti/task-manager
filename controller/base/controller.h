#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "base/component.h"
#include "base/baseserver.h"
#include "service/authservice.h"

enum class KEY {LOGIN = 1, REG, JOIN_PROJECT = 101, LEAVE_PROJECT};

template <class T>
class Controller : public Component<T>
{
protected:
    static inline BaseServer* server = nullptr;

    AuthService* authService = AuthService::getInstance();

    Controller() {};
public:
    void setServer(BaseServer* server)
    {
        if (this->server == nullptr) this->server = server;
    };
};

#endif // CONTROLLER_H
