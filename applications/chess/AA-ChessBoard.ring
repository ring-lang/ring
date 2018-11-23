## Program:	 Chess 2 Players - manual
### Author:	 Bert Mariani
### Date:	 2018-10-14

load "stdlib.ring"
load "guilib.ring"	

###-------------------
### Track Moves

lTrackMoves =  False	 ### True = Knight / False = SolidColor

###-------------------
### WINDOW SIZE

moveX  = 200 moveY	= 100		### Open Window on Screen Position
sizeX  = 840 sizeY	= 820		### Size of Window

hSize	= 8 +2 +2	### Size of array, Display -4 smaller
vSize	= 8 +2 +2	### Size of array, Display -4 smaller

h	= 0	### H-coord of Cell
v	= 0	### V-coord of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray			= null
aButton			= null
workWidget		= null
recordArray		= null
comboPromotePawn = null


TitletMoves			= null
TitletInvalidMove	= null
LayoutButtonRow		= null

FlagStartMove = 0
FromRow = 1
FromCol = 1
ToRow	= 5
ToCol	= 3
OldRow	= 3
OldCol	= 3
PickedPiece	= "e"

TurnColor	= "White"		### "Black"
IgnoreTurnColor = False		### False <<=== Set to TRUE for Debug and Testing

KingRow = 1					###	 Where King is Found by KingChecked()
KingCol = 1

EnPassant		= False		### Only Pawn can eat Other Color Pawn after Move by 2
EnPassantCol	=	1		### Vertical Column of Last Pawn making a 2 move

###----------------------------

aLookup = [ ["BR","BRook.png"], 
			["BN","BKnight.png"],
			["BB","BBishop.png"],
			["BQ","BQueen.png"],
			["BK","BKing.png"],
			["BP","BPawn.png"],	
			
			["WR","WRook.png"], 
			["WN","WKnight.png"],
			["WB","WBishop.png"],
			["WQ","WQueen.png"],
			["WK","WKing.png"],
			["WP","WPawn.png"]
		  ]

 
###---------------------------------------
### Piece on Square - Scale it later

Knight	  = AppFile("WKnight.png")
oKnight	  = new QPixmap(Knight)
bWidth	  = oKnight.width()	  ### 50 
bHeight	  = oKnight.height()	  ### 50

nMoves	  = 0 

oldH = 0
oldV = 0
 
C_Spacing  = 2
C_ButtonFirstStyle	= 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'
			  ###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray;'

C_ButtonSecondStyle	= 'border-radius:1px; color:black; background-color: rgb(179,200,93); '
			  ###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

C_ButtonPickStyle	= 'border-radius:1px; color:black; background-color: rgb(255,255,93); '
			 # ##'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '
			  
C_ButtonDestStyle	= 'border-radius:1px; color:black; background-color: rgb(204,255,204); '
			 # ##'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

C_ButtonCheckStyle	= 'border-radius:1px; color:black; background-color: rgb(204,93,93); '
			 # ##'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '

			 
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
		recordArray	= newList(1, 2)	### Record the Moves ...  WN 8-7  to  6-6
		
		setWindowTitle('Chess 2 Player')
		setStyleSheet('background-color:White')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		  move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Moves Count
			
							
			TitletMoves = new qLineEdit(workWidget) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" Moves: "+ nMoves)
			}	

			TitletInvalidMove = new qLineEdit(workWidget) 
			{
				setStyleSheet("background-color:rgb(255,255,204)")
				setFont(new qFont("Calibri",fontsize,100,0))
				setAlignment( Qt_AlignVCenter)
				setAlignment( Qt_AlignVCenter)
				setText(" White ")
			}		
			
			comboPromotePawn = new QComboBox(workWidget) 
			{
				setStyleSheet("background-color:White")
				setFont(new qFont("Calibri",fontsize,100,0))
				aList = ["Queen","Rook","Bishop","Knight"]
				for x in aList additem(x,0) next				
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
				
			
			LayoutTitleRow.AddWidget(TitletMoves)
			LayoutTitleRow.AddWidget(TitletInvalidMove)	
			LayoutTitleRow.AddWidget(comboPromotePawn)			
			LayoutTitleRow.AddWidget(NewGame)		
								
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
		   
				###-------------------
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


		DrawPieces()
	
		show()
	}

return

###============================================================

###============================================================
### DrawImage( "BRook.png", Row , Col )

Func DrawImage( Piece, Row,	 Col  )

	#SEE "Image: "+ Image +" "+ Row +" "+ Col  +nl

	aButton[Row][Col] { 
						oPiece = new qpixmap(Piece)	 
						nImageWidth	 = oPiece.Width()		### Piece, not Square	 
						nImageHeight = oPiece.Height()		### Piece, not Square	
						oPiece = oPiece.scaled(nImageWidth , nImageHeight ,0,0) 
						setIcon(new qIcon(oPiece)) 
						setIconSize(new qSize(nImageWidth , nImageHeight ))
					  }		

return
###----------------------------------------------------------
### DrawPieces( Image, Wid, Hig, Row, Col)

