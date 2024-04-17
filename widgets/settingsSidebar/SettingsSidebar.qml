import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: page
    signal toProject()
    signal toDetails()
    signal toAccess()
    signal toTaskTypes()
    color: 'white'

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Button {
            text: "К проекту"
            Layout.topMargin: 10
            onClicked: {
                page.toProject()
            }
        }

        Button {
            text: "Сведения"
            onClicked: {
                page.toDetails()
            }
        }

        Button {
            text: "Доступ"
            onClicked: {
                page.toAccess()
            }
        }

        Button {
            text: "Типы задач"
            onClicked: {
                page.toTaskTypes()
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
