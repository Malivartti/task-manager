#include "mainpage.h"
#include <iostream>

QString MainPage::id_user() const {
    return m_id_user;
}
void MainPage::setId_user(const QString& text) {
    if (text != m_id_user) {
        m_id_user = text;
        emit id_userChanged(text);
    }
}

void MainPage::getData() {
    std::cout << m_id_user.toStdString() << std::endl;
}
