import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 300
    color: "#336699"

    // Properties accessible from Ring
    property string currentMessage: "Waiting for Ring..."
    property int counterValue: 0

    // Title from Ring context
    Text {
        id: titleText
        text: typeof appTitle !== "undefined" ? appTitle : "Loading..."
        color: "white"
        font.pointSize: 20
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
    }

    // Version from Ring context
    Text {
        id: versionText
        text: typeof appVersion !== "undefined" ? appVersion : ""
        color: "#aaccff"
        font.pointSize: 12
        anchors.horizontalCenter: parent.horizontalCenter
        y: 55
    }

    // Display the currentMessage property
    Text {
        id: messageText
        text: root.currentMessage
        color: "yellow"
        font.pointSize: 16
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
    }

    // Counter display
    Text {
        id: counterText
        text: "Counter: " + root.counterValue
        color: "white"
        font.pointSize: 18
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 150
    }

    // Status bar
    Rectangle {
        id: statusBar
        width: parent.width
        height: 40
        color: "#224466"
        anchors.bottom: parent.bottom

        Text {
            id: statusText
            text: "QML Ready - Waiting for Ring commands"
            color: "#88bbee"
            font.pointSize: 11
            anchors.centerIn: parent
        }
    }

    // Function callable from Ring via QQmlExpression
    function changeColor() {
        var colors = ["#336699", "#993366", "#669933", "#996633", "#339966", "#663399"];
        var idx = Math.floor(Math.random() * colors.length);
        root.color = colors[idx];
        statusText.text = "Color changed by Ring!";
    }

    // Function to update counter display
    function updateCounter() {
        statusText.text = "Counter updated by Ring to " + root.counterValue;
    }
}
