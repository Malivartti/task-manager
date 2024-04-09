import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Main
import "../../widgets/header"
import "../home"
import "../projects"
import "../account"

Page {
    id: page
    signal sign_in(string id_user)

    MainControl {
        id: control
    }

    function onSign_in(id_user) {
        control.id_user = id_user
        control.getData()
    }

    ColumnLayout {
        id: columnLayout
        anchors {
            left: parent.left
            right: parent.right
        }

        spacing: 10

        Header {
            id: header

            onToHome: {
                stackView.replace(homePage)
            }
            onToProjects: {
                stackView.replace(projectsPage)
            }
            onToAccount: {
                stackView.replace(accountPage)
            }
        }

        StackView {
            id: stackView
            initialItem: homePage

            pushEnter: Transition {}
            pushExit: Transition {}
            popEnter: Transition {}
            popExit: Transition {}
            replaceEnter: Transition {}
            replaceExit: Transition {}
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
    }

    Component.onCompleted: {
        page.sign_in.connect(onSign_in)
    }
}
