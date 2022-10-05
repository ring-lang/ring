#include "ring.h"
#include "stdlib.h"

#include <stdio.h>
#include <conio.h>
#include <time.h>

//------------------------------------
// GLOBALS
// Comments at end of this file
// Visual Studio C does NOT have these ?!?! 
// int bool  = 0;  // Use int

int true  = 1;
int false = 0;

int sudoku[9][9] = {
        {1,2,3, 4,5,6, 7,8,9},
        {2,0,0, 0,0,0, 0,0,8},
        {3,0,0, 0,0,0, 0,0,7},

        {4,0,0, 1,2,3, 0,0,6},
        {5,0,0, 4,5,6, 0,0,5},
        {6,0,0, 7,8,9, 0,0,4},

        {7,0,0, 0,0,0, 0,0,3},
        {8,0,0, 0,0,0, 0,0,2},
        {9,8,7, 6,5,4, 3,2,1} } ;


int aFloorMap[] = {0,0,0,3,3,3,6,6,6} ;  // C-Index-0,  RING-Index-1 = 1,1,1,4,4,4,7,7,7}  ;

int arr[] = {11,12,13};                  // T/F, Row, Col
int gcountIter = 0 ;

//==============================================================
//==============================================================

void prnt(int sudoku[9][9])
{
    int row, column ;
    char alpha ;

    printf("\n|-----------------------|\n");

    for (row = 0; row < 9; row++ )
    {
        printf("|");
        for (column = 0; column < 9; column++ )
        {  printf(" %d", sudoku[row][column]) ;

            if ((column +1) % 3 == 0 )
            {   printf(" |");
            }

        }
        printf("\n");

        if ((row+1) % 3 == 0 )
        {   printf("|-----------------------|\n");
        }
    }

} 


//------------------------------------------------------------
// Checks if num exists on a:                           ROW
// bool => int

int rowHasNotNum(int row, int num)
{
    int column, sNum;

    for (column = 0; column < 9; column++ )
    {
        sNum =  sudoku[row][column];
        if (sNum == num )
        {  return false ;
        }
    }

 return true ;
}

//------------------------------------------------------------
//-- Checks if num exists on a:                         COLUMN
// bool => int

int columnHasNotNum(int column, int num)
{
  int row, sNum;

      for (row = 0; row < 9; row++ )
      {
          sNum =  sudoku[row][column];
          if (sNum == num )
          {   return false;
          }
      }

  return true;
}

//------------------------------------------------------------
// Given a (row, column) location on the sudoku grid
// identifies the corresponding 3x3 box and checks if
// num exists in the:                                   BOX

// bool => int

int boxHasNotNum(int row, int column, int num)
{
    int rwOffset, clOffset, bRow, bColumn, sNum ;

    row    = aFloorMap[row] ;
    column = aFloorMap[column] ;

    for (rwOffset = 0; rwOffset <= 2; rwOffset++ )
    {    for (clOffset = 0; clOffset <= 2; clOffset++ )
         {
            bRow    = row + rwOffset ;
            bColumn = column + clOffset ;

            sNum =  sudoku[bRow][bColumn];
            if (sNum == num )
            { return false;
            }
         }
    }
    
 return true;
}

//------------------------------------------------------
// Checks if num can be assigned to sudoku[row][column]
// without breaking sudoku rules.
// bool => int

int isLegit(int row, int column, int num)
{
     int rRow, rCol,rBox, rCombo ;     // bool

     rRow = rowHasNotNum( row, num) ;
     rCol = columnHasNotNum( column, num) ;
     rBox = boxHasNotNum( row, column, num) ;

     rCombo = rRow && rCol && rBox  ;

 return  rCombo ;
}




//-----------------------------------------------------------------
// Checks if the actual problem is solved. If not, returns false,
// plus the location on the first unassigned cell found.

void  isSolved()
{
  int one = 1, zero = 0, row, column ;


    for (row = 0; row < 9; row++ )
    {    for (column = 0; column < 9; column++ )
         {

            //printf("isSol Row %d Col %d Val %d \n", row, column, sudoku[row][column]  ) ;

            if ( sudoku[row][column] == 0 )
            {    arr[0] = zero ;
                 arr[1] = row  ;
                 arr[2] = column  ;
                 return ;
            }
        }
    }

    arr[0] = one;
 return ;
}

//-----------------------------------------------------------------
// Sudoku solving via backtracking and recursion
// sudoku  : a 2-dimensional grid of numbers (0-9)
//           0 matches unknown values to be found.
// returns : true, if a solution was found,
//           false otherwise.

int solve()
{
 int row, column, num ;
 int solveTF ;
 int result;          // true=1, false =   Visual Studio C does NOT have bool ?!?!

    gcountIter++ ;

    isSolved() ;                   // T/F, Row, Col
    solveTF     = arr[0] ;
    row         = arr[1] ;
    column      = arr[2] ;

    //  printf( "Test-Output: Count: %d Row %d Col %d \n",countIter, solveTF, row, column );
    //  prnt(sudoku)


    if ( solveTF == 1 )
    {
        printf( "SUDOKU is SOLVED: Iterations: %d \n", gcountIter );
        return true ;
    }

    for ( num = 1; num <= 9; num++ )
    {    result = isLegit( row, column, num)   ;

         if ( result == 1 )
         {
            sudoku[row][column] = num ;
                
            if (solve())
            {   return true ;
            }
            
            sudoku[row][column] = 0 ;
        }
    }

return false ;
}

//---------------------------------------------------------------------------


//=================================================================
//=================================================================
// MAIN EQUIVALENT
// Must be LOWER-CASE names --- ring_functionname

