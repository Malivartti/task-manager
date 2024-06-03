#ifndef ENCODER_H
#define ENCODER_H

#include "../base/singleton.h"
#include "rsaencryption.h"
#include "aesencryption.h"

template <class T>
class Encoder : public Singleton<T> {
protected:
    Encoder() {}
};

class RSAEncoder : public Encoder<RSAEncoder>
{
private:
    QRSAEncryption* rsa;
    QByteArray publicKey, privateKey;

protected:
    RSAEncoder() {
        rsa = new QRSAEncryption(QRSAEncryption::Rsa::RSA_128);
        rsa->generatePairKey(publicKey, privateKey);
    }

    friend class Singleton<RSAEncoder>;
public:
    ~RSAEncoder() { delete rsa; }

    QByteArray& getPublicKey() { return publicKey; };
    QByteArray& getPrivateKey() { return privateKey; };

    QByteArray encode(const QByteArray& message, const QByteArray& key) { return rsa->encode(message, key); }
    QByteArray decode(const QByteArray& message, const QByteArray& key) { return rsa->decode(message, key); }
};

class AESEncoder : public Encoder<AESEncoder>
{
private:
    static inline QAESEncryption* aes;

protected:
    AESEncoder() {
        aes = new QAESEncryption(QAESEncryption::AES_128, QAESEncryption::CFB);
    }

    friend class Singleton<AESEncoder>;
public:
    ~AESEncoder() { delete aes; }

    QByteArray encode(const QByteArray& message, const QByteArray& key) { return aes->encode(message, key); }
    QByteArray decode(const QByteArray& message, const QByteArray& key) { return aes->decode(message, key); }
};

#endif // ENCODER_H
