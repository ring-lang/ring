load "guilib.ring"

oApp = new qApp {
 
		oQuick = new qQuickView() {
			engine().AddImportPath(exefolder()+"qml")
			setSource(AppURL("hello.qml") )
			show()
		}
		 
	exec()
}