Func DrawPieces()

	DrawImage("BRook.png",	 3, 3)
	DrawImage("BKnight.png", 3, 4)
	DrawImage("BBishop.png", 3, 5)
	DrawImage("BQueen.png",	 3, 6)
	DrawImage("BKing.png",	 3, 7)
	DrawImage("BBishop.png", 3, 8)
	DrawImage("BKnight.png", 3, 9)
	DrawImage("BRook.png",	 3, 10)

	DrawImage("BPawn.png",	 4, 3)
	DrawImage("BPawn.png",	 4, 4)
	DrawImage("BPawn.png",	 4, 5)
	DrawImage("BPawn.png",	 4, 6)
	DrawImage("BPawn.png",	 4, 7)
	DrawImage("BPawn.png",	 4, 8)
	DrawImage("BPawn.png",	 4, 9)
	DrawImage("BPawn.png",	 4, 10)

	DrawImage("WRook.png",	10, 3)
	DrawImage("WKnight.png",10, 4)
	DrawImage("WBishop.png",10, 5)
	DrawImage("WQueen.png", 10, 6)
	DrawImage("WKing.png",	10, 7)
	DrawImage("WBishop.png",10, 8)
	DrawImage("WKnight.png",10, 9)
	DrawImage("WRook.png",	10, 10)
			   
	DrawImage("WPawn.png",	 9, 3)
	DrawImage("WPawn.png",	 9, 4)
	DrawImage("WPawn.png",	 9, 5)
	DrawImage("WPawn.png",	 9, 6)
	DrawImage("WPawn.png",	 9, 7)
	DrawImage("WPawn.png",	 9, 8)
	DrawImage("WPawn.png",	 9, 9)
	DrawImage("WPawn.png",	 9, 10)



	###-----------------------------------
	### Populare aArray with Piece info:
	### 1	2	3	4	5	6
	### WR, WN, WB, WQ, WK ,WP, e
	### BR, BN, BB, BQ, BK, BP, e

	h = 3	v = 3		### 1 +2
	aArray[h][v+0] = "BR"
	aArray[h][v+7] = "BR"
	aArray[h][v+1] = "BN"
	aArray[h][v+6] = "BN"
	aArray[h][v+2] = "BB"
	aArray[h][v+5] = "BB"
	aArray[h][v+3] = "BQ"
	aArray[h][v+4] = "BK"

	h = 4	v = 3
	aArray[h][v+0] = "BP"
	aArray[h][v+1] = "BP"
	aArray[h][v+2] = "BP"
	aArray[h][v+3] = "BP"
	aArray[h][v+4] = "BP"
	aArray[h][v+5] = "BP"
	aArray[h][v+6] = "BP"
	aArray[h][v+7] = "BP"

	###-------------------

	h = 10	v = 3		### 8 +2
	aArray[h][v+0] = "WR"
	aArray[h][v+7] = "WR"	
	aArray[h][v+1] = "WN"
	aArray[h][v+6] = "WN"					
	aArray[h][v+2] = "WB"
	aArray[h][v+5] = "WB"					
	aArray[h][v+3] = "WQ"
	aArray[h][v+4] = "WK"
					
	h = 9	v = 3		### 7+2 
	aArray[h][v+0] = "WP"
	aArray[h][v+1] = "WP"
	aArray[h][v+2] = "WP"
	aArray[h][v+3] = "WP"
	aArray[h][v+4] = "WP"
	aArray[h][v+5] = "WP"
	aArray[h][v+6] = "WP"
	aArray[h][v+7] = "WP"


Return

###============================================================

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart()
See "Func NewGameStart: "+nl

	workWidget.Close()

	hSize = 8 + 2 + 2	
	vSize = 8 + 2 + 2 
	
		
	for h = 1 to hSize
		for v = 1 to vSize
			aArray[h][v] = 'e'	### e - empty
		next
	next
		
	DrawWidget()	### ===>>>
	
	TurnColor	= "White"		### "Black"
	
return


###-----------------------------------------------
### USER CLICK 
### Get User - Cell Clicked - Horz-Vert

Func UserLeftClick(Row, Col)	

	h = 0+ Row		### convert to number
	v = 0+ Col

	Play(Row,Col)

return

###-----------------------------------------
### PLAY MOVE	
### Highlight the From-Square With Piece	 

