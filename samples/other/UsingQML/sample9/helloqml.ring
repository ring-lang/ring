load "guilib.ring"

oApp = new qApp {
 
		oQuick = new qQuickView() {
			setSource(new qURL("hello.qml") )
			show()
		}
		 
	exec()
}
