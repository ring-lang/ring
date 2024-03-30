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
	t.center()

	func test()
		/*
		if t.MsgBoxYesNo("Do you want?")
			oView.lbl.setText("Yes") 
		else
			oView.lbl.setText("No") 
		ok
		*/

		//msgInfo("Title","Message")

		/*
		myVar = confirmMsg("Title","Do you want?")
		oView.lbl.setText( "" + myVar )
		*/

		/*
		myVar = inputBox("Title","Enter Name:")
		oView.lbl.setText( "" + myVar )
		*/

		/*
		myVar = inputBoxNum("Title","Enter Double Number:")
		oView.lbl.setText( "" + myVar )		
		*/

		/*
		myVar = inputBoxInt("Title","Enter Integer Number:")
		oView.lbl.setText( "" + myVar )		
		*/

		
		myVar = inputBoxPass("Title","Enter Password")
		oView.lbl.setText( "" + myVar )		
		





