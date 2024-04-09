import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Authorization

Page {
    id: page
    signal log_in();
    signal toReg();

    AuthorizationControl {
        id: control
    }

    function onCheckFields() {
        if (textField_email.text === "") {
            warning_email.text = "Введите почту"
        }
        if (textField_password.text === "") {
            warning_password.text = "Введите пароль"
        }
    }

    function onAccessIsDenied() {
        warning_text.text = "Неверна почта или пароль"
        textField_password.clear()
    }

    ColumnLayout {
        id: columnLayout
        Layout.maximumWidth: 300
        anchors.centerIn: parent
        spacing: 10

        Rectangle {
            height: 30
            Layout.fillWidth: true
            anchors.bottomMargin: 30

            Text {
                anchors.centerIn: parent
                text: qsTr("Авторизация")
            }
            color: "white"
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
            width: 213

            Label {
                id: label_email
                text: qsTr("Почта")
            }

            TextField {
                id: textField_email
                Layout.fillWidth: true
                placeholderText: qsTr("Введите почту")
                onTextChanged: {
                    control.email = text;
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
            width: 100

            Label {
                id: label_password
                text: qsTr("Пароль")
            }

            TextField {
                id: textField_password
                echoMode: TextInput.Password
                Layout.fillWidth: true
                placeholderText: qsTr("Введите пароль")
                // text: control.password;
                onTextChanged: {
                    control.password = text
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
            text: "Войти"
            onClicked: {
                // page.log_in();
                control.log_in();
            }
            Layout.alignment: Qt.AlignHCenter

        }

        Button {
             text: "Регистрация"
            onClicked: {
                page.toReg();
            }
            Layout.alignment: Qt.AlignHCenter
        }

        Component.onCompleted: {
            control.accessIsAllowed.connect(log_in)
            control.accessIsDenied.connect(onAccessIsDenied)
            control.accessIsDenied.connect(onCheckFields)
        }
}
}
