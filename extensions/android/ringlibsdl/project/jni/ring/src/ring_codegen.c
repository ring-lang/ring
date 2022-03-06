/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Generate Intermediate Code 
*/

void ring_parser_icg_newoperation ( Parser *pParser , IC_OPERATIONS opcode )
{
    assert(pParser != NULL);
    if ( pParser->nInsertFlag == 1 ) {
        ring_parser_icg_insertoperation(pParser,pParser->nInsertCounter,opcode);
        pParser->nInsertCounter++ ;
        return ;
    }
    pParser->ActiveGenCodeList = ring_list_newlist_gc(pParser->pRingState,pParser->GenCode);
    ring_list_addint_gc(pParser->pRingState,pParser->ActiveGenCodeList,opcode);
    #if RING_SHOWIC
        printf( "\n %6d [ %s ] ",ring_list_getsize(pParser->GenCode) , RING_IC_OP[opcode] ) ;
    #endif
}

void ring_parser_icg_insertoperation ( Parser *pParser , int nPos , IC_OPERATIONS opcode )
{
    assert(pParser != NULL);
    pParser->ActiveGenCodeList = ring_list_insertlist(pParser->GenCode,nPos);
    ring_list_addint_gc(pParser->pRingState,pParser->ActiveGenCodeList,opcode);
    #if RING_SHOWIC
        printf( "\n %6d [ %s ] ",nPos, RING_IC_OP[opcode] ) ;
    #endif
}

void ring_parser_icg_newoperand ( Parser *pParser , const char *cStr )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList);
    ring_list_addstring_gc(pParser->pRingState,pParser->ActiveGenCodeList,cStr);
    #if RING_SHOWIC
        printf( " Operand : %s ",cStr ) ;
    #endif
}

void ring_parser_icg_newoperandint ( Parser *pParser , int nValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList);
    ring_list_addint_gc(pParser->pRingState,pParser->ActiveGenCodeList,nValue);
    #if RING_SHOWIC
        printf( " Operand : %d ",nValue ) ;
    #endif
}

void ring_parser_icg_newoperanddouble ( Parser *pParser , double nValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList);
    ring_list_adddouble_gc(pParser->pRingState,pParser->ActiveGenCodeList,nValue);
    #if RING_SHOWIC
        printf( " Operand : %.5f ",nValue ) ;
    #endif
}

void ring_parser_icg_newoperandpointer ( Parser *pParser , void *pValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList);
    ring_list_addpointer_gc(pParser->pRingState,pParser->ActiveGenCodeList,pValue);
    #if RING_SHOWIC
        printf( " Operand : %p ",pValue ) ;
    #endif
}

List * ring_parser_icg_getactiveoperation ( Parser *pParser )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList);
    return pParser->ActiveGenCodeList ;
}

Items * ring_parser_icg_getoperationpos ( Parser *pParser )
{
    assert(pParser != NULL);
    assert(pParser->GenCode);
    return pParser->GenCode->pLast ;
}

void ring_parser_icg_addoperand ( Parser *pParser ,List *pList , const char *cStr )
{
    assert(pList != NULL);
    ring_list_addstring_gc(pParser->pRingState,pList,cStr);
}

void ring_parser_icg_addoperandint ( Parser *pParser ,List *pList , int nValue )
{
    assert(pList != NULL);
    ring_list_addint_gc(pParser->pRingState,pList,nValue);
}

void ring_parser_icg_addoperandpointer ( Parser *pParser ,List *pList , void *pValue )
{
    assert(pList != NULL);
    ring_list_addpointer_gc(pParser->pRingState,pList,pValue);
}

void ring_parser_icg_showoutput ( List *pListGenCode,int nStatus )
{
    int x,y,nCount,nCount2  ;
    List *pList  ;
    assert(pListGenCode != NULL);
    /* Header */
    printf( "\n\n" ) ;
    ring_general_printline();
    if ( nStatus == 1 ) {
        puts("Byte Code - Before Execution by the VM");
    }
    else {
        puts("Byte Code - After Execution by the VM");
    }
    ring_general_printline();
    nCount = ring_list_getsize(pListGenCode);
    if ( nCount > 0 ) {
        printf( "\n %6s  %10s  %10s\n", "PC","OPCode","Data" ) ;
        for ( x = 1 ; x <= nCount ; x++ ) {
            pList = ring_list_getlist(pListGenCode,x);
            nCount2 = ring_list_getsize(pList);
            printf( "\n %6d  %10s  ", x , RING_IC_OP[ring_list_getint(pList,1)] ) ;
            if ( nCount2 > 1 ) {
                for ( y = 2 ; y <= nCount2 ; y++ ) {
                    if ( ring_list_isstring(pList,y) ) {
                        printf( " %5s ",ring_list_getstring(pList,y) ) ;
                    }
                    else if ( ring_list_isnumber(pList,y) ) {
                        if ( ring_list_isdouble(pList,y) ) {
                            printf( " %f",ring_list_getdouble(pList,y) ) ;
                        }
                        else {
                            printf( " %5d ",ring_list_getint(pList,y) ) ;
                        }
                    }
                    else {
                        printf( " %5p ",ring_list_getpointer(pList,y) ) ;
                    }
                }
            }
        }
        printf( "\n" ) ;
    }
    /* End */
    puts("");
    ring_general_printline();
    puts("");
}

void ring_parser_icg_deletelastoperation ( Parser *pParser )
{
    if ( ring_list_getsize(pParser->GenCode) > 0 ) {
        ring_list_deleteitem_gc(pParser->pRingState,pParser->GenCode,ring_list_getsize(pParser->GenCode));
        pParser->ActiveGenCodeList = ring_list_getlist(pParser->GenCode,ring_list_getsize(pParser->GenCode));
    }
}

void ring_parser_icg_duplicate ( Parser *pParser,int nStart,int nEnd )
{
    List *pList,*pList2  ;
    int x  ;
    #if RING_SHOWIC
        int y,nCount2  ;
    #endif
    assert(pParser != NULL);
    if ( (nStart <= nEnd) && ( nEnd <= ring_parser_icg_instructionscount(pParser) ) ) {
        for ( x = nStart ; x <= nEnd ; x++ ) {
            pList = ring_list_newlist_gc(pParser->pRingState,pParser->GenCode);
            pList2 = ring_list_getlist(pParser->GenCode,x);
            ring_list_copy_gc(pParser->pRingState,pList,pList2);
            #if RING_SHOWIC
                nCount2 = ring_list_getsize(pList);
                printf( "\n %6d [ %s ] ", ring_list_getsize(pParser->GenCode) , RING_IC_OP[ring_list_getint(pList,1)] ) ;
                if ( nCount2 > 1 ) {
                    for ( y = 2 ; y <= nCount2 ; y++ ) {
                        if ( ring_list_isstring(pList,y) ) {
                            printf( " Operand : %s ",ring_list_getstring(pList,y) ) ;
                        }
                        else if ( ring_list_isnumber(pList,y) ) {
                            if ( ring_list_isdouble(pList,y) ) {
                                printf( " Operand : %f ",ring_list_getdouble(pList,y) ) ;
                            }
                            else {
                                printf( " Operand : %5d ",ring_list_getint(pList,y) ) ;
                            }
                        }
                        else {
                            printf( " Operand : %5p ",ring_list_getpointer(pList,y) ) ;
                        }
                    }
                }
            #endif
        }
    }
}

int ring_parser_icg_newlabel2 ( Parser *pParser )
{
    assert(pParser != NULL);
    ring_parser_icg_newoperation(pParser,ICO_NEWLABEL);
    return ring_list_getsize(pParser->GenCode) ;
}
