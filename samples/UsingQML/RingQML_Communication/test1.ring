/*
	RingQt Sample: Ring <--> QML Communication
	Demonstrates the next classes:
		QQmlContext      - Pass data from Ring to QML
		QQmlProperty     - Read/Write QML properties from Ring
		QQmlExpression   - Call QML functions from Ring
*/

load "guilib.ring"

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring <--> QML Communication")
		resize(650, 550)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
			setSource(AppURL("test1.qml"))
			setResizeMode(1)
		}

		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle", new QVariantString("Hello from Ring!"))
		oContext.setContextProperty("appVersion", new QVariantString("RingQt 2026 - Ring version " + version()))
		oContext.setContextProperty("counter", new QVariantInt(0))

		oBtn1 = new qPushButton(w) {
			setText("Read QML Property")
			setClickEvent("readQMLProperty()")
		}
		oBtn2 = new qPushButton(w) {
			setText("Write QML Property")
			setClickEvent("writeQMLProperty()")
		}
		oBtn3 = new qPushButton(w) {
			setText("Call QML Function")
			setClickEvent("callQMLFunction()")
		}
		oBtn4 = new qPushButton(w) {
			setText("Increment Counter")
			setClickEvent("incrementCounter()")
		}

		oLabel = new qLabel(w) {
			setText("Ring Output: (click a button)")
			setStyleSheet("padding: 5px; font-size: 14px; color: blue;")
		}

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
			AddWidget(oBtn1)
			AddWidget(oBtn2)
			AddWidget(oBtn3)
			AddWidget(oBtn4)
			AddWidget(oLabel)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

func readQMLProperty

	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "currentMessage")
	oLabel.setText("Ring read from QML: " + oProp.read().toString())

func writeQMLProperty

	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "currentMessage")
	oProp.write(new QVariantString("Message set by Ring at " + time()))
	oLabel.setText("Ring wrote a new message to QML!")

func callQMLFunction

	oRoot = oQuick.rootObject()
	oContext = oQuick.rootContext()
	oExpr = new QQmlExpression(oContext, oRoot, "changeColor()")
	oExpr.evaluate()
	oLabel.setText("Ring called QML changeColor() function!")

func incrementCounter

	oRoot = oQuick.rootObject()
	oContext = oQuick.rootContext()

	oProp = new QQmlProperty(oRoot, "counterValue")
	nVal = 0 + oProp.read().toString()

	nVal++
	oProp.write(new QVariantInt(nVal))

	oExpr = new QQmlExpression(oContext, oRoot, "updateCounter()")
	oExpr.evaluate()

	oLabel.setText("Ring incremented counter to: " + nVal)