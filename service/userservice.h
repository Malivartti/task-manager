#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "base/service.h"
#include "../repository/userrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/userrequest.h"
#include "../dto/response/userresponse.h"

/**
 * @brief The Service for users.
 * @details Provides required functionality for manipulating users.
*/
class UserService : public Service<UserService>
{
protected:
    UserRepository* userRepository = UserRepository::getInstance();
    SessionRepository* sessionRepository = SessionRepository::getInstance();

    UserService();

    friend class Singleton<UserService>;
public:
    /**
     * @brief The Method for posting (creating) user.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for creating user.
     * @return Response to the post request.
    */
    Response postUser(qintptr descriptor, const UserRequest& request);

    /**
     * @brief The Method for updating user.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for updating user.
     * @return Response to the update request.
    */
    Response updateUser(qintptr descriptor, const UserRequest& request);

    /**
     * @brief The Method for deleting user.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for deleting user.
     * @return Response to the delete request.
    */
    Response removeUser(qintptr descriptor, const SimpleRequest& request);
};

#endif // USERSERVICE_H
