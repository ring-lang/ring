# Project : CalmoSoft Matching Game
# Date    : 15/04/2020-05:56:38
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlibcore.ring"
load "lightguilib.ring"
load "MatchingList.ring"

limit 		= 3
numCountry 	= 0
numcapital 	= 0
lenMatching 	= len(MatchingList)
C_SPACING 	= 1
C_FONTSIZE 	= 15

Countries 	= list(lenMatching)
Capitals 	= list(lenMatching)
SortCountries	= list(lenMatching)
SortCapitals	= list(lenMatching) 

Button1 	= list(limit)
Button2 	= list(limit)
Button3 	= list(limit)
Button4 	= list(limit)
userCountry 	= []
userCapital 	= []

C_StylePink	= ' background-color: Pink; border-radius: 8px; '
C_StyleGreen	= ' background-color: Green; border-radius: 8px; '

for n = 1 to lenMatching
    Countries[n] = MatchingList[n][1]
    Capitals[n]  = MatchingList[n][2]
next

SortCountries	= sort(Countries)
SortCapitals	= sort(Capitals)

randCountry	= []

rnd1		= 1:lenMatching
rndCountry	= randomList(rnd1)
for n = 1 to limit
    randCountry + rndCountry[n]
next
  
randCapital	= randomList(randCountry)

oApp = new QApp {
                 
	styleFusionBlack()

	win = new QWidget() {

		resize(800,600)
		setWindowTitle("Matching Game")
		setWinIcon(self,"images/match.png")

		LayoutButtonMain = new QVBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(100,100,100,100) 
		}

		LayoutButtonRow1 = new QHBoxLayout()
		LayoutButtonCol2 = new QVBoxLayout()
		LayoutButtonCol3 = new QVBoxLayout()
		LayoutButtonRow4 = new QHBoxLayout()

		LayoutButtonCol5 = new QVBoxLayout()
		LayoutButtonCol6 = new QVBoxLayout()
		LayoutButtonRow7 = new QHBoxLayout()

		LayoutButtonRow8 = new QHBoxLayout()

		LayoutButtonRow9 = new QHBoxLayout()
		LayoutButtonRow10 = new QVBoxLayout()
		LayoutButtonRow11 = new QHBoxLayout()
		LayoutButtonRow12 = new QHBoxLayout()

		for x = 1 to limit

			Button1[x] = new QPushButton(win) {
				setFont(new QFont("Verdana",C_FONTSIZE,50,0))
				setClickEvent("countryClick(" + string(x) + ")")
				setText(Countries[rndCountry[x]])
			} 
			LayoutButtonCol2.addWidget(Button1[x])

			Button2[x] = new QPushButton(win) {
				setFont(new QFont("Verdana",C_FONTSIZE,50,0))
				setClickEvent("capitalClick(" + string(x) + ")")
				setText(Capitals[randCapital[x]])
			} 
			LayoutButtonCol3.addWidget(Button2[x])

			Button3[x] = new QPushButton(win) {
				setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			} 
			LayoutButtonCol5.addWidget(Button3[x])

			Button4[x] = new QPushButton(win) {
				setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			}
			LayoutButtonCol6.addWidget(Button4[x]) 

		next


		labelSort = new QLabel(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Countries and Capitals to sort:")
		}

		labelUserSort = new QLabel(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Your Sort:")
		}

		labelEmpty = new QLabel(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("")
		}

		buttonCheckSort = new QPushButton(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Check")
			setClickEvent("checkSort()")
		}

		buttonNewGame = new QPushButton(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("New")
			setClickEvent("newGame()")
		}

		buttonExit = new QPushButton(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Exit")
			setClickEvent("CloseGame()")
		}

		ButtonCear = new QPushButton(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Clear")
			setClickEvent("Clear()")
		}

		ButtonSolve = new QPushButton(win) {
			setFont(new QFont("Verdana",C_FONTSIZE,50,0))
			setText("Solve")
			setClickEvent("Solve()")
		}

		LayoutButtonRow1.addWidget(labelSort)
		LayoutButtonRow8.addWidget(labelUserSort)
		LayoutButtonRow11.addWidget(labelEmpty)

		LayoutButtonRow9 { 
			addWidget(buttonCheckSort)
			addWidget(ButtonSolve)
			addWidget(ButtonCear)
			addWidget(buttonNewGame)
			addWidget(buttonExit)
		}

		LayoutButtonRow4 {
			addLayout(LayoutButtonCol2)
			addLayout(LayoutButtonCol3)
		}

		LayoutButtonRow7 { 
			addLayout(LayoutButtonCol5)
			addLayout(LayoutButtonCol6)
		}

		LayoutButtonRow10.addLayout(LayoutButtonRow9)

		LayoutButtonMain { 
			addLayout(LayoutButtonRow1)
			addLayout(LayoutButtonRow4)
			addLayout(LayoutButtonRow8)
			addLayout(LayoutButtonRow7)
			addLayout(LayoutButtonRow11)
			addLayout(LayoutButtonRow10)
		}

		setLayout(LayoutButtonMain)

		show()
	}

	exec()

}

