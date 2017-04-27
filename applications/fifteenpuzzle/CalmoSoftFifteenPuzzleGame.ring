# Project : CalmoSoft Fifteen Puzzle Game (Under Development)
# Author: Gal Zsolt (~ CalmoSoft ~), Bert Mariani, Mahmoud Fayed

load "guilib.ring"

app1 = new qapp {

        empty = 16  
        nrold = 4 
        nr = 4
        temp = 0
        flag = 0
        flag2 = 0
        button = list(52)   
        sizebtn = list(7)
        table1 = [] 
        table2 = [] 
        table3 = []
        nDegree = 0
        nrDegree = [0,90,180,270 ,-90,-180,-270]
        LabelSizeX = 100
        offSetX    = LabelSizeX / 2
        nDegreeRight = 0
        nDegreeLeft = 0
        btnDegree = newlist(52,2)

        win1 = new qwidget() {
                   move(0,0)
                   resize(380,680)
                   setwindowtitle("Calmosoft Fifteen Puzzle Game")

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
                                   settext("Play Game")  
                                   setclickevent("pPlay()")
                   }
                   newsize(4) 
                   show()
        }
        exec()
}

func sleep x
       nTime = x * 1000
       see "Sleep: "+ nTime + nl
       oTest = new qTest
       oTest.qsleep(nTime)
       return

Func newlist x, y
     if isstring(x) x=0+x ok
     if isstring(y) y=0+y ok
     alist = list(x)
     for t in alist
         t = list(y)
     next
     return alist	

func scramble
       resettiles()
       for n= 1 to 1000   
            nr=random(nrold*nrold-1)+1
            up = (empty = (nr - nrold))
            down = (empty = (nr + nrold))
            left = ((empty = (nr - 1)) and ((nr % nrold) != 1))
            right = ((empty = (nr + 1)) and ((nr % nrold) != 0))
            move = up or down or left  or right
            if move = 1 
               button[nr] { temp2 = text() }
               col = empty%nrold
               if col = 0 col = nrold ok
               row = ceil(empty/nrold)
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
               button[nr].setbuttoncolor("yellow")
               button[nr]{settext("")}
               btnDegree[nr][2] = 0
               empty = nr
            ok
       next
       button[nrold*nrold+2]{settext("Here")}
       for n=1 to nrold*nrold
             button[n].setbuttoncolor("yellow")
       next
       table1 = []
       table2 = []
       table3 = []   
       for n = 1 to nrold*nrold
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
       flag2 = 1

       return

func movetile nr2
       if (nr2 = nrold*nrold-1 and button[nr2].text() = "In")
           pBack()
       else
           up = (empty = (nr2 - nrold))
           down = (empty = (nr2 + nrold))
           left = ((empty = (nr2- 1)) and ((nr2 % nrold) != 1))
           right = ((empty = (nr2 + 1)) and ((nr2 % nrold) != 0))
           move = up or down or left  or right
           if move = 1 
              temp2 = button[nr2].text() 
              add(table1, temp2)
              add(table2, string(nr2))              
              col = empty%nrold
              if col = 0 col = nrold ok
              row = ceil(empty/nrold)
              button[empty] {
                                   setgeometry(60+col*40,60+row*40,40,40)
                                   nDegree = btnDegree[nr2][2]
                                   btnDegree[empty][2] = nDegree
                                   button[empty].setbuttoncolor("orange")
                                   button[empty].settext(temp2)
              }
              add(table3, string(nDegree))
              button[nr2].setbuttoncolor("cyan")
              button[nr2]{settext("")}
              empty = nr2
          ok
      ok 
      return

func resettiles
        nDegree = 0  
        empty = nrold*nrold
        for i = 1 to nrold*nrold-1
             btnDegree[i][2] = 0
             nDegree = 0
             button[i].setstylesheet("background-color:yellow")
             button[i] {settext(string(i))}
        next
        button[nrold*nrold].setstylesheet("background-color:yellow")
        button[nrold*nrold] {settext("")}
        return

