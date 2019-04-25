### AA-Checkerboard.ring will LOAD this file
### load "CheckerPuzzles.ring"	
###
### CheckerPuzzles.ring"
###----------------------------------------

###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------



	
/*
	### Checkers plays only on dark squares
Template = [ 
	["..","ee","..","ee","..","ee","..","ee"],
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","ee","..","ee","..","ee","..","ee"],  
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","ee","..","ee","..","ee","..","ee"],
    ["ee","..","ee","..","ee","..","ee",".."],  
    ["..","ee","..","ee","..","ee","..","ee"],
    ["ee","..","ee","..","ee","..","ee",".."] ]	
*/

P001 =	[
	["..","ee","..","ee","..","WP","..","ee"],
    ["ee","..","WP","..","ee","..","BP",".."],
    ["..","WP","..","ee","..","ee","..","BP"],  
    ["WP","..","WP","..","ee","..","ee",".."],
    ["..","ee","..","WP","..","ee","..","WP"],
    ["BP","..","ee","..","BP","..","ee",".."],  
    ["..","ee","..","ee","..","ee","..","WP"],
    ["ee","..","BP","..","BP","..","BP",".."] ]

P002 =	[
	["..","ee","..","WP","..","WP","..","ee"],
    ["ee","..","ee","..","WP","..","ee",".."],
    ["..","BP","..","ee","..","ee","..","ee"],  
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","WP","..","ee","..","ee","..","BP"],
    ["ee","..","ee","..","ee","..","ee",".."],  
    ["..","ee","..","WP","..","ee","..","ee"],
    ["ee","..","BP","..","BP","..","ee",".."] ]		
	
P003 =	[
	["..","ee","..","ee","..","WP","..","ee"],
    ["ee","..","WP","..","ee","..","BP",".."],
    ["..","WP","..","ee","..","ee","..","BP"],  
    ["ee","..","WP","..","ee","..","ee",".."],
    ["..","ee","..","ee","..","ee","..","WP"],
    ["ee","..","WP","..","ee","..","ee",".."],  
    ["..","ee","..","BP","..","WP","..","WP"],
    ["ee","..","ee","..","BP","..","BP",".."] ]	
 
P004 =	[
	["..","ee","..","WP","..","ee","..","ee"],
    ["ee","..","ee","..","WP","..","WP",".."],
    ["..","WP","..","ee","..","ee","..","ee"],  
    ["ee","..","ee","..","ee","..","WP",".."],
    ["..","WP","..","ee","..","BP","..","BP"],
    ["ee","..","ee","..","ee","..","ee",".."],  
    ["..","ee","..","WP","..","ee","..","ee"],
    ["ee","..","BP","..","BP","..","ee",".."] ]		
###===========
		
PM3Hard1 = [
	["..","ee","..","ee","..","WP","..","ee"],
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","ee","..","BP","..","ee","..","ee"],  
    ["ee","..","ee","..","BK","..","BK",".."],
    ["..","WP","..","ee","..","ee","..","WP"],
    ["ee","..","WP","..","ee","..","ee",".."],  
    ["..","ee","..","WK","..","ee","..","ee"],
    ["BP","..","ee","..","WK","..","ee",".."] ]
		
PM3Hard2 = [
	["..","ee","..","ee","..","ee","..","ee"],
    ["ee","..","ee","..","ee","..","WP",".."],
    ["..","WP","..","BP","..","ee","..","WP"],  
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","BK","..","ee","..","ee","..","WP"],
    ["WP","..","ee","..","ee","..","ee",".."],  
    ["..","WK","..","ee","..","BP","..","BP"],
    ["ee","..","BP","..","BP","..","ee",".."] ]


PM3Hard3 = [
	["..","ee","..","ee","..","WP","..","ee"],
    ["ee","..","ee","..","ee","..","WP",".."],
    ["..","ee","..","ee","..","ee","..","ee"],  
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","BP","..","BK","..","BP","..","ee"],
    ["ee","..","ee","..","BP","..","ee",".."],  
    ["..","WK","..","ee","..","WK","..","ee"],
    ["ee","..","ee","..","ee","..","BP",".."] ]


###======================================================
###======================================================


###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------

PuzzleList = [	"BoardLayout",
				"P001","P002","P003","P004",
				"PM3Hard1","PM3Hard2","PM3Hard3"
			 ]
	

###------------------------------------------------

Func WhichPuzzle(puzzleName)

	#See "FuncWhichPuzzle: "+ puzzleName +nl
	
	if	puzzleName = "BoardLayout"	 Board =  BoardLayout
	
	but puzzleName = "P001"	 Board =  P001  TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win 4" )
	but puzzleName = "P002"	 Board =  P002  TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win 1" )
	but puzzleName = "P003"	 Board =  P003	TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win 2" )
	
	but puzzleName = "P004"	 Board =  P004	TurnColor = "B"  TitletInvalidMove.setText(" Black: Test" )
	
	but puzzleName = "PM3Hard1"	 Board =  PM3Hard1  TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win Hard 4" )
	but puzzleName = "PM3Hard2"	 Board =  PM3Hard2  TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win Hard 4" )
	but puzzleName = "PM3Hard3"	 Board =  PM3Hard3  TurnColor = "B"  TitletInvalidMove.setText(" Black: To Win Hard 4" )
	ok		
return Board		