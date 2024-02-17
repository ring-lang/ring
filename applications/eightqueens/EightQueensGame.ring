# Project : Eight Queens Game 
# Date    : 08/07/2020-17:57:10
# Author  : Gal Zsolt (CalmoSoft)
# Email   : calmosoft@gmail.com

load "stdlibcore.ring"
load "lightguilib.ring"

size = 8
newSize = size
count = 0
sizeBoard = 0
Queens = list(size)
Board = []
badBoard = []

win = null
nMoves = 0
oldx = 0
oldy = 0
bWidth = 0
bHeight = 0

moveX = 550 moveY = 140		### Open Window on Screen Position
sizeX = 800 sizeY = 800		### Size of Window

Button	= null
cmbSize = null
Pink = list(size,size)

Tiles = list(size,size)
TitleMoves = null
LayoutButtonRow = list(size)
LayoutButtonMain = null

WQueen = "images/WQueen.png"
oPic = new QPixmap("images/WQueen.png")
oPicGray = new QPixmap("images/Gray.png")
oPicGreen = new QPixmap("images/Green.png")

nMoves = 0 

wwidth = 0
wheight = 0
WinWidth = 0
WinHeight = 0

C_Spacing  = 2
C_ButtonIconWidth  = 60
C_ButtonIconHeight = 60
C_ButtonMinWidth   = 80
C_ButtonMinHeight  = 80
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'		### Square pale
				###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray;'

C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); '			### Square dark
				###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

C_ButtonPinkStyle	= 'border-radius:1px; color:black; background-color: rgb(255,179,191); '   ### light pink
				###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '


app = new qApp 
{	
	DrawWidget()
        newWindow(size)
        exec()
}
	
### FUNCTIONS 

###============================================================ 

Func DrawWidget()
	 
	### Global definition for win

	win = new qWidget()				
	{
		# Set the Window Icon
		setWindowIcon(new qIcon(new qPixmap(WQueen)))
		win.setminimumwidth(600)
		win.setminimumheight(600)

		Button = list(size, size)	    ### Internal Array with Letters
		
		setWindowTitle('Eight Queens Game')
		setStyleSheet('background-color:White')

		workHeight = win.height()
		fontSize   = 8 + (workHeight / 100)
		
                wwidth = win.width()
                wheight = win.height()
                bwidth = wwidth/size
                bheight = wheight/size	

                myfilter = new qallevents(win)         
                myfilter.setResizeEvent("resizeBoard()")
                installeventfilter(myfilter)

		###----------------------------------------------
		### Title Top Row - Moves Count			
							
			TitleMoves = new qLineEdit(win) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignHCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" Moves: "+ nMoves)
			}

			labelSize = new qLineEdit(win) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignHCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" Size: ")
			}

			cmbSize = new qComboBox(win) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
                                aList = 4:8
                                for x in aList additem(string(x),0) next
                                setcurrentIndex(0)
                                setactivatedEvent("newSize()")
			}

			SolveGame = new QPushButton(win) 
			{
				    setStyleSheet("background-color:rgb(255,204,229)")
				    setFont(new qFont("Calibri",fontsize,100,0))
				    setText(" Solve ")
				    setClickEvent("solveGame()")	  
			}	

			NewGame	 = new QPushButton(win) 
			{
				setStyleSheet("background-color:rgb(255,204,229)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setText(" New ")
				setClickEvent("newGame()")	  
			}

			btnQuit	 = new QPushButton(win) 
			{
				setStyleSheet("background-color:rgb(255,204,229)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setText("Exit")
				setClickEvent("pQuit()")	  
			}

		###------------------------------------------------

		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		### Vertical
		LayoutButtonMain = new QVBoxLayout()				
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)		

		### Horizontal - TOP ROW
			LayoutTitleRow = new QHBoxLayout()				
			{
				setSpacing(C_Spacing)
				setContentsMargins(0,0,0,0)
			}
				
			
			LayoutTitleRow.AddWidget(TitleMoves)
			LayoutTitleRow.AddWidget(labelSize)
			LayoutTitleRow.AddWidget(cmbSize)
			LayoutTitleRow.AddWidget(SolveGame)
			LayoutTitleRow.AddWidget(NewGame)
			LayoutTitleRow.AddWidget(btnQuit)		
								
			LayoutButtonMain.AddLayout(LayoutTitleRow)		
			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(size)	
		
		### QHBoxLayout lays out widgets in a horizontal row, from left to right		
		
		odd = 1
		for Row = 1 to size 
					
			LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
			{
				setSpacing(C_Spacing)
				setContentsmargins(0,0,0,0)
			}	   
		   
			for Col = 1 to size 
		   
				### Create Buttons

					Button[Row][Col] = new QPushButton(win)		
					{
						if odd % 2 = 0
							setStyleSheet(C_ButtonFirstStyle)
							odd++
						else
							setStyleSheet(C_ButtonSecondStyle)
							odd++
						ok
						setClickEvent("UserLeftClick(" + string(Row) +
								 "," + string(Col) + ")")	
						setSizePolicy(1,1)
						resize(bwidth,bheight)	
						setMinimumWidth(C_ButtonMinWidth)
						setMinimumHeight(C_ButtonMinHeight)							
					}
					
				        ### Widget - Add HORIZONTAL BUTTON
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			next
                        if size % 2 = 0
                           odd++
                        ok


		                ### Layout - Add ROW of BUTTONS			   
				LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
		next
		
		###-------------------------------------------------
			
		setLayout(LayoutButtonMain)

		show()
	}

