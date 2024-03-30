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
		/*
		frm = oView.win
		img = oView.image1
		frmRect = new Rect()
		frmRect.Adjust( 0 , 0 , frm.width() , frm.height() )
		frmPixMap = frm.Grab( frmRect )
		img.setPixMap( frmpixMap )
		*/

		frm = oView.win
		img = oView.image1
		img.setPixMap( frm.grab( new rect(){ adjust( 0, 0, frm.width(), frm.height() ) } ) )

	}

	func btnSave_Click(){
		oView.Image1.pixMap().save( t.SaveFileDialog("JPG(*.jpg)") , "JPG" , 100 )
	}
