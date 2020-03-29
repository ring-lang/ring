# Project : CalmoSoft Questions Game
# Date    : 29/03/2020-10:43:36
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "questions.ring"

numQuestion = len(Questions)
numAnswer = len(Questions[1][2])
btnAnswer = list(numAnswer)
nrQuestion = 0
score = 0
keypress = 1
randQuestion = 0
goodFlag = 0
C_Spacing = 1
fontsize = 15

New qApp {

        stylefusionblack()

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
			setFont(new qFont("Verdana",fontsize,50,0))
			settext("Question:")
			setMaximumWidth(200)
	        }

		labelNewQuestion = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
		}

                LayoutButtonRow1 {
			AddWidget(labelQuestion)
			AddWidget(labelNewQuestion)
		}

 		labelAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
			settext("Answers:")
		}

                LayoutButtonRow2.AddWidget(labelAnswer)

                for n = 1 to numAnswer
			btnAnswer[n] = new qpushbutton(win) {
				setFont(new qFont("Verdana",fontsize,50,0))
				setclickevent("CheckAnswer(" + string(n) + ")")                                  
			}
			LayoutButtonRow2.AddWidget(btnAnswer[n])
                next

		btnExit = new QPushButton(win) {
			setFont(new qFont("Verdana",fontSize,50,0))
			setClickEvent("CloseApp()")
			settext("Exit")
		}

                LayoutButtonRow2.AddWidget(btnExit)

		labelYourAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
			settext("Your Answer:")
		}   

		btnYourAnswer = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
		}

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
			settext("Your Score:")
		}   

		labelShowScore = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
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

func NewQuestion()
	goodFlag = 0
	while keypress = 1
		nrQuestion = nrQuestion + 1
		Questions = RandomList(Questions)
		btnYourAnswer.settext("")
		if nrQuestion = numQuestion + 1
			nrQuestion = 1
		ok
		if nrQuestion < numQuestion + 1
			labelNewQuestion.settext(Questions[nrQuestion][1])
			tempAnswer = Questions[nrQuestion][2]
			for n = 1 to numAnswer
				btnAnswer[n].settext(tempAnswer[n])
			next
		ok
		keypress = 0
	end

func CheckAnswer(nr)
	btnYourAnswer.settext(btnAnswer[nr].text())
	if Questions[nrQuestion][3] = nr
		score++
		goodFlag = 1
		labelShowScore.settext(string(score))
		msgInfo("Questions Game","Good Answer!")
	else
		msgInfo("Questions Game","Bad Answer! Try again")
	ok
	if goodFlag = 1
		keypress = 1
		NewQuestion()
	ok

func RandomList(aInput)
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

func CloseApp()
	win.close()
