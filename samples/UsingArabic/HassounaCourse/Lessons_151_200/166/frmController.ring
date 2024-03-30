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
	oView.txtPath.setReadOnly(True)

	func btnSelect_Click(){
		/*
		frm = oView.win
		myPath = ""
		new FileDialog( frm ){
			myPath = GetOpenFileName( frm , "Open File" , "Select" , "Image Files(*.jpg;*.png)" )
		}
		oView.txtPath.SetText( myPath )
		oView.Image1.setPixMap( new pixMap( myPath ) )
		*/
		/*
		myPath = t.OpenFileBox("Images(*.jpg;*.png)")
		oView.txtPath.SetText( myPath )
		oView.Image1.setPixMap( new pixMap( myPath ) )
		*/

		oView.Image1.setPixMap( new pixMap( t.OpenFileBox("Images(*.jpg;*.png)") ) )

	}

