import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: item
    property alias taskNameText: taskName.text
    property alias projectNameText: projectName.text

    contentItem:
        Rectangle {
            RowLayout {
                anchors.fill: parent
                spacing: 0

                Text {
                    id: taskName
                    Layout.rightMargin: 10
                }

                Text {
                    id: projectName
                    color: "#626F86"
                }

                Item {
                    Layout.fillWidth: true
                }
            }
        }
}
