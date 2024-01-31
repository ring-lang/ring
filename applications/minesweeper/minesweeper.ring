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

hSize	= 10 +2	  ### Size of array, Display -2 smaller
vSize	= 10 +2	  ### Size of array, Display -2 smaller
nMines	= 24	  ### Number of Mines
nScore	= 0		  ### Player Score
nClicks = 0		  ### Clicks played

h		= 0		 ### Horizontal coordinate of Cell
v		= 0		 ### Vertical coordinate of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray			= null
aButton			= null
workWidget		= null
TitleMines		= null
TitleClicks		= null
TitleScore		= null
IgnoreMines		= null
LayoutButtonRow = null
 
questionlist	= list(1)	### Cells in Question - Color them Cyan with RightClick

Mine	  = "Mine.jpg"
oMine	  =	 new QPixmap(Mine)
bWidth	  =	 oMine.width()	  ### 50 
bHeight	  =	 oMine.height()	  ### 50 
 
C_Spacing  = 1
C_Spacing0 = 0
C_Spacing5 = 5

C_ButtonEmptyStyle	= 'border-radius:1px; color:black; background-color: darkGray ; border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray; '
C_ButtonWhiteStyle	= 'border-radius:1px; color:black; background-color: white;		border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '

C_ButtonCyanStyle	= 'border-radius:1px; color:black; background-color: cyan;		border-style: solid;  border-width: 2px; border-radius: 2px; border-color: darkgray; '		  
C_ButtonVioletStyle = 'border-radius:3px; color:black; background-color: violet;	border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '
C_ButtonYellowStyle = 'border-radius:3px; color:black; background-color: Yellow;	border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '


###-----------------------------------------------------------
### Statistics Button Count, Used for nScore, nMines, nClicks
### Also used when Game Over !!!
	ce = 0 cM = 0 cF = 0 cC = 0 c1 = 0 c2 = 0 
	c3 = 0 c4 = 0 c5 = 0 c6 = 0 c7 = 0 c8 = 0 

###---------------------
### Icons for Bombs
UserIcons = CurrentDir() +"/"


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
### workWidget items need to be made Global. Make available to other functions

