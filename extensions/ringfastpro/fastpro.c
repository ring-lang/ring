/*
** ListPro extension
** 2023, Mahmoud Fayed
** 2024, Bert Mariani (Added DestCol support in updateList() as a six parameter)
** 2025, Bert Mariani (Added mergemul - multiply 2 rows or 2 col ==> dCol dDestination
** 2025, Bert Mariani (Added mergesub, mergediv,
**                    (Added Row Destination => pRowD if Param = 6
*/

#include "ring.h"
#include "stdlib.h"
#include "fastpro.h"

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
            pList = RING_API_NEWLISTUSINGBLOCKS2D(nPointsCount,3);
            pVM = (VM *) pPointer;
        for (int y=1 ; y <= nHeight ; y++ ) {
        for (int x=1 ; x <= nWidth ; x++ ) {
            pSubList = ring_list_getlist(pList,nPoint++);
            if (nDivide == 0) {
                ring_list_setdouble_gc(pVM->pRingState,pSubList,1,(double) pData[nIndex++]);
                ring_list_setdouble_gc(pVM->pRingState,pSubList,2,(double) pData[nIndex++]);
                ring_list_setdouble_gc(pVM->pRingState,pSubList,3,(double) pData[nIndex++]);
            } else {
                ring_list_setdouble_gc(pVM->pRingState,pSubList,1,( (double) pData[nIndex++] ) / nDivide);
                ring_list_setdouble_gc(pVM->pRingState,pSubList,2,( (double) pData[nIndex++] ) / nDivide);
                ring_list_setdouble_gc(pVM->pRingState,pSubList,3,( (double) pData[nIndex++] ) / nDivide);
            }
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
    size_t nDataSize;
    int nListSize,nIndex,x,lError,nPointListSize,nChannel,nMul;
    pVM = (VM *) pPointer;
    nMul = 1;
    nChannel = 3;
    double nRed,nGreen,nBlue,nAlpha;
    nAlpha = 1.0;
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

    if ( RING_API_PARACOUNT >= 3 )
        if ( RING_API_ISNUMBER(3) )
            nMul = (int) RING_API_GETNUMBER(3);

    if ( RING_API_PARACOUNT >= 4 )
        if ( RING_API_ISNUMBER(4) )
            nAlpha = RING_API_GETNUMBER(4);

    pList = RING_API_GETLIST(1);
    nListSize = ring_list_getsize(pList);
    if ( nListSize < 1 ) return ;

    nDataSize = sizeof(char) * nListSize * nChannel;
    cData = (char *) RING_API_MALLOC(nDataSize);

    nIndex = 0;
    lError = 0;

    for ( x=1 ; x <= nListSize ; x++ ) {

        if ( ! ring_list_islist(pList,x) ){
            lError = 1;
            break;
        }

        pPointList = ring_list_getlist(pList,x);
        nPointListSize = ring_list_getsize(pPointList);
        if ( nPointListSize < 3 ) {
            lError = 1;
            break;
        }

        if ( ring_list_isdouble(pPointList,1) && ring_list_isdouble(pPointList,2) &&
             ring_list_isdouble(pPointList,2) ) {
             nRed   = ring_list_getdouble(pPointList,1);
             nGreen = ring_list_getdouble(pPointList,2);
             nBlue  = ring_list_getdouble(pPointList,3);
             if (nRed   > 1) nRed   = 1;
             if (nGreen > 1) nGreen = 1;
             if (nBlue  > 1) nBlue  = 1;
             cData[nIndex++] = (char) (nRed*nMul);
             cData[nIndex++] = (char) (nGreen*nMul);
             cData[nIndex++] = (char) (nBlue*nMul);
        } else {
            lError = 1;
            break;
        }

        if ( nChannel == 4)
            cData[nIndex++] = (char) (nAlpha*nMul);
    }

    if ( lError == 1 ) {
            RING_API_FREE(cData);
            RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }

    RING_API_RETSTRING2(cData,nDataSize);
    RING_API_FREE(cData);
}

//===========================================================
// FOR UPDATELIST()
//
//       Param  1       2    3         4           5        6
//  updateList(<aList>,:add,:row,     <nRow>,     <nValue>, <nDest>)
//  updateList(<aList>,:add,:col,     <nCol>,     <nValue>, <nDest>)
//  updateList(<aList>,:add,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
//  updateList(<aList>,:add,:manycols,<nColStart>,<nColEnd>,<nValue>)
//
//  aListC = updateList(<aList>,:add,:matrix,<aListB>)
//  aListC = updateList(<aList>,:sub,:matrix,<aListB>)
//  aListC = updateList(<aList>,:mul,:matrix,<aListB>)
//  aListC = updateList(<aList>,:transpose,:matrix )    // 3 Parms
//  aListC = updateList(<aList>,:scalar,<nValue> )
//
//  Set the Operation code. Add Selection Code for Jump => 503
//  strcmp(cOperation,"set")       nOPCode += 100 ;
//  strcmp(cOperation,"add")       nOPCode += 200 ;
//  strcmp(cOperation,"sub")       nOPCode += 300 ;
//  strcmp(cOperation,"mul")       OPCode  += 400 ;
//  strcmp(cOperation,"div")       nOPCode += 500 ;
//  strcmp(cOperation,"copy")      nOPCode += 600 ;
//  strcmp(cOperation,"merge")     nOPCode += 700 ;
//  strcmp(cOperation,"serial")    nOPCode += 800 ;
//  strcmp(cOperation,"pow")       nOPCode += 900 ;
//  strcmp(cOperation,"rem")       nOPCode += 1000 ;
//  strcmp(cOperation,"mergesub")  nOPCode += 1100 ;
//  strcmp(cOperation,"mergemul")  nOPCode += 1200 ;
//  strcmp(cOperation,"mergediv")  nOPCode += 1300 ;
//  strcmp(cOperation,"transpose") nOPCode += 1400 ;   // Transpose-Matrix 1406
//  strcmp(cOperation,"scalar")    nOPCode += 1500 ;   // Scalar-Matrix 1506
//
//  Set the Selection Code
//  strcmp(cSelection,"row")       nOPCode = 1 ;
//  strcmp(cSelection,"col")       nOPCode = 2 ;
//  strcmp(cSelection,"manyrows")  nOPCode = 3 ;
//  strcmp(cSelection,"manycols")  nOPCode = 4 ;
//  strcmp(cSelection,"items")     nOPCode = 5 ;
//  strcmp(cSelection,"matrix")    nOPCode = 6 ;       // Add, Sub, Mul -- Matrix
//a
//===============================================================


RING_FUNC(ring_updatelist)
{
    char *cOperation  ;
    char *cSelection  ;
    List *pList, *pSubList, *pRow, *pRow2  ;
    int   nOPCode,nRow,nCol,nStart,nEnd,iValue  ;

    //=====================================
    // Add MATRIX pList + pListB => pListC
    List *pListB, *pListC, *pRowB, *pRowC ;
    int   nRowB, nColB, nStartB, nEndB;
    int   nRowC, nColC, nStartC, nEndC;

    int   dCol ;  // Dest Column if Parm 6
    int   dRow ;  // Dest Row    if Parm 6
    List *pRowD ; // Dest Row    if Parm 6

    double Sum, valueA, valueB, valueC ;           // Matrix Multiply
    int    i, j ;
    int    vA,  hB, k ;
    int    sizeX, sizeY ;
    List  *pSubListA,*pSubListB, *pSubListC ;

    String *pString ;                              // Use to Debug - message

    //======================================

    int x,y  ;
    double nValue  ;
    VM *pVM  ;
    /* Get VM pointer */
    pVM = (VM *) pPointer ;

    //========================
    /* Check Parameters */

    if ( (RING_API_PARACOUNT < 3) || (RING_API_PARACOUNT > 6) ) {
        //RING_API_ERROR(RING_API_BADPARACOUNT);
          RING_API_ERROR("BADPARACOUNT must be between 3:6");

        return ;
    }

    //------------------ aList        nOpCode(100-1300)      SecectionCode(1-6)
    if ( ! ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }

    //======================
    /* Get Parameters */

    pList      =          RING_API_GETLIST(1) ;
    cOperation = (char *) RING_API_GETSTRING(2) ;
    cSelection = (char *) RING_API_GETSTRING(3) ;

    cOperation = ring_string_lower(cOperation);
    cSelection = ring_string_lower(cSelection);

    if ( ring_list_getsize(pList) == 0 ) {
        /* For empty lists, we does nothing! */
        return ;
    }

    //==============================
    /* Set instruction values */

    nOPCode = 0 ;
    nRow = 0 ;
    nCol = 0 ;
    dCol = 0 ;      // Dest Column if Param 6
    dRow = 0 ;      // Dest Row    if Param 6
    nStart = 0 ;
    nEnd   = 0 ;
    pRow   = NULL ;
    pRowD  = NULL ; // Dest Row

    pListB = NULL ; // Add MATRIX pListA + pListB => pListC
    pListC = NULL ;

    //===============================================

    // ROW SELECTION

    if ( strcmp(cSelection,"row") == 0 ) {
        if ( RING_API_PARACOUNT == 5 || RING_API_PARACOUNT == 6)
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 1 ;
                nRow    = (int) RING_API_GETNUMBER(4) ;
                nValue  =       RING_API_GETNUMBER(5) ;
                iValue  = (int) RING_API_GETNUMBER(5) ;

                // Dest Row ------
                pRowD = ring_list_getlist(pList,nRow) ; // Default
                if ( RING_API_PARACOUNT == 6 )
                {
                    dRow  = (int) RING_API_GETNUMBER(6) ; // Dest Row    = Param 6
                    pRowD = ring_list_getlist(pList,dRow) ;
                }


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

        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }

    // COL SELECTION
    else if ( strcmp(cSelection,"col") == 0 ) {
    if ( RING_API_PARACOUNT == 5 || RING_API_PARACOUNT == 6) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 2 ;
                nCol   = (int) RING_API_GETNUMBER(4) ;   // Dest Col
                nRow   = (int) RING_API_GETNUMBER(4) ;   // Dest Row
                nValue =       RING_API_GETNUMBER(5) ;   // Value to Add Sub etc

                dCol = nCol ;  // Dest Column - Param 4 Default
                dRow = nRow ;  // Dest Row    - Param 4

        if ( RING_API_PARACOUNT == 6 )
        {
            dCol  = (int) RING_API_GETNUMBER(6) ; // Dest Column = Param 6
            dRow  = (int) RING_API_GETNUMBER(6) ; // Dest Row    = Param 6
        }

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

    // MANYROWS
    else if ( strcmp(cSelection,"manyrows") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 3 ;
                nStart = (int) RING_API_GETNUMBER(4) ;
                nEnd   = (int) RING_API_GETNUMBER(5) ;
                nValue =       RING_API_GETNUMBER(6) ;

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

    // MANYCOLS
    else if ( strcmp(cSelection,"manycols") == 0 ) {
        if ( RING_API_PARACOUNT == 6 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6) ) {
                nOPCode = 4 ;
                nStart  = (int) RING_API_GETNUMBER(4) ;
                nEnd    = (int) RING_API_GETNUMBER(5) ;
                nValue  =       RING_API_GETNUMBER(6) ;

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

    // ITEMS
    else if ( strcmp(cSelection,"items") == 0 ) {
        if ( RING_API_PARACOUNT == 4 ) {
            if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 5 ;
                nValue  = RING_API_GETNUMBER(4) ;
                nStart  = 1 ;
                nEnd    = ring_list_getsize(pList) ;
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

    //============================================
    // MATRIX aList
    // updateList(<aList>,:add,      :matrix,<aListB>)          ADD       4 Params
	//  aListC = updateList(<aList>,:scalar,   <nValue> )       SCALAR    4 = Number
    //  aListC = updateList(<aList>,:transpose,:matrix)         TRANSPOSE 3 Params

    else if ( strcmp(cSelection,"matrix") == 0 ) {
        if ( RING_API_PARACOUNT == 3 || RING_API_PARACOUNT == 4 ) {

            if ( RING_API_PARACOUNT == 3) {
                   nOPCode = 6 ;
				   nValue  = 1;
                 //pList   = RING_API_GETLIST(1) ;     // Transpose
            }
            else if ( RING_API_ISLIST(4) ) {
                nOPCode = 6 ;
              //pList   = RING_API_GETLIST(1) ;
                pListB  = RING_API_GETLIST(4) ;
            }   
            else if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 6 ;
              //pList   = RING_API_GETLIST(1) ;
                nValue  = (int) RING_API_GETNUMBER(4) ;  // Scalar-nValue , 0=BAD          
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

    //=================================


    //==========================================
    /* SET THE OPERATION CODE */

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
    else if ( strcmp(cOperation,"serial") == 0 ) {
        nOPCode += 800 ;
    }
    else if ( strcmp(cOperation,"pow") == 0 ) {
        nOPCode += 900 ;
    }
    else if ( strcmp(cOperation,"rem") == 0 ) {
        nOPCode += 1000 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }

    else if ( strcmp(cOperation,"mergesub") == 0 ) {
        nOPCode += 1100 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }
    else if ( strcmp(cOperation,"mergemul") == 0 ) {
        nOPCode += 1200 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }

    else if ( strcmp(cOperation,"mergediv") == 0 ) {
        nOPCode += 1300 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }

    else if ( strcmp(cOperation,"transpose") == 0 ) {
        nOPCode += 1400 ;
    }

    else if ( strcmp(cOperation,"scalar") == 0 ) {
        nOPCode += 1500 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't multiply by zero");
            return ;
        }
    }

    else {
        RING_API_ERROR("The second parameter must be a string: [Set | Add | Sub | Mul | Div | Copy | Merge | MergeSub |  MergeMul | MergeDiv |");
        return ;
    }

    //================================

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

        //====================

        case 201 :
            /* Add to Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                     ring_list_setdouble_gc(pVM->pRingState,pRowD, x,ring_list_getdouble(pRow, x)+nValue);
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
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol, ring_list_getdouble(pSubList,nCol) + nValue);
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

        //===============================================
        case 206 :
            /* Add Matrix 5X5  aList + aListB => aListC */

            //  pListA = RING_API_GETLIST(1) ;
                pListB = RING_API_GETLIST(4) ;

                nStart = 1 ;
                nRow   = ring_list_getsize(pList);      // 5 Row
                pRow   = ring_list_getlist(pList, nRow);
                nEnd   = ring_list_getsize(pRow) ;      // 5 Col

                nStartB = 1 ;
                nRowB   = ring_list_getsize(pListB) ;
                pRowB   = ring_list_getlist(pListB, nRowB);
                nEndB   = ring_list_getsize(pRowB) ;


                //--- CREATE Output List - Outside Dims.-----
                sizeX   = nRow  ;  sizeY   = nEnd ;
                pListC  = RING_API_NEWLISTUSINGBLOCKS2D( sizeX, sizeY) ;

                nRowC   = ring_list_getsize(pListC) ;        // 5=Row-C vert
                pRowC   = ring_list_getlist(pListC,nRowC);
                nEndC   = ring_list_getsize(pRowC) ;         // 4=Col-C horz
               //------------------------------------

            if ((nEnd = nEndB) && (nRow = nRowB)){

                /* Add MATRIX to ManyRows */
                for ( x = nStart ; x <= nEnd ; x++ ) {

                    if ( ring_list_islist(pList,x) ) {

                        pRow  = ring_list_getlist(pList, x) ;
                        pRowB = ring_list_getlist(pListB,x) ;
                        pRowC = ring_list_getlist(pListC,x) ;

                        for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {

                            if ( ring_list_isdouble(pRow,y) ) {

                                 valueA = ring_list_getdouble(pRow, y);
                                 valueB = ring_list_getdouble(pRowB,y);
                                 valueC = valueA + valueB;

                                 ring_list_setdouble_gc(pVM->pRingState,pRowC,y, valueC);
                            }
                        }
                    }
                }

                RING_API_RETLIST( pListC );
                break ;

            } else {
                RING_API_ERROR("Add MATRIX A+B Not same size, Row and Col");
                return ;
            }

        //========================================

        /* Sub */
        case 301 :
            /* Sub from Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRowD,x,ring_list_getdouble(pRow,x)-nValue);
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
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,ring_list_getdouble(pSubList,nCol) - nValue);
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

        //===============================================
        case 306 :
            /* Sub Matrix 5X5  aList - aListB => aListC */

            //  pList  = RING_API_GETLIST(1) ;
                pListB = RING_API_GETLIST(4) ;

                nStart = 1 ;
                nRow   = ring_list_getsize(pList);      // 5 Row
                pRow   = ring_list_getlist(pList,nRow);
                nEnd   = ring_list_getsize(pRow) ;      // 5 Col

                nStartB = 1 ;
                nRowB   = ring_list_getsize(pListB) ;
                pRowB   = ring_list_getlist(pListB,nRowB);
                nEndB   = ring_list_getsize(pRowB) ;

                //--- CREATE Output List - Outside Dims.-----
                sizeX   = nRow  ;  sizeY   = nEnd ;
                pListC  = RING_API_NEWLISTUSINGBLOCKS2D( sizeX, sizeY) ;

                nRowC   = ring_list_getsize(pListC) ;        // 5=Row-C vert
                pRowC   = ring_list_getlist(pListC,nRowC);
                nEndC   = ring_list_getsize(pRowC) ;         // 4=Col-C horz
               //------------------------------------

            if ((nEnd = nEndB) && (nRow = nRowB)){

                /* Add MATRIX to ManyRows */
                for ( x = nStart ; x <= nEnd ; x++ ) {

                    if ( ring_list_islist(pList,x) ) {

                        pRow  = ring_list_getlist(pList, x) ;
                        pRowB = ring_list_getlist(pListB,x) ;
                        pRowC = ring_list_getlist(pListC,x) ;

                        for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {

                            if ( ring_list_isdouble(pRow,y) ) {

                                 valueA = ring_list_getdouble(pRow, y);
                                 valueB = ring_list_getdouble(pRowB,y);
                                 valueC = valueA - valueB;

                                 ring_list_setdouble_gc(pVM->pRingState,pRowC,y, valueC);
                            }
                        }
                    }
                }

                RING_API_RETLIST( pListC );
                break ;

            } else {
                RING_API_ERROR("Sub MATRIX A+B Not same size, Row and Col");
                return ;
            }
        //========================================

        /* Mul */
        case 401 :
            /* Mul Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                     ring_list_setdouble_gc(pVM->pRingState,pRowD,x, ring_list_getdouble(pRow,x) * nValue);
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
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol, ring_list_getdouble(pSubList,nCol) * nValue);
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



        //------------------------------------------------------------

        case 406 :
            /* Mul Matrix A*B => C */

        // pList  = RING_API_GETLIST(1) ;
           pListB = RING_API_GETLIST(4) ;



           nRow   = ring_list_getsize(pList);           // 5 Row-A vert for vA = 1 to vertA
           pRow   = ring_list_getlist(pList,nRow);
           nEnd   = ring_list_getsize(pRow) ;           // 3 Col-A horz for k = 1 to horzA


           nRowB   = ring_list_getsize(pListB) ;        // 3 Row-B vert
           pRowB   = ring_list_getlist(pListB,nRowB);
           nEndB   = ring_list_getsize(pRowB) ;         // 4 Col-C horz for hB = 1 to horzB

           //--- CREATE Output List - Outside Dims.-----
           sizeX   = nRow  ;  sizeY   = nEndB ;
           pListC  = RING_API_NEWLISTUSINGBLOCKS2D( sizeX, sizeY) ;

           nRowC   = ring_list_getsize(pListC) ;        // 5=Row-C vert
           pRowC   = ring_list_getlist(pListC,nRowC);
           nEndC   = ring_list_getsize(pRowC) ;         // 4=Col-C horz
           //------------------------------------

            for (vA = 1; vA <= nRow; vA++)
            {   for (hB = 1; hB <= nEndB; hB++)
                {
                    Sum = 0;

                    for (k = 1; k <=  nEnd; k++)
                    {   // Sum += A[vA][k] * B[k][hB]
                        //         R   C      R  C

                         pSubList  = ring_list_getlist(pList,  vA) ;          // Row-A  vA
                         valueA    = ring_list_getdouble( pSubList, k ) ;     // Col     k

                         pSubListB = ring_list_getlist(pListB, k) ;           // Row-B   k
                         valueB    = ring_list_getdouble( pSubListB, hB ) ;   // Col    hB

                         valueC    = valueA * valueB ;
                         Sum      += valueC  ;
                    }

                    // C[va][hB] = Sum

                    pSubListC = ring_list_getlist(pListC, vA ) ;                  // Row#
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, Sum );  // Col#

                }
            }

            RING_API_RETLIST( pListC );
            break ;

        //======================================================

        /* Div */
        case 501 :
            /* Div Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRowD,x,ring_list_getdouble(pRow,x)/nValue);
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
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol, ring_list_getdouble(pSubList,nCol) / nValue);
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
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,ring_list_getdouble(pRow,y) / nValue);
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
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol) / nValue);
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
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,ring_list_getdouble(pList,x) / nValue);
                }
            }
            break ;

        //===========================

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
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,nValue, ring_list_getdouble(pSubList,nCol));
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
            /* Merge (ADD) two rows */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;
                for ( x = nStart ; x <= nEnd ; x++ ) {
                    if ( x <= ring_list_getsize(pRow2) ) {
                    if (ring_list_isdouble(pRow2,x)) {
                             ring_list_setdouble_gc(pVM->pRingState,pRowD,x,
                             ring_list_getdouble(pRow,x) + ring_list_getdouble(pRow2,x));
                    }
                    }
                }
            }
            break ;
        case 702 :
            /* Merge ADD two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                            ring_list_getdouble(pSubList,nCol) + ring_list_getdouble(pSubList,nValue));
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

        //========================
        case 801 :
            /* Serial Row */
            if ( ring_list_islist(pList,nRow) ) {
                pRow2 = ring_list_getlist(pList,nRow) ;
                for ( x = nStart ; x <= nEnd ; x++ ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow2,x, x+nValue);
                }
            }
            break ;
        case 802 :
            /* Serial Column */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                            x + nValue);
                        }
                    }
                }
            }
            break ;

        case 803 :
            /* Serial ManyRows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                             ring_list_setdouble_gc(pVM->pRingState,pRow,y,
                             ring_list_getdouble(pRow,y) + nValue);
                        }
                    }
                }
            }
            break ;



        case 804 :
            /* Serial ManyCols */

            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                                ring_list_getdouble(pSubList,nCol) + nValue);
                            }
                        }
                    }
                }
            }
            break ;

        //========================

        /* Pow */
        case 901 :
            /* Pow Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,
                    pow(ring_list_getdouble(pRow,x),nValue) );
                }
            }
            break ;
        case 902 :
            /* Pow Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                             pow(ring_list_getdouble(pSubList,nCol),nValue));
                        }
                    }
                }
            }
            break ;

       case 903 :
           /* Pow cells in Many Rows */
           for ( x = nStart ; x <= nEnd ; x++ ) {
               if ( ring_list_islist(pList,x) ) {
                   pRow = ring_list_getlist(pList,x) ;

                   for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                       if ( ring_list_isdouble(pRow,y) ) {
                           ring_list_setdouble_gc(pVM->pRingState,pRow,y,
                           pow(ring_list_getdouble(pRow,y), nValue) );
                       }
                   }
               }
           }
           break ;


        case 904 :
            /* Pow ManyCols */

            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                                pow(ring_list_getdouble(pSubList,nCol) , nValue));
                            }
                        }
                    }
                }
            }
            break ;


        case 905 :
            /* Pow Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,
                    pow(ring_list_getdouble(pList,x), nValue));
                }
            }
            break ;

        //===========================

        /* Rem */
        case 1001 :
            /* Rem Row */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pRow,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pRow,x,
            (int) ring_list_getdouble(pRow,x) % (int) nValue);
                }
            }
            break ;

        case 1002 :
            /* Rem Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                (int) ring_list_getdouble(pSubList,nCol) % (int) nValue);
                        }
                    }
                }
            }
            break ;

        case 1003 :
            /* Rem cells in Many Rows */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pRow = ring_list_getlist(pList,x) ;
                    for ( y = 1 ; y <= ring_list_getsize(pRow) ; y++ ) {
                        if ( ring_list_isdouble(pRow,y) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pRow,y,
                (int) ring_list_getdouble(pRow,y) % (int) nValue);
                        }
                    }
                }
            }
            break ;
        case 1004 :
            /* Rem cells in Many Columns */
            for ( nCol = nStart ; nCol <= nEnd ; nCol++ ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( ring_list_islist(pList,x) ) {
                        pSubList = ring_list_getlist(pList,x) ;
                        if ( ring_list_getsize(pSubList) >= nCol ) {
                            if ( ring_list_isdouble(pSubList,nCol) ) {
                                 ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                           (int) ring_list_getdouble(pSubList,nCol) % (int) nValue);
                            }
                        }
                    }
                }
            }
            break ;
        case 1005 :
            /* Rem Items */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_isdouble(pList,x) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pList,x,
              (int) ring_list_getdouble(pList,x) % (int) nValue);
                }
            }
            break ;

            //================================================

        case 1101 :
            /* Merge-Subtract two rows */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;

                for ( x = nStart ; x <= nEnd ; x++ ) {

                    if ( x <= ring_list_getsize(pRow2) ) {

                        if (ring_list_isdouble(pRow2,x)) {
                             ring_list_setdouble_gc(pVM->pRingState,pRowD,x,
                             ring_list_getdouble(pRow,x) - ring_list_getdouble(pRow2,x));
                        }
                    }
                }
            }
            break ;

        case 1102 :
            /* Merge-Subtract two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {

                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;

                    if ( (ring_list_getsize(pSubList) >= nCol) &&
                         (ring_list_getsize(pSubList) >= nValue) ) {

                        if ( ring_list_isdouble(pSubList,nCol) &&
                             ring_list_isdouble(pSubList,nValue) ) {
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                             ring_list_getdouble(pSubList,nCol) - ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;


            //================================================

        case 1201 :
            /* Merge-Multiply two rows */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;

                for ( x = nStart ; x <= nEnd ; x++ ) {

                    if ( x <= ring_list_getsize(pRow2) ) {

                        if (ring_list_isdouble(pRow2,x)) {
                             ring_list_setdouble_gc(pVM->pRingState,pRowD,x,
                             ring_list_getdouble(pRow,x) * ring_list_getdouble(pRow2,x));
                        }
                    }
                }
            }
            break ;

        case 1202 :
            /* Merge-Multiply two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {

                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;

                    if ( (ring_list_getsize(pSubList) >= nCol) &&
                         (ring_list_getsize(pSubList) >= nValue) ) {

                        if ( ring_list_isdouble(pSubList,nCol) &&
                             ring_list_isdouble(pSubList,nValue) ) {
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                             ring_list_getdouble(pSubList,nCol) * ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;

            //================================================

        case 1301 :
            /* Merge-Divide two rows */
            if ( (iValue < 1) ||  (iValue > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("The selected row is outside the range of the list");
                return ;
            }
            if ( ring_list_islist(pList,iValue) ) {
                pRow2 = ring_list_getlist(pList,iValue) ;

                for ( x = nStart ; x <= nEnd ; x++ ) {

                    if ( x <= ring_list_getsize(pRow2) ) {

                        if (ring_list_isdouble(pRow2,x)) {
                             ring_list_setdouble_gc(pVM->pRingState,pRowD,x,
                             ring_list_getdouble(pRow,x) / ring_list_getdouble(pRow2,x));
                        }
                    }
                }
            }
            break ;

        case 1302 :
            /* Merge-Divide two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {

                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;

                    if ( (ring_list_getsize(pSubList) >= nCol) &&
                         (ring_list_getsize(pSubList) >= nValue) ) {

                        if ( ring_list_isdouble(pSubList,nCol) &&
                             ring_list_isdouble(pSubList,nValue) ) {
                             ring_list_setdouble_gc(pVM->pRingState,pSubList,dCol,
                             ring_list_getdouble(pSubList,nCol) / ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;

        //==============================================

        case 1406 :
            /* Transpose Matrix-A ==> MatriX-C */

           // pList  = RING_API_GETLIST(1) ;

           nRow   = ring_list_getsize(pList);           //  Row-A
           pRow   = ring_list_getlist(pList,nRow);
           nEnd   = ring_list_getsize(pRow) ;           //  Col-A

           //--- CREATE Output List - Same Dims.-----
           pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nEnd, nRow ); // Reverse Col,Row Rect

           nRowC   = ring_list_getsize(pListC) ;        // Row-C vert
           pRowC   = ring_list_getlist(pListC,nRowC);
           nEndC   = ring_list_getsize(pRowC) ;         // Col-C horz
           //------------------------------------


            for (hB = 1; hB <= nEnd; hB++)      // Cols hB j
            {   for (vA = 1; vA <= nRow; vA++)   // Rows vA i
                {
                     pSubList  = ring_list_getlist(pList, hB) ;
                     valueA    = ring_list_getdouble( pSubList, vA ) ;

                     pSubListC = ring_list_getlist(pListC, vA ) ;
                     ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, valueA );
                }
            }

            RING_API_RETLIST( pListC );
            break ;


        //---------------------------------------
        
        case 1506 :
            /* Scalar Matrix-A  * K ==> MatriX-C */
           
            // pList  = RING_API_GETLIST(1) ;
                   k  = RING_API_GETNUMBER(4);
           
            nRow   = ring_list_getsize(pList);           //  Row-A
            pRow   = ring_list_getlist(pList,nRow);
            nEnd   = ring_list_getsize(pRow) ;           //  Col-A
           
            //--- CREATE Output List - Same Dims.-----
            pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd ); // R-C Rect
           
            nRowC   = ring_list_getsize(pListC) ;        // Row-C vert
            pRowC   = ring_list_getlist(pListC,nRowC);
            nEndC   = ring_list_getsize(pRowC) ;         // Col-C horz
            //------------------------------------
           
            for( vA = 1; vA <= nRow ; vA++)
            {   for( hB = 1; hB <= nEnd; hB++)
                { // aListC[vA][hB] = k * (aList[vA][hB])  

                  pSubList  = ring_list_getlist(pList, vA) ;        // Row
                  valueA    = ring_list_getdouble( pSubList, hB ) ; // Col
                  valueC    = valueA * k;

                  pSubListC = ring_list_getlist(pListC, vA ) ;
                  ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, valueC );
                }
            }       
        
            RING_API_RETLIST( pListC );
            break ;

         //===End 1506 ==============================

    //=== End CASES =================================
	
    }
}

