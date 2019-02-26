import QtQuick 2.0

Item {
    width: 320
    height: 120

    Rectangle {
        color: "blue"
        width: 120
        height: 120

        // By setting this SequentialAnimation on x, it and animations within it will automatically animate
        // the x property of this element
        SequentialAnimation on x {
            id: xAnim
            // Animations on properties start running by default
            running: false
            loops: Animation.Infinite // The animation is set to loop indefinitely
            NumberAnimation { from: 0; to: 200; duration: 500; easing.type: Easing.InOutQuad }
            NumberAnimation { from: 200; to: 0; duration: 500; easing.type: Easing.InOutQuad }
            PauseAnimation { duration: 250 } // This puts a bit of time between the loop
        }

        MouseArea {
            anchors.fill: parent
            // The animation starts running when you click within the rectangle
            onClicked: xAnim.running = true
        }
    }
} 
