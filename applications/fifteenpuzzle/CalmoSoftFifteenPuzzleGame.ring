# Project : CalmoSoft Fifteen Puzzle Game (Under Development)
# Author: Gal Zsolt (~ CalmoSoft ~), Bert Mariani, Mahmoud Fayed

load "guilib.ring"

app1 = new qapp {

        stylefusionblack()
        empty = 16  
        nrMoves = 0
        nrSleep = 1
        OldButSize = 4 
        CurButSize = 4
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
        LabelSizeX = 40
        offSetX    = LabelSizeX / 2
        LabelSizeY = 40
        offSetY    = LabelSizeY / 2
        nDegreeRight = 0
        nDegreeLeft = 0
        btnDegree = newlist(52,2)
        CounterMan = 0 

        win1 = new qwidget() {
                   move(0,0)
                   resize(380,680)
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
            CurButSize=random(OldButSize*OldButSize-1)+1
            up = (empty = (CurButSize - OldButSize))
            down = (empty = (CurButSize + OldButSize))
            left = ((empty = (CurButSize - 1)) and ((CurButSize % OldButSize) != 1))
            right = ((empty = (CurButSize + 1)) and ((CurButSize % OldButSize) != 0))
            move = up or down or left  or right
            if move = 1 
               button[CurButSize] { temp2 = text() }
               col = empty%OldButSize
               if col = 0 col = OldButSize ok
               row = ceil(empty/OldButSize)
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
               button[CurButSize].setbuttoncolor("yellow")
               btnDegree[CurButSize][2] = 0
               button[CurButSize]{settext("")}
               empty = CurButSize
            ok
       next
       button[OldButSize*OldButSize+2]{settext("Here")}
       for n=1 to OldButSize*OldButSize
             button[n].setbuttoncolor("yellow")
       next
       table1 = []
       table2 = []
       table3 = []   
       for n = 1 to OldButSize*OldButSize
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
       return

func movetile CurButSize2
       if (CurButSize2 = OldButSize*OldButSize-1 and button[CurButSize2].text() = "In")
           pBack()
       else
           up = (empty = (CurButSize2 - OldButSize))
           down = (empty = (CurButSize2 + OldButSize))
           left = ((empty = (CurButSize2- 1)) and ((CurButSize2 % OldButSize) != 1))
           right = ((empty = (CurButSize2 + 1)) and ((CurButSize2 % OldButSize) != 0))
           move = up or down or left  or right
           if move = 1 
              temp2 = button[CurButSize2].text() 
              btnDegree[empty][1] = temp2
              add(table1, temp2)
              add(table2, string(CurButSize2))              
              col = empty%OldButSize
              if col = 0 col = OldButSize ok
              row = ceil(empty/OldButSize)
              button[empty] {
                                   setgeometry(60+col*40,60+row*40,40,40)
                                   nDegree = btnDegree[CurButSize2][2]
                                   btnDegree[empty][2] = nDegree
                                   button[empty].setbuttoncolor("orange")
                                   button[empty].settext(temp2)
                                   see char(7)
              }
              add(table3, string(nDegree))
              button[CurButSize2].setbuttoncolor("cyan")
              button[CurButSize2]{settext("")}
              empty = CurButSize2
              nrMoves = nrMoves + 1
              btnMoves.settext(string(nrMoves))
           ok
      ok 
      flagmove = 1
      return

func resettiles
        nDegree = 0  
        empty = OldButSize*OldButSize
        for empty = 1 to OldButSize*OldButSize-1
             btnDegree[empty][2] = 0
             nDegree = 0
             btnDegree[empty][1] = string(empty)
             button[empty].setstylesheet("background-color:yellow")
             button[empty] {settext(string(empty))}
        next
        button[OldButSize*OldButSize].setstylesheet("background-color:yellow")
        button[OldButSize*OldButSize] {settext("")}
        table1 = []
        table2 = []
        table3 = []   
        for n = 1 to OldButSize*OldButSize
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
        return

func pHere
        if button[OldButSize*OldButSize-1].text() != "" and button[OldButSize*OldButSize+2].text() = "Here"
           button[OldButSize*OldButSize-1] { temp = text() }
           button[OldButSize*OldButSize+2].close()
           button[OldButSize*OldButSize+2] = new ButtonWithRotatedText(win1)
           button[OldButSize*OldButSize+2] {
           setgeometry(60+(OldButSize-1)*40,60+(OldButSize+1)*40,40,40)
           setstylesheet("background-color:yellow")
           btnDegree[OldButSize*OldButSize+2][2] = btnDegree[OldButSize*OldButSize-1][2]
           nDegree = btnDegree[OldButSize*OldButSize+2][2]
           emptysave = empty
           empty = OldButSize*OldButSize+2
           btnDegree[empty][1] = temp
           settext(temp)
           }
           nDegree = 0
           empty = OldButSize*OldButSize-1
           btnDegree[empty][1] = "In"
           button[OldButSize*OldButSize-1]{settext("In")}
           for n = 1 to OldButSize*OldButSize
	   button[n].setenabled(false)
           next
           button[OldButSize*OldButSize-1].setenabled(true)
           scramblebtn.setenabled(false)
           resetbtn.setenabled(false)
           savebtn.setenabled(false)
           playbtn.setenabled(false)
           empty = emptysave
        ok

func pBack
        button[OldButSize*OldButSize+2] { temp = text() }
        nDegree = btnDegree[OldButSize*OldButSize+2][2]
        btnDegree[OldButSize*OldButSize-1][2] = btnDegree[OldButSize*OldButSize+2][2]
        emptysave = empty
        empty = OldButSize*OldButSize-1
        btnDegree[empty][1] = temp
        button[OldButSize*OldButSize-1] {settext(temp)}
        button[OldButSize*OldButSize+2].close()
        button[OldButSize*OldButSize+2] = new qpushbutton(win1)
                {
                setgeometry(60+(OldButSize-1)*40,60+(OldButSize+1)*40,40,40)
                settext("Here")
                setclickevent("pHere()")   
                show() 
                } 
        for n = 1 to OldButSize*OldButSize
              button[n].setenabled(true)
        next
        scramblebtn.setenabled(true)
        resetbtn.setenabled(true)
        savebtn.setenabled(true)
        playbtn.setenabled(true)
        empty = emptysave

func rotateleft
        if button[OldButSize*OldButSize+2].text() != "Here" 
           button[OldButSize*OldButSize+2].close()
           button[OldButSize*OldButSize+2] = new ButtonWithRotatedText(win1)
                      button[OldButSize*OldButSize+2] {
                      setgeometry(60+(OldButSize-1)*40,60+(OldButSize+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      nDegreeLeft = (nDegreeLeft-90)%360
                      nDegree = nDegreeLeft
                      btnDegree[OldButSize*OldButSize+2][2] = nDegree
                      emptysave = empty
                      empty = OldButSize*OldButSize+2
                      btnDegree[empty][1] = temp
                      button[OldButSize*OldButSize+2]{settext(temp)}
                      } 
                      empty = emptysave
        ok

func rotateright
        if button[OldButSize*OldButSize+2].text() != "Here"  
           button[OldButSize*OldButSize+2].close()
           button[OldButSize*OldButSize+2] = new ButtonWithRotatedText(win1)
                      button[OldButSize*OldButSize+2] {
                      setgeometry(60+(OldButSize-1)*40,60+(OldButSize+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      nDegreeRight = (nDegreeRight+90)%360
                      nDegree = nDegreeRight
                      btnDegree[OldButSize*OldButSize+2][2] = nDegree
                      emptysave = empty
                      empty = OldButSize*OldButSize+2
                      btnDegree[empty][1] = temp
                      button[OldButSize*OldButSize+2]{settext(temp)}
                      }
                      empty = emptysave
        ok

func newsize CurButSize
        win1{ 
                sizenew = CurButSize%4
                win1.resize(360+sizenew*40,560+sizenew*40)
                if flaginit != 0
                   for nb = 1 to OldButSize*OldButSize+3
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

                for n = 1 to CurButSize*CurButSize
                     col = n%CurButSize
                     if col = 0 col = CurButSize ok
                     row = ceil(n/CurButSize)
                     button[n] = new ButtonWithRotatedText(win1)
                                       button[n] {
                                       setgeometry(60+col*40,60+row*40,40,40)
                                       button[n].setbuttoncolor("yellow")                                       
                                       nDegree = 0
                                       if n < CurButSize*CurButSize
                                          button[n].settext(string(n))
                                       but n = CurButSize*CurButSize
                                          button[n].settext("")
                                       ok 
                                       setClickEvent("movetile(" + string(n) +")")
                                       }
                next

                btnMoves = new qpushbutton(win1)
                {
                                        setgeometry(100,60+(CurButSize+1)*40,(CurButSize-3)*40,40)
                                        setStyleSheet("text-align:center")
                                        settext("0")
                                        show() 
                }

                button[CurButSize*CurButSize+1] = new qpushbutton(win1)
                {
                                              setgeometry(60+(CurButSize-2)*40,60+(CurButSize+1)*40,40,40)
                                              settext("<-")
                                              setclickevent("rotateLeft()")   
                                              show() 
                } 

                button[CurButSize*CurButSize+2] = new qpushbutton(win1)
                {
                                             setgeometry(60+(CurButSize-1)*40,60+(CurButSize+1)*40,40,40)
                                             settext("Here")
                                             setclickevent("pHere()")   
                                             show() 
                }

                button[CurButSize*CurButSize+3] = new qpushbutton(win1)
                {
                                             setgeometry(60+CurButSize*40,60+(CurButSize+1)*40,40,40)
                                             settext("->")
                                             setclickevent("rotateRight()")   
                                             show() 
                 }

                scramblebtn = new qpushbutton(win1)
                {
                                      setgeometry(100,100+(CurButSize+1)*40,CurButSize*40,40)
                                      settext("Scramble")
                                      setclickevent("scramble()")
                                      show()                        
                }

                resetbtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(CurButSize+2)*40,CurButSize*40,40)
                                 settext("Reset")
                                 setclickevent("resettiles()")
                                 show() 
                }

                savebtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(CurButSize+3)*40,CurButSize*40,40)
                                 settext("Save Game")
                                 setclickevent("pSave()")
                                 show() 
                }

                playbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(CurButSize+4)*40,CurButSize*40,40)  
                               settext("Resume Game")  
                               setclickevent("pPlay()")
                               show()
                }

                sleepbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(CurButSize+5)*40,(CurButSize-2)*40,40)  
                               settext("Sleep Time: " + string(nrSleep) + " s")  
                               show()
                }

                decbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(CurButSize-2)*40,100+(CurButSize+5)*40,40,40)  
                               settext("<-")  
                               setclickevent("pDecSleep()")
                               show()
                }

                incbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(CurButSize-1)*40,100+(CurButSize+5)*40,40,40)  
                               settext("->")  
                               setclickevent("pIncSleep()")
                               show()
                }

                table1 = []
                table2 = []
                table3 = []   
                for n = 1 to OldButSize*OldButSize
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
                empty = CurButSize*CurButSize
                OldButSize = CurButSize
                flaginit = 1
                flagsave = 0
                flagmove = 0
                nrMoves = 0
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
         return

func pPlay
        if  flagsave = 0 or flagmove = 0
           see "First you must play and save the game." + nl
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
           for empty = 1 to OldButSize*OldButSize
                button[empty].setbuttoncolor("yellow") 
                nDegree = number(table3[empty])
                btnDegree[empty][1] = table1[empty]
                button[empty] {settext(table1[empty])}
           next
           empty = number(table1[OldButSize*OldButSize + 1])
           CounterMan = OldButSize*OldButSize+2
           nrMoves = 0
           TimerMan.start()
       ok

func pTime()
        if flagsave = 0 or flagmove = 0
           see "First you must play and save the game." + nl
        else
           CounterMan++
           pPlaySleep()
           sleep(nrSleep*1000) 
           if CounterMan = len(table1)
              TimerMan.stop()
           ok
        ok

func pPlaySleep
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
        see char(7)
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
