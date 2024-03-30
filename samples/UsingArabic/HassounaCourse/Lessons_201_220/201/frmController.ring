# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView

	func SelectColor()
		myColor = new qColorDialog()
		c = myColor.GetColor()
		r=c[1] g=c[2] b=c[3]
		rgb = "rgb(" + r + "," + g + "," + b + ")"
		oView.LineEdit1.setStylesheet("background:"+rgb)
