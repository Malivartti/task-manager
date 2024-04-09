#include "registrationpage.h"

void RegistrationPage::sign_in() {
    if (m_email != "user@mail.com" && m_password != "123") {
        emit accessIsAllowed("id_user=0");
    } else {
        emit accessIsDenied();
    }
}

QString RegistrationPage::nikname() const {
    return m_nikname;
}
void RegistrationPage::setNikname(const QString& text) {
    if (text != m_nikname) {
        m_nikname = text;
        emit niknameChanged(text);
    }
}

QString RegistrationPage::email() const {
    return m_email;
}
void RegistrationPage::setEmail(const QString& text) {
    if (text != m_email) {
        m_email = text;
        emit emailChanged(text);
    }
}

QString RegistrationPage::password() const {
    return m_password;
}
void RegistrationPage::setPassword(const QString& text) {
    if (text != m_password) {
        m_password = text;
        emit passwordChanged(text);
    }
}