Func Play(Row,Col)

	#See "Func-Play: Call: "+ aArray[Row][Col] +" "+ Row +" "+ Col	+" flag "+ FlagStartMove +nl

		###--------------------------------------------------------------------
		### Yellow the Square for New Pick, Restore Old Destination Square Color
		
		RestoreSquareColor(OldRow, OldCol)
		aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }		### Yellow Highlight the  From-Square
		
		OldRow = Row
		OldCol = Col
	
		###------------------------------------------
		### Color of Piece Picked and Captured Piece
				
		ColorFrom = aArray[FromRow][FromCol]
		ColorTo	  = aArray[Row][Col]
	
	###--------------------------------------------------------------
	### FIRST -PICK Piece - NOT Empty - PIECE is on Square	to Play
	
	if FlagStartMove = 0
		#See "Func-Play: 1st Start 0" +nl
		if aArray[Row][Col] != 'e'	
		
			###--------------------------------
			### Enforce Whose Turn
			PieceColor = aArray[Row][Col] 
			if TurnColor[1] != PieceColor[1]							###	 "White" != "BP" 
				aButton[Row][Col] { setStyleSheet(C_ButtonCheckStyle) }	### NOT Your Turn
				See "TurnColor: "+ TurnColor +" <> "+ PieceColor +nl
				return
			ok		
			###--------------------------------
		
			FlagStartMove = 1											### SECOND MOVE is Next
			FromRow = Row
			FromCol = Col
			PickedPiece	= aArray[Row][Col]		
			#aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }		### Yellow Highlight the  From-Square

		else  ### Start Move is Empty Button
			aButton[Row][Col] { setStyleSheet(C_ButtonCheckStyle) }
			return
						
			
		ok
		
	###---------------------------------------------------	
	### SECOND MOVE Flag but Square has same color Piece 
	### Player CHANGED MIND on which Piece to Play
	
	but ColorFrom[1] = ColorTo[1]										### First "WN" ... Second "WB"	... Changed Mind ?
	
			FlagStartMove = 1											### SECOND MOVE is Next

			PickedPiece	= aArray[Row][Col]		
			aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }		### Yellow the FROM-SQUARE
			RestoreSquareColor(FromRow, FromCol)						### Changed Mind - FROM SQUARE - Un-Yellow
						
			FromRow = Row												### New FROM PickedPiece Coord
			FromCol = Col

	
	###-------------------------------------------------------------
	### SECOND - MOVE Piece to EMPTY SQUARE - Piece that was Picked	
	### FlagStartMove = 1
	
	but aArray[Row][Col] = 'e'	### Empty
		#See "Func-Play: 2nd to Empty Square"+ nl 
		aButton[Row][Col] { setStyleSheet(C_ButtonDestStyle) }			### Cyan Highlight the TO-Square
	
			###---------------------------------------------
			### Check if SKIP OVER PIECES-- FROM => TO Move
			
			skipResult = SkipOverPieces(PickedPiece, FromRow, FromCol, Row, Col)
			#See "CheckSkipResult: "+ skipResult +nl
			
			if skipResult = 1
				### PATH is Blocked			
				FlagStartMove = 0
				RestoreSquareColor(FromRow, FromCol)

				TitletInvalidMove.setText(" Msg: "+	 PickedPiece +" : Jumped Over Piece "  )
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,255)") }
			
				return
			else
				### PATH is Clear 
				TitletInvalidMove.setText(" Msg:			   ")
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,255,204)")}	 ### OK - Pale color
			ok
			
			###-----------------------------------
			### Valid Move for the Piece
			
			Valid = ValidMove( PickedPiece, FromRow, FromCol, Row, Col)			### Valid Move for this Piece ? True=1, False=0
			
			if Valid = 0	
				### NOT VALID - FlagValidMove = 0			
				FlagStartMove = 0
				RestoreSquareColor(FromRow, FromCol)

				TitletInvalidMove.setText(" Msg: "+ PickedPiece +" : Invalid Move to Square" )
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,102)") }				
				
				return
			else
				### VALID - FlagValidMove = 1
				TitletInvalidMove.setText(" Msg:			   ")
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,255,204)")}	 ### OK - Pale color
			ok
			

			
			
			###-----------------------------------------
			### Copy Internal Piece From-Cell to To-Cell
			### Color From-Square
			
			#See "Func-Play: Path - Was Valid" +nl
			
			FlagStartMove = 0									
			Who = Find(aLookup, PickedPiece, 1)
			DrawImage( aLookup[Who][2], Row, Col )
					
			aArray[Row][Col] = aArray[FromRow][FromCol]				
			ClearSquare(FromRow, FromCol)							
			WhoseTurn(PickedPiece)
			RecordNewMove(PickedPiece, FromRow, FromCol, Row, Col)
			
				ByColor = "W"  WhiteKingIsChecked = False
				result = KingChecked( ByColor )							### Check if WhiteKing Checked / CkeckMate
				
					if result = True
						aButton[KingRow][KingCol] { setStyleSheet(C_ButtonCheckStyle) }		### Check Color	
					else
						RestoreSquareColor(KingRow, KingCol)
					ok
				
				ByColor = "B"	BlackKingIsChecked = False
				result = KingChecked( ByColor )							### Check id BlackKing Checked / CheckMate

					if result = True
						aButton[KingRow][KingCol] { setStyleSheet(C_ButtonCheckStyle) }		### Check Color	
					else
						RestoreSquareColor(KingRow, KingCol)
					ok				
	###--------------------------------------------------	
	###	 CAPTURE PIECE on DESTINATION SQUARE	
	else

		#See "Func-Play: Capture Piece" +nl
		aButton[Row][Col] { setStyleSheet(C_ButtonDestStyle) }		### Cyan Highlight the TO-Square
		
			###----------------------------------------------------
			### Valid Move for the Piece Picked to Captured Piece
			
			Valid = ValidMove( PickedPiece, FromRow, FromCol, Row, Col)			### Valid Move for this Piece ? True=1, False=0
			
			if Valid = 0	
				###FlagValidMove = 0			
				FlagStartMove = 0
				RestoreSquareColor(FromRow, FromCol)

				TitletInvalidMove.setText(" Msg: "+ PickedPiece +" : Invalid Move for Capture" )
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,102)") }
				return
			else
				###FlagValidMove = 1
				TitletInvalidMove.setText(" Msg:			   ")
				TitletInvalidMove { setStyleSheet("background-color:rgb(255,255,204)")}	 ### OK - Pale color
			ok

			
			
					
			###-------------------------
			### Other Color Piece
			
			if ColorFrom[1] != ColorTo[1]									### Other Piece
				#See "Func-Play: Capture Other Color" +nl
				
				FlagStartMove = 0									
				Who = Find(aLookup, PickedPiece, 1)
				DrawImage( aLookup[Who][2], Row, Col )
						
				aArray[Row][Col] = aArray[FromRow][FromCol]					### Copy From-Cell to To-Cell
				ClearSquare(FromRow, FromCol)								### Color From-Square	
				WhoseTurn(PickedPiece)
				RecordNewMove(PickedPiece, FromRow, FromCol, Row, Col)
				
				ByColor = "W"
				result = KingChecked( ByColor )							### Check id BlackKing Checked / CheckMate

					if result = True
						aButton[KingRow][KingCol] { setStyleSheet(C_ButtonCheckStyle) }		### Check Color	
					else
						RestoreSquareColor(KingRow, KingCol)
					ok						
				
				
				ByColor = "B"
				result = KingChecked( ByColor )							### Check id BlackKing Checked / CheckMate

					if result = True
						aButton[KingRow][KingCol] { setStyleSheet(C_ButtonCheckStyle) }		### Check Color	
					else
						RestoreSquareColor(KingRow, KingCol)
					ok		
				
			ok	
			
		
	ok
	
