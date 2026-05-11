import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 550
    color: "#1a1a2e"

    property string statusMsg: "Ready"
    property string formData: ""

    // Title
    Text {
        text: typeof appTitle !== "undefined" ? appTitle : "Form Builder"
        color: "#e94560"
        font.pointSize: 22
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
    }

    // Form area
    Rectangle {
        id: formArea
        width: parent.width - 40
        height: parent.height - 120
        radius: 8
        color: "#16213e"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50
        clip: true

        Flickable {
            id: formFlick
            anchors.fill: parent
            anchors.margins: 15
            contentHeight: formColumn.height
            clip: true

            Column {
                id: formColumn
                width: parent.width
                spacing: 12
            }
        }
    }

    // Buttons row
    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: statusBar.top
        anchors.bottomMargin: 8
        spacing: 15

        // Submit button
        Rectangle {
            width: 150
            height: 45
            radius: 8
            color: submitMA.pressed ? "#e94560" : "#c23152"

            Text {
                text: "Submit"
                color: "white"
                font.pointSize: 15
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: submitMA
                anchors.fill: parent
                onClicked: {
                    collectFormData()
                    btnSubmit.click()
                }
            }
        }

        // Clear button
        Rectangle {
            width: 150
            height: 45
            radius: 8
            color: clearMA.pressed ? "#555" : "#34495e"

            Text {
                text: "Clear"
                color: "white"
                font.pointSize: 15
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: clearMA
                anchors.fill: parent
                onClicked: btnClear.click()
            }
        }
    }

    // Status bar
    Rectangle {
        id: statusBar
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

    // --- Functions called by Ring to build the form ---

    function clearForm() {
        for (var i = formColumn.children.length - 1; i >= 0; i--) {
            formColumn.children[i].destroy()
        }
    }

    function addTextField(fieldId, label, placeholder) {
        Qt.createQmlObject('
            import QtQuick 2.0
            Column {
                property string fieldId: "' + fieldId + '"
                property string fieldType: "text"
                property alias fieldValue: input.text
                width: parent ? parent.width : 400
                spacing: 4
                Text {
                    text: "' + label + '"
                    color: "#e94560"
                    font.pointSize: 12
                    font.bold: true
                }
                Rectangle {
                    width: parent.width
                    height: 38
                    radius: 6
                    color: "#1a1a3e"
                    border.color: "#e94560"
                    border.width: 1
                    TextInput {
                        id: input
                        anchors.fill: parent
                        anchors.margins: 8
                        color: "white"
                        font.pointSize: 13
                        verticalAlignment: TextInput.AlignVCenter
                        clip: true
                        Text {
                            text: "' + placeholder + '"
                            color: "#555"
                            font.pointSize: 13
                            visible: !input.text && !input.activeFocus
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }', formColumn, "textField")
    }

    function addDropdown(fieldId, label, optionsStr) {
        var options = optionsStr.split(",")
        var optionsJson = JSON.stringify(options)
        Qt.createQmlObject('
            import QtQuick 2.0
            Column {
                id: dropdownRoot
                property string fieldId: "' + fieldId + '"
                property string fieldType: "dropdown"
                property int currentSelection: 0
                property var options: ' + optionsJson + '
                property string fieldValue: options[currentSelection]
                width: parent ? parent.width : 400
                spacing: 4
                Text {
                    text: "' + label + '"
                    color: "#e94560"
                    font.pointSize: 12
                    font.bold: true
                }
                Flow {
                    width: parent.width
                    spacing: 6
                    Repeater {
                        model: dropdownRoot.options
                        Rectangle {
                            width: Math.max(80, optLabel.width + 20)
                            height: 36
                            radius: 6
                            color: dropdownRoot.currentSelection === index ? "#e94560" : "#1a1a3e"
                            border.color: "#e94560"
                            border.width: 1
                            Text {
                                id: optLabel
                                text: modelData
                                color: "white"
                                font.pointSize: 11
                                anchors.centerIn: parent
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: dropdownRoot.currentSelection = index
                            }
                        }
                    }
                }
            }', formColumn, "dropdown")
    }

    function addCheckbox(fieldId, label) {
        Qt.createQmlObject('
            import QtQuick 2.0
            Row {
                id: checkRoot
                property string fieldId: "' + fieldId + '"
                property string fieldType: "checkbox"
                property bool checked: false
                property string fieldValue: checked ? "true" : "false"
                width: parent ? parent.width : 400
                spacing: 10
                Rectangle {
                    width: 28
                    height: 28
                    radius: 4
                    color: checkRoot.checked ? "#2ecc71" : "transparent"
                    border.color: checkRoot.checked ? "#2ecc71" : "#e94560"
                    border.width: 2
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        text: checkRoot.checked ? "\\u2713" : ""
                        color: "white"
                        font.pointSize: 16
                        font.bold: true
                        anchors.centerIn: parent
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: checkRoot.checked = !checkRoot.checked
                    }
                }
                Text {
                    text: "' + label + '"
                    color: "white"
                    font.pointSize: 13
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea {
                        anchors.fill: parent
                        onClicked: checkRoot.checked = !checkRoot.checked
                    }
                }
            }', formColumn, "checkbox")
    }

    function addTextArea(fieldId, label, placeholder) {
        Qt.createQmlObject('
            import QtQuick 2.0
            Column {
                property string fieldId: "' + fieldId + '"
                property string fieldType: "textarea"
                property alias fieldValue: area.text
                width: parent ? parent.width : 400
                spacing: 4
                Text {
                    text: "' + label + '"
                    color: "#e94560"
                    font.pointSize: 12
                    font.bold: true
                }
                Rectangle {
                    width: parent.width
                    height: 80
                    radius: 6
                    color: "#1a1a3e"
                    border.color: "#e94560"
                    border.width: 1
                    Flickable {
                        anchors.fill: parent
                        anchors.margins: 8
                        contentHeight: area.paintedHeight
                        clip: true
                        TextEdit {
                            id: area
                            width: parent.width
                            color: "white"
                            font.pointSize: 13
                            wrapMode: TextEdit.Wrap
                            Text {
                                text: "' + placeholder + '"
                                color: "#555"
                                font.pointSize: 13
                                visible: !area.text && !area.activeFocus
                            }
                        }
                    }
                }
            }', formColumn, "textarea")
    }

    function addSeparator(label) {
        Qt.createQmlObject('
            import QtQuick 2.0
            Column {
                property string fieldId: ""
                property string fieldType: "separator"
                width: parent ? parent.width : 400
                spacing: 4
                Rectangle {
                    width: parent.width
                    height: 1
                    color: "#34495e"
                }
                Text {
                    text: "' + label + '"
                    color: "#888"
                    font.pointSize: 10
                    font.italic: true
                }
            }', formColumn, "separator")
    }

    // --- Collect form data using fieldValue property ---

    function collectFormData() {
        var data = ""
        for (var i = 0; i < formColumn.children.length; i++) {
            var field = formColumn.children[i]
            if (field.fieldType === "separator") continue
            if (!field.fieldId || field.fieldId === "") continue

            var value = ""
            if (field.fieldValue !== undefined) {
                value = field.fieldValue
            }

            if (data !== "") data += "|"
            data += field.fieldId + "=" + value
        }
        root.formData = data
    }

    function updateStatus(msg) {
        root.statusMsg = msg
    }

    function resetForm() {
        for (var i = 0; i < formColumn.children.length; i++) {
            var field = formColumn.children[i]
            if (field.fieldType === "text" || field.fieldType === "textarea") {
                field.fieldValue = ""
            } else if (field.fieldType === "dropdown") {
                field.currentSelection = 0
            } else if (field.fieldType === "checkbox") {
                field.checked = false
            }
        }
        root.formData = ""
    }
}
