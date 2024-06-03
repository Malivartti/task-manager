import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import MainPage

import "../widget" as Widgets
import "." as Pages

Rectangle {
    MainControl {
        id: control
    }

    function enable(user) {
        control.userId = user.id
        sidebar.setUser(user)
        homePage.setUser(user)
    }

    function toHome() {
        mainView.replace(homePage)
    }

    function toProfile(project) {
        corePage.switchToProfile(project)
        mainView.replace(corePage)
    }

    function toBacklog(project) {
        corePage.switchToBacklog(project)
        mainView.replace(corePage)
    }

    function toBoard(project) {
        corePage.switchToBoard(project)
        mainView.replace(corePage)
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Widgets.Sidebar {
            id: sidebar
            Layout.preferredWidth: 240
            Layout.fillHeight: true
        }

        StackView {
            id: mainView
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


        Pages.HomePage {
            id: homePage
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Pages.CorePage {
            id: corePage
            visible: false
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

    Component.onCompleted: {
        sidebar.toHome.connect(toHome)
        sidebar.toProfile.connect(toProfile)
        sidebar.toBacklog.connect(toBacklog)
        sidebar.toBoard.connect(toBoard)
    }
}
