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
		frm = oView.win
		img = oView.image1
		winX = frm.x()
		winY = frm.y()
		frm.move( 3000 , 3000 )
		screen = frm.windowhandle().screen()
		img.setPixMap( screen.grabWindow( 0 , 0 , 0 , -1 , -1 ) )
		frm.move( winX , winY )
	}

	func btnSave_Click(){
		oView.Image1.pixMap().save( t.SaveFileDialog("JPG(*.jpg)") , "JPG" , 100 )
	}
