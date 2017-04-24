// author : CalmoSoft

load "guilib.ring"

app1 = new qapp {

        temp = ""
        movesnr = 0
        button = list(16)   
 
        win1 = new qwidget() {
                   move(0,0)
                   resize(360, 480)
                   setwindowtitle("Calmosoft Sixteen Puzzle Game")

                   for n = 1 to 16
                         col = n%4
                         if col = 0 col = 4 ok
                         row = ceil(n/4)
                         button[n] = new qpushbutton(win1)
                         {
                                            setgeometry(60+col*40,60+row*40,40,40)
                                            settext(string(n))
                          } 
                   next

                  buttonup1 = new qpushbutton(win1)
                  {
                                      setgeometry(100, 60, 40, 40)
                                      settext("up")
                                      setclickevent("up1()")   
                  }

                  buttonup2 = new qpushbutton(win1)
                  {
                                      setgeometry(140, 60, 40, 40)
                                      settext("up")
                                      setclickevent("up2()")   
                  }

                 buttonup3 = new qpushbutton(win1)
                  {
                                      setgeometry(180, 60, 40, 40)
                                      settext("up")
                                      setclickevent("up3()")   
                  }

                 buttonup4 = new qpushbutton(win1)
                  {
                                      setgeometry(220, 60, 40, 40)
                                      settext("up")
                                      setclickevent("up4()")   
                  }

                  buttondown1 = new qpushbutton(win1)
                  {
                                          setgeometry(100, 260, 40, 40)
                                          settext("down")
                                          setclickevent("down1()")   
                  }

                  buttondown2 = new qpushbutton(win1)
                  {
                                          setgeometry(140, 260, 40, 40)
                                          settext("down")
                                          setclickevent("down2()")   
                  }

                  buttondown3 = new qpushbutton(win1)
                  {
                                          setgeometry(180, 260, 40, 40)
                                          settext("down")
                                          setclickevent("down3()")   
                  }

                 buttondown4 = new qpushbutton(win1)
                  {
                                          setgeometry(220, 260, 40, 40)
                                          settext("down")
                                          setclickevent("down4()")   
                  }

                  buttonleft1 = new qpushbutton(win1)
                  {
                                          setgeometry(60, 100, 40, 40)
                                          settext("<<<")
                                          setclickevent("left1()")   
                  }

                  buttonleft2 = new qpushbutton(win1)
                  {
                                          setgeometry(60, 140, 40, 40)
                                          settext("<<<")
                                          setclickevent("left2()")   
                  }

                  buttonleft3 = new qpushbutton(win1)
                  {
                                          setgeometry(60, 180, 40, 40)
                                          settext("<<<")
                                          setclickevent("left3()")   
                  }

                  buttonleft4 = new qpushbutton(win1)
                  {
                                          setgeometry(60, 220, 40, 40)
                                          settext("<<<")
                                          setclickevent("left4()")   
                  }

                  buttonright1 = new qpushbutton(win1)
                  {
                                          setgeometry(260, 100, 40, 40)
                                          settext(">>>")
                                          setclickevent("right1()")   
                  }

                  buttonright2 = new qpushbutton(win1)
                  {
                                          setgeometry(260, 140, 40, 40)
                                          settext(">>>")
                                          setclickevent("right2()")   
                  }

                  buttonright3 = new qpushbutton(win1)
                  {
                                          setgeometry(260, 180, 40, 40)
                                          settext(">>>")
                                          setclickevent("right3()")   
                  }

                  buttonright4 = new qpushbutton(win1)
                  {
                                          setgeometry(260, 220, 40, 40)
                                          settext(">>>")
                                          setclickevent("right4()")   
                  }

                  buttonscramble = new qpushbutton(win1)
                  {
                                             setgeometry(100, 300, 160, 40)
                                             settext("Scarmble")
                                             setclickevent("scramble()")   
                  }

                  buttonreset = new qpushbutton(win1)
                  {
                                        setgeometry(100, 340, 160, 40)
                                        settext("Reset")
                                        setclickevent("reset()")   
                  }

                  buttonnr = new qpushbutton(win1)
                  {
                                   setgeometry(100, 380, 160, 40)
                                   settext("Moves : ")
                  }

                  show()
        }
        exec()
}

