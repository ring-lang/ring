# Project : Minesweeper Game
# Date    : 2018/09/11
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

limit = 99
C_ROWCOUNT = 16
C_COLCOUNT = 30
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:10px;background-color:white'
C_BUTTONREDSTYLE = 'border-radius:17px;color:black; background-color: red'
C_BUTTONYELLOWSTYLE = 'border-radius:17px;color:black; background-color: yellow'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONGRAYSTYLE = 'border-radius:17px;color:black; background-color: gray'
C_MENUSTYLE	= "color:white;background-color:rgb(50,50,50);border-radius:17px"
button = newlist(C_ROWCOUNT,C_COLCOUNT)
mines = dimlist([C_ROWCOUNT,C_COLCOUNT,1])
LayoutButtonRow = list(C_ROWCOUNT+3)

app = new qApp {
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('Minesweeper Game')
                  move(490,100)
                  resize(800,600)
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
                            if Row = C_ROWCOUNT and Col = C_COLCOUNT
                            ok
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next      
                  setLayout(LayoutButtonMain)
                  pbegin()
                  show()
         }
        exec()
         }

func pplay(m,n) 
       if mines[m][n][1] = 1
          button[m][n] {setbtnimage(self,"mine.png")}
          win.show()
       else
          button[m][n].setstylesheet(C_BUTTONGRAYSTYLE)
       ok

func pbegin()
       for n = 1 to limit
            x = random(C_COLCOUNT - 1) + 1
            y = random(C_ROWCOUNT - 1) + 1
            mines[y][x][1] = 1
            win.show() 
       next

func dimlist(dimArray)
        sizeList = len(dimArray)
        newParms = []
        for i = 2 to sizeList
            Add(newParms, dimArray[i]) 
        next      
        alist = list(dimArray[1])
        if sizeList = 1
           return aList
        ok
        for t in alist
              t = dimlist(newParms)
        next       
        return alist

func msgBox(cText) 
	mb = new qMessageBox(win) {
	        setWindowTitle('Minesweeper Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                pbegin() 
        }
