import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Main
import "../../widgets/projectSidebar"
import "../backlog"
import "../board"
import "../tasks"
import "../settings"

Page {
    id: page
    signal toSettings()

    Rectangle {
        anchors.fill: parent;
        color: "pink"
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent
        spacing: 0

        ProjectSidebar {
            id: projectSidebar
            Layout.preferredWidth: 125
            Layout.fillHeight: true

            onToBacklog: {
                projectStackView.replace(backlogPage)
            }

            onToBoard: {
                projectStackView.replace(boardPage)
            }

            onToTasks: {
                projectStackView.replace(tasksPage)
            }

            onToSettings: {
                page.toSettings()
            }
        }

        StackView {
            id: projectStackView
            initialItem: backlogPage
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

    BacklogPage {
        id: backlogPage
        visible: true
    }

    BoardPage {
        id: boardPage
        visible: false
    }

    TasksPage {
        id: tasksPage
        visible: false
    }
}
