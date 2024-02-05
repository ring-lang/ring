/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_parser_icg_newoperation ( Parser *pParser , IC_OPERATIONS opcode )
{
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
	pParser->ActiveGenCodeList = ring_list_insertlist(pParser->GenCode,nPos);
	ring_list_addint_gc(NULL,pParser->ActiveGenCodeList,opcode);
}

void ring_parser_icg_newoperand ( Parser *pParser , const char *cStr )
{
	ring_list_addstring_gc(NULL,pParser->ActiveGenCodeList,cStr);
}

void ring_parser_icg_addtooperand ( Parser *pParser , const char *cStr )
{
	String *pString  ;
	pString = ring_item_getstring(ring_list_getitem(pParser->ActiveGenCodeList,ring_list_getsize(pParser->ActiveGenCodeList)));
	ring_string_add_gc(NULL,pString,cStr);
}

void ring_parser_icg_newoperandint ( Parser *pParser , int nValue )
{
	ring_list_addint_gc(NULL,pParser->ActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperanddouble ( Parser *pParser , double nValue )
{
	ring_list_adddouble_gc(NULL,pParser->ActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperandpointer ( Parser *pParser , void *pValue )
{
	ring_list_addpointer_gc(NULL,pParser->ActiveGenCodeList,pValue);
}

List * ring_parser_icg_getactiveoperation ( Parser *pParser )
{
	return pParser->ActiveGenCodeList ;
}

void ring_parser_icg_addoperand ( Parser *pParser ,List *pList , const char *cStr )
{
	ring_list_addstring_gc(NULL,pList,cStr);
}

void ring_parser_icg_addoperandint ( Parser *pParser ,List *pList , int nValue )
{
	ring_list_addint_gc(NULL,pList,nValue);
}

void ring_parser_icg_addoperandpointer ( Parser *pParser ,List *pList , void *pValue )
{
	ring_list_addpointer_gc(NULL,pList,pValue);
}

void ring_parser_icg_deletelastoperation ( Parser *pParser )
{
	if ( ring_list_getsize(pParser->GenCode) > 0 ) {
		ring_list_deleteitem_gc(NULL,pParser->GenCode,ring_list_getsize(pParser->GenCode));
		pParser->ActiveGenCodeList = ring_list_getlist(pParser->GenCode,ring_list_getsize(pParser->GenCode));
	}
}

void ring_parser_icg_duplicate ( Parser *pParser,int nStart,int nEnd )
{
	List *pList,*pList2  ;
	int x  ;
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
	ring_parser_icg_newoperation(pParser,ICO_NEWLABEL);
	return ring_list_getsize(pParser->GenCode) + pParser->pRingState->nInstructionsCount ;
}

void ring_parser_icg_setopcode ( Parser *pParser ,List *pList , int nValue )
{
	ring_list_setint_gc(NULL,pList,1,nValue);
}

void ring_parser_icg_deleteoperand ( Parser *pParser , int nPos )
{
	ring_list_deleteitem_gc(NULL,pParser->ActiveGenCodeList,nPos);
}

void ring_parser_icg_loadfunction ( Parser *pParser,const char *cFunctionName )
{
	ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
	ring_parser_icg_newoperand(pParser,cFunctionName);
	ring_parser_icg_newoperandint(pParser,0);
}

void ring_parser_icg_loadaddress ( Parser *pParser,const char *cVariableName )
{
	ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
	ring_parser_icg_newoperand(pParser,cVariableName);
	ring_parser_icg_newoperandint(pParser,0);
	ring_parser_icg_newoperandint(pParser,0);
}

void ring_parser_icg_loadaddressassignmentpos ( Parser *pParser,List *pLoadAPos,int nPos )
{
	ring_list_setint_gc(pParser->pRingState,pLoadAPos,4,nPos);
}

void ring_parser_icg_loadaddresstoloadfunction ( Parser *pParser )
{
	ring_parser_icg_setlastoperation(pParser,ICO_LOADFUNC);
}

void ring_parser_icg_freestack ( Parser *pParser )
{
	ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
}

void ring_parser_icg_newline ( Parser *pParser,int nLine )
{
	if ( pParser->pRingState->lNoLineNumber != 0 ) {
		return ;
	}
	ring_parser_icg_newoperation(pParser,ICO_NEWLINE);
	ring_parser_icg_newoperandint(pParser,nLine);
}

char * ring_parser_icg_parentclassname ( Parser *pParser )
{
	/* This function assume that the current instruction define new class and return the parent class name */
	return ring_list_getstring(pParser->ActiveGenCodeList ,RING_PARSER_ICG_PARENTCLASSPOS) ;
}

char * ring_parser_icg_newpackagename ( Parser *pParser,List *pPos )
{
	return ring_list_getstring(pPos,2) ;
}

void ring_parser_icg_pushn ( Parser *pParser,double nValue )
{
	int nLastOperation, lChange  ;
	/* Optimizations */
	lChange = 0 ;
	if ( pParser->ActiveGenCodeList != NULL ) {
		nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
		if ( nLastOperation == ICO_PUSHN ) {
			ring_parser_icg_setlastoperation(pParser,ICO_PUSH2N);
			lChange = 1 ;
		}
		else if ( nLastOperation == ICO_PUSH2N ) {
			ring_parser_icg_setlastoperation(pParser,ICO_PUSH3N);
			lChange = 1 ;
		}
		else if ( nLastOperation == ICO_PUSH3N ) {
			ring_parser_icg_setlastoperation(pParser,ICO_PUSH4N);
			lChange = 1 ;
		}
	}
	if ( lChange == 0 ) {
		ring_parser_icg_newoperation(pParser,ICO_PUSHN);
	}
	ring_parser_icg_newoperanddouble(pParser,nValue);
}

void ring_parser_icg_beforeequal ( Parser *pParser,int nBeforeEqual )
{
	ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
	ring_parser_icg_newoperandint(pParser,nBeforeEqual);
}

void ring_parser_icg_showoutput ( List *pListGenCode )
{
	int x,y,nCount,nCount2  ;
	List *pList  ;
	/* Header */
	printf( "\n\n" ) ;
	ring_general_printline();
	puts(" Byte Code - Before Execution by the VM");
	ring_general_printline();
	nCount = ring_list_getsize(pListGenCode);
	if ( nCount > 0 ) {
		printf( "\n %6s  %18s  %19s\n", "PC","OPCode","Data" ) ;
		for ( x = 1 ; x <= nCount ; x++ ) {
			pList = ring_list_getlist(pListGenCode,x);
			nCount2 = ring_list_getsize(pList);
			printf( "\n %6d  %18s  ", x , RING_IC_OP[ring_list_getint(pList,1)] ) ;
			if ( nCount2 > 1 ) {
				for ( y = 2 ; y <= nCount2 ; y++ ) {
					if ( ring_list_isstring(pList,y) ) {
						printf( " %18s ",ring_list_getstring(pList,y) ) ;
					}
					else if ( ring_list_isnumber(pList,y) ) {
						if ( ring_list_isdouble(pList,y) ) {
							printf( " %18f",ring_list_getdouble(pList,y) ) ;
						}
						else {
							printf( " %18d ",ring_list_getint(pList,y) ) ;
						}
					}
					else {
						printf( " %18p ",ring_list_getpointer(pList,y) ) ;
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
