# Project : Minesweeper Game
# Date    : 2018/09/17
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

limit = 50
score = 0
flag  = 0
C_ROWCOUNT = 20
C_COLCOUNT = 20
C_SPACING  = 5

C_EMPTYBUTTONSTYLE  =  'border-radius:17px;background-color:gray'
C_BUTTONREDSTYLE    = 'border-radius:17px;color:black; background-color: red'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONWHITESTYLE  = 'border-radius:17px;color:black; background-color: white'

button  = newlist(C_ROWCOUNT,C_COLCOUNT)
mines   = newlist(C_ROWCOUNT,C_COLCOUNT)
minesok = newlist(C_ROWCOUNT,C_COLCOUNT)
minesum = newlist(C_ROWCOUNT,C_COLCOUNT)
tilesok = newlist(C_ROWCOUNT,C_COLCOUNT)
T       = newlist(C_ROWCOUNT,C_COLCOUNT)

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
###==========================

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
                                       settext('A')
                                       setenabled(true)
                                       setIcon(new qIcon(new qPixMap2(0,0))) }
                 win.show() 
            next
       next
	   
       for col = 1 to C_COLCOUNT
            for row = 1 to C_ROWCOUNT
                if minesok[row][col] = 0
                    button[row][col].settext('.')  ### Blanks - Fill the cells
				ok
				
                if mines[row][col] = 1
                    button[row][col].settext('M')  ### No M's ???, After Game Over shows M for empty cells		
				ok				
              
            next
       next
	   
       for col = 1 to C_COLCOUNT
            for row = 1 to C_ROWCOUNT
                 tilesok[row][col] = 0
            next
       next

###============================
	   
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
          pnumbernew(m,n)
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
       button[m][n].settext('B')      ### B - Cell Clicked
       tilesok[m][n] = 1

func emptycells(x,y)
       minesok[x][y] = 1
       button[x][y].settext('C')      ### C - Next to "B" Clicked Cell, no Nbr for Mines
       if mines[x][y] = 1
          return
       else
           if minesum[x][y] != 0
              button[x][y].setstylesheet(C_BUTTONWHITESTYLE)
              button[x][y].settext(string(minesum[x][y]))
           else
              button[x][y].setstylesheet(C_BUTTONVIOLETSTYLE)
              button[x][y].settext('D')
              tilesok[x][y] = 1
           ok
       ok
       T[x][y] = 1
       button[x][y].setstylesheet(C_BUTTONVIOLETSTYLE) 
       button[x][y].settext('E')       ### E Empty Cells around "B"  clicked cell
       tilesok[x][y] = 1
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

