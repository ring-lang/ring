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

	// https://www.websudoku.com/images/example-steps.html
PM4Hard1	 = 	[ 
    [0,0,0, 0,0,0, 6,8,0],
    [0,0,0, 0,7,3, 0,0,9],
    [3,0,9, 0,0,0, 0,4,5],
	
    [4,9,0, 0,0,0, 0,0,0],
    [8,0,3, 0,5,0, 9,0,2],
    [0,0,0, 0,0,0, 0,3,6],
	
    [9,6,0, 0,0,0, 3,0,8],
    [7,0,0, 6,8,0, 0,0,0],
    [0,2,8, 0,0,0, 0,0,0] ]   

	
	// https://www.wikihow.com/Solve-a-Sudoku
PM5Hard1 = 	[ 
    [0,3,0, 0,7,0, 5,0,0],
    [0,2,1, 0,0,0, 0,6,9],
    [5,4,0, 0,0,0, 1,0,0],
	
    [0,0,0, 9,0,0, 0,0,0],
    [8,9,4, 2,6,3, 7,1,5],
    [0,0,0, 0,0,7, 0,0,0],
	
    [0,0,3, 0,0,0, 0,2,1],
    [1,7,0, 0,0,6, 4,8,0],
    [0,0,9, 0,3,0, 0,5,0] ]   


PM5Med1 = 	[ 
    [6,0,5, 0,4,0, 0,7,0],
    [0,0,2, 0,0,0, 0,6,0],
    [0,0,7, 8,0,0, 0,3,2],
	
    [4,0,6, 3,9,0, 0,0,0],
    [0,8,0, 0,2,0, 0,9,0],
    [0,0,0, 0,5,4, 2,0,6],
	
    [3,7,0, 0,0,5, 6,0,0],
    [0,5,0, 0,0,0, 8,0,0],
    [0,6,0, 0,8,0, 1,0,3] ]   


PM5Easy1 = 	[ 
    [0,3,4, 0,0,7, 0,0,8],
    [0,8,0, 0,6,5, 0,0,0],
    [0,0,0, 3,0,0, 0,7,0],
	
    [2,0,0, 0,0,0, 7,0,0],
    [7,1,0, 0,4,0, 0,9,6],
    [0,0,5, 0,0,0, 0,0,1],
	
    [0,5,0, 0,0,2, 0,0,0],
    [0,0,0, 1,7,0, 0,6,0],
    [6,0,0, 9,0,0, 4,3,0] ]   	
	
	
PM5Nestor = [
	[0,0,5, 3,0,0, 0,0,0],
	[8,0,0, 0,0,0, 0,2,0],
	[0,7,0, 0,1,0, 5,0,0],

	[4,0,0, 0,0,5, 3,0,0],
	[0,1,0, 0,7,0, 0,0,6],
	[0,0,3, 2,0,0, 0,8,0],

	[0,6,0, 5,0,0, 0,0,9],
	[0,0,4, 0,0,0, 0,3,0],
	[0,0,0, 0,0,9, 7,0,0] ]
	
PM5NestorH = [	
		[9,0,0, 1,0,0, 0,0,5],
        [0,0,5, 0,9,0, 2,0,1],
        [8,0,0, 0,4,0, 0,0,0],

        [0,0,0, 0,8,0, 0,0,0],
        [0,0,0, 7,0,0, 0,0,0],
        [0,0,0, 0,2,6, 0,0,9],

        [2,0,0, 3,0,0, 0,0,6],
        [0,0,0, 2,0,0, 9,0,0],
        [0,0,1, 9,0,4, 5,7,0] ]	

		
		// http://pi.math.cornell.edu/~mec/Summer2009/meerkamp/Site/Solving_any_Sudoku_I.html

PFiendish1 = [ 
    [0,0,6, 0,0,8, 5,0,0],
    [0,0,0, 0,7,0, 6,1,3],
    [0,0,0, 0,0,0, 0,0,9],
	
    [0,0,0, 0,9,0, 0,0,1],
    [0,0,1, 0,0,0, 8,0,0],
    [4,0,0, 5,3,0, 0,0,0],
	
    [1,0,7, 0,5,3, 0,0,0],
    [0,5,0, 0,6,4, 0,0,0],
    [3,0,0, 1,0,0, 0,6,0] ]   
	
	// https://www.youtube.com/watch?v=O5Gj0cG6O2g&feature=youtu.be
