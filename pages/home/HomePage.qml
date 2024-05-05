import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Home
import "../../widgets/homeTask"

Page {
    id: page

    HomeControl {
        id: control
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Text {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: "Назначенные мне задачи"
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            HomeTask {
                Layout.fillWidth: true
                taskNameText: "Задача 1"
                projectNameText: "Проект 1"

                onClicked: {
                    control.getData()
                }
            }

            HomeTask {
                Layout.fillWidth: true
                taskNameText: "Задача 2"
                projectNameText: "Проект 1"

                onClicked: {
                    console.log("click 2")
                }
            }

            HomeTask {
                Layout.fillWidth: true
                taskNameText: "Задача 3"
                projectNameText: "Проект 1"

                onClicked: {
                    console.log("click 3")
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