func pnumbernew(pos1,pos2)
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
                 if mines[n][m] = 1
                    minenum = minenum + 1
                 ok
                 if minenum = 0
                    if mines[n][m] = 1
                       button[n][m].settext('F')
                       button[n][m].setstylesheet(C_BUTTONWHITESTYLE)
                       button[n][m] {setbtnimage(self,"mine.png")}
                       win.show()
                    ok
                 else
                    if mines[n][m] = 0
                       button[n][m].settext(string(minenum))
                       minesum[n][m] = minenum
                    else
                       button[n][m].settext('G')        ### G  - Mines ? After Game over
                       button[n][m].setstylesheet(C_BUTTONWHITESTYLE)
                       button[n][m] {setbtnimage(self,"mine.png")}
                       win.show()
                    ok
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
       if minenum = 0
          button[1][1].settext("H")
          if mines[1][1] = 1
             button[n][m].settext('I')
             button[n][m].setstylesheet(C_BUTTONWHITESTYLE)
             button[n][m] {setbtnimage(self,"mine.png")}
             win.show()
          ok
       else
          if mines[1][1] = 0
             button[1][1].settext(string(minenum))
             minesum[1][1] = minenum
          else
             button[1][1].settext('J')
             button[n][m].setstylesheet(C_BUTTONWHITESTYLE)
             button[1][1] {setbtnimage(self,"mine.png")}
             win.show()
          ok
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
       if minenum = 0
          button[C_ROWCOUNT][1].settext("K")
          if mines[C_ROWCOUNT][1] = 1
             button[C_ROWCOUNT][1].settext('L')
             button[C_ROWCOUNT][1].setstylesheet(C_BUTTONWHITESTYLE)
             button[C_ROWCOUNT][1] {setbtnimage(self,"mine.png")}
             win.show()
          ok
       else
          if mines[C_ROWCOUNT][1] = 0
             button[C_ROWCOUNT][1].settext(string(minenum))
             minesum[C_ROWCOUNT][1] = minenum
          else
             button[C_ROWCOUNT][1].settext('N')
             button[C_ROWCOUNT][1].setstylesheet(C_BUTTONWHITESTYLE)
             button[C_ROWCOUNT][1] {setbtnimage(self,"mine.png")}
             win.show()
          ok
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
       if minenum = 0
          button[1][C_COLCOUNT].settext("O")
          if mines[1][C_COLCOUNT] = 1
             button[1][C_COLCOUNT].settext('')
             button[1][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
             button[1][C_COLCOUNT] {setbtnimage(self,"mine.png")}
             win.show()
          ok
       else
          if mines[1][C_COLCOUNT] = 0
             button[1][C_COLCOUNT].settext(string(minenum))
             minesum[1][C_COLCOUNT] = minenum
          else
             button[1][C_COLCOUNT].settext('P')
             button[1][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
             button[1][C_COLCOUNT] {setbtnimage(self,"mine.png")}
             win.show()
          ok
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
       if minenum = 0
          button[C_ROWCOUNT][C_COLCOUNT].settext("Q")
          if mines[C_ROWCOUNT][C_COLCOUNT] = 1
             button[C_ROWCOUNT][C_COLCOUNT].settext('R')
             button[C_ROWCOUNT][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
             button[C_ROWCOUNT][C_COLCOUNT] {setbtnimage(self,"mine.png")}
             win.show()
          ok
       else
          if mines[C_ROWCOUNT][C_COLCOUNT] = 0
             button[C_ROWCOUNT][C_COLCOUNT].settext(string(minenum))
             minesum[C_ROWCOUNT][C_COLCOUNT] = minenum
          else
             button[C_ROWCOUNT][C_COLCOUNT].settext('S')
             button[C_ROWCOUNT][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
             button[C_ROWCOUNT][C_COLCOUNT] {setbtnimage(self,"mine.png")}
             win.show()
          ok
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
            if minenum = 0
               button[1][n].settext("T")
               if mines[1][n] = 1
                  button[1][n].settext("U")
                  button[1][n].setstylesheet(C_BUTTONWHITESTYLE)
                  button[1][n] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
            else
               if mines[1][n] != 1
                  button[1][n].settext(string(minenum))
                  minesum[1][n] = minenum
               else
                  button[1][n].settext('V')
                  button[1][n].setstylesheet(C_BUTTONWHITESTYLE)
                  button[1][n] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
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
            if minenum = 0
               button[C_ROWCOUNT][n].settext("W")
               if mines[C_ROWCOUNT][n] = 1
                  button[C_ROWCOUNT][n].settext('X')
                  button[C_ROWCOUNT][n].setstylesheet(C_BUTTONWHITESTYLE)
                  button[C_ROWCOUNT][n] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
            else
               if mines[C_ROWCOUNT][n] != 1
                  button[C_ROWCOUNT][n].settext(string(minenum))
                  minesum[C_ROWCOUNT][n] = minenum
               else
                  button[C_ROWCOUNT][n].settext('Y')
                  button[C_ROWCOUNT][n].setstylesheet(C_BUTTONWHITESTYLE)
                  button[C_ROWCOUNT][n] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
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
            if minenum = 0
               button[n][1].settext("Z")
               if mines[n][1] = 1
                  button[n][1].settext('<')
                  button[n][1].setstylesheet(C_BUTTONWHITESTYLE)
                  button[n][1] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
            else
               if mines[n][1] != 1
                  button[n][1].settext(string(minenum))
                  minesum[n][1] = minenum
               else
                  button[n][1].settext('>')
                  button[n][1].setstylesheet(C_BUTTONWHITESTYLE)
                  button[n][1] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
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
            if minenum = 0
               button[n][C_COLCOUNT].settext("aa")
               if mines[n][C_COLCOUNT] = 1
                  button[n][C_COLCOUNT].settext('ab')
                  button[n][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
                  button[n][C_COLCOUNT] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
            else
               if mines[n][C_COLCOUNT] != 1
                  button[n][C_COLCOUNT].settext(string(minenum))
                  minesum[n][C_COLCOUNT] = minenum
               else
                  button[n][C_COLCOUNT].settext('ac')
                  button[n][C_COLCOUNT].setstylesheet(C_BUTTONWHITESTYLE)
                  button[n][C_COLCOUNT] {setbtnimage(self,"mine.png")}
                  win.show()
               ok
            ok
       next    
       cellsenabled()
       button[pos1][pos2].setstylesheet(C_BUTTONREDSTYLE) 
       button[pos1][pos2].settext('ad')                     ### ad - red - game over
       button[pos1][pos2] {setbtnimage(self,"mine.png")} 
       for col = 1 to C_COLCOUNT
            for row = 1 to C_ROWCOUNT
                 if tilesok[row][col] = 1
                    button[row][col].settext('ae')    ###  ae  After game over - blank cells discovered
                 ok
            next
       next
