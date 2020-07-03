# Form/Window Controller - Source Code File

load "windowflagsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:windowflagsController)
		exec()
	}
}

class windowflagsController from windowsControllerParent

	oView = new windowflagsView