Func DrawWidget()
#See "DrawWidget: "+ nl
	 
	workWidget = new qWidget()				### Global definition for workWidget
	{
		setWinIcon(self,"Mine.jpg")
		aArray	= newList(hSize, vSize)	### Internal Array with Letters
		aButton = newlist(hSize, vSize)	### Button Array with Display Colors 
	
		PopulateArray()

		setWindowTitle('Game MinesSweeper')
		setStyleSheet('background-color:gray')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		  move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Mines, Score, Time
			
				TitleMinesMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("	Mines:	 ")
				}
				
				TitleMines = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment( Qt_AlignVCenter)
					setAlignment( Qt_AlignVCenter)setStyleSheet("background-color:white")
					setText(""+ nMines)
				}				
	
				TitleClicksMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("	Clicks:	  ")
				}
				
				TitleClicks = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment( Qt_AlignVCenter)
					setAlignment( Qt_AlignVCenter)setStyleSheet("background-color:white")
					setText(""+ nClicks)
				}	

				TitleScoreMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("	Score:	 ")
				}
				
				TitleScore = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment( Qt_AlignVCenter)setStyleSheet("background-color:white")
					setText(""+ nScore)
				}	

				
	  ###------------------------------------------------

		###-----------------------------------------------------------------------
		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		LayoutButtonMain = new QVBoxLayout()				### Vertical
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)
		

			LayoutTitleRow = new QHBoxLayout()				### Horizontal - TOP ROW
			{
				setSpacing(C_Spacing5)
				setContentsMargins(0,0,0,0)
			}
				
			LayoutTitleRow.AddWidget(TitleMinesMsg)	
			LayoutTitleRow.AddWidget(TitleMines)		
			LayoutTitleRow.AddWidget(TitleClicksMsg)
			LayoutTitleRow.AddWidget(TitleClicks)
			LayoutTitleRow.AddWidget(TitleScoreMsg)
			LayoutTitleRow.AddWidget(TitleScore)	
							
			LayoutButtonMain.AddLayout(LayoutTitleRow)	### Layout - Add  TITLE-ROW on TOP
			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(hSize)		  
			for Row = 2 to hSize -1
			
				###-----------------------------------------------------------------------
				### QHBoxLayout lays out widgets in a horizontal row, from left to right
				
				#See "Row: "+ Row +nl
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing0)
					setContentsmargins(0,0,0,0)
				}
			   
			   for Col = 2 to vSize -1
					aButton[Row][Col] = new QPushButton(workWidget)	### Create Buttons
					{
						setStyleSheet(C_ButtonEmptyStyle)			
						setClickEvent("GetUserInput(" + string(Row) + "," + string(Col) + ")")	### CLICK
						setSizePolicy(1,1)
						
							###-------------------------------------------------
							### For Right Mouse Click - does NOT show depression
							myfilter = new qAllEvents(workWidget) 
							{
								setContextMenuEvent( "myMenu(	" + string(Row) + "," + string(Col) + ")  " )  ### CLICK CELL ===>>>>
							}
							installeventfilter(myfilter)						
						
					}
					
					LayoutButtonRow[Row].AddWidget(aButton[Row][Col])	### Widget - Add HORIZONTAL BUTTON
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])		### Layout - Add ROW of BUTTONS
			next

			###-------------------------------------------------
			###-------------------------------------------------
			### Bottom Row

				LayoutDataRow = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing5)
					setContentsMargins(0,0,0,0)
				}
				
				BeginnerGame  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:darkGray")
					setText(" Beginner ")
					setClickEvent("NewGameStart(1)")	  
				}	

				IntermediateGame  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:darkGray")
					setText(" Intermediate ")
					setClickEvent("NewGameStart(2)")	  
				}

				ExpertGame	= new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:darkGray")
					setText(" Expert ")
					setClickEvent("NewGameStart(3)")	  
				}	

				###---------------------------------------------------
				### Continue playing CheckBox - Ignore Mines - Checked			
				IgnoreMines = new qcheckbox(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:darkGray")
					setText(" IgnoreMines: ")
				}

			LayoutDataRow.AddWidget(BeginnerGame)	
			LayoutDataRow.AddWidget(IntermediateGame)
			LayoutDataRow.AddWidget(ExpertGame)
			LayoutDataRow.AddWidget(IgnoreMines)

			LayoutButtonMain.AddLayout(LayoutDataRow)			### Layout - Add BOTTOM ROW
			
			###-------------------------------------------------
			###-------------------------------------------------			
			
		setLayout(LayoutButtonMain)

		show()
	}

return

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart(L)
#See "NewGameStart: "+ nl

	workWidget.Close()

		if	L = 1
				hSize = 12	vSize = 12	nMines	= 24
		but L = 2
				hSize = 22	vSize = 22	nMines	= 96
		but L = 3
				hSize = 32	vSize = 32	nMines	= 216
		ok

		nClicks = 0
		nScore	= 0

		 TitleScore.setText(""+ nScore) 
		TitleClicks.setText(""+ nClicks)
		 TitleMines.setText(""+ nMines)
		
		questionList = list(1)				### Cell in Question - Cyan

	DrawWidget()
	
return


###------------------------------------------------
### Populate Internal Array and Mines

Func PopulateArray()
#See "PopulateArray: "+ nl

	n = 1
	for v = 1 to vSize
		for h = 1 to hSize

			if h = 1 OR v = 1 or h = hSize OR v = vSize 
				aArray[h][v] = '.'	### dot - Edges
			else	
				aArray[h][v] = 'e'	### e - Empty
			ok
		  n++
		next
	next
	
	
	###-------------------------------------------------
	### Populate Mines at random

	for n = 1 to nMines
		h = random(hSize -3 ) +2	### Prevent Zero and Edges
		v = random(vSize -3 ) +2	### Inside grid only
		aArray[h][v] = 'M'			### M - Mine
	next

	nMines = 0
	for v = 1 to vSize
		for h = 1 to hSize	
			if	aArray[h][v] = 'M'	### Cont actual Mines, Random overlaps
				nMines++
			ok
		next
	next
	
	
return



###-----------------------------------------------
### START GAME !!!
### Get user to choose cell Horz-Vert

