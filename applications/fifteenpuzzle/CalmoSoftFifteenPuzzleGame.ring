# Project : CalmoSoft Fifteen Puzzle Game (Under Development)
# Author : Gal Zsolt (~ CalmoSoft ~), Bert Mariani, Mahmoud Fayed
# Email   : calmosoft@gmail.com

load "guilib.ring"

app1 = new qapp {

        stylefusionblack()
        empty = 16  
        nrMoves = 0
        nrSleep = 1
        butSize = 4 
        curBut = 4
        temp = 0
        flaginit = 0
        flagsave = 0
        flagmove = 0
        button = list(52)   
        sizebtn = list(7)
        table1 = [] 
        table2 = [] 
        table3 = []
        nDegree = 0
        nrDegree = [0,90,180,270 ,-90,-180,-270]
        nDegreeRight = 0
        nDegreeLeft = 0
        btnDegree = newlist(52,2)
        CounterMan = 0 
        t1 = 0

        win1 = new qwidget() {
                   move(0,0)
                   resize(380,760)
                   setwindowtitle("CalmoSoft Fifteen Puzzle Game")

                  for n=1 to 52
                        for m=1 to 2
                             btnDegree[n][m] = 0
                        next
                  next 

                   for n = 4 to 7
                               sizebtn[n] = new qpushbutton(win1)   
                               {
                                                  col = n%4
                                                  setgeometry(100+col*40,60,40,40)
                                                  settext(string(n) + "x" + string(n))
                                                  setclickevent("newsize(" + string(n) + ")")
                               } 
                   next    

                  btnMoves = new qpushbutton(win1)
                  {
                                 setgeometry(100,260,80,40)
                                 settext("0")
                                 show() 
                  }

                   scramblebtn = new qpushbutton(win1)
                   {
                                         setgeometry(100,300,160,40)
                                         settext("Scramble")
                                         setclickevent("scramble()")                        
                   }

                   resetbtn = new qpushbutton(win1)   
                   {
                                    setgeometry(100,340,160,40)
                                    settext("Reset")
                                    setclickevent("resettiles()")
                   }

                   savebtn = new qpushbutton(win1)   
                   {
                                   setgeometry(100,380,160,40)  
                                   settext("Save Game")  
                                   setclickevent("pSave()")
                   }

                   playbtn = new qpushbutton(win1)   
                   {
                                   setgeometry(100,420,160,40)  
                                   settext("Resume Game")  
                                   setclickevent("pPlay()")
                   }

                   sleepbtn = new qpushbutton(win1)   
                   {
                                   setgeometry(100,460,160,40)  
                                   settext("Sleep Time: ")  

                   }

                  decbtn = new qpushbutton(win1)   
                  {
                               setgeometry(220,460,40,40)  
                               settext("<-")  
                               setclickevent("pDecSleep()")
                  }

                  incbtn = new qpushbutton(win1)   
                  {
                               setgeometry(260,460,40,40)  
                               settext("->")  
                               setclickevent("pIncSleep()")
                  }

                 rightbtn = new qpushbutton(win1)   
                 {
                               setgeometry(100,500,160,40)  
                               settext("In the Right Place : ")  
                 }

                 timebtn = new qpushbutton(win1)   
                 {
                               setgeometry(100,540,160,40)  
                               settext("Elapsed Time : ")  
                 }

                TimerMan = new qtimer(win1)
               {
                                  setinterval(500)
                                  settimeoutevent("pTime()")
                                  stop()
               }
              newsize(4) 
              show()
        }
        exec()
}

Func newlist x, y
     if isstring(x) x=0+x ok
     if isstring(y) y=0+y ok
     alist = list(x)
     for t in alist
         t = list(y)
     next
     return alist

