import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Main
import "../../widgets/header"
import "../home"
import "../projects"
import "../account"
import "../project"
import "../settings"

Page {
    id: page
    signal setUser(int userId)

    MainControl {
        id: control
    }

    function setUserId(userId) {
        control.userId = userId
    }

    function getUserData(userId) {
        control.getUserData()
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        spacing: 0

        Header {
            id: header
            Layout.fillWidth: true
            Layout.preferredHeight: 50

            onToHome: {
                mainStackView.replace(homePage)
            }
            onToProjects: {
                mainStackView.replace(projectsPage)
            }
            onToAccount: {
                mainStackView.replace(accountPage)
            }

            onToProject: {
                mainStackView.replace(projectPage)
            }
        }

        StackView {
            id: mainStackView
            initialItem: homePage
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

    HomePage {
        id: homePage
        visible: true
    }

    ProjectsPage {
        id: projectsPage
        visible: false
    }

    AccountPage {
        id: accountPage
        visible: false
    }

    ProjectPage {
        id: projectPage
        visible: false

        onToSettings: {
            mainStackView.replace(settingsPage)
        }
    }

    SettingsPage {
        id: settingsPage
        visible: false

        onToProject: {
            mainStackView.replace(projectPage)
        }
    }

    Component.onCompleted: {
        // page.setUser.connect(setUserId)
        // page.setUser.connect(getUserData)
    }
}
