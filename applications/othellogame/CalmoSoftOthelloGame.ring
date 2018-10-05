# Project : Othello Game
# Date    : 2018/09/25
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
move = 1
score = 0
flagblack = 0
flagwhite = 0
summoveblack = 0
summovewhite = 0
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:gray'
C_BUTTONBLACKSTYLE = 'border-radius:17px;color:black; background-color: black'
C_BUTTONWHITESTYLE = 'border-radius:17px;color:black; background-color: white'
C_BUTTONORANGESTYLE = 'border-radius:17px;color:black; background-color: orange'
C_BUTTONBLUESTYLE = 'border-radius:17px;color:black; background-color: blue'
button = newlist(size+1,size)
btnblack = newlist(size,size)
btnwhite = newlist(size,size)
LayoutButtonRow = list(size+4)
cols = list(size)
rows = list(size)
//colcells = "A":"H"
colcells = [" ","A","B","C","D","E","F","G","H"]

app = new qApp {
         STYLEFusion()
         win = new qWidget() {
                  setWindowTitle('Othello Game')
                  move(490,100)
                  resize(600,600)
                  winheight = win.height()
                  fontsize = 8 + (winheight/70)
                  playscoreblack = new QLabel(win) {
                                          setFont(new qFont("Verdana",fontsize,100,0))
                                          setstylesheet(C_BUTTONORANGESTYLE)
                                          setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                          settext("Black Player Score: 2")
                                          show()
                                          }
                  playscorewhite = new QLabel(win) {
                                           setFont(new qFont("Verdana",fontsize,100,0))
                                           setstylesheet(C_BUTTONORANGESTYLE)
                                           setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                           settext("White Player Score: 2")
                                           show()
                                           }
                  nextmove = new QLabel(win) {
                                    setFont(new qFont("Verdana",fontsize,100,0))
                                    setstylesheet(C_BUTTONORANGESTYLE)
                                    setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                    settext("Next Move: Black Player")
                                    show()
                                    }
                  newgame  = new QPushButton(win) {
                                     setFont(new qFont("Verdana",fontsize,100,0))
                                     setstylesheet("background-color:violet")
                                     settext("New Game")
                                     setclickevent("pstart()")
                                     show()
                                     }
                  for n = 1 to size
                       cols[n] = new QLabel(win) {
                                    setFont(new qFont("Verdana",fontsize,100,0))
                                    setstylesheet(C_BUTTONBLUESTYLE)
                                    setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                    settext(colcells[n])
                                    }
                  next
                  for n = 1 to size
                       rows[n] = new QLabel(win) {
                                     setFont(new qFont("Verdana",fontsize,100,0))
                                     setstylesheet(C_BUTTONBLUESTYLE)
                                     setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                     settext(string(n))
                                     }
                  next
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_SPACING)
                  LayoutButtonMain.setContentsmargins(0,0,0,0)
                  LayoutButtonColCells = new QHBoxLayout()
                  LayoutButtonColCells.setSpacing(C_SPACING)
                  LayoutButtonColCells.setContentsmargins(0,0,0,0)
                  for n = 1 to size
                       LayoutButtonColCells.AddWidget(cols[n])
                  next
                  LayoutButtonMain.AddLayout(LayoutButtonColCells)
                  for Col = 1 to size
                       LayoutButtonRow[Col] = new QHBoxLayout() {
                       setSpacing(C_SPACING)
                       setContentsmargins(0,0,0,0)
                       }
                       LayoutButtonRow[Col].AddWidget(rows[Col])
                       for Row = 1 to size
                            button[Row][Col] = new QPushButton(win) {
                            setstylesheet(C_EMPTYBUTTONSTYLE)
                            setclickevent("pplay(" + string(Row) + "," + string(Col) + ")")
                            setSizePolicy(1,1)
                            }
                            LayoutButtonRow[Col].AddWidget(button[Row][Col])
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Col])
                  next    
                  LayoutButtonMain.AddWidget(playscoreblack) 
                  LayoutButtonMain.AddWidget(playscorewhite) 
                  LayoutButtonMain.AddWidget(nextmove) 
                  LayoutButtonMain.AddWidget(newgame)  
                  setLayout(LayoutButtonMain)
                  pstart()
                  show()
         }
        exec()
         }

