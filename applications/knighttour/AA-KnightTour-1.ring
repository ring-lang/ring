## Program:	 Knight Tour 
### Author:	 Bert Mariani, Gal Zsolt ~ CalmoSoft ~
### Date:	 2018-10-14

load "stdlib.ring"
load "guilib.ring"	

###-------------------
### WINDOW SIZE

moveX  = 200 moveY	= 100		### Open Window on Screen Position
sizeX  = 800 sizeY	= 820		### Size of Window

hSize	= 8 +2 +2  	### Size of array, Display -4 smaller
vSize	= 8 +2 +2	### Size of array, Display -4 smaller

h	= 0	### H-coord of Cell
v	= 0	### V-coord of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray			= null
aButton			= null
workWidget		= null
ManualGame		= null
TitleKnightMoves	= null
TitleKnightInvalidMove	= null
LayoutButtonRow		= null
 
Knight	  = "Knight.png"
oKnight	  = new QPixmap(Knight)
bWidth	  = oKnight.width()	  ### 50 
bHeight	  = oKnight.height()	  ### 50
nMoves	  = 0 

oldH = 0
oldV = 0
 
C_Spacing  = 2
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'+
			  'border-style: outset;border-width: 2px; border-radius: 2px; border-color: gray;'
C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); border-style: outset;'+
			  'border-width: 2px; border-radius: 2px; border-color: darkGray; '

###=============================================================================
###=============================================================================
### The shortest app function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp 
{
	DrawWidget()
	exec()
}
	
###---------------------


###=================================================
###=================================================

### FUNCTIONS 

###---------------------------------------------------------------------------
### Layout the Grid Square, Create the Arrays
### workWidget items need to be made Global. Mke available toother functions

Func DrawWidget()
	 
	### Global definition for workWidget

	workWidget = new qWidget()				
	{
		# Set the Window Icon
			setWindowIcon(new qIcon(new qPixmap(KNIGHT)))

		aArray	= newList(hSize, vSize)	### Internal Array with Letters
		aButton = newList(hSize, vSize)	### Internal Array with Letters
		
		setWindowTitle('Knight Tour')
		setStyleSheet('background-color:White')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Moves Count
			
			TitleKnightMsg = new qLabel(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
				setText("	Moves:	 ")
			}
			
			TitleKnightMoves = new qLineEdit(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" "+ nMoves)
			}	

			TitleKnightInvalidMove = new qLineEdit(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText("Msg:					 ")
			}	
			
			ManualGame = new qcheckbox(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setText(" Manual Game: ")
			}			
			
			NewGame	 = new QPushButton(workWidget) 
				{
				setFont(new qFont("Calibri",fontsize,100,0))
				setText(" New Game ")
				setClickEvent("NewGameStart()")	  
			}				

		###------------------------------------------------

		###-----------------------------------------------------------------------
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
				
			LayoutTitleRow.AddWidget(ManualGame)
			LayoutTitleRow.AddWidget(TitleKnightMsg)	
			LayoutTitleRow.AddWidget(TitleKnightMoves)
			LayoutTitleRow.AddWidget(TitleKnightInvalidMove)
			
			LayoutTitleRow.AddWidget(NewGame)		

		### Layout - Add  TITLE-ROW on TOP	
								
			LayoutButtonMain.AddLayout(LayoutTitleRow)		
			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(hSize)	
		
		###---------------------------------------------------------------------
		### QHBoxLayout lays out widgets in a horizontal row, from left to right		
		
		odd = 1
		for Row = 3 to hSize -2
					
			LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
			{
				setSpacing(C_Spacing)
				setContentsmargins(0,0,0,0)
			}
		   
		   
		   for Col = 3 to vSize -2
		   
				### Create Buttons
					aButton[Row][Col] = new QPushButton(workWidget)		
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
					}
					
				### Widget - Add HORZ BOTTON
					LayoutButtonRow[Row].AddWidget(aButton[Row][Col])	
		   next
		   odd++

		   ### Layout - Add ROW of BUTTONS			   
		   	LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
		next
		
		###-------------------------------------------------
			
			
		setLayout(LayoutButtonMain)
		
		for h = 1 to hSize
			for v = 1 to vSize
				### e - empty Visible Squares  3--10
					aArray[h][v] = 'e'							
				if h < 3 OR h > 10 or V < 3 or V > 10
					### "." - dot InVisible Squares	 1-2,  3--10,  11-12
						aArray[h][v] = '.'			
				ok
			next
		next
		show()
	}

	NewLocation(3,3)

return

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart()

	workWidget.Close()

	hSize = 8 + 2 + 2	
	vSize = 8 + 2 + 2 
	oldH = 0
	oldV = 0

	nMoves = 0
	TitleKnightMoves.setText(""+ nMoves)

	for h = 1 to hSize
		for v = 1 to vSize
			aArray[h][v] = 'e'	### e - empty
		next
	next
		
	DrawWidget()
	
return


###-----------------------------------------------
### START GAME !!!
### Get User - Cell Clicked - Horz-Vert

Func UserLeftClick(Row, Col)	

	h = 0+ Row		### convert to number
	v = 0+ Col

	Play(h,v)
	
return

###-----------------------------------------
### PLAYED MOVE		 

Func Play(h,v)

	###---------------------------
	### Clear Square -- Old Move
	
	if oldH != 0			### oldH = 0 , oldV = 0 Before Start, No move played
	
		MoveGood = ValidMove(oldH, oldV, h, v)
		if MoveGood = 0
			return			### Move BAD - not valid
		ok
		

		aButton[oldh][oldv] { 
			nImageWidth  = Width() - 70
			nImageHeight = Height() - 70	
			oMine = new qpixmap2(0,0)
			setIcon(new qIcon(oMine))
			setStylesheet("background-color:rgb(0,255,100);")
		}	

	ok

	newLocation(h,v)

	nMoves++			
	TitleKnightMoves.setText("" + nMoves)

###------------------------------------------
### Move the Knight to a new location

Func NewLocation(h,v)
	aButton[h][v] { 
		nImageWidth  = Width()	-24
		nImageHeight = Height() -24		
		oMine = new qpixmap(Knight)
		oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
		setIcon(new qIcon(oMine))
		setIconSize(new qSize(nImageWidth, nImageHeight))
	}			
	oldH = h
	oldV = v
		
return

###------------------------------------------
### ValidMove are L shaped in 8 directions

Func ValidMove( oldH, oldV, h, v)

	### ClockWise-LD	  LU  -- UL	   UR -- RU	   RD --- RU	  DL	  
	PosMove	 = [[-2,-1],[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2]] 
	
	FlagValidMove = 0
	TitleKnightInvalidMove.setText("Msg:  Invalid Move ")
	
	for i = 1 to 8
		if h = oldH + PosMove[i][1] AND	 v = oldV + PosMove[i][2]
			FlagValidMove = 1
			TitleKnightInvalidMove.setText("Msg:			   ")
			exit
		ok
	next
	
return FlagValidMove


###------------------------------------------
### Message Box - Lost or Won

Func MsgBox(Msg)

	mb = new qMessageBox(workWidget) 
	{
		setFont(new qFont("Courier",12,50,0))
		setWindowTitle('Knight Tour')
		setStyleSheet(C_ButtonYellowStyle)
		setText(Msg)
		setstandardbuttons(QMessageBox_OK) 
		result = exec()	### Needed to show Popup window
	}

###-------------------------------------
