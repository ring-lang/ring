# Project : Ascii Table
# Date    : 03/11/2019-16:00:00
# Update  : 03/11/2019-18:00:00
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : quiwox@gmail.com

load "lightguilib.ring"

size  = 16
table = null

app = new QApp {

	styleFusion()

	win = new QWidget() {
		setWinIcon(win,"ascii.png")
		setWindowTitle('ASCII Table')
		resize(900,400)
		setstylesheet('background-color:white')
		oTable = pInit()	    
		showAsciiTable()

		btnClose = new QPushButton(win) { 
			setText("Close") 
			setClickevent("win.close()") 
		}

		oLayout = new QVBoxlayout() {
			addWidget(oTable)
			addWidget(btnClose)
		}
		setLayout(oLayout)

		show()

	}

	exec()

}

func showAsciiTable

	for n = 33 to 125
		row = floor(n/size)
		col = (n % size)
		temp = row * size + col
		item = new qTableWidgetItem(char(temp))
		Table.setitem(row,col,item)
	next

func pInit()

	Table = new qtablewidget(win) {
		move(150,40)
		resize(580,270)
		setcolumncount(16) 
		setrowcount(8)
		setcellClickedEvent("pDec()")

		for x = 1 to Table.rowcount()
			for y = 1 to Table.columncount()
				item1 = new qtablewidgetitem("")
				Table.setitem(x-1,y-1, item1)
			next
		next

		for n = 1 to size+1
			setColumnwidth(n-1,30)
		next

		hex = ["A","B","C","D","E","F"]

		for n = 0 to size - 6
			setHorizontalHeaderItem(n, new QTableWidgetItem(string(n)))
		next

		for n = 10 to size -1
			setHorizontalHeaderItem(n, new QTableWidgetItem(hex[n-9]))
		next

		for n = 0 to 7
			setVerticalHeaderItem(n, new QTableWidgetItem(string(n)))
		next

		show()
	}

	return Table

func pDec

	row  = Table.currentrow()
	col  = Table.currentcolumn()
	temp = row * size + col
	if temp > 32 and temp < 126
		msgbox("The decimal value of " + char(temp) + " = " + temp)
	ok

func msgBox cText
	  
	mb = new qMessageBox(win) {
		setWindowTitle('ASCII Table')
		setText(cText)
		setstandardbuttons(QMessageBox_OK) 
		result = exec() 
	}
