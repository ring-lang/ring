
//(IS442 –Yousef Alyahya)
Load "guilib.ring"

nScale = 1

app1 = new qApp

mypic = new QPixmap("cards.jpg")

mypic2 = mypic.copy(0,(124*4)+1,79,124)
Player1EatPic = mypic.copy(80,(124*4)+1,79,124)
Player2EatPic= mypic.copy(160,(124*4)+1,79,124)

aMyCards = []
aMyValues = []
for x1 = 0 to 3
        for y1 = 0 to 12
          temppic = mypic.copy((79*y1)+1,(124*x1)+1,79,124)
                  aMyCards + temppic
                  aMyValues + (y1+1)
        next
next

nPlayer1Score = 0   nPlayer2Score=0

do
        Page1 = new Game
        Page1.Start()
again Page1.lnewgame

mypic.delete()
mypic2.delete()
Player1EatPic.delete()
Player2EatPic.delete()

for t in aMyCards
          t.delete()
next

func gui_setbtnpixmap pBtn,pPixmap
        pBtn {
                setIcon(new qicon(pPixmap.scaled(width(),height(),0,0)))
                setIconSize(new QSize(width(),height()))
        }

Class Game

        nCardsCount = 10
        win1 layout1 label1 label2 layout2 layout3 aBtns aBtns2
        aCards nRole=1 aStatus = list(nCardsCount) aStatus2 = aStatus
        aValues        aStatusValues = aStatus  aStatusValues2 = aStatus
        Player1EatPic   Player2EatPic
        lnewgame = false
        nDelayEat = 0.5
        nDelayNewGame = 1

        func start

                win1 = new qWidget() {
                        setwindowtitle("Five")
                        setstylesheet("background-color: White")
                        showfullscreen()
                }

                layout1 = new qvboxlayout()

                label1 = new qlabel(win1) {
                        settext("Player (1) - Score : " + nPlayer1Score)
                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                        setstylesheet("color: White; background-color: Purple;
                                         font-size:20pt")
                        setfixedheight(200)
                }

                closebtn = new qpushbutton(win1)  {
                        settext("Close Application")
                        setstylesheet("font-size: 18px ; color : white ;
                                         background-color: black ;")
                        setclickevent("Page1.win1.close()")
                }

                aCards = aMyCards
                aValues = aMyValues

                layout2 = new qhboxlayout()

                aBtns = []

                for x = 1 to nCardsCount
                        aBtns + new qpushbutton(win1)
                        aBtns[x].setfixedwidth(79*nScale)
                        aBtns[x].setfixedheight(124*nScale)
                        gui_setbtnpixmap(aBtns[x],mypic2)
                        layout2.addwidget(aBtns[x])
                        aBtns[x].setclickevent("Page1.Player1click("+x+")")
                next

                layout1.addwidget(label1)
                layout1.addlayout(layout2)

                label2 = new qlabel(win1) {
                        settext("Player (2) - Score : " + nPlayer2Score)
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
                        gui_setbtnpixmap(aBtns2[x],mypic2)
                        layout3.addwidget(aBtns2[x])
                        aBtns2[x].setclickevent("Page1.Player2click("+x+")")
                next

                layout1.addwidget(label2)
                layout1.addlayout(layout3)
                layout1.addwidget(closebtn)

                win1.setlayout(layout1)

                app1.exec()

        Func Player1Click x
                if nRole = 1 and aStatus[x] = 0
                        nPos = ((random(100)+clock())%(len(aCards)-1)) + 1
                        gui_setbtnpixmap(aBtns[x],aCards[nPos])
                        del(aCards,nPos)
                        nRole = 2
                        aStatus[x] = 1
                        aStatusValues[x] = aValues[nPos]
                        del(aValues,nPos)
                        Player1Eat(x,aStatusValues[x])
                        checknewgame()
                ok

        Func Player2Click x
                if nRole = 2 and aStatus2[x] = 0
                        nPos = ((random(100)+clock())%(len(aCards)-1)) + 1
                        gui_setbtnpixmap(aBtns2[x],aCards[nPos])
                        del(aCards,nPos)
                        nRole = 1
                        aStatus2[x] = 1
                        aStatusValues2[x] = aValues[nPos]
                        del(aValues,nPos)
                        Player2Eat(x,aStatusValues2[x])
                        checknewgame()
                ok

        Func Player1Eat nPos,nValue

                 app1.processEvents()

                 delay(nDelayEat)
                 lEat = false
                 for x = 1 to nCardsCount
                         if aStatus2[x] = 1 and (aStatusValues2[x] = nValue or nValue=5)
                                aStatus2[x] = 2
                                gui_setbtnpixmap(aBtns2[x],Player1EatPic)
                                lEat = True
                                nPlayer1Score++
                         ok
                         if (x != nPos) and (aStatus[x] = 1) and
                                (aStatusValues[x] = nValue or nValue=5)
                                aStatus[x] = 2
                                gui_setbtnpixmap(aBtns[x],Player1EatPic)
                                lEat = True
                                nPlayer1Score++
                         ok
                 next
                 if lEat
                                nPlayer1Score++
                                gui_setbtnpixmap(aBtns[nPos],Player1EatPic)
                                aStatus[nPos] = 2
                                label1.settext("Player (1) - Score : " + nPlayer1Score)
                 ok

        Func Player2Eat nPos,nValue

                 app1.processEvents()

                 delay(nDelayEat)
                 lEat = false
                 for x = 1 to  nCardsCount
                         if aStatus[x] = 1 and (aStatusValues[x] = nValue or nValue = 5)
                                aStatus[x] = 2
                                gui_setbtnpixmap(aBtns[x],Player2EatPic)
                                lEat = True
                                nPlayer2Score++
                         ok

                         if (x != nPos) and (aStatus2[x] = 1) and
                                (aStatusValues2[x] = nValue or nValue=5 )
                                aStatus2[x] = 2
                                gui_setbtnpixmap(aBtns2[x],Player2EatPic)
                                lEat = True
                                nPlayer2Score++
                         ok
                 next
                 if lEat
                                nPlayer2Score++
                                gui_setbtnpixmap(aBtns2[nPos],Player2EatPic)
                                aStatus2[nPos] = 2
                                label2.settext("Player (2) - Score : " + nPlayer2Score)
                 ok

        Func checknewgame
                if isnewgame()
                                  lnewgame = true

                                  if nPlayer1Score > nPlayer2Score
                                         label1.settext("Player (1) Wins!!!")
                                  ok
                                  if nPlayer2Score > nPlayer1Score
                                         label2.settext("Player (2) Wins!!!")
                                  ok

                                  app1.processEvents()
                                  delay(nDelayNewGame)

                                  win1.delete()
                                  app1.quit()
                ok

        Func isnewgame
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

        Func delay x
        nTime = x * 1000
        oTest = new qTest
        oTest.qsleep(nTime)
