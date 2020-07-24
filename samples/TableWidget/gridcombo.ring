Load "guilib.ring"

New qApp
{

    win1 = new qMainWindow()
    {
        setGeometry(100,100,1100,370)
        setwindowtitle("Using QTableWidget")

        Table1 = new qTableWidget(win1)
        {
            setrowcount(10) setcolumncount(10)
            setGeometry(0,0,800,400)

            setSelectionMode(QAbstractItemView_SelectItems)   

            for x = 1 to 10
                for y = 1 to 10
                    item1 = new qtablewidgetitem("R"+X+"C"+Y)
                    setitem(x-1,y-1, item1)
                next
            next

            cmb = new QComboBox(Table1)
            {
                alist = ["one","two","three","four","five"]
                for x in aList
                    additem(x,0)
                next
            }

           setCellWidget(5, 5, cmb)

        }

        setcentralwidget(table1)

           myfilter = new qallevents(win1)
           myfilter.setKeyPressEvent("pKeyPress()")
           installeventfilter(myfilter)

          show()
    }

    exec()

}

func pKeyPress
	nKeyCode = myfilter.getkeycode()
	#see "keycode " + nKeyCode +  nl
	if nKeyCode = 16777220
		Table1 { 
			if currentcolumn() = ColumnCount()-1
				setcurrentcell(currentrow()+1,  0)
			else
				setcurrentcell( currentrow() , currentcolumn() + 1)
			ok	
		}
	ok
