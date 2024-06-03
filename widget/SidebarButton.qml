import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: container
    width: 240
    height: 30
    color: "#f7f7f5"

    signal onClicked()

    property alias text: text.text
    property alias leftMargin: text.anchors.leftMargin

    Button {
        id: button
        anchors.centerIn: parent
        width: 220
        height: 30

        background: Rectangle {
            anchors.fill: parent
            radius: 5
            color: button.down ? "#d8d8d6" : (button.hovered ? "#efefed" : container.color)
            border.width: 0

            Text {
                id: text
                color: "#37352f"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 10
                font.pointSize: 10
            }
        }

        onClicked: {
            container.onClicked()
        }
    }
}
