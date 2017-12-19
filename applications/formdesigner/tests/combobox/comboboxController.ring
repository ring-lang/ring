# Form/Window Controller - Source Code File

load "comboboxView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:comboboxController)
		exec()
	}
}

class comboboxController from windowsControllerParent

	oView = new comboboxView
