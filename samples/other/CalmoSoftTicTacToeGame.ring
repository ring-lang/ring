# Project : CalmoSoft Tic-tac-Toe Game
# Date    : 26/10/2019-12:00:00
# Update  : 26/10/2019-17:00:50
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : quiwox@gmail.com

load "stdlib.ring"
load "guilib.ring"

size = 10
player1 = 1
player2 = 0
winsum = 5
button1 = 0
button2 = 0
winbtn = [][]
C_ROWCOUNT = 10
C_COLCOUNT = 10
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
                  setWindowTitle('CalmoSoft Tic-Tac-Toe Game')
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
        gameover(n,m)

func gameover(n,m)
        buttonsum = 0
                if buttonsum1[n][m] = 1
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if (n + p < size + 1) and (m - p > 0)
                          bool1 = (buttonsum1[n+p][m-p] = 1)
                          if bool1 = 1
                             add(winbtn,[n+p,m-p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if (n - p > 0) and (m + p < size + 1)
                          bool2 = (buttonsum1[n-p][m+p] = 1)
                          if bool2 = 1
                             add(winbtn,[n-p,m+p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player1 win!")
                       return
                    ok 
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if (n + p < size + 1) and (m + p < size + 1)
                          bool1 = (buttonsum1[n+p][m+p] = 1)
                          if bool1 = 1
                             add(winbtn,[n+p,m+p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if (n - p > 0) and (m - p > 0)
                          bool2 = (buttonsum1[n-p][m-p] = 1)
                          if bool2 = 1
                             add(winbtn,[n-p,m-p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player1 win!")
                       return
                    ok 
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if m-p > 0
                          bool1 = (buttonsum1[n][m-p] = 1)
                          if bool1 = 1
                             add(winbtn,[n,m-p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if m + p < size + 1
                          bool2 = (buttonsum1[n][m+p] = 1)
                          if bool2 = 1
                             add(winbtn,[n,m+p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player1 win!")
                       return
                    ok                   
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if n + p < size + 1
                          bool1 = (buttonsum1[n+p][m] = 1)
                          if bool1 = 1
                             add(winbtn,[n+p,m])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if n - p > 0
                          bool2 = (buttonsum1[n-p][m] = 1)
                          if bool2 = 1
                             add(winbtn,[n-p,m])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player1 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player1 win!")
                       return
                    ok 
                ok 
                if buttonsum2[n][m] = 2
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if (n + p < size + 1) and (m - p > 0)
                          bool1 = (buttonsum2[n+p][m-p] = 2)
                          if bool1 = 1
                             add(winbtn,[n+p,m-p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if (n - p > 0) and (m + p < size + 1)
                          bool2 = (buttonsum2[n-p][m+p] = 2)
                          if bool2 = 1
                             add(winbtn,[n-p,m+p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player2 win!")
                       return
                    ok 
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if (n + p < size + 1) and (m + p <  size + 1)
                          bool1 = (buttonsum2[n+p][m+p] = 2)
                          if bool1 = 1
                             add(winbtn,[n+p,m+p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if (n - p > 0) and (m - p > 0)
                          bool2 = (buttonsum2[n-p][m-p] = 2)
                          if bool2 = 1
                             add(winbtn,[n-p,m-p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player2 win!")
                       return
                    ok 
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if m-p > 0
                          bool1 = (buttonsum2[n][m-p] = 2)
                          if bool1 = 1
                             add(winbtn,[n,m-p])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if m + p < size + 1
                          bool2 = (buttonsum2[n][m+p] = 2)
                          if bool2 = 1
                             add(winbtn,[n,m+p])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player2 win!")
                       return
                    ok                  
                   button1 = 0
                   button2 = 0
                   winbtn = [][]
                   add(winbtn,[n,m])
                   for p = 1 to winsum-1
                       if n + p < size + 1
                          bool1 = (buttonsum2[n+p][m] = 2)
                          if bool1 = 1
                             add(winbtn,[n+p,m])
                             button1 = button1 + 1
                             if button1 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                   next
                   for p = 1 to winsum-1
                       if n - p > 0
                          bool2 = (buttonsum2[n-p][m] = 2)
                          if bool2 = 1
                             add(winbtn,[n-p,m])
                             button2 = button2 + 1
                             if button2 > winsum - 2
                                msgbox("Player2 win!")
                                return
                             ok
                          else
                             exit
                          ok
                       ok
                    next
                    if button1 + button2 > winsum - 2
                       msgbox("Player2 win!")
                       return
                    ok 
                ok            
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

func msgBox(cText) 
     mb = new qMessageBox(win) {
	  setWindowTitle('Tic-Tac-Toe')
	  setText(cText)
          setstandardbuttons(QMessageBox_OK)
          winbtn = sortFirst(winbtn)
          for n = 1 to winsum
              app.processevents()
              sleep(0.3)
              button[winbtn[n][1]][winbtn[n][2]].setstylesheet(C_BUTTONVIOLETSTYLE)
          next
          result = exec()
          pbegin() 
          }

func sortFirst(aList)
     aList = sort(aList,1)

     for n=1 to len(alist)-1
         for m=n to len(aList)-1 
             if alist[m+1][1] = alist[m][1] and alist[m+1][2] < alist[m][2]
                temp = alist[m+1]
                alist[m+1] = alist[m]
                alist[m] = temp ok
         next
     next
     return aList

