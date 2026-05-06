
import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 470
    color: "#1a1a2e"

    property int redValue: 128
    property int greenValue: 128
    property int blueValue: 128
    property string hexColor: "#808080"
    property string statusMsg: "Drag the sliders to pick a color"

    // Title
    Text {
        text: typeof appTitle !== "undefined" ? appTitle : "Color Picker"
        color: "#e94560"
        font.pointSize: 22
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
    }

    // Color preview
    Rectangle {
        id: preview
        width: 200
        height: 200
        radius: 100
        color: root.hexColor
        border.color: "white"
        border.width: 3
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50

        Text {
            id: hexLabel
            text: root.hexColor
            color: (root.redValue + root.greenValue + root.blueValue) > 382 ? "black" : "white"
            font.pointSize: 18
            font.bold: true
            anchors.centerIn: parent
        }
    }

    // RGB values display
    Text {
        id: rgbText
        text: "RGB( " + root.redValue + ", " + root.greenValue + ", " + root.blueValue + " )"
        color: "#aaa"
        font.pointSize: 12
        anchors.horizontalCenter: parent.horizontalCenter
        y: 260
    }

    // Sliders area
    Column {
        id: slidersColumn
        anchors.horizontalCenter: parent.horizontalCenter
        y: 285
        spacing: 8

        // Red slider
        Row {
            spacing: 10
            Text {
                text: "R"
                color: "#e74c3c"
                font.pointSize: 16
                font.bold: true
                width: 20
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 400
                height: 30
                radius: 15
                color: "#16213e"
                border.color: "#e74c3c"
                border.width: 1
                anchors.verticalCenter: parent.verticalCenter

                // Fill bar
                Rectangle {
                    width: (root.redValue / 255.0) * (parent.width - 4)
                    height: parent.height - 4
                    radius: 13
                    color: Qt.rgba(root.redValue / 255.0, 0, 0, 1)
                    x: 2
                    y: 2
                }

                // Drag handle
                Rectangle {
                    id: redHandle
                    width: 26
                    height: 26
                    radius: 13
                    color: "white"
                    border.color: "#e74c3c"
                    border.width: 2
                    x: (root.redValue / 255.0) * (parent.width - 26)
                    y: 2
                }

                MouseArea {
                    anchors.fill: parent
                    onPositionChanged: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.redValue = val
                        root.statusMsg = "" + val
                        btnRed.click()
                    }
                    onClicked: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.redValue = val
                        root.statusMsg = "" + val
                        btnRed.click()
                    }
                }
            }
            Text {
                text: root.redValue
                color: "#e74c3c"
                font.pointSize: 13
                width: 35
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Green slider
        Row {
            spacing: 10
            Text {
                text: "G"
                color: "#2ecc71"
                font.pointSize: 16
                font.bold: true
                width: 20
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 400
                height: 30
                radius: 15
                color: "#16213e"
                border.color: "#2ecc71"
                border.width: 1
                anchors.verticalCenter: parent.verticalCenter

                Rectangle {
                    width: (root.greenValue / 255.0) * (parent.width - 4)
                    height: parent.height - 4
                    radius: 13
                    color: Qt.rgba(0, root.greenValue / 255.0, 0, 1)
                    x: 2
                    y: 2
                }

                Rectangle {
                    id: greenHandle
                    width: 26
                    height: 26
                    radius: 13
                    color: "white"
                    border.color: "#2ecc71"
                    border.width: 2
                    x: (root.greenValue / 255.0) * (parent.width - 26)
                    y: 2
                }

                MouseArea {
                    anchors.fill: parent
                    onPositionChanged: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.greenValue = val
                        root.statusMsg = "" + val
                        btnGreen.click()
                    }
                    onClicked: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.greenValue = val
                        root.statusMsg = "" + val
                        btnGreen.click()
                    }
                }
            }
            Text {
                text: root.greenValue
                color: "#2ecc71"
                font.pointSize: 13
                width: 35
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Blue slider
        Row {
            spacing: 10
            Text {
                text: "B"
                color: "#3498db"
                font.pointSize: 16
                font.bold: true
                width: 20
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 400
                height: 30
                radius: 15
                color: "#16213e"
                border.color: "#3498db"
                border.width: 1
                anchors.verticalCenter: parent.verticalCenter

                Rectangle {
                    width: (root.blueValue / 255.0) * (parent.width - 4)
                    height: parent.height - 4
                    radius: 13
                    color: Qt.rgba(0, 0, root.blueValue / 255.0, 1)
                    x: 2
                    y: 2
                }

                Rectangle {
                    id: blueHandle
                    width: 26
                    height: 26
                    radius: 13
                    color: "white"
                    border.color: "#3498db"
                    border.width: 2
                    x: (root.blueValue / 255.0) * (parent.width - 26)
                    y: 2
                }

                MouseArea {
                    anchors.fill: parent
                    onPositionChanged: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.blueValue = val
                        root.statusMsg = "" + val
                        btnBlue.click()
                    }
                    onClicked: {
                        var val = Math.max(0, Math.min(255,
                            Math.round((mouse.x / parent.width) * 255)))
                        root.blueValue = val
                        root.statusMsg = "" + val
                        btnBlue.click()
                    }
                }
            }
            Text {
                text: root.blueValue
                color: "#3498db"
                font.pointSize: 13
                width: 35
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    // Preset colors row
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 430
        spacing: 6

        Repeater {
            model: [
                "#e74c3c", "#e67e22", "#f1c40f", "#2ecc71",
                "#3498db", "#9b59b6", "#1abc9c", "#ecf0f1",
                "#34495e", "#000000"
            ]
            Rectangle {
                width: 24
                height: 24
                radius: 4
                color: modelData
                border.color: "white"
                border.width: 1

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.statusMsg = modelData
                        btnPreset.click()
                    }
                }
            }
        }
    }

    // --- Functions called by Ring ---

    function updateColor(hex, r, g, b) {
        root.hexColor = hex
        root.redValue = r
        root.greenValue = g
        root.blueValue = b
    }

    function updateStatus(msg) {
        root.statusMsg = msg
    }
}