return	

###-------------------------------------------------------
### RESTORE SQUARE Color - Remove Yellow Highlight Select

Func RestoreSquareColor(FromRow, FromCol)

	if (FromRow + FromCol ) % 2
		aButton[FromRow][FromCol] { setStyleSheet(C_ButtonSecondStyle) }
	else
		aButton[FromRow][FromCol] { setStyleSheet(C_ButtonFirstStyle) }
	ok

return


###------------------------------------------
### CLEAR SQUARE - Back to EMPTY -- Put Color Back
	
Func ClearSquare(FromRow, FromCol)

	aArray[FromRow][FromCol] = "e"								### Empty From-Cell
	
	### Restore From-Square Solid Color
	if (FromRow + FromCol ) % 2
		aButton[FromRow][FromCol] {		
			oMine = new qpixmap2(0,0)
			setIcon(new qIcon(oMine))
			setStyleSheet(C_ButtonSecondStyle)	
		}		
	else
		aButton[FromRow][FromCol] {		
			oMine = new qpixmap2(0,0)
			setIcon(new qIcon(oMine))
			setStyleSheet(C_ButtonFirstStyle)	
		}
	ok		
			
return

###----------------------------------------------------------
### Whose Turn To Play Next. PickedPiece was the Last Played

Func WhoseTurn(PickedPiece)

	if PickedPiece[1] = "W"
		TurnColor = "Black"
		TitletInvalidMove { setStyleSheet("background-color:rgb(204,255,255)")}
	else
		TurnColor = "White"
		TitletInvalidMove { setStyleSheet("background-color:rgb(255,255,204)")}
	ok
	
	TitletInvalidMove.setText(TurnColor)
return			

###------------------------------------------
### Increase Moves Counter. Record Move

Func RecordNewMove(PickedPiece, FromRow, FromCol, Row, Col)

	nMoves++			
	FR = FromRow-2	FC = FromCol-2
	TR = Row-2		TC = Col-2
	TitletMoves.setText(" Move: "+ nMoves +" : "+ PickedPiece  +" "+ FR +"-"+ FC +" >> "+ TR +"-"+ TC )
	
	#Details = ""+ nMoves +" "+ PickedPiece +" "+ FR +" "+ FC +" "+ TR +" "+ TC
	 Details = ""+ nMoves +" "+ PickedPiece +" "+ FromRow +" "+ FromCol +" "+ Row +" "+ Col
	
	Add( recordArray, Details)
	See nl+nl  See recordArray	See nl+nl
	
return

		
###------------------------------------------
### VALID MOVE for ALL PIECES

Func ValidMove( Piece, oldH, oldV, h, v)

#SEE "Func ValidMove: "+ Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl

	FlagValidMove = 0
	
	if		Piece = "WR" or Piece = "BR"	result = ValidMoveRook(	 Piece, oldH, oldV, h, v)
		but Piece = "WN" or Piece = "BN"	result = ValidMoveKnight(Piece, oldH, oldV, h, v) 
		but Piece = "WB" or Piece = "BB"	result = ValidMoveBishop(Piece, oldH, oldV, h, v) 
		but Piece = "WQ" or Piece = "BQ"	result = ValidMoveQueen( Piece, oldH, oldV, h, v) 
		but Piece = "WK" or Piece = "BK"	result = ValidMoveKing(	 Piece, oldH, oldV, h, v) 
		but Piece = "WP"	result = ValidMovePawnWhite( Piece, oldH, oldV, h, v) 
		but Piece = "BP"	result = ValidMovePawnBlack( Piece, oldH, oldV, h, v)
		else See "Switch-Case: Failed: " Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl
	ok
	
	FlagValidMove = result
	
	###-------------------------------------------------------------- 
	### EnPassant is Cleared by ANY Piece Move. 
	### Only Pawn can Capture enPassant Pawn. Only on very next move
	
	if ( ((Piece != "WP") AND (Piece != "BP")) AND (FlagValidMove = True) AND (EnPassant = True) )
		#See "AnyPiece EnPassant Clear: "+ Piece +" "+ FlagValidMove +" "+ EnPassant +nl
		EnPassant = False
	ok

	
	
