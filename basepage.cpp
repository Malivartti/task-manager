#include "basepage.h"

BasePage::BasePage()
{
    if (handler == nullptr) handler = Handler::getInstance();
    if (controller == nullptr) controller = Controller::getInstance();
}
