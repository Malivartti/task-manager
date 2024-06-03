import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import "." as Pages
import "../widget" as Widgets

Rectangle {
    function switchToProfile(project) {
        console.log("Profile", project.id)
        navbar.setBreadCrumbs([project.name])
        profilePage.enable(project)
        coreView.replace(profilePage)
    }

    function switchToBacklog(project) {
        console.log("Backlog", project.id)
        navbar.setBreadCrumbs([project.name, 'Backlog'])
        backlogPage.enable(project)
        coreView.replace(backlogPage)
    }

    function switchToBoard(project) {
        console.log("Board", project.id)
        navbar.setBreadCrumbs([project.name, 'Board'])
        coreView.replace(boardPage)
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Widgets.Navbar {
            id: navbar
            Layout.fillWidth: true
            Layout.preferredHeight: 40
        }

        StackView {
            id: coreView
            initialItem: profilePage
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

    Pages.ProfilePage {
        id: profilePage
        visible: false
    }

    Pages.BacklogPage {
        id: backlogPage
        visible: false
    }

    Pages.BoardPage {
        id: boardPage
        visible: false
    }
}
