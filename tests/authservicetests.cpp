#include "authservicetests.h"

#define GENERATOR QRandomGenerator::global()->bounded(10000, 200000)

AuthServiceTests::AuthServiceTests() {}

void AuthServiceTests::login()
{
    qintptr descriptor = GENERATOR;
    LoginRequest request("MDxR", "12345");

    QCOMPARE(authService->login(descriptor, request).head["code"].toInt(), 1);
    QCOMPARE(authService->isAuthorized(descriptor), 1);
    QCOMPARE(authService->logout(descriptor, {}).head["code"].toInt(), 1);
}

void AuthServiceTests::reg()
{
    qintptr descriptor1 = GENERATOR;

    quint32 name = GENERATOR;

    RegisterRequest request(QString::number(name) + "@gmail.com" , QString::number(name), "12345");

    QCOMPARE(authService->reg(descriptor1, request).head["code"].toInt(), 1);
    QCOMPARE(authService->isAuthorized(descriptor1), 1);
    QCOMPARE(authService->logout(descriptor1, {}).head["code"].toInt(), 1);

    qintptr descriptor2 = GENERATOR;

    QCOMPARE(authService->reg(descriptor2, request).head["code"].toInt(), 0);
    QCOMPARE(authService->isAuthorized(descriptor2), 0);
}

void AuthServiceTests::logout()
{
    qintptr descriptor = GENERATOR;
    QCOMPARE(authService->logout(descriptor, {}).head["code"].toInt(), 1);
}
