#include "basepage.h"

BasePage::BasePage()
{
    if (handler == nullptr) handler = Handler::getInstance();
    if (controller == nullptr) controller = Controller::getInstance();
    handler->addPage(this);
}

unsigned int BasePage::getUserId() const {
    return userId;
}

// Запретить назначение userId на всех страницах, кроме MainPage (добавить реализацию этого метода только в MainPage)
void BasePage::setUserId(const unsigned int id) {
    qDebug() << "User ID:" << userId << id;
    if (id != userId) {
        userId = id;
        emit userIdChanged();
        //controller->sendToServer(104, SimpleRequest(userId).toJson());
    }
}
