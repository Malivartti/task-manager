#include "mainpage.h"
#include <iostream>

unsigned int MainPage::getUserId() const {
    return userId;
}

void MainPage::setUserId(const unsigned int id) {
    qDebug() << "User ID:" << userId << id;
    if (id != userId) {
        userId = id;
        // controller->sendToServer(104, SimpleRequest(userId).toJson());
    }
}

void MainPage::getUserData()
{
    // controller->sendToServer(104, SimpleRequest(userId).toJson());
}