return FlagValidMove

###================================================
###================================================
###================================================
### VALID MOVE BY PIECES
###---------------------------------------
### KNIGHT


Func ValidMoveKnight(Piece, oldH, oldV, h, v)

	FlagValidMove = 0
	PossibleMove  = [[-2,-1],[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2]] 
	
	### Moves as an "L"	
	for i = 1 to 8
		if h = oldH + PossibleMove[i][1] AND v = oldV + PossibleMove[i][2]
			FlagValidMove = 1
			exit
		ok
	next
	
return FlagValidMove

###--------------------------------------------
### ROOK

Func ValidMoveRook(Piece, oldH, oldV, h, v)

	FlagValidMove = 0
	
	### Moves on SAME Row or SAME Column	
	if ( (h = oldH	AND v != OldV) OR (h != oldH AND v = OldV  ) )
		FlagValidMove = 1
	ok

return FlagValidMove

###--------------------------------------------
### BISHOP

Func ValidMoveBishop(Piece, oldH, oldV, h, v)

	FlagValidMove = 0
	
	### Moves as an "X". Equal change in Row AND Column. 4 directions
	if ( fabs(h - oldH) = fabs(v - OldV) )
		FlagValidMove = 1
	ok
			
return FlagValidMove

###---------------------------------------
### QUEEN

Func ValidMoveQueen(Piece, oldH, oldV, h, v)

	FlagValidMove = 0
		
	### Moves like Rook "+" and Bishop "X"
	###	  Horzontal						Vertical						Sideways-Bishop
	if (((h = oldH	AND v != OldV) OR ( h != oldH AND v = OldV ) ) OR ( fabs(h - oldH) = fabs(v - OldV) ) )
		FlagValidMove = 1
	ok
	
return FlagValidMove

###---------------------------------------
### KING

Func ValidMoveKing(Piece, oldH, oldV, h, v)
	
	FlagValidMove = 0
	
	### Move 1 Horzontal		 Vertical			  
	if (fabs(h - oldH) = 1) OR (fabs(v - oldV) = 1)		
		FlagValidMove = 1
		
	
	###----------------------------------------------------------------
	### WKing-CASTLE-RIGHT and Move Rook, Draw Rook and Emptied Square
	
	but (Piece = "WK" AND oldH = 10 AND	 v = 9 AND aArray[10][10] = "WR" AND aArray[10][8] = "e" AND aArray[10][9] = "e" )
	
		Who = Find(aLookup, "WR", 1)
		DrawImage( aLookup[Who][2], 10, 8 )
		ClearSquare(10, 10)

		aArray[10][10] = 'e'
		aArray[10][8]  = "WR"
		FlagValidMove  = 1

	### WKing-CASTLE-LEFT
	but (Piece = "WK" AND oldH = 10 AND	 v = 5 AND aArray[10][3] = "WR" AND aArray[10][4] = "e" AND aArray[10][5] = "e" AND aArray[10][6] = "e" )
	
		Who = Find(aLookup, "WR", 1)
		DrawImage( aLookup[Who][2], 10, 6 )
		ClearSquare(10, 3)

		aArray[10][3] = 'e'
		aArray[10][6] = "WR"
		FlagValidMove = 1
		
	###-------------------------------------=
	### BKing-CASTLE-RIGHT	
	
	but (Piece = "BK" AND oldH = 3 AND	v = 9 AND aArray[3][10] = "BR" AND aArray[3][8] = "e" AND aArray[3][9] = "e" )
	
		Who = Find(aLookup, "BR", 1)
		DrawImage( aLookup[Who][2], 3, 8 )
		ClearSquare(3, 10)

		aArray[3][10] = 'e'
		aArray[3][8]  = "BR"
		FlagValidMove = 1
		
	### BKing-CASTLE-LEFT
	but (Piece = "BK" AND oldH = 3 AND	v = 5 AND aArray[3][3] = "BR" AND aArray[3][4] = "e" AND aArray[3][5] = "e" AND aArray[3][6] = "e")
	
		Who = Find(aLookup, "BR", 1)
		DrawImage( aLookup[Who][2], 3, 6 )
		ClearSquare(3, 3)

		aArray[3][3]  = 'e'
		aArray[3][6]  = "BR"
		FlagValidMove = 1
				
	ok
	
	
return FlagValidMove

###---------------------------------------
### PAWN - WHITE

