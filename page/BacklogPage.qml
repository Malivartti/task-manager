import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import BacklogPage
import "../widget" as Widgets

Rectangle {
    id: backlog

    BacklogControl {
        id: control
    }

    function enable(project) {
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

    // property bool isOpenPopup: false




    // Rectangle {
    //     visible: isOpenPopup
    //     anchors.fill: parent
    //     z: 10

    //     opacity: 0.1

    //     MouseArea {
    //         anchors.fill: parent
    //         onClicked: isOpenPopup = false
    //     }

    //     Rectangle {
    //         width: 400
    //         height: 240
    //         anchors.verticalCenter: parent.verticalCenter
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         color: "red"

    //         MouseArea {
    //             anchors.fill: parent
    //         }
    //     }
    // }



    Rectangle {
        anchors.fill: parent
        anchors.margins: 50


        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            Button {
                id: button
                Layout.preferredWidth: 100
                Layout.preferredHeight: 30
                Layout.bottomMargin: 20

                background: Rectangle {
                    anchors.fill: parent
                    radius: 5
                    color: button.down ? "#d8d8d6" : (button.hovered ? "#efefed" : "#fff")
                    border.width: 0

                    Text {
                        id: text
                        color: "#37352f"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pointSize: 10
                        text: "Add Task"
                    }
                }

                onClicked: {
                    // isOpenPopup = true
                    // popup.open()
                }
            }

            ListView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                snapMode: ListView.NoSnap
                interactive: false

                model: ListModel {
                    id: listModel
                }

                delegate: Rectangle {
                    id: taskButtonRectangle
                    width: parent.width
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


        }
    }



    Component.onCompleted: {
        control.displayTasks.connect(displayTasks)
    }
}
