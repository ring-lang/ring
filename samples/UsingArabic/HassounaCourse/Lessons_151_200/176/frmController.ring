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
	load "hassounaLib.ring"
	t = new FormTools( oView.win )
	t.center()

	func GetVal(){
		oView.lblVal.setText( "" + oView.Slider1.Value() )
		oView.ProgressBar1.setValue( oView.Slider1.Value() )
		oView.ProgressBar2.setValue( oView.Slider1.Value() )
	}



