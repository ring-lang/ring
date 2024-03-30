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
	oView.Image1.SetScaledContents( True )


	func btn1(){
		img = new pixMap( "ahmed.jpg" )
		oView.Image1.SetPixMap( img )
	}

	func btn2(){
		img = new pixMap( "egypt.jpg" )
		oView.Image1.SetPixMap( img )
	}
