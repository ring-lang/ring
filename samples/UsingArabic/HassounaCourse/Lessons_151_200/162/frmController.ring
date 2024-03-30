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

	oView.cbxJava.SetCheckState( True )
	oView.cbxCSharp.SetCheckState( True )
	oView.cbxRing.SetCheckState( True )
	oView.cbxVB.SetCheckState( True )
	oView.cbxPython.SetCheckState( True )

	oView.cbxRing.SetCheckState( 2 )
	oView.cbxVB.SetCheckState( 0 )

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
		state = oView.cbxJava.CheckState()
		if state=0 str += "Unchecked"
		but state=1 str+= "Indeterminate" 
		else  str += "Checked" 
		ok
		oView.lwHistory.AddItem( str )
	}

	func cbxCSharp_Clicked(){
		str = "C Sharp - "
		state = oView.cbxCSharp.CheckState()
		if state=0 str += "Unchecked"
		but state=1 str+= "Indeterminate" 
		else  str += "Checked" 
		ok
		oView.lwHistory.AddItem( str )
	}

	func cbxRing_Clicked(){
		str = "Ring - "
		state = oView.cbxRing.CheckState()
		if state=0 str += "Unchecked"
		but state=1 str+= "Indeterminate" 
		else  str += "Checked" 
		ok
		oView.lwHistory.AddItem( str )
	}

	func cbxVB_Clicked(){
		str = "Visual Basic - "
		state = oView.cbxVB.CheckState()
		if state=0 str += "Unchecked"
		but state=1 str+= "Indeterminate" 
		else  str += "Checked" 
		ok
		oView.lwHistory.AddItem( str )
	}

	func cbxPython_Clicked(){
		str = "Python - "
		state = oView.cbxPython.CheckState()
		if state=0 str += "Unchecked"
		but state=1 str+= "Indeterminate" 
		else  str += "Checked" 
		ok
		oView.lwHistory.AddItem( str )
	}
