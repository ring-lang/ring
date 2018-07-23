load "guilib.ring"

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QML") resize(600,400) move(100,100)
		oQuick = new qQuickWidget(w) {
			setSource(new qURL("hello.qml") )
		}
		oLayout = new qVBoxlayout() {
			AddWidget(oQuick)
		}
		setlayout(oLayout)
		show()
	}
	exec()
}
