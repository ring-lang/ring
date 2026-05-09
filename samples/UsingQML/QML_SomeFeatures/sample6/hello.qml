import QtQuick 2.0

Item {
    id: container
    width: 320
    height: 120

    Rectangle {
        id: rect
        color: "red"
        width: 120
        height: 120

        MouseArea {
            anchors.fill: parent
            onClicked: container.state == 'other' ? container.state = '' : container.state = 'other'
        }
    }
    states: [
        // This adds a second state to the container where the rectangle is farther to the right

        State { name: "other"

            PropertyChanges {
                target: rect
                x: 200
            }
        }
    ]
    transitions: [
        // This adds a transition that defaults to applying to all state changes

        Transition {

            // This applies a default NumberAnimation to any changes a state change makes to x or y properties
            NumberAnimation { properties: "x,y" }
        }
    ]
}
