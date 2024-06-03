#ifndef AUTHSERVICETESTS_H
#define AUTHSERVICETESTS_H

#include <QTest>
#include <QRandomGenerator>

#include "../service/authservice.h"

class AuthServiceTests : public QObject
{
    Q_OBJECT
private:
    AuthService* authService = AuthService::getInstance();
public:
    AuthServiceTests();

private slots:
    void login();
    void reg();
    void logout();
};

#endif // AUTHSERVICETESTS_H
