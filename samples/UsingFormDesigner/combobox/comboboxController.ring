# Form/Window Controller - Source Code File

load "comboboxView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:comboboxController)
		exec()
	}
}

class comboboxController from windowsControllerParent

	oView = new comboboxView
