import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 450
    color: "#1a1a2e"

    property string statusMsg: "Ready"

    // Title
    Text {
        id: title
        text: typeof appTitle !== "undefined" ? appTitle : "Todo List"
        color: "#e94560"
        font.pointSize: 22
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
    }

    // Input area
    Rectangle {
        id: inputArea
        width: 500
        height: 45
        radius: 8
        color: "#16213e"
        border.color: "#e94560"
        border.width: 2
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50

        TextInput {
            id: taskInput
            width: parent.width - 80
            height: parent.height
            color: "white"
            font.pointSize: 16
            verticalAlignment: TextInput.AlignVCenter
            anchors.left: parent.left
            anchors.leftMargin: 15
            clip: true

            Text {
                text: "Type a new task..."
                color: "#555"
                font.pointSize: 16
                visible: !taskInput.text && !taskInput.activeFocus
                anchors.verticalCenter: parent.verticalCenter
            }

            Keys.onReturnPressed: {
                if (taskInput.text !== "") {
                    addTask(taskInput.text)
                }
            }
        }

        // Add button
        Rectangle {
            width: 55
            height: 35
            radius: 6
            color: addMA.pressed ? "#e94560" : "#c23152"
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter

            Text {
                text: "Add"
                color: "white"
                font.pointSize: 13
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: addMA
                anchors.fill: parent
                onClicked: {
                    if (taskInput.text !== "") {
                        addTask(taskInput.text)
                    }
                }
            }
        }
    }

    // Task counter
    Text {
        id: counterText
        text: "0 tasks"
        color: "#e94560"
        font.pointSize: 11
        anchors.horizontalCenter: parent.horizontalCenter
        y: 102
    }

    // Task list
    Rectangle {
        id: listArea
        width: 500
        height: 260
        radius: 8
        color: "#16213e"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 122
        clip: true

        ListModel {
            id: taskModel
        }

        ListView {
            id: taskList
            anchors.fill: parent
            anchors.margins: 5
            model: taskModel
            spacing: 4

            delegate: Rectangle {
                width: taskList.width
                height: 45
                radius: 6
                color: model.done ? "#0a3d0a" : "#1a1a3e"
                border.color: model.done ? "#2ecc71" : "#34495e"
                border.width: 1

                Row {
                    anchors.fill: parent
                    anchors.margins: 8
                    spacing: 10

                    // Done checkbox
                    Rectangle {
                        width: 28
                        height: 28
                        radius: 4
                        color: model.done ? "#2ecc71" : "transparent"
                        border.color: model.done ? "#2ecc71" : "#e94560"
                        border.width: 2
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            text: model.done ? "\u2713" : ""
                            color: "white"
                            font.pointSize: 16
                            font.bold: true
                            anchors.centerIn: parent
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: toggleTask(model.idx)
                        }
                    }

                    // Task text
                    Text {
                        text: model.task
                        color: model.done ? "#2ecc71" : "white"
                        font.pointSize: 14
                        font.strikeout: model.done
                        width: parent.width - 80
                        elide: Text.ElideRight
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    // Delete button
                    Rectangle {
                        width: 28
                        height: 28
                        radius: 4
                        color: delMA.pressed ? "#e74c3c" : "#c0392b"
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            text: "\u2717"
                            color: "white"
                            font.pointSize: 14
                            font.bold: true
                            anchors.centerIn: parent
                        }

                        MouseArea {
                            id: delMA
                            anchors.fill: parent
                            onClicked: deleteTask(model.idx)
                        }
                    }
                }
            }
        }

        // Empty state
        Text {
            text: "No tasks yet - add one above!"
            color: "#555"
            font.pointSize: 14
            anchors.centerIn: parent
            visible: taskModel.count === 0
        }
    }

    // Status bar
    Rectangle {
        width: parent.width
        height: 30
        color: "#16213e"
        anchors.bottom: parent.bottom

        Text {
            text: root.statusMsg
            color: "#e94560"
            font.pointSize: 10
            anchors.centerIn: parent
        }
    }

    // --- Functions called by Ring to update QML ---

    function clearList() {
        taskModel.clear()
    }

    function addItem(task, done, idx) {
        taskModel.append({ task: task, done: done, idx: idx })
    }

    function updateCounter(total, completed) {
        counterText.text = total + " task(s), " + completed + " done"
    }

    function updateStatus(msg) {
        root.statusMsg = msg
    }

    function clearInput() {
        taskInput.text = ""
    }

    function getInputText() {
        return taskInput.text
    }

    // --- Functions that call Ring via RingCode buttons ---

    function addTask(text) {
        btnAddTask.click()
    }

    function toggleTask(idx) {
        root.statusMsg = "" + idx
        btnToggleTask.click()
    }

    function deleteTask(idx) {
        root.statusMsg = "" + idx
        btnDeleteTask.click()
    }
}
