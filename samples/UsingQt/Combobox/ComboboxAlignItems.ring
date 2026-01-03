load "guilib.ring"
new qApp { 

	win1 = new qWidget() { 

		setwindowtitle("Using QComboBox")
		setGeometry(100, 100, 400, 400)

		new QComboBox(win1) { 

			// If you want to center the selected item
			// setEditable(True)
			// lineEdit().setAlignment(Qt_AlignHCenter)
			// lineEdit().setReadOnly(True)

			setGeometry(150, 100, 200, 30)
			alist = ["one", "two", "three", "four", "five"]
			for x in aList 
				additem(x, 0)
			next 

			// Center items in the drop list 
			centerComboItems( self )

		}

		show()
	}

	exec()
}


func centerComboItems oComboBox 

	Qt_TextAlignmentRole = 7
	property = new QVariant2(Qt_AlignHCenter)

	oComboBox { 
		for t = 1 to count()
			setItemData(t-1, property, Qt_TextAlignmentRole)
		next 
	}
	