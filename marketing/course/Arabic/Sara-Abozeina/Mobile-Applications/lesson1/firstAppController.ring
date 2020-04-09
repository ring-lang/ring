# Form/Window Controller - Source Code File

load "firstAppView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:firstAppController)
		exec()
	}
}

class firstAppController from windowsControllerParent

	oView = new firstAppView
	func msg{
			msgINFO("MyApp","Hello in Ring Language")
	}

	func close
		oView.win.Close()