//=================================================

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
    int aInsOPCode[C_INSCOUNT];
    int aInsCol[C_INSCOUNT];
    int aInsiValue[C_INSCOUNT];
    double aInsdValue[C_INSCOUNT];
    int nCurrentIns,nInsCount;
    VM *pVM  ;
    nCurrentIns = 0;
    nInsCount   = 0;
    pVM = (VM *) pPointer ;

    // Get the list
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
    nPos = 2;   // Start getting new instruction from the second parameter
    while ( ring_getnewinstruciton(pPointer, &nPos, &cCommand, &nCol, &iValue, &dValue) ) {
        if (nCurrentIns >= C_INSCOUNT) {
            RING_API_ERROR("Extra number of commands!");
            return;
        }
        if ( strcmp(cCommand,"set") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SET;
        } else if ( strcmp(cCommand,"add") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_ADD;
        } else if ( strcmp(cCommand,"sub") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SUB;
        } else if ( strcmp(cCommand,"mul") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_MUL;
        } else if ( strcmp(cCommand,"div") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_DIV;
        } else if ( strcmp(cCommand,"merge") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_MERGE;
        } else if ( strcmp(cCommand,"copy") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_COPY;
        } else if ( strcmp(cCommand,"serial") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SERIAL;
        } else if ( strcmp(cCommand,"pow") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_POW;
        } else if ( strcmp(cCommand,"rem") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_REM;
        }
        aInsCol[nCurrentIns]    = nCol;
        aInsiValue[nCurrentIns] = iValue;
        aInsdValue[nCurrentIns] = dValue;
        nCurrentIns++;
    }
    nInsCount = nCurrentIns ;

    // Execute instructions
    for ( int x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        if ( ring_list_islist(pList,x) ) {
            pSubList = ring_list_getlist(pList,x) ;
            for (nCurrentIns = 0 ; nCurrentIns < nInsCount ; nCurrentIns++) {
                nCol   = aInsCol[nCurrentIns];
                iValue = aInsiValue[nCurrentIns];
                dValue = aInsdValue[nCurrentIns];
                // Execute Instruction
                if ( aInsOPCode[nCurrentIns] == INS_SET ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        dValue);
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_ADD ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        ring_list_getdouble(pSubList,nCol)+dValue);
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_SUB ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        ring_list_getdouble(pSubList,nCol)-dValue);
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_MUL ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        ring_list_getdouble(pSubList,nCol)*dValue);
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_DIV ) {
                        if ( dValue == 0 ) {
                                RING_API_ERROR("Can't divide by zero");
                                return ;
                        }
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        ring_list_getdouble(pSubList,nCol)/dValue);
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_MERGE ) {
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= iValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,iValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                            ring_list_getdouble(pSubList,nCol)+ring_list_getdouble(pSubList,iValue));
                        }
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_COPY ) {
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= iValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,iValue,
                            ring_list_getdouble(pSubList,nCol));
                        }
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_SERIAL ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        x+dValue );
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_POW ) {
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        pow(ring_list_getdouble(pSubList,nCol),dValue) );
                    }
                } else if ( aInsOPCode[nCurrentIns] == INS_REM ) {
                        if ( dValue == 0 ) {
                                RING_API_ERROR("Can't divide by zero");
                                return ;
                        }
                    if ( ring_list_isdouble(pSubList,nCol) ) {
                        ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,
                        (int) ring_list_getdouble(pSubList,nCol) % (int) dValue);
                    }
                }
            }
        }
    }
}