func scramble
       for n= 1 to 1000   
            curBut=random(butSize*butSize-1)+1
            up = (empty = (curBut - butSize))
            down = (empty = (curBut + butSize))
            left = ((empty = (curBut - 1)) and ((curBut % butSize) != 1))
            right = ((empty = (curBut + 1)) and ((curBut % butSize) != 0))
            move = up or down or left  or right
            if move = 1 
               button[curBut] { temp2 = text() }
               col = empty%butSize
               if col = 0 col = butSize ok
               row = ceil(empty/butSize)
               button[empty] {
                       setgeometry(60+col*40,60+row*40,40,40)
                       rnd = random(6)+1
                       nDegree = nrDegree[rnd]
                       button[empty].setbuttoncolor("yellow")
                       button[empty].settext(temp2)
                       button[empty].setClickEvent("movetile(" + string(empty) +")")
                       btnDegree[empty] [1] = temp2
                       btnDegree[empty] [2] = nDegree
                       }
               button[curBut].setbuttoncolor("yellow")
               btnDegree[curBut][2] = 0
               button[curBut]{settext("")}
               empty = curBut
            ok
       next
       button[butSize*butSize+2]{settext("Here")}
       for n=1 to butSize*butSize
             button[n].setbuttoncolor("yellow")
       next
       table1 = []
       table2 = []
       table3 = []   
       for n = 1 to butSize*butSize
             add(table1, button[n].text())
             add(table2, button[n].text())
             add(table3, string(btnDegree[n][2]))
       next
       add(table1, string(empty))
       add(table2, string(empty))
       add(table3, string(empty))
       add(table1, "OK")
       add(table2, "OK")
       add(table3, "OK")
       flagsave = 0
       flagmove = 0
       nrMoves = 0
       btnMoves.settext(string(nrMoves))
       timebtn.settext("Elapsed Time : ")
       t1 = clock()
       rightPlace()
       return

func movetile curBut2
       if (curBut2 = butSize*butSize-1 and button[curBut2].text() = "In")
           pBack()
       else
           see char(7)
           up = (empty = (curBut2 - butSize))
           down = (empty = (curBut2 + butSize))
           left = ((empty = (curBut2- 1)) and ((curBut2 % butSize) != 1))
           right = ((empty = (curBut2 + 1)) and ((curBut2 % butSize) != 0))
           move = up or down or left  or right
           if move = 1 
              temp2 = button[curBut2].text() 
              btnDegree[empty][1] = temp2
              add(table1, temp2)
              add(table2, string(curBut2))              
              col = empty%butSize
              if col = 0 col = butSize ok
              row = ceil(empty/butSize)
              button[empty] {
                                   setgeometry(60+col*40,60+row*40,40,40)
                                   nDegree = btnDegree[curBut2][2]
                                   btnDegree[empty][2] = nDegree
                                   button[empty].setbuttoncolor("orange")
                                   button[empty].settext(temp2)                                   
              }
              add(table3, string(nDegree))
              button[curBut2].setbuttoncolor("cyan")
              button[curBut2]{settext("")}
              empty = curBut2
              nrMoves = nrMoves + 1
              btnMoves.settext(string(nrMoves))
              isGameOver()
           ok
      ok 
      flagmove = 1
      pElapsedTime()
      rightPlace()
      return

func resettiles
        nDegree = 0  
        empty = butSize*butSize
        for empty = 1 to butSize*butSize-1
             btnDegree[empty][2] = 0
             nDegree = 0
             btnDegree[empty][1] = string(empty)
             button[empty].setstylesheet("background-color:yellow")
             button[empty] {settext(string(empty))}
        next
        button[butSize*butSize].setstylesheet("background-color:yellow")
        button[butSize*butSize] {settext("")}
        table1 = []
        table2 = []
        table3 = []   
        for n = 1 to butSize*butSize
             add(table1, button[n].text())
             add(table2, button[n].text())
             add(table3, string(btnDegree[n][2]))
        next
        add(table1, string(empty))
        add(table2, string(empty))
        add(table3, string(empty))
        add(table1, "OK")
        add(table2, "OK")
        add(table3, "OK")
        flagsave = 0
        flagmove = 0
        nrMoves = 0
        btnMoves.settext(string(nrMoves))
        timebtn.settext("Elapsed Time : ")
        t1 = clock()
        rightPlace()
        return

func pHere
        if button[butSize*butSize-1].text() != "" and button[butSize*butSize+2].text() = "Here"
           button[butSize*butSize-1] { temp = text() }
           button[butSize*butSize+2].close()
           button[butSize*butSize+2] = new ButtonWithRotatedText(win1)
           button[butSize*butSize+2] {
           setgeometry(60+(butSize-1)*40,60+(butSize+1)*40,40,40)
           setstylesheet("background-color:yellow")
           btnDegree[butSize*butSize+2][2] = btnDegree[butSize*butSize-1][2]
           nDegree = btnDegree[butSize*butSize+2][2]
           emptysave = empty
           empty = butSize*butSize+2
           btnDegree[empty][1] = temp
           settext(temp)
           }
           nDegree = 0
           empty = butSize*butSize-1
           btnDegree[empty][1] = "In"
           button[butSize*butSize-1]{settext("In")}
           for n = 1 to butSize*butSize
	   button[n].setenabled(false)
           next
           button[butSize*butSize-1].setenabled(true)
           scramblebtn.setenabled(false)
           resetbtn.setenabled(false)
           savebtn.setenabled(false)
           playbtn.setenabled(false)
           empty = emptysave
        ok

