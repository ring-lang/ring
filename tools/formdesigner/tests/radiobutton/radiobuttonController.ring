# Form/Window Controller - Source Code File

load "radiobuttonView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:radiobuttonController)
		exec()
	}
}

class radiobuttonController from windowsControllerParent

	oView = new radiobuttonView
