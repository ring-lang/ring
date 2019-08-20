# Form/Window Controller - Source Code File

load "myappView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:myappController)
		exec()
	}
}

class myappController from windowsControllerParent

	oView = new myappView

	func SayHello
		msgInfo("MyApp","Hello, World!")

	func CloseApp
		oView.win.close()