RING_FUNC(ring_sudokusolver)
{
    //----------------------------------------------------------
    // Input:  Sudoku array[9][9] sent by Ring to solve
    // Return: Solved array[9][9]
    //
    
    List *pList, *pRow, *pCol;
    int           nRow,  nCol, nbr, nRowSize, nColSize;
    
    
    pList  = RING_API_GETLIST(1);
    
        nRow = ring_list_getsize(pList);            // X - Width size
        pRow = ring_list_getlist(pList,nRow);       // Pointer to Row in List
        nCol = ring_list_getsize(pRow);             // Y - Height size
        
        nRowSize = nRow;
        nColSize = nCol;
    

    //-------------------------------------------------------------
    // Show pList Uses Index 1, sudoku array passed from Ring to C  
    //      sudoku[][] Index 0, for C-Code
   
            
    //-----------------------------------       
    // Copy pList Array to  Sudoku Array
    
    
    for (nRow = 1 ; nRow <= nRowSize ; nRow++ )
    {       
        pRow = ring_list_getlist(pList,nRow);           // Pointer to Row 1..9 in List
        
        for (nCol = 1 ; nCol <= nColSize ; nCol++ ) 
        {  
            nbr = ring_list_getdouble(pRow, nCol);      // Use Pointer to Current Row, get Value (double number)
            //printf(" %d",nbr);
            
            sudoku[nRow-1][nCol-1] = nbr ;              // Fill the C-ARRAY -- Index 0
        }
        //printf("\n");
    }

    
    //-------------------------
    // MAIN Equivalent
    
    clock_t start, end;
    double  timeused;

            prnt(sudoku);           // BEFORE

		gcountIter = 0 ;            // Count Iterations it took to solve
        start = clock();
       
          
    solve();
     
        end = clock();
        timeused = ((double) (end - start)) / CLOCKS_PER_SEC ;
        printf("Time taken: %f seconds \n", timeused ) ;

            prnt(sudoku);           // AFTER


    //-------------------------------------
    // Stuff the array from C back to Ring
    
    for (nRow = 1 ; nRow <= nRowSize ; nRow++ )
    {       
        pRow = ring_list_getlist(pList,nRow);           // Pointer to Row 1..9 in List
        
        for (nCol = 1 ; nCol <= nColSize ; nCol++ ) 
        {   
            nbr = sudoku[nRow-1][nCol-1] ;              // C-Index-0  
            ring_list_setdouble(pRow, nCol, nbr);       // nbr -> RING calling array[][] 
        }
    }
    
 return ;
    
}

//=========================================================
// Must be LOWER-CASE names 

RING_API void ringlib_init(RingState *pRingState)
{
    ring_vm_funcregister("sudokusolver", ring_sudokusolver);
}



//=====================================================================================
// TO BUILD the C-CODE USE:
// c:\ring\src\buildvc.bat      
//
// Copy it to directory c:\MyStuff. Edit as shown  
// COMPILES the C-Code using Visual Studio C
//                  
// SCRIPT: buildvc-Sudoku.bat   
//
//      echo build Sudoku
//      cls
//      call c:\ring\src\locatevc.bat
//      cl /c /DEBUG mylibSudoku.c -I"c:\ring\include"
//      link /DEBUG mylibSudoku.obj  c:\ring\lib\ring.lib /DLL /OUT:mylibSudoku.dll /SUBSYSTEM:CONSOLE,"5.01"
//      del mylibSudoku.obj
//      pause
//
// DISTRIBUTE THESE FILES
//     AA-Sudoku.ring
//     Sudoku.c
//     Sudokulib.ring
//     buildvc-Sudoku.bat
//     SudokuPuzzles.ring
//
//==========================================================================


    
//==========================================================================  
//========================================================================== 
//========================================================================== 


//===========================================================================
// MAIN PRORAM
/*
	#pragma argsused

int main(int argc, char* argv[])
{

 clock_t start, end;
 double  timeused;

 printf( "Hello, press a key to start \n");
 getch();
 prnt(sudoku);

      start = clock();
 solve();
      end = clock();
      timeused = ((double) (end - start)) / CLOCKS_PER_SEC ;
      printf("Time taken: %f seconds \n", timeused ) ;

 prnt(sudoku);

 getch();

 return 0;
}

//---------------------------------------------------------------------------

*/

//===========================================================================

/*
//--------------------------------

int sudoku[9][9] = {
        {9,0,0, 1,0,0, 0,0,5},
        {0,0,5, 0,9,0, 2,0,1},
        {8,0,0, 0,4,0, 0,0,0},

        {0,0,0, 0,8,0, 0,0,0},
        {0,0,0, 7,0,0, 0,0,0},
        {0,0,0, 0,2,6, 0,0,9},

        {2,0,0, 3,0,0, 0,0,6},
        {0,0,0, 2,0,0, 9,0,0},
        {0,0,1, 9,0,4, 5,7,0} } ;

SUDOKU is SOLVED: 1
Time taken: 1.719000 seconds

        |-----------------------|
        | 9 3 4 | 1 7 2 | 6 8 5 |
        | 7 6 5 | 8 9 3 | 2 4 1 |
        | 8 1 2 | 6 4 5 | 3 9 7 |
        |-----------------------|
        | 4 2 9 | 5 8 1 | 7 6 3 |
        | 6 5 8 | 7 3 9 | 1 2 4 |
        | 1 7 3 | 4 2 6 | 8 5 9 |
        |-----------------------|
        | 2 9 7 | 3 5 8 | 4 1 6 |
        | 5 4 6 | 2 1 7 | 9 3 8 |
        | 3 8 1 | 9 6 4 | 5 7 2 |
        |-----------------------|

*/

//==================================================================