Func ValidMovePawnWhite(Piece, oldH, oldV, h, v)

		FlagValidMove = 0
		
		###---------------------------------
		### Forward 1 
		###	  To-Empty					  SameCol			  Up-By-1			   
		if ( ( aArray[h][v] = 'e' ) AND	 ( v = OldV )  AND	( oldH - h = 1 ) )	
			EnPassant = False
			FlagValidMove = 1
		ok
		
		###---------------------------------
		### Forward 2
		###	  To-Empty					   SameCol				  Up-By-2-From-Start
		if ( ( aArray[h][v] = 'e' ) AND ( aArray[h+1][v] = 'e' ) AND  ( v = OldV ) AND	( oldH = 9 AND h = 7 ) )	
			EnPassant = True
			EnPassantCol = v
			See "EnPassant: "+ EnPassant +" "+ PickedPiece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl 
			FlagValidMove = 1
		ok
		
		###---------------------------------
		### Eat Sideway
		if ( ( aArray[h][v] != 'e' ) AND ( oldH - h = 1 )  AND	( fabs(v - oldV) = 1 )	)
			EnPassant = False
			FlagValidMove = 1
		ok	

		###--------------------------------------
		### Eat EnPassant: BP oldH = 4 AND h = 6 
		###		WP move to h = 8  and Captures Empty h =5	
		
		if (	( EnPassant = True ) AND 
				( EnPassantCol = v ) AND
				( aArray[h][v] = 'e' ) AND 
				( oldH - h = 1 )  AND  
				( fabs(v - oldV) = 1 ) AND
				( PickedPiece = "WP" ) )
				
			See "Eat EnPassant: "+ EnPassant +" "+ PickedPiece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl
			
			aArray[h+1][v] = 'e'	### Remove BP internal array
			ClearSquare(h+1,v)		### Remove BP from Square 
			EnPassant = False		### Clear - EnPassant Pawn was captured
			FlagValidMove = 1
		ok	
		
		###--------------------------------------
		### Promote Pawn if on Other Side WP v=3
		
		if h = 3
			patternType = comboPromotePawn.currentText()
			if patternType = "Queen"	aArray[oldH][oldV] = "WQ"  PickedPiece = "WQ"			
			but patternType = "Rook"	aArray[oldH][oldV] = "WR"  PickedPiece = "WR"
			but patternType = "Bishop"	aArray[oldH][oldV] = "WB"  PickedPiece = "WB"				
			but patternType = "Knight"	aArray[oldH][oldV] = "WN"  PickedPiece = "WN"
			ok			
			
			MsgBox("Promoting:"+ nl +"From: White Pawn	To: "+ patternType )
		ok
		
	
return FlagValidMove

###---------------------------------------
### PAWN - BLACK

Func ValidMovePawnBlack(Piece, oldH, oldV, h, v)

		FlagValidMove = 0
		
		###----------------------------------------
		### Move straight ahead 1, but not eat ahead
		###								SameCol				 Down-By-1			  
		if ( ( aArray[h][v] = 'e' ) AND	 ( v = OldV )	 AND  (	oldH - h = -1 )	 ) 
			EnPassant = False
			FlagValidMove = 1
		ok
		
		###----------------------------------------
		### Move straight ahead 2, but not eat ahead
		###								SameCol				Down-By-2-From-Start
		if ( ( aArray[h][v] = 'e' ) AND ( aArray[h-1][v] = 'e' ) AND  ( v = OldV )	 AND  ( oldH = 4 AND h = 6	) ) 
			EnPassant = True
			EnPassantCol = v
			See "EnPassant: "+ EnPassant +" "+ PickedPiece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl 
			FlagValidMove = 1
		ok		
		
		###----------------------------------------
		### Eat sideway
		if ( ( aArray[h][v] != 'e' ) AND ( oldH - h = -1 )	AND	 ( fabs(v - oldV) = 1)	)
			EnPassant = False
			FlagValidMove = 1
		ok		
		
		###--------------------------------------
		### Eat EnPassant: WP oldH = 9 AND h = 7 
		###		BP move to h =8	 and captures h =7	

		if (	( EnPassant = True ) AND 
				( EnPassantCol = v ) AND
				( aArray[h][v] = 'e' ) AND 
				( oldH - h = -1 )  AND	
				( fabs(v - oldV) = 1 ) AND
				( PickedPiece = "BP" ) )
			  
			See "Eat EnPassant: "+ EnPassant +" "+ PickedPiece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl  
			
			aArray[h-1][v] = 'e'	### Remove WP internal array
			ClearSquare(h-1,v)		### Remove WP board
			EnPassant = False		### Clear - EnPassant Pawn was captured
			FlagValidMove = 1
		ok			
		
		###---------------------------------------
		### Promote Pawn if on Other Side BP v=10
		
		if h = 10			patternType = comboPromotePawn.currentText()
			if patternType = "Queen"	aArray[oldH][oldV] = "BQ"  PickedPiece = "BQ"				
			but patternType = "Rook"	aArray[oldH][oldV] = "BR"  PickedPiece = "BR"
			but patternType = "Bishop"	aArray[oldH][oldV] = "BB"  PickedPiece = "BB"			
			but patternType = "Knight"	aArray[oldH][oldV] = "BN"  PickedPiece = "BN"
			ok			
			
			MsgBox("Promoting:"+ nl +"From: Black Pawn	To: "+ patternType )
		ok
	