func pstart()
       move = 1
       score = 0 
       flagblack = 0
       flagwhite = 0
       for col = 1 to size
            for row = 1 to size
                 btnblack[col][row] = 0
                 btnwhite[col][row] = 0
                 button[col][row].setenabled(true)
                 button[col][row] { setstylesheet(C_EMPTYBUTTONSTYLE) }
            next
       next
       nextmove.settext("Next Move: Black Player")
       playscoreblack.settext("Black Player Score: 2")
       playscorewhite.settext("White Player Score: 2")
       button[4][4].setenabled(false)
       button[5][5].setenabled(false)
       button[4][5].setenabled(false)
       button[5][4].setenabled(false)
       button[4][4] { setstylesheet(C_BUTTONBLACKSTYLE) }
       button[5][5] { setstylesheet(C_BUTTONBLACKSTYLE) }
       button[4][5] { setstylesheet(C_BUTTONWHITESTYLE) }
       button[5][4] { setstylesheet(C_BUTTONWHITESTYLE) }
       btnblack[4][4] = 1
       btnblack[5][5] = 1
       btnwhite[4][5] = 1
       btnwhite[5][4] = 1

func summove()
       summoveblack = 0
       summovewhite = 0
       for col = 1 to size
            for row = 1 to size
                 if btnblack[col][row] = 1
                    summoveblack = summoveblack + 1
                 ok
                 if btnwhite[col][row] = 1
                    summovewhite = summovewhite + 1
                 ok 
            next
       next
       playscoreblack.settext("Black Player Score: " + string(summoveblack))
       playscorewhite.settext("White Player Score: " + string(summovewhite))

func pplay(n,m)
       if move = 1
          nextmove.settext("Next Move: White Player")    
       else
          nextmove.settext("Next Move: Black Player") 
       ok              
       if move = 1
          move = 0
          button[n][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
          btnblack[n][m] = 1
          pcheckrightblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckleftblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdownblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckupblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagdownrightblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagdownleftblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiaguprightblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagupleftblack(n,m)
          if flagblack = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          if flagblack = 0
             msgBox('Bad move')
             move = 1
             button[n][m] { setstylesheet(C_EMPTYBUTTONSTYLE) }
          ok
       ok
       if move = 0
          move = 1
          button[n][m] { setstylesheet(C_BUTTONWHITESTYLE) }
          btnwhite[n][m] = 1
          pcheckrightwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckleftwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdownwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckupwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagdownrightwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagdownleftwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiaguprightwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          pcheckdiagupleftwhite(n,m)
          if flagwhite = 1
             button[n][m].setenabled(false)
             summove()
             return
          ok
          if flagwhite = 0
             msgBox('Bad move')
             move = 0
             button[n][m] { setstylesheet(C_EMPTYBUTTONSTYLE) }
          ok
       ok

func pcheckrightblack(n,m)
       yesflag = 0
       whiteno = 0
       for x = n+1 to size-1
            if btnwhite[x][m] = 1
               yesflag = 1
               loop
            else
               whiteno = x
               exit
            ok
       next
       if whiteno > n+1 and btnblack[whiteno][m] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = n+1 to whiteno - 1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[nc][m] = 0
               btnblack[nc][m] = 1
          next
       ok

func pcheckleftblack(n,m)
       yesflag = 0
       whiteno = 0
       for x = n-1 to 1 step -1
            if btnwhite[x][m] = 1
               yesflag = 1
               loop
            else
               whiteno = x
               exit
            ok
       next
       if whiteno < n-1 and btnblack[whiteno][m] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = n-1 to whiteno step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[nc][m] = 0
               btnblack[nc][m] = 1
          next
       ok

func pcheckdownblack(n,m)
       yesflag = 0
       whiteno = 0
       for y = m+1 to size-1
            if btnwhite[n][y] = 1
               yesflag = 1
               loop
            else
               whiteno = y
               exit
            ok
       next
       if whiteno > m+1 and btnblack[n][whiteno] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nr = m+1 to whiteno - 1
               button[nr][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nr] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n][nr] = 0
               btnblack[n][nr] = 1
          next
       ok

