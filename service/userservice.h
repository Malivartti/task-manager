#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "base/service.h"
#include "../repository/userrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/userrequest.h"
#include "../dto/response/userresponse.h"

class UserService : public Service<UserService>
{
protected:
    UserRepository* userRepository = UserRepository::getInstance();
    SessionRepository* sessionRepository = SessionRepository::getInstance();

    UserService();

    friend class Singleton<UserService>;
public:
    Response updateUser(qintptr descriptor, const UserRequest& request);
    Response removeUser(qintptr descriptor, const SimpleRequest& request);
};

#endif // USERSERVICE_H