func newGame

	numCountry = 0
	numcapital = 0

	for n = 1 to lenMatching
		Countries[n]	= MatchingList[n][1]
		Capitals[n]	= MatchingList[n][2]
	next

	SortCountries	= sort(Countries)
	SortCapitals	= sort(Capitals)

	randCountry	= []

	rnd1	= 1:lenMatching
	rndCountry = randomList(rnd1)
	for n = 1 to limit
		randCountry + rndCountry[n]
	next
  
	randCapital = randomList(randCountry)

	for x = 1 to limit
		Button1[x] { 
			setClickEvent("countryClick(" + string(x) + ")")
			setText(Countries[rndCountry[x]])
			setEnabled(true)
		}
		Button2[x] { 
			setClickEvent("capitalClick(" + string(x) + ")")
			setText(Capitals[randCapital[x]])
			setEnabled(true)
		}
		Button3[x] { 
			setStyleSheet("background-color: ;")
			setText("")
		}
		Button4[x] { 
			setText("")
			setStyleSheet("background-color: ;")
		}
	next

func closeGame

	win.close()

func countryClick nr1

	numCountry++
	if numCountry <= limit
		country = Countries[rndCountry[nr1]]
		Button3[numCountry].setText(country)
		userCountry + country
		Button1[nr1].setEnabled(false)
	ok

func capitalClick nr2

	numCapital++
	if numCapital <= limit
		capital = Capitals[randCapital[nr2]]
		Button4[numCapital].setText(capital)
		userCapital + capital
		Button2[nr2].setEnabled(false)
	ok

func checkSort

	flag = 1
	for n = 1 to limit
		Button3[n] { temp5 = text() }
		Button4[n] { temp6 = text() }
		num = find(Countries, temp5)
		if (num > 0) and (temp6 = Capitals[num])
			flag = 1
		else
			flag = 0
			exit
		ok
	next
	if flag = 1
		for n = 1 to limit
			Button3[n].setStyleSheet("background-color: green;")
			Button4[n].setStyleSheet("background-color: green;")
		next
	else
		for n = 1 to limit
			Button3[n].setStyleSheet("background-color: red;")
			Button4[n].setStyleSheet("background-color: red;")
		next
	ok

func clear

	numCountry = 0
	numCapital = 0
	for n = 1 to limit
		Button3[n].setText("")
		Button4[n].setText("")
		Button1[n].setEnabled(true)
		Button2[n].setEnabled(true)
		Button3[n].setStyleSheet("background-color:;")
		Button4[n].setStyleSheet("background-color:;")
	next
   
func solve

	for n = 1 to limit 
		temp1	= Button1[n].text()
		Button3[n].setText(temp1)
		Button3[n].setStyleSheet("background-color:orange;")
		num	= find(Countries, temp1)
		temp2	= Capitals[num]
		Button4[n].setText(temp2)
		Button4[n].setStyleSheet("background-color:orange;") 
	next
