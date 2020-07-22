# Form/Window Controller - Source Code File

load "checkboxView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:checkboxController)
		exec()
	}
}

class checkboxController from windowsControllerParent

	oView = new checkboxView
