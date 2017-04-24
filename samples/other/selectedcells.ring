Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setGeometry(100,100,800,600)
                setwindowtitle("Using QTableWidget")

                Table1 = new qTableWidget(win1) {

                        setrowcount(10) setcolumncount(10)
                        setGeometry(10,10,400,400)

                        for x = 1 to 10
                                for y = 1 to 10
                                        item1 = new qtablewidgetitem("10")
                                        setitem(x-1,y-1,item1)
                                next
                        next

                }

	btn1 = new qPushButton(win1) {
		setText("Increase")	
		setGeometry(510,10,100,30)
		setClickEvent("pClick()")
	}

             show()

        }

        exec()
}

func pClick

	for nRow = 0 to Table1.rowcount() - 1
		for nCol = 0 to Table1.columncount() - 1
			Table1.item(nRow,nCol)  {
				if isSelected() 
					setText( "" + ( 10 + text()) ) 
				ok
			}
		next
	next
