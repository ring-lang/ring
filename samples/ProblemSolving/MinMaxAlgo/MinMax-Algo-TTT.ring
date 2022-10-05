// MinMax Algo using Tic-Tac-Toe as example play
// Use Array of One Dimension -- Board[9], TicTacToes is 3x3
// Can be beat.

Player   = 'X' 
Opponent = 'O'


//==================================================  
// MAIN - Driver CODE 

// Use Array of One Dimension -- Board[9]
// Use 'X'  'O'  '_'
// Create the PAttern to be tested.

Func main()

    // Board = [ [ 'X', 'O', 'X' ],
    //           [ 'O', 'O', 'X' ],
    //           [ '_', '_', '_' ] ]
              
    //------------------------------------------------
    //  Evaluate this Position. Recommend Optimal Move

    Board = [ 'X','O','X','O','O','X','_','_','_' ]
              
    Player   = 'X'   // Turn First
    Opponent = 'O'   // Turn Second

    See "Start Board:" +nl
    DrawBoard(Board)
    
    bestMove = findBestMove(Board)

    See nl+"The Optimal Move for Player: "+ Player +" -> "+ bestMove  +nl
    
    Board[bestMove] = Player
    DrawBoard(Board)
    
    
return 
//======================================

Func findBestMove(Board)

    bestVal      = -1000
    bestMove     = -1

    // Traverse all cells, evaluate minimax function for all empty cells. 
    // And return the cell with Optimal Value.
    
    for i = 1 to 9   
                  
            // Check if cell is empty 
            if (Board[i] = '_')
            
                // Make the move 
                Board[i] = Player
               
                // Compute evaluation function for this move. Board, Depth, false=O
                moveVal = minimax(Board, 0, false)
                    
                // Undo the move 
                Board[i] = '_'
                
                
                // If the value of the current move is more than the best value, then update BestValue 
                if (moveVal > bestVal)
                  bestMove = i
                  bestVal  = moveVal
                ok
            ok                                      
    next

return bestMove


//=================================================================================
// This is the MiniMax function. It considers all the possible ways the game can go
// and returns the value of the Board 

Func minimax(Board, depth, isMax)

    score = evaluate(Board)

    // If Maximizer has won the game return his evaluated score 
    if score = 10
        return score
    ok

    // If Minimizer has won the game return his evaluated score 
    if score = -10  
        return score
    ok
    
    // If there are no more moves and no winner then it is a tie 
    if isMovesLeft(Board) = false   
        return 0
    ok
    
    // If this MAXimizer's move PLAYER
    if isMax            // PLAYER
        best = -1000

        // Traverse all cells 
        for i = 1 to 9      

            // Check if cell is empty 
            if (Board[i] = '_')
            
                // Make the move 
                Board[i] = Player
                
                // RECURSIVE Call minimax recursively and choose the maximum value 
                valRet = minimax(Board, depth + 1, !(isMax) )
                best = max(best, valRet )
                
                // Undo the move 
                Board[i] = '_'
                                
            ok
        next
        
        return best
    

    //-------------------------------------------
    // If this MINimizer's move !isMax = OPPONENT
    else  
        best = 1000

        // Traverse all cells 
        for i = 1 to 9      
            
            // Check if cell is empty 
            if (Board[i] = '_')
            
                // Make the move 
                Board[i] = Opponent

                // Call minimax recursively and choose the minimum value 
                valRet = minimax(Board, depth + 1, !(isMax) )
                
                best   = min(best, valRet)
                
                // Undo the move 
                Board[i] = '_'
                                
            ok                      
        next
            
        return best
    ok

return

//======================================================================= 
// This function returns TRUE if there are moves  remaining on the Board. 
// It returns FALSE if there are no moves left to play. 

Func isMovesLeft(Board)

     for i = 1 to 9      
            if (Board[i] = '_')
                return true
            ok  
      next  
      
return false
      

//==================================================  
// This is the Evaluation function 
// Assign points to different results
// Check who won. Assign +- 10 points

Func evaluate(b)

    //-------------------------------------------
    // ROWS Checking for Rows for X or O victory. 

    if  (( b[1] = b[2]  AND  b[2] = b[3] ) ||
         ( b[4] = b[5]  AND  b[5] = b[6] ) ||
         ( b[7] = b[8]  AND  b[8] = b[9] )   )
         
            if  b[1] = Player    || b[4] = Player   ||  b[7] = Player    return  10
            but b[1] = Opponent  || b[4] = Opponent ||  b[7] = Opponent  return -10
            ok               
    ok
         
         
    //----------------------------------------------
    // COL Checking for Columns for X or O victory. 

    if  (( b[1] = b[4]  AND  b[4] = b[7] ) ||
         ( b[2] = b[5]  AND  b[5] = b[8] ) ||
         ( b[3] = b[6]  AND  b[6] = b[9] )   )
         
            if  b[1] = Player    || b[2] = Player   ||  b[3] = Player    return  10
            but b[1] = Opponent  || b[2] = Opponent ||  b[3] = Opponent  return -10
            ok               
    ok
    
    //------------------------------------------------
    // DIAG Checking for Diagonals for X or O victory. 
    
    if b[1] = b[5] AND b[5] = b[9]
  
        if  b[1] = Player      return  10   
        but b[1] = Opponent    return -10
        ok    
    ok
    
    //------------------------------------------------
    // DIAG
    if b[3] = b[5] AND b[5] = b[7]
    
        if  b[3] = Player      return  10   
        but b[3] = Opponent    return -10
        ok     
    ok

    // Else if none of them have won then return 0 
        
     
return 0


//================================================== 

Func DrawBoard(Board)
    i = 1
    for k = 1 to 3                 
        for m = 1 to 3    
             See "|"+ Board[i]
             i++
        next
        
        See "|" +nl
    next
return
 

//======================================
////////////////////////////////////////
//======================================
