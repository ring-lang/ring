# Form/Window Controller - Source Code File

load "datetimeView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:datetimeController)
		exec()
	}
}

class datetimeController from windowsControllerParent

	oView = new datetimeView
