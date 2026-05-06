import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 550
    color: "#1a1a2e"

    property string statusMsg: ""

    // Title bar
    Rectangle {
        id: titleBar
        width: parent.width
        height: 50
        color: "#16213e"

        Text {
            text: typeof appTitle !== "undefined" ? appTitle : "Chat"
            color: "#e94560"
            font.pointSize: 18
            font.bold: true
            anchors.centerIn: parent
        }

        // Online indicator
        Row {
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.verticalCenter: parent.verticalCenter
            spacing: 6

            Rectangle {
                width: 10
                height: 10
                radius: 5
                color: "#2ecc71"
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: "Online"
                color: "#2ecc71"
                font.pointSize: 10
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    // Chat messages area
    Rectangle {
        id: chatArea
        width: parent.width
        height: parent.height - titleBar.height - inputArea.height
        y: titleBar.height
        color: "#1a1a2e"
        clip: true

        ListModel {
            id: messageModel
        }

        ListView {
            id: messageList
            anchors.fill: parent
            anchors.margins: 10
            model: messageModel
            spacing: 8
            verticalLayoutDirection: ListView.TopToBottom

            delegate: Item {
                width: messageList.width
                height: bubble.height + 4

                // Message bubble
                Rectangle {
                    id: bubble
                    width: Math.min(messageList.width * 0.75, msgText.width + 30)
                    height: msgText.height + senderText.height + timeText.height + 25
                    radius: 12
                    color: model.isUser ? "#e94560" : "#16213e"
                    border.color: model.isUser ? "#e94560" : "#2a2a4e"
                    border.width: model.isUser ? 0 : 1
                    anchors.right: model.isUser ? parent.right : undefined
                    anchors.left: model.isUser ? undefined : parent.left

                    // Sender name
                    Text {
                        id: senderText
                        text: model.sender
                        color: model.isUser ? "#ffccd5" : "#e94560"
                        font.pointSize: 9
                        font.bold: true
                        x: 12
                        y: 6
                    }

                    // Message text
                    Text {
                        id: msgText
                        text: model.message
                        color: "white"
                        font.pointSize: 13
                        wrapMode: Text.Wrap
                        width: Math.min(messageList.width * 0.75 - 30, implicitWidth)
                        x: 12
                        y: senderText.height + 10
                    }

                    // Time stamp
                    Text {
                        id: timeText
                        text: model.time
                        color: model.isUser ? "#ffaabb" : "#555"
                        font.pointSize: 8
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        y: senderText.height + msgText.height + 14
                    }
                }
            }

            // Auto scroll to bottom
            onCountChanged: {
                positionViewAtEnd()
            }
        }

        // Empty state
        Text {
            text: "No messages yet. Say hello!"
            color: "#555"
            font.pointSize: 14
            anchors.centerIn: parent
            visible: messageModel.count === 0
        }
    }

    // Input area
    Rectangle {
        id: inputArea
        width: parent.width
        height: 60
        color: "#16213e"
        anchors.bottom: parent.bottom

        Rectangle {
            width: parent.width - 90
            height: 40
            radius: 20
            color: "#1a1a3e"
            border.color: "#e94560"
            border.width: 1
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            TextInput {
                id: msgInput
                anchors.fill: parent
                anchors.leftMargin: 15
                anchors.rightMargin: 15
                color: "white"
                font.pointSize: 14
                verticalAlignment: TextInput.AlignVCenter
                clip: true

                Text {
                    text: "Type a message..."
                    color: "#555"
                    font.pointSize: 14
                    visible: !msgInput.text && !msgInput.activeFocus
                    anchors.verticalCenter: parent.verticalCenter
                }

                Keys.onReturnPressed: {
                    if (msgInput.text !== "") {
                        root.statusMsg = msgInput.text
                        btnSend.click()
                    }
                }
            }
        }

        // Send button
        Rectangle {
            width: 60
            height: 40
            radius: 20
            color: sendMA.pressed ? "#e94560" : "#c23152"
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            Text {
                text: "\u27A4"
                color: "white"
                font.pointSize: 18
                anchors.centerIn: parent
            }

            MouseArea {
                id: sendMA
                anchors.fill: parent
                onClicked: {
                    if (msgInput.text !== "") {
                        root.statusMsg = msgInput.text
                        btnSend.click()
                    }
                }
            }
        }
    }

    // --- Functions called by Ring ---

    function addMessage(sender, message, time, isUser) {
        messageModel.append({
            sender: sender,
            message: message,
            time: time,
            isUser: isUser
        })
    }

    function clearInput() {
        msgInput.text = ""
    }

    function clearMessages() {
        messageModel.clear()
    }

    function getInputText() {
        return msgInput.text
    }
}
