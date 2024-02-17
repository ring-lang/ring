# Project : Tessera Game
# Date    : 2018/09/11
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

size = 7
player1 = 0
player2 = 0
player = 0
playercomp = 0
C_ROWCOUNT = 7
C_COLCOUNT = 7
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:blue'
C_BUTTONREDSTYLE = 'border-radius:17px;color:black; background-color: red'
C_BUTTONYELLOWSTYLE = 'border-radius:17px;color:black; background-color: yellow'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_MENUSTYLE	= "color:white;background-color:rgb(50,50,50);border-radius:17px"
button = list(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT+3)
buttonsum1 = dimlist([size,size,1])
buttonsum2 = dimlist([size,size,1])

app = new QApp {
         StyleFusion()
         win = new QWidget() {
                  setWindowTitle('Tessera Game')
		  setWindowIcon(new QIcon(new qPixmap("thought.png")))
                  move(490,100)
                  resize(600,600)
                  setstylesheet('background-color:white')
                  playcomp = new QPushButton(win)
                  playcomp { setstylesheet(C_MENUSTYLE)
                                   setstylesheet("font-size:30px")   
                                   settext("Play with computer")
                                   setclickevent("pcomputer()")
                                   setSizePolicy(1,1)
                                   show() }
                  playtwo = new QPushButton(win)
                  playtwo { setstylesheet(C_MENUSTYLE)  
                                setstylesheet("font-size:30px") 
                                settext("Two players")
                                setclickevent("ptwo()")
                                setSizePolicy(1,1)
                                show() }
                  playexit = new QPushButton(win)
                  playexit { setstylesheet(C_MENUSTYLE)
                                setstylesheet("font-size:30px")   
                                settext("Exit")
                                setclickevent("pexit()")
                                setSizePolicy(1,1)
                                show() }
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
		  oMainLayout = new qVBoxlayout() {
		                        AddWidget(playcomp)
		                        AddWidget(playtwo)
		                        AddWidget(playexit)
			                }
                  LayoutButtonMain.AddLayout(oMainLayout)
                  setLayout(LayoutButtonMain)
                  show()
	}
	pComputer()
        exec()
}

func compenter()
       row2 = 0
        while row2 = 0
                n2 = random(size-1)+1 
                for x = size to 1 step -1
                     bool =  (buttonsum1[n2][x][1] != 1) and (buttonsum2[n2][x][1] != 2)
                     if bool = 1
                        row2 = x
                        exit 2
                     ok
                next 
        end
        pcolor(n2,row2,C_BUTTONYELLOWSTYLE)
        button[row2][n2] {setstylesheet(C_BUTTONYELLOWSTYLE)
                                playercomp = 0
                                player = 1}
                                buttonsum2[n2][row2][1] = 2
        if row2 = 1 
           for nr = 1 to size
                button[nr][n2].setenabled(false)
           next
        ok
 
func pcolor(n,row,bcolor)
        for x = 1 to row - 1
             app.processevents()
             sleep(0.1) 
             button[x][n].setstylesheet(bcolor)
             app.processevents() 
             sleep(0.1)
             button[x][n].setstylesheet(C_EMPTYBUTTONSTYLE)
        next

func pplay(m,n) 
        if playercomp = 1
           n = random(size-1)+1 
        ok
        for x = size to 1 step -1
             bool =  (buttonsum1[n][x][1] != 1) and (buttonsum2[n][x][1] != 2)
             if bool = 1
                row = x
                exit
             ok    
        next
        if player = 1 or  player1 = 1
           pcolor(n,row,C_BUTTONREDSTYLE)
        ok
        if player2 = 1
           pcolor(n,row,C_BUTTONYELLOWSTYLE)
        ok
        if player = 1            
           button[row][n] {setstylesheet(C_BUTTONREDSTYLE)
                                  player = 0
                                  playercomp = 1}
                                  buttonsum1[n][row][1] = 1
           gameover()
           compenter() 
        ok
        if player1 = 1 
           button[row][n] {setstylesheet(C_BUTTONREDSTYLE)}
                                   buttonsum1[n][row][1] = 1
        ok
        if player2 = 1
           button[row][n] {setstylesheet(C_BUTTONYELLOWSTYLE)}
                                  buttonsum2[n][row][1] = 2
        ok
        if player1 = 1 and player = 0 and playercomp = 0
           player1 = 0
           player2 = 1
        but player1 = 0 and player = 0 and playercomp = 0
           player1 = 1
           player2 = 0
        ok
        if row = 1 
           for nr = 1 to size
                button[nr][n].setenabled(false)
           next
        ok
        gameover()

