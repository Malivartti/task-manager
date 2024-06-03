import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import "." as Widgets

Rectangle {
    id: navbar
    color: "#fff"

    signal setBreadCrumbs(var arr);

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 10
            spacing: 0

            Widgets.BreadCrumbs {
                id: breadCrumbs
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "#f7f7f5"
        }
    }

    Component.onCompleted: {
        navbar.setBreadCrumbs.connect(breadCrumbs.displayBreadCrumbs)
    }
}