func pHere
        if button[nrold*nrold-1].text() != "" and button[nrold*nrold+2].text() = "Here"
           button[nrold*nrold-1] { temp = text() }
           button[nrold*nrold+2].close()
           button[nrold*nrold+2] = new ButtonWithRotatedText(win1)
           button[nrold*nrold+2] {
           setgeometry(60+(nrold-1)*40,60+(nrold+1)*40,40,40)
           btnDegree[nrold*nrold+2][2] = btnDegree[nrold*nrold-1][2]
           nDegree = btnDegree[nrold*nrold+2][2]
           settext(temp)
           }
           nDegree = 0
           button[nrold*nrold-1]{settext("In")}
           for n = 1 to nrold*nrold
	   button[n].setenabled(false)
           next
           button[nrold*nrold-1].setenabled(true)
           scramblebtn.setenabled(false)
           resetbtn.setenabled(false)
           savebtn.setenabled(false)
           playbtn.setenabled(false)
        ok

func pBack
        button[nrold*nrold+2] { temp = text() }
        nDegree = btnDegree[nrold*nrold+2][2]
        btnDegree[nrold*nrold-1][2] = btnDegree[nrold*nrold+2][2]
        button[nrold*nrold-1] {settext(temp)}
        button[nrold*nrold+2].close()
        button[nrold*nrold+2] = new qpushbutton(win1)
                {
                setgeometry(60+(nrold-1)*40,60+(nrold+1)*40,40,40)
                settext("Here")
                setclickevent("pHere()")   
                show() 
                } 
        for n = 1 to nrold*nrold
              button[n].setenabled(true)
        next
        scramblebtn.setenabled(true)
        resetbtn.setenabled(true)
        savebtn.setenabled(true)
        playbtn.setenabled(true)

func rotateleft
        if button[nrold*nrold+2].text() != "Here" 
           button[nrold*nrold+2].close()
           button[nrold*nrold+2] = new ButtonWithRotatedText(win1)
                      button[nrold*nrold+2] {
                      setgeometry(60+(nrold-1)*40,60+(nrold+1)*40,40,40)
                      nDegreeLeft = (nDegreeLeft-90)%360
                      nDegree = nDegreeLeft
                      btnDegree[nrold*nrold+2][2] = nDegree
                      button[nrold*nrold+2]{settext(temp)}
                      } 
        ok

func rotateright
        if button[nrold*nrold+2].text() != "Here"  
           button[nrold*nrold+2].close()
           button[nrold*nrold+2] = new ButtonWithRotatedText(win1)
                      button[nrold*nrold+2] {
                      setgeometry(60+(nrold-1)*40,60+(nrold+1)*40,40,40)
                      nDegreeRight = (nDegreeRight+90)%360
                      nDegree = nDegreeRight
                      btnDegree[nrold*nrold+2][2] = nDegree
                      button[nrold*nrold+2]{settext(temp)}
                      }
        ok

