# Form/Window Controller - Source Code File

load "rtlView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		setlayoutdirection(1)			# Right To Left
		openWindow(:rtlController)
		exec()
	}
}

class rtlController from windowsControllerParent

	oView = new rtlView

	// No need to use setLayoutDirection() for the window 
	// Since we are using it with the App object 
	// oView.win.setlayoutdirection(1)

	func Close 
		oView.win.close()
