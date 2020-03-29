# Project : CalmoSoft Questions Game
# Date    : 28/03/2020-10:49:26
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
randQuestion = 0
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
	        }

		labelNewQuestion = new QLabel(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
		}

		btnNewQuestion = new qpushbutton(win) {
			setFont(new qFont("Verdana",fontsize,50,0))
			setText("New question")
			setClickEvent("NewQuestion()")
		}

                LayoutButtonRow1 {
			AddWidget(labelQuestion)
			AddWidget(labelNewQuestion)
			AddWidget(btnNewQuestion)
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
        score = 0
        nrQuestion = nrQuestion + 1
        labelShowScore.settext("")
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

func CheckAnswer(nr)
        score = score + 1
        labelShowScore.settext(string(score))
	btnYourAnswer.settext(btnAnswer[nr].text())
	if Questions[nrQuestion][3] = nr
		msgBox("Good Answer!")
	else
		msgBox("Bad Answer! Try again")
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

func msgBox(cText)	  
	mb = new qMessageBox(win) {
		setWindowTitle('Questions Game')
		setText(cText)
		setstandardbuttons(QMessageBox_OK) 
		result = exec() 
	}

func CloseApp()
	win.close()
