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
	#oView.ListWidget1.SetSelectionMode( 1 ) #الطبيعي
	#oView.ListWidget1.SetSelectionMode( 2 ) #تحديد متعدد بدون كترل
	oView.ListWidget1.SetSelectionMode( 3 ) #تحديد متعدد بالكترل

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

	func btnDeleteAll_Click(){
		oView.ListWidget1.Clear()
	}

	func btnRemove_Click(){
		num = Number( oView.LineEdit3.Text() )
		oView.ListWidget1.TakeItem( num )
	}

	func btnShowCount_Click(){
		t.msgbox( "" + oView.ListWidget1.Count() )
	}

	func btnGetSelectedName_Click(){
		crNo = oView.ListWidget1.CurrentRow()
		crText = oView.ListWidget1.Item( crNo ).Text()
		t.msgbox( crText )
	}

	func btnEdit_Click(){
		crNo = oView.ListWidget1.CurrentRow()
		NewText = oView.LineEdit4.Text()
		oView.ListWidget1.Item( crNo ).setText( NewText )
	}

	func btnSetSelected2_Click(){
		num = Number( oView.LineEdit1.Text() )
		oView.ListWidget1.Item( num ).setSelected( True )
	}




