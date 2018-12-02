# Project   : Checkers Game
# Date      : 2018/12/02
# Update    : 2018/12/02
# Author    : Gal Zsolt (~ CalmoSoft ~)
# Email     : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
bwidth = 70 
bheight = 70 
redmove = 1
bluemove = 0
scorered = 0
scoreblack = 0
flagblack = 0
flagnext = 0
flagover = 1
flagjump = false
x = 0
y = 0
xold = 0
yold = 0
xblack1 = 0
xblack2 = 0
yblack1 = 0
yblack2 = 0
xking1 = 0
xking2 =0
yking1 = 0
yking2 = 0
xking3 = 0
xking4 =0
yking3 = 0
yking4 = 0
rowking = 0
colking = 0
total = 0
oPicBlackDisc = new QPixmap("blackdisc.jpg")
oPicRedDisc = new QPixmap("reddisc.jpg")
oPicGreenDisc = new QPixmap("greendisc.jpg")
oPicYellowDisc = new QPixmap("yellowdisc.jpg")
oPicBrownCell = new QPixmap("browncell.jpg")
oPicLightBrownCell = new QPixmap("lightbrowncell.jpg")
oPicNextStep = new QPixmap("nextstep.jpg")
oPicDelBlack = new QPixmap("delblack.jpg")
kingredold = new QPixmap("kingredold.jpg")
kingrednew = new QPixmap("kingrednew.jpg")
blackmove = new QPixmap("blackmove.jpg")

C_Spacing = 1

C_EmptyButtonStyle  = 'border-radius: 1px; background-color: gray; border-style: 
                                  outset; border-width 16px; border-color: white; '
C_ButtonRedStyle   = 'border-radius:6px;color:black; background-color: red'
C_ButtonBlueStyle   = 'border-radius:6px;color:black; background-color: blue'
C_ButtonBlackStyle   = 'border-radius:6px;color:black; background-color: black'
C_ButtonOrangeStyle = 'border-radius:6px;color:black; background-color: orange'

Button = newlist(size,size)
cellsok = newlist(size,size)
Cells = newlist(size,size)
CellsKing = newlist(size,size)
no = "0"
red = "red"
black = "black"
green = "green"
yellow = "yellow"
nextstep = "next"
brown = "brown"
delblack = "delblack"
kingred = "kingred"
lastblack = "lastblack"
LayoutButtonRow = list(size)

for n = 1 to size
     for m = 1 to size
          cellsok[n][m] = 0
     next
next

