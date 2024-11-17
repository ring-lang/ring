# Form/Window Controller - Source Code File

load "archView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:archController)
		exec()
	}
}

class archController from windowsControllerParent

	oView = new archView

	? "Generate Image: output.png"

	oView.win {
		w = width()  h = height()
		grab( new QRect() { setWidth(w) setHeight(h) } ).save("output.png",NULL,0)
	}

