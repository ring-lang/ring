# Author: Gal Zsolt

load "stdlib.ring"
load "lightguilib.ring"

size      = 10
Table     = null
a2DSquare = list(size,size)
a2DFinal  = list(size,size)

app = new QApp {

        aList  = 1:size
    	aList2 = RandomList(aList)

       	GenerateRows(aList2)
	ShuffleCols(a2DSquare,a2DFinal)

	DisplaySquare(a2DFinal,app)
        latsum()
    		
	win = new QWidget() {
		setWinIcon(win,"ascii.png")
		setWindowTitle('Latin Squares')
		resize(430,400)
		setstylesheet('background-color:white')

		btnClose = new QPushButton(win) { 
			setText("Close") 
			setClickevent("win.close()") 
		}

		oLayout = new QVBoxlayout() {
			addWidget(Table)
			addWidget(btnClose)
		}
		setLayout(oLayout)

		show()

	}

	exec()

}

Func GenerateRows(aInput)

	aOutput = []
	size  = len(aInput)
        shift = 1

	for k = 1 to size									// Make 8 Rows of lists
		aOutput = []
		
		for i = 1 to size           			// make a list
			   pick = i + shift     		// shift every Row by +1 more
			if pick > size   pick = pick - size  ok
	
			aOutput + aInput[pick]
		next
	
		a2DSquare[k] = aOutput				// Row of Output to a2DSquare

		shift++                    			// shift next line by +1 more
		if shift > size  shift = 1 ok
	next

return

Func ShuffleCols(a2DSquare,a2DFinal)

	aSuffle  = 1:size
        aSuffle2 = RandomList(aSuffle)	// Pick random Col to insert in a2DFinal
	
	for i = 1 to size           	// Row		
		pick = aSuffle2[i]

        for j = 1 to size		// Col
			a2DFinal[i][j] =  a2DSquare[pick][j]  // i-Row-Col j-Horz-Vert
		next
	next

	a2DSquare = a2DFinal		// Now do the verticals
	aSuffle  = 1:size
	aSuffle2 = RandomList(aSuffle)

	for i = 1 to size           				// Row	
		pick = aSuffle2[i]
        	for j = 1 to size				// Col
			a2DFinal[j][i] =  a2DSquare[j][pick]  	//Reverse i-j i-Row-Col j-Horz-Vert
		next
	next

return

Func DisplaySquare(a2DSquare,win)

		Table = pInit(win)
                Table.verticalHeader().setStyleSheet("color: red")
                Table.horizontalHeader().setStyleSheet("color: red")
                Table.setAlternatingRowColors(true)	
		for x = 1 to Table.rowcount()
			for y = 1 to Table.columncount()
                                output = string(a2DSquare[x][y])
				item1 = new qtablewidgetitem(output)
				Table.setitem(x-1,y-1,item1)
                                Table.item(x-1,y-1).setTextAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
			next
		next

return

func pInit(win)

	Table = new qtablewidget(win) {

		move(150,40)
		resize(580,270)
		setcolumncount(10) 
		setrowcount(10)

		for x = 1 to Table.rowcount()
			for y = 1 to Table.columncount()
				item1 = new qtablewidgetitem("")
				Table.setitem(x-1,y-1,item1)
			next
		next

		for n = 1 to size+1
			setColumnwidth(n-1,30)
		next

		for n = 0 to 10
			setVerticalHeaderItem(n,new QTableWidgetItem(string(n)))
		next

		show()
	}

	return Table



func msgBox cText
	  
	mb = new qMessageBox(win) {
		setWindowTitle('ASCII Table')
		setText(cText)
		setstandardbuttons(QMessageBox_OK) 
		result = exec() 
	}

func latsum()

	for n = 1 to 10
		sum = 0
		for m = 1 to 10
			sum = sum + a2DSquare[n][m]
		next
		see "row " + string(n) + " = " + sum + nl
	next
	see nl

	for n = 1 to 10
		sum = 0
		for m = 1 to 10
			sum = sum + a2DSquare[m][n]
		next
		see "column " + string(n) + " = " + sum + nl
	next
