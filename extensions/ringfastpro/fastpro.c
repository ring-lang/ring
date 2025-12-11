/*
** RingFastPro extension
** 2023, Mahmoud Fayed
** 2024, Bert Mariani Added DestCol support in updateList() as a 6 parameter)
** 2025, Bert Mariani Added merge mergemul mergesub, mergediv
**                          Can use 2 rows or col ==> dRow or dCol dDestination
**                    manyrows, manycols can use range 
**                    Transpose, Scalar, DotProduct-1D,2D
**                    Fill-Matrix
**                    Maximum-Matrix  Find Max in: 0=Entire, 1 Diagonal 
**                    Identity-Matrix Make Diagonal - 1's, Rest 0's   
**                    Random-Matrix  
**                    Mean-Matrix  
**                    Sqrt-Matrix  
**                    Square-Matrix
**                    Sigmoid-Matrix
**                    SigmoidPrime-Matrix
**                    Tanh-Matrix
**                    LeakyReLU-Matrix
**                    LeakyReLUPrime-Matrix
**                    ReLu-Matrix
**                    ReLuPrime-Matrix
**                    Exp-Matrix
**                    Sum-Matrix      // Axis 1=Rows, 0=Cols
**                    Softmax-Matrix
**                    ScalarDiv
**                    HorStack
**                    VerStack
**                    Ravel
**                    ZeroLike
**                    AtLeast2D
**                    ArgMax       // Flat array find Index of Max number  
**                    DeRepeat     // Flat array Remove duplicatevalue
**                    Append
**                    AllSum
**                    Mandelbrot
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
//  aListC = updateList(<aList>,:mul,:matrix,<aListB>)        // 4 Parms
//  aListC = updateList(<aList>,:transpose,:matrix )          // 3 Parms - Rotate matrix
//  aListC = updateList(<aList>,:scalar,:matrix,<nValue> )    // Matrix Multiply
//  valueA/aListC = updateList(<aList>,:dotproduct,:matrix,<aListB>) // Result 1D=Scalar-Nbr, 2D=Matrix
//  aListC = updateList(<aList>,:fill,:matrix,<nValue> )      // Matrix fill with nValue
//  valueA = updateList(<aList>,:maximum,:matrix,<nValue> )   // nValue = 0/1  Entire/Diagonal
//  aList  = updateList(<aList>,:identity,:matrix )           // 3 Parms. Make Diagonal = 1's
//  aList  = updateList(<aList>,:random,:matrix )             // 3 Parms. Random numbers
//  valueA = updateList(<aList>,:mean,:matrix )               // 3 Parms. Arith. Mean
//  aListC = updateList(<aList>,:sqrt,:matrix )               // 3 Parms, Sqrt of Each entry 
//  aListC = updateList(<aList>,:square,:matrix )             // 3 Parms, Sqrt of Each entry 
//  aListC = updateList(<aList>,:sigmoid,:matrix )            // 3 Parms, Sigmoid of Each entry 
//  aListC = updateList(<aList>,:sigmoidprime,:matrix )       // 3 Parms, SigmoidPrime 
//  aListC = updateList(<aList>,:tanh,:matrix )               // 3 Parms, Tanh of Each entry
//  aListC = updateList(<aList>,:leakyrelu,:matrix )          // 3 Parms, LeakyReLU of Each entry
//  aListC = updateList(<aList>,:leakyreluprime,:matrix )     // 3 Parms, LeakyReLUPrime
//  aListC = updateList(<aList>,:relu,:matrix )               // 3 Parms, ReLu
//  aListC = updateList(<aList>,:reluprime,:matrix )          // 3 Parms, ReLuPrime
//  aListC = updateList(<aList>,:exp,:matrix )                // 3 Parms, Exp
//  aListC = updateList(<aList>,:sum,:matrix )                // 3 Parms, Sum Axis 1=Rows 0=Cols
//  aListC = updateList(<aList>,:softmax,:matrix )            // 3 Parms, Softmax
//  aListC = updateList(<aList>,:scalardiv,:matrix,<nValue> ) // Matrix Scalar Divide
//  aListC = updateList(<aList>,:horstack,:matrix,<aListB> )   // Matrix HorStack
//  aListC = updateList(<aList>,:verstack,:matrix,<aListB> )   // Matrix verStack
//  aListC = updateList(<aList>,:ravel,:matrix )              // 3 Parms Matrix Ravel
//  aListC = updateList(<aList>,:zerolike,:matrix )           // 3 Parms Matrix ZeroLike 
//  aListC = updateList(<aList>,:atleast2d,:matrix )          // 3 Parms Matrix AtLeast2D 
//  valueA = updateList(<aList>,:argmax,:matrix )             // 3 Parms Matrix ArgMax
//  aListC = updateList(<aList>,:derepeat,:matrix )           // 3 Parms Matrix DeRepeat  
//  aListC = updateList(<aList>,:append,:matrix,<aListB>,<nValue> )  // 5 -Matrix Append 
//  valueA = updateList(<aList>,:allsum,:matrix )             // 3 Parms Matrix AllSum
//  aListC = updateList(<aList>,:mandelbrot,:matrix,<aFlatB> )  // Matrix MandelBrot
//
//  Set the Operation code. Add Selection Code for Jump => 503
//  strcmp(cOperation,"set")        nOPCode += 100 ;
//  strcmp(cOperation,"add")        nOPCode += 200 ;
//  strcmp(cOperation,"sub")        nOPCode += 300 ;
//  strcmp(cOperation,"mul")        OPCode  += 400 ;
//  strcmp(cOperation,"div")        nOPCode += 500 ;
//  strcmp(cOperation,"copy")       nOPCode += 600 ;
//  strcmp(cOperation,"merge")      nOPCode += 700 ;
//  strcmp(cOperation,"serial")     nOPCode += 800 ;
//  strcmp(cOperation,"pow")        nOPCode += 900 ;
//  strcmp(cOperation,"rem")        nOPCode += 1000 ;
//  strcmp(cOperation,"mergesub")   nOPCode += 1100 ;
//  strcmp(cOperation,"mergemul")   nOPCode += 1200 ;
//  strcmp(cOperation,"mergediv")   nOPCode += 1300 ;
//  strcmp(cOperation,"transpose")  nOPCode += 1400 ;   // Transpose-Matrix  1406
//  SCALAR = DivByNum when 1/nvalue or inverse multiply // DivByNum
//  strcmp(cOperation,"scalar")     nOPCode += 1500 ;   // Scalar-Matrix     1506
//  strcmp(cOperation,"dotproduct") nOPCode += 1600 ;   // DotProduct-Matrix 1606
//  strcmp(cOperation,"fill")       nOPCode += 1700 ;   // Fill-Matrix       1706
//  strcmp(cOperation,"maximum")    nOPCode += 1800 ;   // Maximum-Matrix    1806
//  strcmp(cOperation,"identity")   nOPCode += 1900 ;   // Identity-Matrix   1906
//  strcmp(cOperation,"random")     nOPCode += 2000 ;   // Random-Matrix     2006
//  strcmp(cOperation,"mean")       nOPCode += 2100 ;   // Mean-Matrix       2106
//  strcmp(cOperation,"sqrt")       nOPCode += 2200 ;   // Sqrt-Matrix       2206
//  strcmp(cOperation,"square")     nOPCode += 2300 ;   // Square-Matrix     2306
//  strcmp(cOperation,"sigmoid")    nOPCode += 2400 ;   // Sigmoid-Matrix    2406
//  strcmp(cOperation,"sigmoidprime")   nOPCode += 2500 ;  // Sigmoid-Matrix 2506
//  strcmp(cOperation,"tanh")       nOPCode += 2600 ;   // Tanh-Matrix       2606
//  strcmp(cOperation,"leakyrelu")  nOPCode += 2700 ;       // LeakyReLu-Matrix 2706
//  strcmp(cOperation,"leakyreluprime") nOPCode += 2800 ;   // LeakyReLuPrime-Matrix 2806
//  strcmp(cOperation,"relu")       nOPCode += 2900 ;   // ReLu-Matrix       2906
//  strcmp(cOperation,"reluprime")  nOPCode += 3000 ;   // ReLuPrime-Matrix  3006
//  strcmp(cOperation,"exp")        nOPCode += 3100 ;   // Exp-Matrix        3106
//  strcmp(cOperation,"sum")        nOPCode += 3200 ;   // Sum-Matrix        3206
//  strcmp(cOperation,"softmax")    nOPCode += 3300 ;   // Softmax-Matrix    3306
//  strcmp(cOperation,"scalardiv")  nOPCode += 3400 ;   // ScalarDiv-Matrix  3406
//  strcmp(cOperation,"horstack")   nOPCode += 3500 ;   // HorStack-Matrix   3506
//  strcmp(cOperation,"verstack")   nOPCode += 3600 ;   // VerStack-Matrix   3606
//  strcmp(cOperation,"ravel")      nOPCode += 3700 ;   // Ravel-Matrix      3706
//  strcmp(cOperation,"zerolike")   nOPCode += 3800 ;   // ZeroLike-Matrix   3806
//  strcmp(cOperation,"atleast2d")  nOPCode += 3900 ;   // AtLeast2D-Matrix  3906
//  strcmp(cOperation,"atrgmax")    nOPCode += 4000 ;   // ArgMax-Matrix     4006
//  strcmp(cOperation,"derepeat")   nOPCode += 4100 ;   // DeRepeat-Matrix   4106
//  strcmp(cOperation,"append")     nOPCode += 4200 ;   // Append-Matrix     4206
//  strcmp(cOperation,"allsum")     nOPCode += 4300 ;   // AllSum-Matrix     4306
//  strcmp(cOperation,"mandelbrot") nOPCode += 4400 ;   // MandelBrot-Matrix 4406
//
//  Set the Selection Code
//  strcmp(cSelection,"row")       nOPCode = 1 ;
//  strcmp(cSelection,"col")       nOPCode = 2 ;
//  strcmp(cSelection,"manyrows")  nOPCode = 3 ;
//  strcmp(cSelection,"manycols")  nOPCode = 4 ;
//  strcmp(cSelection,"items")     nOPCode = 5 ;
//  strcmp(cSelection,"matrix")    nOPCode = 6 ;       // Add, Sub, Mul -- Matrix
//
//===============================================================


RING_FUNC(ring_updatelist)
{
    char *cOperation  ;
    char *cSelection  ;
    List *pList, *pSubList, *pRow, *pRow2  ;
    int   nOPCode,nRow,nCol,nStart,nEnd,iValue, nTotal  ;

    //=====================================
    // Add MATRIX pList + pListB => pListC
    
    List *pListB, *pListC, *pListD, *pRowB, *pRowC ; // *pRowD ;
    int   nRowB, nColB, nStartB, nEndB;
    int   nRowC, nColC, nStartC, nEndC;
    int   nRowD, nColD, nStartD, nEndD;

    int   dCol ;  // Dest Column if Parm 6
    int   dRow ;  // Dest Row    if Parm 6
    List *pRowD ; // Dest Row    if Parm 6

    double Sum, valueA, valueB, valueC, nSum ;     // Matrix Multiply
    int    i, j, k , v, h ;
    int    vA, vB, vC, hA, hB, hC, Axis ;
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

    if ( (RING_API_PARACOUNT < 2) || (RING_API_PARACOUNT > 6) ) {
        RING_API_ERROR("BADPARACOUNT must be between 3:6");
        return ;
    }

    //------------------ 
    // ISLIST(1)   = aList        
    // ISSTRING(2) = nOpCode(100-1300)      
    // ISSTRING(3) = SecectionCode(1-6)
    
    if ( ! ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }

    //======================
    /* Get Parameters */

    pList      =          RING_API_GETLIST(1) ;
    cOperation = (char *) RING_API_GETSTRING(2) ;
    cSelection = (char *) RING_API_GETSTRING(3) ;

    cOperation = ring_general_lower(cOperation);
    cSelection = ring_general_lower(cSelection);

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
    //          updateList(<aList>,:add,      :matrix,<aListB>)        ADD 4-P list-list
    // aListC = updateList(<aList>,:scalar,  <nValue> )             SCALAR 3-P list-number
    // aListC = updateList(<aList>,:transpose,:matrix)           TRANSPOSE 3-P list-list
    // aListC = updatelist(aListA,:append,    :matrix,aListB, Axis) APPEND 5-P list-list-nbr
    // sum    = updatelist(aListA,:allsum,    :matrix)              ALLSUM 2-P list

    else if ( strcmp(cSelection,"matrix") == 0 ) {
        if ( RING_API_PARACOUNT == 3 || 
             RING_API_PARACOUNT == 4 || 
             RING_API_PARACOUNT == 5  ) {
                 

            if ( RING_API_PARACOUNT == 3) {
                   nOPCode = 6 ;
                   nValue  = 1;
            }
            else if ( RING_API_ISLIST(4) ) {
                nOPCode = 6 ;
                pListB  = RING_API_GETLIST(4) ;
            }   
            else if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 6 ;
                nValue  = (double) RING_API_GETNUMBER(4) ;  // Scalar-nValue
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
    
    else if ( strcmp(cOperation,"dotproduct") == 0 ) {
        nOPCode += 1600 ;
    }
    
    else if ( strcmp(cOperation,"fill") == 0 ) {
        nOPCode += 1700 ;
    }
     
    else if ( strcmp(cOperation,"maximum") == 0 ) {
        nOPCode += 1800 ;
            if ( nValue > 1 ) {
            RING_API_ERROR("Maximum Axis must be 0-ALL, 1=Diagonal");
            return ;
        }
    }
    
    else if ( strcmp(cOperation,"identity") == 0 ) {
        nOPCode += 1900 ;
    }   
    
    else if ( strcmp(cOperation,"random") == 0 ) {
        nOPCode += 2000 ;
    }   
    
    else if ( strcmp(cOperation,"mean") == 0 ) {
        nOPCode += 2100 ;
    } 
    
    else if ( strcmp(cOperation,"sqrt") == 0 ) {
        nOPCode += 2200 ;
    }   
    
    else if ( strcmp(cOperation,"square") == 0 ) {
        nOPCode += 2300 ;
    }  
    
    else if ( strcmp(cOperation,"sigmoid") == 0 ) {
        nOPCode += 2400 ;
    }
    
    else if ( strcmp(cOperation,"sigmoidprime") == 0 ) {
        nOPCode += 2500 ;
    } 
    
    else if ( strcmp(cOperation,"tanh") == 0 ) {
        nOPCode += 2600 ;
    }   
 
    else if ( strcmp(cOperation,"leakyrelu") == 0 ) {
        nOPCode += 2700 ;
    }  
    
    else if ( strcmp(cOperation,"leakyreluprime") == 0 ) {
        nOPCode += 2800 ;
    }
    
    else if ( strcmp(cOperation,"relu") == 0 ) {
        nOPCode += 2900 ;
    }
    
    else if ( strcmp(cOperation,"reluprime") == 0 ) {
        nOPCode += 3000 ;
    } 

    else if ( strcmp(cOperation,"exp") == 0 ) {
        nOPCode += 3100 ;
    } 

    else if ( strcmp(cOperation,"sum") == 0 ) {
        nOPCode += 3200 ;
            if ( nValue > 1 ) {
            RING_API_ERROR("Sum Axis must be 1=Rows, 0=Cols");
            return ;
        }
    }   

    else if ( strcmp(cOperation,"softmax") == 0 ) {
        nOPCode += 3300 ;
    } 

    else if ( strcmp(cOperation,"scalardiv") == 0 ) {
        nOPCode += 3400 ;
        if ( nValue == 0 ) {
            RING_API_ERROR("Can't divide by zero");
            return ;
        }
    }
    
    else if ( strcmp(cOperation,"horstack") == 0 ) {
        nOPCode += 3500 ;
    } 
    
    else if ( strcmp(cOperation,"verstack") == 0 ) {
        nOPCode += 3600 ;
    }  

    else if ( strcmp(cOperation,"ravel") == 0 ) {
        nOPCode += 3700 ;
    }   

    else if ( strcmp(cOperation,"zerolike") == 0 ) {
        nOPCode += 3800 ;
    }  

    else if ( strcmp(cOperation,"atleast2d") == 0 ) {
        nOPCode += 3900 ;
    }
    
    else if ( strcmp(cOperation,"argmax") == 0 ) {
        nOPCode += 4000 ;
    }
    
    else if ( strcmp(cOperation,"derepeat") == 0 ) {
        nOPCode += 4100 ;
    }
        
    else if ( strcmp(cOperation,"append") == 0 ) {
        nOPCode += 4200 ;
    }
         
    else if ( strcmp(cOperation,"allsum") == 0 ) {
        nOPCode += 4300 ;
    }
    
    else if ( strcmp(cOperation,"mandelbrot") == 0 ) {
        nOPCode += 4400 ;
    }
    else if ( strcmp(cOperation,"emul") == 0 ) {
        nOPCode += 4500 ;
    }
     
    else {
        RING_API_ERROR("The second parameter -cOperation- must be a string: [Set | Add | Sub | Mul | Div | Copy | Merge | MergeSub |  MergeMul | MergeDiv | Matrix | etc ");
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

                RING_API_RETLISTBYREF( pListC );
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

                RING_API_RETLISTBYREF( pListC );
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
			// Check[nRowA x nColA] * [nRowB x nColB] 
			// Must:        nColA = nRowB 
			// Result Size: nRowA x nColB

           pListB = RING_API_GETLIST(4) ;

           nRow   = ring_list_getsize(pList);           // 5 Row-A vert for vA = 1 to vertA
           pRow   = ring_list_getlist(pList,nRow);
           nEnd   = ring_list_getsize(pRow) ;           // 3 Col-A horz for k = 1 to horzA


           nRowB   = ring_list_getsize(pListB) ;        // 3 Row-B vert
           pRowB   = ring_list_getlist(pListB,nRowB);
           nEndB   = ring_list_getsize(pRowB) ;         // 4 Col-C horz for hB = 1 to horzB

           if( nEnd != nRowB ) 
		   {   RING_API_ERROR("Mul-Matrix: nColA != nRowB for [nRowA x nColA] * [nRowB x nColB]" );
               return ;
		   }

           //--- CREATE Output List - Outside Dims.-----
           sizeX   = nRow  ;  sizeY   = nEndB ;
           pListC  = RING_API_NEWLISTUSINGBLOCKS2D( sizeX, sizeY) ;

           nRowC   = ring_list_getsize(pListC) ;        // 5=Row-C vert
           pRowC   = ring_list_getlist(pListC,nRowC);
           nEndC   = ring_list_getsize(pRowC) ;         // 4=Col-C horz
           //------------------------------------

            for (vA = 1; vA <= nRow; vA++)
            {   pSubList  = ring_list_getlist(pList,  vA) ;          // Row-A vA 12890x4
		
		        for (hB = 1; hB <= nEndB; hB++)
                {
                    Sum = 0;

                    for (k = 1; k <=  nEnd; k++)
                    {   
			// Sum += A[vA][k] * B[k][hB]
                        //          R   C      R  C
                        
			pSubListB = ring_list_getlist(pListB, k) ;       // Row-B k 4x4
						
                        valueA  = ring_list_getdouble( pSubList, k ) ;   // Col-A  k
                        valueB  = ring_list_getdouble( pSubListB, hB ) ; // Col-B   hB
                        valueC  = valueA * valueB ;
                        Sum    += valueC  ;
                    }

                    pSubListC = ring_list_getlist(pListC, vA ) ;                  // Row#
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, Sum );  // Col#

                }
            }

            RING_API_RETLISTBYREF(pListC); // FAST
			  
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
            {   
                pSubListC = ring_list_getlist(pListC, hB); // Row of C

                for (vA = 1; vA <= nRow; vA++)   // Rows vA i
                {
                     pSubList  = ring_list_getlist(pList, vA) ; // Row of A
                     valueA    = ring_list_getdouble( pSubList, hB ) ; // Col of A

                     ring_list_setdouble_gc(pVM->pRingState,pSubListC, vA, valueA ); // Col of C
                }
            }

            RING_API_RETLISTBYREF( pListC );
            break ;


        //---------------------------------------
        
        case 1506 :
            /* Scalar Matrix-A  * K ==> MatriX-C */
           
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
                { 

                  // aListC[vA][hB] = k * (aList[vA][hB])  

                  pSubList  = ring_list_getlist(pList, vA) ;        // Row
                  valueA    = ring_list_getdouble( pSubList, hB ) ; // Col
                  valueC    = valueA * nValue;

                  pSubListC = ring_list_getlist(pListC, vA ) ;
                  ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, valueC );
                }
            }       
        
            RING_API_RETLISTBYREF( pListC );
            break ;

         //===End 1506 ==============================    
         
        case 1606 :
            /* 1D DotProduct Matrix-A * Matrix-B ==> Scalar Number   Row 5 Col 1 */ 
            // 3 Rows by 1 Col
            
            /* 2D DotProduct Matrix-A * Matrix-B ==> Matrix-C        Row 5 Col 5 */
            // 3 Rows by 3 Col

           pListB = RING_API_GETLIST(4) ;

           nRow   = ring_list_getsize(pList);           // Row-A vert for vA 
           pRow   = ring_list_getlist(pList,nRow);
           nEnd   = ring_list_getsize(pRow) ;           // Col-A horz for hB

           nRowB   = ring_list_getsize(pListB) ;        // Row-B vert for vB
           pRowB   = ring_list_getlist(pListB,nRowB);
           nEndB   = ring_list_getsize(pRowB) ;         // Col-C horz for hB 

           //--- CREATE Output List - Outside Dims.-----
           sizeX   = nRow  ;  sizeY   = nEndB ;
           pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

           nRowC   = ring_list_getsize(pListC) ;        // Row-C vert for vC
           pRowC   = ring_list_getlist(pListC,nRowC);                
           nEndC   = ring_list_getsize(pRowC) ;         // Col-C horzf or hC
           //------------------------------------        

           vA = nRow ;        hA = nEnd ;
           vB = nRowB;        hB = nEndB;

        if( (hA == 1) && (hB == 1) )               
        { // Single Dimension 1D Return Scalar
           
  
           if( (hA != 1 || hB != 1) ||  (vA != vB) )
           {   RING_API_ERROR("Dot Product 1D Dimension: Not same size Vector");
               return ;
           }

           Sum = 0;
           for( vA = 1; vA <= nRow; vA++)
           {   
                pSubList  = ring_list_getlist(pList, vA) ;        // Row 1 2 3
                valueA    = ring_list_getdouble( pSubList, 1 ) ;  // Col 1
                
                pSubListB = ring_list_getlist(pListB, vA) ;        // Row
                valueB    = ring_list_getdouble( pSubListB, 1 ) ;   // Col 1
                
                valueC    = valueA * valueB ;          
                Sum      += valueC;
           }
            RING_API_RETNUMBER(Sum);
        }

        else     
        {   if( (hA != hB ) ||  (vA != vB) )
            { RING_API_ERROR("Dot Product 2D Dimension: Not same size array");
               return ;
            }
         
            for(  v = 1; v <= vA; v++)
            {   for(h = 1; h <= hB ; h++)
                {
                   Sum = 0;
                   for( k = 1; k <= hA; k++)
                   {
                      pSubList  = ring_list_getlist(pList, v) ;         // Row 1 2 3
                      valueA    = ring_list_getdouble( pSubList, k ) ;  // Col 1
                      
                      pSubListB = ring_list_getlist(pListB, k) ;         // Row
                      valueB    = ring_list_getdouble( pSubListB, h ) ;  // Col 1
                      
                      valueC    = valueA * valueB ;
                      Sum       += valueC;              
                    } 
                    
                    pSubListC = ring_list_getlist(pListC, v ) ;
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, Sum );
                   
                } 
            }
            RING_API_RETLISTBYREF( pListC ); 
        }   
            
        
            //==============        
            break ;

        //===End 1606 ==============================
        
        //---------------------------------------
        
        case 1706 :
            /* Fill Matrix-A  with k nValue */
                     
            nRow   = ring_list_getsize(pList);           //  Row-A
            pRow   = ring_list_getlist(pList,nRow);
            nEnd   = ring_list_getsize(pRow) ;           //  Col-A

            //------------------------------------
           
            for( vA = 1; vA <= nRow ; vA++)
            {   for( hB = 1; hB <= nEnd; hB++)
                {   
                  pSubList  = ring_list_getlist(pList, vA) ;                // Row
                              ring_list_getdouble( pSubList, hB ) ;         // Col 
               
                  ring_list_setdouble_gc(pVM->pRingState,pSubList, hB, nValue);  // Set R-C = k
                }
            }       
        
            RING_API_RETLIST( pList );
            break ;

         //===End 1706 ==============================   

        case 1806 :
            /* Maximum in  Matrix-A  nValue = Axis  0=ALL  1=Diagonal */    

            Axis   = RING_API_GETNUMBER(4);           // Axis  0=ALL  1=Diagonal         

            nRow   = ring_list_getsize(pList);           //  Row-A
            pRow   = ring_list_getlist(pList,nRow);
            nEnd   = ring_list_getsize(pRow) ;           //  Col-A      
        
            if(Axis == 1)  
            {   valueB = 0;
        
                for( v = 1; v <= nRow; v++)  
                {                           
                   pSubList  = ring_list_getlist(pList, v) ;                // Row
                   valueA    = ring_list_getdouble( pSubList, v ) ;         // Col  = value 
                   
                   if( valueA > valueB )
                   {   valueB = valueA ;
                   }  
                }               
                RING_API_RETNUMBER(valueB); 
            }
  
            else if( Axis == 0 )
            {       valueB = 0 ;
                    for( v = 1; v <= nRow; v++)  
                    {   for( h = 1; h <= nEnd; h++ )
                        {
                              pSubList  = ring_list_getlist(pList, v) ;        // Row                     
                              valueA    = ring_list_getdouble( pSubList, h ) ; // Col = value 
                       
                           if( valueA > valueB )
                           {   valueB = valueA ;
                           }                        
                        } 
                    } 
                    RING_API_RETNUMBER(valueB);
                
            }
            else
            {RING_API_ERROR("BAD nValue. 1=Diagonal  0=Entire Matrix");         
            } 

            break ;
            
         //===End 1806 ============================== 

        case 1906 :
            /* Identity Matrix-A  */    

            nRow   = ring_list_getsize(pList);           //  Row-A
            pRow   = ring_list_getlist(pList,nRow);
            nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
            
            if( nRow != nEnd)
            {   RING_API_ERROR("Matrix must be square. Row != Col ");
            }

            // Set 0's All
            for( v = 1; v <= nRow; v++) 
            {
               for( h = 1; h <= nEnd; h++) 
               {                
                   pSubList  = ring_list_getlist(pList, v) ;   // Row                     
                               ring_list_setdouble_gc(pVM->pRingState,pSubList, h, 0);  // Set R-C==     
               }        
            }

            // Set 1's Diagonal
            for( v = 1; v <= nRow; v++) 
            {  
                pSubList  = ring_list_getlist(pList, v) ;   // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubList, v, 1);  // Set R-C=1      
            }

            RING_API_RETLIST(pList);
            //----------------
            break ;

         //===End 1906 ==============================    

       case 2006 :
         /* Random Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
        
         // Set Random Number All
        
         srand( time( NULL));
         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
               valueA = (double)(rand() % 100 + 1)/ 100 ;  // Random 1 to 100
       
               pSubList  = ring_list_getlist(pList, v) ;   // Row                     
                           ring_list_setdouble_gc(pVM->pRingState,pSubList, h, valueA );      
           }        
         }

         RING_API_RETLIST(pList);
         //----------------
         break ;

      //===End 2006 ==============================  
      
       case 2106 :
         /* Mean Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
        
         Sum = 0;
         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col = value 
                Sum      += valueA ;
           }        
         }
         
         valueC = Sum / (nRow * nEnd);   // Total / entries
         RING_API_RETNUMBER(valueC);

         //----------------
         break ;

      //===End 2106 ============================== 
 
       case 2206 :
         /* SQRT Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
           
         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                
                valueC    = sqrt(valueA);
                
                pSubListC = ring_list_getlist(pListC, v) ;   // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );              
                
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2206 ==============================    
      
       case 2306 :
         /* SQUARE Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
           
         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                
                valueC    = pow( valueA, 2);
                
                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );               
                
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2306 ==============================    

        case 2406 :
         /* SIGMOID Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
           
         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                
                valueC    = 1 / (1 +( exp(-valueA) ) );
              
                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2406 ==============================   

        case 2506 :
         /* SIGMOID-PRIME Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                
                valueC    = valueA * (1 - valueA) ;

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2506 ==============================   
   
        case 2606 :
         /* TANH Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                
                valueC    = tanh(valueA) ;

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2606 ==============================   


        case 2706 :
         /* LeakyReLU Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                

                if( valueA < 0 ) 
                {   valueC = valueA * 0.01 ;
                }
                else
                {    valueC = valueA ;
                } 

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2706 ==============================  

        case 2806 :
         /* LeakyReLUPrime Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                             

                if( valueA < 0 ) 
                {   valueC = 0.01 ;
                }
                else
                {    valueC = 1 ;
                } 

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2806 ==============================  

        case 2906 :
         /* ReLu Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                             

                if( valueA < 0 ) 
                {   valueC = 0 ;
                }
                else
                {    valueC = valueA ;
                } 

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 2906 ==============================  

        case 3006 :
         /* ReLuPrime Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                             

                if( valueA < 0 ) 
                {   valueC = 0 ;
                }
                else
                {    valueC = 1 ;
                } 

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 3006 ==============================  

        case 3106 :
         /* EXP Matrix-A  */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

         for( v = 1; v <= nRow; v++ ) 
         {  
           for( h = 1; h <= nEnd; h++ ) 
           {        
                pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                valueA    = ring_list_getdouble( pSubList, h ) ; // Col-A = value 
                             
                valueC = exp(valueA);

                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, valueC );                             
           }        
         }
         
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 3106 ==============================        

        case 3206 :
         /* SUM Matrix-A Axis 1=Rows, 0=Cols */    

         Axis   = RING_API_GETNUMBER(4);              // Axis 1=Rows 0=Cols

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - Outside Dims.-----
        if(Axis == 1)   // Rows
        { pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow,1) ;
        }
        else
        { pListC  = RING_API_NEWLISTUSINGBLOCKS2D( 1,nEnd) ;
        }

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //---------------------------------------------
        // ONLY NEED 1 Loop. For Rows-Sum or Col-sum
        
        if(Axis == 1)   // Rows
        {  
            for( v = 1; v <= nRow; v++ ) 
            {  
                //--- Sum up the COLS-k in that Row -----
                nSum = 0;
                for( k = 1; k <= nEnd; k++ )   
                {   
                   pSubList  = ring_list_getlist(pList, v) ;        // Row-A                     
                   nSum     += ring_list_getdouble( pSubList, k ) ; // Col-A = value 
                }             
            
                pSubListC = ring_list_getlist(pListC, v) ;       // Row                     
                            ring_list_setdouble_gc(pVM->pRingState,pSubListC, 1, nSum );                             
            
            }
            
            RING_API_RETLISTBYREF( pListC );
         
        }
        else if( Axis == 0 )
        {   
            for( h = 1; h <= nEnd; h++ ) 
            {   
                 //--- Sum up the ROWS-k in that Col -----
                 nSum = 0;
                 for( k = 1; k <= nRow; k++ )
                 { pSubList  = ring_list_getlist(pList, k) ; // Row-A                     
                   nSum     += ring_list_getdouble( pSubList, h ) ; // Col-A = 
                 } 
         
                 pSubListC = ring_list_getlist(pListC, 1) ;       // Row                     
                             ring_list_setdouble_gc(pVM->pRingState,pSubListC, h, nSum );                             
            }        
           
           RING_API_RETLISTBYREF( pListC );
         
        }
        else
          {RING_API_ERROR("Sum BAD nValue. 1=Rows  0=Cols");         
        } 
         
         //----------
         break ;

      //===End 3206 ==============================  

        case 3306 :
        /* Softmax Matrix-A */    

        nRow   = ring_list_getsize(pList);           //  Row-A
        pRow   = ring_list_getlist(pList,nRow);
        nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

        //--- CREATE Output List-C - Same Dims.-----
        pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

        nRowC   = ring_list_getsize(pListC) ;        // Row-C v
        pRowC   = ring_list_getlist(pListC,nRowC);                
        nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

        for( v = 1; v <= nRow; v++ ) 
        {  
            // 1. Find Max Value in the Row (For Numerical Stability)
            pSubList = ring_list_getlist(pList, v); // Row Input
            double maxVal = -1.0e300; // Very small number
            
            for ( h = 1; h <= nEnd; h++) {
                valueA = ring_list_getdouble(pSubList, h);
                if (valueA > maxVal) {
                    maxVal = valueA;
                }
            }

            // 2. Calculate Exponentials and Sum
            double rowSum = 0.0;
            pSubListC = ring_list_getlist(pListC, v); // Row Output
            
            for ( h = 1; h <= nEnd; h++) {
                valueA = ring_list_getdouble(pSubList, h);
                // exp(x - max) prevents overflow
                valueC = exp(valueA - maxVal); 
                
                // Store temporarily in output list
                ring_list_setdouble_gc(pVM->pRingState, pSubListC, h, valueC);
                
                rowSum += valueC;
            }

            // 3. Normalize (Divide by Sum)
            for ( h = 1; h <= nEnd; h++) {
                // Retrieve the exp value we just stored
                valueC = ring_list_getdouble(pSubListC, h);
                
                // Divide by sum to get probability
                if (rowSum != 0) {
                    valueC = valueC / rowSum;
                } else {
                    valueC = 0.0; // Should not happen with exp
                }
                
                ring_list_setdouble_gc(pVM->pRingState, pSubListC, h, valueC);
            }
        }
         
        RING_API_RETLISTBYREF( pListC );
         
        //----------
        break ;


      //===End 3306 ==============================             

        
        case 3406 :
            /* ScalarDiv Matrix-A / K  ==> MatriX-C */
           
            // k  = RING_API_GETNUMBER(4);           // DivideBy nValue
           
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
            {   pSubList  = ring_list_getlist(pList, vA) ;         // Row
        
                for( hB = 1; hB <= nEnd; hB++)
                {   
                  valueA    = ring_list_getdouble( pSubList, hB ) ; // Col
                  valueC    = valueA / nValue;

                  pSubListC = ring_list_getlist(pListC, vA ) ;
                  ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, valueC );
                }
            }       
        
            RING_API_RETLISTBYREF( pListC );
            break ;

         //===End 3406 ==============================   


        case 3506 :
         /* HorStack Matrix-A Matric-C => Matrix-C */ 
         
         pListB = RING_API_GETLIST(4) ;

         nRow   = ring_list_getsize(pList);           //  Row-A  5x5
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
         
         nRowB   = ring_list_getsize(pListB);         //  Row-A  5x5
         pRowB   = ring_list_getlist(pList,nRowB);
         nEndB   = ring_list_getsize(pRowB) ;         //  Col-A          

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, (nEnd+nEndB) ) ; // Wide 2x

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------
        
        if( nRow != nRowB )
        { RING_API_ERROR("HorStack: Number of Rows Not Equal in Matrix-A and Matrix-B ");  
          return;
        }

        for( i = 1; i <= nRow; i++)      // Row-A
        {   pSubList = ring_list_getlist(pList, i) ;            // Row-A
        
            for( j = 1; j <= nEnd; j++)  // Col-A
            {           
                valueA    = ring_list_getdouble( pSubList, j ) ; // Col-A
                
                pSubListC = ring_list_getlist(pListC, i ) ;
                ring_list_setdouble_gc(pVM->pRingState,pSubListC, j, valueA); // Offset 
                      
            }
        }

    
        for( i = 1; i <= nRowB; i++)      // Row-B
        {   pSubListB = ring_list_getlist(pListB, i) ;           // Row-B
            for( j = 1; j <= nEndB; j++)  // Col-B
            {
                valueB    = ring_list_getdouble( pSubListB, j ) ; // Col-B
                
                pSubListC = ring_list_getlist(pListC, i ) ;
                ring_list_setdouble_gc(pVM->pRingState,pSubListC, nEnd + j, valueB ); // Offset Col-A
                      
            }
        }   

       RING_API_RETLISTBYREF( pListC );
        
        //----------
        break ;

      //===End 3506 ==============================             


        case 3606 :
         /* VerStack Matrix-A Matric-C => Matrix-C */ 
         
         pListB = RING_API_GETLIST(4) ;

         nRow   = ring_list_getsize(pList);           //  Row-A  5x5
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
         
         nRowB   = ring_list_getsize(pListB);         //  Row-A  5x5
         pRowB   = ring_list_getlist(pList,nRowB);
         nEndB   = ring_list_getsize(pRowB) ;         //  Col-A          

         //--- CREATE Output List-C - Outside Dims.-----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( (nRow + nRowB), (nEnd) ) ; // Vertical 2x

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------
        
        if( nEnd != nEndB )
        { RING_API_ERROR("VerStack: Number of Cols Not Equal in Matrix-A and Matrix-B ");  
          return;
        }

        for( i = 1; i <= nRow; i++)      // Row-A
        {   pSubList = ring_list_getlist(pList, i) ;             // Row-A
        
            for( j = 1; j <= nEnd; j++)  // Col-A
            {           
                valueA    = ring_list_getdouble( pSubList, j ) ; // Col-A
                
                pSubListC = ring_list_getlist(pListC, i ) ;
                ring_list_setdouble_gc(pVM->pRingState,pSubListC, j, valueA); // Offset 
                      
            }
        }

    
        for( i = 1; i <= nRowB; i++)      // Row-B
        {   pSubListB = ring_list_getlist(pListB, i) ;           // Row-B
            for( j = 1; j <= nEndB; j++)  // Col-B
            {
                valueB    = ring_list_getdouble( pSubListB, j ) ; // Col-B
                
                pSubListC = ring_list_getlist(pListC, nRow +i ) ;
                ring_list_setdouble_gc(pVM->pRingState,pSubListC, j, valueB ); // Offset Col-A
                      
            }
        }   

       RING_API_RETLISTBYREF( pListC );
        
        //----------
        break ;

      //===End 3606 ==============================             
      

        case 3706 :
         /* RAVEL Matrix-A - Flaten the 2D Matrix */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C - FLAT List 1 x nTotal.-----
         nTotal  = nRow * nEnd ;
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( 1, nTotal) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

        for( i = 1; i<= nRow; i++) { 
            pSubList  = ring_list_getlist(pList, i) ;        // Row-A
            
            for( j = 1; j <= nEnd; j++) { 
                k = ((i-1)* nEnd) + j ;   
                valueA  = ring_list_getdouble( pSubList, j ) ; // Col-A = value 
                
                pSubListC = ring_list_getlist(pListC, 1) ;       // Row                     
                           ring_list_setdouble_gc(pVM->pRingState,pSubListC, k, valueA );
            } 
        } 
    
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 3706 ==============================        


        case 3806 :
         /* ZeroLike Matrix-A Fill with 0 */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C -----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //-------------------

        for( i = 1; i<= nRow; i++) { 
            pSubList  = ring_list_getlist(pList, i) ;        // Row-A
            pSubListC = ring_list_getlist(pListC,i) ;        // Row-C   
    
            for( j = 1; j <= nEnd; j++) {                               
                 ring_list_setdouble_gc(pVM->pRingState,pSubListC, j, 0 );
            } 
        } 
    
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 3806 ==============================        


        case 3906 :
         /* AtLeast2D Flat Matrix-A to 2D -- 1 x TotalLen */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  

         //--- CREATE Output List-C -----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( 1, nRow) ; // FLAT 1-Row Many-Cols

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         
        //----------------------------------------
        // nRow = len(FlatArray). No Col in Flat array
        
        for( vA = 1; vA <= nRow ; vA++)  
        {   
             valueA    = ring_list_getdouble( pList, vA );   // Start of Row-List  Col-vA

             pSubListC = ring_list_getlist(pListC, 1 );      // Row-C-1
             ring_list_setdouble_gc(pVM->pRingState,pSubListC, vA, valueA ); // Col-vA       
        } 

         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 3906 ============================== 


        case 4006 :
         /* ArgMax Flat Matrix-A Find Max-Value - return Position Index*/    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
     
        //----------------------------------------
        // nRow = len(FlatArray). No Col in Flat array
        
        valueC = 0;
        for( vA = 1; vA <= nRow ; vA++)  
        {   
            valueA     = ring_list_getdouble( pList, vA );   // Start of Row-List  Col-vA
            if( valueA > valueC )
            {   valueC = valueA ;  // New Max
                hA     = vA ;      // Position-Index
            }     
        } 

         RING_API_RETNUMBER(hA) ;

         //----------
         break ;

      //===End 4006 ==============================       


        case 4106 :
         /* DeRepeat Flat Matrix-A Remove Duplicate value*/  
         // Incredibly SLOW Alogrithm !n     

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
 
         //--- CREATE Output List-C -----
         pListC  = RING_API_NEWLISTUSINGBLOCKS2D( 1, nRow) ;  // 1xSize

         nRowC   = ring_list_getsize(pListC) ;        // Row-C v
         pRowC   = ring_list_getlist(pListC,nRowC);                
         nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
 
        //----------------------------------------
        // DeRepeat nRow = len(FlatArray). No Col in Flat array
       
        valueC = 0;
        j      = 1;
        int isDuplicate = 0;
        
        pSubListC = ring_list_getlist(pListC, 1 );     // Row-C..1
        
        for( i = 1; i <= nRow ; i++)  
        {   valueA = ring_list_getdouble( pList, i);   // Flat Row-A  Col-i
            isDuplicate = 0 ;
            
            for (int k = 1; k <= j; k++) {
                valueC = ring_list_getdouble( pSubListC, k); 
                
                if (valueA == valueC) {
                    isDuplicate = 1;
                    break;
                }
            }   
            
            if (!isDuplicate) {
                ring_list_setdouble( pSubListC, j++, valueA ); // J is 1 bigger when Fin
            }           
        }
        
         //--- CREATE Output List-B New 1x(j-1) Size without Dups -----
         pListB  = RING_API_NEWLISTUSINGBLOCKS2D( 1, (j-1) ) ;  
        
         nRowB   = ring_list_getsize(pListB) ;        // Row-C v
         pRowB   = ring_list_getlist(pListC,nRowB);                
         nEndB   = ring_list_getsize(pRowB) ;         // Col-C h
        
        //----------------------------------------      
        // Copy unique elements PListB
        
         pSubListB = ring_list_getlist(pListB, 1 );          // Row-B..1
        
         for (int i = 1; i <= (j-1) ; i++) {
             valueA = ring_list_getdouble( pSubListC, i);           // Row-C-i
                      ring_list_setdouble( pSubListB, i, valueA );  // Row-B-i 
        
         }  
    
         RING_API_RETLISTBYREF( pListB );

         //----------
         break ;

      //===End 4106 ==============================       


        case 4206 :
         /* Append  Matrix-A + MatricB  Axis: 0=Vert  1=Horz */    
         // aListC = updatelist(aListA,:append,:matrix,aListB, 1)

         pListB = RING_API_GETLIST(4) ;
         Axis   = RING_API_GETNUMBER(5);             // Axis  0=Vert  1=Horz

         
         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A 

         nRowB   = ring_list_getsize(pListB);         //  Row-B
         pRowB   = ring_list_getlist(pListB,nRow);
         nEndB   = ring_list_getsize(pRowB) ;         //  Col-B 


         //--- CREATE Output List --- Axis: 0=Vert
         // Axis 0=VERT Add Rows
         if( Axis == 0 ) { 
             pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow + nRowB, nEnd) ;
             
             nRowC   = ring_list_getsize(pListC) ;        // Row-C v
             pRowC   = ring_list_getlist(pListC,nRowC);                
             nEndC   = ring_list_getsize(pRowC) ;         // Col-C h
         }
         
         //--- CREATE Output List --- Axis: 1=Horz
         // Axis 1=Horz Add Cols
         if( Axis == 1 ) {  
            pListC  = RING_API_NEWLISTUSINGBLOCKS2D(nRow, nEnd + nEndB) ;

            nRowC   = ring_list_getsize(pListC) ;        // Row-C v
            pRowC   = ring_list_getlist(pListC,nRowC);                
            nEndC   = ring_list_getsize(pRowC) ;         // Col-C h      
         }
         
        //-------------------

         if( Axis == 0 )
         {
            // Get Data from aListA
            for( vA = 1; vA<= nRow; vA++) { 
               pSubList  = ring_list_getlist(pList, vA) ;        // Row-A
               pSubListC = ring_list_getlist(pListC,vA) ;        // Row-C   
           
               for( hA = 1; hA <= nEnd; hA++) {   
                    valueA = ring_list_getdouble( pSubList, hA);           // Row-A-i              
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hA, valueA );
               } 
            }
            
            // GetData from aListB - offst it into Row of  aListC
            for( vA = 1; vA<= nRow; vA++) { 
               pSubListB  = ring_list_getlist(pListB, vA) ;         // Row-B
               pSubListC = ring_list_getlist(pListC,vA +nRowB ) ;   // Row-C + nRowB 
           
               for( hA = 1; hA <= nEnd; hA++) {   
                    valueA = ring_list_getdouble( pSubListB, hA);        // Row-B-i            
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hA, valueA );
               } 
            }
                        
            
         }  
 
        //-------------------
        // 1 = Horz

         if( Axis == 1 )
         {
            // Get Data from aListA
            for( vA = 1; vA<= nRow; vA++) { 
               pSubList  = ring_list_getlist(pList, vA) ;        // Row-A
               pSubListC = ring_list_getlist(pListC,vA) ;        // Row-C   
           
               for( hA = 1; hA <= nEnd; hA++) {   
                    valueA = ring_list_getdouble( pSubList, hA);           // Row-A-i              
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hA, valueA );
               } 
            }
            
            // GetData from aListB - offst it into Row of  aListC
            for( vA = 1; vA<= nRow; vA++) { 
               pSubListB  = ring_list_getlist(pListB, vA) ;    // Row-B
               pSubListC = ring_list_getlist(pListC,vA  ) ;    // Row-C  
           
               for( hA = 1; hA <= nEnd; hA++) {   
                    valueA = ring_list_getdouble( pSubListB, hA);        // Row-B-i            
                    ring_list_setdouble_gc(pVM->pRingState,pSubListC, hA + nEnd, valueA );
               } 
            }
                        
            
         }
      
         RING_API_RETLISTBYREF( pListC );
         
         //----------
         break ;

      //===End 4206 ==============================        


        case 4306 :
         /* AllSuM Matrix-A  Sum of All values */    

         nRow   = ring_list_getsize(pList);           //  Row-A
         pRow   = ring_list_getlist(pList,nRow);
         nEnd   = ring_list_getsize(pRow) ;           //  Col-A  
        
        //---------------------------------------------
        // ONLY NEED 1 Loop. For Rows-Sum 
        
         nSum = 0;
         for( vA = 1; vA <= nRow; vA++ ) 
         {  
             pSubList  = ring_list_getlist(pList, vA) ;        // Row-A 
             
             for( hA = 1; hA <= nEnd; hA++ )                   // Col-A
             {                    
                 valueA = ring_list_getdouble( pSubList, hA ) ; // Col-A = value 
                 nSum  += valueA ;
             }             
                            
         }
            
            RING_API_RETNUMBER( nSum );
      
         //----------
         break ;

      //===End 4306 ==============================  


        case 4406 :

            ring_mandelbrot(pPointer);

         //----------
         break ;

        case 4506 :
            /* Element-Wise Mul Matrix A .* B => C */
            
            pListB = RING_API_GETLIST(4) ;

            nRow   = ring_list_getsize(pList);      // Row-A
            pRow   = ring_list_getlist(pList, nRow);
            nEnd   = ring_list_getsize(pRow) ;      // Col-A

            nRowB   = ring_list_getsize(pListB) ;
            pRowB   = ring_list_getlist(pListB, nRowB);
            nEndB   = ring_list_getsize(pRowB) ;

            if ( (nRow != nRowB) || (nEnd != nEndB) ) {
                RING_API_ERROR("Element-Wise Mul: Matrices must have same dimensions");
                return ;
            }

            //--- CREATE Output List - Same Dims.-----
            pListC  = RING_API_NEWLISTUSINGBLOCKS2D( nRow, nEnd) ;

            for ( vA = 1 ; vA <= nRow ; vA++ ) {
                pSubList  = ring_list_getlist(pList, vA) ;
                pSubListB = ring_list_getlist(pListB, vA) ;
                pSubListC = ring_list_getlist(pListC, vA) ;

                for ( hB = 1 ; hB <= nEnd ; hB++ ) {
                     valueA = ring_list_getdouble(pSubList, hB);
                     valueB = ring_list_getdouble(pSubListB, hB);
                     valueC = valueA * valueB;

                     ring_list_setdouble_gc(pVM->pRingState,pSubListC, hB, valueC);
                }
            }

            RING_API_RETLISTBYREF( pListC );
            break ;
        

      //===End 4406 ==============================  

     
    //===============================================
    //=== End CASES =================================
    
    }
}


