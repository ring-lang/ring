/*
	RingQt Sample: Bidirectional Ring <--> QML Communication
	A calculator where:
		- Ring sets initial values and title via QQmlContext
		- QML provides the UI (buttons, display)
		- QML button clicks call Ring functions via RingCode
		- Ring does the math and updates QML via QQmlExpression
	Demonstrates the full round-trip: Ring -> QML -> Ring -> QML
*/

load "guilib.ring"
load "lib/easyqml.ring"

cDisplay = "0"
nFirst = 0
cOp = ""
lNewNumber = true

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Calculator")
		resize(650, 500)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set initial data via QQmlContext
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Calculator"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/calculator.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Button clicks call Ring functions via RingCode
		# Number buttons
		for x = 0 to 9
			new RingCode(oQuick, "btn" + x,
				"pressNumber(" + x + ")")
		next

		# Operation buttons
		new RingCode(oQuick, "btnAdd", "pressOp('+')")
		new RingCode(oQuick, "btnSub", "pressOp('-')")
		new RingCode(oQuick, "btnMul", "pressOp('*')")
		new RingCode(oQuick, "btnDiv", "pressOp('/')")
		new RingCode(oQuick, "btnEqual", "pressEqual()")
		new RingCode(oQuick, "btnClear", "pressClear()")

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

func pressNumber nNum

	if lNewNumber
		cDisplay = "" + nNum
		lNewNumber = false
	else
		if cDisplay = "0"
			cDisplay = "" + nNum
		else
			cDisplay += nNum
		ok
	ok
	updateQML()

func pressOp cNewOp

	if cOp != "" and !lNewNumber
		pressEqual()
	ok
	nFirst = 0 + cDisplay
	cOp = cNewOp
	lNewNumber = true
	updateOpQML()

func pressEqual

	if cOp = "" return ok

	nSecond = 0 + cDisplay
	nResult = 0

	switch cOp
		on "+" nResult = nFirst + nSecond
		on "-" nResult = nFirst - nSecond
		on "*" nResult = nFirst * nSecond
		on "/"
			if nSecond = 0
				updateStatusQML("Cannot divide by zero!")
				return
			ok
			nResult = nFirst / nSecond
	off

	cStatus = "" + nFirst + " " + cOp + " " + nSecond + " = " + nResult
	cDisplay = "" + nResult
	cOp = ""
	nFirst = 0
	lNewNumber = true

	updateQML()
	updateOpQML()
	updateStatusQML(cStatus)

func pressClear

	cDisplay = "0"
	nFirst = 0
	cOp = ""
	lNewNumber = true
	updateQML()
	updateOpQML()
	updateStatusQML("Cleared")

# Ring --> QML: Update display via QQmlExpression
func updateQML

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot,
		"updateDisplay('" + cDisplay + "')")
	oExpr.evaluate()

func updateOpQML

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	cShow = cOp
	if cOp != ""
		cShow = "" + nFirst + " " + cOp
	ok
	oExpr = new QQmlExpression(oCtx, oRoot,
		"updateOperation('" + cShow + "')")
	oExpr.evaluate()

func updateStatusQML cMsg

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot,
		"updateStatus('" + cMsg + "')")
	oExpr.evaluate()
