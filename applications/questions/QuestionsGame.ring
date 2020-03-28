# Project : CalmoSoft Questions Game
# Date    : 26/03/2020-10:15:02
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "questions.ring"

numQuestion = len(Questions)
numAnswer = len(Questions[1][2])
btnAnswer = list(numAnswer)
randQuestion = 0

New qApp {

        win = new qWidget() {

                setwindowtitle("Questions Game")
                setGeometry(100,100,600,400)
                move(540,140)

 		labelQuestion = new QLabel(win) {
				setGeometry(50,50,50,20)
				settext("Question:")
			        }

 		labelAnswer = new QLabel(win) {
			      setGeometry(50,100,50,20)
			      settext("Answers:")
			      }

		labelYourAnswer = new QLabel(win) {
			          setGeometry(50,200,80,20)
			          settext("Your Answer:")
			          }
   
		btnNewQuestion = new qpushbutton(win) {
			        setgeometry(150,50,200,20)
			        }

		btnQuestion = new qpushbutton(win) {
			    setgeometry(370,50,100,20)
			    setText("New question")
			    setClickEvent("pNewQuestion()")
			    }

		btnYourAnswer = new qpushbutton(win) {
			        setgeometry(150,200,200,20)
			        }

                for n = 1 to numAnswer
		    btnAnswer[n] = new qpushbutton(win) {
			           setgeometry(150,100+(n-1)*20,200,20)
			           setclickevent("pCheckAnswer(" + string(n) + ")")
			           }
                next
                show()
        }

        exec()
}

func pNewQuestion()
     btnYourAnswer.settext("")
     randQuestion = random(len(Questions)-1) + 1
     btnNewQuestion.settext(Questions[randQuestion][1])
     tempAnswer = Questions[randQuestion][2]
     see tempAnswer
     for n = 1 to numAnswer
         btnAnswer[n].settext(tempAnswer[n])
     next 

func pCheckAnswer(nr)
     btnYourAnswer.settext(btnAnswer[nr].text())
     if Questions[randQuestion][3] = nr
        msgbox("Good Answer!")
     else
        msgbox("Bad Answer! Try again")
     ok

func msgBox(cText)	  
     mb = new qMessageBox(win) {
	  setWindowTitle('Questions Game')
	  setText(cText)
          setstandardbuttons(QMessageBox_OK) 
          result = exec() 
     }


