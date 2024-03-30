# Form/Window Controller - Source Code File

load "buttonView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:buttonController)
		exec()
	}
}

class buttonController from windowsControllerParent

	oView = new buttonView

	func test 
		msginfo("Test","Remove button Image")
		oView.button1.setIcon(new qIcon(new qPixMap2(0,0)))
