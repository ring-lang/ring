# Project : CalmoSoft Questions Game
# Date    : 29/03/2020-10:43:36
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "questions.ring"

# Constants for the Questions list
	C_QUESTION      = 1
	C_ANSWERS       = 2
	C_CORRECTANSWER = 3

# Constants for the Style
	C_SPACING	= 1
	C_FONTSIZE	= 15

# Game Data
	Questions 	= RandomList(Questions)
	numQuestion 	= len(Questions)
	numAnswer 	= len(Questions[1][C_ANSWERS])
	btnAnswer 	= list(numAnswer)
	nrQuestion 	= 0
	score 		= 0

New qApp {

        stylefusionblack()

	oDesktop = new QDesktopWidget() {
		C_DESKTOPWIDTH = Width()
	}

        win = new qWidget() {

                setwindowtitle("Questions Game")

                LayoutButtonMain = new QVBoxLayout() {
                	setSpacing(C_SPACING)
                        setContentsmargins(100,100,100,100) 
		}

                LayoutButtonRow1 = new QHBoxLayout()
                LayoutButtonRow2 = new QVBoxLayout()
                LayoutButtonRow3 = new QVBoxLayout()

                LayoutButtonRow = new QVBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(10,10,10,10) 
		}


 		labelQuestion = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Question:")
			setMaximumWidth(C_DESKTOPWIDTH*0.15)
	        }

		labelNewQuestion = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
		}

                LayoutButtonRow1 {
			AddWidget(labelQuestion)
			AddWidget(labelNewQuestion)
		}

 		labelAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Answers:")
		}

                LayoutButtonRow2.AddWidget(labelAnswer)

                for n = 1 to numAnswer
			btnAnswer[n] = new qpushbutton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
				setclickevent("CheckAnswer(" + string(n) + ")")                                  
			}
			LayoutButtonRow2.AddWidget(btnAnswer[n])
                next

		btnExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			setClickEvent("CloseApp()")
			settext("Exit")
		}

                LayoutButtonRow2.AddWidget(btnExit)

		labelYourAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Your Answer:")
		}   

		btnYourAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
		}

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Your Score:")
		}   

		labelShowScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			setText("0")
		}   

                LayoutButtonRow3 {
			AddWidget(labelYourAnswer)
			AddWidget(btnYourAnswer)
			AddWidget(labelScore)
			AddWidget(labelShowScore)
		}

                LayoutButtonMain {
			AddLayout(LayoutButtonRow)
			AddLayout(LayoutButtonRow1)
			AddLayout(LayoutButtonRow2)
			AddLayout(LayoutButtonRow3)
		}

                setLayout(LayoutButtonMain)

                ShowFullScreen()

                NewQuestion()

        }

        exec()
}

func NewQuestion
	nrQuestion++
	btnYourAnswer.settext("")
	if nrQuestion = numQuestion + 1
		nrQuestion = 1
	ok
	if nrQuestion < numQuestion + 1
		labelNewQuestion.settext(Questions[nrQuestion][C_QUESTION])
		tempAnswer = Questions[nrQuestion][C_ANSWERS]
		for n = 1 to numAnswer
			btnAnswer[n].settext(tempAnswer[n])
		next
	ok

func CheckAnswer nr
	btnYourAnswer.settext(btnAnswer[nr].text())
	if Questions[nrQuestion][C_CORRECTANSWER] = nr
		IncreaseScore()
		MsgInfo("Questions Game","Good Answer!")
		NewQuestion()
	else
		MsgInfo("Questions Game","Bad Answer! Try again")
	ok

func IncreaseScore
	score++
	labelShowScore.settext(string(score))

func RandomList aInput
	aOutput = []
	while len(aInput) > 0   
		nIndex = 0
		while nIndex = 0
			nIndex = random( len( aInput) ) 
		end
		aOutput + aInput[nIndex]
		del(aInput,nIndex)
	end
	return aOutput

func CloseApp
	win.close()
