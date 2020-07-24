load "guilib.ring"

oApp = new qApp {
 
		oQuick = new qQuickView() {
			engine().AddImportPath(exefolder()+"qml")
			setSource(new qURL("hello.qml") )
			show()
		}
		 
	exec()
}
