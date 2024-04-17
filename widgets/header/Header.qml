import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: page
    signal toHome()
    signal toProjects()
    signal toAccount()
    signal toProject()
    color: "white"

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Button {
            text: "Главная"
            onClicked: {
                page.toHome()
            }
        }

        Button {
            text: "Проекты"
            onClicked: {
                page.toProjects()
            }
        }

        Button {
            text: "Аккаунт"
            onClicked: {
                page.toAccount()
            }
        }

        Button {
            text: "Проект"
            onClicked: {
                page.toProject()
            }
        }
        Item {
            Layout.fillWidth: true
        }
    }
}
