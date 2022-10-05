#include "ring.h"

#include "stdlib.h"

RING_FUNC(ring_myfunction)
{
	printf("Hello, World!\n");
}

RING_FUNC(ring_sumtwonumbers)
{
	double nNum1,nNum2,nSum;
	// Check Parameters Count
		if (RING_API_PARACOUNT != 2) {
			RING_API_ERROR(RING_API_MISS2PARA);
			return;
		}
	// Check Parameters Type
		if ( ! (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	// Sum Numbers 
		nNum1 = RING_API_GETNUMBER(1);
		nNum2 = RING_API_GETNUMBER(2);
		nSum  = nNum1 + nNum2 ;
	// Return Output
		RING_API_RETNUMBER(nSum);
}

RING_FUNC(ring_sayhello)
{
	// Check Parameters Count
		if (RING_API_PARACOUNT != 1) {
			RING_API_ERROR(RING_API_MISS1PARA);
			return;
		}
	// Check Parameters Type
		if ( ! RING_API_ISSTRING(1) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	printf("Hello %s\n",RING_API_GETSTRING(1));
}

RING_LIBINIT
{
	RING_API_REGISTER("myfunction",ring_myfunction);
	RING_API_REGISTER("sumtwonumbers",ring_sumtwonumbers);
	RING_API_REGISTER("sayhello",ring_sayhello);
}