app = new qApp 
{
	win = new qWidget() {
		setWindowTitle('Checkers Game')
		move(500,150)
		reSize(500,600)
		winheight = win.height()
		fontSize = 8 + (winheight / 100)

		RedScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Red Score: 0")
						}

		BlackScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
                                                        setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
							setstylesheet(C_ButtonOrangestyle)
							settext("Black Score: 0")
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
                                                if (Col%2 = 1 and Row%2 = 1) or (Col%2 = 0 and Row%2 = 0)
                                                   setButtonImage(Button[Row][Col],oPicLightBrownCell,bwidth,bheight)
                                                else
                                                   setButtonImage(Button[Row][Col],oPicBrownCell,bwidth,bheight)
                                                ok
                                                if (Col%2 = 0 and Row%2 = 1) and Row < 4
                                                   Cells[Row][Col] = black
                                                   setButtonImage(Button[Row][Col],oPicBlackDisc,bwidth,bheight)
                                                ok
                                                if Col%2 = 1 and Row = 2
                                                   Cells[Row][Col] = black
                                                   setButtonImage(Button[Row][Col],oPicBlackDisc,bwidth,bheight)
                                                ok
                                               if Col%2 = 1 and Row = 6 
                                                   cellsok[Row][Col] = 1
                                                   setButtonImage(Button[Row][Col],oPicNextStep,bwidth,bheight)
                                                ok
                                                if Col%2 = 0 and Row = 7
                                                   Cells[Row][Col] = red
                                                   setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
                                                ok
                                                if Col%2 = 1 and Row = 8
                                                   Cells[Row][Col] = red
                                                   setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
                                                ok
                                                setclickevent("pmovered(" + string(Row) + "," + string(Col) + ")")		
						setSizePolicy(1,1)                                                
					}
					
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
			next

                                LayoutDataRow1 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
				LayoutDataRow2 = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

				LayoutDataRow1.AddWidget(RedScore)
				LayoutDataRow1.AddWidget(BlackScore) 
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
       redmove = 1
       bluemove = 0
       scorered = 0
       scoreblack = 0
       total = 0
       flagblack = 0
       flagnext = 0  
       flagover = 1  
       flagjump = false
       xblack1 = 0
       xblack2 = 0
       yblack1 = 0
       yblack2 = 0
       xking1 = 0
       xking2 =0
       yking1 = 0
       yking2 = 0
       xking3 = 0
       xking4 =0
       yking3 = 0
       yking4 = 0
       cellsok = newlist(size,size)
       Cells = newlist(size,size)
       for n = 1 to size
            for m = 1 to size
                 cellsok[n][m] = 1
                 CellsKing[n][m] = 0    
            next
       next
       for Col = 1 to size
            for Row = 1 to size
                 if (Col%2 = 1 and Row%2 = 1) or (Col%2 = 0 and Row%2 = 0)
                     setButtonImage(Button[Row][Col],oPicLightBrownCell,bwidth,bheight)
                 else
                     setButtonImage(Button[Row][Col],oPicBrownCell,bwidth,bheight)
                 ok
                 if (Col%2 = 0 and Row%2 = 1) and Row < 4
                     Cells[Row][Col] = black
                     setButtonImage(Button[Row][Col],oPicBlackDisc,bwidth,bheight)
                 ok
                 if Col%2 = 1 and Row = 2
                    Cells[Row][Col] = black
                    setButtonImage(Button[Row][Col],oPicBlackDisc,bwidth,bheight)
                 ok
                 if Col%2 = 1 and Row = 6
                    cellsok[Row][Col] = 1
                    Cells[Row][Col] = nextstep  
                    setButtonImage(Button[Row][Col],oPicNextStep,bwidth,bheight)
                 ok
                 if Col%2 = 0 and Row = 7
                    Cells[Row][Col] = nextstep
                    setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
                 ok
                 if Col%2 = 1 and Row = 8
                    Cells[Row][Col] = nextstep
                    setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
                 ok
            next
       next
       redcells = newlist(size,size)
       RedScore.settext("Red Score: 0")
       BlackScore.settext("Black Score: 0")
       NextPlayer.settext("Next Player: Red")

func pdeleteblacK()
       for n = 1 to size
            for m = 1 to size
                 if n < size-1  and m > 2 and Cells[n][m] = red and Cells[n+1][m-1] = black 
                    setButtonImage(Button[n+2][m-2],oPicRedDisc,bwidth,bheight)
                 ok
            next
       next

func pjumpblack()
       xblack1 = 0
       yblack1 = 0
       xblack2 = 0
       yblack2 = 0
       flagjump = false
       for n = 1 to size
            for m = 1 to size
                 if Cells[n][m] = delblack
                    xblack1 = n
                    yblack1 = m
                    flagjump = true
                    setButtonImage(Button[n][m],oPicGreenDisc,bwidth,bheight)
                    exit 2          
                 ok
            next
       next
       for n = 1 to size
            for m = 1 to size
                 if Cells[n][m] = delblack and flagjump = true and n != xblack1 and m != yblack1
                    xblack2 = n
                    yblack2 = m
                    flagjump = true
                    setButtonImage(Button[n][m],oPicGreenDisc,bwidth,bheight)
                    exit 2          
                 ok
            next
       next