func sleep x
       nTime = x * 1000
       oTest = new qTest
       oTest.qsleep(nTime)
return

func scramble
       reset()
       empty = 16
       movesnr = 0
       buttonnr.settext("Moves : " + movesnr)

       for n= 1 to 1000  
            nr=random(15)+1
            up = (empty = (nr - 4))
            down = (empty = (nr + 4))
            left = ((empty = (nr - 1)) and ((nr % 4) != 1))
            right = ((empty = (nr + 1)) and ((nr % 4) != 0))
            move = up or down or left  or right
            if move = 1 
               temp1 = button[nr].text()
               temp2 = button[empty].text()
               button[empty].settext(temp1)
               button[nr].settext(temp2)
               empty = nr
            ok
       next

func reset
        movesnr = 0
        buttonnr.settext("Moves : " + movesnr)
        for i = 1 to 16
             button[i] {settext(string(i))}
        next
        return

func up1
        temp = button[1].text()
        button[1].settext(button[5].text())
        button[5].settext(button[9].text())
        button[9].settext(button[13].text())
        button[13].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func up2
        temp = button[2].text()
        button[2].settext(button[6].text())
        button[6].settext(button[10].text())
        button[10].settext(button[14].text())
        button[14].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func up3
        temp = button[3].text()
        button[3].settext(button[7].text())
        button[7].settext(button[11].text())
        button[11].settext(button[15].text())
        button[15].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func up4
        temp = button[4].text()
        button[4].settext(button[8].text())
        button[8].settext(button[12].text())
        button[12].settext(button[16].text())
        button[16].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func down1
        temp = button[13].text()
        button[13].settext(button[9].text())
        button[9].settext(button[5].text())
        button[5].settext(button[1].text())
        button[1].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func down2
        temp = button[14].text()
        button[14].settext(button[10].text())
        button[10].settext(button[6].text())
        button[6].settext(button[2].text())
        button[2].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func down3
        temp = button[15].text()
        button[15].settext(button[11].text())
        button[11].settext(button[7].text())
        button[7].settext(button[3].text())
        button[3].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func down4
        temp = button[16].text()
        button[16].settext(button[12].text())
        button[12].settext(button[8].text())
        button[8].settext(button[4].text())
        button[4].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func left1
        temp = button[1].text()
        button[1].settext(button[2].text())
        button[2].settext(button[3].text())
        button[3].settext(button[4].text())
        button[4].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func left2
        temp = button[5].text()
        button[5].settext(button[6].text())
        button[6].settext(button[7].text())
        button[7].settext(button[8].text())
        button[8].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func left3
        temp = button[9].text()
        button[9].settext(button[10].text())
        button[10].settext(button[11].text())
        button[11].settext(button[12].text())
        button[12].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func left4
        temp = button[13].text()
        button[13].settext(button[14].text())
        button[14].settext(button[15].text())
        button[15].settext(button[16].text())
        button[16].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func right1
        temp = button[4].text()
        button[4].settext(button[3].text())
        button[3].settext(button[2].text())
        button[2].settext(button[1].text())
        button[1].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func right2
        temp = button[8].text()
        button[8].settext(button[7].text())
        button[7].settext(button[6].text())
        button[6].settext(button[5].text())
        button[5].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func right3
        temp = button[12].text()
        button[12].settext(button[11].text())
        button[11].settext(button[10].text())
        button[10].settext(button[9].text())
        button[9].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return

func right4
        temp = button[16].text()
        button[16].settext(button[15].text())
        button[15].settext(button[14].text())
        button[14].settext(button[13].text())
        button[13].settext(temp)
        movesnr =movesnr + 1
        buttonnr.settext("Moves : " + string(movesnr))
        return
