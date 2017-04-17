load "guilib.ring"

app1 = new qapp {

        empty = 16  
        nrold = 4 
        nr = 0
        temp = 0
        flag = 0
        button = list(52)   
        sizebtn = list(7)
        table = [] 
        table2 = [] 
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

                  for n=1 to 49
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
            nr=random(nrold*nrold)
            up = (empty = (nr - nrold))
            down = (empty = (nr + nrold))
            left = ((empty = (nr - 1)) and ((nr % nrold) != 1))
            right = ((empty = (nr + 1)) and ((nr % nrold) != 0))
            move = up or down or left  or right
            if move = 1 and (nr != 0)
               button[nr] { temp2 = text() }
               col = empty%nrold
               if col = 0 col = nrold ok
               row = ceil(empty/nrold)
               button[empty] = new ButtonWithRotatedText(win1)
                       button[empty] {
                       setgeometry(60+col*40,60+row*40,40,40)
                       rnd = random(6)+1
                       nDegree = nrDegree[rnd]
                       settext(temp2)
                       btnDegree[empty] [1] = temp2
                       btnDegree[empty] [2] = nDegree
                       }
               button[nr]  {settext("")}
               btnDegree[nr][2] = 0
               empty = nr
            ok
       next
       button[nrold*nrold+2]{settext("Here")}
       table = []
       table2 = []
       for n = 1 to nrold*nrold
             add(table, button[n].text())
       next
       add(table, string(empty))

       for n = 1 to nrold*nrold
             add(table2, button[n].text())
       next
       add(table2, string(empty))
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
              button[nr2] { temp2 = text() }
              add(table, temp2)
              add(table2, string(nr2))              
              col = empty%nrold
              if col = 0 col = nrold ok
              row = ceil(empty/nrold)
              button[empty] = new ButtonWithRotatedText(win1)
              button[empty] {
                                   setgeometry(60+col*40,60+row*40,40,40)
                                   nDegree = btnDegree[nr2][2]
                                   btnDegree[empty][2] = btnDegree[nr2][2]
                                   button[empty]{settext(temp2)}
                                   setClickEvent("movetile(" + string(empty) +")")
              }
              button[nr2] {settext("")}
              empty = nr2
          ok
      ok 
      return

func resettiles
        nDegree = 0  
        empty = nrold*nrold
        for i = 1 to nrold*nrold-1
             btnDegree[i][2] = 0
             button[i] {settext(string(i))}
        next
        button[nrold*nrold] {settext("")}
        button[nrold*nrold+2].close()

        button[nrold*nrold+2] = new qpushbutton(win1)
                {
                setgeometry(60+(nrold-1)*40,60+(nrold+1)*40,40,40)
                settext("Here")
                setclickevent("pHere()")   
                show() 
                } 
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
           /*for n = 1 to nrold*nrold
                 button[n]{setenabled = false}
           next*/
           button[nrold*nrold-1]{setenabled = true}
           scramblebtn{setenabled = false}
           resetbtn{setenabled = false}
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
        /*for n = 1 to nrold*nrold
              button[n]{setenabled = true}
        next*/
        scramblebtn{setenabled = true}
        resetbtn{setenabled = true}

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
                win1.resize(380+sizenew*40,520+sizenew*40)
                if flag != 0
                   see "nrold = " + nrold + nl
                   for n = 1 to nrold*nrold+3
                         button[n].close()
                         see n + nl
                   next
                ok
                scramblebtn.close()
                resetbtn.close()
                savebtn.close()
                playbtn.close()

                for n = 1 to nr*nr-1
                     col = n%nr
                     if col = 0 col = nr ok
                     row = ceil(n/nr)

                button[n] = new ButtonWithRotatedText(win1)
                       button[n] {
                       setgeometry(60+col*40,60+row*40,40,40)
                       nDegree = 0
                       settext(string(n))
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

                col = nr*nr%nrold
                if col = 0 col = nrold ok
                row = ceil(nr*nr/nrold)
                button[nr*nr] = new ButtonWithRotatedText(win1)
                                       button[nr*nr] {
                                       setgeometry(60+col*40,60+row*40,40,40)
                                       settext("")
                                       setClickEvent("movetile(" + string(nr*nr) +")")
                                       }

                empty = nr*nr
                nrold = nr
                flag = flag + 1
                }

func pSave
        textedit1 = list2str(table)
        textedit2 = list2str(table2)
chdir(exefolder()+"../extensions/ringallegro")
      	cName = exefolder()+"../CalmoSoftPuzzle.txt"
      	cName2 = exefolder()+"../CalmoSoftPuzzle2.txt"
		write(cName,textedit1)
		write(cName2,textedit2)
        return

func pPlay

      	cName = cName = exefolder()+"../CalmoSoftPuzzle.txt"
		textedit1 = read(cName)
        table = str2list(textedit1)

      	cName2 = "C:\Ring\bin\CalmoSoftPuzzle2.txt"
		textedit2 = read(cName2)
        table2 = str2list(textedit2)

        for n = 1 to nrold*nrold
              button[n] {settext(table[n])}
        next

        empty = table[nrold*nrold + 1]

        for n = nrold*nrold + 2 to len(table)
             tmp = table[n]
             tmp2 = table2[n]
             button[number(empty)].settext(tmp)
             button[number(tmp2)].settext("")
             empty = tmp2
             t = clock()
             while clock() - t <= clockspersecond() end
        next
        return 

Class ButtonWithRotatedText

    oButton oLabel  cText="We are here"  nDegree = 30  nTransX = 50   nTransY = 0

    func init( oParent) 
        oButton = new qPushButton(oParent)
        oLabel  = new qLabel(oParent)
        oLabel.setAttribute(Qt_WA_TransparentForMouseEvents,True)
        oLabel.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.setAttribute(Qt_WA_DeleteOnClose, True)
    return
    
    func close()
            oLabel.close()
            //oButton.close()
            return

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

func setenabled()
        oButton.setenabled()
    	
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
