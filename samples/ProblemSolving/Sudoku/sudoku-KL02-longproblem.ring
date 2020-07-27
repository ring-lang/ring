// sudoku with recursion & backtracking
// quelle: kennyledet github
// transscript lua2ring: 21.05.2019 (nestor)
// adjusted/extended: 22.05.2019 (bert mariani)

sudoku = [
  [9,0,0, 1,0,0, 0,0,5],
  [0,0,5, 0,9,0, 2,0,1],
  [8,0,0, 0,4,0, 0,0,0],

  [0,0,0, 0,8,0, 0,0,0],
  [0,0,0, 7,0,0, 0,0,0],
  [0,0,0, 0,2,6, 0,0,9],

  [2,0,0, 3,0,0, 0,0,6],
  [0,0,0, 2,0,0, 9,0,0],
  [0,0,1, 9,0,4, 5,7,0]
]


aFloorMap = [1,1,1,4,4,4,7,7,7]

? "Input:"
prnt(sudoku)        		// vorlage

// -----------------------------------------------------    main
?  "Start: " +Time()
solve(sudoku)       		// finde loesung 
?  "End: " +Time()		//(+/- 20 sec)
// -----------------------------------------------------
? nl+nl+"Output:"       	// resultat
prnt(sudoku)        		// show result

func prnt(sudoku)
  See nl+"|-------------------------|"+nl
  for row = 1 to 9
    See "|"
    for column = 1 to 9 
        see " "+ sudoku[row][column]		
	if column % 3 = 0  See " | "  ok
    next
    if row % 3 = 0  See nl+"|-------------------------|"  ok
    ? " "
  next
return

//------------------------------------------------------------
// Given a (row, column) location on the sudoku grid
// identifies the corresponding 3x3 box and checks if
// num exists in the:                                  box

func boxHasNotNum(sudoku, row, column, num)
    row = aFloorMap[row]
    column = aFloorMap[column]
 
    for rwOffset = 0 to 2 
        for clOffset = 0 to 2 
            if sudoku[row + rwOffset][column + clOffset] = num return false ok
        next
    next
    
return true

//------------------------------------------------------
// Checks if num can be assigned to sudoku[row][column]
// without breaking sudoku rules.

func isLegit(sudoku, row, column, num)
    return ! find(sudoku[row], num)    and
           ! find(sudoku,num,column)   and
           boxHasNotNum(sudoku, row, column, num) 


//-----------------------------------------------------------------
// Checks if the actual problem is solved. If not, returns false, 
// plus the location on the first unassigned cell found.

func isSolved(sudoku)
    for row = 1 to 9 
	column = find(sudoku[row],0)
	if column 
                    return [ false , row, column ] 
        ok
    next  
    return [true, row, column]

//-----------------------------------------------------------------
// Sudoku solving via backtracking and recursion
// sudoku  : a 2-dimensional grid of numbers (0-9)
//           0 matches unknown values to be found.
// returns : true, if a solution was found,
//           false otherwise.

func solve(sudoku)
    solved      = isSolved(sudoku)             // true / false 2te: row   3te: col 
        solv_       = solved[1] 
        row         = solved[2]                // problem on last row/col in sudoku
        column      = solved[3]

    if solv_ 
        See nl+nl+"SUDOKU is SOLVED: "+nl
        return true 
    ok

    for num = 1 to 9
        if isLegit(sudoku, row, column, num) 
                sudoku[row][column] = num
                
            if solve(sudoku)
                    return true 
            ok  
                sudoku[row][column] = 0
        ok 
    next 
    
return false