return FlagValidMove

###================================================
###================================================
###================================================
### CHECK: SKIPPED OVER PIECE - Only Knight can do this

Func SkipOverPieces(PickedPiece, FromRow, FromCol, Row, Col)

	#SEE nl +"Skip Func: "+ PickedPiece +" From "+ FromRow +"-"+ FromCol +" TO "+ Row +"-"+ Col +nl
	skipResult = 1	
	
	###-----------------------------------------
	### Knight 
	
	if PickedPiece = "WN" OR PickedPiece = "BN"
		#See "Move Knight - Ignore: "+nl
		skipResult = 0	
		return skipResult
	ok
	
	###---------------------------------------------------
	### Move 1 Square - Horz, Vert, Sideways: ALL Pieces
	
	if ( ((fabs(FromRow - Row) = 1) AND (fabs(FromCol - Col) = 0)) OR
		 ((fabs(FromRow - Row) = 0) AND (fabs(FromCol - Col) = 1)) OR
		 ((fabs(FromRow - Row) = 1) AND (fabs(FromCol - Col) = 1)) )
		
		#See "Moved 1 Square: "+ aArray[FromRow][FromCol] +" "+ FromRow +"-"+ FromCol +" TO "+ Row +"-"+ Col +nl
		skipResult = 0
		return skipResult
	ok
	
	###------------------------------------------------------
	### Move 2 or More Squares. Step plus/minus : ALL Pieces
	### WQ 10-6 to 7-6	Row-Col Skip over WP

	if	FromRow > Row  rowStep = -1	 but FromRow < Row	rowStep =  1  but FromRow = Row	 rowStep =	0 ok
		startRow = FromRow	+ rowStep
		destRow	 = Row		- rowStep
	
	if	FromCol > Col  colStep = -1	 but FromCol < Col	colStep =  1  but FromCol = Col	 colStep =	0  ok	
		startCol = FromCol	+ colStep
		destCol	 = Col		- colStep
	
		#SEE "CheckSkip: Row: "+ startRow +"=>"+ destrow +" Col: "+ startCol +"=>"+ destCol +nl
	
	###----------------------------------------------
	### Check PATH: Start to End
	
	skipResult = 0
	while (startRow != Row)	 OR ( startCol != Col )
		
		#See "WhileStart: Row: "+ startRow +"=>"+ Row +" Col: "+ startCol +"-"+ Col +nl
						
		if aArray[startRow][startCol] != 'e'
			#SEE " SKIP: "+ aArray[startRow][startCol] +" at "+ Row +"-"+ Col  
			#See " From: Row: "+ FromRow  +"=>"+ Row +" Col: "+ FromCol +"=>"+ Col 
			#See " Row: "+ startRow +"=>"+ Row +" by "+ rowStep 
			#See " Col: "+ startCol +"=>"+ Col +" by "+ colStep +nl 
			
			skipResult = 1
			return skipResult
		ok
		
		if startCol != Col	startCol += colStep	 ok	
		if startRow != Row	startRow += rowStep	 ok
		
	end

	#SEE "WhileEnd: skipResult: "+ skipresult +nl 
	
return skipResult

###=======================================================
###=======================================================
### KING IN CHECK ?
### Did Other Color Piece -- Check the KING
### Or Other Color Piece move out of the way to allow attack
### Or Same Color Piece move out of the way to allow check
### Return CheckedKing = True / False

Func KingChecked( ByColor )

	WKRow = 1	WKCol = 1 WKFound = False
	BKRow = 1	BKCol = 1 BKFound = False				
				
	### Find the Kings Square
	for h = 3 to 10
		for v = 3 to 10
			if aArray[h][v] = "WK"	WKRow = h  WKCol = v  WKFound = True ok			
			if aArray[h][v] = "BK"	BKRow = h  BKCol = v  BKFound = True ok			
		next
	next
	
	if WKFound = False
		MsgBox("WK captured !")
		return
	ok

	if BKFound = False
		MsgBox("BK captured !")
		return
	ok
	
	#See nl +"VerifyCheck: "+ ByColor +" WK: "+ WKRow +"-"+ WKCol +" BK: "+ BKRow +"-"+ BKCol +nl

	###---------------------------------------------------------------------
	### Check for Either King depending on Color of Piece Moved for Attack
	
	if ByColor = "B"	### BLACK Attacking White King
		King   = "WK"
		Queen  = "BQ"
		Rook   = "BR"
		Bishop = "BB"
		Knight = "BN"
		Pawn   = "BP"
		KingRow = WKRow		###	 White King under attack
		KingCol = WKCol
		SameColor  = "W"
		OtherColor = "B"
		OtherKing  = "BK"
	
	else				### WHITE Attacking Black King
		King   = "BK"
		Queen  = "WQ"
		Rook   = "WR"
		Bishop = "WB"
		Knight = "WN"
		Pawn   = "WP"	
		KingRow = BKRow		### Black King under attack
		KingCol = BKCol	
		SameColor  = "B"	
		OtherColor = "W"
		OtherKing  = "WK"
	ok
	
	###-----------------------------------------
	###-----------------------------------------
	
	CheckedKing = 0
	### Vertical UP Attack ?
		h = KingRow	  v = KingCol  
		
		for h = KingRow to 3 step -1
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Rook
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
		next
		#See "VU.QR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
	
	### Vertical DOWN Attack ?
		h = KingRow	  v = KingCol  
		
		for h = KingRow to 10 
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Rook
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
		next	
		#See "VD.QR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl

	###---------------------------------
	
	### Horizontal LEFT Attack ?
		h = KingRow	  v = KingCol  
		
		for v = KingCol to 3 step -1
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Rook
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
		next
		#See "HL.QR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
		
	### Horizontal RIGHT Attack ?
		h = KingRow	  v = KingCol  
		
		for v = KingCol to 10 
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Rook
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
		next		
		#See "HR.QR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
		
	###---------------------------------
	
