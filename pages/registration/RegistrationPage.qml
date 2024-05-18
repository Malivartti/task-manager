import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Registration

Page {
    id: page
    signal toMainPage(int userId)
    signal toAuthorizationPage()

    RegistrationControl {
        id: control
    }

    function onCheckFields() {
        if (textField_nikname.text === "") {
            warning_nikname.text = "Введите никнейм"
        }

        if (textField_email.text === "") {
            warning_email.text = "Введите почту"
        }
        if (textField_password.text === "") {
            warning_password.text = "Введите пароль"
        }
    }

    function onAccessIsDenied() {
        warning_text.text = "Данная почта занята"
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

            Text {
                anchors.centerIn: parent
                text: qsTr("Регистрация")
            }
            color: "white"
        }

        Text {
            id: warning_text
            color: "red"
            Layout.alignment: Qt.AlignHCenter
        }

        ColumnLayout {
            id: nikname
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            width: 213
            spacing: 0

            Label {
                id: label_nikname
                text: qsTr("Никнейм")
            }

            TextField {
                id: textField_nikname
                Layout.fillWidth: true
                placeholderText: qsTr("Введите никнейм")
                onTextChanged: {
                    control.nikname = text;
                    if (warning_nikname.text !== "") {
                        warning_nikname.text = ""
                    }
                }
            }

            Text {
                id: warning_nikname
                font.pixelSize: 12
                color: "red"
            }
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
            Layout.preferredWidth: 100
            spacing: 0

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
            text: "Зарегистрироваться"
            onClicked: {
                control.sendSignUpRequest();
            }
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Войти"
            onClicked: {
                page.toAuthorizationPage();
            }
            Layout.alignment: Qt.AlignHCenter
        }

        Component.onCompleted: {
            control.accessIsAllowed.connect(toMainPage)
            control.accessIsDenied.connect(onAccessIsDenied)
            control.accessIsDenied.connect(onCheckFields)
        }
    }
}
