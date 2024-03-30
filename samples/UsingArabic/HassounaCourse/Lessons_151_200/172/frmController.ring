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
	oView.Image1.SetScaledContents(True)
	t.Center()

	func btnTakeScreenshot_Click(){
		oView.image1.setPixMap( t.GetScreenShot() )
	}
 
	func btnSave_Click(){
		oView.Image1.pixMap().save( t.SaveFileDialog("JPG(*.jpg)") , "JPG" , 100 )
	}