Func GetUserInput(Row, Col)	
#See "GetUserInput: "+ m +"-"+ n +nl
	
	h = 0+ Row		### convert to number
	v = 0+ Col

	Play(h,v)
	
return

###-----------------------------------------
		 
Func Play(h,v)
#See "Play: "+ h +"-"+ v +nl
	
		if aArray[h][v] = 'e'		### e-Empty
			aArray[h][v] = 'C'		### C-Chosen
			aButton[h][v] { setStyleSheet(C_ButtonWhiteStyle) setText("") }	
			
			nClicks++
		
			CheckCellChosen(h,v)		
			nScore = CountCellsOpened()

			 TitleScore.setText(""+ nScore) 
			TitleClicks.setText(""+ nClicks)
			 TitleMines.setText(""+ nMines)	### Random generates overlapping Mines

		ok

		###---------------------------------------
	  ### MINE Explosion.  Continue Play Check

		if aArray[h][v] = 'M'	   ### M-Mine

			aArray[h][v] = 'B'		### Boom !!! 

			aButton[h][v] { 
				setStyleSheet(C_ButtonYellowStyle)			
				nImageWidth	 = Width()	-10
				nImageHeight = Height() -10
				oMine = new qpixmap(Mine)
				oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
				setIcon(new qIcon(oMine))
				setIconSize(new qSize(nImageWidth, nImageHeight))
			}
			
			nMines--
			TitleMines.setText(""+nMines)

			See "Boom !!!" +nl

			if ignoreMines.isChecked()
				return					### Continue Play
			else
				ShowMines()				### Show rest of Mine positions
		 ok

		ok

	###---------------------------------------
	### BOOM !!! Mine was chosen - END of GAME

Return

###-----------------------------------------------
### Boom ! Mine Hit. Show rest of Mine positions

Func ShowMines()
#See "ShowMines: "+nl

	for v = 2 to vSize -1
		for h = 2 to hSize -1

			if aArray[h][v] = 'M'	   ### M-Mine

				aButton[h][v] { 
					setStyleSheet(C_ButtonEmptyStyle) 
					nImageWidth	 = Width()	-16
					nImageHeight = Height() -16		
					oMine = new qpixmap(Mine)
					oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
					setIcon(new qIcon(oMine))
					setIconSize(new qSize(nImageWidth, nImageHeight))
				}

			ok

		next
	next

	
	Msg = "Game Over !!!" +nl 
	
		#	"Stat:"
		#	"Left:	"+ ce +nl +
		#	"Mines: "+ cM +nl +
		#	"Empty: "+ cF +nl +
		#	"Click: "+ cC +nl +
		#	"1's :	"+ c1 +nl +
		#	"2's :	"+ c2 +nl +
		#	"3's :	"+ c3 +nl +
		#	"4's :	"+ c4 +nl +
		#	"5-8 :	"+ c5 +"-"+ c6 +"-"+ c7 +"-"+ c8 +nl
	
	MsgBox(Msg)

			
return

###------------------------------------------
### Message Box - Lost or Won

Func MsgBox(Msg)

	mb = new qMessageBox(workWidget) 
			{
				setFont(new qFont("Courier",12,50,0))
				setWindowTitle('Minesweeper Game')
				setStyleSheet(C_ButtonYellowStyle)
				setText(Msg)
				setstandardbuttons(QMessageBox_OK) 
				result = exec()	### Needed to show Popup window
			}

###-------------------------------------
### Check 8 Neighbors of C cell clicked
### Flip e-empty to E-visited

Func CheckCellChosen(h,v)
#SEE "CheckCellChosen: "+ h +"-"+ v +nl

	#See "HV:"+h +"-"+v +" "+ aArray[h][v] +nl

	for vert = v-1 to v+1
		for horz = h-1 to h+1
	
			if aArray[horz][vert] = 'e'
				aArray[horz][vert] = "E" 
				
				aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("") }

				### Count number of Mines around the E cell
				MineCount = CheckMines(horz,vert)
				
				if MineCount != 0	
					aArray[horz][vert] = MineCount 
					 aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText(""+ MineCount) }
				ok 

				### Flip e-Cells around E-Cell
				if MineCount = 0   
					CheckAroundE(horz,vert)
				ok 

			ok	
		next
	next

