#include "authservice.h"

static bool isEmail(QString& login) {
    return login.contains('@');
}

AuthService::AuthService() {}

QJsonDocument AuthService::login(LoginRequest &request)
{
    User user;
    if (isEmail(request.login)) { // email
        user = userRepository->getByEmail(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect email"}.toJson().object(),
                UserResponse{}.toJson().object()}.toJson();
        }
    }
    else { // username
        user = userRepository->getByUsername(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect username"}.toJson().object(),
                UserResponse{}.toJson().object()}.toJson();
        }
    }

    if (user.getPassword() != request.password) {
        return Response{
            Header{0, "Incorrect password"}.toJson().object(),
            UserResponse{}.toJson().object()}.toJson();
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJson().object()}.toJson();
}

QJsonDocument AuthService::reg(RegisterRequest& request) {
    if (userRepository->getByEmail(request.email).getId() != 0) {
        return Response{
            Header{0, "User with this email already exists"}.toJson().object(),
            UserResponse{}.toJson().object()}.toJson();
    }

    if (userRepository->getByUsername(request.username).getId() != 0) {
        return Response{
            Header{0, "User with this username already exists"}.toJson().object(),
            UserResponse{}.toJson().object()}.toJson();
    }

    if (!userRepository->save(User(request.email, request.username, request.password))) {
        return Response{
            Header{0, "Internal error"}.toJson().object(),
            UserResponse{}.toJson().object()}.toJson();
    }

    User user = userRepository->getByEmail(request.email);
    return Response{
        Header{1, "OK"}.toJson().object(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJson().object()}.toJson();
}
