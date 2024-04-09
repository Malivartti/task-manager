#include "authorizationpage.h"

void AuthorizationPage::log_in() {
    if (m_email == "user@mail.com" && m_password == "123") {
        emit accessIsAllowed("id_user");
    } else {
        emit accessIsDenied();
    }
}

QString AuthorizationPage::email() const {
    return m_email;
}
void AuthorizationPage::setEmail(const QString& text) {
    if (text != m_email) {
        m_email = text;
        emit emailChanged(text);
    }
}

QString AuthorizationPage::password() const {
    return m_password;
}
void AuthorizationPage::setPassword(const QString& text) {
    if (text != m_password) {
        m_password = text;
        emit passwordChanged(text);
    }
}
