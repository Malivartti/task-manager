#include "authservice.h"

#define GENERATE_HASH(string) QString(QCryptographicHash::hash(string.toLocal8Bit(), QCryptographicHash::Algorithm::Sha256))

static bool isEmail(const QString& login) {
    return login.contains('@');
}

AuthService::AuthService() {}

bool AuthService::createSession(qintptr descriptor, const User& user)
{
    if (!sessionRepository->insert(
            Session(
                descriptor,
                user.getId(),
                QDateTime::currentSecsSinceEpoch(),
                QDateTime::currentSecsSinceEpoch() + sessionExpiration,
                NULL
            )
        )
    ) {
        qDebug() << "Failed to create session";
        return false;
    }
    return true;
}

bool AuthService::isAuthorized(qintptr descriptor)
{
    Session session = sessionRepository->getByDescriptor(descriptor);
    return (session.getId() != 0 && session.getEndAt() > QDateTime::currentSecsSinceEpoch());
}

QVector<qintptr> AuthService::getListeningDescriptors(qintptr descriptor)
{
    return sessionRepository->getListeningDescriptors(descriptor);
}

Response AuthService::getUnauthorizedAccess()
{
    return unauthorizedAccess;
}

Response AuthService::getForbiddenAccess()
{
    return unauthorizedAccess;
}

Response AuthService::login(qintptr descriptor, const LoginRequest& request)
{
    qDebug() << "AuthService::login()";
    User user;
    if (isEmail(request.login)) { // email
        user = userRepository->getByEmail(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect email"}.toJsonObject(),
                UserResponse{}.toJsonObject()};
        }
    }
    else { // username
        user = userRepository->getByUsername(request.login);
        if (user.getId() == 0) {
            return Response{
                Header{0, "Incorrect username"}.toJsonObject(),
                UserResponse{}.toJsonObject()};
        }
    }

    // Убрать GENERATE_HASH или перевести пароли в хэш
    if (!(user.getPassword() == request.password || user.getPassword() == GENERATE_HASH(request.password))) {
        return Response{
            Header{0, "Incorrect password"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    qDebug() << "Logging with Descriptor" << descriptor;
    if (!createSession(descriptor, user)) {
        return Response{
            Header{0, "Internal error"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJsonObject()};
}

Response AuthService::reg(qintptr descriptor, const RegisterRequest& request) {
    if (userRepository->getByEmail(request.email).getId() != 0) {
        return Response{
            Header{0, "User with this email already exists"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    if (userRepository->getByUsername(request.username).getId() != 0) {
        return Response{
            Header{0, "User with this username already exists"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    User user = userRepository->save(User(request.email, request.username, GENERATE_HASH(request.password)));
    if (user.getId() == 0) {
        return Response{
            Header{0, "Internal error"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    qDebug() << "Registrating with Descriptor" << descriptor;
    if (!createSession(descriptor, user)) {
        return Response{
            Header{0, "Internal error"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJsonObject()};
}

Response AuthService::logout(qintptr descriptor, const SimpleRequest &request)
{
    qDebug() << "AuthService::logout()";
    if (!sessionRepository->removeByDescriptor(descriptor)) {
        return Response{
            Header{0, "Internal error"}.toJsonObject(),
            UserResponse{}.toJsonObject()};
    }
    return Response{
        Header{1, "OK"}.toJsonObject(),
        UserResponse{}.toJsonObject()};
}
