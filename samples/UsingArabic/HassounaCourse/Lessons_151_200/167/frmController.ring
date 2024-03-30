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

	func btnSave_Click(){
		frm = oView.win
		myPath = ""
		new FileDialog( frm ){
			myPath = GetSaveFileName( frm , "Save File" , "my" , "Images(*.jpg;*.png);;All(*.*)" )
		}
		if myPath = ""
			t.msgBox("Empty")
		else
			oView.Image1.pixMap().save( myPath , "JPG" , 100 )
		ok
	}
