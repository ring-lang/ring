# Project : Random Latin Squares 
# Date    : 29/07/2020-23:20:56
# Author  : Gal Zsolt (CalmoSoft)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

###====================================================================================

list    = 1:5
lenList = len(list)
per= list(factorial(lenList),lenList)
permut  = []

permut()

lenPer  = len(per)

size= lenList
nrCells   = 6
C_SPACING = 1
checkRC   = 0
Button= list(size,size)
LayoutButtonRow= list(size)
C_ButtonOrangeStyle = 'border-radius:1x;color:black; background-color: orange'

###====================================================================================

MyApp = New qApp {

	StyleFusion()

	win = new qWidget() {

		desktop = new QDesktopWidget()
		workHeight = win.height()
		fontSize = 8 + (workHeight / 50)

		setwindowtitle("Random Latin Squares")
		move(555,175)
		resize(200,200)

		myfilter = new qallevents(win) 
		myfilter.setResizeEvent("resizeBoard()")
		installeventfilter(myfilter)

		LayoutButtonMain = new QVBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(50,50,50,50) 
		}

		LayoutButtonStart = new QHBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(0,0,0,0)
		}

		btnStart = new QPushButton(win) {
			setFont(new qFont("Calibri",fontsize,2100,0))
			setMinimumWidth(desktop.Width() * 0.05)
			setMinimumHeight(desktop.Height() * 0.05)
			settext(" Start ")
			setstylesheet(C_ButtonOrangeStyle)
			setclickevent("gameSolution()")
		}

		sizeBtn = new QPushButton(win) 
		{
			setFont(new qFont("Calibri",fontsize,2100,0))
			setMinimumWidth(desktop.Width() * 0.1)
			setMinimumHeight(desktop.Height() * 0.05)
			setStyleSheet("background-color:rgb(255,255,204)")  
			setText(" Enter size: ")
			setClickEvent("newBoardSize()")
		}	

		lineSize = new qLineEdit(win) 
		{
			setFont(new qFont("Calibri",fontsize,2100,0))
			setMinimumWidth(desktop.Width() * 0.05)
			setMinimumHeight(desktop.Height() * 0.05)
			setStyleSheet("background-color:rgb(255,255,204)")
			setAlignment( Qt_AlignHCenter)
			setAlignment( Qt_AlignVCenter)
			setreturnPressedEvent("newBoardSize()")
			setText(" 5 ")
		}

		btnExit = new QPushButton(win) {
			setFont(new qFont("Calibri",fontsize,2100,0))
			setMinimumWidth(desktop.Width() * 0.05)
			setMinimumHeight(desktop.Height() * 0.05)
			settext(" Exit ")
			setstylesheet(C_ButtonOrangeStyle)
			setclickevent("pExit()")
		}

		LayoutButtonStart.AddWidget(btnStart)
		LayoutButtonStart.AddWidget(sizeBtn)
		LayoutButtonStart.AddWidget(lineSize)
		LayoutButtonStart.AddWidget(btnExit)
	
		LayoutButtonMain.AddLayout(LayoutButtonStart)

		for Row = 1 to size

			LayoutButtonRow[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}

			for Col = 1 to size
				Button[Row][Col] = new QPushButton(win) {
					setFont(new qFont("Calibri",fontsize,2100,0))
					setMinimumWidth(desktop.Width() * 0.05)
					setMinimumHeight(desktop.Height() * 0.05)
				} 
				LayoutButtonRow[Row].AddWidget(Button[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow[Row])

		next

		setLayout(LayoutButtonMain)

		 show()

	}

	exec()
}

###====================================================================================

func newBoardSize()

	nrSize = number(lineSize.text())
	if nrSize > nrCells or nrSize < 2
		? "Enter a number in range: 2-6"
		return
	ok
	list    = 1: nrSize
	lenList = len(list)
	per= list(factorial(lenList),lenList)
	permut  = []

	permut()

	lenPer  = len(per)

	newWindow(nrSize)
	for Row = 1 to size
		for Col = 1 to size
			Button[Row][Col].settext("")
		next
	next

