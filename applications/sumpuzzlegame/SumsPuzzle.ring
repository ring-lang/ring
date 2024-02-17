# Project : Sums Puzzle Game
# Date    : 2018/11/05
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

size = 5
sum = 0
flag = 0
oldrow = 0
oldcol = 0
Rowold = 1
Colold = 1
C_Spacing = 1

C_EmptyButtonStyle  = 'border-radius: 1px; background-Color: gray; border-style: outset; border-width 16px; border-Color: white; '
C_ButtonBlueStyle   = 'border-radius:6px;Color:black; background-Color: blue'
C_ButtonOrangeStyle = 'border-radius:6px;Color:black; background-Color: orange'
C_ButtonVioletStyle = 'border-radius:6px;Color:black; background-Color: violet'

Button = list(size,size)
cellsok = list(size,size)
cellsno = list(size,size)
bestscores = []
LayoutButtonRow = list(size)

app = new qApp 
{
	win = new qWidget() {
		setWinIcon(self,"icon.png")
		setWindowTitle('Sums Puzzle Game')
		move(500,100)
		reSize(100,300)
		winheight = win.height()
		fontSize = 8 + (winheight / 100)
		fontSize2 = 24 + (winheight / 100)

		GameScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Score: 0")
						}

		BestScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Best Score: 0")
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
                                                setFont(new qFont("Verdana",fontSize2,100,0))
						setStyleSheet(C_ButtonBlueStyle)
                                                setclickevent("psum(" + string(Row) + "," + string(Col) + ")")		
						setSizePolicy(1,1)                                                
					}
					
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
			next

                               LayoutDataRow1 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
    			       LayoutDataRow2 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

                               LayoutDataRow1.AddWidget(GameScore)
                               LayoutDataRow1.AddWidget(BestScore)
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

func psum(Row,Col)
       if cellsno[Row][Col] = 1
          return
       ok
       flag = flag + 1
       if flag = 1
          cellsok[Row][Col] = '1'
          cellsno[Row][Col] = 1
          Button[Row][Col].settext('1')
          Button[Row][Col].setstylesheet(C_EmptyButtonStyle)
          oldrow = Row
          oldcol = Col
          return
       ok
       if flag = 2
          if not (oldrow = Row and oldcol = Col)
             cellsok[Row][Col] = '1'
          cellsno[Row][Col] = 1
             Button[Row][Col].settext('1')
             Button[Row][Col].setstylesheet(C_EmptyButtonStyle)
             return
           else
              flag = 1
              return
           ok
       ok
       sum1 = '' sum2 = '' sum3 = '' sum4 = ''
       sum5 = '' sum6 = '' sum7 = '' sum8 = ''
       if Row > 1
          sum1 = cellsok[Row-1][Col]
       ok
       if Row < size
          sum2 = cellsok[Row+1][Col]
       ok
       if Col > 1 
          sum3 = cellsok[Row][Col-1]
       ok
       if Col < size
          sum4 = cellsok[Row][Col+1]
       ok
       if Row > 1 and Col > 1
          sum5 = cellsok[Row-1][Col-1]
       ok
       if Col < size and Row > 1
          sum6 = cellsok[Row-1][Col+1]
       ok
       if Col > 1 and Row < size
          sum7 = cellsok[Row+1][Col-1]
       ok
       if Row< size and Col < size
          sum8 = cellsok[Row+1][Col+1]
       ok
       sum = number(sum1) + number(sum2) + number(sum3) + number(sum4)
       sum = sum + number(sum5) + number(sum6) + number(sum7) + number(sum8)
       if sum != 0
          cellsno[Row][Col] = 1
          cellsok[Row][Col] = string(sum)
          Button[Row][Col].settext(string(sum))
       else
          cellsno[Row][Col] = 1
          cellsok[Row][Col] = '1'
          Button[Row][Col].settext('1')
       ok
       Button[Rowold][Colold].setstylesheet(C_EmptyButtonStyle)
       if flag != 1
          Button[Row][Col].setstylesheet(C_ButtonVioletStyle)
       ok
       Rowold = Row
       Colold = Col
       gameover()

func gameover()
       total = 0
       for n = 1 to size   
            for m = 1 to size
                 if cellsok[n][m] != ''
                    total = total + 1
                 ok
            next
       next
       add(bestscores,sum)
       bestscores = sort(bestscores)
       bestscores = reverse(bestscores)
       if total = size*size
          GameScore.settext('Score: ' + string(sum))
          BestScore.settext('Best Score: ' + string(bestscores[1]))
       ok

func pBegin()
       flag = 0
       oldrow = 0
       oldcol = 0
       for n = 1 to size   
            for m = 1 to size
                 Button[n][m].setstylesheet(C_EmptyButtonStyle)
                 Button[n][m].settext('')
                 cellsok[n][m] = ''
                 cellsno[n][m] = 0
            next
       next
       GameScore.settext('Score: 0')

func cellsbegin()
       for n = 1 to size   
            for m = 1 to size
                 Button[n][m] { temp = text() }
                 cellsok[n][m] = temp
            next
       next

 
Func msgBox(cText) 
	mb = new qMessageBox(win) 
		{
	        setWindowTitle('Sums Puzzle Game')
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
