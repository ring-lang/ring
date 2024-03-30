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
	t = new FormTools(oView.win)
	t.center()

	func inc() oView.LCDNumber1{ Display( value()+1 ) }

	func dec() oView.LCDNumber1{ Display( value()-1 ) }


		//t.msgbox( "" + oView.lcdnumber1.value() )
		//oView.lcdNumber1.Display(199)
		