func pBack
        button[butSize*butSize+2] { temp = text() }
        nDegree = btnDegree[butSize*butSize+2][2]
        btnDegree[butSize*butSize-1][2] = btnDegree[butSize*butSize+2][2]
        emptysave = empty
        empty = butSize*butSize-1
        btnDegree[empty][1] = temp
        button[butSize*butSize-1] {settext(temp)}
        button[butSize*butSize+2].close()
        button[butSize*butSize+2] = new qpushbutton(win1)
                {
                setgeometry(60+(butSize-1)*40,60+(butSize+1)*40,40,40)
                settext("Here")
                setclickevent("pHere()")   
                show() 
                } 
        for n = 1 to butSize*butSize
              button[n].setenabled(true)
        next
        scramblebtn.setenabled(true)
        resetbtn.setenabled(true)
        savebtn.setenabled(true)
        playbtn.setenabled(true)
        empty = emptysave
        isGameOver()

func rotateleft
        if button[butSize*butSize+2].text() != "Here" 
           button[butSize*butSize+2].close()
           button[butSize*butSize+2] = new ButtonWithRotatedText(win1)
                      button[butSize*butSize+2] {
                      setgeometry(60+(butSize-1)*40,60+(butSize+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      nDegreeLeft = (nDegreeLeft-90)%360
                      nDegree = nDegreeLeft
                      btnDegree[butSize*butSize+2][2] = nDegree
                      emptysave = empty
                      empty = butSize*butSize+2
                      btnDegree[empty][1] = temp
                      button[butSize*butSize+2]{settext(temp)}
                      } 
                      empty = emptysave
        ok

func rotateright
        if button[butSize*butSize+2].text() != "Here"  
           button[butSize*butSize+2].close()
           button[butSize*butSize+2] = new ButtonWithRotatedText(win1)
                      button[butSize*butSize+2] {
                      setgeometry(60+(butSize-1)*40,60+(butSize+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      nDegreeRight = (nDegreeRight+90)%360
                      nDegree = nDegreeRight
                      btnDegree[butSize*butSize+2][2] = nDegree
                      emptysave = empty
                      empty = butSize*butSize+2
                      btnDegree[empty][1] = temp
                      button[butSize*butSize+2]{settext(temp)}
                      }
                      empty = emptysave
        ok

func newsize curBut
        win1{ 
                sizenew = curBut%4
                win1.resize(360+sizenew*40,640+sizenew*40)
                if flaginit != 0
                   for nb = 1 to butSize*butSize+3
                         button[nb] {close()}
                   next
                   btnMoves.close()
                ok
                scramblebtn.close()
                resetbtn.close()
                savebtn.close()
                playbtn.close()
                btnMoves.close()
                sleepbtn.close()
                decbtn.close()
                incbtn.close()
                rightbtn.close()
                timebtn.close()

                for n = 1 to curBut*curBut
                     col = n%curBut
                     if col = 0 col = curBut ok
                     row = ceil(n/curBut)
                     button[n] = new ButtonWithRotatedText(win1)
                                       button[n] {
                                       setgeometry(60+col*40,60+row*40,40,40)
                                       button[n].setbuttoncolor("yellow")                                       
                                       nDegree = 0
                                       if n < curBut*curBut
                                          button[n].settext(string(n))
                                       but n = curBut*curBut
                                          button[n].settext("")
                                       ok 
                                       setClickEvent("movetile(" + string(n) +")")
                                       }
                next

                btnMoves = new qpushbutton(win1)
                {
                                        setgeometry(100,60+(curBut+1)*40,(curBut-3)*40,40)
                                        setStyleSheet("text-align:center")
                                        settext("0")
                                        show() 
                }

                button[curBut*curBut+1] = new qpushbutton(win1)
                {
                                              setgeometry(60+(curBut-2)*40,60+(curBut+1)*40,40,40)
                                              settext("<-")
                                              setclickevent("rotateLeft()")   
                                              show() 
                } 

                button[curBut*curBut+2] = new qpushbutton(win1)
                {
                                             setgeometry(60+(curBut-1)*40,60+(curBut+1)*40,40,40)
                                             settext("Here")
                                             setclickevent("pHere()")   
                                             show() 
                }

                button[curBut*curBut+3] = new qpushbutton(win1)
                {
                                             setgeometry(60+curBut*40,60+(curBut+1)*40,40,40)
                                             settext("->")
                                             setclickevent("rotateRight()")   
                                             show() 
                 }

                scramblebtn = new qpushbutton(win1)
                {
                                      setgeometry(100,100+(curBut+1)*40,curBut*40,40)
                                      settext("Scramble")
                                      setclickevent("scramble()")
                                      show()                        
                }

                resetbtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(curBut+2)*40,curBut*40,40)
                                 settext("Reset")
                                 setclickevent("resettiles()")
                                 show() 
                }

                savebtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(curBut+3)*40,curBut*40,40)
                                 settext("Save Game")
                                 setclickevent("pSave()")
                                 show() 
                }

                playbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(curBut+4)*40,curBut*40,40)  
                               settext("Resume Game")  
                               setclickevent("pPlay()")
                               show()
                }

                sleepbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(curBut+5)*40,(curBut-2)*40,40)  
                               settext("Sleep Time: " + string(nrSleep) + " s")  
                               show()
                }

                decbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(curBut-2)*40,100+(curBut+5)*40,40,40)  
                               settext("<-")  
                               setclickevent("pDecSleep()")
                               show()
                }

                incbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(curBut-1)*40,100+(curBut+5)*40,40,40)  
                               settext("->")  
                               setclickevent("pIncSleep()")
                               show()
                }

               rightbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(curBut+6)*40,curBut*40,40)  
                               settext("In the Right Place : ")  
                               show()
                }

                timebtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(curBut+7)*40,curBut*40,40)  
                               settext("Elapsed Time : ")  
                               show()
                }

                table1 = []
                table2 = []
                table3 = []   
                for n = 1 to butSize*butSize
                      add(table1, button[n].text())
                      add(table2, button[n].text())
                      add(table3, string(0))
                next
                add(table1, string(empty))
                add(table2, string(empty))
                add(table3, string(empty))
                add(table1, "OK")
                add(table2, "OK")
                add(table3, "OK")
                empty = curBut*curBut
                butSize = curBut
                flaginit = 1
                flagsave = 0
                flagmove = 0
                nrMoves = 0
                timebtn.settext("Elapsed Time : ")
                t1 = clock()
                scramble()
                }

