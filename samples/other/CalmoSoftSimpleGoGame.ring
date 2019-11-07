# Project : CalmoSoft Simple Go Game
# Date    : 28/10/2019-12:00:00
# Update  : 28/10/2019-16:33:23
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

size = 20
player1 = 1
player2 = 0
winbtn = [][]
C_ROWCOUNT = 20
C_COLCOUNT = 20
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:silver'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONBLUESTYLE = 'border-radius:17px;color:black; background-color: blue'
C_BUTTONORANGESTYLE = 'border-radius:17px;color:black; background-color: orange'
button = newlist(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT)
buttonsum1 = newlist(size,size)
buttonsum2 = newlist(size,size)

app = new qApp {
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('CalmoSoft Simple Go Game')
                  move(550,140)
                  resize(600,600)
                  setstylesheet('background-color:white')
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_SPACING)
                  LayoutButtonMain.setContentsmargins(0,0,0,0)
                  for Row = 1 to C_ROWCOUNT
                       LayoutButtonRow[Row] = new QHBoxLayout() {
                       setSpacing(C_SPACING)
                       setContentsmargins(0,0,0,0)
                       }
                       for Col = 1 to C_COLCOUNT
                            button[Row][Col] = new QPushButton(win) {
                            setstylesheet(C_EMPTYBUTTONSTYLE)
                            setclickevent("pplay(" + string(Row) + "," + string(Col) + ")")
                            setSizePolicy(1,1)
                            }
                            LayoutButtonRow[Row].AddWidget(button[Row][Col])
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next
                  setLayout(LayoutButtonMain)
                  show()
         }
        exec()
         }

func pplay(n,m)
     if player1 = 1 
        button[n][m] {setstylesheet(C_BUTTONORANGESTYLE)
                      player1 = 0
                      player2 = 1
                      setenabled(false)}
                      buttonsum1[n][m] = 1
     else
        button[n][m] {setstylesheet(C_BUTTONBLUESTYLE)
                      player1 = 1
                      player2 = 0
                      setenabled(false)}
                      buttonsum2[n][m] = 2
     ok
     gameover()

func gameover()
     buttonsum = 0
     for n = 1 to size
         for m = 1 to size
             if buttonsum2[n][m] = 2
                winbtn = [][]
                if (n > 1)
                    add(winbtn,[n-1,m])
                    bool1 = (buttonsum1[n-1][m] = 1) 
                else
                    bool1 = 1
                ok
                if (n > 1) and (m > 1)
                    add(winbtn,[n-1,m-1])
                    bool2 = (buttonsum1[n-1][m-1] = 1)
                else
                    bool2 = 1 
                ok
                if (m > 1)
                    add(winbtn,[n,m-1])
                    bool3 = (buttonsum1[n][m-1] = 1)
                else
                    bool3 = 1 
                ok
                if (n < size) and (m > 1)
                    add(winbtn,[n+1,m-1])
                    bool4 = (buttonsum1[n+1][m-1] = 1)
                else
                    bool4 = 1 
                ok
                if (n < size)
                    add(winbtn,[n+1,m])
                    bool5 = (buttonsum1[n+1][m] = 1)
                else
                    bool5 = 1 
                ok
                if (n < size) and (m < size)
                    add(winbtn,[n+1,m+1])
                    bool6 = (buttonsum1[n+1][m+1] = 1)
                else
                    bool6 = 1 
                ok
                if (m < size)
                    add(winbtn,[n,m+1])
                    bool7 = (buttonsum1[n][m+1] = 1)
                else
                    bool7 = 1 
                ok
                if (n > 1) and (m < size)
                    add(winbtn,[n-1,m+1])
                    bool8 = (buttonsum1[n-1][m+1] = 1)
                else
                    bool8 = 1 
                ok
                bool = bool1 + bool2 + bool3 + bool4 + bool5 + bool6 + bool7 + bool8
                if bool = 8
                   msgbox("Player1 win!",n,m,1)
                ok
             ok
             if buttonsum1[n][m] = 1
                winbtn = [][]
                if (n > 1)
                    add(winbtn,[n-1,m])
                    bool1 = (buttonsum2[n-1][m] = 2) 
                else
                    bool1 = 1
                ok
                if (n > 1) and (m > 1)
                    add(winbtn,[n-1,m-1])
                    bool2 = (buttonsum2[n-1][m-1] = 2)
                else
                    bool2 = 1 
                ok
                if (m > 1)
                    add(winbtn,[n,m-1])
                    bool3 = (buttonsum2[n][m-1] = 2)
                else
                    bool3 = 1 
                ok
                if (n < size) and (m > 1)
                    add(winbtn,[n+1,m-1])
                    bool4 = (buttonsum2[n+1][m-1] = 2)
                else
                    bool4 = 1 
                ok
                if (n < size)
                    add(winbtn,[n+1,m])
                    bool5 = (buttonsum2[n+1][m] = 2)
                else
                    bool5 = 1 
                ok
                if (n < size) and (m < size)
                    add(winbtn,[n+1,m+1])
                    bool6 = (buttonsum2[n+1][m+1] = 2)
                else
                    bool6 = 1 
                ok
                if (m < size)
                    add(winbtn,[n,m+1])
                    bool7 = (buttonsum2[n][m+1] = 2)
                else
                    bool7 = 1 
                ok
                if (n > 1) and (m < size)
                    add(winbtn,[n-1,m+1])
                    bool8 = (buttonsum2[n-1][m+1] = 2)
                else
                    bool8 = 1 
                ok
                bool = bool1 + bool2 + bool3 + bool4 + bool5 + bool6 + bool7 + bool8
                if bool = 8
                   msgbox("Player2 win!",n,m,2)
                ok
             ok
         next
     next
     for n = 1 to size
         for m = 1 to size
             bool = (buttonsum1[n][m] = 1) or (buttonsum2[n][m] = 2)
             if bool = 1
                buttonsum = buttonsum + 1
             ok
         next
     next
     if buttonsum = size*size     
        msgBox("Game Over!")
     ok

func pbegin()
     player1 = 1
     player2 = 0
     for n = 1 to size
         for m = 1 to size
             button[n][m] { setstylesheet(C_EMPTYBUTTONSTYLE)
                            buttonsum1[n][m] = 0
                            buttonsum2[n][m] = 0
                            button[n][m].setenabled(true)
                            win.show() }
         next
     next

func msgBox(cText,n,m,winind) 
     mb = new qMessageBox(win) {
	  setWindowTitle('Go Game')
	  setText(cText)
          setstandardbuttons(QMessageBox_OK) 
              app.processevents()
              sleep(10)
          /*for p = 1 to len(winbtn)
              app.processevents()
              sleep(3)
              button[winbtn[p][1]][winbtn[p][2]].setstylesheet(C_BUTTONVIOLETSTYLE)
          next
          for p = 1 to len(winbtn)
              app.processevents()
              sleep(3)
              if winind = 1
                 button[winbtn[p][1]][winbtn[p][2]].setstylesheet(C_BUTTONORANGESTYLE)
              else
                 button[winbtn[p][1]][winbtn[p][2]].setstylesheet(C_BUTTONBLUESTYLE)
              ok
          next
          app.processevents()
          sleep(3)
          if winind = 1
             button[n][m].setstylesheet(C_BUTTONORANGESTYLE)
          else
             button[n][m].setstylesheet(C_BUTTONBLUESTYLE)
          ok*/
          result = exec()
          pbegin() 
          }
