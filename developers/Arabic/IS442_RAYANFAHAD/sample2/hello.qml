import QtQuick 2.1

Rectangle {
    id: rectangle
    color: "purple"
    width: 600
    height: 600

    Text {
        id: text
        text: "Using QML from RingQt\n(Click to pause)"
	color: "white"
        font.pointSize: 24
        anchors.centerIn: parent
        PropertyAnimation {
            id: animation
            target: text
            property: "rotation"
            from: 0; to: 360; duration: 5000
            loops: Animation.Infinite
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: animation.paused ? animation.resume() : animation.pause()
    }
    Component.onCompleted: animation.start()
}
