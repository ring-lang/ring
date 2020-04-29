# Project : CalmoSoft Pairs Game
# Date    : 28/04/2020-14:23:16
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : <calmosoft@gmail.com>

#===================================================================================#
# Load the required libraries 
#===================================================================================#

	load "stdlib.ring"
	load "guilib.ring"

#===================================================================================#
# Define variables & constants
#===================================================================================#

	size1		= 6
	size2		= 6
	width		= 50
	height		= 50
	
	xWidth		= 600
	yHeight		= 600   
	
	C_SPACING	= 1
	C_FONTSIZE	= 15
	
	Pair1 		= 0
	Pair2		= 0
	PairOld		= 0
	row1		= 0
	row2		= 0
	col1		= 0
	col2		= 0
	click		= 0
	score		= 0
	time1		= 0
	time2		= 0
	move		= 0
	
	C_EMPTY		= "images/empty.png"
	C_COVER		= "images/cover.png"
	C_P1		= "images/p1.png"
	C_P2		= "images/p2.png"
	C_P3		= "images/p3.png"
	C_P4		= "images/p4.png"
	C_P5		= "images/p5.png"
	C_P6		= "images/p6.png"
	C_P7		= "images/p7.png"
	C_P8		= "images/p8.png"
	C_P9		= "images/p9.png"
	C_P10		= "images/p10.png"
	C_P11		= "images/p11.png"
	C_P12		= "images/p12.png"
	C_P13		= "images/p13.png"
	C_P14		= "images/p14.png"
	C_P15		= "images/p15.png"
	C_P16		= "images/p16.png"
	C_P17		= "images/p17.png"
	C_P18		= "images/p18.png"
	
	PLIST		= [
				C_P1,C_P2,C_P3,C_P4,C_P5,C_P6,C_P7,C_P8,C_P9,
				C_P10,C_P11,C_P12,C_P13,C_P14,C_P15,C_P16,C_P17,C_P18,
				C_P1,C_P2,C_P3,C_P4,C_P5,C_P6,C_P7,C_P8,C_P9,
				C_P10,C_P11,C_P12,C_P13,C_P14,C_P15,C_P16,C_P17,C_P18
			  ]
	
	limit		= len(PLIST)
	
	Pairs		= newlist(size1,size2)
	Pairs2		= newlist(size1,size2)
	Button		= newlist(size1,size2)
	PairsXY		= newlist(limit,2)
	Pairs6		= list(limit)
	PairsList	= list(limit)
	PairsRand	= []
	Tiles		= list(size2+1)
	TilesRow	= list(size1)
	
	LayoutButtonRow2= list(size1)

#===================================================================================#
# The User Interface (Game Window and Buttons)	
#===================================================================================#

app = new qApp {

	StyleFusion()

	win = new qWidget() {

		setWindowTitle('CalmoSoft Pairs Game')
		setWinIcon(self,"images/cover.png")
		reSize(xWidth, yHeight)
		setStyleSheet("background-image:url('images/background.jpg');")

		LayoutButtonMain = new QVBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(50,50,50,50) 
		}

		LayoutButtonRow1 = new QHBoxLayout()
		LayoutButtonRow3 = new QHBoxLayout()
		LayoutButtonRow4 = new QHBoxLayout()
		LayoutButtonRow5 = new QHBoxLayout()
		LayoutButtonRow6 = new QHBoxLayout()
		
		labelEmpty1 = new QLabel(win)
		labelEmpty2 = new QLabel(win)
		
		labelTime = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext(" Time: ") 
		}

		labelShowTime = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0)) 
		}

		labelMove = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Move: ")
		}

		labelShowMove = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0)) 
		}

		LayoutButtonRow5.AddWidget(labelEmpty1)

		LayoutButtonMain { 
			AddLayout(LayoutButtonRow1)
			AddLayout(LayoutButtonRow5)
			AddLayout(LayoutButtonRow4)
		}

		for Row = 1 to size1
			LayoutButtonRow2[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}
			for Col = 1 to size2
				Button[Row][Col] = new QPushButton(win) {
					setSizePolicy(1,1)
					setclickevent("pPairsClick(" + string(Row) + "," + string(Col) + ")")
					seticon(new qicon(new qpixmap(C_COVER)))  
					setIconSize(new qSize(100,75))	                    
					setMaximumWidth(100)
					setMaximumHeight(75)
				}
				LayoutButtonRow2[Row].AddWidget(Button[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow2[Row])
		next

		buttonNewGame = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("New")
			setClickEvent("pNewGame()") 
		}

		buttonExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Exit")
			setClickEvent("pQuit()") 
		}

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("           Score:")
		}

		labelNumScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("0")
		}

		LayoutButtonRow6.AddWidget(labelEmpty2)

		LayoutButtonMain.AddLayout(LayoutButtonRow6)

		LayoutButtonRow1 {
			AddWidget(labelTime)
			AddWidget(labelShowTime)
			AddWidget(labelMove)
			AddWidget(labelShowMove)
		}

		LayoutButtonRow3 {
			AddWidget(buttonNewGame)
			AddWidget(labelScore)
			AddWidget(labelNumScore)
			AddWidget(buttonExit)
		}

		LayoutButtonMain.AddLayout(LayoutButtonRow3)

		setLayout(LayoutButtonMain)

		TimerMan = new qTimer(win) {
			time1 = clock()
			setInterval(1000)
			setTimeoutEvent("pTimerMan()")  ### ==>> Func
			start()
		}
		
		pRandomPairs()
		show()

	}

	exec()

}

#===================================================================================#
# Game Logic
#===================================================================================#

