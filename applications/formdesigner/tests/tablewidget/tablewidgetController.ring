# Form/Window Controller - Source Code File

load "tablewidgetView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:tablewidgetController)
		exec()
	}
}

class tablewidgetController from windowsControllerParent

	oView = new tablewidgetView
