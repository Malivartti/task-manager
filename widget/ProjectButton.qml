import QtQuick 2.15

Rectangle {
    id: container
    width: 195
    height: 75
    color: "#ffffff"
    border.color: "#d8d8d6"
    border.width: 1
    layer.enabled: true
    // layer.effect: DropShadowEffect {
    //     id: dropShadow
    //     color: "#1f000000"
    //     radius: 4
    //     spread: 0.25
    //     verticalOffset: 0
    //     horizontalOffset: 0
    // }
    radius: 5

    Text {
        id: name
        x: 8
        y: 4
        color: "#55534e"
        text: projectName
        font.weight: 600
        font.pointSize: 12
    }
    Text {
        id: username
        x: 8
        y: 29
        color: "#55534e"
        text: ownerUsername
        font.pointSize: 9
    }
    Text {
        id: placeholder
        x: 8
        y: 50
        color: "#55534e"
        text: "Placeholder"
        font.pointSize: 9
    }
}
