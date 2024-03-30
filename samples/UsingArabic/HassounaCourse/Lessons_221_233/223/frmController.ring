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
	t.Center()
	oView.LCD_H.setDigitcount(2)
	oView.LCD_M.setDigitcount(2)

	func showDT() 
		h = number( timelist()[8] )
		m = number( timelist()[11] )
		a = timelist()[12]
		if oView.lblSecond.isVisible()
			oView.lblSecond.hide()
		else
			oView.lblSecond.show()
		ok
		oView.LCD_H.Display(h)
		oView.LCD_M.Display(m)
		oView.lblA.setText(a)

