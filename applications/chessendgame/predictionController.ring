# Form/Window Controller - Source Code File

load "predictionView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:predictionController)
		exec()
	}
}

class predictionController from windowsControllerParent

	oView = new predictionView

	func closeWindow 
		oView.win.close()
