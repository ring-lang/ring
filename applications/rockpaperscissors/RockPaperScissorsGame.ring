# Project : Rock Paper Scissors Game
# Date    : 09/04/2020-03:30:17
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

width 		= 200
height 		= 200

myChose 	= 1
compChose 	= 1
nextPlayer 	= 1
myScore 	= 0
compScore 	= 0
C_FONTSIZE 	= 15

C_ROCK 		= "images/rock.jpg"
C_PAPER 	= "images/paper.jpg"
C_SCISSORS 	= "images/scissors.jpg"

ChoseList 	= [C_ROCK,C_PAPER,C_SCISSORS]

Button 		= list(len(ChoseList))

app = new QApp 
{

	StyleFusion()

	win = new QWidget() {

		setWindowTitle('Stone Paper Scissors Game')
		setWinIcon(self,C_ROCK)
		setStyleSheet("background-color:cyan;")
		setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowCloseButtonHint | Qt_CustomizeWindowHint)
		reSize(900,600)
		winheight 	= height()
		fontSize	= 8 + (winheight / 100)

		for Col = 1 to len(ChoseList)
			Button[Col] = new QPushButton(win) {
				x = 150+(Col-1)*height
				setgeometry(x,35,width,height)
				setStyleSheet("background-color:white;")
				seticon(new qicon(new qpixmap(ChoseList[Col])))
				setIconSize(new qSize(200,200))
				setclickevent("ButtonPress(" + string(Col) + ")")
				setSizePolicy(1,1) 
			}				       
		next

		labelMyChose = new QLabel(win) { 
			setgeometry(200,250,150,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("My Chose:") 
		}

		labelCompChose = new QLabel(win) { 
			setgeometry(580,250,150,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Comp Chose:") 
		}

		labelScoreEnd = new QLabel(win) { 
			setgeometry(0,510,win.width(),30)
			setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("") 
		}

		btnMyChose = new QPushButton(win) { 
			setgeometry(150,300,width,height) 
			setStyleSheet("background-color:white;")
		}

		btnCompChose = new QPushButton(win) { 
			setgeometry(550,300,width,height) 
			setStyleSheet("background-color:white;")
		}

		btnNewGame = new QPushButton(win) {
			setgeometry(170,550,150,40)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			setclickevent("NewGame()")
			settext("New Game") 
		}

		btnExit = new QPushButton(win) { 
			setgeometry(580,550,150,40)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			setclickevent("Close()")
			settext("Exit") 
		}

		labelMyScore = new QLabel(win) { 
			setgeometry(170,0,100,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("My Score: ") 
		}

		labelMyScoreSum = new QLabel(win) { 
			setgeometry(300,0,100,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("") 
		}

		labelCompScore = new QLabel(win) {
			setgeometry(580,0,130,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Comp Score: ") 
		}

		labelCompScoreSum = new QLabel(win) { 
			setgeometry(730,0,100,30)
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("") 
		}

		show()

	}

	exec()

}

func ButtonPress Col

	if nextPlayer = 1
		myChose = Col
		btnMyChose { 
			seticon(new qicon(new qpixmap(ChoseList[Col])))
			setIconSize(new qSize(width,height)) 
		}
		nextPlayer = 2
		compChose()
	ok

func compChose

	rndChose = random(len(ChoseList)-1) + 1
	compChose = rndChose
	btnCompChose { 
		seticon(new qicon(new qpixmap(ChoseList[compChose])))
		setIconSize(new qSize(width,height)) 
	}
	nextPlayer = 1
	Result()
    

func Result

	if (myChose = compChose)
		labelScoreEnd.settext("Draw!")
	ok
	if (myChose = 1) and (compChose = 2)
		labelScoreEnd.settext("Computer Win!")
		compScore = compScore + 1
		labelCompScoreSum.settext(string(compScore))
	ok
	if (myChose = 1) and (compChose = 3)
		labelScoreEnd.settext("I Win!")
		myScore = myScore + 1
		labelMyScoreSum.settext(string(myScore))
	ok
	if (myChose = 2) and (compChose = 3)
		labelScoreEnd.settext("Computer Win!")
		compScore = compScore + 1
		labelCompScoreSum.settext(string(compScore))
	ok	
	if (myChose = 2) and (compChose = 1)
		labelScoreEnd.settext("I Win!")
		myScore = myScore + 1
		labelMyScoreSum.settext(string(myScore))
	ok
	if (myChose = 3) and (compChose = 1)
		labelScoreEnd.settext("Computer Win!")
		compScore = compScore + 1
		labelCompScoreSum.settext(string(compScore))
	ok
	if (myChose = 3) and (compChose = 2)
		labelScoreEnd.settext("I Win!")
		myScore = myScore + 1
		labelMyScoreSum.settext(string(myScore))
	ok

func NewGame

	nextPlayer 	= 1
	myScore 	= 0
	compScore 	= 0
     
	btnMyChose { 
		seticon(new qicon(new qpixmap("")))
		setIconSize(new qSize(200,200)) 
	}

	btnCompChose {
		seticon(new qicon(new qpixmap("")))
		setIconSize(new qSize(200,200)) 
	}

	labelScoreEnd.settext("")
	labelMyScoreSum.settext("0")
	labelCompScoreSum.settext("0")

     
func Close

	win.close()
	app.quit()	

