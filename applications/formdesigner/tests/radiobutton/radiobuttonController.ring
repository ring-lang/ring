# Form/Window Controller - Source Code File

load "radiobuttonView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:radiobuttonController)
		exec()
	}
}

class radiobuttonController from windowsControllerParent

	oView = new radiobuttonView
