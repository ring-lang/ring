# Project : CalmoSoft Matching Game
# Date    : 15/04/2020-05:56:38
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "matchinglist.ring"

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
rndCountry	= RandomList(rnd1)
for n = 1 to limit
    randCountry + rndCountry[n]
next
  
randCapital	= RandomList(randCountry)

oApp = New QApp {
                 
	StyleFusionBlack()

	win = new qWidget() {

		resize(800,600)
		setwindowtitle("Matching Game")
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

			Button1[x] = new qPushButton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
				setclickevent("countryClick(" + string(x) + ")")
				settext(Countries[rndCountry[x]])
			} 
			LayoutButtonCol2.addwidget(Button1[x])

			Button2[x] = new qPushButton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
				setclickevent("capitalClick(" + string(x) + ")")
				settext(Capitals[randCapital[x]])
			} 
			LayoutButtonCol3.addwidget(Button2[x])

			Button3[x] = new qPushButton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			} 
			LayoutButtonCol5.addwidget(Button3[x])

			Button4[x] = new qPushButton(win) {
				setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			}
			LayoutButtonCol6.addwidget(Button4[x]) 

		next


		labelSort = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Countries and Capitals to sort:")
		}

		labelUserSort = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Your Sort:")
		}

		labelEmpty = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("")
		}

		buttonCheckSort = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Check")
			setClickEvent("checkSort()")
		}

		buttonNewGame = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("New")
			setClickEvent("newGame()")
		}

		buttonExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Exit")
			setClickEvent("CloseGame()")
		}

		ButtonCear = new qPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Clear")
			setClickEvent("Clear()")
		}

		ButtonSolve = new qPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Solve")
			setClickEvent("Solve()")
		}

		LayoutButtonRow1.AddWidget(labelSort)
		LayoutButtonRow8.AddWidget(labelUserSort)
		LayoutButtonRow11.AddWidget(labelEmpty)

		LayoutButtonRow9.AddWidget(buttonCheckSort)
		LayoutButtonRow9.AddWidget(ButtonSolve)
		LayoutButtonRow9.AddWidget(ButtonCear)
		LayoutButtonRow9.AddWidget(buttonNewGame)
		LayoutButtonRow9.AddWidget(buttonExit)

		LayoutButtonRow4.AddLayout(LayoutButtonCol2)
		LayoutButtonRow4.AddLayout(LayoutButtonCol3)
		LayoutButtonRow7.AddLayout(LayoutButtonCol5)
		LayoutButtonRow7.AddLayout(LayoutButtonCol6)
		LayoutButtonRow10.AddLayout(LayoutButtonRow9)

		LayoutButtonMain.AddLayout(LayoutButtonRow1)
		LayoutButtonMain.AddLayout(LayoutButtonRow4)
		LayoutButtonMain.AddLayout(LayoutButtonRow8)

		LayoutButtonMain.AddLayout(LayoutButtonRow7)
		LayoutButtonMain.AddLayout(LayoutButtonRow11)
		LayoutButtonMain.AddLayout(LayoutButtonRow10)

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
	rndCountry = RandomList(rnd1)
	for n = 1 to limit
		randCountry + rndCountry[n]
	next
  
	randCapital = RandomList(randCountry)

	for x = 1 to limit
		Button3[x].settext("")
		Button4[x].settext("")
		Button1[x].setclickevent("countryClick(" + string(x) + ")")
		Button1[x].settext(Countries[rndCountry[x]])
		Button1[x].setenabled(true)
		Button2[x].setclickevent("capitalClick(" + string(x) + ")")
		Button2[x].settext(Capitals[randCapital[x]])
		Button2[x].setenabled(true)
		Button3[x].setstylesheet("background-color: ;")
		Button4[x].setstylesheet("background-color: ;")
	next

func closeGame
	win.close()

func randomList aInput
	aOutput = []
	while len(aInput) > 1
		nIndex = random(len(aInput)-1)
		nIndex++
		aOutput + aInput[nIndex]
		del(aInput,nIndex)
	end
	aOutput + aInput[1]
	return aOutput

func countryClick nr1
	numCountry++
	if numCountry <= limit
		country = Countries[rndCountry[nr1]]
		Button3[numCountry].settext(country)
		userCountry + country
		Button1[nr1].setenabled(false)
	ok

func capitalClick nr2
	numCapital++
	if numCapital <= limit
		capital = Capitals[randCapital[nr2]]
		Button4[numCapital].settext(capital)
		userCapital + capital
		Button2[nr2].setenabled(false)
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
			Button3[n].setstylesheet("background-color: green;")
			Button4[n].setstylesheet("background-color: green;")
		next
	else
		for n = 1 to limit
			Button3[n].setstylesheet("background-color: red;")
			Button4[n].setstylesheet("background-color: red;")
		next
	ok

func clear
	numCountry = 0
	numCapital = 0
	for n = 1 to limit
		Button3[n].settext("")
		Button4[n].settext("")
		Button1[n].setenabled(true)
		Button2[n].setenabled(true)
		Button3[n].setstylesheet("background-color:;")
		Button4[n].setstylesheet("background-color:;")
	next
   
func solve
	for n = 1 to limit 
		temp1	= Button1[n].text()
		Button3[n].settext(temp1)
		Button3[n].setstylesheet("background-color:orange;")
		num	= find(Countries, temp1)
		temp2	= Capitals[num]
		Button4[n].settext(temp2)
		Button4[n].setstylesheet("background-color:orange;") 
	next
