/*
** ListPro extension
** 2023, Mahmoud Fayed 
*/

#include "ring.h"
#include "stdlib.h"

RING_FUNC(ring_bytes2list)
{
	unsigned char *pData;
	List *pList, *pSubList;
	int nIndex,nPoint,nChannel,nPointsCount,nChannelDiff,nDivide,nWidth,nHeight;
	VM *pVM;
	if ( RING_API_PARACOUNT < 4 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pData   = (unsigned char *) RING_API_GETSTRING(1);
	nIndex  = 0;
	nPoint  = 1;
	nWidth  = (int) RING_API_GETNUMBER(2);
	nHeight = (int) RING_API_GETNUMBER(3);
	nPointsCount = nWidth*nHeight;
	nChannel = (int) RING_API_GETNUMBER(4);
	nChannelDiff = 0;
	if (nChannel > 3)
		nChannelDiff = nChannel - 3;
	nDivide = 0;
	if (RING_API_PARACOUNT > 4)
		if (RING_API_ISNUMBER(5))
			nDivide = (int) RING_API_GETNUMBER(5) ;
	pList = RING_API_NEWLISTUSINGBLOCKS2D(nPointsCount,6);
	pVM = (VM *) pPointer;
	for (int y=1 ; y <= nHeight ; y++ ) {
		for (int x=1 ; x <= nWidth ; x++ ) {
			pSubList = ring_list_getlist(pList,nPoint++);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,1,(double) x);
			ring_list_setdouble_gc(pVM->pRingState,pSubList,2,(double) y);
			if (nDivide == 0) {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,(double) pData[nIndex++]);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,(double) pData[nIndex++]);						
				ring_list_setdouble_gc(pVM->pRingState,pSubList,5,(double) pData[nIndex++]);
			} else {
				ring_list_setdouble_gc(pVM->pRingState,pSubList,3,( (double) pData[nIndex++] ) / nDivide);
				ring_list_setdouble_gc(pVM->pRingState,pSubList,4,( (double) pData[nIndex++] ) / nDivide);				
				ring_list_setdouble_gc(pVM->pRingState,pSubList,5,( (double) pData[nIndex++] ) / nDivide);
			}
			ring_list_setdouble_gc(pVM->pRingState,pSubList,6,(double) 1.0);
			nIndex += nChannelDiff;	
		}
	}
	RING_API_RETLISTBYREF(pList);
}

