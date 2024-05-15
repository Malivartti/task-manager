#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "base/controller.h"
#include "../service/authservice.h"

class AuthController : public Controller<AuthController>
{
protected:
    AuthService* authService = AuthService::getInstance();
    AuthController();

    friend class Singleton<AuthController>;
public:
    Response login(qintptr descriptor, const LoginRequest& request);
    Response reg(qintptr descriptor, const RegisterRequest& request);
    Response logout(qintptr descriptor, const SimpleRequest& request);
};

#endif // AUTHCONTROLLER_H
