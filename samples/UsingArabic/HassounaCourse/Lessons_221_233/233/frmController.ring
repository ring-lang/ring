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

	func GetAction()
		if GetRandom(1,2)=1 return "+"
		else return "-" 
		ok

	func MoveNow()
		actionX = GetAction()
		actionY = GetAction()
		oView.img2{
			if x() > 700 move( 700 , y() ) ok
			if x() < 5   move( 5 , y() ) ok
			if y() > 370 move( x() , 370 ) ok
			if y() < 5   move( x() , 5 ) ok

			if actionX="+" move( x()+GetRandom(1,3) , y() ) ok
			if actionY="+" move( x() , y()+GetRandom(1,3)) ok
			if actionX="-" move( x()-GetRandom(1,3) , y() ) ok
			if actionY="-" move( x() , y()-GetRandom(1,3)) ok
		}



