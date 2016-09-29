load "guilib.ring"

App1 = new qApp {

        rnd = []
        empty = 16        
        
        win1 = new qWidget() {
                   move(0,0)
                   resize(350,400)
                   setWindowTitle("CalmoSoft Fifteen Puzzle Game")

                new qPushButton(win1)
                {
                       setgeometry(100,220,120,30)
                       settext("Scramble")
                       setclickevent("scramble()")                        
                }

                 btn1 = new qPushButton(win1)
                {
                            setgeometry(100,100,30,30)
                            setclickevent("moveTile(1)")                   
                }                

                btn2 = new qPushButton(win1)
                {
                           setgeometry(130,100,30,30)
                           setclickevent("moveTile(2)")                      
                } 

                btn3 = new qPushButton(win1)
                {
                           setgeometry(160,100,30,30)
                           setclickevent("moveTile(3)")                        
                }
 
                btn4 = new qPushButton(win1)
                {
                           setgeometry(190,100,30,30)
                           setclickevent("moveTile(4)")
                }

                btn5 = new qPushButton(win1)
                {
                           setgeometry(100,130,30,30)
                           setclickevent("moveTile(5)")
                }
    
                btn6 = new qPushButton(win1)
                {
                           setgeometry(130,130,30,30)
                           setclickevent("moveTile(6)")
                }

                btn7 = new qPushButton(win1)
                {
                           setgeometry(160,130,30,30)
                           setclickevent("moveTile(7)")
                }

                btn8 = new qPushButton(win1)
                {
                           setgeometry(190,130,30,30)
                           setclickevent("moveTile(8)")
                }

                btn9 = new qPushButton(win1)   
                {
                           setgeometry(100,160,30,30)
                           setclickevent("moveTile(9)")
                }

                btn10 = new qPushButton(win1)   
                {
                             setgeometry(130,160,30,30)
                             setclickevent("moveTile(10)")
                }

                btn11 = new qPushButton(win1)   
                {
                             setgeometry(160,160,30,30)
                             setclickevent("moveTile(11)")
                }

                btn12 = new qPushButton(win1)   
                {
                             setgeometry(190,160,30,30)
                             setclickevent("moveTile(12)")
                }

                btn13 = new qPushButton(win1)   
                {
                             setgeometry(100,190,30,30)
                             setclickevent("moveTile(13)")
                }

                btn14 = new qPushButton(win1)   
                {
                             setgeometry(130,190,30,30)
                             setclickevent("moveTile(14)")
                }

                btn15 = new qPushButton(win1)   
                {
                             setgeometry(160,190,30,30)
                             setclickevent("moveTile(15)")
                }

                btn16 = new qPushButton(win1)   
                {
                             setgeometry(190,190,30,30)
                             settext("")
                             setclickevent("moveTile(16)")
                }

                resetbtn = new qPushButton(win1)   
                {
                                setgeometry(100,250,120,30)
                                settext("Reset")
                                setclickevent("resetTiles()")
                }

                button = [btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, btn11, btn12, btn13, btn14, btn15, btn16]                
                for i = 1 to 15
                     button[i] {settext(string(i))}
                next
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

func moveTile nr2
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

func resetTiles
       empty = 16
       for i = 1 to 15
            button[i] {settext(string(i))}
       next
       button[16] {settext("")}
