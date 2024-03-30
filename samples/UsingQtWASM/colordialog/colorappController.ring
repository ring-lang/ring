# Form/Window Controller - Source Code File

load "colorappView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:colorappController)
		exec()
	}
}

class colorappController from windowsControllerParent

	oView = new colorappView
	
	oColor = new QColorDialog() {
		setcolorselectedevent(Method(:newcolor))
	}

	func setcolor 
		oColor.show()

	func newcolor 
		oNewColor = oColor.selectedcolor()
		r = oNewColor.red()
		g = oNewColor.green()
		b = oNewColor.blue()
		oView.win.setstylesheet("background-color: rgb("+r+", " + g+ "," + b + ")")
