import QtQuick 2.0

Rectangle {
    id: root
    width: 500
    height: 550
    color: "#1a1a2e"

    property int hours: 0
    property int minutes: 0
    property int seconds: 0
    property string timeString: "00:00:00"
    property string dateString: ""

    // Title
    Text {
        text: typeof appTitle !== "undefined" ? appTitle : "Clock"
        color: "#e94560"
        font.pointSize: 22
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
    }

    // Clock face container
    Item {
        id: clockContainer
        width: 360
        height: 360
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50

        // Clock face background
        Rectangle {
            id: clockFace
            width: parent.width
            height: parent.height
            radius: width / 2
            color: "#16213e"
            border.color: "#e94560"
            border.width: 4
            anchors.centerIn: parent

            // Inner ring
            Rectangle {
                width: parent.width - 20
                height: parent.height - 20
                radius: width / 2
                color: "transparent"
                border.color: "#2a2a4e"
                border.width: 1
                anchors.centerIn: parent
            }

            // Hour markers
            Repeater {
                model: 12
                Rectangle {
                    width: index % 3 === 0 ? 4 : 2
                    height: index % 3 === 0 ? 20 : 12
                    color: index % 3 === 0 ? "#e94560" : "#555"
                    antialiasing: true
                    x: clockFace.width / 2 - width / 2
                    y: 15
                    transform: Rotation {
                        origin.x: width / 2
                        origin.y: clockFace.height / 2 - 15
                        angle: index * 30
                    }
                }
            }

            // Hour numbers
            Repeater {
                model: 12
                Text {
                    property real angle: (index + 1) * 30 * Math.PI / 180
                    property real radius: clockFace.width / 2 - 45
                    text: index + 1
                    color: (index + 1) % 3 === 0 ? "#e94560" : "#aaa"
                    font.pointSize: (index + 1) % 3 === 0 ? 16 : 12
                    font.bold: (index + 1) % 3 === 0
                    x: clockFace.width / 2 + radius * Math.sin(angle) - width / 2
                    y: clockFace.height / 2 - radius * Math.cos(angle) - height / 2
                }
            }

            // Minute tick marks
            Repeater {
                model: 60
                Rectangle {
                    visible: index % 5 !== 0
                    width: 1
                    height: 6
                    color: "#333"
                    antialiasing: true
                    x: clockFace.width / 2 - width / 2
                    y: 12
                    transform: Rotation {
                        origin.x: width / 2
                        origin.y: clockFace.height / 2 - 12
                        angle: index * 6
                    }
                }
            }

            // Hour hand
            Rectangle {
                id: hourHand
                width: 6
                height: 90
                radius: 3
                color: "#ecf0f1"
                antialiasing: true
                x: clockFace.width / 2 - width / 2
                y: clockFace.height / 2 - height + 15
                transformOrigin: Item.Bottom

                transform: Rotation {
                    id: hourRotation
                    origin.x: hourHand.width / 2
                    origin.y: hourHand.height - 15
                    angle: (root.hours % 12) * 30 + root.minutes * 0.5
                }
            }

            // Minute hand
            Rectangle {
                id: minuteHand
                width: 4
                height: 125
                radius: 2
                color: "#3498db"
                antialiasing: true
                x: clockFace.width / 2 - width / 2
                y: clockFace.height / 2 - height + 15
                transformOrigin: Item.Bottom

                transform: Rotation {
                    id: minuteRotation
                    origin.x: minuteHand.width / 2
                    origin.y: minuteHand.height - 15
                    angle: root.minutes * 6 + root.seconds * 0.1
                }
            }

            // Second hand
            Rectangle {
                id: secondHand
                width: 2
                height: 140
                radius: 1
                color: "#e94560"
                antialiasing: true
                x: clockFace.width / 2 - width / 2
                y: clockFace.height / 2 - height + 25
                transformOrigin: Item.Bottom

                transform: Rotation {
                    id: secondRotation
                    origin.x: secondHand.width / 2
                    origin.y: secondHand.height - 25
                    angle: root.seconds * 6
                }
            }

            // Center dot
            Rectangle {
                width: 14
                height: 14
                radius: 7
                color: "#e94560"
                anchors.centerIn: parent
            }

            // Inner center dot
            Rectangle {
                width: 6
                height: 6
                radius: 3
                color: "#1a1a2e"
                anchors.centerIn: parent
            }
        }
    }

    // Digital time display
    Text {
        id: digitalTime
        text: root.timeString
        color: "white"
        font.pointSize: 36
        font.bold: true
        font.family: "Courier"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 425
    }

    // Date display
    Text {
        id: dateText
        text: root.dateString
        color: "#888"
        font.pointSize: 13
        anchors.horizontalCenter: parent.horizontalCenter
        y: 475
    }

    // Status bar
    Rectangle {
        width: parent.width
        height: 30
        color: "#16213e"
        anchors.bottom: parent.bottom

        Text {
            text: "Powered by Ring + QML"
            color: "#e94560"
            font.pointSize: 10
            anchors.centerIn: parent
        }
    }

    // --- Functions called by Ring ---

    function updateTime(h, m, s, timeStr, dateStr) {
        root.hours = h
        root.minutes = m
        root.seconds = s
        root.timeString = timeStr
        root.dateString = dateStr
    }
}
