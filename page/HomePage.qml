import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import HomePage
import MainPage

Rectangle {
    id: homePage

    HomeControl {
        id: homeControl
    }

    MainControl {
        id: projectsControl
    }

    function setUser(user) {
        username.text = user.username + " (" + user.email + ")"
        logoCharacter.text = Array.from(user.username)[0].toUpperCase()
        homeControl.getTasks(user.id)
    }

    function displayProjects(data) {
        console.log("PROJECTS DISPLAYED")
    }

    function displayTasks(data) {
        console.log("TASKS DISPLAYED")
    }

    Component.onCompleted: {
        homeControl.displayTasks.connect(displayTasks)
        projectsControl.displayProjects.connect(displayProjects)
    }

    Rectangle {
        id: banner
        width: parent.width
        height: parent.height * 0.25
        visible: true
        color: "#d8d8d6"
        anchors.left: parent.left
        anchors.top: parent.top
    }

    Rectangle {
        id: logo
        width: 50
        height: 50
        color: "#efefed"
        radius: logo.width * 0.15
        anchors.left: parent.left
        anchors.top: banner.bottom
        anchors.leftMargin: 115
        anchors.topMargin: -25
        Text {
            id: logoCharacter
            width: parent.width
            height: parent.height
            color: "#d8d8d6"
            text: "M"
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 33
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Text {
        id: username
        color: "#55534e"
        text: "Username (email@gmail.com)"
        anchors.left: parent.left
        anchors.top: logo.bottom
        anchors.leftMargin: 100
        anchors.topMargin: 15
        font.pointSize: 33
    }

    Rectangle {
        id: projects
        width: parent.width - 100 * 2
        height: 155
        color: "#ffffff"
        radius: 5
        border.color: "#d8d8d6"
        border.width: 1
        anchors.top: username.bottom
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.topMargin: 15
        Text {
            color: "#55534e"
            text: "Projects"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 15
            anchors.topMargin: 10
            font.weight: 600
            font.pointSize: 12
        }

        Rectangle {
            id: rectangle
            x: 36
            y: 50
            width: 195
            height: 75
            color: "#ffffff"
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true

            radius: 5

            Text {
                id: text2
                x: 8
                y: 4
                color: "#55534e"
                text: "Project Name"
                font.weight: 600
                font.pointSize: 12
            }
            Text {
                id: text3
                x: 8
                y: 29
                color: "#55534e"
                text: "Owner's Username"
                font.pointSize: 9
            }
            Text {
                id: text4
                x: 8
                y: 50
                color: "#55534e"
                text: "My Tasks: 5"
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle5
            x: 247
            y: 50
            width: 195
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            // layer.effect: DropShadowEffect {
            //     id: dropShadow1
            //     color: "#1f000000"
            //     radius: 4
            //     verticalOffset: 0
            //     spread: 0.25
            //     horizontalOffset: 0
            // }
            Text {
                id: text5
                x: 8
                y: 4
                color: "#55534e"
                text: "Project Name"
                font.weight: 600
                font.pointSize: 12
            }

            Text {
                id: text6
                x: 8
                y: 29
                color: "#55534e"
                text: "Owner's Username"
                font.pointSize: 9
            }

            Text {
                id: text7
                x: 8
                y: 50
                color: "#55534e"
                text: "My Tasks: 5"
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle6
            x: 460
            y: 50
            width: 195
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            // layer.effect: DropShadowEffect {
            //     id: dropShadow2
            //     color: "#1f000000"
            //     radius: 4
            //     verticalOffset: 0
            //     spread: 0.25
            //     horizontalOffset: 0
            // }
            Text {
                id: text8
                x: 8
                y: 4
                color: "#55534e"
                text: "Project Name"
                font.weight: 600
                font.pointSize: 12
            }

            Text {
                id: text9
                x: 8
                y: 29
                color: "#55534e"
                text: "Owner's Username"
                font.pointSize: 9
            }

            Text {
                id: text10
                x: 8
                y: 50
                color: "#55534e"
                text: "My Tasks: 5"
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle7
            x: 671
            y: 50
            width: 195
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            // layer.effect: DropShadowEffect {
            //     id: dropShadow3
            //     color: "#1f000000"
            //     radius: 4
            //     verticalOffset: 0
            //     spread: 0.25
            //     horizontalOffset: 0
            // }
            Text {
                id: text11
                x: 8
                y: 4
                color: "#55534e"
                text: "Project Name"
                font.weight: 600
                font.pointSize: 12
            }

            Text {
                id: text12
                x: 8
                y: 29
                color: "#55534e"
                text: "Owner's Username"
                font.pointSize: 9
            }

            Text {
                id: text13
                x: 8
                y: 50
                color: "#55534e"
                text: "My Tasks: 5"
                font.pointSize: 9
            }
        }
    }
    Rectangle {
        id: backlog2
        width: parent.width - 100 * 2
        height: 155
        color: "#ffffff"
        radius: 5
        border.color: "#d8d8d6"
        border.width: 1
        anchors.top: projects.bottom
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.topMargin: 15
        Text {
            color: "#55534e"
            text: "Tasks"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 15
            anchors.topMargin: 10
            font.weight: 600
            font.pointSize: 12
        }

        Rectangle {
            id: rectangle8
            x: 37
            y: 48
            width: 195
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            // layer.effect: DropShadowEffect {
            //     id: dropShadow4
            //     color: "#1f000000"
            //     radius: 4
            //     verticalOffset: 0
            //     spread: 0.25
            //     horizontalOffset: 0
            // }
            Text {
                id: text14
                x: 8
                y: 4
                color: "#55534e"
                text: "Task name"
                font.weight: 600
                font.pointSize: 12
            }

            Text {
                id: text15
                x: 8
                y: 29
                color: "#55534e"
                text: "Project\"s name"
                font.pointSize: 9
            }

            Text {
                id: text16
                x: 129
                y: 9
                color: "#55534e"
                text: "In progress"
                font.pointSize: 9
            }

            Text {
                id: text26
                x: 8
                y: 51
                color: "#55534e"
                text: "7th June, 2024"
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle9
            x: 248
            y: 48
            width: 195
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            // layer.effect: DropShadowEffect {
            //     id: dropShadow5
            //     color: "#1f000000"
            //     radius: 4
            //     verticalOffset: 0
            //     spread: 0.25
            //     horizontalOffset: 0
            // }
            Text {
                id: text17
                x: 8
                y: 4
                color: "#55534e"
                text: "Task name"
                font.weight: 600
                font.pointSize: 12
            }

            Text {
                id: text18
                x: 8
                y: 29
                color: "#55534e"
                text: "Project\"s name"
                font.pointSize: 9
            }

            Text {
                id: text19
                x: 159
                y: 9
                color: "#55534e"
                text: "Done"
                font.pointSize: 9
            }

            Text {
                id: text27
                x: 8
                y: 51
                color: "#55534e"
                text: "7th June, 2024/10th June, 2024"
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle10
            x: 458
            y: 48
            width: 134
            height: 75
            color: "#ffffff"
            radius: 5
            border.color: "#d8d8d6"
            border.width: 1
            layer.enabled: true
            Text {
                id: text20
                color: "#d8d8d6"
                text: "+ New"
                font.weight: 600
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 12
            }
        }
    }
}
