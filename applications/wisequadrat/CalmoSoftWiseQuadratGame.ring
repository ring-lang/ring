# Project : Wise Quadrat Game
# Date    : 2018/09/07
# Author : Gal Zsolt (~ CalmoSoft ~), Mahmoud Fayed
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 6
player1 = 1
player2 = 0
C_ROWCOUNT = 6
C_COLCOUNT = 6
C_SPACING = 5
button = newlist(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT)
buttonsum1 = dimlist([size,size,1])
buttonsum2 = dimlist([size,size,1])
colorgray = 'background-color:gray'
colorviolet = 'background-color:violet'
colorwhite = 'background-color:white'
colororange = 'background-color:orange'

app = new qApp {
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('Resizing buttons in Layout')
                  move(490,100)
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
                            setstylesheet(colorgray)
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
           button[n][m] {setstylesheet(colororange)
                                player1 = 0
                                player2 = 1
                                setenabled(false)}
                                buttonsum1[n][m][1] = 1
        else
           button[n][m] {setstylesheet(colorwhite)
                                player1 = 1
                                player2 = 0
                                setenabled(false)}
                                buttonsum2[n][m][1] = 2
        ok
        gameover()

func gameover()
        for p = 1 to size-1
             for n = 1 to size-p
                  for m = 1 to size-p
                       bool1 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n+p][m][1] = 1)
                       bool2 = (buttonsum1[n][m+p][1] = 1) and (buttonsum1[n+p][m+p][1] = 1)
                       bool3 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n+p][m][1] = 2)
                       bool4 = (buttonsum2[n][m+p][1] = 2) and (buttonsum2[n+p][m+p][1] = 2)
                       if bool1 and bool2
                          button[n][m].setstylesheet(colorviolet)
                          button[n+p][m].setstylesheet(colorviolet)
                          button[n][m+p].setstylesheet(colorviolet)
                          button[n+p][m+p].setstylesheet(colorviolet)
                          msgBox("Player1 won!")
                       ok
                       if bool3 and bool4
                          button[n][m].setstylesheet(colorviolet)
                          button[n+p][m].setstylesheet(colorviolet)
                          button[n][m+p].setstylesheet(colorviolet)
                          button[n+p][m+p].setstylesheet(colorviolet)
                          msgBox("Player2 won!")
                       ok
                  next
             next
        next

func pbegin()
       player1 = 1
       player2 = 0
       for n = 1 to size
            for m = 1 to size
                 button[n][m] { setstylesheet(colorgray)
                                       buttonsum1[n][m][1] = 0
                                       buttonsum2[n][m][1] = 0
                                       button[n][m].setenabled(true)
                                       win.show() }
            next
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
	        setWindowTitle('Memory Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                pbegin() 
        }