return

###============================================================

func newWindow(newSize)

                for Row = 1 to size
                    for Col = 1 to size
                        Tiles[Row][Col] = 0
                        Button[Row][Col].delete()
                    next
                next

                size = newSize
                nMoves = 0
                TitleMoves.settext(" Moves: 0")

                wwidth = win.width()
                wheight = win.height()
                bwidth = wwidth/size
                bheight = wheight/size

                win.resize(500,500)

                Button = list(size,size)
                Pink = list(size,size)

		LayoutButtonRow = list(size)	
		
		### QHBoxLayout lays out widgets in a horizontal row, from left to right		
		
                odd = 1
		for Row = 1 to size 
					
			LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
			{
				setSpacing(C_Spacing)
				setContentsmargins(0,0,0,0)
			}	   
		   
			for Col = 1 to size 
		   
				### Create Buttons

					Button[Row][Col] = new QPushButton(win)		
					{
						if odd % 2 = 1
							setStyleSheet(C_ButtonFirstStyle)
							odd++
						else  
							setStyleSheet(C_ButtonSecondStyle)
							odd++
						ok
						setClickEvent("UserLeftClick(" + string(Row) +
								 "," + string(Col) + ")")	
						setSizePolicy(1,1)
                                                resize(bwidth,bheight)	
					}
					
				        ### Widget - Add HORIZONTAL BUTTON
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			next
                        if size % 2 = 0
                           odd++
                        ok

		                ### Layout - Add ROW of BUTTONS			   
				LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
		next
		
		###-------------------------------------------------
			
		win.setLayout(LayoutButtonMain)

###============================================================

func newSize()
     nSize = cmbSize.currentText()
     nSize = number(nSize)
     count = 0
     newWindow(nSize)

###============================================================

