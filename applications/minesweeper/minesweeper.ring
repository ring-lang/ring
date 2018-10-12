# Project : Minesweeper Game
# Date    : 2018/09/17
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

limit = 79
score = 0
flag = 0
C_ROWCOUNT = 16
C_COLCOUNT = 30
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:gray'
C_BUTTONREDSTYLE = 'border-radius:17px;color:black; background-color: red'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONWHITESTYLE = 'border-radius:17px;color:black; background-color: white'
button = newlist(C_ROWCOUNT,C_COLCOUNT)
mines = newlist(C_ROWCOUNT,C_COLCOUNT)
minesok = newlist(C_ROWCOUNT,C_COLCOUNT)
minesum = newlist(C_ROWCOUNT,C_COLCOUNT)
T = newlist(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT+3)

app = new qApp {
         STYLEFusion()
         win = new qWidget() {
                  setWindowTitle('Minesweeper Game')
                  move(490,100)
                  resize(800,600)
                  winheight = win.height()
                  fontsize = 8 + (winheight/70)
                  playerscore = new QLabel(win) {
                                      setFont(new qFont("Verdana",fontsize,100,0))
                                      setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                      settext("Play Score:")
                                      show()
                                      }
                  newgame  = new QPushButton(win) {
                                     setFont(new qFont("Verdana",fontsize,100,0))
                                     setstylesheet("background-color:violet")
                                     settext("New Game")
                                     setclickevent("pbegin()")
                                     show()
                                     }
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
                            setclickevent("pplaybegin(" + string(Row) + "," + string(Col) + ")")
                            setSizePolicy(1,1)
                            }
                            LayoutButtonRow[Row].AddWidget(button[Row][Col])
                            if Row = C_ROWCOUNT and Col = C_COLCOUNT
                            ok
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next    
                  LayoutButtonMain.AddWidget(playerscore)  
                  LayoutButtonMain.AddWidget(newgame)  
                  setLayout(LayoutButtonMain)
                  pbegin()
                  show()
         }
        exec()
         }

func pbegin()
       score = 0       
       playerscore.settext('Play score: ')
       mines = newlist(C_ROWCOUNT,C_COLCOUNT)
       for n = 1 to limit
            x = random(C_COLCOUNT - 1) + 1
            y = random(C_ROWCOUNT - 1) + 1
            mines[y][x] = 1
            win.show() 
       next
       for n = 1 to C_ROWCOUNT
            for m = 1 to C_COLCOUNT
                 button[n][m] { setstylesheet(C_EMPTYBUTTONSTYLE)
                                       settext('')
                                       setenabled(true)
                                       setIcon(new qIcon(new qPixMap2(0,0))) }
                 win.show() 
            next
       next
       for col = 1 to C_COLCOUNT
            for row = 1 to C_ROWCOUNT
                 if minesok[row][col] = 0
                    button[row][col].settext('')
                 ok
            next
       next
       for col = 1 to C_COLCOUNT
            for row = 1 to C_ROWCOUNT
                 minesum[row][col] = 0
            next
       next

func cellsenabled()
       for n = 1 to C_ROWCOUNT
            for m = 1 to C_COLCOUNT
                 button[n][m].setenabled(false)
                 win.show() 
            next
       next

func pplaybegin(m,n) 
       flag = 1
       score = score + 1
       playerscore.settext('Play score: ' + string(score))
       if mines[m][n] = 1
          button[m][n].setstylesheet(C_BUTTONREDSTYLE)    
          button[m][n] {setbtnimage(self,"mine.png")}
          msgBox('Game Over')
          flag = 0
       else
          pplaynext(m,n)
       ok

func pplaynext(m,n) 
       pnumber()
       for n1 = 1 to C_COLCOUNT
            for n2 = 2 to C_ROWCOUNT
                 T[n2][n1] = minesum[n2][n1]
            next
       next
       emptycells(m,n)
       button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
       button[m][n].settext('')

func emptycells(x,y)
       minesok[x][y] = 1
       button[x][y].settext('')
       if mines[x][y] = 1
          return
       else
           if minesum[x][y] != 0
              button[x][y].setstylesheet(C_BUTTONWHITESTYLE)
              button[x][y].settext(string(minesum[x][y]))
           else
              button[x][y].setstylesheet(C_BUTTONVIOLETSTYLE)
              button[x][y].settext('')
           ok
       ok
       T[x][y] = 1
       button[x][y].setstylesheet(C_BUTTONVIOLETSTYLE) 
       button[x][y].settext('')
       if x > 1
          xx = x - 1
       else
          return
       ok
       if x > 1 and T[xx][y ] = 0 minesok[xx][y] = 1 emptycells(xx,y) 
          else if minesum[xx][y] != 0 
          button[xx][y].setstylesheet(C_BUTTONWHITESTYLE)
          button[xx][y].settext(string(minesum[xx][y])) 
          button[xx][y].setenabled(false) ok ok
       if x < C_ROWCOUNT
          xx = x + 1
       else
          return
       ok
       if x < C_ROWCOUNT and T[xx][y] = 0 minesok[xx][y] = 1 emptycells(xx,y) 
          else if minesum[xx][y] != 0 
          button[xx][y].setstylesheet(C_BUTTONWHITESTYLE)
          button[xx][y].settext(string(minesum[xx][y])) 
          button[xx][y].setenabled(false) ok ok
       if y > 1
          yy = y - 1
       else
          return
       ok
       if y > 1 and T[x][yy] = 0 minesok[x][yy] = 1 emptycells(x,yy) 
          else if minesum[x][yy] != 0
          button[x][yy].setstylesheet(C_BUTTONWHITESTYLE)
          button[x][yy].settext(string(minesum[x][yy]))
          button[x][yy].setenabled(false) ok ok
       if y < C_COLCOUNT
          yy = y + 1
       else
          return
       ok
       if yy < C_COLCOUNT and T[x][yy] = 0 minesok[x][yy] = 1 emptycells(x,yy) 
          else if minesum[x][yy] != 0
          button[x][yy].setstylesheet(C_BUTTONWHITESTYLE)
          button[x][yy].settext(string(minesum[x][yy])) 
          button[x][yy].setenabled(false) ok ok
       if minesum[x-1][y-1] != 0
          button[x-1][y-1].setstylesheet(C_BUTTONWHITESTYLE)
          button[x-1][y-1].settext(string(minesum[x-1][y-1]))
          button[x-1][y-1].setenabled(false) 
       ok
       if minesum[x+1][y-1] != 0
          button[x+1][y-1].setstylesheet(C_BUTTONWHITESTYLE)
          button[x+1][y-1].settext(string(minesum[x+1][y-1]))
          button[x+1][y-1].setenabled(false)
       ok
       if minesum[x-1][y+1] != 0
          button[x-1][y+1].setstylesheet(C_BUTTONWHITESTYLE)
          button[x-1][y+1].settext(string(minesum[x-1][y+1]))
          button[x-1][y+1].setenabled(false)
       ok
       if minesum[x+1][y+1] != 0
          button[x+1][y+1].setstylesheet(C_BUTTONWHITESTYLE)
          button[x+1][y+1].settext(string(minesum[x+1][y+1]))
          button[x+1][y+1].setenabled(false)
       ok