func pSave
        textedit1 = list2str(table1)
        textedit2 = list2str(table2)
        textedit3 = list2str(table3)
        chdir(currentdir())
        cName1 = "CalmoSoftPuzzle1.txt"
        cName2 = "CalmoSoftPuzzle2.txt"
        cName3 = "CalmoSoftPuzzle3.txt"
        write(cName1,textedit1)
        write(cName2,textedit2)
        write(cName3,textedit3)
         flagsave = 1   
         timebtn.settext("Elapsed Time : ")
         t1 = clock()
         return

func pPlay
        if  flagsave = 0 or flagmove = 0
            warning()  
        else
           chdir(currentdir())
           cName1 = "CalmoSoftPuzzle1.txt"
           textedit1 = read(cName1)
           table1 = str2list(textedit1)
           cName2 = "CalmoSoftPuzzle2.txt"
           textedit2 = read(cName2)
           table2 = str2list(textedit2)
           cName3 = "CalmoSoftPuzzle3.txt"
           textedit3 = read(cName3)
           table3 = str2list(textedit3)
           for empty = 1 to butSize*butSize
                button[empty].setbuttoncolor("yellow") 
                nDegree = number(table3[empty])
                btnDegree[empty][1] = table1[empty]
                button[empty] {settext(table1[empty])}
           next
           empty = number(table1[butSize*butSize + 1])
           CounterMan = butSize*butSize+2
           nrMoves = 0
           t1 = clock()
           TimerMan.start()
       ok

func pTime()
        if flagsave = 0 or flagmove = 0
           warning()    
        else
           CounterMan++
           pPlaySleep()
           sleep(nrSleep*1000) 
           pElapsedTime()
           if CounterMan = len(table1)
              TimerMan.stop()
           ok
        ok

func pPlaySleep
        see char(7)
        value = table1[CounterMan]
        place = table2[CounterMan]
        nDegree = number(table3[CounterMan])
        btnDegree[empty][1] = value
        button[empty].setbuttoncolor("orange")
        button[empty] {settext(value)}
        nDegree = 0
        button[number(place)].setbuttoncolor("cyan")
        button[number(place)] {settext("")}
        empty = number(place)        
        nrMoves = nrMoves + 1
        btnMoves.settext(string(nrMoves))