func pcheckupblack(n,m)
       yesflag = 0
       whiteno = 0
       for x = m-1 to 1 step -1
            if btnwhite[n][x] = 1
               yesflag = 1
               loop
            else
               whiteno = x
               exit
            ok
       next
       if whiteno < m-1 and btnblack[n][whiteno] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = m-1 to whiteno step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n][nc] = 0
               btnblack[n][nc] = 1
          next
       ok

func pcheckdiagdownrightblack(n,m)
       yesflag = 0
       whiteno1 = 0
       whiteno2 = 0
       for x = 1 to size
            if (n+x) < size and (m+x) < size
               if btnwhite[n+x][m+x] = 1
                  yesflag = 1
                  loop
               else
                  whiteno1 = n+x
                  whiteno2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if whiteno1 > n and btnblack[whiteno1][whiteno2] = 1 # # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = 1 to x
               button[n+nc][m+nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m+nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n+nc][m+nc] = 0
               btnblack[n+nc][m+nc] = 1
          next
       ok

func pcheckdiagdownleftblack(n,m)
       yesflag = 0
       whiteno1 = 0
       whiteno2 = 0
       for x = 1 to size
            if (n-x) < size and (m+x) < size and (n-x) > 0
               if btnwhite[n-x][m+x] = 1
                  yesflag = 1
                  loop
               else
                  whiteno1 = n-x
                  whiteno2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if whiteno1 > 0 and whiteno2 > 0
          if whiteno1 < n-1 and btnblack[whiteno1][whiteno2] = 1 # and yesflag = 1
             flagblack = 1
             flagwhite = 0
             for nc = 1 to x
                  button[n-nc][m+nc].setenabled(false)
                  app.processevents()
                  sleep(0.5)
                  button[n-nc][m+nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
                  btnwhite[n-nc][m+nc] = 0
                  btnblack[n-nc][m+nc] = 1
             next
          ok
       ok

func pcheckdiaguprightblack(n,m)
       yesflag = 0
       whiteno1 = 0
       whiteno2 = 0
       for x = 1 to size
            if (n+x) > 1 and (m-x) > 1 and (n+x) < size and (m-x) < size
               if btnwhite[n+x][m-x] = 1
                  yesflag = 1
                  loop
               else
                  whiteno1 = n+x
                  whiteno2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if whiteno1 > n+1 and btnblack[whiteno1][whiteno2] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = 1 to x
               button[n+nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m-nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n+nc][m-nc] = 0
               btnblack[n+nc][m-nc] = 1
          next
       ok

func pcheckdiagupleftblack(n,m)
       yesflag = 0
       whiteno1 = 0
       whiteno2 = 0
       for x = 1 to size
            if (n-x) > 0 and (m-x) > 0
               if btnwhite[n-x][m-x] = 1
                  yesflag = 1
                  loop
               else
                  whiteno1 = n-x
                  whiteno2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if whiteno1 > 0 and btnblack[whiteno1][whiteno2] = 1 # and yesflag = 1
          flagblack = 1
          flagwhite = 0
          for nc = 1 to x
               button[n-nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n-nc][m-nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n-nc][m-nc] = 0
               btnblack[n-nc][m-nc] = 1
          next
       ok

func pcheckrightwhite(n,m)
       yesflag = 0
       blackno = 0
       for x = n+1 to size-1
            if btnblack[x][m] = 1
               yesflag = 1
               loop
            else
               blackno = x
               exit
            ok
       next
       if blackno > n+1 and btnwhite[blackno][m] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = n+1 to blackno - 1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[nc][m] = 0
               btnwhite[nc][m] = 1
          next
       ok

func pcheckleftwhite(n,m)
       yesflag = 0
       blackno = 0
       for x = n-1 to 1 step -1
            if btnblack[x][m] = 1
               yesflag = 1
               loop
            else
               blackno = x
               exit
            ok
       next
       if blackno < n-1 and btnwhite[blackno][m] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = n-1 to blackno step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[nc][m] = 0
               btnwhite[nc][m] = 1
          next
       ok

func pcheckdownwhite(n,m)
       yesflag = 0
       blackno = 0
       for y = m+1 to size-1
            if btnblack[n][y] = 1
               yesflag = 1
               loop
            else
               blackno = y
               exit
            ok
       next
       if blackno > m+1 and btnwhite[n][blackno] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nr = m+1 to blackno - 1
               button[n][nr].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nr] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n][nr] = 0
               btnwhite[n][nr] = 1
          next
       ok

