# Form/Window Controller - Source Code File

load "windowflagsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:windowflagsController)
		exec()
	}
}

class windowflagsController from windowsControllerParent

	oView = new windowflagsView
