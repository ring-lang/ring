import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 350
    color: "#2c3e50"

    Text {
        id: title
        text: "QML Calling Ring Functions"
        color: "white"
        font.pointSize: 22
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
    }

    Text {
        text: "Click the buttons below - they call Ring functions!"
        color: "#bdc3c7"
        font.pointSize: 12
        anchors.horizontalCenter: parent.horizontalCenter
        y: 60
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 110
        spacing: 15

        Rectangle {
            width: 300
            height: 50
            radius: 8
            color: mouseArea1.pressed ? "#1abc9c" : "#16a085"

            Text {
                text: "Greet Me (calls Ring)"
                color: "white"
                font.pointSize: 14
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onClicked: btnGreet.click()
            }
        }

        Rectangle {
            width: 300
            height: 50
            radius: 8
            color: mouseArea2.pressed ? "#3498db" : "#2980b9"

            Text {
                text: "Show Time (calls Ring)"
                color: "white"
                font.pointSize: 14
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onClicked: btnTime.click()
            }
        }

        Rectangle {
            width: 300
            height: 50
            radius: 8
            color: mouseArea3.pressed ? "#e74c3c" : "#c0392b"

            Text {
                text: "Count Clicks (calls Ring)"
                color: "white"
                font.pointSize: 14
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: mouseArea3
                anchors.fill: parent
                onClicked: btnCount.click()
            }
        }
    }
}
