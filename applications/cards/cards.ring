/*
** Application  : Cards Game
** Author       : Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "guilib.ring"

oGame = NULL

func main

	oApp = new qApp 
	
	oPic = new QPixmap(AppFile("cards.jpg"))
	oPic2 = oPic.copy(0,(124*4)+1,79,124)
	Player1EatPic = oPic.copy(80,(124*4)+1,79,124)
	Player2EatPic= oPic.copy(160,(124*4)+1,79,124)
	
	aGameCards = []
	aGameValues = []
	for x1 = 0 to 3
		for y1 = 0 to 12
			temppic = oPic.copy((79*y1)+1,(124*x1)+1,79,124)
			aGameCards + temppic
			aGameValues + (y1+1)
		next
	next
	
	nPlayer1Score = 0   nPlayer2Score=0
	
	do
		oGame = new Game {
			loadGame(oApp,oPic,oPic2,Player1EatPic,Player2EatPic,
				 aGameCards,aGameValues,nPlayer1Score,nPlayer2Score)
			Start()
		}
		nPlayer1Score = oGame.nPlayer1Score 
		nPlayer2Score = oGame.nPlayer2Score
	again oGame.lnewgame
	
	oPic.delete()
	oPic2.delete()
	Player1EatPic.delete()
	Player2EatPic.delete()
	
	for t in aGameCards
	          t.delete()
	next
		
class Game

        if ismobile()
		nCardsCount = 5
		nScale = 3
        else
		nCardsCount = 10
		nScale = 1
        ok

	oApp oPic oPic2 Player1EatPic Player2EatPic aGameCards aGameValues
	nPlayer1Score nPlayer2Score
	
        win1 layout1 label1 label2 layout2 layout3 aBtns aBtns2
        aCards nRole=1 aStatus = list(nCardsCount) aStatus2 = aStatus
        aValues        aStatusValues = aStatus  aStatusValues2 = aStatus
        lnewgame = false
        nDelayEat = 0.5
        nDelayNewGame = 1

	func loadgame p1,p2,p3,p4,p5,p6,p7,p8,p9
		oApp=p1 oPic=p2 oPic2=p3 
		Player1EatPic=p4 Player2EatPic=p5
		aGameCards=p6 aGameValues=p7 
		nPlayer1Score=p8 nPlayer2Score=p9

        func start

                win1 = new qWidget() {
                        setwindowtitle("Five")
                        setstylesheet("background-color: White")
                        showfullscreen()
                }

                layout1 = new qvboxlayout()

                label1 = new qlabel(win1) {
                        settext("Player (1) - Score : " + this.nPlayer1Score)
                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                        setstylesheet("color: White; background-color: Purple;
                                         font-size:20pt")
                        setfixedheight(200)
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
                        if ismobile()
                            setfixedheight(100)
                        ok
                }

                aCards = aGameCards
                aValues = aGameValues

                layout2 = new qhboxlayout()

                aBtns = []

                for x = 1 to nCardsCount
                        aBtns + new qpushbutton(win1)
                        aBtns[x].setfixedwidth(79*nScale)
                        aBtns[x].setfixedheight(124*nScale)
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
                        setfixedheight(200)
                }

                layout3 = new qhboxlayout()

                aBtns2 = []
                for x = 1 to nCardsCount
                        aBtns2 + new qpushbutton(win1)
                        aBtns2[x].setfixedwidth(79*nScale)
                        aBtns2[x].setfixedheight(124*nScale)
                        setButtonImage(aBtns2[x],oPic2)
                        layout3.addwidget(aBtns2[x])
                        aBtns2[x].setclickevent("oGame.Player2click("+x+")")
			setButtonStyle(aBtns2[x])
                next

                layout1.addwidget(label2)
                layout1.addlayout(layout3)
                layout1.addwidget(closebtn)

                win1.setlayout(layout1)

                oApp.exec()

	func setButtonImage oBtn,oPixmap
	        oBtn {
	                setIcon(new qicon(oPixmap.scaled(width(),height(),0,0)))
	                setIconSize(new QSize(width(),height()))
	        }
	
	func setButtonStyle oBtn
		if ismobile()
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
                ok
 
        func Player1Eat nPos,nValue
                 oApp.processEvents()
                 delay(nDelayEat)
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
                 delay(nDelayEat)
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
			oApp.processEvents()
			delay(nDelayNewGame)
			win1.delete()
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

        func delay x
		nTime = x * 1000
		oTest = new qTest
		oTest.qsleep(nTime)
