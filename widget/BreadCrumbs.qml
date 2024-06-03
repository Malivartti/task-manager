import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {


    function displayBreadCrumbs(arr) {
        listModel.clear()
        arr.forEach(crumb => listModel.append({ crumb }))
    }

    ListView {
        id: list
        anchors.fill: parent
        orientation: Qt.Horizontal
        snapMode: ListView.NoSnap
        interactive: false
        spacing: 5

        model: ListModel {
            id: listModel
        }

        delegate: Rectangle {
            width: text.contentWidth
            height: text.contentHeight

            Row {
                spacing: 5

                Text {
                    text: "/"
                    color: "#37352f"
                    font.pointSize: 10
                    anchors.verticalCenter: parent.verticalCentera
                    visible: index != 0
                }

                Text {
                    id: text
                    color: "#37352f"
                    font.pointSize: 10
                    text: crumb
                }
            }
        }

    }
}