####

	### Diagonal UP LEFT Attack ?
		h = KingRow	  v = KingCol  
		
		while ((h != 3) OR (v != 3))
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Bishop
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok

			if h != 3  h -= 1 ok 
			if v != 3  v -= 1 ok 
		end
		#See "DULQB Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
		
	### Diagonal UP RIGHT Attack ?
		h = KingRow	  v = KingCol  
		
		while ((h != 3) OR (v != 10))
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Bishop
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
					
			if h != 3	h -= 1 ok 
			if v != 10	v += 1 ok
		end	
		#See "DURQB Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
		
	###---------------------------------
	
	### Diagonal DOWN LEFT Attack ?
		h = KingRow	  v = KingCol  
		
		while ((h != 10) OR (v != 3))
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Bishop
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok
			
			if h != 10	h += 1 ok 
			if v != 3	v -= 1 ok
		end
		#See "DDLQB Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl
		
	### Diagonal DOWN RIGHT Attack ?
		h = KingRow	  v = KingCol  
		
		while ((h != 10) OR (v != 10))
			Piece = aArray[h][v]
			if Piece = Queen OR Piece = Bishop
				CheckedKing += 1
				exit
			but Piece[1] = SameColor AND Piece != King
				exit
			but Piece[1] = OtherColor
				exit
			ok 
			
			if h != 10	h += 1 ok 
			if v != 10	v += 1 ok
		end
		#See "DDRQB Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl

	
	###------------------------------
	### KNIGHT L shape captures

	h = KingRow	 V = KingCol
	PossibleMove  = [[-2,-1],[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2]] 
	
	### Moves as an "L"	
	for i = 1 to 8
		Piece = aArray[KingRow + PossibleMove[i][1]][KingCol + PossibleMove[i][2]]
		if Piece = Knight
			CheckedKing += 1
			exit
		but Piece[1] = SameColor AND Piece != King
			### Test all 8 possible
		but Piece[1] = OtherColor
			### Test all 8 possible
		ok
	next
	#See "L..N. Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ Piece +nl


		
	###---------------------------------
	### Black Pawn Diagonal
	
		h = KingRow	  v = KingCol  
		
		if (aArray[h-1][v-1] = Pawn) 
			CheckedKing += 1
		ok
		#See "BPLPL Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ aArray[h-1][v-1] +nl
		
		if (aArray[h-1][v+1] = Pawn)
			CheckedKing += 1
		ok
		#See "BPRPR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ aArray[h-1][v+1] +nl
		
	### White Pawn Diagonal
		h = KingRow	  v = KingCol  
		
		if (aArray[h+1][v-1] = Pawn) 
			CheckedKing += 1
		ok
		#See "BPLPL Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ aArray[h+1][v-1] +nl
		
		if (aArray[h+1][v+1] = Pawn)
			CheckedKing += 1
		ok
		#See "BPRPR Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ aArray[h+1][v+1] +nl		
		
	###-------------------------------------------
	### Black King Vertical Horizontal	Diagonal
	
		h = KingRow	  v = KingCol  
		
		for h = KingRow -1 to KingRow +1
			for v = KingCol -1 to KingCol +1
				if (aArray[h][v] = OtherKing)
					CheckedKing += 1				
					exit 2
				ok
				
			next
		next
		#See "KngKK Checked: "+ CheckedKing +" "+ h +"-"+ v +" by "+ aArray[h][v] +nl
		
			
	###---------------------------------------------
	### Called 2 for Each Color King.
	### Color King Square Red if either King in Check
	### Do NOT Clear unless BOTH Kings ok
	### WhiteKingIsChecked = False	set BEFORE calling KingChecked(ByColor)
	### BlackKingIsChecked = False	set BEFORE calling KingChecked(ByColor)	
	
	#See "King is Checked ?: "+ King +" "+ CheckedKing +nl
	
return CheckedKing


###------------------------------------------------
### KING IN Stalemate ?
### Can King Move to any Surrounding Square
### Or a Piece Block the Attack

###------------------------------------------------
### KING Move  ?
### Destination Not Under Attack




###------------------------------------------------
### Message Box 
	
Func MsgBox(cText) 
	mb = new qMessageBox(workWidget) 
		{
			setWindowTitle('Chess')
			setText(cText)
			setStandardButtons(QMessageBox_OK) 
			result = exec()
			See "MsgBox Result: "+ result +nl
		}
return

###--------------------------------
