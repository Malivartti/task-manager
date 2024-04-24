#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QJsonDocument>
#include <QJsonObject>

#include "base/service.h"
#include "repository/userrepository.h"
#include "dto/base/response.h"
#include "dto/request/loginrequest.h"
#include "dto/request/registerrequest.h"
#include "dto/response/userresponse.h"

class AuthService : public Service<AuthService>
{
protected:
    AuthService();
    UserRepository* userRepository = (UserRepository*)UserRepository::getInstance();

    friend class Singleton<AuthService>;
public:
    QJsonDocument login(LoginRequest& request);
    QJsonDocument reg(RegisterRequest& request);
};

#endif // AUTHSERVICE_H
