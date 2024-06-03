#include "userservice.h"

UserService::UserService() {}

Response UserService::updateUser(qintptr descriptor, const UserRequest &request)
{
    if (sessionRepository->getByDescriptor(descriptor).getUserId() != request.userId) {
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(request.userId);
    if (user.getId() == 0) {
        return Response{Header{0, "User does not exist"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    if (user.getEmail() != request.email) {
        if (userRepository->getByEmail(request.email).getId() != 0) {
            return Response{Header{0, "User already exists"}.toJsonObject(), UserResponse{}.toJsonObject()};
        }
    }

    if (user.getUsername() != request.username) {
        if (userRepository->getByUsername(request.username).getId() != 0) {
            return Response{Header{0, "User already exists"}.toJsonObject(), UserResponse{}.toJsonObject()};
        }
    }

    user = userRepository->save(User(request.userId, request.email, request.username, request.password));
    if (user.getId() == 0) {
        return Response{Header{0, "Internal error"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        UserResponse{
            user.getId(),
            user.getEmail(),
            user.getUsername()
        }.toJsonObject()
    };
}

Response UserService::removeUser(qintptr descriptor, const SimpleRequest &request)
{
    if (sessionRepository->getByDescriptor(descriptor).getUserId() != request.id) {
        return Response{Header{0, "Access to perform this action has been denied"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    User user = userRepository->getById(request.id);
    if (user.getId() == 0) {
        return Response{Header{0, "User does not exist"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    if (!userRepository->remove(user)) {
        return Response{Header{0, "Internal error"}.toJsonObject(), UserResponse{}.toJsonObject()};
    }

    return Response{
        Header{1, "OK"}.toJsonObject(),
        UserResponse{}.toJsonObject()
    };
}
