// peg-tri-14V2.ring	(from: myPegSoliTri0Phix.ring)
//quell: demo\rosetta\IQpuzzle.exw		(PHIX)
// 7.5.2020 - nestor kuka / bert mariani

Load "stdlib.ring"

// PlayBoard - Start Formation:
// Pos     0        1         2         3         4    45
// Pos     123456789012345678901234567890123456789012345
start  =  "----0-------1-1-----1-1-1---1-1-1-1-1-1-1-1-1"

/*
for better visualisation:
----0----     #         05             
---1-1---     #       13  15      jump by -8  -10  +8  +10  Target -16 +16  -20 +20
--1-1-1--     #      21 23 25     jump by -2  +2            Target -4  +4
-1-1-1-1-     #    29 31 33 35
1-1-1-1-1"    #  37 39 41 43 45
*/

moves  = [-10,  -8, 2, 10  ,8 , -2]   	// Jump Over possible directions
n      = 9                              // line size ( +1 because: nl)
countB = 0                              // Actual '1' on PegBoard

See "STARTED"+nl
show_b(start)                           // show start formation
See  "--------------------"+nl 

solve(start, 14)                        // <<<=== solve puzzle

? nl+" Number of attempts: "+ countB
? nl+"FINISHED"+nl

// -------------------------------------------------- func show_board
func show_b(start) 
   ? "" ;  ? ""							// 2 blank lines
   for j = 1 to 5						// total lines
      for i = 1 to 9					// total columns
         see start[(j-1)*9 +i] 
      next
         See  nl
   next

// ------------------------------------------------------ func solve
func solve(board, left) 

    if left = 1 ; return "" ; ok

    // test all pos in the board:
    for pos = 1 to len(board) 		 	// to boardsize       
   
        if board[pos] = '1'

           // Try all directions:         
            for j = 1 to len(moves)		//to length of Moves[]
                mj   = moves[j]         
                over = pos + mj           
                tgt  = pos + ( 2 * mj )     
				// IF - formatted for better readability:
				if  ( tgt >= 1          &&      
					tgt <= len(start) 	&&
					board[tgt]  = '0'  	&&
					board[over] = '1' )
					// then move
					board[pos]  = '0'
					board[over] = '0'
					board[tgt]  = '1' 

					countB++                     // number of tries
					show_b(board)                // After move is made show board
					
					See "--------------------- Pos: "+ pos +" CountB: "+ countB +nl
					See "Step Control (Press Enter): "  Give nNum1

					res = solve(board, left-1)	//  <--<< RECURSION
					if len(res) != 4 
					   return [board, res] 		// 2 param. return
					ok
					// unmove
					board[pos]  = '1'
					board[over] = '1'
					board[tgt]  = '0'                  
				ok // if tgt         
			next // for dir      
		ok // if board  
	next // for pos
    //See nl+"Oops:"+ nl      // No Valid Move possible
return "OOPS"
   
// --------------------------------------------------------- end pgm

/*
Solution:
----0----
---0-0---
--0-0-0--
-0-0-0-0-
0-0-1-0-0

peg tri game online:
https://www.mathsisfun.com/games/triangle-peg-solitaire/index.html
*/
