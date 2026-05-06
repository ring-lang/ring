/*
	RingQt Sample: Quiz Game with Ring <--> QML Communication
	Demonstrates:
		- Ring manages game state (questions, score, progress)
		- QML provides animated quiz UI (cards, buttons, results)
		- QML --> Ring: answer selection via RingCode
		- Ring --> QML: pushes questions, feedback, and results
		- Game state management with progression and scoring
*/

load "guilib.ring"
load "lib/easyqml.ring"

# Game state
aQuestions = []
nCurrent = 1
nScore = 0

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Quiz Game")
		resize(650, 600)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Quiz"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/quiz.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Actions
		new RingCode(oQuick, "btnAnswer", "onAnswer()")
		new RingCode(oQuick, "btnNext", "onNext()")
		new RingCode(oQuick, "btnRestart", "onRestart()")

		# Load questions and start
		loadQuestions()
		showQuestion()

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Load questions ---

func loadQuestions

	aQuestions = []

	addQuestion(
		"What programming language is RingQt built for?",
		["Ring", "Python", "Java", "C++"],
		1
	)

	addQuestion(
		"Which class is used to create a window in RingQt?",
		["QWidget", "QFrame", "QDialog", "QWindow"],
		1
	)

	addQuestion(
		"What does QML stand for?",
		["Qt Modeling Language", "Qt Markup Language",
		 "Quick Markup Language", "Query Modeling Language"],
		2
	)

	addQuestion(
		"Which class connects Ring to QML context?",
		["QQmlEngine", "QQmlContext", "QQmlComponent", "QQuickView"],
		2
	)

	addQuestion(
		"What function evaluates QML expressions from Ring?",
		["QQmlProperty", "QQmlEngine", "QQmlExpression", "QQmlComponent"],
		3
	)

	addQuestion(
		"Which layout arranges widgets vertically?",
		["QHBoxLayout", "QGridLayout", "QVBoxLayout", "QFormLayout"],
		3
	)

	addQuestion(
		"What signal does QPushButton emit when clicked?",
		["pressed()", "clicked()", "triggered()", "activated()"],
		2
	)

	addQuestion(
		"Which class is used for database operations in RingQt?",
		["QDataStream", "QSqlDatabase", "QNetworkRequest", "QFileInfo"],
		2
	)

	addQuestion(
		"What does the RingCode class inherit from?",
		["QObject", "QWidget", "QPushButton", "QLabel"],
		3
	)

	addQuestion(
		"Which class provides a timer in RingQt?",
		["QClock", "QTime", "QTimer", "QInterval"],
		3
	)

func addQuestion cQuestion, aAnswers, nCorrect

	add(aQuestions, [
		:question = cQuestion,
		:answers = aAnswers,
		:correct = nCorrect
	])

# --- Show current question ---

func showQuestion

	if nCurrent > len(aQuestions)
		showResults()
		return
	ok

	oQ = aQuestions[nCurrent]
	cQuestion = escapeQuotes(oQ[:question])
	nTotal = len(aQuestions)

	callQML("setQuestion(" + nCurrent + ", " + nTotal +
		", '" + cQuestion + "')")

	aLetters = ["A", "B", "C", "D"]
	for x = 1 to len(oQ[:answers])
		cAnswer = escapeQuotes(oQ[:answers][x])
		callQML("addAnswer(" + x + ", '" + aLetters[x] +
			"', '" + cAnswer + "')")
	next

	callQML("updateScore(" + nScore + ")")

# --- Handle answer selection ---

func onAnswer

	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "statusMsg")
	nSelected = 0 + oProp.read().toString()

	oQ = aQuestions[nCurrent]
	nCorrect = oQ[:correct]

	# Show correct/wrong highlights
	callQML("showCorrect(" + nCorrect + ", " + nSelected + ")")

	# Check answer
	if nSelected = nCorrect
		nScore++
		callQML("updateScore(" + nScore + ")")
		callQML("showFeedback(true, 'Correct! Well done!')")
	else
		cCorrectAnswer = escapeQuotes(oQ[:answers][nCorrect])
		callQML("showFeedback(false, 'Wrong! Answer: " +
			cCorrectAnswer + "')")
	ok

	# Show next button
	if nCurrent >= len(aQuestions)
		callQML("showNextButton(true)")
	else
		callQML("showNextButton(false)")
	ok

# --- Next question or results ---

func onNext

	nCurrent++
	if nCurrent > len(aQuestions)
		showResults()
	else
		showQuestion()
	ok

# --- Show results ---

func showResults

	nTotal = len(aQuestions)
	nPercent = 0
	if nTotal > 0
		nPercent = floor((nScore / nTotal) * 100)
	ok

	if nPercent >= 90
		cGrade = "Outstanding! You are a RingQt master!"
	but nPercent >= 70
		cGrade = "Great job! You know RingQt well!"
	but nPercent >= 50
		cGrade = "Good effort! Keep learning!"
	but nPercent >= 30
		cGrade = "Not bad! Review the docs and try again!"
	else
		cGrade = "Keep practicing! You will get there!"
	ok

	callQML("showResults('" + cGrade + "')")

# --- Restart ---

func onRestart

	nCurrent = 1
	nScore = 0
	callQML("resetQuiz()")
	showQuestion()

# --- Helpers ---

func escapeQuotes cText

	cText = substr(cText, "'", " ")
	cText = substr(cText, '"', " ")
	cText = substr(cText, char(10), " ")
	cText = substr(cText, char(13), " ")
	return cText

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