###====================================================================================

func newWindow(newSize)

	for Row = 1 to size
		for Col = 1 to size
			Button[Row][Col].delete()
		next
	next

	size = newSize
 
	LayoutButtonStart = new QHBoxLayout() {
		setSpacing(C_SPACING)
		setContentsmargins(0,0,0,0)
	}

	LayoutButtonMsg = new QHBoxLayout() {
		setSpacing(C_SPACING)
		setContentsmargins(0,0,0,0)
	}

	Button = list(size,size)
	LayoutButtonRow = list(size)

	for Row = 1 to size

		LayoutButtonRow[Row] = new QHBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(0,0,0,0)
		}

		for Col = 1 to size

			Button[Row][Col] = new QPushButton(win) {
				setFont(new qFont("Calibri",fontsize,2100,0))
				setMinimumWidth(desktop.Width() * 0.05)
				setMinimumHeight(desktop.Height() * 0.05)
			}
			LayoutButtonRow[Row].AddWidget(Button[Row][Col])

		next

		LayoutButtonMain.AddLayout(LayoutButtonRow[Row])

	next

	win.setLayout(LayoutButtonMain)

	for Row = 1 to size
		for Col = 1 to size
			Button[Row][Col].settext("")
		 next
	next

###====================================================================================

func checkBoard(cRow,cCol,cRnd)

	checkRow = 1
	checkCol = 1
	for Col = 1 to size 
		if Col != cCol
			if Button[cRow][Col].text() = cRnd
				checkRow = 0
				exit
			ok
		ok 
	next

	for Row = 1 to size 
		if Row != cRow
			if Button[Row][cCol].text() = cRnd
				checkCol = 0
				exit
			ok
		ok 
	next
	checkRC = checkRow and checkCol

###====================================================================================

func resizeBoard

	bwidth  = (win.width() - 8) / size    
	bheight = (win.height() - 32) / size   

	for Row = 1 to size
		for Col = 1 to size
			Button[Row][Col].resize(bwidth-8,bheight-8)
		next
	next

###====================================================================================

Func pExit

	MyApp.quit()

###====================================================================================

func perm a

	elementcount = len(a)
	if elementcount < 1 
		return
	ok
	pos = elementcount-1
	while a[pos] >= a[pos+1] 
		pos = pos - 1
		if pos <= 0
			permutationReverse(a,1,elementcount)
			return
		ok
	end
	last = elementcount
	while a[last] <= a[pos]
		last = last - 1
	end
	temp = a[pos]
	a[pos] = a[last]
	a[last] = temp
	permReverse(a, pos+1, elementcount)

###====================================================================================
 
func permReverse a, first, last

	while first < last
		temp = a[first]
		a[first] = a[last]
		a[last] = temp
		first = first + 1
		last = last - 1
	end

###====================================================================================

func permut

	for perm = 1 to factorial(lenlist)
		for i = 1 to len(list)
			add(permut,list[i])
		next
		perm(list)
	next

	for n = 1 to len(permut)
		ind1 = ceil(n/lenList)
		ind2 = n % lenList
		if ind2 = 0
			ind2 = lenList 
		ok
		per[ind1][ind2] = permut[n]
	next

###====================================================================================

func gameSolution()

	for nRow = 1 to size 
		for nCol = 1 to size
			Button[nRow][nCol].settext("-")
		next 
	next

	for nRow = 1 to size
		for nCol = 1 to size
			if nCol = 1
				rnd = random(len(per)-1)+1
			ok
			val = per[rnd][nCol]
			checkBoard(nRow,nCol,val)
			if checkRC = 1
				Button[nRow][nCol].settext(string(val))
			ok
			if checkRC = 0
				nCol = 0
				for y = 1 to size
					Button[nRow][y].settext("-")
				next
			ok
		next
	next

###====================================================================================

