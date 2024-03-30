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

	func btnSelect_Click(){
		#oView.Image1.setPixMap( new pixMap( t.OpenFileDialog("Images(*.jpg;*.png)") ) )
		oView.Image1.setPixMap( new pixMap( t.OpenFileDialog(["jpg","png","bmp"]) ) )
	}

	func btnSave_Click(){
		#oView.Image1.pixMap().save( t.SaveFileDialog("JPG(*.jpg)") , "JPG" , 100 )
		oView.Image1.pixMap().save( t.SaveFileDialog(["jpg","png","bmp"]) , "JPG" , 100 )
	}
