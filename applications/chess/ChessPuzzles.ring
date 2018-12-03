### AA-ChessBoard.ring will LOAD this file
### load "ChessPuzzles.ring"	
###
### ChessPuzzles.ring"
###----------------------------------------

###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------



	
/*
Template = [
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"]]
*/

P001 =	[
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["BP","ee","ee","ee","ee","ee","ee","ee"],
		["BK","BP","WP","ee","ee","ee","ee","ee"],
		["BQ","BR","BP","ee","BB","ee","ee","ee"],
		["BR","BP","WP","ee","ee","BB","ee","ee"],
		["BP","WP","ee","ee","ee","ee","BB","ee"],
		["WP","ee","ee","ee","WK","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"]]		

P002 =	[
		["ee","ee","ee","ee","ee","ee","BQ","BK"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","WP","ee","BP"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","WQ","WP"],
		["ee","ee","ee","ee","ee","WP","WP","ee"],
		["ee","ee","ee","ee","WR","ee","WK","ee"]]		
	
P003 =	[
		["WQ","ee","BN","BR","BR","BK","ee","ee"],
		["ee","ee","ee","ee","ee","ee","BP","BP"],
		["ee","ee","ee","ee","ee","BP","BB","BB"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","WB","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","WB","ee","WQ","ee","ee"],
		["ee","ee","ee","ee","WR","WK","ee","ee"]]	
 
P004 =	[
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","BP","ee"],
		["ee","ee","ee","ee","ee","ee","ee","BK"],
		["ee","ee","ee","BR","ee","ee","WN","WP"],
		["WB","ee","ee","ee","ee","ee","WP","WK"],
		["ee","ee","BB","BR","ee","WR","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"]] 
		
P005 =	[
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","WK","ee","ee","ee","ee"],
		["ee","ee","WR","ee","WP","ee","ee","ee"],
		["ee","WP","ee","BK","BR","ee","ee","ee"],
		["ee","ee","ee","WN","BP","BB","ee","ee"],
		["ee","ee","ee","ee","WP","ee","ee","ee"],
		["ee","ee","ee","ee","ee","ee","ee","ee"],
		["ee","ee","ee","ee","ee","WN","ee","ee"]]

		
###======================================================
###======================================================


###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------

PuzzleList = [	"BoardLayout",
				"P001",
				"P002",
				"P003",
				"P004",
				"P005"			
			 ]
	

###------------------------------------------------

Func WhichPuzzle(puzzleName)

	#See "FuncWhichPuzzle: "+ puzzleName +nl
	
	if	puzzleName = "BoardLayout"	 Board =  BoardLayout
	but puzzleName = "P001"	 Board =  P001  TurnColor = "W"  TitletInvalidMove.setText(" White: Draw " )
	but puzzleName = "P002"	 Board =  P002  TurnColor = "W"  TitletInvalidMove.setText(" White: Mate in 2 " )
	but puzzleName = "P003"	 Board =  P003	TurnColor = "W"  TitletInvalidMove.setText(" White: Mate in 2 " )
	but puzzleName = "P004"	 Board =  P004	TurnColor = "W"  TitletInvalidMove.setText(" White: Mate in 2 " )	
	but puzzleName = "P005"	 Board =  P005  TurnColor = "W"  TitletInvalidMove.setText(" White: Mate in 2 " )
	ok		
return Board		