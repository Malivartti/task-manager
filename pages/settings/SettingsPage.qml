import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Main
import "../../widgets/settingsSidebar"
import "../../widgets/projectSidebar"
import "../datails"
import "../access"
import "../taskTypes"

Page {
    id: page
    signal toProject()

    Rectangle {
        anchors.fill: parent;
        color: "pink"
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent
        spacing: 0

        SettingsSidebar {
            id: settingsSidebar
            Layout.preferredWidth: 125
            Layout.fillHeight: true

            onToProject: {
                page.toProject()
            }

            onToDetails: {
                settingsStackView.replace(detailsPage)
            }

            onToAccess: {
                settingsStackView.replace(accessPage)
            }

            onToTaskTypes: {
                settingsStackView.replace(taskTypesPage)
            }
        }

        StackView {
            id: settingsStackView
            initialItem: detailsPage
            Layout.fillWidth: true
            Layout.fillHeight: true

            pushEnter: Transition {}
            pushExit: Transition {}
            popEnter: Transition {}
            popExit: Transition {}
            replaceEnter: Transition {}
            replaceExit: Transition {}
        }
    }

    DetailsPage {
        id: detailsPage
        visible: true
    }

    AccessPage {
        id: accessPage
        visible: false
    }

    TaskTypesPage {
        id: taskTypesPage
        visible: false
    }
}
