### Program:	 Knight Tour 
### Author:	 Bert Mariani, Nestor Kuka
### Date:	 2018-10-14
### Update:	 2018-11-11

load "stdlib.ring"
load "guilib.ring"	

###-------------------
### Track Moves

lTrackMoves =  False	 ### True = Knight / False = SolidColor

###-------------------
### WINDOW SIZE

sizeX  = 800 sizeY	= 600		### Size of Window

hSize	= 8 +2 +2	### Size of array, Display -4 smaller
vSize	= 8 +2 +2	### Size of array, Display -4 smaller

h	= 0	### Horizontal coordinate of Cell
v	= 0	### Vertical coordinate of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray			= null
aButton			= null
workWidget		= null
ManualGame		= null
OldMoveColor	= null
Slider1			= null
TitleKnightMoves		= null
TitleKnightInvalidMove	= null
LayoutButtonRow			= null
 
Knight	  = AppFile("knight.png")
oKnight	  = new QPixmap(Knight)
bWidth	  = oKnight.width()	  	### 50 
bHeight	  = oKnight.height()	### 50
nMoves	  = 0 

oldH = 0
oldV = 0
 
C_Spacing  = 2
C_ButtonIconWidth  = 60
C_ButtonIconHeight = 60
C_ButtonMinWidth   = 80
C_ButtonMinHeight  = 80
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'+
			  'border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray;'
C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); '+
			  'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

			  
animationDelay = 0.5	###	 Sleep 1 second between Computer Moves display
	
###=============================================================================
###=============================================================================
### The shortest app function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp 
{
	
	DrawWidget()
	NewGameStart()
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
		
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Moves Count
			
							
			TitleKnightMoves = new qLineEdit(workWidget) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" Moves: "+ nMoves)
			}	

			TitleKnightInvalidMove = new qLineEdit(workWidget) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText("Click on Square to Start")
			}	


		   Slider1 = new qslider(workWidget) 
		   {
				setorientation(Qt_Horizontal)
				setTickInterval(50)								### Remember setting on New Game
				setvalue( 100 - (animationDelay * 100 ) )		### 100 - ( 0.5 * 100) => 0.5 sec delay between moves
				setValueChangedEvent("SliderEventValueChg()")

			}			

			OldMoveColor = new qcheckbox(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setStyleSheet("background-color:rgb(204,255,229)")
				setText("SolidColor")
			}
			
			ManualGame = new qcheckbox(workWidget) 
			{
				setFont(new qFont("Calibri",fontsize,100,0))
				setStyleSheet("background-color:rgb(204,255,229)")
				setText("Computer")
			}
			
			NewGame	 = new QPushButton(workWidget) 
			{
				setStyleSheet("background-color:rgb(255,204,229)")
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
				
			
			LayoutTitleRow.AddWidget(TitleKnightMoves)
			LayoutTitleRow.AddWidget(TitleKnightInvalidMove)
			LayoutTitleRow.AddWidget(Slider1)		
			LayoutTitleRow.AddWidget(OldMoveColor)
			LayoutTitleRow.AddWidget(ManualGame)
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
						setMinimumWidth(C_ButtonMinWidth)
						setMinimumHeight(C_ButtonMinHeight)														
					}
					
				### Widget - Add HORIZONTAL BUTTON
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

	###NewLocation(3,3)


return

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart()

	workWidget.Close()

	hSize = 8 + 2 + 2	
	vSize = 8 + 2 + 2 
	
	NewLocation(0, 0)	### Indicate start game - User Picks Starting Square

	
	###--------------------------------------------------
	### What were previous setting
	
	FlagOldMoveColor	= 0
	FlagManualGame		= 0
	oldAnimationDelay	= animationDelay 
	
	if OldMoveColor.isChecked() FlagOldMoveColor = 1  ok
	if ManualGame.isChecked()	FlagManualGame	 = 1  ok

	
	nMoves = 0
	TitleKnightMoves.setText(" Moves: "+ nMoves)
	TitleKnightInvalidMove.setText(" Click a Square to Start")
	
	
	for h = 1 to hSize
		for v = 1 to vSize
			aArray[h][v] = 'e'	### e - empty
		next
	next
		
	DrawWidget()	### ===>>>
	
	###--------------------------------------------------
	### Restore previous settings
	
	if FlagOldMoveColor = 1 OldMoveColor.setChecked(True) ok
	if FlagManualGame	= 1 ManualGame.setChecked(True)	  ok


	
return

###-----------------------------------------------
### START GAME !!!
### Get User - Cell Clicked - Horz-Vert

