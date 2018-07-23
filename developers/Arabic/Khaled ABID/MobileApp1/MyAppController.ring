# Form/Window Controller - Source Code File

load "MyAppView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:MyAppController)
		exec()
	}
}

class MyAppController from windowsControllerParent

	oView = new MyAppView
	
	func TellMeHello
		msginfo("MyApp","Hello, World!")

	func CloseApp
		oView.win.close()
