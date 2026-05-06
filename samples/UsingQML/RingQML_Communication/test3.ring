/*
	Use the RingCode class (a subclass from QPushButton)
	Pass RingCode object to QML via QQmlContext
	QML calls the RingCode click event which executes Ring code
	Demonstrates: setContextPropertyUsingObject() to pass QObject to QML
*/

load "guilib.ring"
load "lib/easyqml.ring"

nCount = 0

new qApp {

	w = new qWidget() {

		setWindowTitle("QML calls Ring via QPushButton")
		resize(650, 500)
		move(100, 100)

		# Label to show Ring output
		oLabel = new qLabel(w) {
			setText("Waiting for QML to call Ring...")
			setStyleSheet("padding: 10px; font-size: 16px; color: white; background-color: #333;")
			setAlignment(1)
		}

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
			setSource(AppURL("qml/buttons.qml"))
			setResizeMode(1)
		}

		# Define Ring Code to be called by QML
		new RingCode(oQuick,"btnGreet",func { 
			oLabel.setText("Ring says: Hello from Ring! Welcome to RingQt!") 
		} ) 
		new RingCode(oQuick,"btnTime",func {
			oLabel.setText("Ring says: Current time is " + time())
		}) 
		new RingCode(oQuick,"btnCount",func {
			nCount++
			oLabel.setText("Ring says: Button clicked " + nCount + " time(s)")
		})

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
			AddWidget(oLabel)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}
