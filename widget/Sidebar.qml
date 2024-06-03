import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import MainPage

import "." as Widgets

Rectangle {
    id: sidebar
    color: "#f7f7f5"

    property int openedProjectById: -1

    MainControl {
        id: control
    }

    signal toHome()
    signal toProfile(var project)
    signal toBacklog(var project)
    signal toBoard(var project)

    function setUser(user) {
        userButton.text = user.username + "'s Task Manager"
        control.getProjects(user.id)
    }

    function appendProject(project) {
        listModel.append({
            id: project.id,
            name: project.name,
            description: project.description,
            owner: {
                id: project.owner.id,
                email: project.owner.email,
                username: project.owner.username,
            },
            createdAt: project.createdAt
        })
    }

    function displayProjects(data) {
        listModel.clear()
        for (var i = 0; i < data.length; i++) {
            appendProject(data[i])
        }
    }

    ColumnLayout {
        spacing: 0
        anchors.fill: parent

        Widgets.SidebarButton {
            id: userButton
            text: "Unknown"
            Layout.topMargin: 40
        }

        Widgets.SidebarButton {
            id: homeButton
            text: "Home"
            onOnClicked: {
                toHome()
            }
        }

        Widgets.SidebarButton {
            id: inboxButton
            text: "Inbox"
        }

        Text {
            text: "Projects"
            color: "#bdbdbb"
            Layout.topMargin: 20
            Layout.leftMargin: 20
            font.weight: Font.DemiBold
            font.pointSize: 9
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            //Layout.topMargin: 20

            model: ListModel {
                id: listModel
            }
            delegate: Widgets.SidebarProjectButton {
                id: projectButton

                onOpenProject: { openedProjectById = index }
                onCloseProject: { openedProjectById = -1 }
                isOpen: openedProjectById == index

                onToProfile: { sidebar.toProfile(model) }
                onToBacklog: { sidebar.toBacklog(model) }
                onToBoard: { sidebar.toBoard(model) }
            }
        }
    }

    Rectangle {
        width: 1
        height: parent.height
        color: "#f1f1ef"
        anchors.right: sidebar.right
    }

    Component.onCompleted: {
        control.displayProjects.connect(displayProjects)
    }
}
