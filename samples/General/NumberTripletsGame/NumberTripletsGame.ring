# Project : NUmber Tripéets Game
# Date    : 19/08/2021-06:30:09
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

C_GAMETITLE		= 'Number Triplets Game'
C_WINDOWBACKGROUND 	= "background-color: gray;"

if isMobile()
	C_LABELFONTSIZE 	= "font-size:120px;"
	C_BUTTONFONTSIZE 	= "font-size:160px;"
else 
	C_LABELFONTSIZE 	= "font-size:50px;"
	C_BUTTONFONTSIZE 	= "font-size:80px;"
ok

C_NEWGAMESTYLE		= 'color:magenta;background-color:rgb(50,50,50);border-radius:17px;' + C_LABELFONTSIZE
C_BUTTONTOP 	        = 'border-radius:17px;color:white; background-color: blue ;' + C_BUTTONFONTSIZE
C_BUTTONREDSTYLE 	= 'border-radius:17px;color:white; background-color: red ;' + C_BUTTONFONTSIZE
C_BUTTONSTYLE 	        = 'border-radius:17px;color:white; background-color: yellow ;' + C_BUTTONFONTSIZE
C_EMPTYBUTTONSTYLE      = 'border-radius:17px;color:black; background-color: white ;' + C_BUTTONFONTSIZE
C_BUTTONBLACKSTYLE      = 'border-radius:17px;color:black; background-color: black ;' + C_BUTTONFONTSIZE

C_LAYOUTSPACING		= 10

sizex	= 9
sizey	= 5
flag	= 0
x1	= 0
x2	= 0
y1	= 0
y2	= 0

button		= list(sizex,sizey)
LayoutButtonRow	= list(sizey)

app = new qApp {
	StyleFusion()
	processevents()
	win = new qWidget() {
		setWindowTitle(C_GAMETITLE)
		setgeometry(100,100,800,600)
		setminimumwidth(300)
		setminimumheight(300)
		if not isMobile()
			grabkeyboard()
		ok
		setstylesheet(C_WINDOWBACKGROUND)
		move(490,100) 
		newgame = new QLabel(win) {
			setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
			setstylesheet(C_NEWGAMESTYLE)
			settext('New Game')
			myfilter4 = new qallevents(newgame)
			myfilter4.setMouseButtonPressEvent("pbegin()")
			installeventfilter(myfilter4)
		}
		for n = 1 to sizex
			for m = 1 to sizey
				button[n][m] = new QPushButton(win)
			next
		next
		LayoutGrid = new QGridLayout() {
			setSpacing(C_LAYOUTSPACING)
			for n = 1 to sizey
				for m = 1 to sizex
					AddWidget(button[m][n],n-1,m-1,0)
				next
			next
		}
		LayoutButtonMain = new QVBoxLayout() {
			AddLayout(LayoutGrid)
			AddWidget(newGame)
		}
		setLayout(LayoutButtonMain)
		show()
		pbegin()  
	}
	exec()
}

func pbegin
	flag = 0
	for n = 1 to sizex
		for m = 1 to sizey
			if n%2 = 1  
				button[n][m].setstylesheet(C_EMPTYBUTTONSTYLE)
				button[n][m].setenabled(false)
			else
				button[n][m].setstylesheet(C_BUTTONSTYLE)
			ok
			if n = 1 or n = 9 or m = 1 
				button[n][m].setstylesheet(C_EMPTYBUTTONSTYLE) 
				button[n][m].setenabled(false)              
				button[n][m].settext('')
			ok
			if m = 1  
				button[n][m].setstylesheet(C_BUTTONTOP) 
				button[n][m].setenabled(true)              
				button[n][m].settext('')
			ok
			button[n][m] { setclickevent("keypress(" + string(n) + "," + string(m) + ")") }
		next
	next

	for row = 2 to sizey
		button[1][row].setstylesheet(C_BUTTONBLACKSTYLE)
		button[9][row].setstylesheet(C_BUTTONBLACKSTYLE)
	next

	numRand = list(4)
	pRandom()

func pRandom
	for n = 1 to sizex
		for m = 1 to sizey
			button[n][m].settext("")
		next
	next
	checkNum = []
	randNum = list(4)
	for p = 1 to 4
		randNum[p] = 0
	next
	while true
		xRand = random(sizex-1) + 1
		yRand = random(sizey-1) + 1
		numRand = random(3)+1
		str = " "
		if xRand%2 = 0 and yRand != 1
			if randNum[numRand] < 3
				numStr = string(xRand)+string(yRand)
				ind = find(checkNum,numStr)
				if ind < 1
					add(checkNum,numStr)
					temp = randNum[numRand]
					randNum[numRand] = temp + 1
					button[xRand][yRand].settext(str+string(numRand)+str)
					button[xRand][yRand].setstylesheet(C_BUTTONREDSTYLE) 
				ok
			ok
		ok
		if randNum[1] = 3 and randNum[2] = 3 and randNum[3] = 3 and randNum[4] = 3
			exit 
		ok
	end

func keyPress x,y
	flag++
	switch flag
	on 1
		x1 = x
		y1 = y
	on 2
		x2 = x
		y2 = y
		flag = 0
		pMove(x1,y1,x2,y2)
	off
        
func pMove col1,row1,col2,row2
	if col1!=0 and col2!=0 and row1!=0 and row2!=0 
		if ( col1=col2 and row2=row1+1 and col1%2=0 ) or
		   ( col1=col2 and row2=row1-1 and col1%2=0 ) or 
		   ( row1=row2 and col2=col1+1 and row1=1   ) or 
		   ( row1=row2 and col2=col1-1 and row1=1   ) or 
		   ( row1=row2 and col2=col1-1 and row1=1   )

			temp = button[col1][row1].text()
			if temp!= ""
				button[col2][row2].setstylesheet(C_BUTTONREDSTYLE)
				button[col2][row2].settext(temp)
				if row1 = 1
					button[col1][row1].setstylesheet(C_BUTTONTOP)              
				else
					button[col1][row1].setstylesheet(C_BUTTONSTYLE)
				ok
				button[col1][row1].settext("") 
			ok
		ok   
	ok
