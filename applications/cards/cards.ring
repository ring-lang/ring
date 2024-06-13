/*
** Application  : Cards Game
** Author       : Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "stdlibcore.ring"
load "lightguilib.ring"

# Global variables and constants used by the main menu 

	oGame 			= NULL
	oApp  	  		= NULL   
	winMenu 		= NULL

	C_GAMEMODE_ONEPLAYER 	= 1
	C_GAMEMODE_TWOPLAYERS 	= 2
	nGameMode 		= C_GAMEMODE_TWOPLAYERS

   	C_LABEL_STYLE = "font-size: 48px ; color : White ; background-color: Purple ;"

        C_BUTTON_STYLE ="QPushButton{font-size: 28px ;background-color:navy;border:2px solid #9977fa;
			 border-radius:7px;color:lightblue;} 
			 QPushButton:hover{font-size: 28px ;color:navy;background-color:lightblue;} 
			 QPushButton:pressed{font-size: 28px ;color:#aaa;background-color:#33116a; }"

	new QDesktopWidget() {
		C_WIDTH  = width()
		C_HEIGHT = height()
		C_BUTTONHEIGHT = floor( C_HEIGHT * 0.13 )
	}

func main
	oApp = new qApp {
		winMenu = new qWidget() {
			setWindowTitle("The Cards Game")
			setstylesheet("background-color: white;")	
			oCardsLabel = new qLabel(winMenu) {
				setText("The Cards Game")
				setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
				setFixedheight(C_BUTTONHEIGHT)
				setstylesheet(C_LABEL_STYLE)
			}
			oBtnOnePlayer = new qPushbutton(winMenu) {
				setText("One Player")
				setFixedheight(C_BUTTONHEIGHT)
				setstylesheet(C_BUTTON_STYLE)
				setclickevent("OnePlayer()")
			}
			oBtnTwoPlayers = new qPushbutton(winMenu) {
				setText("Two Players")
				setFixedheight(C_BUTTONHEIGHT)
				setstylesheet(C_BUTTON_STYLE)
				setclickevent("TwoPlayers()")
			}
			oBtnExit = new qPushbutton(winMenu) {
				setText("Exit")
				setFixedheight(C_BUTTONHEIGHT)
				setstylesheet(C_BUTTON_STYLE)
				setClickevent("CloseGame()")
			}
			oMainLayout = new qVBoxlayout() {
				AddWidget(oCardsLabel)
				AddWidget(oBtnOnePlayer)
				AddWidget(oBtnTwoPlayers)
				AddWidget(oBtnExit)
			}
			setLayout(oMainLayout)
			showfullscreen()
		}
		exec()
	}

func OnePlayer
	nGameMode = C_GAMEMODE_ONEPLAYER 
	LoadCardsGame()

func TwoPlayers
	nGameMode = C_GAMEMODE_TWOPLAYERS
	LoadCardsGame()

func CloseGame
	winMenu.close()
	oApp.quit()

func LoadCardsGame 
	# Load Images	
		oPic 		= new QPixmap(AppFile("cards.jpg"))
		oPic2 		= oPic.copy(0,(124*4)+1,79,124)
		Player1EatPic 	= oPic.copy(80,(124*4)+1,79,124)
		Player2EatPic	= oPic.copy(160,(124*4)+1,79,124)		
		aGameCards 	= []
		aGameValues 	= []
		for x1 = 0 to 3
			for y1 = 0 to 12
				temppic = oPic.copy((79*y1)+1,(124*x1)+1,79,124)
				aGameCards  + temppic
				aGameValues + (y1+1)
			next
		next
	# Start the Game		
		nPlayer1Score = 0   nPlayer2Score=0
		do
			oGame = new Game {
				loadGame(oPic,oPic2,Player1EatPic,Player2EatPic,aGameCards,aGameValues,nPlayer1Score,nPlayer2Score)
				Start()			
			}
			nPlayer1Score = oGame.nPlayer1Score 
			nPlayer2Score = oGame.nPlayer2Score
		again oGame.lnewgame

class Game

	# Setting properties based on platform
		C_BTNIMAGEWIDTH  = floor( C_WIDTH * 0.057 )
		C_BTNIMAGEHEIGHT = floor( C_HEIGHT * 0.16 )

		C_PLAYERTITLEHEIGHT = floor( C_HEIGHT * 0.16 )
		C_CLOSEBTNHEIGHT    = floor( C_HEIGHT * 0.13 )

	        if isMobile() or isWebAssembly()
			nCardsCount = 5
	        else
			nCardsCount = 10
	        ok
	
	# From the Game State
		oPic 		oPic2 
		Player1EatPic 	Player2EatPic 
		aGameCards 	aGameValues
		nPlayer1Score 	nPlayer2Score
	
	# The Game Window	
	        win1 layout1 label1 label2 layout2 layout3 aBtns aBtns2
	        aCards nRole=1 aStatus = list(nCardsCount) aStatus2 = aStatus
	        aValues        aStatusValues = aStatus  aStatusValues2 = aStatus
	
	# Playing with the computer 
		oOnePlayerTimer  
		aComputerActions = []
	
	# More attributes
	        lnewgame 	= false
	        nDelayEat 	= 0.5
	        nDelayNewGame 	= 0.5
		nDelayComputer  = 0.3
	
	func loadGame poPic,poPic2,pPlayer1Eatpic,pPlayer2Eatpic,paGameCards,paGameValues,pnPlayer1Score,pnPlayer2Score
		oPic		= poPic 
		oPic2		= poPic2 
		Player1EatPic	= pPlayer1EatPic 
		Player2EatPic	= pPlayer2EatPic
		aGameCards	= paGameCards 
		aGameValues	= paGameValues
		nPlayer1Score	= pnPlayer1Score 
		nPlayer2Score	= pnPlayer2Score

        func start
                win1 = new qDialog(null) {
			setAttribute(Qt_WA_DeleteOnClose,True)
                        setwindowtitle("Five")
                        setstylesheet("background-color: White")  
                }

                layout1 = new qvboxlayout()

                label1 = new qlabel(win1) {
                        settext("Player (1) - Score : " + this.nPlayer1Score)
                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                        setstylesheet("color: White; background-color: Purple;
                                         font-size:20pt")
                        setfixedheight(this.C_PLAYERTITLEHEIGHT)
                }

                closebtn = new qpushbutton(win1)  {
                        settext("Close Application")
                        setstylesheet("font-size: 18px ; color : white ;
                                         background-color: black ;
                                         border-style: outset;
                                         border-width: 2px;
                                         border-radius: 4px;
                                         border-color: black;
                                         padding: 6px;
                                        ")
                        setclickevent("oGame.win1.close()")
                        if isMobile() or isWebAssembly()
                            setfixedheight(this.C_CLOSEBTNHEIGHT)
                        ok
                }

                aCards = aGameCards
                aValues = aGameValues

                layout2 = new qhboxlayout()

                aBtns = []

                for x = 1 to nCardsCount
                        aBtns + new qpushbutton(win1)
                        aBtns[x].setfixedwidth(this.C_BTNIMAGEWIDTH)
                        aBtns[x].setfixedheight(this.C_BTNIMAGEHEIGHT)
                        setButtonImage(aBtns[x],oPic2)
                        layout2.addwidget(aBtns[x])
                        aBtns[x].setclickevent("oGame.Player1click("+x+")")
			setButtonStyle(aBtns[x])
                next

                layout1.addwidget(label1)
                layout1.addlayout(layout2)

                label2 = new qlabel(win1) {
                        settext("Player (2) - Score : " + this.nPlayer2Score)
                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                        setstylesheet("color: white; background-color: red;
                                         font-size:20pt")
                        setfixedheight(this.C_PLAYERTITLEHEIGHT)
                }

                layout3 = new qhboxlayout()

                aBtns2 = []
                for x = 1 to nCardsCount
                        aBtns2 + new qpushbutton(win1)
                        aBtns2[x].setfixedwidth(this.C_BTNIMAGEWIDTH)
                        aBtns2[x].setfixedheight(this.C_BTNIMAGEHEIGHT)
                        setButtonImage(aBtns2[x],oPic2)
                        layout3.addwidget(aBtns2[x])
                        aBtns2[x].setclickevent("oGame.Player2click("+x+")")
			setButtonStyle(aBtns2[x])
                next

                layout1.addwidget(label2)
                layout1.addlayout(layout3)
                layout1.addwidget(closebtn)

                win1.setlayout(layout1)

		if nGameMode = C_GAMEMODE_ONEPLAYER
			oOnePlayerTimer = new qTimer(win1) {
				setinterval(200)
				settimeoutevent("oGame.ComputerAction()")
				start()
			}
		ok

		win1.showfullscreen()

		if ! isWebAssembly()
			win1.exec()
		ok

	func setButtonImage oBtn,oPixmap
	        oBtn {
	                setIcon(new qicon(oPixmap.scaled(width(),height(),0,0)))
	                setIconSize(new QSize(width(),height()))
	        }
	
	func setButtonStyle oBtn
		if isMobile() or isWebAssembly()
			oBtn.setStyleSheet("
			border-style: outset;
			border-width: 2px;
			border-radius: 4px;
			border-color: black;
			padding: 6px;")
		ok

        func Player1Click x
                if nRole = 1 and aStatus[x] = 0
                        nPos = ((random(100)+clock())%(len(aCards)-1)) + 1
                        setButtonImage(aBtns[x],aCards[nPos])
                        del(aCards,nPos)
                        nRole = 2
                        aStatus[x] = 1
                        aStatusValues[x] = aValues[nPos]
                        del(aValues,nPos)
                        Player1Eat(x,aStatusValues[x])
                        checknewgame()
                ok

        func Player2Click x
                if nRole = 2 and aStatus2[x] = 0
                        nPos = ((random(100)+clock())%(len(aCards)-1)) + 1
                        setButtonImage(aBtns2[x],aCards[nPos])
                        del(aCards,nPos)
                        nRole = 1
                        aStatus2[x] = 1
                        aStatusValues2[x] = aValues[nPos]
                        del(aValues,nPos)
                        Player2Eat(x,aStatusValues2[x])
                        checknewgame()
			if nGameMode = C_GAMEMODE_ONEPLAYER
				sleep(nDelayComputer)
				ComputerAction()
			ok
                ok
 
        func Player1Eat nPos,nValue
                 oApp.processEvents()
                 sleep(nDelayEat)
                 lEat = false
                 for x = 1 to nCardsCount
                         if aStatus2[x] = 1 and (aStatusValues2[x] = nValue or nValue=5)
                                aStatus2[x] = 2
                                setButtonImage(aBtns2[x],Player1EatPic)
                                lEat = True
                                nPlayer1Score++
                         ok
                         if (x != nPos) and (aStatus[x] = 1) and
                                (aStatusValues[x] = nValue or nValue=5)
                                aStatus[x] = 2
                                setButtonImage(aBtns[x],Player1EatPic)
                                lEat = True
                                nPlayer1Score++
                         ok
                 next
                 if lEat
			nPlayer1Score++
			setButtonImage(aBtns[nPos],Player1EatPic)
			aStatus[nPos] = 2
			label1.settext("Player (1) - Score : " + nPlayer1Score)
                 ok

        func Player2Eat nPos,nValue
                 oApp.processEvents()
                 sleep(nDelayEat)
                 lEat = false
                 for x = 1 to  nCardsCount
                         if aStatus[x] = 1 and (aStatusValues[x] = nValue or nValue = 5)
                                aStatus[x] = 2
                                setButtonImage(aBtns[x],Player2EatPic)
                                lEat = True
                                nPlayer2Score++
                         ok

                         if (x != nPos) and (aStatus2[x] = 1) and
                                (aStatusValues2[x] = nValue or nValue=5 )
                                aStatus2[x] = 2
                                setButtonImage(aBtns2[x],Player2EatPic)
                                lEat = True
                                nPlayer2Score++
                         ok
                 next
                 if lEat
			nPlayer2Score++
			setButtonImage(aBtns2[nPos],Player2EatPic)
			aStatus2[nPos] = 2
			label2.settext("Player (2) - Score : " + nPlayer2Score)
                 ok

        func checknewgame
                if isnewgame()
			lnewgame = true
			if nPlayer1Score > nPlayer2Score
				label1.settext("Player (1) Wins!!!")
			ok
			if nPlayer2Score > nPlayer1Score
				label2.settext("Player (2) Wins!!!")
			ok
			if nGameMode = C_GAMEMODE_ONEPLAYER
				oOnePlayerTimer.stop()
			ok
			oApp.processEvents()
			sleep(nDelayNewGame)
			win1.close()
                ok

        func isnewgame
                for t in aStatus
                        if t = 0
                                return false
                        ok
                next
                for t in aStatus2
                        if t = 0
                                return false
                        ok
                next
                return true

	func ComputerAction
		oOnePlayerTimer.stop()
		aOptions = 1:nCardsCount
		if len(aComputerActions) > 0
			for nNum in aComputerActions		
				nPos = find(aOptions,nNum)
				if nPos
					del(aOptions,nPos)
				ok
			next
		ok
		if len(aComputerActions) < nCardsCount
			# Repeat until you find new (unopened) card 
				nCardNumber = Random(len(aOptions))
				if nCardNumber = 0
					nCardNumber = 1
				ok
				nCardNumber = aOptions[nCardNumber]
			aComputerActions + nCardNumber
			Player1Click(nCardNumber)
		ok 