func pjumpred()
       flagjump = false
       for n = 1 to size
            for m = 1 to size
                 if n < size-2 and m > 2 and Cells[n][m] = black and (Cells[n+1][m-1] = red or
                    Cells[n+1][m-1] = nextstep) and Cells[n+2][m-2] = no
                    Cells[n][m] = no
                    Cells[n+1][m-1] = no
                    Cells[n+2][m-2] = black
                    setButtonImage(Button[n][m],oPicBrownCell,bwidth,bheight)
                    setButtonImage(Button[n+1][m-1],oPicBrownCell,bwidth,bheight)
                    setButtonImage(Button[n+2][m-2],oPicBlackDisc,bwidth,bheight)
                    flagjump = true
                    exit 2          
                 ok
            next
       next

       for n = 1 to size
            for m = 1 to size
                 if n < size-2 and m < size-2 and flagjump = false and Cells[n][m] = black and
                    (Cells[n+1][m+1] = red or Cells[n+1][m+1] = nextstep) and Cells[n+2][m+2] = no
                    Cells[n][m] = no
                    Cells[n+1][m+1] = no
                    Cells[n+2][m+2] = black
                    setButtonImage(Button[n][m],oPicBrownCell,bwidth,bheight)
                    setButtonImage(Button[n+1][m+1],oPicBrownCell,bwidth,bheight)
                    setButtonImage(Button[n+2][m+2],oPicBlackDisc,bwidth,bheight)
                    flagjump = true
                    exit 2          
                 ok
            next
       next

