#include "handler.h"

Handler::Handler() {}

Handler *Handler::getInstance()
{
    if (!instance) {
        instance = new Handler();
    }
    return instance;
}

void Handler::addPage(BasePage *page)
{
    buffer.insert(page);
}

void Handler::removePage(BasePage *page)
{
    buffer.remove(page);
}

void Handler::mapRequest(quint16 key, const QJsonDocument &object)
{
    for (BasePage* page : buffer) page->notify(key, object);
}