func pcheckupwhite(n,m)
       yesflag = 0
       blackno = 0
       for x = m-1 to 1 step -1
            if btnblack[n][x] = 1
               yesflag = 1
               loop
            else
               blackno = x
               exit
            ok
       next
       if blackno < m-1 and btnwhite[n][blackno] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = m-1 to blackno step -1
               button[n][nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n][nc] = 0
               btnwhite[n][nc] = 1
          next
       ok

func pcheckdiagdownrightwhite(n,m)
       yesflag = 0
       blackno1 = 0
       blackno2 = 0
       for x = 1 to size
            if (n+x) < (size+1) and (m+x) < (size+1)
               if btnblack[n+x][m+x] = 1
                  yesflag = 1
                  loop
               else
                  blackno1 = n+x
                  blackno2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if blackno1 > n and btnwhite[blackno1][blackno2] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = 1 to x
               button[n+nc][m+nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m+nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n+nc][m+nc] = 0
               btnwhite[n+nc][m+nc] = 1
          next
       ok

func pcheckdiagdownleftwhite(n,m)
       yesflag = 0
       blackno1 = 0
       blackno2 = 0
       for x = 1 to size
            if (n-x) < size and (m+x) < size and (n-x) > 0
               if btnblack[n-x][m+x] = 1
                  yesflag = 1
                  loop
               else
                  blackno1 = n-x
                  blackno2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if blackno1 > 0 and blackno2 > 0
          if blackno1 < n-1 and btnwhite[blackno1][blackno2] = 1 # and yesflag = 1
             flagwhite = 1
             flagblack = 0
             for nc = 1 to x
                  button[n-nc][m+nc].setenabled(false)
                  app.processevents()
                  sleep(0.5)
                  button[n-nc][m+nc] { setstylesheet(C_BUTTONWHITESTYLE) }
                  btnblack[n-nc][m+nc] = 0
                  btnwhite[n-nc][m+nc] = 1
             next
          ok
       ok

func pcheckdiaguprightwhite(n,m)
       yesflag = 0
       blackno1 = 0
       blackno2 = 0
       for x = 1 to size
            if (n+x) > 1 and (m-x) > 1 and (n+x) < size and (m-x) < size
               if btnblack[n+x][m-x] = 1
                  yesflag = 1
                  loop
               else
                  blackno1 = n+x
                  blackno2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if blackno1 > n+1 and btnwhite[blackno1][blackno2] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = 1 to x
               button[n+nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m-nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n+nc][m-nc] = 0
               btnwhite[n+nc][m-nc] = 1
          next
       ok

func pcheckdiagupleftwhite(n,m)
       yesflag = 0
       blackno1 = 0
       blackno2 = 0
       for x = 1 to size
            if (n-x) > 0 and (m-x) > 0
               if btnblack[n-x][m-x] = 1
                  yesflag = 1
                  loop
               else
                  blackno1 = n-x
                  blackno2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if blackno1 > 0 and btnwhite[blackno1][blackno2] = 1 # and yesflag = 1
          flagwhite = 1
          flagblack = 0
          for nc = 1 to x
               button[n-nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n-nc][m-nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n-nc][m-nc] = 0
               btnwhite[n-nc][m-nc] = 1
          next
       ok

func msgBox(cText) 
	mb = new qMessageBox(win) {
	        setWindowTitle('Othello Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
        }
        return