Func UserLeftClick(Row, Col)	

	h = 0+ Row		### convert to number
	v = 0+ Col
	
	if OldMoveColor.isChecked()
		lTrackMoves = False
	else
		lTrackMoves = True
	ok
	
	if ManualGame.isChecked() 
		ComputerPlay(h,v)	### Then ===>>> Calls Play(h,v)
	else
		Play(h,v)
	ok
	
return

###-----------------------------------------
### PLAYED MOVE		 

Func Play(h,v)

#See "Func-Play: "+h +"-"+ v +nl

	if ValidMove(oldH, oldV, h, v)
		if CheckEndOfGame() return ok
		
		ClearOldMove()	
		NewLocation(h,v)
		RecordNewMove()
		
		if CheckEndOfGame() return ok
	ok
return	

###---------------------------
### Clear Square -- Old Move
	
Func ClearOldMove()
	if oldH != 0								### oldH = 0 , oldV = 0 Before Start, No move played
		aButton[oldh][oldv] { 
			if lTrackMoves						### True - show Knight
			
				nImageWidth	 = Width()	- 65
				nImageHeight = Height() - 65	
				oMine = new qpixmap(Knight)
				setIcon(new qIcon(oMine))
				setFont(new qFont("Calibri",14,100,0))
				setText(""+ nMoves)		
				setIconSize(new qSize(C_ButtonIconWidth, C_ButtonIconHeight))	
			else								### False show Solid Color
				oMine = new qpixmap2(0,0)
				setIcon(new qIcon(oMine))
				setStylesheet("background-color:rgb(64,128,128);")	### Color blind people have problem with rgb(0,255,100);") 
				setFont(new qFont("Calibri",14,100,0))
				setText(""+ nMoves)
				setIconSize(new qSize(C_ButtonIconWidth, C_ButtonIconHeight))
			ok
		}	
	ok
return

###------------------------------------------
### Increase Moves Counter 

Func RecordNewMove
	nMoves++			
	TitleKnightMoves.setText(" Moves: " + nMoves)
return

###------------------------------------------
### Check that all cells are visited

Func CheckEndOfGame()
	for Row = 3 to vSize -2
		for Col = 3 to vSize -2
			if aArray[Row][Col] != 'v'
				return False 
			ok
		next
	next
	cMsg = "You completed the game in " + nMoves + " moves" 
	if nMoves > 63
		cMsg += ", but can you do it in a fewer?" 
	ok
	MsgInfo("Knight Tour",cMsg)
return True

###------------------------------------------
### Move the Knight to a new location

Func NewLocation(h,v)

	if h = 0 and V = 0
		### Ignore
	else
		aButton[h][v] { 
			nImageWidth	 = Width()	-24
			nImageHeight = Height() -24		
			oMine = new qpixmap(Knight)
			//oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
			setIcon(new qIcon(oMine))
			setIconSize(new qSize(C_ButtonIconWidth, C_ButtonIconHeight))
		}		
	

		aArray[h][v] = 'v'
	ok

	oldH = h
	oldV = v
return
		
###------------------------------------------
### ValidMove are L shaped in 8 directions

Func ValidMove( oldH, oldV, h, v)

	### ClockWise-LD	  LU  -- UL	   UR -- RU	   RD --- RU	  DL	  
	PosMove	 = [[-2,-1],[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2]] 
	
	FlagValidMove = 0
	if Not (oldH=0 and oldV=0) 
		TitleKnightInvalidMove.setText(" Msg:  Invalid Move ")
	ok
	
	for i = 1 to 8
		if h = oldH + PosMove[i][1] AND	 v = oldV + PosMove[i][2]
			FlagValidMove = 1
			TitleKnightInvalidMove.setText(" Msg:			   ")
			exit
		ok
	next
	
	###---------------------
	### Debug
	if FlagValidMove = 0
		See "InvalidMove: "+ oldH +"-"+ oldV +" >>> "+ h +"-"+ v +nl
		
		if oldH = 0 AND oldV = 0		### Ignore. User selects First Move
			FlagValidMove = 1
		ok
	ok
	
return FlagValidMove

###-------------------------------------
### Speed of Move Animation

Func SliderEventValueChg()

	#See "Change: "+ Slider1.value() +nl
	animationDelay = (100 - Slider1.value() ) / 100
return

###================================================
###================================================
###================================================

### Knights Tour Version - 1  Nestor Kuka -- Derived from: C:\euphoria\myWork\kt-main.eux 
### Which is based on the py version recipe.
### Works Fine /  Version without graphics/	With Warnsdorff's rule (extended)
### Load "stdlib.ring"

