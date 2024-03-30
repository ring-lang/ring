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


	func btnGetSelected_Click(){
		t.msgBox( "" + oView.ListWidget1.CurrentRow() )
	}

	func btnSetSelected_Click(){
		num = Number( oView.LineEdit1.Text() )
		oView.ListWidget1.SetCurrentRow( num , 3 )
	}

	func btnAdd_Click(){
		item = oView.LineEdit2.Text()
		oView.ListWidget1.AddItem( item )
	}

	func btnInsert_Click(){
		item = oView.LineEdit2.Text()
		oView.ListWidget1.InsertItem( 0 , item )
	}