func solveGame()

     newWindow(size)

     for Row = 1 to size
         for Col = 1 to size
             Tiles[Row][Col] = 0 
         next
     next

     bwidth  = (win.width()  -8 ) / size            // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size            // <<< QT FIX because of Win Title

     odd = 1
     for Row = 1 to size
         for Col = 1 to size
	     if odd % 2 = 1
		setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight)
		odd++
	     else
		setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight)
		odd++
	     ok
         next
         if size % 2 = 0
            odd++
         ok
     next

     Queens = list(20)
     n = size
     count = count + 1
     if count = 1 
        Board = []
        queen(1,n)
     ok

     sizeBoard = len(Board)/size
     num = random(sizeBoard-1) + 1
     see "Solution = " + num + nl

     for n = (num-1)*size+1 to num*size
         x = Board[n][2]
         y = Board[n][1]
         Tiles[x][y]  = 1
         setButtonImage(Button[x][y],oPic,bwidth-8,bheight)

     next

###============================================================
 
func prn(n)

     for i = 1 to n
         for j = 1 to n  
             if Queens[i] = j
                add(Board,[i,j])
             ok
         next
     next

###============================================================

func place(row,column)

     for i = 1 to row-1 
         if Queens[i]=column
            return 0
         else
            if fabs(Queens[i]-column) = fabs(i-row)
               return 0
            ok
         ok
     next 
     return 1

###============================================================
 
func queen(row,n)

     for column = 1 to n
         if place(row,column)  
            Queens[row] = column
            if row = n 
               prn(n)
            else 
               queen(row+1,n)
            ok
         ok
     next

###============================================================     

func newGame

     newWindow(size)
     return

###============================================================ 

func canPlace Row,Col

     badBoard = []
     add(badBoard,[Row,Col])
     bwidth  = (win.width()  -8 ) / size            // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size            // <<< QT FIX because of Win Title
        cp1 = 1
        for n = 1 to size
            if Row < 9
               if n != Col and Tiles[Row][n] = 1
                  cp1 = 0
                  add(badBoard,[Row,n])
                  exit
               ok
            ok
        next

        cp2 = 1
        for n = 1 to size
            if Col < 9
               if n != Row and Tiles[n][Col] = 1
                  cp2 = 0
                  add(badBoard,[n,Col])
                  exit
               ok
            ok
        next

        cp3 = 1
        for x = 1 to size
            if Row + x < size + 1 and Col - x > 0
               if Tiles[Row+x][Col-x] = 1
                  cp3 = 0
                  add(badBoard,[Row+x,Col-x])
                  exit
               ok
            ok
        next

        cp4 = 1
        for x = 1 to size
            if Row - x > 0 and Col + x < size + 1
               if Tiles[Row-x][Col+x] = 1
                  cp4 = 0
                  add(badBoard,[Row-x,Col+x])
                  exit
               ok
            ok
        next

        cp5 = 1
        for x = 1 to size
            if Row + x < size + 1 and Col + x < size + 1
               if Tiles[Row+x][Col+x] = 1
                  cp5 = 0
                  add(badBoard,[Row+x,Col+x])
                  exit
               ok
            ok
        next

        cp6 = 1
        for x = 1 to size
            if Row - x > 0 and Col - x > 0
               if Tiles[Row-x][Col-x] = 1
                  cp6 = 0
                  add(badBoard,[Row-x,Col-x])
                  exit
               ok
            ok
        next

        cp7 = cp1 and cp2 and cp3 and cp4 and cp5 and cp6

        return cp7

###============================================================ 

func resizeBoard

     bwidth  = (win.width() - 8) / size            
     bheight = (win.height() - 32) / size           

     for Row = 1 to size
         for Col = 1 to size
             if Tiles[Row][Col] = 1 
                setButtonImage(Button[Row][Col],oPic,bwidth - 8,bheight - 8)   
             ok
         next
     next

###============================================================

