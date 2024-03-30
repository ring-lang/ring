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
	t = new FormTools( oView.win )
	t.center()
	#oView.combobox1.setEditable( true )

	func btnAddItems_Click()
		oView.combobox1.AddItem( "Cairo" , 0 )
		oView.combobox1.AddItem( "Giza" , 0 )
		oView.combobox1.AddItem( "Alex" , 0 )
		oView.combobox1.AddItem( "Aswan" , 0 )
		oView.combobox1.AddItem( "Loxur" , 0 )



	func btnRemove_Click()
		#oview.combobox1.RemoveItem( 1 )
		oview.combobox1.clear()