RING_FUNC(ring_list2bytes)
{

    VM *pVM;
    char *cData;
    List *pList, *pPointList;
    int nDataSize,nListSize,nIndex,x,lError,nPointListSize,nChannel,nMul;
    pVM = (VM *) pPointer;
    nMul = 1;
    nChannel = 3;
    if ( RING_API_PARACOUNT < 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( ! RING_API_ISLIST(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
    }
    if ( ! RING_API_ISNUMBER(2) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
    }
    nChannel = (int) RING_API_GETNUMBER(2);
    if ( (nChannel != 3) && (nChannel != 4) )  {
        RING_API_ERROR("Wrong channel value (Pass 3 or 4)");
	return ;
    }

    if ( RING_API_PARACOUNT == 3 ) 
        if ( RING_API_ISNUMBER(3) ) 
            nMul = (int) RING_API_GETNUMBER(3);

    pList = RING_API_GETLIST(1);
    nListSize = ring_list_getsize(pList);
    if ( nListSize < 1 ) return ;

    nDataSize = nListSize * nChannel;
    cData = (char *) malloc(nDataSize);
    nIndex = 0;
    lError = 0;

    for ( x=1 ; x <= nListSize ; x++ ) {

        if ( ! ring_list_islist(pList,x) ){
            lError = 1;
            break;
        }

        pPointList = ring_list_getlist(pList,x);
        nPointListSize = ring_list_getsize(pPointList);
        if ( nPointListSize < 6 ) {
            lError = 1;
            break;
        }

        if ( ring_list_isdouble(pPointList,3) && ring_list_isdouble(pPointList,4) && 
             ring_list_isdouble(pPointList,5) ) {
             cData[nIndex++] = (char) (ring_list_getdouble(pPointList,3)*nMul);
             cData[nIndex++] = (char) (ring_list_getdouble(pPointList,4)*nMul);
             cData[nIndex++] = (char) (ring_list_getdouble(pPointList,5)*nMul);
        } else {
            lError = 1;
            break;
        }

        if ( nChannel == 4) 
            if ( ring_list_isdouble(pPointList,6) ) { 
                 cData[nIndex++] = (char) (ring_list_getdouble(pPointList,6)*nMul);
            } else {
                lError = 1;
                break;
            }
    }

    if ( lError == 1 ) {
            free(cData);
            RING_API_ERROR(RING_API_BADPARATYPE);
	    return ;
    }

    RING_API_RETSTRING2(cData,nDataSize);
    free(cData);
}


RING_FUNC(ring_updatelist)
{
    char *cOperation  ;
    char *cSelection  ;
    List *pList, *pSubList, *pRow, *pRow2  ;
    int nOPCode,nRow,nCol,nStart,nEnd,iValue  ;
    int x,y  ;
    double nValue  ;
    VM *pVM  ;
    /* Get VM pointer */
    pVM = (VM *) pPointer ;
    /* Check Parameters */
    if ( (RING_API_PARACOUNT < 4) || (RING_API_PARACOUNT > 6) ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( ! ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    /* Get Parameters */
    pList = RING_API_GETLIST(1) ;
    cOperation = (char *) RING_API_GETSTRING(2) ;
    cSelection = (char *) RING_API_GETSTRING(3) ;
    cOperation = ring_string_lower(cOperation);
    cSelection = ring_string_lower(cSelection);
    if ( ring_list_getsize(pList) == 0 ) {
        /* For empty lists, we does nothing! */
        return ;
    }
    /* Set instruction values */
    nOPCode = 0 ;
    nRow = 0 ;
    nCol = 0 ;
    nStart = 0 ;
    nEnd = 0 ;
    pRow = NULL ;
    /* Check Selection */
    if ( strcmp(cSelection,"row") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 1 ;
                nRow = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
                iValue = (int) RING_API_GETNUMBER(5) ;
                if ( (nRow < 1) || (nRow > ring_list_getsize(pList)) ) {
                    RING_API_ERROR("The selected row is outside the range of the list");
                    return ;
                }
                if ( ! ring_list_islist(pList,nRow) ) {
                    RING_API_ERROR("The selected row is not a list");
                    return ;
                }
                nStart = 1 ;
                pRow = ring_list_getlist(pList,nRow) ;
                nEnd = ring_list_getsize(pRow) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"col") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 2 ;
                nCol = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
                nStart = 1 ;
                nEnd = ring_list_getsize(pList) ;
                iValue = (int) RING_API_GETNUMBER(5) ;
                if ( nCol < 1 ) {
                    RING_API_ERROR("The selected column is outside the range of the list");
                    return ;
                }
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"manyrows") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 3 ;
                nStart = (int) RING_API_GETNUMBER(4) ;
                nEnd = (int) RING_API_GETNUMBER(5) ;
                nValue = RING_API_GETNUMBER(6) ;
                if ( (nStart < 1) || (nStart > ring_list_getsize(pList)) || (nEnd < 1) || 
			(nEnd > ring_list_getsize(pList)) || (nEnd < nStart) ) {
                    RING_API_ERROR("The selected rows are outside the range of the list");
                    return ;
                }
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"manycols") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 4 ;
                nStart = (int) RING_API_GETNUMBER(4) ;
                nEnd = (int) RING_API_GETNUMBER(5) ;
                nValue = RING_API_GETNUMBER(6) ;
                if ( (nStart < 1) || (nEnd < 1)  || (nEnd < nStart) ) {
                    RING_API_ERROR("The selected columns are outside the range of the list");
                    return ;
                }
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"items") == 0 ) {
        if ( RING_API_PARACOUNT == 4 ) {
            if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 5 ;
                nValue = RING_API_GETNUMBER(4) ;
                nStart = 1 ;
                nEnd = ring_list_getsize(pList) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else {
        RING_API_ERROR("The third parameter must be a string: [ Row | Col | ManyRows | ManyCols | Items ]");
        return ;
    }
    /* Set the operation code */
    if ( strcmp(cOperation,"set") == 0 ) {
        nOPCode += 100 ;
    }
    else if ( strcmp(cOperation,"add") == 0 ) {
        nOPCode += 200 ;
    }
    else if ( strcmp(cOperation,"sub") == 0 ) {
        nOPCode += 300 ;
    }
    else if ( strcmp(cOperation,"mul") == 0 ) {
        nOPCode += 400 ;
    }
    else if ( strcmp(cOperation,"div") == 0 ) {
        nOPCode += 500 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }
    else if ( strcmp(cOperation,"copy") == 0 ) {
        nOPCode += 600 ;
        if ( nValue <= 0 ) {
            RING_API_ERROR("Wrong column index.");
            return ;
        }
    }
    else if ( strcmp(cOperation,"merge") == 0 ) {
        nOPCode += 700 ;
        if ( nValue <= 0 ) {
            RING_API_ERROR("Wrong column index.");
            return ;
        }
    }
    else {
        RING_API_ERROR("The second parameter must be a string: [Set | Add | Sub | Mul | Div | Copy | Merge ]");
        return ;
    }
    /* Execute */
    switch ( nOPCode ) {
        /* Set */
        case 101 :
            /* Set Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                ring_list_setdouble_gc(pVM->pRingState,pRow,x,nValue);
            }
            break ;
        case 102 :
            /* Set Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,nValue);
                    }
                }
            }
            break ;
        case 103 :
            /* Set Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        ring_list_setdouble_gc(pVM->pRingState,pRow,y,nValue);
                    }
                }
            }
            break ;
        case 104 :
            /* Set Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,nValue);
                        }
                    }
                }
            }
            break ;
        case 105 :
            /* Set Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                ring_list_setdouble_gc(pVM->pRingState,pList,x,nValue);
            }
            break ;
        /* Add */
        case 201 :
            /* Add to Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)+nValue);
                }
            }
            break ;
        case 202 :
            /* Add to Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+nValue);
                        }
                    }
                }
            }
            break ;
        case 203 :
            /* Add to Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)+nValue);
                        }
                    }
                }
            }
            break ;
        case 204 :
            /* Add to Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 205 :
            /* Add to Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)+nValue);
                }
            }
            break ;
        /* Sub */
        case 301 :
            /* Sub from Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)-nValue);
                }
            }
            break ;
        case 302 :
            /* Sub from Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)-nValue);
                        }
                    }
                }
            }
            break ;
        case 303 :
            /* Sub from Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)-nValue);
                        }
                    }
                }
            }
            break ;
        case 304 :
            /* Sub from Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)-nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 305 :
            /* Sub from Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)-nValue);
                }
            }
            break ;
        /* Mul */
        case 401 :
            /* Mul Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)*nValue);
                }
            }
            break ;
        case 402 :
            /* Mul Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)*nValue);
                        }
                    }
                }
            }
            break ;
        case 403 :
            /* Mul cells in Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)*nValue);
                        }
                    }
                }
            }
            break ;
        case 404 :
            /* Mul cells in Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)*nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 405 :
            /* Mul Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)*nValue);
                }
            }
            break ;
        /* Div */
        case 501 :
            /* Div Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)/nValue);
                }
            }
            break ;
        case 502 :
            /* Div Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)/nValue);
                        }
                    }
                }
            }
            break ;
        case 503 :
            /* Div cells in Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y)/nValue);
                        }
                    }
                }
            }
            break ;
        case 504 :
            /* Div cells in Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)/nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 505 :
            /* Div Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x)/nValue);
                }
            }
            break ;
        /* Copy */
        case 601 :
            /* Copy Row */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;
                for ( x = nStart ; x <= nEnd ; x++ ) {
                    if ( x <= ring_list_getsize(pRow2) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pRow2,x,ring_list_getdouble(pRow,x));
                    }
                }
            }
            break ;
        case 602 :
            /* Copy Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nValue,ring_list_getdouble(pSubList,nCol));
                        }
                    }
                }
            }
            break ;
        case 603 :
            /* Copy to Many Rows */
		RING_API_ERROR("The copy operation is not defined for many rows");
            break ;
        case 604 :
            /* Copy to Many Columns */
		RING_API_ERROR("The copy operation is not defined for many columns");
            break ;
        case 605 :
            /* Copy Items */
                RING_API_ERROR("The copy operation is not defined for all of the list items");
            break ;
        /* Merge */
        case 701 :
            /* Merge two rows */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;
                for ( x = nStart ; x <= nEnd ; x++ ) {
                    if ( x <= ring_list_getsize(pRow2) ) {
			if (ring_list_isdouble(pRow2,x)) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,x,ring_list_getdouble(pRow,x)+
									ring_list_getdouble(pRow2,x));
			}
                    }
                }
            }
            break ;
        case 702 :
            /* Merge two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
			    ring_list_getdouble(pSubList,nCol)+ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;
        case 703 :
            /* Merge and Many Rows */
		RING_API_ERROR("The merge operation is not defined for many rows");
            break ;
        case 704 :
            /* Merge and Many Columns */
		RING_API_ERROR("The merge operation is not defined for many columns");
            break ;
        case 705 :
            /* Merge Items */
		RING_API_ERROR("The merge operation is not defined for all of the list items");
            break ;
    }
}

