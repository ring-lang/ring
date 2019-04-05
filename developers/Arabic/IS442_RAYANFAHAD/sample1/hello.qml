import QtQuick 2.0

Rectangle {
    id: page
    width: 520; height: 480
    color: "purple"

    Text {
        id: helloText
        text: "Hello world!"
		color: "white"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }
	Text {
        id: welcomeText
        text: "RingQt support QML too!"
		color: "white"
        y: 130
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }
}