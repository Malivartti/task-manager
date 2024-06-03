#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "base/controller.h"
#include "../service/authservice.h"

/**
 * @brief The Controller for processing authorization requests.
 * @details The Controller validates Client' authorization requests, dispatches them to specific commands provided by AuthService to trigger behavior associated with the request.
*/
class AuthController : public Controller<AuthController>
{
protected:
    AuthService* authService = AuthService::getInstance();
    AuthController();

    friend class Singleton<AuthController>;
public:
    /**
     * @brief The Method for authorization.
     * @details The Method is invoked with **key 1**.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for signing in.
     * @return Response to the authorization request.
    */
    Response login(qintptr descriptor, const LoginRequest& request);

    /**
     * @brief The Method for registation.
     * @details The Method is invoked with **key 2**.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for signing up.
     * @return Response to the registation request.
    */
    Response reg(qintptr descriptor, const RegisterRequest& request);

    /**
     * @brief The Method for logging out.
     * @details The Method is invoked with **key 3**.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for signing up.
     * @return Response to the registation request.
    */
    Response logout(qintptr descriptor, const SimpleRequest& request);
};

#endif // AUTHCONTROLLER_H
