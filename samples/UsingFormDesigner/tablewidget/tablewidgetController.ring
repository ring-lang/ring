# Form/Window Controller - Source Code File

load "tablewidgetView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:tablewidgetController)
		exec()
	}
}

class tablewidgetController from windowsControllerParent

	oView = new tablewidgetView
