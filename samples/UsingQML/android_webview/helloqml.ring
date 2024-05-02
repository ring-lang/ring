load "guilib.ring"

new QApp {
	oDesktop = new QDesktopWidget()
	w = new QWidget() {
		setWindowTitle("Using QML")  
		oQuick = new qQuickWidget(w) {
			if isMobile()
				setSource(new QUrl("qrc:hello.qml"))
			else
				setSource(new QUrl("hello.qml"))
			ok
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
