#include "authservice.h"

static bool isEmail(const QString& login) {
    return login.contains('@');
}

AuthService::AuthService() {}

Session AuthService::createSession(qintptr descriptor, const User& user)
{
    if (!sessionRepository->save(
            Session(
                descriptor,
                user.getId(),
                QDateTime::currentSecsSinceEpoch(),
                QDateTime::currentSecsSinceEpoch() + sessionExpiration,
                NULL
            )
        )
    ) {
        qDebug() << "Failed";
        return {};
    }
    return sessionRepository->getByUserId(user.getId()).last();
}

bool AuthService::isAuthorized(qintptr descriptor)
{
    Session session = sessionRepository->getByDescriptor(descriptor);
    return (session.getId() != 0 && session.getEndAt() > QDateTime::currentSecsSinceEpoch());
}

bool AuthService::isAuthenticated(qintptr descriptor, unsigned int userId)
{
    Session session = sessionRepository->getByDescriptor(descriptor);
    return (userId != 0 && session.getId() == userId && session.getEndAt() > QDateTime::currentSecsSinceEpoch());
}

QVector<qintptr> AuthService::getListeningDescriptors(qintptr descriptor)
{
    return sessionRepository->getListeningDescriptors(descriptor);
}

Response AuthService::getUnauthorizedAccess()
{
    return unauthorizedAccess;
}

Response AuthService::getUnauthenticatedAccess()
{
    return unauthenticatedAccess;
}

Response AuthService::login(qintptr descriptor, const LoginRequest& request)
{
    qDebug() << "AuthService::login()";
    User user;
    if (isEmail(request.login)) { // email
        user = userRepository->getByEmail(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect email"}.toJson().object(),
                UserResponse{}.toJson().object()};
        }
    }
    else { // username
        user = userRepository->getByUsername(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect username"}.toJson().object(),
                UserResponse{}.toJson().object()};
        }
    }

    if (user.getPassword() != request.password) {
        return Response{
            Header{0, "Incorrect password"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    qDebug() << "Logging with Descriptor" << descriptor;
    if (createSession(descriptor, user).getId() == 0) {
        return Response{
            Header{0, "Internal error"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJson().object()};
}

Response AuthService::reg(qintptr descriptor, const RegisterRequest& request) {
    if (userRepository->getByEmail(request.email).getId() != 0) {
        return Response{
            Header{0, "User with this email already exists"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    if (userRepository->getByUsername(request.username).getId() != 0) {
        return Response{
            Header{0, "User with this username already exists"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    if (!userRepository->save(User(request.email, request.username, request.password))) {
        return Response{
            Header{0, "Internal error"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    User user = userRepository->getByEmail(request.email);

    qDebug() << "Registrating with Descriptor" << descriptor;
    if (createSession(descriptor, user).getId() == 0) {
        return Response{
            Header{0, "Internal error"}.toJson().object(),
            UserResponse{}.toJson().object()};
    }

    return Response{
        Header{1, "OK"}.toJson().object(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJson().object()};
}
