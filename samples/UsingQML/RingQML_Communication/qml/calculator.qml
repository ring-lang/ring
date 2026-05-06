
import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 400
    color: "#1a1a2e"

    property string displayValue: "0"
    property string operation: ""
    property string statusMsg: "Ready"

    // Title
    Text {
        text: typeof appTitle !== "undefined" ? appTitle : "Calculator"
        color: "#e94560"
        font.pointSize: 20
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
    }

    // Display
    Rectangle {
        id: display
        width: 360
        height: 60
        radius: 8
        color: "#16213e"
        border.color: "#e94560"
        border.width: 2
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50

        Text {
            id: displayText
            text: root.displayValue
            color: "white"
            font.pointSize: 28
            font.bold: true
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    // Operation indicator
    Text {
        text: root.operation
        color: "#e94560"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        y: 115
    }

    // Number buttons grid
    Grid {
        id: buttonGrid
        columns: 4
        spacing: 8
        anchors.horizontalCenter: parent.horizontalCenter
        y: 140

        // Row 1: 7 8 9 +
        Repeater {
            model: [
                { label: "7", action: "btn7" },
                { label: "8", action: "btn8" },
                { label: "9", action: "btn9" },
                { label: "+", action: "btnAdd" }
            ]
            Rectangle {
                width: 85
                height: 50
                radius: 6
                color: modelData.label === "+" ? 
                    (ma.pressed ? "#e94560" : "#c23152") :
                    (ma.pressed ? "#2a2a4a" : "#16213e")
                border.color: "#e94560"
                border.width: 1
                Text {
                    text: modelData.label
                    color: "white"
                    font.pointSize: 18
                    font.bold: true
                    anchors.centerIn: parent
                }
                MouseArea {
                    id: ma
                    anchors.fill: parent
                    onClicked: {
                        if (modelData.action === "btn7") btn7.click()
                        else if (modelData.action === "btn8") btn8.click()
                        else if (modelData.action === "btn9") btn9.click()
                        else if (modelData.action === "btnAdd") btnAdd.click()
                    }
                }
            }
        }

        // Row 2: 4 5 6 -
        Repeater {
            model: [
                { label: "4", action: "btn4" },
                { label: "5", action: "btn5" },
                { label: "6", action: "btn6" },
                { label: "-", action: "btnSub" }
            ]
            Rectangle {
                width: 85
                height: 50
                radius: 6
                color: modelData.label === "-" ? 
                    (ma2.pressed ? "#e94560" : "#c23152") :
                    (ma2.pressed ? "#2a2a4a" : "#16213e")
                border.color: "#e94560"
                border.width: 1
                Text {
                    text: modelData.label
                    color: "white"
                    font.pointSize: 18
                    font.bold: true
                    anchors.centerIn: parent
                }
                MouseArea {
                    id: ma2
                    anchors.fill: parent
                    onClicked: {
                        if (modelData.action === "btn4") btn4.click()
                        else if (modelData.action === "btn5") btn5.click()
                        else if (modelData.action === "btn6") btn6.click()
                        else if (modelData.action === "btnSub") btnSub.click()
                    }
                }
            }
        }

        // Row 3: 1 2 3 *
        Repeater {
            model: [
                { label: "1", action: "btn1" },
                { label: "2", action: "btn2" },
                { label: "3", action: "btn3" },
                { label: "*", action: "btnMul" } // changed from unicode to *
            ]
            Rectangle {
                width: 85
                height: 50
                radius: 6
                color: modelData.label === "*" ? 
                    (ma3.pressed ? "#e94560" : "#c23152") :
                    (ma3.pressed ? "#2a2a4a" : "#16213e")
                border.color: "#e94560"
                border.width: 1
                Text {
                    text: modelData.label
                    color: "white"
                    font.pointSize: 18
                    font.bold: true
                    anchors.centerIn: parent
                }
                MouseArea {
                    id: ma3
                    anchors.fill: parent
                    onClicked: {
                        if (modelData.action === "btn1") btn1.click()
                        else if (modelData.action === "btn2") btn2.click()
                        else if (modelData.action === "btn3") btn3.click()
                        else if (modelData.action === "btnMul") btnMul.click()
                    }
                }
            }
        }

        // Row 4: C 0 = /
        Repeater {
            model: [
                { label: "C", action: "btnClear" },
                { label: "0", action: "btn0" },
                { label: "=", action: "btnEqual" },
                { label: "/", action: "btnDiv" }
            ]
            Rectangle {
                width: 85
                height: 50
                radius: 6
                color: modelData.label === "=" ?
                    (ma4.pressed ? "#0f3460" : "#e94560") :
                    modelData.label === "C" ?
                    (ma4.pressed ? "#e94560" : "#c23152") :
                    modelData.label === "/" ?
                    (ma4.pressed ? "#e94560" : "#c23152") :
                    (ma4.pressed ? "#2a2a4a" : "#16213e")
                border.color: "#e94560"
                border.width: 1
                Text {
                    text: modelData.label
                    color: "white"
                    font.pointSize: 18
                    font.bold: true
                    anchors.centerIn: parent
                }
                MouseArea {
                    id: ma4
                    anchors.fill: parent
                    onClicked: {
                        if (modelData.action === "btnClear") btnClear.click()
                        else if (modelData.action === "btn0") btn0.click()
                        else if (modelData.action === "btnEqual") btnEqual.click()
                        else if (modelData.action === "btnDiv") btnDiv.click()
                    }
                }
            }
        }
    }

    // Status bar
    Rectangle {
        width: parent.width
        height: 35
        color: "#16213e"
        anchors.bottom: parent.bottom

        Text {
            text: root.statusMsg
            color: "#e94560"
            font.pointSize: 11
            anchors.centerIn: parent
        }
    }

    function updateDisplay(val) {
        root.displayValue = val
    }

    function updateStatus(msg) {
        root.statusMsg = msg
    }

    function updateOperation(op) {
        root.operation = op
    }
}
