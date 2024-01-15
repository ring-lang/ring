# Project : Dots and Boxes Game
# Date    : 2018/11/02
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 9
score = 0
redmove = 1
bluemove = 0
scorered = 0
scoreblue = 0
total = 0

C_Spacing = 1

C_EmptyButtonStyle  = 'border-radius: 1px; background-color: gray; border-style: outset; border-width 16px; border-color: white; '
C_ButtonRedStyle   = 'border-radius:6px;color:black; background-color: red'
C_ButtonBlueStyle   = 'border-radius:6px;color:black; background-color: blue'
C_ButtonBlackStyle   = 'border-radius:6px;color:black; background-color: black'
C_ButtonOrangeStyle = 'border-radius:6px;color:black; background-color: orange'

Button = newlist(size,size)
redcells = newlist(size,size)
bluecells = newlist(size,size)
cellsok = newlist(size,size)
LayoutButtonRow = list(size)

app = new qApp 
{
	win = new qWidget() {
		setWinIcon(self,"dot.png")
		setWindowTitle('Dots and Boxes Game')
		move(500,100)
		reSize(600,600)
		winheight = win.height()
		fontSize = 8 + (winheight / 100)

		RedScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Red Score: 0")
						}

		BlueScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Blue Score: 0")
						}

		NextPlayer = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Next Player: Red")
						}

		ExitLabel = new QPushButton(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
							setstylesheet(C_ButtonOrangestyle)
                                                        setClickEvent("pExit()")
							settext("Exit")
						}

		NewGame = new QPushButton(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
							setstylesheet(C_ButtonOrangestyle)
                                                        setClickEvent("pBegin()")
							settext("New Game")
						} 

 		LayoutButtonMain = new QVBoxLayout()			
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsmargins(0,0,0,0)

			for Row = 1 to size
				LayoutButtonRow[Row] = new QHBoxLayout()	
				{
					setSpacing(C_Spacing)
					setContentsmargins(0,0,0,0)
				} 
         		   for Col = 1 to size
					Button[Row][Col] = new QPushButton(win)	
					{
						setStyleSheet(C_ButtonBlueStyle)
                                                setclickevent("pselect(" + string(Row) + "," + string(Col) + ")")		
						setSizePolicy(1,1)                                                
					}
					
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
			next

                                LayoutDataRow1 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
				LayoutDataRow2 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

				LayoutDataRow1.AddWidget(RedScore)
				LayoutDataRow1.AddWidget(BlueScore) 
				LayoutDataRow1.AddWidget(NextPlayer) 		
				LayoutDataRow2.AddWidget(NewGame) 			  
				LayoutDataRow2.AddWidget(ExitLabel) 

  				LayoutButtonMain.AddLayout(LayoutDataRow1)
				LayoutButtonMain.AddLayout(LayoutDataRow2)

            setLayout(LayoutButtonMain)

            pBegin()			
            show()
   }
   exec()
}

func pBegin()
       score = 0
       redmove = 1
       bluemove = 0
       scorered = 0
       scoreblue = 0
       total = 0
       redcells = newlist(size,size)
       bluecells = newlist(size,size)
       for n = 1 to size   
            for m = 1 to size
                 if n%2 = 1 and m%2 = 1
                    Button[n][m].setstylesheet(C_ButtonBlackStyle)
                 else
                    cellsok[n][m]  = 0
                    redcells[n][m] = ""
                    Button[n][m].setstylesheet(C_EmptyButtonStyle)
                 ok
            next
       next
       RedScore.settext("Red Score: 0")
       BlueScore.settext("Blue Score: 0")
       NextPlayer.settext("Next Player: Red")

func pselect(Row,Col)
       bool1 = not (Row%2 = 1 and Col%2 = 1)
       bool2 = not (Row%2 = 0 and Col%2 = 0)
       bool3 = not (redcells[Row][Col] = "red" or bluecells[Row][Col] = "blue")
       if  bool1 and bool2 and bool3
          if redmove = 1
             redmove = 0
             bluemove = 1
             total = total + 1
             redcells[Row][Col] = "red"
             NextPlayer.settext("Next Player: Blue")
             Button[Row][Col].setstylesheet(C_ButtonRedStyle)
             gameover()
          else
             redmove = 1
             bluemove = 0
             total = total + 1
             bluecells[Row][Col] = "blue"
             NextPlayer.settext("Next Player: Red")
             Button[Row][Col].setstylesheet(C_ButtonBlueStyle)
             gameover()
          ok
       ok

func gameover()
       for n = 2 to size step 2  
            for m = 1 to size-2 step 2
                 bool1 = (redcells[m][n] = "red") or (bluecells[m][n] = "blue")
                 bool2 = (redcells[m+1][n-1] = "red") or (bluecells[m+1][n-1] = "blue")
                 bool3 = (redcells[m+1][n+1] = "red") or (bluecells[m+1][n+1] = "blue")
                 bool4 = (redcells[m+2][n] = "red") or (bluecells[m+2][n] = "blue")
                 bool5 = not (cellsok[m][n] = 1 and cellsok[m+1][n-1] = 1 and cellsok[m+1][n+1] = 1 and cellsok[m+2][n] = 1)
                 if bool1 = 1 and bool2 = 1 and bool3 = 1 and bool4 = 1 and bool5 = 1
                    if redmove = 0
                       redmove = 1
                       bluemove = 0
                       scorered = scorered + 1  
                       NextPlayer.settext("Next Player: Red")              
                       RedScore.settext("Red Score: " + string(scorered))
                       Button[m+1][n].setstylesheet(C_ButtonRedStyle)
                       cellsok[m][n] = 1
                       cellsok[m+1][n-1] = 1
                       cellsok[m+1][n+1] = 1 
                       cellsok[m+2][n] = 1
                       loop
                    else
                       redmove = 0
                       bluemove = 1
                       scoreblue = scoreblue + 1  
                       NextPlayer.settext("Next Player: Blue")              
                       BlueScore.settext("Blue Score: " + string(scoreblue))
                       Button[m+1][n].setstylesheet(C_ButtonBlueStyle)
                       cellsok[m][n] = 1
                       cellsok[m+1][n-1] = 1
                       cellsok[m+1][n+1] = 1 
                       cellsok[m+2][n] = 1
                    ok
                 ok
            next
       next
       if total = 40
          if scorered >  scoreblue
             msgbox("Player Red Won")
          but scorered <  scoreblue
             msgbox("Player Blue Won")
          else
             msgbox("Draw")
          ok
        ok

       
Func msgBox(cText) 
	mb = new qMessageBox(win) 
		{
	        setWindowTitle('Dots and Boxes Game')
	        setText(cText )
                setstandardButtons(QMessageBox_Discard | QMessageBox_OK) 
                result = exec()
                if result = QMessageBox_OK
                   pbegin()
                ok			
        }
        return

func pExit()
	win.close()
	app.quit()	
