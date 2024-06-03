import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import AuthPage

Rectangle {
    id: page
    color: "#fff"
    signal toMain(var user)

    AuthControl {
        id: control
    }

    function onCheckFields() {
        if (emailField.text === "") {
            warning_email.text = "Введите логин"
        }
        if (passwordField.text === "") {
            warning_password.text = "Введите пароль"
        }
    }

    function onAccessIsDenied() {
        warning_text.text = "Неверна почта или пароль"
        passwordField.clear()
    }

    ColumnLayout {
        id: columnLayout
        Layout.maximumWidth: 300
        anchors.centerIn: parent
        spacing: 0

        Rectangle {
            Layout.preferredHeight: 30
            Layout.fillWidth: true
            anchors.bottomMargin: 30
            color: "white"

            Text {
                anchors.centerIn: parent
                text: qsTr("Авторизация")
            }
        }

        Text {
            id: warning_text
            color: "red"
            Layout.alignment: Qt.AlignHCenter
        }

        ColumnLayout {
            id: email
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            Layout.preferredWidth: 213
            spacing: 0

            Label {
                id: label_email
                text: qsTr("Почта")
            }

            TextField {
                id: emailField
                Layout.fillWidth: true
                placeholderText: qsTr("Введите почту")
                onTextChanged: {
                    if (warning_email.text !== "") {
                        warning_email.text = ""
                    }
                }
            }

            Text {
                id: warning_email
                font.pixelSize: 12
                color: "red"
            }
        }

        ColumnLayout {
            id: password
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            Layout.preferredWidth: 100
            spacing: 0

            Label {
                id: label_password
                text: qsTr("Пароль")
            }

            TextField {
                id: passwordField
                echoMode: TextInput.Password
                Layout.fillWidth: true
                placeholderText: qsTr("Введите пароль")
                // text: control.password;
                onTextChanged: {
                    if (warning_password.text !== "") {
                        warning_password.text = ""
                    }
                }
            }

            Text {
                id: warning_password
                font.pixelSize: 12
                color: "red"
            }
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Войти"
            onClicked: {
                control.sendLoginRequest(emailField.text, passwordField.text)
            }

        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Регистрация"
            onClicked: {
                page.toRegistrationPage()
            }
        }

        Component.onCompleted: {
            control.accessIsAllowed.connect(toMain)
            control.accessIsDenied.connect(onAccessIsDenied)
            control.accessIsDenied.connect(onCheckFields)
        }
    }
}
