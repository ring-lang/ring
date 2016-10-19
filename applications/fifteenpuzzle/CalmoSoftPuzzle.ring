load "guilib.ring"

App1 = new qApp {

        empty = 16   
        button = list(19)   

        win1 = new qWidget() {
                   move(0,0)
                   resize(370,480)
                   setWindowTitle("CalmoSoft Fifteen Puzzle Game")

                for n = 1 to 16
                      col = n%4
                      if col = 0 col = 4 ok
                      row = ceil(n/4)
                      button[n] = new qPushButton (win1)
                     {
                                         setgeometry(60+col*40,60+row*40,40,40)
                                         button[n] {settext(string(n))}
                                         setclickevent("moveTile(" + string(n) +")")                   
                      }                
                next

                button[16] {settext("")}                     

                button[17] = new qPushButton(win1)   
                {
                                     setgeometry(140,260,40,40)
                                     settext("<-")
                                     setclickevent("rotateLeft()")
                }

                button[18] = new qPushButton(win1)   
                {
                                     setgeometry(180,260,40,40)
                                     settext("Here")
                                     setclickevent("pHere()")
                }

                button[19] = new qPushButton(win1)   
                {
                                     setgeometry(220,260,40,40)
                                     settext("->")
                                     setclickevent("rotateRight()")
                }

                scramblebtn = new qPushButton(win1)
                {
                       setgeometry(100,300,160,40)
                       settext("Scramble")
                       setclickevent("scramble()")                        
                }

                resetbtn = new qPushButton(win1)   
                {
                                 setgeometry(100,340,160,40)
                                 settext("Reset")
                                 setclickevent("resetTiles()")
                }
                show()
        }
        exec()
}
 
func scramble
       for n= 1 to 300   
            nr=random(16)
            up = (empty = (nr - 4))
            down = (empty = (nr + 4))
            left = ((empty = (nr - 1)) and ((nr % 4) != 1))
            right = ((empty = (nr + 1)) and ((nr % 4) != 0))
            move = up or down or left  or right
            if move = 1 and (nr != 0)
               button[nr] { temp = text() }
               button[empty]  {settext(temp)}
               button[nr]  {settext("")}
               empty = nr
            ok
       next
       return

func moveTile nr2
       if (nr2 = 15 and button[nr2].text() = "Back")
           pBack()
       else
           up = (empty = (nr2 - 4))
           down = (empty = (nr2 + 4))
           left = ((empty = (nr2- 1)) and ((nr2 % 4) != 1))
           right = ((empty = (nr2 + 1)) and ((nr2 % 4) != 0))
           move = up or down or left  or right
           if move = 1    
              button[nr2] { temp2 = text() }
              button[empty]  {settext(temp2)}
              button[nr2]  {settext("")}
              empty = nr2
           ok
      ok 
      return

func resetTiles
        empty = 16
        for i = 1 to 15
             button[i] {settext(string(i))}
        next
        button[16] {settext("")}
        return

func pHere
        if button[15].text() != "" and button[18].text() = "Here"
           button[15] { temp = text() }
           button[18] {settext(temp)}
           for n = 1 to 16
                 button[n].setEnabled(false)
           next  
           button[15].setEnabled(true)
           scramblebtn.setEnabled(false)
           resetbtn.setEnabled(false)
           button[15]  {settext("Back")}
           return ok

func pBack
        button[18] { temp = text() }
        button[15] {settext(temp)}
        button[18] {settext("Here")}
        for n = 1 to 16
              button[n].setEnabled(true)
        next 
        scramblebtn.setEnabled(true)
        resetbtn.setEnabled(true)
        return

func rotateLeft
        if button[18].text() != "Here"  
           button[18] {settext(string(number(button[18].text())-1))}
           return ok

func rotateRight
        if button[18].text() != "Here"  
           button[18] {settext(string(number(button[18].text())+1))}
           return ok

