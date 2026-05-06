/*
	RingQt Sample: Todo List with Ring <--> QML Communication
	Demonstrates:
		- Ring manages data (list of tasks)
		- QML provides the UI (ListView, TextInput, buttons)
		- QML --> Ring: button clicks to add/toggle/delete tasks
		- Ring --> QML: pushes updated task list back to QML
		- Uses statusMsg property to pass task index from QML to Ring
*/

load "guilib.ring"
load "lib/ringcode.ring"

# Task data managed by Ring
aTasks = []

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Todo List")
		resize(650, 530)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title via context
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Todo List"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/todolist.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Actions via RingCode
		new RingCode(oQuick, "btnAddTask", "addTask()")
		new RingCode(oQuick, "btnToggleTask", "toggleTask()")
		new RingCode(oQuick, "btnDeleteTask", "deleteTask()")

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Ring functions called by QML ---

func addTask

	# Read the input text from QML
	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, "getInputText()")
	cText = oExpr.evaluate().toString()

	if trim(cText) = "" return ok

	# Add to Ring list
	add(aTasks, [ :task = cText, :done = false ])

	# Clear input and refresh
	callQML("clearInput()")
	refreshList()
	updateStatus("Added: " + cText)

func toggleTask

	# Get task index from QML statusMsg property
	nIdx = getTaskIndex()
	if nIdx < 1 or nIdx > len(aTasks) return ok

	# Toggle done state in Ring
	aTasks[nIdx][:done] = !aTasks[nIdx][:done]

	cText = aTasks[nIdx][:task]
	if aTasks[nIdx][:done]
		cStatus = "Completed: " + cText
	else
		cStatus = "Reopened: " + cText
	ok

	refreshList()
	updateStatus(cStatus)

func deleteTask

	# Get task index from QML statusMsg property
	nIdx = getTaskIndex()
	if nIdx < 1 or nIdx > len(aTasks) return ok

	cText = aTasks[nIdx][:task]
	del(aTasks, nIdx)

	refreshList()
	updateStatus("Deleted: " + cText)

# --- Ring --> QML: Push data back ---

func refreshList

	# Clear QML list
	callQML("clearList()")

	# Add each task to QML
	for x = 1 to len(aTasks)
		cTask = aTasks[x][:task]
		# Escape single quotes in task text
		cTask = substr(cTask, "'", "\'")
		if aTasks[x][:done]
			cDone = "true"
		else
			cDone = "false"
		ok
		callQML("addItem('" + cTask + "', " + cDone + ", " + x + ")")
	next

	# Update counter
	nDone = 0
	for x = 1 to len(aTasks)
		if aTasks[x][:done] nDone++ ok
	next
	callQML("updateCounter(" + len(aTasks) + ", " + nDone + ")")

func getTaskIndex

	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "statusMsg")
	return 0 + oProp.read().toString()

func updateStatus cMsg

	cMsg = substr(cMsg, "'", "\'")
	callQML("updateStatus('" + cMsg + "')")

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