func pmovered(Row,Col)
       gameover()
       if Row = xking1 and Col = yking1
          pchangekingred(Row,Col)
          pdeletegreen()
       ok
       if Row = xking2 and Col = yking2
          pchangekingred(Row,Col)
          pdeletegreen()
       ok

       if Row = xking3 and Col = yking3
          pchangekingred(Row,Col)
          pdeletegreen()
       ok
       if Row = xking4 and Col = yking4
          pchangekingred(Row,Col)
          pdeletegreen()
       ok

       if Cells[Row][Col] = kingred
          pmovekingred(Row,Col)
       ok
       pjumpblack()
       if flagjump = true and not ((Row = xblack1 and Col = yblack1) or (Row = xblack2 and Col = yblack2))
          see "You must jump black disc" + nl
          return
       ok
      if Row = 1 and Col > 1 and Cells[1][Col] = green and Cells[2][Col+1] = nextstep
          setButtonImage(Button[1][Col],kingredold,bwidth,bheight) 
          app.processevents()
          sleep(1)
          Cells[1][Col] = kingred
          Cells[2][Col+1] = no
          setButtonImage(Button[1][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[2][Col+1],oPicBrownCell,bwidth,bheight)
          pdeletegreen()
          return
       ok
       if Row = 1 and Col < size-1 and Cells[1][Col] = green and Cells[2][Col-1] = nextstep
          setButtonImage(Button[1][Col],kingredold,bwidth,bheight) 
          app.processevents()
          sleep(1)
          Cells[1][Col] = kingred
          Cells[2][Col-1] = no
          setButtonImage(Button[1][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[2][Col-1],oPicBrownCell,bwidth,bheight)
          pdeletegreen()
          return
       ok
       if Row > 2 and Col > 2 and (Cells[Row][Col] = red or Cells[Row][Col] = nextstep) and 
          Cells[Row-1][Col-1] = black and Cells[Row-2][Col-2] = no
          Cells[Row-2][Col-2] = delblack
       ok
       if Row > 2
          if Row < size and Col < size - 2 and (Cells[Row][Col] = red or Cells[Row][Col] = nextstep) and 
             Cells[Row-1][Col+1] = black and Cells[Row-2][Col+2] = delblack
             Cells[Row-2][Col+2] = delblack
          ok
       ok
       if Row = 6 and Col > 2 and Cells[Row][Col] = delblack and 
          Cells[7][Col-1] = black and (Cells[8][Col-2] = red or Cells[8][Col-2] = nextstep)
          Cells[6][Col] = red
          Cells[7][Col-1] = no
          Cells[8][Col-2] = no
          cellsok[6][Col] = 1
          cellsok[7][Col-1] = 0
          cellsok[8][Col-2] = 0
          setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
          setButtonImage(Button[7][Col-1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[8][Col-2],oPicBrownCell,bwidth,bheight)
          scorered = scorered + 1
          RedScore.settext("Red Score: " + string(scorered))
          pmoveblack()
          return
       ok
       if Row = 6 and Col < size-2 and Cells[Row][Col] = delblack and 
          Cells[7][Col+1] = black and (Cells[8][Col+2] = red or Cells[8][Col+2] = nextstep)
          Cells[6][Col] = red
          Cells[7][Col+1] = no
          Cells[8][Col+2] = no
          cellsok[6][Col] = 1
          cellsok[7][Col+1] = 0
          cellsok[8][Col+2] = 0
          setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
          setButtonImage(Button[7][Col+1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[8][Col+2],oPicBrownCell,bwidth,bheight)
          scorered = scorered + 1
          RedScore.settext("Red Score: " + string(scorered))
          pmoveblack()
          return
       ok
       if Row < size-2 and Col = 6 and Cells[Row][Col] = delblack and 
          Cells[Row+1][7] = black and (Cells[Row+2][8] = red or Cells[Row+2][8] = nextstep)
          Cells[Row][6] = red
          Cells[Row+1][7] = no
          Cells[Row+2][8] = no
          cellsok[Row][6] = 1
          cellsok[Row+1][7] = 0
          cellsok[Row+2][8] = 0
          setButtonImage(Button[Row][6],oPicRedDisc,bwidth,bheight)
          setButtonImage(Button[Row+1][7],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+2][8],oPicBrownCell,bwidth,bheight)
          scorered = scorered + 1
          RedScore.settext("Red Score: " + string(scorered))
          pmoveblack()
          return
       ok
       if Row < size-2 and Col > 2 and Cells[Row][Col] = delblack and 
          Cells[Row+1][Col-1] = black and (Cells[Row+2][Col-2] = red or Cells[Row+2][Col-2] = nextstep)
          Cells[Row][Col] = red
          Cells[Row+1][Col-1] = no
          Cells[Row+2][Col-2] = no
          cellsok[Row][Col] = 1
          cellsok[Row+1][Col-1] = 0
          cellsok[Row+2][Col-2] = 0
          setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
          setButtonImage(Button[Row+1][Col-1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+2][Col-2],oPicBrownCell,bwidth,bheight)
          scorered = scorered + 1
          RedScore.settext("Red Score: " + string(scorered))
          pstepnext()
          return
       ok
       if Row < size-2 and Col < size-2 and Cells[Row][Col] = delblack and 
          Cells[Row+1][Col+1] = black and (Cells[Row+2][Col+2] = red or Cells[Row+2][Col+2] = nextstep)
          Cells[Row][Col] = red
          Cells[Row+1][Col+1] = no
          Cells[Row+2][Col+2] = no
          cellsok[Row][Col] = 1
          cellsok[Row+1][Col+1] = 0
          cellsok[Row+2][Col+2] = 0
          setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight)
          setButtonImage(Button[Row+1][Col+1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+2][Col+2],oPicBrownCell,bwidth,bheight)
          scorered = scorered + 1
          RedScore.settext("Red Score: " + string(scorered))
          pstepnext()
          return
       ok
       if Col > 1 and cellsok[Row][Col] = 1 and Cells[Row][Col] = nextstep and Cells[Row-1][Col-1] = no 
         xold = Row
         yold = Col
         cellsok[Row-1][Col-1] = 1
         Cells[Row-1][Col-1] = green
         setButtonImage(Button[Row-1][Col-1],oPicGreenDisc,bwidth,bheight)
         setButtonImage(Button[Row][Col],oPicYellowDisc,bwidth,bheight)
      ok
       if Col < size and cellsok[Row][Col] = 1 and Cells[Row][Col] = nextstep  and Cells[Row-1][Col+1] = no
         xold = Row
         yold = Col
         cellsok[Row-1][Col+1] = 1
         Cells[Row-1][Col+1] = green
         setButtonImage(Button[Row-1][Col+1],oPicGreenDisc,bwidth,bheight)
         setButtonImage(Button[Row][Col],oPicYellowDisc,bwidth,bheight)
      ok
      pdeletered()
      if Cells[Row][Col] = green
         Cells[Row][Col] = red
         Cells[xold][yold] = no
         setButtonImage(Button[Row][Col],oPicRedDisc,bwidth,bheight) 
         setButtonImage(Button[xold][yold],oPicBrownCell,bwidth,bheight)
         pdeletegreen() 
         pstepnext()
         pmoveblack()
      ok
      gameover()

func gameover()
       flagover = 1
       for Col = 1 to size
            for Row = 1 to size
                 if Cells[Col][Row] = nextstep
                    flagover = 0
                 ok
            next
        next
        if flagover = 1 and scorered > scoreblack
           msgBox("Red Player Win")
        but flagover = 1 and scorered < scoreblack
            msgBox("Black Player Win")
        but flagover = 1 and scorered = scoreblack
            msgBox("Draw")
        ok       

func pstepnext()
       for n = 1 to size
             for m = 1 to size 
                     if Cells[m][n] = nextstep
                        Cells[m][n] = red
                        setButtonImage(Button[m][n],oPicRedDisc,bwidth,bheight)
                     ok
             next
        next
        for n = 1 to size
             for m = 1 to size 
                  if n > 1 and m > 1
                     if (Cells[m][n] = red or Cells[m][n] = nextstep) and Cells[m-1][n-1] = no
                        Cells[m][n] = nextstep
                        setButtonImage(Button[m][n],oPicNextStep,bwidth,bheight)
                     ok
                     if Cells[m-1][n-1] = black and Cells[m][n] = red
                        setButtonImage(Button[m][n],oPicRedDisc,bwidth,bheight)
                     ok
                  ok
                  if n < size and m > 1
                     if (Cells[m][n] = red or Cells[m][n] = nextstep) and Cells[m-1][n+1] = no
                        Cells[m][n] = nextstep
                        setButtonImage(Button[m][n],oPicNextStep,bwidth,bheight)
                     ok 
                     if Cells[m-1][n+1] = black and Cells[m][n] = red
                        setButtonImage(Button[m][n],oPicRedDisc,bwidth,bheight)
                     ok
                  ok
             next
        next  

 func  pdeletegreen()
       for n = 1 to size
            for m = 1 to size
                 if Cells[m][n] = green or Cells[m][n] = delblack
                    Cells[m][n] = no
                    setButtonImage(Button[m][n],oPicBrownCell,bwidth,bheight)
                 ok
            next
       next

func pdeletered()
       for n = 1 to size
            for m = 1 to size
                 if n > 2 and m > 2 and (Cells[n][m] = red or Cells[n][m] = nextstep) and 
                    Cells[n-1][m-1] = black and Cells[n-2][m-2] = delblack
                    Cells[n-2][m-2] = delblack
                    setButtonImage(Button[n-2][m-2],oPicBrownCell,bwidth,bheight)
                 ok
                 if n > 2 and Col < size - 2 and (Cells[n][m] = red or Cells[n][m] = nextstep) and 
                    Cells[n-1][m+1] = black and Cells[n-2][m+2] = delblack
                    Cells[n-2][m+2] = delblack
                   setButtonImage(Button[n-2][m+2],oPicBrownCell,bwidth,bheight)
                 ok
            next
       next

 func pmoveblack()
       gameover()
       pjumpred()
       /*if flagjump = true
          return
       ok*/
       for n = 1 to size
            for m = 1 to size
                 if Cells[n][m] = lastblack
                    Cells[n][m] = black
                    setButtonImage(Button[n][m],oPicBlackDisc,bwidth,bheight)
                 ok                 
            next
       next
       flagback = 0
       if Row < size - 2 and Col > 2 and Cells[Row][Col] = black and (Cells[Row+1][Col-1] = red or 
          Cells[Row+1][Col-1] = nextstep) and Cells[Row+2][Col-2] = no
          Cells[Row][Col] = no
          Cells[Row+1][Col-1] = no
          Cells[Row+2][Col-2] = lastblack
          cellsok[Row][Col] = 0
          cellsok[Row+1][Col-1] = 0
          cellsok[Row+2][Col-2] = 1
          app.processevents()
          sleep(1)
          setButtonImage(Button[Row][Col],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+1][Col-1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+2][Col-2],blackmove,bwidth,bheight)
          scoreblack = string(scoreblack + 1)
          BlackScore.settext("Red Score: " + scoreblack)
          pstepnext()
          return
       ok
       if Row < size and Col > 2 and Cells[Row][Col] = black and (Cells[Row+1][Col+1] = red or 
          Cells[Row+1][Col+1] = nextstep) and Cells[Row+2][Col+2] = no
          Cells[Row][Col] = no
          Cells[Row+1][Col+1] = no
          Cells[Row+2][Col+2] = lastblack
          cellsok[Row][Col] = 0
          cellsok[Row+1][Col+1] = 0
          cellsok[Row+2][Col+2] = 1
          app.processevents()
          sleep(1)
          setButtonImage(Button[Row][Col],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+1][Col+1],oPicBrownCell,bwidth,bheight)
          setButtonImage(Button[Row+2][Col+2],blackmove,bwidth,bheight)
          scoreblack = string(scoreblack + 1)
          BlackScore.settext("Red Score: " + scoreblack)
          pstepnext()
          return
       ok
       while true
               n = random(size-1)+1
               m = random(size-1)+1
               if n < size and m > 1 and Cells[n+1][m-1] = no and Cells[n][m] = black
                  Cells[n][m] = no
                  Cells[n+1][m-1] = lastblack
                  app.processevents()
                  sleep(1)
                  setButtonImage(Button[n+1][m-1],blackmove,bwidth,bheight)
                  x = n
                  y = m
                  flagblack = 1
                  gameover()
                  exit
               ok
               if n < size and m < size and Cells[n+1][m+1] = no and Cells[n][m] = black
                  Cells[n][m] = no
                  Cells[n+1][m+1] = lastblack
                  app.processevents()
                  sleep(1)
                  setButtonImage(Button[n+1][m+1],blackmove,bwidth,bheight)
                  x = n
                  y = m
                  flagblack = 1
                  gameover()
                  exit
               ok
       end
       if flagblack = 1 and x > 0 and y > 0
          Cells[x][y] = no
          setButtonImage(Button[x][y],oPicBrownCell,bwidth,bheight)
       else
          msgBox("Game Over")
       ok
       for Row = 1 to size
            for Col = 1 to size
                 if Row > 2 and Col > 2 and (Cells[Row][Col] = red or Cells[Row][Col] = red) and 
                    Cells[Row-1][Col-1] = black and Cells[Row-2][Col-2] = no
                    Cells[Row-2][Col-2] = delblack
                    setButtonImage(Button[Row-2][Col-2],oPicDelBlack,bwidth,bheight)
                 ok
                 if Row > 2 and Col < size - 2 and (Cells[Row][Col] = red or Cells[Row][Col] = red) and 
                    Cells[Row-1][Col+1] = black and Cells[Row-2][Col+2] = no
                    Cells[Row-2][Col+2] = delblack
                   setButtonImage(Button[Row-2][Col+2],oPicDelBlack,bwidth,bheight)
                 ok
            next
       next
       gameover()
       pstepnext()