Func ComputerPlay(horz,vert)

### Possible Moves
pm = [[-2,1],[-1,2],[1,2],[2,1],[-2,-1],[-1,-2],[1,-2],[2,-1]]

n	= 8						### Number rows/columns
cbx = n						### rows
cby = n						### cols

/*
### Startfield	( 2/2 = Critical!) 
### kx	= 2					### works fine now
### ky	= 2					### works fine now

### Startfield	-  Randomizer (to test)
kx	= random(n)				### function
ky	= random(n)

### Randomizer works from 0 to ...n
if kx = 0 kx = kx+1 ok		### arrays not	NULL based!
if ky = 0 ky = ky+1 ok
see "Start-field Kx/Kx: "+kx +"/"+ ky +nl+nl
*/

###-------------------------------------------------------
### OverRide Random. USER Picks Starting Square. 
### By Calling this function ComputerPlay(horz.vert)

Kx = horz -2
Ky = vert -2
NewLocation(Kx+2, Ky+2)		### Board to Internal

see "Start-field Kx-Ky: "+Kx +"-"+ Ky +nl

###------------------------------------------------------
### Make Chessboard n*n

cb = list(cby) for x in cb	x = list(cbx)  next

k = 0						### jumps-counter 
while k <= cbx * cby
	cb[ky][kx] = k+1
	pq = []					### priority Queue
	for i = 1 to n			### row
		nx = kx + pm[i][1]
		ny = ky + pm[i][2]	
		
		if between(nx, 1, cbx) and between(ny, 1, cby)	
			if cb[ny][nx] = 0  ctr = 0
			
				for j = 1 to n	### col
					ex = nx + pm[j][1] ;	
					ey = ny + pm[j][2]
					
					if between(ex, 1, cbx) and between(ey, 1, cby)	### funzt
						if cb[ey][ex] = 0  
							ctr++ 
						ok
					ok
				next		
				add(pq,(ctr*100)+i)		### format zB: 302
			ok	
		ok	
	next	   

	###	 -- Warnsdorff’s algorithms;	extended
	###		Move to the neighbor that has min number of available neighbors
	###		Randomization:	we could take it - or not
	
	if len(pq) > 0
		pq = sort(pq)				### min-value at begin
			minVal = 8				### max loop nr
			minD   = 0				### min value 
			
			for dd = 1 to len(pq)
				x= pq[1]			### min-value 
				p  = floor(x/100)	### ctr	 - value
				m = x % 10			### i	 - value (row)
				
				if p = minVal and random(10) <5	
					minVal = p
					minD   = m
				end
					
				if p < minVal 
					minVal = p
					minD   = m
				end	 
					
				Del(pq,1)			### delete item number three
				
			end	 ### dd

		m = minD 

		kx = kx + pm[m][1]
		ky = ky + pm[m][2]

		###------------------------------------------
		### Call Func PLAY for this move

		app.processevents()
		Sleep(animationDelay)		### Need Delay - Read from Slider1
		
		horz =		kx +2			### Internal move = Board +2
		vert =		ky +2 
		
		SEE "Kx-Ky: "+k +" "+ kx +"-"+ ky +nl	 ### SEE "	--- Play: "+horz +"-"+ vert +nl
		Play(horz, vert)
		
		####------------------------------------------
		
	else 
		if k < 63
			see "Error in the field no .: "+k+nl+nl
			exit
		else
			see "Success." +nl+nl
			exit
		ok
	ok

	k++
	
end ### while

### end program ************************************

###-------------------------------------------------
### Control output:

  See "..| 1| 2| 3| 4| 5| 6| 7| 8|" +nl
  for r = 1 to N					### row
	See " "+ r
	for c = 1 to N					### col
		see	 "|"					### separator
		if cb[c][r] <= (n+1)
			see "_" 
			###see " "				### protected blank: old 255 (not enough)
			see	 cb[c][r]		
		else
				see cb[c][r]		### get content from cb
		ok
	next ###for 
	
	see	"|"							### separator
	see nl
  next ###for	

func between x, mi, mx				### min & max are keywords
	between = (x >= mi) AND (x <= mx)
return between


/* Example:
### Result from kt-02-3.ring
|46|19|16|_1|30|43|14|11|
|17|_2|45|56|15|12|29|42|
|20|47|18|31|44|55|10|13|
|_3|34|57|54|59|32|41|28|
|50|21|48|33|62|27|60|_9|
|35|_4|51|58|53|40|63|26|
|22|49|_6|37|24|61|_8|39|
|_5|36|23|52|_7|38|25|64|
*/

###==========================================
