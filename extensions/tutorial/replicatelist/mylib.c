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

RING_FUNC(ring_sumlist)
{
	List *pList;
	int x,nSum;
	// Check Parameters Count
		if (RING_API_PARACOUNT != 1) {
			RING_API_ERROR(RING_API_MISS1PARA);
			return;
		}
	// Check Parameters Type
		if ( ! RING_API_ISLIST(1) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	// Sum List Numbers 
		nSum = 0;
		pList = RING_API_GETLIST(1);
		for(x=1 ; x <= ring_list_getsize(pList) ; x++) {
			if ( ring_list_isdouble(pList,x) ) {
				nSum += (int) ring_list_getdouble(pList,x) ;
			}
		}
	// Return Output 
		RING_API_RETNUMBER(nSum);
}

RING_FUNC(ring_inclist)
{
	List *pList;
	int x,nSum;
	// Check Parameters Count
		if (RING_API_PARACOUNT != 2) {
			RING_API_ERROR(RING_API_MISS2PARA);
			return;
		}
	// Check Parameters Type
		if ( ! ( RING_API_ISLIST(1) && RING_API_ISNUMBER(2) ) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	// Increment List Items
		nSum = 0;
		pList = RING_API_GETLIST(1);
		for(x=1 ; x <= ring_list_getsize(pList) ; x++) {
			if ( ring_list_isdouble(pList,x) ) {
				ring_list_setdouble_gc(RING_API_STATE,pList,x,ring_list_getdouble(pList,x)+RING_API_GETNUMBER(2)) ;
			}
		}
	// Return Output
		RING_API_RETLIST(pList);
}

RING_FUNC(ring_filterlist)
{
	List *pList;
	int x;
	// Check Parameters Count
		if (RING_API_PARACOUNT != 2) {
			RING_API_ERROR(RING_API_MISS2PARA);
			return;
		}
	// Check Parameters Type
		if ( ! ( RING_API_ISLIST(1) && RING_API_ISNUMBER(2) ) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	// Filter List Items
		pList = RING_API_GETLIST(1);
		for(x = ring_list_getsize(pList) ; x >= 1 ; x--) 
			if ( ring_list_isdouble(pList,x) ) 
				if ( ! (ring_list_getdouble(pList,x) > RING_API_GETNUMBER(2)) )
					ring_list_deleteitem_gc(RING_API_STATE,pList,x) ;
	// Return Output
		RING_API_RETLIST(pList);
}

RING_FUNC(ring_replicatelist)
{
	List *pList;
	int x,y,nTimes,nSize;
	// Check Parameters Count
		if (RING_API_PARACOUNT != 2) {
			RING_API_ERROR(RING_API_MISS2PARA);
			return;
		}
	// Check Parameters Type
		if ( ! ( RING_API_ISLIST(1) && RING_API_ISNUMBER(2) ) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	// Replicate List Items
		pList = RING_API_GETLIST(1);
		nSize = ring_list_getsize(pList);
		nTimes = (int) RING_API_GETNUMBER(2);
		if (nTimes < 1) {
			RING_API_ERROR("Error: The second parameter must be >= 1 \n");
			return;
		}
		for(x = 1 ; x <= nTimes ; x++) 
			for(y = 1 ; y <= nSize ; y++) 
				if ( ring_list_isdouble(pList,y) ) 
					ring_list_adddouble_gc(RING_API_STATE,pList,ring_list_getdouble(pList,y));
	// Return Output
		RING_API_RETLIST(pList);
}

RING_LIBINIT
{
	RING_API_REGISTER("myfunction",ring_myfunction);
	RING_API_REGISTER("sumtwonumbers",ring_sumtwonumbers);
	RING_API_REGISTER("sayhello",ring_sayhello);
	RING_API_REGISTER("sumlist",ring_sumlist);
	RING_API_REGISTER("inclist",ring_inclist);
	RING_API_REGISTER("filterlist",ring_filterlist);
	RING_API_REGISTER("replicatelist",ring_replicatelist);
}
