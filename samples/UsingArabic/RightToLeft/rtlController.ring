# Form/Window Controller - Source Code File

load "rtlView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:rtlController)
		exec()
	}
}

class rtlController from windowsControllerParent

	oView = new rtlView

	oView.win.setlayoutdirection(1)

	func Close 
		oView.win.close()
