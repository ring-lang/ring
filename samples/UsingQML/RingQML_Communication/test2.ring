/*
	RingQt Sample: Pass QPushButton to QML via QQmlContext
	QML calls the button's click event which executes Ring code
	Demonstrates: setContextPropertyUsingObject() to pass QObject to QML
*/

load "guilib.ring"

nCount = 0

new qApp {

	w = new qWidget() {

		setWindowTitle("QML calls Ring via QPushButton")
		resize(650, 500)
		move(100, 100)

		# Create buttons in Ring with click events
		oBtnGreet = new qPushButton(w) {
			setClickEvent("greetUser()")
			hide()
		}
		oBtnTime = new qPushButton(w) {
			setClickEvent("showTime()")
			hide()
		}
		oBtnCount = new qPushButton(w) {
			setClickEvent("countClick()")
			hide()
		}

		# Label to show Ring output
		oLabel = new qLabel(w) {
			setText("Waiting for QML to call Ring...")
			setStyleSheet("padding: 10px; font-size: 16px; color: white; background-color: #333;")
			setAlignment(1)
		}

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Pass the Ring buttons to QML as context properties
		oContext = oQuick.rootContext()
		oContext.setContextPropertyUsingObject("btnGreet", oBtnGreet)
		oContext.setContextPropertyUsingObject("btnTime", oBtnTime)
		oContext.setContextPropertyUsingObject("btnCount", oBtnCount)

		# Load QML after setting context properties
		oQuick {
			setSource(AppURL("qml/buttons.qml"))
			setResizeMode(1)
		}

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
			AddWidget(oLabel)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

func greetUser

	oLabel.setText("Ring says: Hello from Ring! Welcome to RingQt!")

func showTime

	oLabel.setText("Ring says: Current time is " + time())

func countClick

	nCount++
	oLabel.setText("Ring says: Button clicked " + nCount + " time(s)")
