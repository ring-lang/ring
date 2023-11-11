#include "ring.h"
#include "stdlib.h"

RING_FUNC(ring_mandel)
{

    //----------------------------------------------------------
    // RAW MANDELBROT IMAGE
    // Imaginary-Vertical and Real-Horizontal. Limits are +-2
    // minI = -2.0    maxI = 2.0    minR = -2.0    maxR = 2.0     # Default limits

	List *pList, *pRow, *pCol;
	int   nRow,nCol;
	int   sum;              // nRow + nCol
		
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
	
    // Get the List (Represent a Table)
        pList = RING_API_GETLIST(8);

	stepR = fabs(maxR - minR) / width ;      // step-Real-horizontal
	stepI = fabs(maxI - minI) / height ;     // step-Virtual-vertical

						
    // Update the Table Rows and Columns
	for (y = 1 ; y <= height ; y++ ) 			 // Each vertical point
	{                                                
		pCol = ring_list_getlist(pList, y);
		
		pointI = minI + stepI * y ;              // Imaginary + Step
		
		for (x = 1 ; x <= width ; x++ ) 
		{                                        // Each horizontal point	
			pRow = ring_list_getlist(pList, x);		
			
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
				}                                // Beyond boundary limits +-2

				zI = 2 * zR * zI + pointI ;      // Vertical-imaginary + Step
				zR = a - b + pointR ;            // Horizontal-real

			}  
			
			ring_list_setdouble_gc(RING_API_STATE,pCol, x,  N);	 // N -> aList[][]
														
		}

	}
												
} 

RING_LIBINIT
{
	RING_API_REGISTER("mandel",ring_mandel);
}