RING_FUNC(ring_updatebytescolumn)
{
    unsigned char *pBytes;
    int nBytesSize,nColumns,nSize,nDec,nPos,nCol,iValue;
    char *cCommand;
    double dCalc,dValue;
    int aInsOPCode[C_INSCOUNT];
    int aInsCol[C_INSCOUNT];
    int aInsiValue[C_INSCOUNT];
    double aInsdValue[C_INSCOUNT];
    int nCurrentIns,nInsCount;
    VM *pVM  ;
    nCurrentIns = 0;
    nInsCount   = 0;
    pVM = (VM *) pPointer ;

    if (RING_API_PARACOUNT < 4) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }

    if ( ! RING_API_ISSTRING(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    pBytes = RING_API_GETSTRING(1);
    nBytesSize = RING_API_GETSTRINGSIZE(1);

    if ( ! RING_API_ISNUMBER(2) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    nColumns = (int) RING_API_GETNUMBER(2);

    if ( ! RING_API_ISNUMBER(3) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    nSize = (int) RING_API_GETNUMBER(3);

    if ( ! RING_API_ISNUMBER(4) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    nDec = (int) RING_API_GETNUMBER(4);

    // Get Instructions
    nPos = 5;   // Start getting new instruction from the second parameter
    while ( ring_getnewinstruciton(pPointer, &nPos, &cCommand, &nCol, &iValue, &dValue) ) {
        if (nCurrentIns >= C_INSCOUNT) {
            RING_API_ERROR("Extra number of commands!");
            return;
        }
        if ( strcmp(cCommand,"set") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SET;
        } else if ( strcmp(cCommand,"add") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_ADD;
        } else if ( strcmp(cCommand,"sub") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SUB;
        } else if ( strcmp(cCommand,"mul") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_MUL;
        } else if ( strcmp(cCommand,"div") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_DIV;
        } else if ( strcmp(cCommand,"merge") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_MERGE;
        } else if ( strcmp(cCommand,"copy") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_COPY;
        } else if ( strcmp(cCommand,"serial") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_SERIAL;
        } else if ( strcmp(cCommand,"pow") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_POW;
        } else if ( strcmp(cCommand,"rem") == 0 ) {
            aInsOPCode[nCurrentIns] = INS_REM;
        }
        aInsCol[nCurrentIns]    = nCol;
        aInsiValue[nCurrentIns] = iValue;
        aInsdValue[nCurrentIns] = dValue;
        nCurrentIns++;
    }
    nInsCount = nCurrentIns ;

    // Execute instructions
    for ( int x = 1 ; x <= nBytesSize ; x += nColumns  ) {
        for (nCurrentIns = 0 ; nCurrentIns < nInsCount ; nCurrentIns++) {
            nCol   = aInsCol[nCurrentIns];
            iValue = aInsiValue[nCurrentIns];
            dValue = aInsdValue[nCurrentIns];
            // Execute Instruction
            if ( aInsOPCode[nCurrentIns] == INS_SET ) {
                pBytes[(x-1)+(nCol-1)] = (char) dValue;
            } else if ( aInsOPCode[nCurrentIns] == INS_ADD ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc /= nDec;
                dCalc += dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_SUB ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc /= nDec;
                dCalc -= dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_MUL ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc = dCalc / nDec;
                dCalc = dCalc * dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc = dCalc * nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_DIV ) {
                    if ( dValue == 0 ) {
                            RING_API_ERROR("Can't divide by zero");
                            return ;
                    }
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc /= nDec;
                dCalc /= dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_MERGE ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)] / nDec;
                dCalc += ( (double) pBytes[(x-1)+(iValue-1)] / nDec ) ;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_COPY ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)] / nDec;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(iValue-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_SERIAL ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc = dCalc / nDec;
                dCalc = x+dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_POW ) {
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc = dCalc / nDec;
                dCalc = pow(dCalc,dValue);
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            } else if ( aInsOPCode[nCurrentIns] == INS_REM ) {
                    if ( dValue == 0 ) {
                            RING_API_ERROR("Can't divide by zero");
                            return ;
                    }
                dCalc = (double) pBytes[(x-1)+(nCol-1)];
                dCalc /= nDec;
                dCalc = (int)dCalc % (int)dValue;
                if ( nDec != 1 )
                    if ( dCalc > 1 ) dCalc = 1;
                dCalc *= nDec;
                pBytes[(x-1)+(nCol-1)] = (char) dCalc;
            }
        }
    }
    RING_API_RETSTRING2(pBytes,nBytesSize);
}

RING_FUNC(ring_addbytescolumn)
{
    unsigned char *pBytes, *pNewBytes;
    int nBytesSize,nColumns,nSize,nNewBytesSize,nIndex;

    if (RING_API_PARACOUNT < 3) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }

    if ( ! RING_API_ISSTRING(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    pBytes = RING_API_GETSTRING(1);
    nBytesSize = RING_API_GETSTRINGSIZE(1);

    if ( ! RING_API_ISNUMBER(2) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    nColumns = (int) RING_API_GETNUMBER(2);

    if ( ! RING_API_ISNUMBER(3) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    nSize = (int) RING_API_GETNUMBER(3);


    nNewBytesSize = (nColumns+1)*nSize;
    pNewBytes = RING_API_MALLOC(nNewBytesSize);

    nIndex = 0;
    for ( int x = 1 ; x <= nBytesSize ; x += nColumns  ) {
        for ( int t=0 ; t < nColumns ; t++) {
            pNewBytes[nIndex++] = pBytes[x-1+t];
        }
        pNewBytes[nIndex++] = (char) 255;
    }

    RING_API_RETSTRING2(pNewBytes,nNewBytesSize);

}

RING_LIBINIT
{
    RING_API_REGISTER("bytes2list",ring_bytes2list);
    RING_API_REGISTER("list2bytes",ring_list2bytes);
    RING_API_REGISTER("updatelist",ring_updatelist);
    RING_API_REGISTER("updatecolumn",ring_updatecolumn);
    RING_API_REGISTER("updatebytescolumn",ring_updatebytescolumn);
    RING_API_REGISTER("addbytescolumn",ring_addbytescolumn);
}