func pmovekingred(Row,Col)
       xking1 = 0
       yking1 = 0
       xking2 = 0
       yking2 = 0
       xking3 = 0
       yking3 = 0
       xking4 = 0
       yking4 = 0
       if Row < size and Col > 1 and Cells[Row][Col] = kingred and 
          (Cells[Row+1][Col-1] = kingred or Cells[Row+1][Col-1] = no)
          xking1 = Row+1
          yking1 = Col-1
          Cells[Row+1][Col-1] = green
          setButtonImage(Button[Row+1][Col-1],oPicGreenDisc,bwidth,bheight)
       ok
       if Row < size and Col < size and Cells[Row][Col] = kingred and
          (Cells[Row+1][Col+1] = kingred or Cells[Row+1][Col+1] = no)
          xking2 = Row+1
          yking2 = Col+1
          Cells[Row+1][Col+1] = green
          setButtonImage(Button[Row+1][Col+1],oPicGreenDisc,bwidth,bheight)
       ok
       if Row > 1 and Col > 1 and Cells[Row][Col] = kingred and
          (Cells[Row-1][Col-1] = kingred or Cells[Row-1][Col-1] = no)
          xking3 = Row-1
          yking3 = Col-1
          Cells[Row-1][Col-1] = green
          setButtonImage(Button[Row-1][Col-1],oPicGreenDisc,bwidth,bheight)
       ok
       if Row > 1 and Col < size and Cells[Row][Col] = kingred and 
          (Cells[Row-1][Col+1] = kingred or Cells[Row-1][Col+1] = no)
          xking4 = Row-1
          yking4 = Col+1
          Cells[Row-1][Col+1] = green
          setButtonImage(Button[Row-1][Col+1],oPicGreenDisc,bwidth,bheight)
       ok

