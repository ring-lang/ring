#include "ring.h"
#include "stdlib.h"

RING_FUNC(ring_mandel)
{
    //----------------------------------------------------------
    // RAW MANDELBROT IMAGE
    // Imaginary-Vertical and Real-Horizontal. Limits are +-2
    // minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0     # Default limits
	
	printf("We are in Mandel Code \n");

	List *pList, *pRow, *pCol;
	int           nRow,  nCol;
		
	printf("\nMandel C-Calc called by Ring \n" );
	
	double minI   = -2.0, maxI   = 2.0, minR = -2.0, maxR = 2.0 ;
	double stepR  = 0,    stepI  = 0;
	double pointI = 0,    pointR = 0;
	double zI = 0, zR = 0 ;
	double a  = 0, b  = 0 ;

	int    width = 400,  height = 400 ;
	int    iter  = 50 ;
	int    x = 0, y = 0, N = 0 ;

	minI   = RING_API_GETNUMBER(1);
	maxI   = RING_API_GETNUMBER(2);
	minR   = RING_API_GETNUMBER(3);
	maxR   = RING_API_GETNUMBER(4);
	iter   = RING_API_GETNUMBER(5);
	width  = RING_API_GETNUMBER(6);
	height = RING_API_GETNUMBER(7);
	pList  = RING_API_GETLIST(8);
	
	printf("MinI: %10.9f MinR: %10.9f \nMaxI: %10.9f MaxR: %10.9f Iter: %d Width: %d Height: %d pList: %p \n\n", 
              minI,minR,maxI,maxR,iter,width,height, pList ) ; // &arrayM) ;  

	//--------------------------------------
    // Get the List (Represent a Table)
        pList = RING_API_GETLIST(8);
		
		nRow = ring_list_getsize(pList);			// X - Width
		pRow = ring_list_getlist(pList,nRow);       // Pointer to Row in List
		nCol = ring_list_getsize(pRow);				// Y - Height
		
		
	//-------------------------------------------------------------
    // Update the Table ROWS and COLUMS  X-Y. 
	// We want Height and Width Y-X
	
	stepR = fabs(maxR - minR) / width ;      // step-Real-horizontal
	stepI = fabs(maxI - minI) / height ;     // step-Virtual-vertical

	for (nRow = 1 ; nRow <= ring_list_getsize(pList) ; nRow++ )
	{   
        y      = nRow;                           // y = height                            
		pRow   = ring_list_getlist(pList, nRow);		
		pointI = minI + stepI * y ;              // Imaginary + Step

		
		for (nCol = 1 ; nCol <= ring_list_getsize(pRow) ; nCol++ )	
		{  
         	x      = nCol;                       // x - width, Each horizontal point			
			pointR = minR + stepR * x ;          // Real horizontal + Step

			zR = pointR ;                        // Depth - horizontal-real
			zI = pointI ;                        // Depth - vertical-imaginary

			for (N = 0 ; N < iter; N++)
			{                                    // Does it leave Orbit ?
				a = zR * zR ;                    //  zR^2  - horizontal-real
				b = zI * zI ;                    //  zI^2  - vertical-imaginary

				if (a + b > 4 )
				{
				   break;
				}                                // Beyond boudary limts +-2

				zI = 2 * zR * zI + pointI ;      // Vertical-imaginary + Step
				zR = a - b + pointR ;            // Horizontal-real

			}  
			
			ring_list_setdouble(pRow, x, N);	 // N -> aList[][] Draws WRONG direction.
														
		}
	}																
} 

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("mandel",ring_mandel);
}

			  
/*	
    //===================================================================  
	// ORIGINAL C-CODE
	
    stepR = fabs(maxR - minR) / width ;          // step-Real-horizontal
    stepI = fabs(maxI - minI) / height ;         // step-Virtual-vertical

    for (y = 0 ; y <= height; y++ )
    {                                            // Each vertical point
         pointI = minI + stepI * y ;             // Imaginary + Step

        for (x = 0 ; x <= width; x++)
        {                                        // Each horizontal point
              pointR = minR + stepR * x ;        // Real horizontal + Step

               zR = pointR ;                     // Depth - horizontal-real
               zI = pointI ;                     // Depth - vertical-imaginary

            for (n = 0 ; n <= iter; n++)
            {                                    // Does it leave Orbit ?
                a = zR * zR ;                    //  zR^2  - horizontal-real
                b = zI * zI ;                    //  zI^2  - vertical-imaginary

                if (a + b > 4 )
                {
                   break;
                }                                // Beyond boudary limts +-2

                zI = 2 * zR * zI + pointI ;      // Vertical-imaginary + Step
                zR = a - b + pointR ;            // Horizontal-real

            }  

			printf("Array: x:%d y:%d iter:%d  n:%d  \n", x, y, iter, n );
			arrayM[x][y] = n;
        }   
    }

	//==========================================================================
		
*/
	




/*

 //=============================================================
 // RING C-CODE EXAMPLE
 
RING_FUNC(ring_updatetable)
{
	List *pList, *pRow;
	int   nRow, nCol;
	
	// Check Parameters Count
	if (RING_API_PARACOUNT != 2) {
			RING_API_ERROR(RING_API_MISS2PARA);
			return;
	}
			
	// Check Parameters Type
	if ( ! ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
	}
	
	// Get the List (Represent a Table)
			pList = RING_API_GETLIST(1);
			
	//------------------------------------------------------------		
	// Update the Table Rows and Columns
	
	for (nRow = 1 ; nRow <= ring_list_getsize(pList) ; nRow++ ) {
		
		if ( ring_list_islist(pList,nRow) ) {
			pRow = ring_list_getlist(pList,nRow);
			
			for (nCol = 1 ; nCol <= ring_list_getsize(pRow) ; nCol++ ) {
				
				if ( ring_list_isdouble(pRow,nCol) ) {
						ring_list_setdouble(pRow,nCol,RING_API_GETNUMBER(2));
						
				} else {
						RING_API_ERROR("Error : We expect numbers!\n");
						return ;
				}
			}
			
		} else {
				RING_API_ERROR("Error : The parameter is not a table! \n");
				return ;
		}
	}
}
//=======================================================================

*/