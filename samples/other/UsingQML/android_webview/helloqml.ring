load "guilib.ring"

new qApp {
	w = new qMainWIndow() {
		setWindowTitle("Using QML")  
		oQuick = new qQuickWidget(w) {
			setSource(new qURL("qrc:///hello.qml") )
			show()
			QQuickWidget_SizeRootObjectToView = 1
			setResizeMode(QQuickWidget_SizeRootObjectToView)
			setGeometry(0,0,1300,1300)
		}		
		show()
	}
	exec()
}