func msgBox(cText) 
	mb = new qMessageBox(win) {
	        setWindowTitle('Minesweeper Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                pbegin() 
        }

func pnumber()
       for m = 2 to C_COLCOUNT-1
            for n = 2 to C_ROWCOUNT-1
                 minenum = 0
                 if mines[n][m-1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n][m+1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n-1][m] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n+1][m] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n-1][m-1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n+1][m-1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n-1][m+1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n+1][m+1] = 1
                    minenum = minenum + 1
                 ok
                 if mines[n][m] != 1
                    minesum[n][m] = minenum
                 ok
            next
       next
       minenum = 0
       if mines[2][1] = 1
          minenum = minenum + 1
       ok
       if mines[1][2] = 1
          minenum = minenum + 1
       ok
       if mines[2][2] = 1
          minenum = minenum + 1
       ok
       if mines[1][1] = 0
          minesum[1][1] = minenum
       ok
       minenum = 0
       if mines[C_ROWCOUNT-1][1] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT-1][2] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT][2] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT][1] = 0
          minesum[C_ROWCOUNT][1] = minenum
       ok
       minenum = 0
       if mines[1][C_COLCOUNT-1] = 1
          minenum = minenum + 1
       ok
       if mines[2][C_COLCOUNT-1] = 1
          minenum = minenum + 1
       ok
       if mines[2][C_COLCOUNT] = 1
          minenum = minenum + 1
       ok
       if mines[1][C_COLCOUNT] = 0
          minesum[1][C_COLCOUNT] = minenum
       ok
       minenum = 0
       if mines[C_ROWCOUNT][C_COLCOUNT-1] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT-1][C_COLCOUNT-1] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT-1][C_COLCOUNT] = 1
          minenum = minenum + 1
       ok
       if mines[C_ROWCOUNT][C_COLCOUNT] = 0
          minesum[C_ROWCOUNT][C_COLCOUNT] = minenum
       ok
       for n = 2 to C_COLCOUNT-1
            minenum = 0
            if mines[1][n-1] = 1
               minenum = minenum + 1
            ok
            if mines[1][n+1] = 1
               minenum = minenum + 1
            ok
            if mines[2][n-1] = 1
               minenum = minenum + 1
            ok
            if mines[2][n+1] = 1
               minenum = minenum + 1
            ok
            if mines[2][n] = 1
               minenum = minenum + 1
            ok
            if mines[1][n] != 1
               minesum[1][n] = minenum
            ok
       next
       for n = 2 to C_COLCOUNT-1
            minenum = 0
            if mines[C_ROWCOUNT][n] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT][n-1] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT][n+1] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT-1][n-1] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT-1][n+1] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT-1][n] = 1
               minenum = minenum + 1
            ok
            if mines[C_ROWCOUNT][n] != 1
               minesum[C_ROWCOUNT][n] = minenum
            ok
       next
       for n = 2 to C_ROWCOUNT-1
            minenum = 0
            if mines[n-1][1] = 1
               minenum = minenum + 1
            ok
            if mines[n+1][1] = 1
               minenum = minenum + 1
            ok
            if mines[n-1][2] = 1
               minenum = minenum + 1
            ok
            if mines[n+1][2] = 1
               minenum = minenum + 1
            ok
            if mines[n][2] = 1
               minenum = minenum + 1
            ok
            if mines[n][1] != 1
               minesum[n][1] = minenum
            ok
       next
       for n = 2 to C_ROWCOUNT-1
            minenum = 0
            if mines[n-1][C_COLCOUNT] = 1
               minenum = minenum + 1
            ok
            if mines[n+1][C_COLCOUNT] = 1
               minenum = minenum + 1
            ok
            if mines[n-1][C_COLCOUNT-1] = 1
               minenum = minenum + 1
            ok
            if mines[n+1][C_COLCOUNT-1] = 1
               minenum = minenum + 1
            ok
            if mines[n][C_COLCOUNT-1] = 1
               minenum = minenum + 1
            ok
            if mines[n][C_COLCOUNT] != 1
               minesum[n][C_COLCOUNT] = minenum
            ok
       next
