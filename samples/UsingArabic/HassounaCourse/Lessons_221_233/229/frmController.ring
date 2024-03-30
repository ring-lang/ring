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
	oView.Timer1.stop()

	func MoveUp()
		oView.imgRocket{ 
			move( x() , y()-1 ) 
			if y()<-160 move( x() , 550 ) ok 
		}

	func StartMove() oView.Timer1.start()

	func StopMove() oView.Timer1.stop()

	func SetSpeed() oView{ Timer1.setInterval( spinBox1.value() ) } 
