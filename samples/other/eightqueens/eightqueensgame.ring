# Project : Eight Queens Game 
# Date    : 26/06/2020-09:48:52
# Author  : Gal Zsolt (CalmoSoft), Nestor Kuka
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "solutions.ring"

rown		= 8
cb		= list(rown)	                        ### cb[i] = cb coordinate of queen in row i (col) 
check		= 0
numBoard	= 0
sizeBoard	= 0

size		= 8
win		= null
nMoves		= 0

moveX 		= 550 		moveY	= 140		### Open Window on Screen Position
sizeX 		= 800 		sizeY	= 800		### Size of Window

Button		= null

Tiles 		= newlist(size,size)
TitleMoves 	= null
LayoutButtonRow = list(size)
LayoutButtonMain= null

WQueen		= "images/WQueen.png"
oPic		= new QPixmap(AppFile("images/WQueen.png"))
oPicGray	= new QPixmap(AppFile("images/Gray.png"))
oPicGreen	= new QPixmap(AppFile("images/Green.png"))

nMoves		= 0 

wwidth		= 0
wheight		= 0
WinWidth	= 0
WinHeight	= 0

C_Spacing		= 2
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'		### Square pale

C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); '			### Square dark

app = new qApp 
{	
	DrawWidget()
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
                win.setminimumwidth(400)
                win.setminimumheight(400)

		Button = newList(size, size)	    ### Internal Array with Letters
		
		setWindowTitle('Eight Queens Game')
		setStyleSheet('background-color:White')

		workHeight = win.height()
		fontSize   = 8 + (workHeight / 100)
		
		move(moveX, moveY)

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

			SolveGame = new QPushButton(win) 
			{
				    setStyleSheet("background-color:rgb(255,204,229)")
				    setFont(new qFont("Calibri",fontsize,100,0))
				    setText(" Solve Game ")
				    setClickEvent("solveGame()")	  
			}	

			NewGame	 = new QPushButton(win) 
			{
				setStyleSheet("background-color:rgb(255,204,229)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setText(" New Game ")
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
						if odd % 2
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
					
				        ### Widget - Add HORZ BOTTON
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			next
			odd++

		                ### Layout - Add ROW of BUTTONS			   
				LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
		next
		
		###-------------------------------------------------
			
		setLayout(LayoutButtonMain)

		show()
	}

return

###============================================================

func solveGame()

     for Row = 1 to size
         for Col = 1 to size
             Tiles[Row][Col] = 0 
         next
     next

     nRow = 1			                   // number of colls in row bei n=6  4 varianten
     rown = 8		 	                   // number of rows
     cb = list(rown)	                           // cb[i] = cb coordinate of queen in row i (col) 

     bwidth  = (win.width()  -8 ) / size           // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size           // <<< QT FIX because of Win Title

     odd = 1
     for Row = 1 to size
         for Col = 1 to size
	     if odd % 2
		setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight)
		odd++
	     else
		setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight)
		odd++
	     ok
         next
         odd++
     next

     sizeBoard = len(Board)
     num = random(sizeBoard-1) + 1
     see "Solution = " + num + nl

     for n = 1 to size
         y = Board[num][n]
         Tiles[n][y]  = 1
         setButtonImage(Button[n][y],oPic,bwidth-8,bheight)
     next

###============================================================     

func newGame
     count = 0
     nMoves = 0
     numBoard = 0
     sizeBoard = 0
     for x = 1 to size
         for y = 1 to size
             Tiles[x][y] = 0
         next
     next

     win.setminimumwidth(400)
     win.setminimumheight(400)

     bwidth  = (win.width()  -8 ) / size            // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size            // <<< QT FIX because of Win Title

     odd = 1
     for Row = 1 to size
         for Col = 1 to size
	     if odd % 2
		setButtonImage(Button[Row][Col],oPicGray,bwidth-8,bheight)
		odd++
	     else
		setButtonImage(Button[Row][Col],oPicGreen,bwidth-8,bheight)
		odd++
	     ok
         next
         odd++
     next

     for Row = 1 to size
         for Col = 1 to size
             Button[Row][Col].setenabled(true)
         next
     next

     TitleMoves.settext(" Moves: 0")

###============================================================ 

func canPlace Row,Col
     bwidth  = (win.width()  -8 ) / size            // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size            // <<< QT FIX because of Win Title
        cp1 = 1
        for n = 1 to size
            if Row < 9
               if n != Col and Tiles[Row][n] = 1
               //if Tiles[Row][n] = 1
                  cp1 = 0
                  exit
               ok
            ok
        next

        cp2 = 1
        for n = 1 to size
            if Col < 9
               if n != Row and Tiles[n][Col] = 1
                  cp2 = 0
                  exit
               ok
            ok
        next

        cp3 = 1
        for x = 1 to size
            if Row + x < size + 1 and Col - x > 0
               if Tiles[Row+x][Col-x] = 1
                  cp3 = 0
                  exit
               ok
            ok
        next

        cp4 = 1
        for x = 1 to size
            if Row - x > 0 and Col + x < size + 1
               if Tiles[Row-x][Col+x] = 1
                  cp4 = 0
                  exit
               ok
            ok
        next

        cp5 = 1
        for x = 1 to size
            if Row + x < size + 1 and Col + x < size + 1
               if Tiles[Row+x][Col+x] = 1
                  cp5 = 0
                  exit
               ok
            ok
        next

        cp6 = 1
        for x = 1 to size
            if Row - x > 0 and Col - x > 0
               if Tiles[Row-x][Col-x] = 1
                  cp6 = 0
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

     bwidth  = (win.width()  -8 ) / size            // <<< QT FIX because of Win Title
     bheight = (win.height() -32) / size            // <<< QT FIX because of Win Title

     cp8 = canPlace(Row,Col)
     if cp8 = 1
        setButtonImage(Button[Row][Col],oPic,bwidth+-8,bheight-8)
        Tiles[Row][Col] = 1
        nMoves = nMoves + 1
        TitleMoves.settext(" Moves: " + nMoves)
        gameOver()
     else
        return
     ok

     for Row = 1 to size
         for Col = 1 to size
             if Tiles[Row][Col] = 1
                setButtonImage(Button[Row][Col],oPic,bwidth-8,bheight-8)
             ok
         next
     next

###============================================================ 

func setButtonImage oBtn,oPixmap,width,height
     oBtn { setIcon(new qicon(oPixmap.scaled(width(),height(),0,0)))
	    setIconSize(new QSize(width,height))
	  }

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