func pchangekingred(Row,Col)
       if Row > 1 and Col < size and Row = xking4 and Col = yking4
          Cells[Row][Col] = kingred
          Cells[Row-1][Col+1] = no
          CellsKing[Row][Col] = 1
          CellsKing[Row-1][Col+1] = 0
          setButtonImage(Button[Row][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[Row-1][Col+1],oPicBrownCell,bwidth,bheight)
       ok
       if Row > 1 and Col > 1 and Row = xking3 and Col= yking3 
          Cells[Row][Col] = kingred
          Cells[Row-1][Col-1] = no
          CellsKing[Row][Col] = 1
          CellsKing[Row-1][Col-1] = 0
          setButtonImage(Button[Row][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[Row-1][Col-1],oPicBrownCell,bwidth,bheight)
       ok
       if Row < size and Col < size and Row = xking2 and Col = yking2
          Cells[Row][Col] = kingred
          Cells[Row+1][Col+1] = no
          CellsKing[Row][Col] = 1
          CellsKing[Row+1][Col+1] = 0
          setButtonImage(Button[Row][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[Row-1][Col-1],oPicBrownCell,bwidth,bheight)
       ok
       if Row < size and Col > 1 and Row = xking1 and Col= yking1 
          Cells[Row][Col] = kingred
          Cells[Row+1][Col-1] = no
          CellsKing[Row][Col] = 1
          CellsKing[Row+1][Col-1] = 0
          setButtonImage(Button[Row][Col],kingrednew,bwidth,bheight)
          setButtonImage(Button[Row-1][Col+1],oPicBrownCell,bwidth,bheight)
       ok

func pnext()
       for n = 1 to size
            for m = 1 to size
                 if n > 1 and m > 1 and Cells[n-1][m-1] = no and Cells[n][m] = red
                    Cells[n][m] = no
                    Cells[n-1][m-1] = nextstep
                    setButtonImage(Button[n-1][m-1],oPicRedDisc,bwidth,bheight)
                 ok
                 if n < size and m > 1 and Cells[n+1][m-1] = no and Cells[n][m] = red
                    Cells[n][m] = no
                    Cells[n+1][m-1] = nextstep
                    setButtonImage(Button[n+1][m-1],oPicRedDisc,bwidth,bheight)
                  ok
            next
       next

func pstart()
       for n = 1 to size
            for m = 1 to size
                 if Cells[n][m] = red and n > 1 and m < size
                    if cellsok[n-1][m+1] = 0 and Cells[n-1][m+1] = no
                       cellsok[n][m] = 1
                       Cells[n-1][m+1] = nextstep 
                       setButtonImage(Button[n-1][m+1],oPicNextStep,bwidth,bheight)
                     else
                       Cells[n-1][m+1] = brown 
                     ok
                 ok
            next
       next

Func msgBox(cText) 
	mb = new qMessageBox(win) 
		{
	        setWindowTitle('Checkers Game')
	        setText(cText )
                setstandardButtons(QMessageBox_Discard | QMessageBox_OK) 
                result = exec()	
        }
        return

func pExit()
	win.close()
	app.quit()	

func setButtonImage(oBtn,oPixmap,bwidth,bheight)
       oBtn { setIcon(new qicon(oPixmap.scaled(bwidth,bheight,0,0)))
                 setIconSize(new QSize(bwidth,bheight)) }