func newsize nr
        win1{ 
                sizenew = nr%4
                win1.resize(360+sizenew*40,520+sizenew*40)
                if flag != 0
                   for nb = 1 to nrold*nrold+3
                         button[nb] {close()}
                   next
                ok
                scramblebtn.close()
                resetbtn.close()
                savebtn.close()
                playbtn.close()

                for n = 1 to nr*nr
                     col = n%nr
                     if col = 0 col = nr ok
                     row = ceil(n/nr)
                     button[n] = new ButtonWithRotatedText(win1)
                                       button[n] {
                                       setgeometry(60+col*40,60+row*40,40,40)
                                       button[n].setbuttoncolor("yellow")                                       
                                       nDegree = 0
                                       if n < nr*nr
                                          button[n].settext(string(n))
                                       but n = nr*nr
                                          button[n].settext("")
                                       ok 
                                       setClickEvent("movetile(" + string(n) +")")
                                       }
                next

                button[nr*nr+1] = new qpushbutton(win1)
                {
                                              setgeometry(60+(nr-2)*40,60+(nr+1)*40,40,40)
                                              settext("<-")
                                              setclickevent("rotateLeft()")   
                                              show() 
                } 

                button[nr*nr+2] = new qpushbutton(win1)
                {
                                             setgeometry(60+(nr-1)*40,60+(nr+1)*40,40,40)
                                             settext("Here")
                                             setclickevent("pHere()")   
                                             show() 
                }

                button[nr*nr+3] = new qpushbutton(win1)
                {
                                             setgeometry(60+nr*40,60+(nr+1)*40,40,40)
                                             settext("->")
                                             setclickevent("rotateRight()")   
                                             show() 
                 }

                scramblebtn = new qpushbutton(win1)
                {
                                      setgeometry(100,100+(nr+1)*40,nr*40,40)
                                      settext("Scramble")
                                      setclickevent("scramble()")
                                      show()                        
                }

                resetbtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(nr+2)*40,nr*40,40)
                                 settext("Reset")
                                 setclickevent("resettiles()")
                                 show() 
                }

                savebtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(nr+3)*40,nr*40,40)
                                 settext("Save Game")
                                 setclickevent("pSave()")
                                 show() 
                }

                playbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(nr+4)*40,nr*40,40)  
                               settext("Play Game")  
                               setclickevent("pPlay()")
                               show()
                }
                table1 = []
                table2 = []
                table3 = []   
                for n = 1 to nrold*nrold
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
                empty = nr*nr
                nrold = nr
                flag = flag + 1
                }

func pSave
        textedit1 = list2str(table1)
        textedit2 = list2str(table2)
        textedit3 = list2str(table3)
        cName1 = "C:\Ring\bin\CalmoSoftPuzzle1.txt"
        cName2 = "C:\Ring\bin\CalmoSoftPuzzle2.txt"
        cName3 = "C:\Ring\bin\CalmoSoftPuzzle3.txt"
        write(cName1,textedit1)
        write(cName2,textedit2)
        write(cName3,textedit3)
        return

func pPlay
        if flag2 = 0
        see "First you must 'Scramble' the tiles and play and save the game."
        else
        cName1 = "C:\Ring\bin\CalmoSoftPuzzle1.txt"
        textedit1 = read(cName1)
        table1 = str2list(textedit1)
        cName2 = "C:\Ring\bin\CalmoSoftPuzzle2.txt"
        textedit2 = read(cName2)
        table2 = str2list(textedit2)
        cName3 = "C:\Ring\bin\CalmoSoftPuzzle3.txt"
        textedit3 = read(cName3)
        table3 = str2list(textedit3)
        for n = 1 to nrold*nrold
              nDegree = number(table3[n])
              button[n] {settext(table1[n])}
        next
        empty = number(table1[nrold*nrold + 1])
        for n = nrold*nrold+3 to len(table1)
             sleep(1)
             value = table1[n]
             place = table2[n]
             nDegree = number(table3[n])
             button[empty]{settext(value)}
             button[number(place)]{settext("")}
             empty = number(place)
        next
        ok
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
    	
    Func draw()
                    picture = new qpicture()
                    color   = new qcolor() { setrgb(0,0,255,255) }
                    pen     = new qpen()   { setcolor(color) setwidth(10) }
                    
                    painter = new qpainter() 
                    {
                                  begin(picture)        
                                  setpen(pen)
                                  oFont = font()
                                  oFont.setpointsize(20)
                                  setfont(oFont)
                                  if nDegree = 0
                                     translate(5,10)
                                  but nDegree = 90
                                     translate(10,-10)
                                  but nDegree = 180
                                     translate(30,-10)
                                  but nDegree = 270
                                     translate(30,15)
                                  but nDegree = -90
                                     translate(30,20)
                                  but nDegree = -180
                                     translate(30,-10)
                                  but nDegree = -270
                                     translate(10,-15)
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
