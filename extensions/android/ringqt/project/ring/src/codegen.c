/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
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
    pParser->ActiveGenCodeList = ring_list_newlist_gc(NULL,pParser->GenCode);
    ring_list_addint_gc(NULL,pParser->ActiveGenCodeList,opcode);
}

void ring_parser_icg_insertoperation ( Parser *pParser , int nPos , IC_OPERATIONS opcode )
{
    assert(pParser != NULL);
    pParser->ActiveGenCodeList = ring_list_insertlist(pParser->GenCode,nPos);
    ring_list_addint_gc(NULL,pParser->ActiveGenCodeList,opcode);
}

void ring_parser_icg_newoperand ( Parser *pParser , const char *cStr )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    ring_list_addstring_gc(NULL,pParser->ActiveGenCodeList,cStr);
}

void ring_parser_icg_addtooperand ( Parser *pParser , const char *cStr )
{
    String *pString  ;
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    pString = ring_item_getstring(ring_list_getitem(pParser->ActiveGenCodeList,ring_list_getsize(pParser->ActiveGenCodeList)));
    ring_string_add_gc(NULL,pString,cStr);
}

void ring_parser_icg_newoperandint ( Parser *pParser , int nValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    ring_list_addint_gc(NULL,pParser->ActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperanddouble ( Parser *pParser , double nValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList  != NULL);
    ring_list_adddouble_gc(NULL,pParser->ActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperandpointer ( Parser *pParser , void *pValue )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    ring_list_addpointer_gc(NULL,pParser->ActiveGenCodeList,pValue);
}

List * ring_parser_icg_getactiveoperation ( Parser *pParser )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    return pParser->ActiveGenCodeList ;
}

void ring_parser_icg_addoperand ( Parser *pParser ,List *pList , const char *cStr )
{
    assert(pParser != NULL);
    assert(pList != NULL);
    ring_list_addstring_gc(NULL,pList,cStr);
}

void ring_parser_icg_addoperandint ( Parser *pParser ,List *pList , int nValue )
{
    assert(pParser != NULL);
    assert(pList != NULL);
    ring_list_addint_gc(NULL,pList,nValue);
}

void ring_parser_icg_addoperandpointer ( Parser *pParser ,List *pList , void *pValue )
{
    assert(pParser != NULL);
    assert(pList != NULL);
    ring_list_addpointer_gc(NULL,pList,pValue);
}

void ring_parser_icg_deletelastoperation ( Parser *pParser )
{
    assert(pParser != NULL);
    if ( ring_list_getsize(pParser->GenCode) > 0 ) {
        ring_list_deleteitem_gc(NULL,pParser->GenCode,ring_list_getsize(pParser->GenCode));
        pParser->ActiveGenCodeList = ring_list_getlist(pParser->GenCode,ring_list_getsize(pParser->GenCode));
    }
}

void ring_parser_icg_duplicate ( Parser *pParser,int nStart,int nEnd )
{
    List *pList,*pList2  ;
    int x  ;
    assert(pParser != NULL);
    if ( (nStart <= nEnd) && ( nEnd <= ring_list_getsize(pParser->GenCode) ) ) {
        for ( x = nStart ; x <= nEnd ; x++ ) {
            pList = ring_list_newlist_gc(NULL,pParser->GenCode);
            pList2 = ring_list_getlist(pParser->GenCode,x);
            ring_list_copy_gc(NULL,pList,pList2);
        }
    }
}

int ring_parser_icg_newlabel2 ( Parser *pParser )
{
    assert(pParser != NULL);
    ring_parser_icg_newoperation(pParser,ICO_NEWLABEL);
    return ring_list_getsize(pParser->GenCode) + pParser->pRingState->nInstructionsCount ;
}

void ring_parser_icg_setopcode ( Parser *pParser ,List *pList , int nValue )
{
    assert(pParser != NULL);
    ring_list_setint_gc(NULL,pList,1,nValue);
}

void ring_parser_icg_deleteoperand ( Parser *pParser , int nPos )
{
    assert(pParser != NULL);
    assert(pParser->ActiveGenCodeList != NULL);
    ring_list_deleteitem_gc(NULL,pParser->ActiveGenCodeList,nPos);
}
/* Specific Instructions */

void ring_parser_icg_loadfunction ( Parser *pParser,const char *cFunctionName )
{
    assert(pParser != NULL);
    ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
    ring_parser_icg_newoperand(pParser,cFunctionName);
    ring_parser_icg_newoperandint(pParser,0);
}

void ring_parser_icg_loadaddress ( Parser *pParser,const char *cVariableName )
{
    assert(pParser != NULL);
    /* Extra Parameters */
    ring_parser_icg_newoperation(pParser,ICO_EXTRAPARA);
    ring_parser_icg_newoperandint(pParser,0);
    ring_parser_icg_newoperandint(pParser,0);
    ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
    ring_parser_icg_newoperand(pParser,cVariableName);
    ring_parser_icg_newoperandint(pParser,0);
    ring_parser_icg_newoperandint(pParser,0);
}

void ring_parser_icg_loadaddressassignmentpos ( Parser *pParser,List *pLoadAPos,int nPos )
{
    assert(pParser != NULL);
    ring_list_setint_gc(pParser->pRingState,pLoadAPos,4,nPos);
}

void ring_parser_icg_loadaddresstoloadfunction ( Parser *pParser )
{
    RING_PARSER_ICG_INSTRUCTIONSLISTTYPE *pList  ;
    assert(pParser != NULL);
    ring_parser_icg_setlastoperation(pParser,ICO_LOADFUNC);
    /*
    **  The ICO_LOADADDRESS uses 3 operands after the Variable Name 
    **  While the ICO_LOADFUNC uses 4 operands after the function name 
    **  So we add another operand 
    */
    pList = ring_parser_icg_getoperationlist(pParser,ring_list_getsize(pParser->GenCode)-1) ;
    ring_parser_icg_addoperandint(pParser,pList,0);
}

void ring_parser_icg_freestack ( Parser *pParser )
{
    assert(pParser != NULL);
    ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
}

void ring_parser_icg_newline ( Parser *pParser,int nLine )
{
    assert(pParser != NULL);
    if ( pParser->pRingState->lNoLineNumber != 0 ) {
        return ;
    }
    ring_parser_icg_newoperation(pParser,ICO_NEWLINE);
    ring_parser_icg_newoperandint(pParser,nLine);
}

char * ring_parser_icg_parentclassname ( Parser *pParser )
{
    assert(pParser != NULL);
    /* This function assume that the current instruction define new class and return the parent class name */
    return ring_list_getstring(pParser->ActiveGenCodeList ,RING_PARSER_ICG_PARENTCLASSPOS) ;
}

char * ring_parser_icg_newpackagename ( Parser *pParser,List *pPos )
{
    return ring_list_getstring(pPos,2) ;
}
/* Show the Intermediate Code */

void ring_parser_icg_showoutput ( List *pListGenCode )
{
    int x,y,nCount,nCount2  ;
    List *pList  ;
    assert(pListGenCode != NULL);
    /* Header */
    printf( "\n\n" ) ;
    ring_general_printline();
    puts(" Byte Code - Before Execution by the VM");
    ring_general_printline();
    nCount = ring_list_getsize(pListGenCode);
    if ( nCount > 0 ) {
        printf( "\n %6s  %18s  %29s\n", "PC","OPCode","Data" ) ;
        for ( x = 1 ; x <= nCount ; x++ ) {
            pList = ring_list_getlist(pListGenCode,x);
            nCount2 = ring_list_getsize(pList);
            printf( "\n %6d  %18s  ", x , RING_IC_OP[ring_list_getint(pList,1)] ) ;
            if ( nCount2 > 1 ) {
                for ( y = 2 ; y <= nCount2 ; y++ ) {
                    if ( ring_list_isstring(pList,y) ) {
                        printf( " %12s ",ring_list_getstring(pList,y) ) ;
                    }
                    else if ( ring_list_isnumber(pList,y) ) {
                        if ( ring_list_isdouble(pList,y) ) {
                            printf( " %12f",ring_list_getdouble(pList,y) ) ;
                        }
                        else {
                            printf( " %12d ",ring_list_getint(pList,y) ) ;
                        }
                    }
                    else {
                        printf( " %12p ",ring_list_getpointer(pList,y) ) ;
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
