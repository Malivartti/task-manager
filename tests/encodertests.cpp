#include "encodertests.h"

#define GENERATOR QRandomGenerator::global()->bounded(10000, 200000)

EncoderTests::EncoderTests() {}

void EncoderTests::testString()
{
    QString text = QString::number(GENERATOR);

    auto encodedText = rsa->encode(text.toLocal8Bit(), rsa->getPublicKey());
    auto decodedText = rsa->decode(encodedText, rsa->getPrivateKey());

    QCOMPARE(text, decodedText);
}

void EncoderTests::testJson()
{
    QJsonDocument json{
        QJsonObject{
            {"id", GENERATOR},
            {"name", QString::number(GENERATOR)}
        }
    };

    auto encodedText = rsa->encode(json.toJson(), rsa->getPublicKey());
    auto decodedText = rsa->decode(encodedText, rsa->getPrivateKey());

    QCOMPARE(json, QJsonDocument::fromJson(decodedText));
}
