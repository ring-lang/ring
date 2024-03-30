# Form/Window Controller - Source Code File

load "frmView.ring"
load "hassounaLib.ring"

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
	t = new FormTools(oView.win)
	t.center()
	oView.Timer1.stop()

	func MoveToRight()
		oView.imgShip{ 
			move( x()+1 , y() ) 
		}
		if oView.imgShip.x()>=700 oView.Timer1.stop() ok 

	func myGo()
		oView.imgShip.move( 5 , oView.imgShip.y() )
		oView.Timer1.start()