void ring_mandelbrot(void *pPointer) {

         List *pList, *pListB, *pRow, *pRowB, *pSubList;

         /* MandelBrot Matrix-A (800x800)  MatrixB = Parameters aFlat */ 

         // aListC = updatelist(aListA,:mandelBrot,:matrix,aFlatB ) 
     
         //----------------------------------------
         double stepR, stepI, pointI, pointR, zI, zR, aZ, bZ, minI, maxI, minR, maxR ;
         
         int    width, height, iter, nZ, nRow, nEnd, nRowB, nEndB, x, i, y;  
             
         //-----------------------------------------

          pList  = RING_API_GETLIST(1) ;
          pListB = RING_API_GETLIST(4) ;
         
          nRow   = ring_list_getsize(pList);           //  Row-A  size 800
          pRow   = ring_list_getlist(pList,nRow);
          nEnd   = ring_list_getsize(pRow) ;           //  Col-A  size800 
          
               
         nRowB   = ring_list_getsize(pListB);          //  Row-B  size 9 Flat
         pRowB   = ring_list_getlist(pList,nRowB);
         nEndB   = ring_list_getsize(pRowB) ;          //  Col-B  size 0         
               
        //-------------------        

        //----------------------------------------------
        // READ aListB PARAMS 
         
                  minI   = ring_list_getdouble( pListB, 1) ;  // Col-A = value 
                  maxI   = ring_list_getdouble( pListB, 2) ;
                  minR   = ring_list_getdouble( pListB, 3) ;
                  maxR   = ring_list_getdouble( pListB, 4) ;
                  iter   = ring_list_getdouble( pListB, 5) ;
                  stepI  = ring_list_getdouble( pListB, 6) ;
                  stepR  = ring_list_getdouble( pListB, 7) ;
                  width  = ring_list_getdouble( pListB, 8) ;
                  height = ring_list_getdouble( pListB, 9) ;
                  
                  
        //--------------------------------------------  

    //-------------------------------------------------------------
    // PART 1
    // Update the Table ROWS and COLUMS  X-Y. 
    // We want Height and Width Y-X
  
    for (y = 1 ; y <= nRow ; y++ )
    {   
       pSubList = ring_list_getlist(pList, y) ;   // Row       
       pointI   = minI + (stepI * y );         // Imaginary + Step

            
       for (x = 1 ; x <= nEnd ; x++ )      
       {  
          pointR = minR + (stepR * x) ;        // Real horizontal + Step

          zR = pointR ;                        // Depth - horizontal-real
          zI = pointI ;                        // Depth - vertical-imaginary

          for (nZ = 0 ; nZ < iter; nZ++)
          {                                    // Does it leave Orbit ?
                  aZ = zR * zR ;               // zR^2  - horizontal-real
                  bZ = zI * zI ;               // zI^2  - vertical-imaginary

                  if ( (aZ + bZ) > 4 )
                  {
                     break;
                  }                                // Beyond boundary limits +-2
 
                  zI = (2 * zR * zI) + pointI ;    // Vertical-imaginary + Step
                  zR = (aZ - bZ) + pointR ;        // Horizontal-real

          }  
          
          ring_list_setdouble( pSubList, x, nZ );  // Col, N = color to draw

       }
    } 
   
    //==============================================================
    // PART 2
    // Calc DrawBYTES Color char value for each N in pList 2D array
    // 100x100xx =   40000   40x40x4 = 6400
    // 200x200x4 =  160000
    // 400x400x4 =  640000
    // 800x800x4 = 2560000
    
       int  nItems  = width * height * 4 ; 
       char *FList = (char *) RING_API_MALLOC(nItems * sizeof(char));
            
       int N = 0; 
       int nPenID = 0;
       int nLastPenID = 0;

       //--- DrawBytes() Color Table uses CHAR value---
       char aCHR[12][4] = 
                  {
                    { 255, 255, 255, 255},   //  0  1 White 
                    {   0, 255, 128, 255},   //  1  0 204,0,0,255 Red
                    {   0, 204,   0, 255},   //  2  3 Green 
                    {   0,   0, 255, 255},   //  3  4 Blue  
                    { 128, 128, 128, 255},   //  4  5 Gray  
                    { 153,  76,   0, 255},   //  5  6 Brown 
                    { 255, 178, 159, 255},   //  6  7 Grape 
                    { 255, 128,   0, 255},   //  7  8 Orange
                    { 255, 255,   0, 255},   //  8  9 Yellow
                    { 153, 153, 255, 255},   //  9 10 Purple
                    { 255,  51, 255, 255},   // 10 11 Pink  
                    { 128, 255,   0, 255}    // 11 12 Lime                                                    
                  };                              
                  
       //----------------------------------------------
        
       i = 0;
       for( x = 1; x <= width; x++)                    // Rotate Image using x-y Horz-Vert
       {    pSubList = ring_list_getlist(pList, x) ;   // Row
       
            for( y = 1; y <= height; y++)              // Col
            {              

               N = ring_list_getdouble( pSubList, y ); // Row-x  Col-y 

               if( N > 0 && N < iter )                 // 1..50 Color N to char
               { 
                   nPenID = ((N % 12) );              // C=0    N=1..49 Mod=1..11,0
                   
                   FList[++i] = aCHR[nPenID][0] ;     
                   FList[++i] = aCHR[nPenID][1] ;               
                   FList[++i] = aCHR[nPenID][2] ;                
                   FList[++i] = aCHR[nPenID][3] ;    
               }   
               else
               {   
                 i = i+4 ;    // Skip over Black pixel
               }
  
            }           
       }  

       // Return CHAR Array as String nItems
       RING_API_RETSTRING2( FList, nItems );   // ?? Ret Char Array 

       // Free memory
       RING_API_FREE(FList); 



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

    RING_API_FREE(pNewBytes);

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
