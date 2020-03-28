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
				//setGeometry(600,350,100,20)
                                setFont(new qFont("Verdana",fontsize,50,0))
				settext("Question:")
			        }

		labelNewQuestion = new QLabel(win) {
			         //setgeometry(800,350,400,20)
                                 setFont(new qFont("Verdana",fontsize,50,0))
			         }

		btnNewQuestion = new qpushbutton(win) {
			   // setgeometry(1200,350,180,30)
                            setFont(new qFont("Verdana",fontsize,50,0))
			    setText("New question")
			    setClickEvent("pNewQuestion()")
			    }

                LayoutButtonRow1.AddWidget(labelQuestion)
                LayoutButtonRow1.AddWidget(labelNewQuestion)
                LayoutButtonRow1.AddWidget(btnNewQuestion)

 		labelAnswer = new QLabel(win) {
			      //setGeometry(600,400,450,20)
                              setFont(new qFont("Verdana",fontsize,50,0))
			      settext("Answers:")
			      }

                LayoutButtonRow2.AddWidget(labelAnswer)

                for n = 1 to numAnswer
		    btnAnswer[n] = new qpushbutton(win) {
			           //setgeometry(800,400+(n-1)*30,200,30) 
                                   setFont(new qFont("Verdana",fontsize,50,0))
			           setclickevent("pCheckAnswer(" + string(n) + ")")                                  
 			           }
                    LayoutButtonRow2.AddWidget(btnAnswer[n])
                next

		btnExit = new QPushButton(win) {
			  //setgeometry(1200,400,180,30)
			  setFont(new qFont("Verdana",fontSize,50,0))
                          setClickEvent("pExit()")
			  settext("Exit")
			  }

                LayoutButtonRow2.AddWidget(btnExit)

		labelYourAnswer = new QLabel(win) {
			          //setGeometry(600,550,130,20)
                                  setFont(new qFont("Verdana",fontsize,50,0))
			          settext("Your Answer:")
			          }   

		btnYourAnswer = new QLabel(win) {
			        //setgeometry(800,550,200,30)
                                setFont(new qFont("Verdana",fontsize,50,0))
			        }

                LayoutButtonRow3.AddWidget(labelYourAnswer)
                LayoutButtonRow3.AddWidget(btnYourAnswer)

                LayoutButtonMain.AddLayout(LayoutButtonRow)
		LayoutButtonMain.AddLayout(LayoutButtonRow1)
	 	LayoutButtonMain.AddLayout(LayoutButtonRow2)
		LayoutButtonMain.AddLayout(LayoutButtonRow3)

                setLayout(LayoutButtonMain)

                ShowFullScreen()
                pNewQuestion()

        }

        exec()
}

func pNewQuestion()
     btnYourAnswer.settext("")
     randQuestion = random(len(Questions)-1) + 1
     labelNewQuestion.settext(Questions[randQuestion][1])
     tempAnswer = Questions[randQuestion][2]
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

func pExit()
     win.close()
