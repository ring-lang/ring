# Project : CalmoSoft Money Case Game
# Date    : 30/03/2020-11:40:18
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlibcore.ring"
load "lightguilib.ring"

C_SPACING	= 1
C_FONTSIZE	= 15

score 		= 0
sumMoney 	= 0
desiredMoney 	= 0
numMoney 	= 0
limit 		= 10
limitMoney 	= 30
caseMoney 	= [10,10,10,20,20,20,30,30,30,40,
		   50,50,50,60,60,60,70,70,70,80,
		   100,200,300,400,500,1000,2000,5000,10000,20000]

lenMoneyCase 	= len(caseMoney)
btnMoney 	= list(lenMoneyCase)

oApp = New QApp {

        stylefusionblack()

        win = new qWidget() {

                setwindowtitle("Money Case Game")

                LayoutButtonMain = new QVBoxLayout() {
                	setSpacing(C_SPACING)
                        setContentsmargins(100,100,100,100) 
		}

                LayoutButtonRow1 = new QHBoxLayout() 
                LayoutButtonRow2 = new QHBoxLayout()
                LayoutButtonRow3 = new QHBoxLayout()
                LayoutButtonRow4 = new QHBoxLayout()
                LayoutButtonRow5 = new QHBoxLayout()
                LayoutButtonRow6 = new QHBoxLayout()

                for n = 1 to lenMoneyCase/2
			btnMoney[n] = new qpushbutton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
				setclickevent("selectMoney(" + string(n) + ")")  
				setStyleSheet("color:white;background-color:gray;")                                
			}
			LayoutButtonRow1.AddWidget(btnMoney[n])
                next

                for n = lenMoneyCase/2 + 1 to lenMoneyCase
			btnMoney[n] = new qpushbutton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
				setclickevent("selectMoney(" + string(n) + ")")                                  
				setStyleSheet("color:white;background-color:gray;")                                
			}
			LayoutButtonRow2.AddWidget(btnMoney[n])
                next

		btnExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			setClickEvent("CloseApp()")
			settext("Exit")
		}

		labelAmount = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Amount:")
		}

		btnAmount = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
		}

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Score:")
		}

		labelNumScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
		}

		labelDesiredAmount = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Desired Amount:")
		}

		labelDesiredMoneyAmount = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
		}

                LayoutButtonRow3.AddWidget(labelAmount)
                LayoutButtonRow3.AddWidget(btnAmount)
                LayoutButtonRow4.AddWidget(labelDesiredAmount)
                LayoutButtonRow4.AddWidget(labelDesiredMoneyAmount)
                LayoutButtonRow5.AddWidget(labelScore)
                LayoutButtonRow5.AddWidget(labelNumScore)
                LayoutButtonRow6.AddWidget(btnExit)

                LayoutButtonMain.AddLayout(LayoutButtonRow1)
                LayoutButtonMain.AddLayout(LayoutButtonRow2)
                LayoutButtonMain.AddLayout(LayoutButtonRow3)
                LayoutButtonMain.AddLayout(LayoutButtonRow4)
                LayoutButtonMain.AddLayout(LayoutButtonRow5)
                LayoutButtonMain.AddLayout(LayoutButtonRow6)

                setLayout(LayoutButtonMain)

                newCaseMoneyList()
                desiredMoneyAmount()

                ShowFullScreen()
        }

        exec()
}

func desiredMoneyAmount
	desiredMoney = random(20000) + 1
	desiredMoney = desiredMoney - (desiredMoney % 10)
	labelDesiredMoneyAmount.settext(string(desiredMoney))

func newCaseMoneyList
	for n = 1 to lenMoneyCase/2
		btnMoney[n].settext(string(caseMoney[n]))
	next
	for n = lenMoneyCase/2 + 1 to lenMoneyCase
		btnMoney[n].settext(string(caseMoney[n]))
	next

func selectMoney nr
	numMoney = numMoney + 1
	sumMoney = sumMoney + btnMoney[nr].text()
	btnAmount.settext(string(sumMoney))
	btnMoney[nr].setStyleSheet("color:white;background-color:green;")
	btnMoney[nr].setenabled(False)
	if (desiredMoney = sumMoney) and (numMoney <= limit)
		score = score + 1
		labelNumScore.settext(string(score))
		msgbox("You Win!")
		pNextGame()
	ok
	if (desiredMoney < sumMoney) or (numMoney > limit)
		msgbox("Game Over!")
		pNextGame()
	ok 

func pNextGame
	sumMoney = 0
	numMoney = 0
	btnAmount.settext("")
	labelDesiredMoneyAmount.settext("")
	for n = 1 to lenMoneyCase
		btnMoney[n].setenabled(True)
		btnMoney[n].setStyleSheet("color:white;background-color:gray;")
	next
	desiredMoneyAmount()

func msgBox cText
	mb = new qMessageBox(win) {
		setWindowTitle("Money Case")
		setText(cText)
		setstandardbuttons(QMessageBox_OK) 
		result = exec() 
	}

func CloseApp
	win.close()