func pTimerMan

	nowTime    = ceil( (clock() - time1) / 1000 )
	nowMinute  = floor( nowTime / 60 )
	nowSeconds = nowTime % 60
        
	if nowSeconds < 10  
		nowSeconds = "0"+ nowSeconds
	ok

	nowMinSec  = ""+ nowMinute +":"+ nowSeconds        
	labelShowTime.setText(nowMinSec)      


func pNewGame

	labelShowTime.setText("0:00")
	time1 = clock()
	TimerMan.start()
	move = 0
	labelShowMove.settext("0")
	PairsXY = newlist(limit,2)
	pRandomPairs()

func pRandomPairs

	PLIST	= [
			C_P1,C_P2,C_P3,C_P4,C_P5,C_P6,C_P7,C_P8,C_P9,
			C_P10,C_P11,C_P12,C_P13,C_P14,C_P15,C_P16,C_P17,C_P18,
			C_P1,C_P2,C_P3,C_P4,C_P5,C_P6,C_P7,C_P8,C_P9,
			C_P10,C_P11,C_P12,C_P13,C_P14,C_P15,C_P16,C_P17,C_P18
		  ]
	PairsList	= randomList(PLIST)
	randList	= 1:len(PairsList)
	randList	= randomList(randList)

	for n = 1 to size1
		for m = 1 to size2
			ind = (n-1)*6 + m
			PairsXY[ind][1] = n
			PairsXY[ind][2] = m
		next
	next

	for nr = 1 to limit
		rand1 = random(len(randList)-1)+1
		if len(randList) = 1
			rand1 = 1
		ok
		rand2 = randList[rand1]
		pairsNew = PairsList[nr]
		row = pairsXY[rand1][1]
		col = pairsXY[rand1][2]
		Pairs[row][col] = pairsNew
		Button[row][col].setenabled(true)
		Button[row][col] {
			seticon(new qicon(new qpixmap(C_COVER)))                        
			setIconSize(new qSize(100,100)) 
		}
		del(PairsXY,rand1)
		del(randList,rand1)
	next
	Pairs2 = Pairs

func pPairsClick Row,Col

	click++
	if click = 1
		Pair1 = Pairs[Row][Col]    
		row1 = Row
		col1 = Col
		Button[Row][Col]{
			seticon(new qicon(new qpixmap(Pair1)))
			setIconSize(new qSize(100,100)) show() 
		}
		if (row2 > 0) and (col2 > 0) and (Pair2 != PairOld)
			Button[row2][col2] {
				seticon(new qicon(new qpixmap(C_COVER)))
				setIconSize(new qSize(100,100)) 
				show()
			} 
		ok   
		return
	else
		Pair2 = Pairs[Row][Col]
		row2 = Row
		col2 = Col
		Button[Row][Col] { 
			seticon(new qicon(new qpixmap(Pair2)))
			setIconSize(new qSize(100,100))
			show() 
		}
		app.processevents()
		sleep(0.5)
		Button[Row][Col] {
			seticon(new qicon(new qpixmap(C_COVER)))
			setIconSize(new qSize(100,100))
			show()
		}
	ok
	if (Pair1 = Pair2) and (click = 2) and not(row1=row2 and col1=col2)
		PairOld = Pair1
		Button[row1][col1] { 
			seticon(new qicon(new qpixmap(Pair1)))
			setIconSize(new qSize(100,100))
			show()
		}
		Button[row2][col2] {
			seticon(new qicon(new qpixmap(Pair2)))
			setIconSize(new qSize(100,100)) 
			show() 
		}
		app.processevents()
		sleep(0.5)
		Button[row1][col1] {
			seticon(new qicon(new qpixmap(C_EMPTY)))
			setIconSize(new qSize(100,100))
			show()
		}
		Button[row2][col2] { 
			seticon(new qicon(new qpixmap(C_EMPTY)))
			setIconSize(new qSize(100,100))
			show() 
		}
		Button[row1][col1].setenabled(false)
		Button[row2][col2].setenabled(false)
		Pairs[row1][col1] = C_EMPTY
		Pairs[row2][col2] = C_EMPTY
		gameOver()
	else
		Button[row1][col1] {
			seticon(new qicon(new qpixmap(C_COVER)))
			setIconSize(new qSize(100,100)) 
			show() 
		}
	ok
	if (row1=row2) and (col1=col2)
		Button[row1][col1] { 
			seticon(new qicon(new qpixmap(Pair1)))
			setIconSize(new qSize(100,100)) 
			show() 
		}
	ok
	if click = 2
		click = 0
		move++
		labelShowMove.settext(string(move))
	ok

func gameOver
	check = 0
	for row = 1 to size1
		for col = 1 to size2
			if Pairs[row][col] != C_EMPTY
				check = 0
				exit 2
			else
				check = 1
			ok
		next
	next
	if check = 1
		TimerMan.stop()
		score++
		labelNumScore.settext(string(score))
		for Row = 1 to size1
			for Col = 1 to size2
				pairsOld = Pairs2[Row][Col]
				Button[Row][Col] { 
					setenabled(true)
					seticon(new qicon(new qpixmap(pairsOld)))
					setIconSize(new qSize(100,100)) 
					show() 
				}
			next
		next
	ok

func randomList aInput
	aOutput = []
	while len(aInput) > 1
		nIndex = random(len(aInput)-1)
		nIndex++
		aOutput + aInput[nIndex]
		del(aInput,nIndex)
	end
	aOutput + aInput[1]
	return aOutput

func pQuit
	win.close()

#===================================================================================#
