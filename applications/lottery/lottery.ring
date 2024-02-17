# Project : CalmoSoft Lottery Game
# Date    : 03/05/2020-22:24:46
# Author  : Gal Zsolt
# Email   : <calmosoft@gmail.com>

#===================================================================================#
# Load the required libraries 
#===================================================================================#

	load "stdlibcore.ring"
	load "guilib.ring"

#===================================================================================#
# Define variables & constants
#===================================================================================#

	width		= 50
	height   	= 50
	
	xWidth		= 600
	yHeight		= 600   
	
	C_SPACING	= 1
	C_FONTSIZE	= 15
	

	size = 7
	limit = 6


	Button		= list(size,size)
	PairsRand	= []

        score            = 0	
        click            = 0
        user             = 1
	LayoutButtonRow2 = list(size)
	PairsXY		 = list(size*size,2)
        Lottery          = list(size,size)
        C_FONTSIZE 	 = 15
        C_StylePink	 = ' background-color: Pink; border-radius: 8px; '
        C_StyleGreen	 = ' background-color: Green; border-radius: 8px; '
        C_StyleGray	 = ' color: Purple; background-color: LightGray; border-radius: 8px; '
        C_StyleRed	 = ' background-color: Red; border-radius: 8px; '
        C_StyleBlack	 = ' background-color: Black; border-radius: 8px; '
        C_StyleYellow	 = ' color: Black; background-color: Yellow; border-radius: 8px; '
        C_StylePurple	 = ' color: White; background-color: Purple; border-radius: 8px; '

#===================================================================================#
# The User Interface (Game Window and Buttons)	
#===================================================================================#

app = new qApp {

	StyleFusion()

	win = new qWidget() {

		setWindowTitle('CalmoSoft Lottery Game')
		setWinIcon(self,"images/lottery.jpg")
		reSize(xWidth, yHeight)

		setStyleSheet("color: white; selection-color: black;
                selection-background-color:white ;
                background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #000, stop: 1 #00f);")

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

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Score: ")
		}

		labelShowScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        settext("0") 
		}

		labelChoice = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Choice: ")
		}

		labelShowChoice = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        settext("0") 
		}

		LayoutButtonRow5.AddWidget(labelEmpty1)

		LayoutButtonMain { 
			AddLayout(LayoutButtonRow1)
			AddLayout(LayoutButtonRow5)
			AddLayout(LayoutButtonRow4)
		}

		for Row = 1 to size
			LayoutButtonRow2[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}
			for Col = 1 to size
				Button[Row][Col] = new QPushButton(win) {
					setSizePolicy(1,1)
                                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                                        num = (Row-1)*size+Col
                                        settext(string(num))
					setclickevent("UserClick(" + string(Row) + "," + string(Col) + ")")
					setMaximumWidth(100)
					setMaximumHeight(100)
                                        setStylesheet(C_StyleGray)
				}
				LayoutButtonRow2[Row].AddWidget(Button[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow2[Row])
		next

		buttonNewGame = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("New")
			setClickEvent("newGame()") 
		}

		buttonDraw = new QPushButton(win) {
			     setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			     settext("Draw")
			     setClickEvent("lotteryDraw()") 
		}

		buttonExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Exit")
			setClickEvent("closeGame()") 
		}

		LayoutButtonRow6.AddWidget(labelEmpty2)

		LayoutButtonMain.AddLayout(LayoutButtonRow6)

		LayoutButtonRow1 {
			AddWidget(labelTime)
			AddWidget(labelShowTime)
                        AddWidget(labelChoice)
                        AddWidget(labelShowChoice)
			AddWidget(labelScore)
			AddWidget(labelShowScore)
		}

		LayoutButtonRow3 {
			AddWidget(buttonNewGame)
			AddWidget(buttonDraw)
			AddWidget(buttonExit)
		}

		LayoutButtonMain.AddLayout(LayoutButtonRow3)

		setLayout(LayoutButtonMain)

		TimerMan = new qTimer(win) {
			time1 = clock()
			setInterval(1000)
			setTimeoutEvent("timerMan()")  ### ==>> Func
			start()
		}
		
		voice = new QTextToSpeech(win) {
			say("Welcome to the Lottery Game, Select 6 Numbers!")
		}

		show()

	}

	exec()

}

#===================================================================================#
# Game Logic
#===================================================================================#

func userClick Row,Col

	click++
	if click > limit or Lottery[Row][Col] = 1
		return
	ok
	if user = 1
		Button[Row][Col] {
			setStylesheet(C_StylePurple)
			setenabled(false)
			voice.Say(Text())
		}
		labelShowChoice.settext(string(click))
		Lottery[Row][Col] = 1
	ok
	if click = limit
		user = 2
	ok

func lotteryDraw

        if user = 1 return ok
        if user = 2
		PairsXY = list(size*size,2)
		randList = 1:6
		randList = randomList(randList)
		for n = 1 to size
			for m = 1 to size
				ind = (n-1)*size + m
				PairsXY[ind][1] = n
				PairsXY[ind][2] = m
			next
		next
		for nr = 1 to limit
			rand1   = randList[nr]
			rand2	= randList[rand1]
			row	= pairsXY[rand1][1]
			col	= pairsXY[rand1][2]
	                if Lottery[rand1][rand2] = 1
				Button[rand1][rand2].setStylesheet(C_StyleYellow)
				score++
				labelShowScore.settext(string(score))
	                else
				Button[rand1][rand2].setStylesheet(C_StyleBlack)
	                ok
			del(PairsXY,rand1)
		next
        ok
        user = 0

func newGame

	click = 0
	user = 1
	score = 0
	labelShowScore.settext(string(score))
	labelShowChoice.settext("0")
	for n = 1 to size
		for m = 1 to size
			Button[n][m].setStylesheet(C_StyleGray)
			Button[n][m].setenabled(true)
			Lottery[n][m] = 0
		next
	next

func timerMan

	nowTime    = ceil( (clock() - time1) / 1000 )
	nowMinute  = floor( nowTime / 60 )
	nowSeconds = nowTime % 60
	if nowSeconds < 10  
		nowSeconds = "0"+ nowSeconds
	ok
	nowMinSec  = "" + nowMinute + ":" + nowSeconds        
	labelShowTime.setText(nowMinSec)

func closeGame

	win.close()

#===================================================================================#
