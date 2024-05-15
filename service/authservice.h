#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

#include "base/service.h"
#include "../repository/userrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/loginrequest.h"
#include "../dto/request/registerrequest.h"
#include "../dto/response/userresponse.h"

class AuthService : public Service<AuthService>
{
private:
    const unsigned int sessionExpiration = 60 * 24 * 7;
    const Response unauthorizedAccess{
        Header{401, "Unauthorized Access"}.toJsonObject(),
        QJsonObject{}
    };
    const Response forbiddenAccess{
        Header{403, "Forbidden Access"}.toJsonObject(),
        QJsonObject{}
    };
protected:
    UserRepository* userRepository = UserRepository::getInstance();
    SessionRepository* sessionRepository = SessionRepository::getInstance();

    AuthService();

    friend class Singleton<AuthService>;

    bool createSession(qintptr descriptor, const User& user);
    //Session updateSession(Session session);
public:
    bool isAuthorized(qintptr descriptor);

    QVector<qintptr> getListeningDescriptors(qintptr descriptor);

    Response getUnauthorizedAccess();
    Response getForbiddenAccess();

    Response login(qintptr descriptor, const LoginRequest& request);
    Response reg(qintptr descriptor, const RegisterRequest& request);
    Response logout(qintptr descriptor, const SimpleRequest& request);
};

#endif // AUTHSERVICE_H