func pIncSleep
        nrSleep = nrSleep + 1 
        sleepbtn.settext("Sleep Time: " + string(nrSleep) + " s")

func pDecSleep
        if nrSleep > 1 
           nrSleep = nrSleep - 1
           sleepbtn.settext("Sleep Time: " + string(nrSleep) + " s")
        ok

func sleep(x)
        nTime = x 
        oTest = new qTest
        oTest.qsleep(nTime)
        return

func isGameOver
        flagend = 1
        for n=1 to butSize*butSize-1
              if button[n].text() != n or btnDegree[n][2] != 0
                 flagend = 0
                 exit
              ok
        next
        if flagend = 1
           new qmessagebox(win1) {
                   setwindowtitle("Game Over") 
                   settext("Congratulations!")
                   show()
                   }   
        ok   

func rightPlace
        count = 0
        for n=1 to butSize*butSize
             if button[n].text() = n and btnDegree[n][2] = 0
                count = count + 1
             ok
        next   
        rightbtn.settext("In the Right Place : " + count)

func warning
        new qmessagebox(win1) {
                setwindowtitle("Warning!") 
                settext("First you must play and save the game.")
                show()
                }         

func pElapsedTime
        t2 = (clock() - t1)/1000
        timebtn.settext("Elapsed Time : " + t2 + " s")

Class ButtonWithRotatedText

         oButton oLabel  cText="We are here"  nDegree = 30  nTransX = 50   nTransY = 0

func init( oParent)
        oButton = new qPushButton(oParent)
        oLabel  = new qLabel(oParent)
        oLabel.setAttribute(Qt_WA_TransparentForMouseEvents,True)
        oLabel.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.Show()
        return
    
func close()
        oLabel.close()
        oButton.close()
        return

func setstylesheet(x)
        oButton.setstylesheet(x)

func setgeometry( x,y,width,height)
        oButton.setgeometry(x,y,width,height)
        oLabel.setgeometry( x,y,width,height)
        
func setText( cValue)
        cText = cValue
        return
    
func Text() 
         return cText

func setTranslate( x,y )    
         nTransX = x
         nTransY = y		
         return

func TranslateOffsetX()
        return nTransX 

func TranslateOffsetY()
        return nTransY 
	
func setRotationDegree( nValue)
        nDegree = nValue
        return
    
func RotationDegree()
        return nDegree

func setClickEvent( cEvent)
        oButton.setClickEvent(cEvent)
        return
    
func braceend()
        draw() 
        return

func setEnabled(value)        
        oButton.setenabled(value)
        return	

 func setButtonColor(color)  
         colorIt = "background-color:" + color  
         oButton.setstylesheet(colorIt) 
         return
    	
func draw()
         picture = new qpicture()
         color   = new qcolor() { setrgb(0,0,255,255) }
         pen     = new qpen()   { setcolor(color) setwidth(10) }
                    
         painter = new qpainter() 
         {
                       begin(picture)        
                       setpen(pen)
                       oFont = new qfont("Courier New",12,75,0)
                       oFont.setpointsize(20)
                       setfont(oFont)
                       if nDegree = 0
                          if btnDegree[empty] [1]="In" p1 = -8 p2=0 
                          translate(p1,p2) ok ok
                       if nDegree = 0
                          if btnDegree[empty] [1]<10 p1 = 10 p2=10 else p1=5 p2=10 ok
                          translate(p1,p2)
                       but nDegree = 90
                             if btnDegree[empty] [1]<10 p=-10 else p=-15 ok
                             translate(10,p)
                       but nDegree = 180
                              if btnDegree[empty] [1]<10 p1= 30 p2=-10 else p1=35 p2=-10 ok
                              translate(p1,p2)
                       but nDegree = 270
                             if btnDegree[empty] [1]<10 p=10 else p=15 ok
                             translate(30,p)
                       but nDegree = -90
                             if btnDegree[empty] [1]<10 p=10 else p=15 ok
                             translate(30,p)
                       but nDegree = -180
                              if btnDegree[empty] [1]<10 p1=30 p2=-10 else p1=35 p2=-10 ok
                              translate(p1,p2)
                       but nDegree = -270
                             if btnDegree[empty] [1]<10 p1=10 p2=-10 else p1=10 p2=-15 ok
                             translate(p1,p2)
                       ok						
                       rotate(nDegree)
	          drawtext(0,0,this.Text())   
                       endpaint()
         }
         oLabel {
                    setpicture(picture)  
                     show() 
                    }
         return
