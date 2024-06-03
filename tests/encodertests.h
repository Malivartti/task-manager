#ifndef ENCODERTESTS_H
#define ENCODERTESTS_H

#include <QTest>
#include <QRandomGenerator>
#include <QJsonDocument>
#include <QJsonObject>

#include "../security/encoder.h"

class EncoderTests : public QObject
{
    Q_OBJECT
private:
    RSAEncoder* rsa = RSAEncoder::getInstance();
public:
    EncoderTests();

private slots:
    void testString();
    void testJson();
};

#endif // ENCODERTESTS_H
