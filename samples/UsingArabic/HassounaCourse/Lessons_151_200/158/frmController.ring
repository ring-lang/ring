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

	func btnGetSelectedItems_Click(){
		SelectedItems = ""
		for x=1 to oView.ListWidget1.Count()
			if oView.ListWidget1.Item( x ).IsSelected()
				SelectedItems += oView.ListWidget1.Item( x ).Text() + " , "
			ok
		next
		t.msgbox(SelectedItems)
	}

	func btnFill_Click(){
		names = [ "Ahmed","Adel","Ehab","Eslam","Amr","Omar","Mahmoud","Yaser" ]
		for x=1 to len(names)
			oView.ListWidget1.AddItem( names[x] )
		next
	}

	func btnFill2_Click(){
		for x=2000 to 2019
			oView.ListWidget1.AddItem( "Year " + x )
		next 
	}

	func btnFill3_Click(){
		t.FillListWidget( oView.ListWidget1 , ["A","B","C","D","E","F"] )
	}


