#include "loginfragment_old.h"
#include <QJsonValue>
#include <QLabel>
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QSettings>

LoginFragment_old::LoginFragment_old() {
    qDebug("SplashFragnebt crete");

    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QFrame *centerConainer = new QFrame;

    QVBoxLayout *startMainLayout = new QVBoxLayout;
    QHBoxLayout *startContent = new QHBoxLayout;

    QVBoxLayout *backContainer = new QVBoxLayout;

    QVBoxLayout *startVerticalContent = new QVBoxLayout;
    QLabel *title = new QLabel("Вход в приложение");
    QLabel *subtitle = new QLabel("Не сообщяйте никому свои данные для авторизации.");
    loginEdit = new QLineEdit;
    passwordEdit = new QLineEdit;

    QVBoxLayout *buttonContainer = new QVBoxLayout;
    QHBoxLayout *loadingButtonContainer = new QHBoxLayout;

    loginButton = new QPushButton("Войти");

    subtitle->setMaximumWidth(335);
    subtitle->setMinimumWidth(335);
    subtitle->setWordWrap(true);
    startVerticalContent->addWidget(title);
    startVerticalContent->addWidget(subtitle);
    startVerticalContent->setAlignment(Qt::AlignTop);
    buttonContainer->setAlignment(Qt::AlignBottom);

    startMainLayout->addLayout(startVerticalContent);
    startMainLayout->addLayout(buttonContainer);

    loginEdit->setMaximumWidth(335);
    loginEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    loginEdit->setPlaceholderText("Логин");
    passwordEdit->setMaximumWidth(335);
    passwordEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    passwordEdit->setPlaceholderText("Пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);

    buttonContainer->addWidget(loginEdit);
    buttonContainer->addWidget(passwordEdit);
    loadingButtonContainer->addWidget(loginButton);
    buttonContainer->addLayout(loadingButtonContainer);

    startContent->setContentsMargins(46,46,46,46);

    centerConainer->setLayout(startContent);
    backContainer->setAlignment(Qt::AlignTop);
    startContent->addLayout(backContainer);
    startContent->addLayout(startMainLayout);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

}
