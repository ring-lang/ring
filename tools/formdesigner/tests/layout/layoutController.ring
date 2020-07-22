# Form/Window Controller - Source Code File

load "layoutView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:layoutController)
		exec()
	}
}

class layoutController from windowsControllerParent

	oView = new layoutView
