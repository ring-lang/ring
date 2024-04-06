// myCalcTransform(FC, RC) => RC
// Called by Ring
// Does Transforms Rotations on ShapeMug 12890x4 using MAtrixMultiply
// Bert Mariani 2023-08-07
//
// USAGE in RING
// if iswindows()
//     LoadLib("mylibCalcTransform.dll")            // buildvc.bat  => mylibCalcTransform.dll
//     ? "Windows loaded mylibCalcTransform.dll"    // mylib.dll    => myCalcTransform
// ok
//
//	FC  = Transform                  // Transform 4x4       
//  RC  = InitialArray               // Points Array ex 1296x4     
//  myCalcTransform(FC, RC)          // FC x RC => RC				
//           
//----------------------------------------------------------------

#include "ring.h"
#include "stdlib.h"
#include <stdio.h>

#define M  4
#define N  4
#define P  4
#define Q  1

float  MatrixMultiply(float FC[M][N], float MA[P][Q], float C[P][Q] ) ; 

//==========================================================
// MatrixMultiply SubRoutine  FCxA

float MatrixMultiply( float FC[M][N], float MA[P][Q], float C[P][Q] )       //  (4x4).(4x1) => (4x4)
{
   float Sum;
     
    for (int i = 0; i < M; i++ )     // 4x1
    {  
		Sum = 0;
		for (int j = 0; j < Q; j++)
		{
            for (int k = 0; k < N; k++) 
			{	
		        Sum += FC[i][k] * MA[k][j] ;   				
				C[i][j] = Sum;         				
			}	
		}
    }

return C[P][Q] ;
}

//========================================================

RING_FUNC(ring_mycalctransform)
{

    //printf("In C-Mug-Calc \n");
    //pList = RING_API_GETLIST(1);      // PARAMTER 1 from Ring FC 4x4
    //mList = RING_API_GETLIST(2);      // PARAMTER 2 from Ring A  1x1	
	
    //----------------------------------------
    // Definitions of List and pointers for C

	int   x, y;
	
	float FC[4][4] ;   // Transform Array
	float MA[4][1] ;   // Mug Array
	float  C[4][1] ;   // Result MatrixMultiply FC x A
	float Value, Value2, Value3;
	
	//-----------------------------------
	
    List *pList, *pRow, *pCol;        // Transform Array 4x4
    int           nRow,  nCol;
    
    List *p2List, *p2Row, *p2Col;     // Mug Array 12890x4
    int            n2Row,  n2Col;
    
    //----------------------------------------------------------------
	// PARAMTER 1 from Ring FC 4x4 -- GETLIST 1 (Represent a Table)
	
       pList = RING_API_GETLIST(1);                // <==== PARAMTER 1   
       nRow  = ring_list_getsize(pList);           //  Rows 4x4
       pRow  = ring_list_getlist(pList,nRow);      // *Pointer to Row in List, to get Col
       nCol  = ring_list_getsize(pRow);            //  Cols Rx4    
	    
	// Update the Table Rows and Columns

	for (x = 1 ; x <= nRow ; x++ ) 			       // Each Row 4x4 - vertical point
	{                                                
		for (y = 1 ; y <= nCol ; y++ )             // Each Col  Rx4 - horizontal point
		{                                        	
			pRow  = ring_list_getlist(pList, x);   // *Pointer to Row-x start of Col-y
			Value = ring_list_getdouble(pRow,y);   // Value of Row=X Col-y
		
			FC[x-1][y-1] = Value;                  // Index Ring 1 C 0			
        }
	
    }	
	
	//------------------------------------------------------------------
	// PARAMTER 2 from Ring Mug-A 4x1  -- GETLIST 2 (Represent a Table)
	
       p2List = RING_API_GETLIST(2);                 // <==== PARAMTER 2   
       n2Row  = ring_list_getsize(p2List);           //  Rows 4x1
       p2Row  = ring_list_getlist(p2List,n2Row);     // *Pointer to Row in List, to get Col
       n2Col  = ring_list_getsize(p2Row);            //  Cols Rx1     
	     
	// Update the Table Rows and Columns

	for (x = 1 ; x <= n2Row ; x++ ) 			     // Each Row4x1  - vertical point
	{                                                
		for (y = 1 ; y <= n2Col ; y++ )              // Each Col Rx1 - horizontal point
		{                                        	
			p2Row  = ring_list_getlist(p2List, x);   // *Pointer to Row-x start of Col-y
			Value2 = ring_list_getdouble(p2Row,y);   // Value <== Row=X Col-y	
			MA[y-1][0] = Value2;                     // MA 4x1 Index Ring 1 C 0			
        }

        MatrixMultiply(FC,MA,C) ;                     // MATRIX MULTIPLY FC x MA => C
	
		for (y = 1 ; y <= n2Col ; y++ )               // UPDATE Each Col Rx1 - horizontal point
		{     
			p2Row  = ring_list_getlist(p2List, x);    // *Pointer to Row-x start of Col-y
			
			Value3 = C[y-1][0];                       // GET: Result of Multiple ==> C
		
			ring_list_setdouble(p2Row,y, Value3);     // SET: List-2(Row,Col) <== Valu2			//
        }	   
    }	
	

	//-------------------------------------------------------------  
    // Return Update p2List -ShapeMug[12890[4] as Output
    RING_API_RETLIST(p2List);
	
} 

//==========================================================

RING_LIBINIT
{
   RING_API_REGISTER("mycalctransform",ring_mycalctransform);
}

	

//==========================================================
    
