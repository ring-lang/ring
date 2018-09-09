# Project : Tessera Game
# Date    : 2018/09/09
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 7
player1 = 1
player2 = 0
C_ROWCOUNT = 7
C_COLCOUNT = 7
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:blue'
C_BUTTONREDSTYLE = 'border-radius:17px;color:black; background-color: red'
C_BUTTONYELLOWSTYLE = 'border-radius:17px;color:black; background-color: yellow'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
button = newlist(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT)
buttonsum1 = dimlist([size,size,1])
buttonsum2 = dimlist([size,size,1])

app = new qApp {
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('Tessera Game')
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

func pplay(m,n)
        for x = size to 1 step -1
             bool =  (buttonsum1[n][x][1] != 1) and (buttonsum2[n][x][1] != 2)
             if bool = 1
                row = x
                exit
             ok
        next             
        if player1 = 1 
           button[row][n] {setstylesheet(C_BUTTONREDSTYLE)
                                player1 = 0
                                player2 = 1
                                setenabled(false)}
                                buttonsum1[n][row][1] = 1
        else
           button[row][n] {setstylesheet(C_BUTTONYELLOWSTYLE)
                                player1 = 1
                                player2 = 0
                                setenabled(false)}
                                buttonsum2[n][row][1] = 2
        ok
        gameover()

func gameover()
        buttonsum = 0
              for n = 1 to size-3
                  for m = 1 to size-3
                       bool1 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n+1][m][1] = 1)
                       bool2 = (buttonsum1[n+2][m][1] = 1) and (buttonsum1[n+3][m][1] = 1)
                       bool3 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n][m+1][1] = 1)
                       bool4 = (buttonsum1[n][m+2][1] = 1) and (buttonsum1[n][m+3][1] = 1)
                       bool5 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n+1][m+1][1] = 1)
                       bool6 = (buttonsum1[n+2][m+2][1] = 1) and (buttonsum1[n+3][m+3][1] = 1)
                       bool7 = (buttonsum1[n+3][m][1] = 1) and (buttonsum1[n+2][m+1][1] = 1)
                       bool8 = (buttonsum1[n+1][m+2][1] = 1) and (buttonsum1[n][m+3][1] = 1)
                       bool9 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n+1][m][1] = 2)
                       bool10 = (buttonsum2[n+2][m][1] = 2) and (buttonsum2[n+3][m][1] = 2)
                       bool11 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n][m+1][1] = 2)
                       bool12 = (buttonsum2[n][m+2][1] = 2) and (buttonsum2[n][m+3][1] = 2)
                       bool13 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n+1][m+1][1] = 2)
                       bool14 = (buttonsum2[n+2][m+2][1] = 2) and (buttonsum2[n+3][m+3][1] = 2)
                       bool15 = (buttonsum2[n+3][m][1] = 2) and (buttonsum2[n+2][m+1][1] = 2)
                       bool16 = (buttonsum2[n+1][m+2][1] = 2) and (buttonsum2[n][m+3][1] = 2)
                       if bool1 and bool2
                           button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+1][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+2][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+3][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           msgBox("Player1 won!")
                       ok
                       if bool3 and bool4
                          button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player1 won!")
                       ok
                       if bool5 and bool6
                          button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+1][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+2][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+3][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player1 won!")
                       ok
                       if bool7 and bool8
                          button[n+3][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+2][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+1][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player1 won!")
                       ok
                       if bool9 and bool10
                           button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+1][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+2][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           button[n+3][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                           msgBox("Player2 won!")
                       ok
                       if bool11 and bool12
                          button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player2 won!")
                       ok
                       if bool13 and bool14
                          button[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+1][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+2][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+3][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player2 won!")
                       ok
                       if bool15 and bool16
                          button[n+3][m].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+2][m+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n+1][m+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                          button[n][m+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                          msgBox("Player2 won!")
                       ok
                  next
             next
             for n = 1 to size
                  for m = 1 to size
                       bool = (buttonsum1[n][m][1] = 1) or (buttonsum2[n][m][1] = 2)
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
