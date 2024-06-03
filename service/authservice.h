#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QCryptographicHash>

#include "base/service.h"
#include "../repository/userrepository.h"
#include "../repository/sessionrepository.h"
#include "../dto/base/response.h"
#include "../dto/request/simplerequest.h"
#include "../dto/request/loginrequest.h"
#include "../dto/request/registerrequest.h"
#include "../dto/response/userresponse.h"

/**
 * @brief The Service for authorization and authentication.
 * @details Provides required functionality for authorization and authentication.
*/
class AuthService : public Service<AuthService>
{
private:
    /**
     * @brief Session expiration time (7 days).
    */
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

    /**
     * @brief The Method for creating Client's sessions.
     * @param descriptor Client's socket descriptor.
     * @param user Client's data.
     * @return true if successful, else false.
    */
    bool createSession(qintptr descriptor, const User& user);

    //Session updateSession(Session session);
public:
    Response getUnauthorizedAccess();
    Response getForbiddenAccess();

    /**
     * @brief The Method for determining whether Client is allowed to perform actions or not.
     * @param descriptor Client's socket descriptor.
     * @return true if allowed, else false.
    */
    bool isAuthorized(qintptr descriptor);

    /**
     * @brief The Method for obtaining Clients' descriptors that are currently on the same project page as the Client.
     * @param descriptor Client's socket descriptor.
     * @return QVector of descriptors.
    */
    QVector<qintptr> getListeningDescriptors(qintptr descriptor);

    /**
     * @brief The Method for authorization.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for signing in.
     * @return Response to the authorization request.
    */
    Response login(qintptr descriptor, const LoginRequest& request);

    /**
     * @brief The Method for registation.
     * @param descriptor Client's socket descriptor.
     * @param request Client's request for signing up.
     * @note If successful, the client is automatically logged in.
     * @return Response to the registation request.
    */
    Response reg(qintptr descriptor, const RegisterRequest& request);

    /**
     * @brief The Method for logging out.
     * @param descriptor Client's socket descriptor.
     * @param request (unnecessary) Client's request for logging out.
     * @return Response to the logout request.
    */
    Response logout(qintptr descriptor, const SimpleRequest& request);
};

#endif // AUTHSERVICE_H
