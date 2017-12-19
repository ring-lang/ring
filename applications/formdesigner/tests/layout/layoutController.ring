# Form/Window Controller - Source Code File

load "layoutView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:layoutController)
		exec()
	}
}

class layoutController from windowsControllerParent

	oView = new layoutView
