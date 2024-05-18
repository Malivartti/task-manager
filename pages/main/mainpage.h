#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <QDebug>

#include "controller.h"
#include "dto/simplerequest.h"

class MainPage : public QObject
{
    Q_OBJECT
public:
    MainPage(QObject* parent = nullptr) {}
    Q_INVOKABLE void getUserData();
    Q_PROPERTY(unsigned int userId READ getUserId WRITE setUserId);

    unsigned int getUserId() const;
    void setUserId(const unsigned int);

private:
    unsigned int userId = 0;
    static inline Controller* controller = Controller::getInstance();
    static inline Handler* handler = Handler::getInstance();
};

#endif // MAINPAGE_H
