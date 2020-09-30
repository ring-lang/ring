# Form/Window Controller - Source Code File

load "datetimeView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:datetimeController)
		exec()
	}
}

class datetimeController from windowsControllerParent

	oView = new datetimeView
