# Form/Window Controller - Source Code File

load "checkboxView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:checkboxController)
		exec()
	}
}

class checkboxController from windowsControllerParent

	oView = new checkboxView