return

###---------------------------------------------------
### Count the number of MINES around C and E cell

Func CheckMines(h,v)
#SEE "CheckMines: "+ h +"-"+ v +nl

   MineCount = 0

	for vert = v-1 to v+1
		for horz = h-1 to h+1
	
			if aArray[horz][vert] = 'M'	 
				MineCount++	 
			ok		
		next
	next

return MineCount

###--------------------------------------------------
### Check around E-cell for e-empty, Flip e to E 

Func CheckAroundE(h,v)
#See "CheckAroundE: "+ h +"-"+ v +nl

	### See "E: "+h +"-"+ v +nl
	for vert = v-1 to v+1
		for horz = h-1 to h+1
	
			if aArray[horz][vert] = 'e'
				aArray[horz][vert] = "E" 
					aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("") }
										

				### Count number of Mines around the E cell
				MineCount = CheckMines(horz,vert)
				
				if MineCount != 0	
					aArray[horz][vert] = MineCount 
						 aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText(""+ MineCount) }					 
				ok 

				### Recursive - check around New E's
				### Flip e-Cells around E-Cell
				if MineCount = 0   
					CheckAroundE(horz,vert)
				ok 

			ok	
		next
	next

return

###-----------------------------------------------------------
### Count Cells that were opened -Global - for nScore, Statistic count

Func CountCellsOpened()
	
		### Statistics Reset to 0. Fresh Count
		ce = 0 cM = 0 cF = 0 cC = 0 c1 = 0 c2 = 0 
		c3 = 0 c4 = 0 c5 = 0 c6 = 0 c7 = 0 c8 = 0 

	cells = (hSize-2) * ( vSize-2)
	for v = 2 to vSize -1
		for h = 2 to hSize -1
			if aArray[h][v] = "e"  ce++	 ok
			if aArray[h][v] = "M"  cM++	 ok
			if aArray[h][v] = "E"  cF++	 ok
			if aArray[h][v] = "C"  cC++	 ok
			if aArray[h][v] = "1"  c1++	 ok
			if aArray[h][v] = "2"  c2++	 ok
			if aArray[h][v] = "3"  c3++	 ok
			if aArray[h][v] = "4"  c4++	 ok
			if aArray[h][v] = "5"  c5++	 ok
			if aArray[h][v] = "6"  c6++	 ok
			if aArray[h][v] = "7"  c7++	 ok
			if aArray[h][v] = "8"  c8++	 ok			
		next 
	next
	
	#SEE "Cells Opened: "+ ce +"-"+ cM +"-"+ cF +"-"+ cC +"-"+ c1 +"-"+ c2 +"-"+ c3 +"-"+ c4 +"-"+ c5 +"-"+ c6 +"-"+ c7 +"-"+ c8 +nl
	count = cF +cC +c1 +c2 +c3 +c4 +c5 +c6 +c7 +c8
	
	if ce = 0
		Msg = "You Won !!!"
		MsgBox(Msg)
	ok
	
return count
	
###--------------------------------------------------

###--------------------------------------------------
### RightMouse Click on PushButton - 

Func myMenu(Row,Col)

	### Record which Cells are Questioned with RightClick
	### questionList = list(1)
	
	Cell = ""+ Row +"-"+ Col
	Add( questionList, Cell)
	#SEE "questionList: "+nl  SEE questionList	SEE nl

	aButton[Row][Col] { setStyleSheet(C_ButtonCyanStyle) }
	
	###---------------------------------
	### Should ??? Button be Un-Flipped
	j = len(questionList)
	for i = 1 to (j-1)
		#SEE"List: "+ i +" "+ questionList[i] +" :: "+ questionList[j] +nl
		
		if questionList[i] = questionList[j]							### matches last entry
		
		### SEE"Equal "+ i +" "+ questionList[i] +" :: "+ questionList[j] +nl
		
			aButton[Row][Col] { setStyleSheet(C_ButtonEmptyStyle) }		### Un-Flip it
			Del( questionList, j)										### remove last entry from list
			Del( questionList, i)
			exit
		ok
	 
	next
	
	
return

###---------------------------