func gameover()
        buttonsum = 0
        for n = 1 to size-3
             for m = 1 to size
                  bool1 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n+1][m][1] = 1)
                  bool2 = (buttonsum1[n+2][m][1] = 1) and (buttonsum1[n+3][m][1] = 1)
                  bool9 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n+1][m][1] = 2)
                  bool10 = (buttonsum2[n+2][m][1] = 2) and (buttonsum2[n+3][m][1] = 2)
                  if bool1 and bool2
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player1 won!")
                  ok
                  if bool9 and bool10
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player2 won!")
                  ok
             next
        next
        for n = 1 to size
             for m = 1 to size-3
                  bool3 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n][m+1][1] = 1)
                  bool4 = (buttonsum1[n][m+2][1] = 1) and (buttonsum1[n][m+3][1] = 1)
                  bool11 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n][m+1][1] = 2)
                  bool12 = (buttonsum2[n][m+2][1] = 2) and (buttonsum2[n][m+3][1] = 2)
                  if bool3 and bool4
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player1 won!")
                  ok
                  if bool11 and bool12
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player2 won!")
                  ok
             next
        next
        for n = 1 to size-3
             for m = 1 to size-3
                  bool5 = (buttonsum1[n][m][1] = 1) and (buttonsum1[n+1][m+1][1] = 1)
                  bool6 = (buttonsum1[n+2][m+2][1] = 1) and (buttonsum1[n+3][m+3][1] = 1)
                  bool13 = (buttonsum2[n][m][1] = 2) and (buttonsum2[n+1][m+1][1] = 2)
                  bool14 = (buttonsum2[n+2][m+2][1] = 2) and (buttonsum2[n+3][m+3][1] = 2)
                  if bool5 and bool6
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player1 won!")
                  ok
                  if bool13 and bool14
                     button[m][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player2 won!")
                  ok
             next
        next
        for n = 1 to size-3
             for m = 1 to size-3
                  bool7 = (buttonsum1[n+3][m][1] = 1) and (buttonsum1[n+2][m+1][1] = 1)
                  bool8 = (buttonsum1[n+1][m+2][1] = 1) and (buttonsum1[n][m+3][1] = 1)
                  bool15 = (buttonsum2[n+3][m][1] = 2) and (buttonsum2[n+2][m+1][1] = 2)
                  bool16 = (buttonsum2[n+1][m+2][1] = 2) and (buttonsum2[n][m+3][1] = 2)
                  if bool7 and bool8
                     button[m][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n].setstylesheet(C_BUTTONVIOLETSTYLE)
                     msgBox("Player1 won!")
                  ok
                  if bool15 and bool16
                     button[m][n+3].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+1][n+2].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+2][n+1].setstylesheet(C_BUTTONVIOLETSTYLE)
                     button[m+3][n].setstylesheet(C_BUTTONVIOLETSTYLE)
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
       buttonsum1 = dimlist([size,size,1])
       buttonsum2 = dimlist([size,size,1])
       for n = 1 to size
            for m = 1 to size
                 button[n][m] { setstylesheet(C_EMPTYBUTTONSTYLE)
                                       buttonsum1[n][m][1] = 0
                                       buttonsum2[n][m][1] = 0
                                       setenabled(true)
                                       win.show() }
            next
       next

func pcomputer()
       player = 1
       playercomp = 0
       player1 = 0
       player2 = 0
       pbegin()

func ptwo()
       player1 = 1
       player2 = 0
       player = 0
       playercomp = 0
       pbegin()

func pexit()
	win.close()
	app.quit()

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
	        setWindowTitle('Tessera Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                pbegin() 
        }
