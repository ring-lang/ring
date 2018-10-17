## Program:	 Knight Tour 
### Author:	 Bert Mariani, Nestor Kuka
### Date:	 2018-10-14

load "stdlib.ring"
load "guilib.ring"	

###-------------------
### Track Moves

lTrackMoves =  False	 ### True = Knight / False = SolidColor

###-------------------
### WINDOW SIZE

moveX  = 200 moveY	= 100		### Open Window on Screen Position
sizeX  = 800 sizeY	= 820		### Size of Window

hSize	= 8 +2 +2	### Size of array, Display -4 smaller
vSize	= 8 +2 +2	### Size of array, Display -4 smaller

h	= 0	### H-coord of Cell
v	= 0	### V-coord of Cell


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
bWidth	  = oKnight.width()	  ### 50 
bHeight	  = oKnight.height()	  ### 50
nMoves	  = 0 

oldH = 0
oldV = 0
 
C_Spacing  = 2
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'+
			  'border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray;'
C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); '+
			  'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

			  
animationDelay = 0.5	###	 Sleep 1 sec bewteen Computer Moves display
	
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
				setTickInterval(50)					### Remember setting on New Game
				setvalue(animationDelay * 100 )		### 50 / 100 = 0.5 sec delay between moves
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
	if oldH != 0			### oldH = 0 , oldV = 0 Before Start, No move played
		aButton[oldh][oldv] { 
			if lTrackMoves						### True - show Knight
			
				nImageWidth	 = Width()	- 65
				nImageHeight = Height() - 65	
				oMine = new qpixmap(Knight)
				setIcon(new qIcon(oMine))
				setIconSize(new qSize(nImageWidth, nImageHeight))
				setFont(new qFont("Calibri",14,100,0))
				setText(""+ nMoves)			
			else								### False show Solid Color
				oMine = new qpixmap2(0,0)
				setIcon(new qIcon(oMine))
				setStylesheet("background-color:rgb(64,128,128);")	### Color blind people have problem with rgb(0,255,100);") 
				setFont(new qFont("Calibri",14,100,0))
				setText(""+ nMoves)
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
			oMine = oMine.scaled(nImageWidth , nImageHeight ,0,0)
			setIcon(new qIcon(oMine))
			setIconSize(new qSize(nImageWidth, nImageHeight))
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
	TitleKnightInvalidMove.setText(" Msg:  Invalid Move ")
	
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
	animationDelay = Slider1.value() / 100
return

###================================================
###================================================
###================================================

### Nestor Kuka 
### Knights Tour version - 1  derived from: C:\euphoria\myWork\kt-main.eux 
### which is based on the py version recipe..
### funzt (finally) version without graphics

### Load "stdlib.ring"

Func ComputerPlay(horz,vert)

### Possible Moves
PosMoves = [[-2,1],[-1,2],[1,2],[2,1],[-2,-1],[-1,-2],[1,-2],[2,-1]]

Size	= 8				### number rows/collons
BoardX	= Size			### rows
BoardY	= Size			### colls

### Start field - Random generator (to test)
Kx	= random(Size)			### funzt
Ky	= random(Size)

### critical start point (wernsdoff wrong?)
### Kx	= 2 
### Ky	= 2

###---------------------------------
### Randomizer works from 0 to ...

if Kx = 0 Kx = Kx +1 ok		### arrays are not NULL based!
if Ky = 0 Ky = Ky +1 ok

###-------------------------------------------------------
### OverRide Random. USER Picks Starting Square. 
### By Calling this function ComputerPlay(horz.vert)

Kx = horz -2
Ky = vert -2
NewLocation(Kx+2, Ky+2)		### Board to Internal

see "Start-field Kx-Ky: "+Kx +"-"+ Ky +nl

###-----------------------
### Make Board Size*Size

ChessB = list(BoardY) 
for x in ChessB	 
	x = list(BoardX)  
next

JumpCnt = 0								### Jumps-counter 
while JumpCnt <= BoardX * BoardY
	ChessB[Ky][Kx]	= JumpCnt +1
	PriorityQueue	= []					### Priority Queue
	
	for i = 1 to Size						### Row
		NextX = Kx + PosMoves[i][1]
		NextY = Ky + PosMoves[i][2]	 
		
		if Between(NextX, 1, BoardX) and Between(NextY, 1, BoardY)	### Func ===>>>
			if ChessB[NextY][NextX] = 0	 Counter = 0
			
				for j = 1 to Size			### Col
				
					plusNextX = NextX + PosMoves[j][1]
					plusNextY = NextY + PosMoves[j][2]
					
					if Between(plusNextX, 1, BoardX) and Between(plusNextY, 1, BoardY)	### funzt
						if ChessB[plusNextY][plusNextX] = 0	 Counter++ ok
					ok
				next						
				
				add(PriorityQueue,(Counter * 100) +i)		### format zB: 302
			ok								
			
		ok									
	next								
	
	###	 -- Warnsdorff�s algorithmus;  
	###		Move to the neighbor that has min number of available neighbors
	###		Randomization:	we could take it - or not
	
	if len(PriorityQueue) > 0
		PriorityQueue = sort(PriorityQueue)					### min-value at the beginning
		x  = PriorityQueue[1]								### min-value 
		p  = floor(x / 100)									### Counter-value
		m  = x % 10											### i - value (Row)

		if p = m > 0 and random(10) < 5						### ring-array is not 0-based! 
			m = m % 10			
		elseif p < m 
			m = m % 10		
		ok

		Kx = Kx + PosMoves[m][1]
		Ky = Ky + PosMoves[m][2]
		
		###------------------------------------------
		### Call Func PLAY for this move

		app.processevents()
		Sleep(animationDelay)			### Need Delay - Read from Slider1
		
		horz =		kx +2	### Internal move = Board +2
		vert =		ky +2 
		
		SEE "Kx-Ky: "+JumpCnt +" "+ kx +"-"+ ky	 SEE "	--- Play: "+horz +"-"+ vert +nl
		Play(horz, vert)
		
		####------------------------------------------
		
	else 
		if JumpCnt < 63
			see "Error in Field No..: "+JumpCnt +nl+nl
			exit
		else
			see "Sucess." +nl+nl
			exit
		ok
	ok
	JumpCnt++
	
end ### while

	### END PROGRAM	  **************************************

	###----------------------------------------
	### Control-edition:

	for r = 1 to Size					### row
		for c = 1 to Size				### col
		
			see	 "|"					### disconnect sign
			if ChessB[c][r] <= (Size+1)
				see "_"					### Protected blank: old 255 (not enough)		
				see	 ChessB[c][r]		
			else
				see	 ChessB[c][r]		### Get content from ChessB
			ok
			
		next 
		see "|"	+nl						### disconnect sign		
	next   


###----------------------------------------
### min & max sind keywords

Func Between x, mi, mx	
	between = (x >= mi) AND (x <= mx)
return between


/* beispiel:
### resultat aus kt-01.ring 
|46|19|16|_1|30|43|14|11|
|17|_2|45|56|15|12|29|42|
|20|47|18|31|44|55|10|13|
|_3|34|57|54|59|32|41|28|
|50|21|48|33|62|27|60|_9|
|35|_4|51|58|53|40|63|26|
|22|49|_6|37|24|61|_8|39|
|_5|36|23|52|_7|38|25|64|
*/


###=====================================
