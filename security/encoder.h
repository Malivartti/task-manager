#ifndef ENCODER_H
#define ENCODER_H

#include "rsaencryption.h"
#include "aesencryption.h"

template <class T>
class Encoder {
private:
    static inline T* instance = nullptr;
protected:
    Encoder() {}
    Encoder(const Encoder&) = delete;
    Encoder& operator=(const Encoder&) = delete;
    ~Encoder() {};
public:
    static T* getInstance()
    {
        if (!instance) {
            instance = new T();
        }
        return instance;
    }
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

    friend class Encoder<RSAEncoder>;
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
        aes = new QAESEncryption(QAESEncryption::AES_128, QAESEncryption::ECB);
    }

    friend class Encoder<AESEncoder>;
public:
    ~AESEncoder() { delete aes; }

    QByteArray encode(const QByteArray& message, const QByteArray& key) { return aes->encode(message, key); }
    QByteArray decode(const QByteArray& message, const QByteArray& key) { return aes->decode(message, key); }
};

#endif // ENCODER_H
