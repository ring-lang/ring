load "guilib.ring"

new QApp {
	oDesktop = new QDesktopWidget()
	w = new QWidget() {
		setWindowTitle("Using QML")  
		oQuick = new qQuickWidget(w) {
			setSource(AppURL("hello.qml"))
			QQuickWidget_SizeRootObjectToView = 1
			setResizeMode(QQuickWidget_SizeRootObjectToView)
			show()
		}	
		oLayout = new QVBoxlayout() {
			AddWidget(oQuick)
		}
		setLayout(oLayout)	
		showMaximized()
	}
	exec()
}
