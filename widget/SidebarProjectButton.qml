import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import "." as Widgets

Rectangle {
    property bool isOpen: false

    signal toProfile()
    signal toBacklog()
    signal toBoard()

    function onSomething() {console.log("clicked")}

    id: container
    width: 240
    height: 30 + isOpen * 3 * 30
    color: "#f7f7f5"

    ColumnLayout {
        spacing: 0
        anchors.fill: parent

        Button {
            id: projectButton
            Layout.preferredWidth: 240 - 20
            Layout.preferredHeight: 30
            Layout.alignment: Qt.AlignHCenter

            background: Rectangle {
                anchors.fill: parent
                radius: 5
                color: projectButton.down ? "#d8d8d6" : projectButton.hovered ? "#efefed" : container.color
                border.width: 0

                Text {
                    text: name
                    color: "#37352f"
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    font.pointSize: 10
                }
            }

            onClicked: {
                isOpen = !isOpen
            }
        }

        Widgets.SidebarButton {
            id: mainProjectButton
            visible: isOpen
            text: "Main"
            leftMargin: 20

            onOnClicked: { container.toProfile() }
        }

        Widgets.SidebarButton {
            id: backlogProjectButton
            visible: isOpen
            text: "Backlog"
            leftMargin: 20

            onOnClicked: { container.toBacklog() }
        }

        Widgets.SidebarButton {
            id: boardProjectButton
            visible: isOpen
            text: "Board"
            leftMargin: 20

            onOnClicked: { container.toBoard() }
        }
    }
}
