import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import BacklogPage

Rectangle {
    id: workspace

    BacklogControl {
        id: control
    }

    function enable(project) {
        projectName.text = project.name
        description.text = project.description
        logoCharacter.text = Array.from(project.name)[0].toUpperCase()
        control.getTasks(project.id)
    }

    function formatNumber(number) {
        if (number < 10) {
            return "0" + number;
        }
        return number
    }
    function formatDate(date) {
        if (date === 0) return "Not specified"
        date = new Date(date * 1000)
        return formatNumber(date.getDate()) + "." + formatNumber(date.getMonth() + 1) + "." + date.getFullYear()
    }

    function appendTask(task) {
        listModel.append({
                id: task.id,
                name: task.name,
                description: task.description,
                project: {
                    id: task.project.id,
                    name: task.project.name,
                    description: task.project.description,
                    owner: {
                        id: task.project.owner.id,
                        email: task.project.owner.email,
                        username: task.project.owner.username
                    },
                    createdAt: task.project.createdAt
                },
                sprint: task.sprint,
                creator: {
                    id: task.creator.id,
                    email: task.creator.email,
                    username: task.creator.username
                },
                startAt: formatDate(task.startAt),
                endAt: formatDate(task.endAt),
                resolvedAt: task.resolvedAt,
                status: task.status,
                performers: task.performers
            }
        )
    }

    function displayTasks(data) {
        listModel.clear()
        for (var i = 0; i < data.length; i++) {
            appendTask(data[i])
        }
    }

    Rectangle {
        id: banner
        width: parent.width
        height: parent.height * 0.25
        color: "#d8d8d6"

        visible: true

        anchors.top: parent.top
        anchors.left: parent.left
    }

    Rectangle {
        id: logo
        width: 50
        height: 50
        radius: logo.width * 0.15
        color: "#efefed"
        Text {
            id: logoCharacter
            width: parent.width
            height: parent.height
            text: "M"
            color: "#d8d8d6"
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 33
        }

        anchors.top: banner.bottom
        anchors.left: parent.left
        anchors.leftMargin: 115
        anchors.topMargin: -25
    }
    Text {
        id: projectName
        height: 0
        text: "Project Name"
        color: "#55534e"
        font.pointSize: 33
        anchors.top: logo.bottom
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.topMargin: 15
    }

    Rectangle {
        id: description
        width: parent.width - 100 * 2
        height: 38
        color: "#ffffff"
        property alias text: descriptionText.text
        Text {
            id: descriptionText
            width: parent.width
            height: parent.height
            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed pharetra dictum erat, ac pharetra diam lobortis sit amet. Sed molestie ut nunc eget viverra. Curabitur mattis euismod elementum. Ut tristique odio in nulla semper, quis lobortis diam sodales."
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            maximumLineCount: 2
            color: "#55534e"
            wrapMode: Text.WordWrap
            font.pointSize: 10
        }
        anchors.top: projectName.bottom
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.topMargin: 65
    }

    Rectangle {
        id: backlog
        width: parent.width - 100 * 2
        height: 175
        color: "#ffffff"

        radius: 5
        border.color: "#d8d8d6"
        border.width: 1

        Text {
            id: backlogText
            text: "Backlog"
            font.weight: 500
            font.pointSize: 12
            color: "#55534e"
            height: 18

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.topMargin: 10
        }

        ListView {
            id: listView
            anchors.fill: parent
            snapMode: ListView.NoSnap
            interactive: false
            anchors.top: backlog.top
            anchors.topMargin: 40

            model: ListModel {
                id: listModel
                // ListElement {
                //     name: "Task 1"
                //     startAt: "7th June, 2024"
                //     endAt: "9th June, 2024"
                //     status: "Not started"
                // }
                // ListElement {
                //     name: "Task 1"
                //     startAt: "7th June, 2024"
                //     endAt: "9th June, 2024"
                //     status: "Not started"
                // }
                // ListElement {
                //     name: "Task 1"
                //     startAt: "7th June, 2024"
                //     endAt: "9th June, 2024"
                //     status: "Not started"
                // }
            }

            delegate: Rectangle {
                id: taskButtonRectangle
                width: parent.width - 40
                anchors.leftMargin: 20

                anchors.left: parent.left
                height: 30
                Button {
                    id: taskButton
                    width: parent.width
                    height: 30

                    background: Rectangle {
                        radius: 5
                        color: taskButton.down ? "#d8d8d6" : (taskButton.hovered ? "#efefed" : backlog.color)
                        Rectangle {
                            id: taskName
                            width: parent.width / 4
                            height: 30
                            color: "transparent"

                            Text {
                                text: name
                                color: "#37352f"
                                //Layout.verticalCenter: parent.verticalCenter
                            }

                            anchors.left: parent.left
                            anchors.leftMargin: 10
                        }

                        Rectangle {
                            id: taskStartAt
                            width: parent.width / 4
                            height: 30
                            color: "transparent"

                            Text {
                                text: startAt
                                color: "#37352f"
                                //Layout.verticalCenter: parent.verticalCenter
                            }

                            anchors.left: taskName.right
                            anchors.leftMargin: 10
                        }

                        Rectangle {
                            id: taskEndAt
                            width: parent.width / 4
                            height: 30
                            color: "transparent"

                            Text {
                                text: endAt
                                color: "#37352f"
                                //Layout.verticalCenter: parent.verticalCenter
                            }

                            anchors.left: taskStartAt.right
                            anchors.leftMargin: 10
                        }

                        Rectangle {
                            id: taskStatus
                            width: parent.width / 4
                            height: 30
                            color: "transparent"

                            Text {
                                text: status
                                color: "#37352f"
                                //Layout.verticalCenter: parent.verticalCenter
                            }

                            anchors.left: taskEndAt.right
                            anchors.leftMargin: 10
                        }
                    }
                }
            }
        }

        anchors.top: description.bottom
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.topMargin: 15
    }

    Component.onCompleted: {
        control.displayTasks.connect(displayTasks)
    }
}

