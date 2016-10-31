load "guilib.ring"

app1 = new qapp {

        empty = 16  
        nrold = 4 
        flag = 0
        button = list(52)   
        sizebtn = list(7)

        win1 = new qwidget() {
                   move(0,0)
                   resize(380,480)
                   setwindowtitle("Calmosoft Fifteen Puzzle Game")

                   newsize(4)

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
                   show()
        }
        exec()
}

func scramble
       for n= 1 to 10000   
            nr=random(nrold*nrold)
            up = (empty = (nr - nrold))
            down = (empty = (nr + nrold))
            left = ((empty = (nr - 1)) and ((nr % nrold) != 1))
            right = ((empty = (nr + 1)) and ((nr % nrold) != 0))
            move = up or down or left  or right
            if move = 1 and (nr != 0)
               button[nr] { temp = text() }
               button[empty]  {settext(temp)}
               button[nr]  {settext("")}
               empty = nr
            ok
       next
       return

func movetile nr2
       if (nr2 = nrold*nrold-1 and button[nr2].text() = "Back")
           pBack()
       else
           up = (empty = (nr2 - nrold))
           down = (empty = (nr2 + nrold))
           left = ((empty = (nr2- 1)) and ((nr2 % nrold) != 1))
           right = ((empty = (nr2 + 1)) and ((nr2 % nrold) != 0))
           move = up or down or left  or right
           if move = 1    
              button[nr2] { temp2 = text() }
              button[empty]  {settext(temp2)}
              button[nr2]  {settext("")}
              empty = nr2
           ok
      ok 
      return

func resettiles
        empty = nrold*nrold
        for i = 1 to nrold*nrold-1
             button[i] {settext(string(i))}
        next
        button[nrold*nrold] {settext("")}
        return

func pHere
        if button[nrold*nrold-1].text() != "" and button[nrold*nrold+2].text() = "Here"
           button[nrold*nrold-1] { temp = text() }
           button[nrold*nrold+2] {settext(temp)}
           for n = 1 to nrold*nrold
                 button[n].setenabled(false)
           next  
           button[nrold*nrold-1].setenabled(true)
           scramblebtn.setenabled(false)
           resetbtn.setenabled(false)
           button[nrold*nrold-1]  {settext("Back")}
           return ok

func pBack
        button[nrold*nrold+2] { temp = text() }
        button[nrold*nrold-1] {settext(temp)}
        button[nrold*nrold+2] {settext("Here")}
        for n = 1 to nrold*nrold
              button[n].setenabled(true)
        next 
        scramblebtn.setenabled(true)
        resetbtn.setenabled(true)
        return

func rotateleft
        if button[nrold*nrold+2].text() != "Here"  
           button[nrold*nrold+2] {settext(string(number(button[nrold*nrold+2].text())-1))}
           return ok

func rotateright
        if button[nrold*nrold+2].text() != "Here"  
           button[nrold*nrold+2] {settext(string(number(button[nrold*nrold+2].text())+1))}
           return ok

func newsize nr
        win1{
                sizenew = nr%4
                win1.resize(380+sizenew*40,480+sizenew*40)
if flag != 0
                for n = 1 to nrold*nrold+3
                      button[n].close()
                next
                scramblebtn.close()
                resetbtn.close()
ok
                for n = 1 to nr*nr
                     col = n%nr
                     if col = 0 col = nr ok
                     row = ceil(n/nr)

                     button[n] = new qpushbutton(win1)
                     {
                                        setgeometry(60+col*40,60+row*40,40,40)
                                        settext(string(n))
                                        setclickevent("movetile(" + string(n) +")")   
                                        show() 
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
                button[nr*nr] {settext("")}
                empty = nr*nr
                nrold = nr
                flag = flag + 1
                }

