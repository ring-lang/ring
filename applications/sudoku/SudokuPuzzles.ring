### AA-Sudoku.ring will LOAD this file
### load "SudokuPuzzles.ring"	
###
### SudpkuPuzzles.ring"
###----------------------------------------

###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------



	
/*
	### Sudoku
Template = 	[ 
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
	
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
	
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0] ]   
*/

	//Easy NewYork Times
P001 =	[
    [0,6,0, 0,0,0, 0,0,7],
    [1,0,7, 0,2,9, 0,0,0],
    [3,2,9, 0,0,0, 8,0,0],
	
    [0,0,0, 1,0,0, 2,4,0],
    [6,7,8, 0,4,0, 1,9,5],
    [0,1,2, 0,0,6, 0,0,0],
	
    [0,0,6, 0,0,1, 3,7,9],
    [0,0,0, 6,8,0, 4,0,2],
    [7,0,0, 0,0,0, 0,8,0] ]

	//Easy NewYork Times
P002 = 	[ 
    [4,0,0, 6,8,9, 2,0,0],
    [3,8,0, 4,0,0, 6,0,0],
    [2,0,1, 3,0,0, 8,0,0],
	
    [0,0,8, 0,6,7, 0,3,2],
    [0,5,6, 0,9,0, 0,8,0],
    [0,3,0, 8,5,0, 0,9,6],
	
    [6,0,0, 0,0,0, 1,7,5],
    [0,0,4, 0,2,1, 0,0,8],
    [8,0,7, 0,0,6, 0,0,0] ]  	
	
	//https://sudoku.game/medium
P003 = 	[ 
     
    [0,0,3, 0,0,0, 9,0,1],
    [0,0,4, 6,0,0, 0,0,0],
    [6,0,0, 7,1,0, 3,0,0],
	
    [8,0,0, 0,0,0, 5,0,0],
    [0,0,1, 8,0,0, 0,4,3],
    [0,0,0, 3,0,0, 0,0,8],
	
    [5,0,0, 0,0,9, 0,0,0],
    [4,0,0, 0,0,6, 0,0,0],
    [0,0,9, 5,0,0, 4,7,0] ]    	
 
	//https://sudoku.game/medium
P004 = 	[ 
    [0,0,4, 0,6,0, 0,0,0],
    [0,0,0, 0,0,3, 0,0,0],
    [0,6,0, 5,1,4, 0,2,0],
	
    [4,9,0, 0,0,0, 0,0,8],
    [0,0,0, 0,0,0, 6,5,0],
    [0,0,0, 0,0,2, 7,3,0],
	
    [6,1,0, 7,0,0, 0,0,0],
    [0,3,0, 6,8,0, 0,0,0],
    [0,0,9, 0,0,0, 1,0,0] ]  	
	
###===========
		
		//Hard NewYork Times
PM3Hard1 = 	[ 
    [7,0,8, 0,0,4, 0,9,0],
    [0,6,0, 0,0,0, 2,0,0],
    [1,4,0, 0,0,6, 0,0,7],
	
    [0,7,0, 0,0,0, 0,0,4],
    [5,0,0, 0,0,0, 0,2,0],
    [0,0,0, 0,5,0, 9,3,0],
	
    [0,8,6, 4,0,3, 1,0,0],
    [0,0,0, 0,6,1, 0,0,0],
    [0,0,0, 0,0,0, 0,0,3] ]    
	
		//https://www.sudokukingdom.com/
PM3Hard2 = 	[ 
    [0,0,0, 0,0,9, 0,0,8],
    [0,0,1, 7,0,0, 0,0,0],
    [0,2,0, 0,8,0, 7,0,0],
	
    [0,0,0, 5,9,0, 8,0,0],
    [5,0,0, 0,0,7, 0,4,0],
    [2,0,6, 0,0,0, 0,7,1],
	
    [0,3,0, 0,1,0, 2,0,0],
    [0,0,4, 6,0,0, 0,0,3],
    [0,5,0, 0,0,8, 0,1,7] ]   

	//https://www.sudokukingdom.com/
PM3Hard3 = 	[ 
    [2,9,0, 3,0,0, 0,0,0],
    [0,0,1, 0,0,0, 6,0,3],
    [0,0,0, 4,0,1, 0,2,0],
	
    [0,0,4, 0,0,0, 8,1,0],
    [0,8,0, 0,0,0, 0,7,2],
    [0,6,0, 0,0,2, 0,0,0],
	
    [8,0,0, 7,5,0, 0,9,0],
    [4,0,2, 0,0,9, 5,0,0],
    [3,0,0, 0,0,0, 0,0,1] ]   


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

Board = P001
	//See "FuncWhichPuzzle: "+ puzzleName +nl
	
	if	puzzleName = "BoardLayout"	 Board =  aArray
	
		but puzzleName = "P001"	 Board =  P001    TitletInvalidMove.setText(" Easy" )
		but puzzleName = "P002"	 Board =  P002    TitletInvalidMove.setText(" Easy" )
		but puzzleName = "P003"	 Board =  P003	  TitletInvalidMove.setText(" Medium" )
		
		but puzzleName = "P004"	 Board =  P004	  TitletInvalidMove.setText(" Medium" )
		
		but puzzleName = "PM3Hard1"	 Board =  PM3Hard1    TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM3Hard2"	 Board =  PM3Hard2    TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM3Hard3"	 Board =  PM3Hard3    TitletInvalidMove.setText(" Very Hard" )
	ok		
	
	//See "WhichPuzzle Selected: "+ puzzleName +nl
	
	
return Board		