func UserLeftClick Row,Col

     Tiles[Row][Col] = 1

     bWidthHeight()

     bool = (Row = oldx) and (Col = oldy)

     cp8 = canPlace(Row,Col)

     if Pink[Row][Col] = 1
        Pink[Row][Col] = 0
        Tiles[Row][Col] = 0
        if Row % 2 = 1 and Col % 2 = 1
           Button[Row][Col].setStyleSheet(C_ButtonFirstStyle)
           setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight-8)
        ok
        if Row % 2 = 0 and Col % 2 = 0
           Button[Row][Col].setStyleSheet(C_ButtonFirstStyle)
           setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight-8)
        ok
        if Row % 2 = 1 and Col % 2 = 0
           Button[Row][Col].setStyleSheet(C_ButtonSecondStyle)
           setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight-8)
        ok
        if Row % 2 = 0 and Col % 2 = 1
           Button[Row][Col].setStyleSheet(C_ButtonSecondStyle)
           setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight-8)
        ok
        checkBoard()
        return
     ok

     if cp8 = 1 and bool = 0
        setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
        Tiles[Row][Col] = 1
        nMoves = nMoves + 1
        oldx = Row
        oldy = Col
        TitleMoves.settext(" Moves: " + nMoves)
        gameOver()
     ok
     if cp8 = 1 and bool = 1 
        if Row % 2 = 1 and Col % 2 = 1
           setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight-8)
        ok
        if Row % 2 = 0 and Col % 2 = 0
           setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight-8)
        ok
        if Row % 2 = 1 and Col % 2 = 0
           setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight-8)
        ok
        if Row % 2 = 0 and Col % 2 = 1
           setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight-8)
        ok
        Tiles[Row][Col] = 0
     ok

     for Row = 1 to size
         for Col = 1 to size
             if Tiles[Row][Col] = 1
                setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
             ok
         next
     next

     if cp8 = 0
        pBadCell(Row,Col)
        return
     ok

###============================================================

func checkBoard()

     for Row = 1 to size
         for Col = 1 to size
         if Pink[Row][Col] = 1
            cp9 = canPlace(Row,Col)
            if cp9 = 0
               Button[Row][Col].setStyleSheet(C_ButtonPinkStyle)
               setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight)
            else
               if Row % 2 = 1 and Col % 2 = 1
                  Button[Row][Col].setStyleSheet(C_ButtonFirstStyle)
                  setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
               ok
               if Row % 2 = 0 and Col % 2 = 0
                  Button[Row][Col].setStyleSheet(C_ButtonFirstStyle)
                  setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
               ok
               if Row % 2 = 1 and Col % 2 = 0
                  Button[Row][Col].setStyleSheet(C_ButtonSecondStyle)
                  setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
               ok
               if Row % 2 = 0 and Col % 2 = 1
                  Button[Row][Col].setStyleSheet(C_ButtonSecondStyle)
                  setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
               ok
            ok
         ok
         next
     next

###============================================================

func pBadCell(Row,Col)

     for n = 1 to len(badBoard)
         Row = badBoard[n][1]
         Col = badBoard[n][2]
         Pink[Row][Col] = 1
         Button[Row][Col].setStyleSheet(C_ButtonPinkStyle)
         setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight)
     next

###============================================================

func setButtonImage oBtn,oPixmap,width,height
     oBtn { setIcon(new qicon(oPixmap.scaled(width(),height(),0,0)))
	    setIconSize(new QSize(C_ButtonIconWidth,C_ButtonIconHeight))
	  }

###============================================================ 

func bWidthHeight()

     bWidth  = (win.width()  -8 ) / size            
     bHeight = (win.height() -32) / size            

###============================================================

func msgBox cText	  
     mb = new qMessageBox(win) {
	  setWindowTitle('Eight Queens')
	  setText(cText)
          setstandardbuttons(QMessageBox_OK) 
          result = exec() 
     }

###============================================================ 

func pQuit()
     win.close()

###============================================================ 

func gameOver

     total = 0
     for Row = 1 to size
         for Col = 1 to size
             if Tiles[Row][Col] = 1
                total = total + 1
             ok
         next
     next

     if total = size
        for Row = 1 to size
            for Col = 1 to size
                Button[Row][Col].setenabled(false)
            next
        next
        msgBox("You Win!")
     ok

###============================================================ 
