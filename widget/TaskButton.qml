import QtQuick 2.15

Rectangle {
    id: container
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
        id: name
        x: 8
        y: 4
        color: "#55534e"
        text: taskName
        font.weight: 600
        font.pointSize: 12
    }

    Text {
        id: project
        x: 8
        y: 29
        color: "#55534e"
        text: projectName
        font.pointSize: 9
    }

    Text {
        id: status
        x: 129
        y: 9
        color: "#55534e"
        text: taskStatus
        font.pointSize: 9
    }

    Text {
        id: startEndDate
        x: 8
        y: 51
        color: "#55534e"
        text: startDate == "Not specified" ? "" : (endDate == "Not specified" ? startDate : startDate + "/" + endDate)
        font.pointSize: 9
    }
}