PIsreal = 	[ 
    [2,8,0, 0,0,0, 7,0,0],
    [4,5,0, 0,8,0, 0,0,0],
    [0,0,0, 0,0,4, 0,0,0],
	
    [5,0,0, 0,0,0, 0,0,0],
    [9,0,0, 0,0,6, 3,0,0],
    [8,0,6, 0,0,0, 1,2,0],
	
    [0,0,0, 0,9,5, 0,0,6],
    [0,0,0, 0,2,3, 0,0,1],
    [6,0,0, 8,0,1, 0,5,0] ]  	
	
	// https://www.youtube.com/watch?v=-ZZFEgCQsvA&t=305s
PHardest1 = 	[ 
    [0,0,1, 0,6,0, 0,5,9],
    [0,0,0, 0,0,3, 0,2,0],
    [0,6,0, 0,8,0, 0,0,0],
	
    [4,0,0, 0,0,0, 5,0,0],
    [0,2,0, 0,0,0, 0,0,0],
    [0,7,0, 2,0,0, 4,8,0],
	
    [8,0,0, 0,0,0, 9,0,5],
    [7,0,0, 6,0,9, 0,3,0],
    [0,0,5, 0,0,0, 0,4,0] ]  

	// https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html
PEverest = 	[ 
    [8,0,0, 0,0,0, 0,0,0],
    [0,0,3, 6,0,0, 0,0,0],
    [0,7,0, 0,9,0, 2,0,0],
	
    [0,5,0, 0,0,7, 0,0,0],
    [0,0,0, 0,4,5, 7,0,0],
    [0,0,0, 1,0,0, 0,3,0],
	
    [0,0,1, 0,0,0, 0,6,8],
    [0,0,8, 5,0,0, 0,1,0],
    [0,9,0, 0,0,0, 4,0,0] ]  	
	
	
###======================================================
###======================================================


###----------------------------------------------------
### Which Puzzle in ComboBox, Return Puzzle Array Name	
### Func is a BOTTOM of this file
### UPDATE it when adding NEW Puzzle
###----------------------------------------------------

PuzzleList = [	
				"SelectPuzzle","EnterYourOwn","P001","P002","P003","P004",
				"PM3Hard1","PM3Hard2","PM3Hard3","PM4Hard1",
				"PM5Easy1","PM5Med1","PM5Hard1","PM5Nestor","PM5NestorH",
				"PFiendish1","PIsreal","PHardest1","PEverest"
			 ]
	

###------------------------------------------------

Func WhichPuzzle(puzzleName)

Board = P001
	//See "FuncWhichPuzzle: "+ puzzleName +nl
	
	if	    puzzleName = "P001"			Board =  P001    	TitletInvalidMove.setText(" Easy" )
	
		but puzzleName = "EnterYourOwn"	Board =  zeroArray	
		but puzzleName = "P001"	 		Board =  P001    	TitletInvalidMove.setText(" Easy" )
		but puzzleName = "P002"	 		Board =  P002    	TitletInvalidMove.setText(" Easy" )
		but puzzleName = "P003"	 		Board =  P003	  	TitletInvalidMove.setText(" Medium" )
		
		but puzzleName = "P004"	 		Board =  P004	  	TitletInvalidMove.setText(" Medium" )
		
		but puzzleName = "PM3Hard1"	 	Board =  PM3Hard1   TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM3Hard2"	 	Board =  PM3Hard2   TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM3Hard3"	 	Board =  PM3Hard3   TitletInvalidMove.setText(" Very Hard" )
		but puzzleName = "PM4Hard1"	 	Board =  PM4Hard1   TitletInvalidMove.setText(" Very Hard" )
		
		but puzzleName = "PM5Easy1"	  	Board =  PM5Easy1   TitletInvalidMove.setText(" Easy" )
		but puzzleName = "PM5Med1" 	   Board =  PM5Med1    TitletInvalidMove.setText(" Medium" )
		but puzzleName = "PM5Hard1"	  	Board =  PM5Hard1   TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM5Nestor"  	Board =  PM5Nestor  TitletInvalidMove.setText(" Hard" )
		but puzzleName = "PM5NestorH"    Board =  PM5NestorH TitletInvalidMove.setText(" VeryHard" )
		
		but puzzleName = "PFiendish1" 	Board =  PFiendish1 TitletInvalidMove.setText(" Fiendish" )
		but puzzleName = "PIsreal"    	Board =  PIsreal    TitletInvalidMove.setText(" Fiendish" )
		but puzzleName = "PHardest1"  	Board =  PHardest1  TitletInvalidMove.setText(" Fiendish" )
		but puzzleName = "PEverest"  	   Board =  PEverest   TitletInvalidMove.setText(" WorldHardest" )
	ok		
	
	//See "WhichPuzzle Selected: "+ puzzleName +nl
	
	
return Board		