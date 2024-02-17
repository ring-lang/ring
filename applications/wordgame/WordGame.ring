# Project : CalmoSoft Word Game
# Date    : 07/05/2020-04:01:01
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

#===================================================================================#
# Load the required libraries 
#===================================================================================#

	load "stdlibcore.ring"
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
        scoreOld        = 0
        checkScore      = 0
        checkVoice      = 0
        wordVoice       = 0 
        nNumberOfMoves  = 0               
	
        WordList2       = []
        WordList3       = []
        WordList4       = []
	limit		= 6
	
	Button		= list(size1,size2)    // main buttons for letters
	PairsXY		= list(size1*size2,2)  // store coordinates (x,y) of cells
        rowWord         = list(size1)
        colWord         = list(size2)
        labelWord       = list(limit)
	
	LayoutButtonRow2 = list(size1)             // Layout for buttons
        WordListSave     = WordList
        WordListScore    = []

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
		LayoutButtonRow7 = new QVBoxLayout()
		
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

                for n = 1 to 2
	            labelWord[n] = new QLabel(win) {
			           setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                                   setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
		    }
                    LayoutButtonRow7.AddWidget(labelWord[n])
                next

		LayoutButtonMain.AddLayout(LayoutButtonRow7)

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

		buttonSolve = new QPushButton(win) {
			setFont(new qFont("Verdana",C_FONTSIZE,50,0))
			settext("Solve")
			setClickEvent("pSolve()") 
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
                        AddWidget(buttonSolve)
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
                showWordList()
		show()
	}
	exec()
}

#===================================================================================#
# Game Logic
#===================================================================================#

#============================
# show full words list
#============================

func pSolve()

     for n = 1 to size1
         for m = 1 to size2
             Button[n][m].settext("")
             Button[n][m].setstylesheet(C_StyleGray)
         next
     next

     rowList = 1:12
     for n = 1 to 6
         rowind = random(len(rowList)-1)+1
         row = rowList[rowind]
         word = WordList2[n]
         lenWord = len(word)
         len = 12 - lenWord
         rand2 = random(len-1)+1
         col = 0
         for m = rand2 to rand2+lenWord-1
             col = col + 1
             temp = word[col]
             Button[row][m].settext(temp)
         next
         del(rowList,rowind)
     next


     ListWord = WordList2
     listWords1 = ListWord[1] + " -- " + ListWord[2] + " -- " + ListWord[3]
     listWords2 = ListWord[4] + " -- " + ListWord[5] + " -- " + ListWord[6]
     labelWord[1].settext(listWords1)
     labelWord[2].settext(listWords2)
     labelShowSwap.settext("0")
     score = 6
     labelShowScore.settext(string(score))
     pSetEnabledFalse()

#============================
# show words list in label
#============================

func pSetEnabledFalse
     for n = 1 to size1
         for m = 1 to size2
             Button[n][m].setenabled(false)
         next
     next

#============================
# show words list in label
#============================

func showWordList()

     ListWord = WordList2
     for n = 1 to len(ListWord)
         len = len(ListWord[n])
         temp = random(len-1)+1
         ListWord[n][temp] = "?"
     next
     listWords1 = ListWord[1] + " -- " + ListWord[2] + " -- " + ListWord[3]
     listWords2 = ListWord[4] + " -- " + ListWord[5] + " -- " + ListWord[6]
     labelWord[1].settext(listWords1)
     labelWord[2].settext(listWords2)
     nNumberOfMoves = len(ListWord[1]) + len(ListWord[2]) + len(ListWord[3]) +
                      len(ListWord[4]) + len(ListWord[5]) + len(ListWord[6]) + 15

#============================
# create words list
#============================

