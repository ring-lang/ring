## Program:	 MineSweeper - Button Screen
### Author:	 Bert Mariani, Gal Zsolt ~ CalmoSoft ~
### Date:	 2018-09-18
###
### TAB set to 3 Spaces
### aArray Letters: "."-Edge, e-empty, E-EmptyVisited, C-Chosen, M-Mine, B-Boom

load "stdlib.ring"
load "guilib.ring"	

###-------------------
### WINDOW SIZE

moveX  = 200 moveY	= 100		### Open Window on Screen Position
sizeX  = 800 sizeY	= 850		### Size of Window

hSize	= 8 +2	  ### Size of array, Display -2 smaller
vSize	= 8 +2	  ### Size of array, Display -2 smaller

h		= 0		 ### H-coord of Cell
v		= 0		 ### V-coord of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray			= null
aButton			= null
workWidget		= null
TitleKnightMoves = null
LayoutButtonRow	 = null
 

Knight	  = "Knight.jpg"
oKnight	  =	 new QPixmap(Knight)
bWidth	  =	 oKnight.width()	  ### 50 
bHeight	  =	 oKnight.height()	  ### 50
nMoves	  =	 0 
 
C_Spacing  = 2
C_ButtonGrayStyle		= 'border-radius:1px; color:black; background-color: darkGray ; border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray; '
C_ButtonDarkGrayStyle	= 'border-radius:1px; color:black; background-color: Gray;		border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '


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
	 
	workWidget = new qWidget()				### Global definition for workWidget
	{
	
		aArray	= newList(hSize, vSize)	### Internal Array with Letters
		aButton = newList(hSize, vSize)	### Internal Array with Letters
		
		setWindowTitle('Knight Tour')
		setStyleSheet('background-color:gray')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		  move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Mines, Score, Time
			
				TitleKnightMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("	Moves:	 ")
				}
				
				TitleKnightMoves = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment( Qt_AlignVCenter)
					setAlignment( Qt_AlignVCenter)setStyleSheet("background-color:white")
					setText(""+ nMoves)
				}				
	


				
		###------------------------------------------------

		###-----------------------------------------------------------------------
		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		LayoutButtonMain = new QVBoxLayout()				### Vertical
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)
		

			LayoutTitleRow = new QHBoxLayout()				### Horizontal - TOP ROW
			{
				setSpacing(C_Spacing)
				setContentsMargins(0,0,0,0)
			}
				
				LayoutTitleRow.AddWidget(TitleKnightMsg)	
				LayoutTitleRow.AddWidget(TitleKnightMoves)		
										
			LayoutButtonMain.AddLayout(LayoutTitleRow)		### Layout - Add  TITLE-ROW on TOP
			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(hSize)	
		
			###---------------------------------------------------------------------
			### QHBoxLayout lays out widgets in a horizontal row, from left to right		
			
			for Row = 2 to hSize -1
						
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing)
					setContentsmargins(0,0,0,0)
				}
			   
			   for Col = 2 to vSize -1
			   
					aButton[Row][Col] = new QPushButton(workWidget)		### Create Buttons
					{
						setStyleSheet(C_ButtonGrayStyle)			
						setClickEvent("UserLeftClick(" + string(Row) + "," + string(Col) + ")")	### CLICK ===>>>>>>>>
						setSizePolicy(1,1)									
					}
					
					LayoutButtonRow[Row].AddWidget(aButton[Row][Col])	### Widget - Add HORZ BOTTON
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			### Layout - Add ROW of BUTTONS
			next
			
			###-------------------------------------------------
			
			
		setLayout(LayoutButtonMain)
		NewGameStart()
		
		show()
	}

return

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart()
#See "NewGameStart: "+ nl

	workWidget.Close()

		hSize = 8 + 2	
		vSize = 8 + 2

		nMoves = 0
		TitleKnightMoves.setText(""+ nMoves)

		for h = 1 to hSize
			for v = 1 to vSize
				aArray[h][v] = 'e'			### e - empty
			next
		next
		
	### DrawWidget()
	
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
	
		if aArray[h][v] = 'e'
		
			nMoves++			
			aButton[h][v] { 
					setStyleSheet(C_ButtonDarkGrayStyle) 
					setText(""+nMoves)
					nImageWidth	 = Width()	-24
					nImageHeight = Height() -8		
					oMine = new qpixmap(Knight)
					oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
					setIcon(new qIcon(oMine))
					setIconSize(new qSize(nImageWidth, nImageHeight))
				}			
			
			TitleKnightMoves.setText(""+ nMoves)	### Random generates ovlapping Mines
		ok
		
return

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





