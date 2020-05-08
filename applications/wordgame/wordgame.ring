# Project : CalmoSoft Word Game
# Date    : 07/05/2020-04:01:01
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

#===================================================================================#
# Load the required libraries 
#===================================================================================#

	load "stdlib.ring"
	load "guilib.ring"
        load "WordList.ring"

#===================================================================================#
# Define variables & constants
#===================================================================================#

	size1		= 12
	size2		= 12
        letter1           = ""                   // letter to swap
        letter2           = ""                   // letter to swap to
	width		= 50
	height	        = 50
	xWidth		= 800
	yHeight		= 600
	
	C_SPACING	= 1
	C_FONTSIZE	= 15
	
	row1		= 0                      // row value of letter1
	row2		= 0                      // row value of letter2
	col1		= 0
	col2		= 0
	click		= 1                      // check for letter to swap
                                                 // click = 1 first letter
                                                 // click = 2 second letter
	score		= 0
	time1		= 0
	time2		= 0
	swap		= 0
        score           = 0  
        checkScore      = 0                  
	
        WordList        = []
	limit		= 6
	
	Button		= newlist(size1,size2)    // main buttons for letters
	PairsXY		= newlist(size1*size2,2)  // store coordinates (x,y) of cells
        rowWord         = list(size1)
        colWord         = list(size2)
	
	LayoutButtonRow2= list(size1)             // Layout for buttons

        C_StyleGray	= ' color: Purple; background-color: LightGray; border-radius: 8px; '
        C_StyleYellow	= ' color: Yellow; background-color: Black; border-radius: 8px; '
        C_StyleGreen    = ' background-color: Green; border-radius: 8px; '

#===================================================================================#
# The User Interface (Game Window and Buttons)	
#===================================================================================#

app = new qApp {

	StyleFusion()

	win = new qWidget() {

		setWindowTitle('CalmoSoft Word Game')
		setWinIcon(self,"images/WordGameIcon.png")
		reSize(xWidth, yHeight)

                setStyleSheet("color: white; selection-color: black;
                selection-background-color:white ;
                background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #000, stop: 1 #0f0);")

		LayoutButtonMain = new QVBoxLayout() {
			setSpacing(C_SPACING)
			setContentsmargins(50,50,50,50) 
		}

		LayoutButtonRow1 = new QHBoxLayout()
		LayoutButtonRow3 = new QHBoxLayout()
		LayoutButtonRow4 = new QHBoxLayout()
		LayoutButtonRow5 = new QHBoxLayout()
		LayoutButtonRow6 = new QHBoxLayout()
		
		labelEmpty1 = new QLabel(win)
		labelEmpty2 = new QLabel(win)
		
		labelTime = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext(" Time: ") 
		}

		labelShowTime = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0)) 
		}

		labelSwap = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Swap: ")
		}

		labelShowSwap = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0)) 
		}

		LayoutButtonRow5.AddWidget(labelEmpty1)

		LayoutButtonMain { 
			AddLayout(LayoutButtonRow1)
			AddLayout(LayoutButtonRow5)
			AddLayout(LayoutButtonRow4)
		}

		for Row = 1 to size1
			LayoutButtonRow2[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}
			for Col = 1 to size2
				Button[Row][Col] = new QPushButton(win) {
					setSizePolicy(1,1)
			                setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                                        setstylesheet(C_StyleGray)
					setclickevent("pUserClick(" + string(Row) + "," + string(Col) + ")")
				}
				LayoutButtonRow2[Row].AddWidget(Button[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow2[Row])
		next

		buttonNewGame = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("New")
			setClickEvent("newGame()") 
		}

		buttonExit = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Exit")
			setClickEvent("closeGame()") 
		}

		labelScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("           Score:")
		}

		labelShowScore = new QLabel(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("0")
		}

		LayoutButtonRow6.AddWidget(labelEmpty2)

		LayoutButtonMain.AddLayout(LayoutButtonRow6)

		LayoutButtonRow1 {
			AddWidget(labelTime)
			AddWidget(labelShowTime)
			AddWidget(labelSwap)
			AddWidget(labelShowSwap)
		}

		LayoutButtonRow3 {
			AddWidget(buttonNewGame)
			AddWidget(labelScore)
			AddWidget(labelShowScore)
			AddWidget(buttonExit)
		}

		LayoutButtonMain.AddLayout(LayoutButtonRow3)

		setLayout(LayoutButtonMain)

		TimerMan = new qTimer(win) {
			time1 = clock()
			setInterval(1000)
			setTimeoutEvent("timerMan()")  ### ==>> Func
			start()
		}
                createWordList()		
                newGame()
		show()

	}

	exec()

}

#===================================================================================#
# Game Logic
#===================================================================================#

#============================
# create words list
#============================

func createWordList()

     for n = 1 to len(MatchingList)
         if len(MatchingList[n][1]) > 12
            del(MatchingList,n)
         ok
         if len(MatchingList[n][2]) > 12
            del(MatchingList,n)
         ok
     next

     WordList = []
     for n = 1 to limit
         randList = 1:len(MatchingList)
         rand1 = random(len(MatchingList)-1)+1
         rand2 = random(1)+1
         if rand2 = 1
            temp = MatchingList[rand1][1]
         else
            temp = MatchingList[rand1][2]
         ok
         add(WordList,temp)
         del(MatchingList,rand1)
     next

