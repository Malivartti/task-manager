#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QJsonDocument>

class Handler : public QObject
{
    Q_OBJECT
private:
    static inline Handler* instance = nullptr;
protected:
    Handler();
public:
    static Handler* getInstance();
    void mapRequest(quint16 key, const QJsonDocument& object);
signals:
    void login(const QJsonDocument& object);
    void reg(const QJsonDocument& object);
};

#endif // HANDLER_H

// [1, 2, 3]
