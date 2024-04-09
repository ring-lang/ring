# Project : Wise Quadrat Game
# Date    : 2018/11/01
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

size                = 6
player1             = 1
player2             = 0
C_ROWCOUNT          = 6
C_COLCOUNT          = 6
C_SPACING           = 5
C_EMPTYBUTTONSTYLE  =  'border-radius:17px;background-color:silver'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONBLUESTYLE   = 'border-radius:17px;color:black; background-color: blue'
C_BUTTONORANGESTYLE = 'border-radius:17px;color:black; background-color: orange'
button              = list(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow     = list(C_ROWCOUNT)
buttonsum1          = list(size,size)
buttonsum2          = list(size,size)

app = new qApp {
	StyleFusion()
	win = new qWidget() {
		setWinIcon(self,"icon.png")
		setWindowTitle('Wise Quadrat Game')
		move(490,100)
		resize(600,600)
		setstylesheet('background-color:white')
		LayoutButtonMain = new QVBoxLayout()
		LayoutButtonMain.setSpacing(C_SPACING)
		LayoutButtonMain.setContentsmargins(0,0,0,0)
		for Row = 1 to C_ROWCOUNT
			LayoutButtonRow[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}
			for Col = 1 to C_COLCOUNT
				button[Row][Col] = new QPushButton(win) {
 				setstylesheet(C_EMPTYBUTTONSTYLE)
				setclickevent("pplay(" + string(Row) + "," + string(Col) + ")")
				setSizePolicy(1,1)
				}
				LayoutButtonRow[Row].AddWidget(button[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
		next
		setLayout(LayoutButtonMain)
		show()
	}
	exec()
}

func pplay(n,m)
	if player1 = 1 
		button[n][m] {
			setstylesheet(C_BUTTONORANGESTYLE)
			player1 = 0
			player2 = 1
			setenabled(false)
		}
		buttonsum1[n][m] = 1
        else
		button[n][m] {
			setstylesheet(C_BUTTONBLUESTYLE)
			player1 = 1
			player2 = 0
			setenabled(false)
		}
		buttonsum2[n][m] = 2
	ok
	gameover()

func gameover()
	buttonsum = 0
	for p = 1 to size-1
		for n = 1 to size-p
			for m = 1 to size-p
				bool1    = (buttonsum1[n][m] = 1)   and (buttonsum1[n+p][m] = 1)
				bool2    = (buttonsum1[n][m+p] = 1) and (buttonsum1[n+p][m+p] = 1)
				bool3    = (buttonsum2[n][m] = 2)   and (buttonsum2[n+p][m] = 2)
				bool4    = (buttonsum2[n][m+p] = 2) and (buttonsum2[n+p][m+p] = 2)
				cWinMsg  = NULL
				if bool1 and bool2
					cWinMsg = "Player1 won!"
				ok
				if bool3 and bool4
					cWinMsg = "Player2 won!"
				ok
				if cWinMsg
					win.setEnabled(False)
					app.processevents()
					sleep(0.3)
					button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
					app.processevents()
					sleep(0.3)
					button[n+p][m].setstylesheet(C_BUTTONVIOLETSTYLE)
					app.processevents()
					sleep(0.3)
					button[n][m+p].setstylesheet(C_BUTTONVIOLETSTYLE)
					app.processevents()
					sleep(0.3)
					button[n+p][m+p].setstylesheet(C_BUTTONVIOLETSTYLE)
					msgInfo("Memory Game",cWinMsg)
					pbegin()
					win.setEnabled(True)
				ok
			next
		next
        next
	for n = 1 to size
		for m = 1 to size
			if (buttonsum1[n][m] = 1) or (buttonsum2[n][m] = 2)
				buttonsum++
			ok
		next
        next
        if buttonsum = size*size     
		msgInfo("Memory Game","Game Over!")
        ok

func pbegin()
	player1 = 1
	player2 = 0
	for n = 1 to size
		for m = 1 to size
			button[n][m] { 
				setstylesheet(C_EMPTYBUTTONSTYLE)
				buttonsum1[n][m] = 0
				buttonsum2[n][m] = 0
				button[n][m].setenabled(true)
				win.show() 
			}
		next
	next