#============================
# set buttons colour to gray
#============================

func pSetColourGray()

     for n = 1 to size1
         for m = 1 to size2
             Button[n][m].setstylesheet(C_StyleGray)
         next
     next

#============================
# check if the word completed
#============================

func checkLetters

     pSetColourGray()

     for row = 1 to size1                        // search words in rows
         rowWord[row] = ""
         for col = 1 to size2
             Button[row][col] { temp = text() }
             if temp = ""
                temp = " "
             ok
             rowWord[row] = rowWord[row] + temp
         next
         for word = 1 to len(WordList)
             findWord = substr(rowWord[row],WordList[word])
             if findWord > 0
                for n = 1 to len(WordList[word])
                    Button[row][findWord+n-1].setstylesheet(C_StyleYellow)
                next
             ok
         next
     next

     for col = 1 to size2                        // search words in columns
         colWord[col] = ""
         for row = 1 to size1
             Button[row][col] { temp = text() }
             if temp = ""
                temp = " "
             ok
             colWord[col] = colWord[col] + temp
         next
         for word = 1 to len(WordList)
             findWord = substr(colWord[col],WordList[word])
             if findWord > 0
                for n = 1 to len(WordList[word])
                    Button[findWord+n-1][col].setstylesheet(C_StyleYellow)
                next
             ok
         next
     next

#============================
# show the score
#============================

func checkLettersScore

     WordListScore = WordList
     score = 0
     labelShowScore.settext(string(score))

     for row = 1 to size1                        // search words in rows
         rowWord[row] = ""
         for col = 1 to size2
             Button[row][col] { temp = text() }
             if temp = ""
                temp = " "
             ok
             rowWord[row] = rowWord[row] + temp
         next
         for word = 1 to len(WordListScore)
             findWord = substr(rowWord[row],WordListScore[word])
             if findWord > 0
                    del(WordListScore,word)
                    score++
                    labelShowScore.settext(string(score))
             ok
         next
     next

     for col = 1 to size2                        // search words in columns
         colWord[col] = ""
         for row = 1 to size1
             Button[row][col] { temp = text() }
             if temp = ""
                temp = " "
             ok
             colWord[col] = colWord[col] + temp
         next
         for word = 1 to len(WordListScore)
             findWord = substr(colWord[col],WordListScore[word])
             if findWord > 0
                    del(WordListScore,word)
                    score++
                    labelShowScore.settext(string(score))
             ok
         next
     next

#=================================
# generate random letters of words
#=================================

func showLetters

        LettersList = []
        for n = 1 to len(WordList)
            for m = 1 to len(WordList[n])
                add(LettersList,WordList[n][m])
            next
        next
	LettersList = randomList(LettersList)
        lenLettersList = len(LettersList)

	randList = 1:(size1*size2)
	randList = randomList(randList)

	for n = 1 to size1
		for m = 1 to size2
			ind = (n-1)*12 + m
			PairsXY[ind][1] = n
			PairsXY[ind][2] = m
		next
	next

	for nr = 1 to lenLettersList
	    rand1 = random(len(randList)-1)+1
            letterNew = LettersList[nr]
	    row = pairsXY[rand1][1]
	    col = pairsXY[rand1][2]
            Button[row][col].settext(letterNew)
            del(PairsXY,rand1)                   // delete coordinate of rand1
	    del(randList,rand1)                  // delete rand1 random number
	next

        abcWord = sort(WordList)
        see "You must discover the words:" + nl + nl
        see abcWord

#================================
# handle the user click on button
#================================    

func pUserClick Row,Col

	if click = 1                                    // show letters of first click
		Button[Row][Col] { letter1 = text() 
                                   setStylesheet(C_StyleGreen)
                                 }
		row1 = Row
                col1 = Col
                click = 2
                return
	ok
	if click = 2                                    // show letters of second click
		Button[Row][Col] { letter2 = text()
		}
                row2 = Row
                col2 = Col
                Button[row1][col1] { settext(letter2)
                                     setStylesheet(C_StyleGray)
                                      }
                Button[row2][col2] { settext(letter1) 
                                     setStylesheet(C_StyleGray) }
                swap++
                labelShowSwap.settext(string(swap))
                checkLetters()
                checkLettersScore()
                click = 1
                return
	ok

#============================
# generate new game
#============================

func newGame

        click = 1
	labelShowTime.setText("0:00")
	time1 = clock()
	TimerMan.start()
	swap = 0
	labelShowSwap.settext("0")
        score = 0
        labelShowScore.settext(string(score))
        WordListScore   = WordList
	PairsXY = newlist(size1*size2,2)
        for n = 1 to size1
            for m = 1 to size2
                Button[n][m].settext("")
                Button[n][m].setstylesheet(C_StyleGray)
            next
        next
        createWordList()
	showLetters()

#============================
# function for timer
#============================

func timerMan

	nowTime    = ceil( (clock() - time1) / 1000 )
	nowMinute  = floor( nowTime / 60 )
	nowSeconds = nowTime % 60
        
	if nowSeconds < 10  
		nowSeconds = "0"+ nowSeconds
	ok

	nowMinSec  = ""+ nowMinute +":"+ nowSeconds        
	labelShowTime.setText(nowMinSec) 

#============================
# randomise input list
#============================

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

#============================
# close the game
#============================

func closeGame
	win.close()

#===================================================================================#
