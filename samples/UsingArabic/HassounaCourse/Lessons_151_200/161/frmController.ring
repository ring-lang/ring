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
	oView.cbxRing.setChecked( True )
	oView.cbxVB.setChecked( True )

	func btnGetSelected_Click(){
		strSelected = ""

		if oView.cbxJava.IsChecked() strSelected += "Java , " ok
		if oView.cbxCSharp.IsChecked() strSelected += "C Sharp , " ok
		if oView.cbxRing.IsChecked() strSelected += "Ring , " ok
		if oView.cbxVB.IsChecked() strSelected += "Visual Basic , " ok
		if oView.cbxPython.IsChecked() strSelected += "Python , " ok
		
		t.msgbox(strSelected)
	}

	func cbxJava_Clicked(){
		str = "Java - "
		if oView.cbxJava.IsChecked() str += "Checked" else str += "Unchecked" ok
		oView.lwHistory.AddItem( str )
	}

	func cbxCSharp_Clicked(){
		str = "C Sharp - "
		if oView.cbxCSharp.IsChecked() str += "Checked" else str += "Unchecked" ok
		oView.lwHistory.AddItem( str )
	}

	func cbxRing_Clicked(){
		str = "Ring - "
		if oView.cbxRing.IsChecked() str += "Checked" else str += "Unchecked" ok
		oView.lwHistory.AddItem( str )
	}

	func cbxVB_Clicked(){
		str = "Visual Basic - "
		if oView.cbxVB.IsChecked() str += "Checked" else str += "Unchecked" ok
		oView.lwHistory.AddItem( str )
	}

	func cbxPython_Clicked(){
		str = "Python - "
		if oView.cbxPython.IsChecked() str += "Checked" else str += "Unchecked" ok
		oView.lwHistory.AddItem( str )
	}