int ring_getnewinstruciton(void *pPointer, int *nStart,char **cCommand,int *nCol, int *iValue, double *dValue) {
	int nPos,nCount;
	nPos = *nStart;
	nCount = nPos + 2 ;
	if (RING_API_PARACOUNT < nCount) {
		return 0;
	}
	if ( ! ( RING_API_ISSTRING(nPos) && RING_API_ISNUMBER(nPos+1) && RING_API_ISNUMBER(nPos+2) ) ) {
		return 0;
	}
	*cCommand = RING_API_GETSTRING(nPos);
	*nCol = (int) RING_API_GETNUMBER(nPos+1);
	*iValue = (int) RING_API_GETNUMBER(nPos+2);
	*dValue = RING_API_GETNUMBER(nPos+2);
	*nStart = nPos+3;
	return 1;
}

RING_FUNC(ring_updatecolumn)
{
	List *pList, *pSubList;
	int nPos,nCol,iValue;
	char *cCommand;
	double dValue;
	int aInsOPCode[100];
	int aInsCol[100];
	int aInsiValue[100];
	double aInsdValue[100];
	int nCurrentIns,nInsCount;
	VM *pVM  ;
	nCurrentIns = 0;
	nInsCount   = 0;
	pVM = (VM *) pPointer ;

	if (RING_API_PARACOUNT < 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);	
		return ;
	}
	if ( ! RING_API_ISLIST(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	pList = RING_API_GETLIST(1);

	// Get Instructions
	nPos = 2;	// Start getting new instruction from the second parameter 
	while ( ring_getnewinstruciton(pPointer, &nPos, &cCommand, &nCol, &iValue, &dValue) ) {
		if ( strcmp(cCommand,"set") == 0 ) {
			aInsOPCode[nCurrentIns] = 1;
		} else if ( strcmp(cCommand,"add") == 0 ) {
			aInsOPCode[nCurrentIns] = 2;
		} else if ( strcmp(cCommand,"sub") == 0 ) {
			aInsOPCode[nCurrentIns] = 3;
		} else if ( strcmp(cCommand,"mul") == 0 ) {
			aInsOPCode[nCurrentIns] = 4;
		} else if ( strcmp(cCommand,"div") == 0 ) {
			aInsOPCode[nCurrentIns] = 5;
		} else if ( strcmp(cCommand,"merge") == 0 ) {
			aInsOPCode[nCurrentIns] = 6;
		} else if ( strcmp(cCommand,"copy") == 0 ) {
			aInsOPCode[nCurrentIns] = 7;
		}
		aInsCol[nCurrentIns]    = nCol;
		aInsiValue[nCurrentIns] = iValue;
		aInsdValue[nCurrentIns] = dValue;
		nCurrentIns++; 
	}
			
	nInsCount = nCurrentIns ;

	for ( int x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_islist(pList,x) ) {
			pSubList = ring_list_getlist(pList,x) ;

			nCurrentIns = 0;
			while ( nCurrentIns < nInsCount ) {
		
				nCol   = aInsCol[nCurrentIns];
				iValue = aInsiValue[nCurrentIns];
				dValue = aInsdValue[nCurrentIns];
 		
			// Execute Instruction
			if ( aInsOPCode[nCurrentIns] == 1 ) {
			} else if ( aInsOPCode[nCurrentIns] == 2 ) {
			} else if ( aInsOPCode[nCurrentIns] == 3 ) {
			} else if ( aInsOPCode[nCurrentIns] == 4 ) {
				if ( ring_list_isdouble(pSubList,nCol) ) {
					ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
					ring_list_getdouble(pSubList,nCol)*dValue);
				}
			} else if ( aInsOPCode[nCurrentIns] == 5 ) {
			} else if ( aInsOPCode[nCurrentIns] == 6 ) {
				if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= iValue) ) {
					if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,iValue) ) {
						ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
						ring_list_getdouble(pSubList,nCol)+ring_list_getdouble(pSubList,iValue));
					}
				}
			} else if ( aInsOPCode[nCurrentIns] == 7 ) {
				if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= iValue) ) {
					if ( ring_list_isdouble(pSubList,nCol) ) {
						ring_list_setdouble_gc(pVM->pRingState,pSubList,iValue,
						ring_list_getdouble(pSubList,nCol));
					}
				}
			}

			nCurrentIns++;
			}

			nPos = 2;
		}
	}
}

RING_LIBINIT
{
    RING_API_REGISTER("bytes2list",ring_bytes2list);
    RING_API_REGISTER("list2bytes",ring_list2bytes);
    RING_API_REGISTER("updatelist",ring_updatelist);
    RING_API_REGISTER("updatecolumn",ring_updatecolumn);
}
