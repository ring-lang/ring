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



	func myT()
		new qTimer(oView.win){
			setInterval(1000)
			setTimeOutEvent(method(:inc))
			start()
		}



	func inc() oView.lcdNumber1{ Display( value()+1 ) }	

