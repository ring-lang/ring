# Form/Window Controller - Source Code File

load "tabinsidetabView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:tabinsidetabController)
		exec()
	}
}

class tabinsidetabController from windowsControllerParent

	oView = new tabinsidetabView
