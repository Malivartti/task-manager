#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

#include "base/service.h"
#include "repository/userrepository.h"
#include "repository/sessionrepository.h"
#include "dto/base/response.h"
#include "dto/request/loginrequest.h"
#include "dto/request/registerrequest.h"
#include "dto/response/userresponse.h"

class AuthService : public Service<AuthService>
{
private:
    const unsigned int sessionExpiration = 60 * 24 * 7;
    const Response unauthorizedAccess{
        Header{401, "Unauthorized Access"}.toJson().object(),
        QJsonObject{}
    };
    const Response unauthenticatedAccess{
        Header{403, "Unauthenticated Access"}.toJson().object(),
        QJsonObject{}
    };
protected:
    UserRepository* userRepository = (UserRepository*)UserRepository::getInstance();
    SessionRepository* sessionRepository = (SessionRepository*)SessionRepository::getInstance();

    AuthService();

    friend class Singleton<AuthService>;

    Session createSession(qintptr descriptor, const User& user);
    //Session updateSession(Session session);
public:
    bool isAuthorized(qintptr descriptor);
    bool isAuthenticated(qintptr descriptor, unsigned int userId);

    QVector<qintptr> getListeningDescriptors(qintptr descriptor);

    Response getUnauthorizedAccess();
    Response getUnauthenticatedAccess();

    Response login(qintptr descriptor, const LoginRequest& request);
    Response reg(qintptr descriptor, const RegisterRequest& request);
};

#endif // AUTHSERVICE_H
