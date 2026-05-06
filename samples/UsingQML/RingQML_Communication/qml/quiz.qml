import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 570
    color: "#1a1a2e"

    property string statusMsg: ""
    property int score: 0
    property int totalQuestions: 0
    property int currentQuestion: 0
    property bool showingResult: false

    // Title bar
    Rectangle {
        id: titleBar
        width: parent.width
        height: 50
        color: "#16213e"

        Text {
            text: typeof appTitle !== "undefined" ? appTitle : "Quiz"
            color: "#e94560"
            font.pointSize: 18
            font.bold: true
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
        }

        // Score display
        Text {
            id: scoreText
            text: "Score: " + root.score + " / " + root.totalQuestions
            color: "#2ecc71"
            font.pointSize: 14
            font.bold: true
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    // Progress bar
    Rectangle {
        id: progressBg
        width: parent.width
        height: 6
        y: titleBar.height
        color: "#16213e"

        Rectangle {
            width: root.totalQuestions > 0 ?
                (root.currentQuestion / root.totalQuestions) * parent.width : 0
            height: parent.height
            color: "#e94560"

            Behavior on width {
                NumberAnimation { duration: 300 }
            }
        }
    }

    // Question area
    Rectangle {
        id: questionArea
        width: parent.width - 40
        height: 100
        radius: 12
        color: "#16213e"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 75

        // Question number badge
        Rectangle {
            width: 80
            height: 26
            radius: 13
            color: "#e94560"
            anchors.horizontalCenter: parent.horizontalCenter
            y: -13

            Text {
                text: "Q " + root.currentQuestion + " / " + root.totalQuestions
                color: "white"
                font.pointSize: 10
                font.bold: true
                anchors.centerIn: parent
            }
        }

        Text {
            id: questionText
            text: ""
            color: "white"
            font.pointSize: 16
            font.bold: true
            wrapMode: Text.Wrap
            width: parent.width - 40
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
        }
    }

    // Answer buttons
    Column {
        id: answersColumn
        anchors.horizontalCenter: parent.horizontalCenter
        y: 195
        spacing: 12
        width: parent.width - 40

        Repeater {
            id: answerRepeater
            model: ListModel { id: answerModel }

            Rectangle {
                id: answerBtn
                width: answersColumn.width
                height: 55
                radius: 10
                color: model.btnColor !== undefined ? model.btnColor : "#16213e"
                border.color: "#e94560"
                border.width: 1

                Behavior on color {
                    ColorAnimation { duration: 300 }
                }

                Row {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 12

                    // Letter badge
                    Rectangle {
                        width: 32
                        height: 32
                        radius: 16
                        color: "#e94560"
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            text: model.letter
                            color: "white"
                            font.pointSize: 14
                            font.bold: true
                            anchors.centerIn: parent
                        }
                    }

                    Text {
                        text: model.answer
                        color: "white"
                        font.pointSize: 14
                        width: parent.width - 50
                        wrapMode: Text.Wrap
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    enabled: !root.showingResult
                    onClicked: {
                        root.statusMsg = "" + model.idx
                        btnAnswer.click()
                    }
                }
            }
        }
    }

    // Feedback and Next button container
    Column {
        id: bottomColumn
        anchors.horizontalCenter: parent.horizontalCenter
        y: 470
        spacing: 10

        // Feedback area
        Rectangle {
            id: feedbackArea
            width: root.width - 40
            height: 45
            radius: 10
            color: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
            visible: false

            Text {
                id: feedbackText
                text: ""
                color: "white"
                font.pointSize: 14
                font.bold: true
                anchors.centerIn: parent
            }
        }

        // Next button
        Rectangle {
            id: nextBtn
            width: 200
            height: 45
            radius: 10
            color: nextMA.pressed ? "#e94560" : "#c23152"
            anchors.horizontalCenter: parent.horizontalCenter
            visible: false

            Text {
                id: nextBtnText
                text: "Next Question"
                color: "white"
                font.pointSize: 14
                font.bold: true
                anchors.centerIn: parent
            }

            MouseArea {
                id: nextMA
                anchors.fill: parent
                onClicked: btnNext.click()
            }
        }
    }

    // Results screen overlay
    Rectangle {
        id: resultsScreen
        width: parent.width
        height: parent.height
        color: "#1a1a2e"
        visible: false

        Column {
            anchors.centerIn: parent
            spacing: 20

            Text {
                text: "Quiz Complete!"
                color: "#e94560"
                font.pointSize: 28
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            // Score circle
            Rectangle {
                width: 160
                height: 160
                radius: 80
                color: "#16213e"
                border.color: root.score >= root.totalQuestions / 2 ? "#2ecc71" : "#e74c3c"
                border.width: 5
                anchors.horizontalCenter: parent.horizontalCenter

                Column {
                    anchors.centerIn: parent
                    spacing: 4

                    Text {
                        text: root.score + "/" + root.totalQuestions
                        color: "white"
                        font.pointSize: 32
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        id: percentText
                        text: root.totalQuestions > 0 ?
                            Math.round((root.score / root.totalQuestions) * 100) + "%" : "0%"
                        color: "#aaa"
                        font.pointSize: 16
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }

            Text {
                id: gradeText
                text: ""
                color: "#2ecc71"
                font.pointSize: 18
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            // Restart button
            Rectangle {
                width: 200
                height: 50
                radius: 10
                color: restartMA.pressed ? "#e94560" : "#c23152"
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    text: "Play Again"
                    color: "white"
                    font.pointSize: 16
                    font.bold: true
                    anchors.centerIn: parent
                }

                MouseArea {
                    id: restartMA
                    anchors.fill: parent
                    onClicked: btnRestart.click()
                }
            }
        }
    }

    // --- Functions called by Ring ---

    function setQuestion(num, total, question) {
        root.currentQuestion = num
        root.totalQuestions = total
        questionText.text = question
        answerModel.clear()
        feedbackArea.visible = false
        nextBtn.visible = false
        root.showingResult = false
        resultsScreen.visible = false
    }

    function addAnswer(idx, letter, answer) {
        answerModel.append({
            idx: idx,
            letter: letter,
            answer: answer,
            btnColor: "#16213e"
        })
    }

    function showCorrect(correctIdx, selectedIdx) {
        root.showingResult = true
        for (var i = 0; i < answerModel.count; i++) {
            if (answerModel.get(i).idx === correctIdx) {
                answerModel.setProperty(i, "btnColor", "#0a5d2a")
            } else if (answerModel.get(i).idx === selectedIdx && selectedIdx !== correctIdx) {
                answerModel.setProperty(i, "btnColor", "#8b1a1a")
            }
        }
    }

    function showFeedback(isCorrect, msg) {
        feedbackArea.visible = true
        feedbackArea.color = isCorrect ? "#0a5d2a" : "#8b1a1a"
        feedbackText.text = msg
    }

    function showNextButton(isLast) {
        nextBtn.visible = true
        nextBtnText.text = isLast ? "See Results" : "Next Question"
    }

    function updateScore(s) {
        root.score = s
    }

    function showResults(grade) {
        resultsScreen.visible = true
        gradeText.text = grade
    }

    function resetQuiz() {
        root.score = 0
        root.currentQuestion = 0
        resultsScreen.visible = false
        feedbackArea.visible = false
        nextBtn.visible = false
    }
}
