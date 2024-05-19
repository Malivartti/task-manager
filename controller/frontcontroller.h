#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include <QJsonDocument>
#include <QTcpSocket>

#include "../base/baseserver.h"
#include "base/controller.h"
#include "projectcontroller.h"
#include "authcontroller.h"
#include "../service/authservice.h"

/*
 * KEYS:
 *  [1, 10] AUTH
 *  [11, 100] USER
 *  [101, 200] PROJECT
 *      199 IS RESERVED FOR REDIRECT FROM PROJECT
 *      200 IS RESERVED FOR REDIRECT TO PROJECT
 *  [201, 300] TASK
*/

class FrontController : public Controller<FrontController>
{
protected:
    static inline BaseServer* server = nullptr;
    const quint16 START_AUTH = 1;
    const quint16 END_AUTH = 2;
    // QVector<quint16> authKeys;
    // QVector<quint16> publicKeys;
    QVector<quint16> multicastKeys;
    QMap<quint16, std::function<Response(qintptr descriptor, const QJsonDocument&)>> commands;

    AuthService* authService = AuthService::getInstance();

    ProjectController* projectController = ProjectController::getInstance();
    AuthController* authController = AuthController::getInstance();

    FrontController();

    // bool isAuth(quint16 key);
    // bool isPublic(quint16 key);
    bool isMulticast(quint16 key);
    bool isRegistred(quint16 key);
    bool isSuccessful(const QJsonDocument& object);

    friend class Singleton<FrontController>;
public:
    void setServer(BaseServer* server);;
    void mapRequest(qintptr descriptor, quint16 key, const QJsonDocument& object);
};

#endif // FRONTCONTROLLER_H
