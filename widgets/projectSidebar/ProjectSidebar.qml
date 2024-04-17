import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: page
    signal toBacklog()
    signal toBoard()
    signal toTasks()
    signal toSettings()
    color: 'white'

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Button {
            text: "Беклог"
            Layout.topMargin: 10
            onClicked: {
                page.toBacklog()
            }
        }

        Button {
            text: "Доска"
            onClicked: {
                page.toBoard()
            }
        }

        Button {
            text: "Задачи"
            onClicked: {
                page.toTasks()
            }
        }

        Button {
            text: "Настройки"
            onClicked: {
                page.toSettings()
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
