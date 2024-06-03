#include "authcontroller.h"

AuthController::AuthController() {}

Response AuthController::login(qintptr descriptor, const LoginRequest &request)
{
    return authService->login(descriptor, request);
}

Response AuthController::reg(qintptr descriptor, const RegisterRequest &request)
{
    return authService->reg(descriptor, request);
}

Response AuthController::logout(qintptr descriptor, const SimpleRequest &request) // Зачем SimpleRequest, если logout по Session?
{
    return authService->logout(descriptor, request);
}