func createWordList()

     if len(WordList) < 10
        WordList = MatchingListSave
     ok

     for n = 1 to len(WordList)
         if len(WordList[n][1]) > 10
            del(WordList,n)
         ok
         if len(WordList[n][2]) > 10
            del(WordList,n)
         ok
     next

     WordList2 = []
     for n = 1 to limit
         randList = 1:len(WordList)
         rand1 = random(len(WordList)-1)+1
         rand2 = random(1)+1
         if rand2 = 1
            temp = WordList[rand1][1]
         else
            temp = WordList[rand1][2]
         ok
         add(WordList2,temp)
         del(WordList,rand1)
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
         for word = 1 to len(WordList2)
             findWord = substr(rowWord[row],WordList2[word])
             if findWord > 0
                for n = 1 to len(WordList2[word])
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
         for word = 1 to len(WordList2)
             findWord = substr(colWord[col],WordList2[word])
             if findWord > 0
                for n = 1 to len(WordList2[word])
                    Button[findWord+n-1][col].setstylesheet(C_StyleYellow)
                next
             ok
         next
     next

#============================
# show the score
#============================

func checkLettersScore

     scoreOld = score
     WordListScore = WordList2
     WordListTemp = WordListScore
     score = 0
     labelShowScore.settext(string(score))
     checkVoice = 0

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
                    if score = 6
                       labelWord[1].settext("You Win!")
                       labelWord[2].settext("")
                       pSetEnabledFalse()
                       TimerMan.stop()
                    ok
                    checkVoice = 1
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
                    if score = 6
                       labelWord[1].settext("You Win!")
                       labelWord[2].settext("")
                       pSetEnabledFalse()
                       TimerMan.stop()
                    ok
                    checkVoice = 1
             ok
         next
     next

#=================================
# generate random letters of words
#=================================

func showLetters

        LettersList = []
        for n = 1 to len(WordList2)
            for m = 1 to len(WordList2[n])
                add(LettersList,WordList2[n][m])
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

#================================
# handle the user click on button
#================================    

func pUserClick Row,Col

        WordListTemp = WordListScore
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
                if swap > nNumberOfMoves
                   labelWord[1].settext("Game Over!")
                   labelWord[2].settext("")
                   TimerMan.stop()
                   pSetEnabledFalse()
                   for n = 1 to size1
                       for m = 1 to size2
                           Button[n][m].setenabled(false)
                       next
                   next
                ok

                checkLetters()
                checkLettersScore()

                len1 = len(WordListTemp)
                len2 = len(WordListScore)
                if len1 > len2
                   for n = 1 to len2
                       temp = WordListScore[n]
                       ind = find(WordListTemp,temp)
                       del(WordListTemp,ind)
                   next
                   wordVoice = WordListTemp[1]
                ok

                if (score > scoreOld)
                    voice = new QTextToSpeech(win) {
                            say(wordVoice) }
                ok

                click = 1
                return
	ok

#============================
# generate new game
#============================

func newGame

        click = 1
        checkVoice = 0 
	labelShowTime.setText("0:00")
	time1 = clock()
	TimerMan.start()
	swap = 0
	labelShowSwap.settext("0")
        score = 0
        labelShowScore.settext(string(score))
        WordListScore   = WordList2
	PairsXY = list(size1*size2,2)
        for n = 1 to size1
            for m = 1 to size2
                Button[n][m].settext("")
                Button[n][m].setenabled(true)
                Button[n][m].setstylesheet(C_StyleGray)
            next
        next
        createWordList()
	showLetters()
        showWordList()

#============================
# function for timer
#============================

func timerMan

	nowTime    = floor( (clock() - time1) / clockspersecond() )
	nowMinute  = floor( nowTime / 60 )
	nowSeconds = nowTime % 60
        
	if nowSeconds < 10  
		nowSeconds = "0"+ nowSeconds
	ok

	nowMinSec  = ""+ nowMinute +":"+ nowSeconds        
	labelShowTime.setText(nowMinSec) 

#============================
# close the game
#============================

func closeGame
	win.close()

#===================================================================================#
