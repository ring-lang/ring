/*
	RingQt Sample: Analog Clock with Ring <--> QML Communication
	Demonstrates:
		- QTimer fires every second in Ring
		- Ring reads current time and pushes to QML
		- QML rotates clock hands based on time values
		- Timer-driven continuous updates (new pattern)
*/

load "guilib.ring"

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Analog Clock")
		resize(550, 600)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Analog Clock"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/clock.qml"))
			setResizeMode(1)
		}

		# Create a timer that ticks every second
		oTimer = new qTimer(w) {
			setInterval(1000)
			setTimeoutEvent("onTick()")
			start()
		}

		# Update immediately on start
		onTick()

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Timer tick: read time and push to QML ---

func onTick

	# Get current time
	oTime = new QTime()
	oTime = oTime.currentTime()
	nH = oTime.hour()
	nM = oTime.minute()
	nS = oTime.second()

	# Format time string with leading zeros
	if nH < 10  cH = "0" + nH  else  cH = "" + nH  ok
	if nM < 10  cM = "0" + nM  else  cM = "" + nM  ok
	if nS < 10  cS = "0" + nS  else  cS = "" + nS  ok
	cTime = cH + ":" + cM + ":" + cS

	# Get current date
	cDate = date()

	# Push to QML
	callQML("updateTime(" + nH + ", " + nM + ", " + nS +
		", '" + cTime + "', '" + cDate + "')")

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
