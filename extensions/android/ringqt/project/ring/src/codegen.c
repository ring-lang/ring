/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_parser_icg_newoperation ( Parser *pParser , IC_OPERATIONS nOPCode )
{
	if ( pParser->lInsertFlag == 1 ) {
		ring_parser_icg_insertoperation(pParser,pParser->nInsertCounter,nOPCode);
		pParser->nInsertCounter++ ;
		return ;
	}
	pParser->pActiveGenCodeList = ring_list_newlist_gc(NULL,pParser->pGenCode);
	ring_list_addint_gc(NULL,pParser->pActiveGenCodeList,nOPCode);
}

void ring_parser_icg_insertoperation ( Parser *pParser , int nPos , IC_OPERATIONS nOPCode )
{
	pParser->pActiveGenCodeList = ring_list_insertlist(pParser->pGenCode,nPos);
	ring_list_addint_gc(NULL,pParser->pActiveGenCodeList,nOPCode);
}

void ring_parser_icg_newoperand ( Parser *pParser , const char *cStr )
{
	ring_list_addstring_gc(NULL,pParser->pActiveGenCodeList,cStr);
}

void ring_parser_icg_addtooperand ( Parser *pParser , const char *cStr )
{
	String *pString  ;
	pString = ring_item_getstring(ring_list_getitem(pParser->pActiveGenCodeList,ring_list_getsize(pParser->pActiveGenCodeList)));
	ring_string_add_gc(NULL,pString,cStr);
}

void ring_parser_icg_newoperandint ( Parser *pParser , int nValue )
{
	ring_list_addint_gc(NULL,pParser->pActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperanddouble ( Parser *pParser , double nValue )
{
	ring_list_adddouble_gc(NULL,pParser->pActiveGenCodeList,nValue);
}

void ring_parser_icg_newoperandpointer ( Parser *pParser , void *pValue )
{
	ring_list_addpointer_gc(NULL,pParser->pActiveGenCodeList,pValue);
}

List * ring_parser_icg_getactiveoperation ( Parser *pParser )
{
	return pParser->pActiveGenCodeList ;
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
	if ( ring_list_getsize(pParser->pGenCode) > 0 ) {
		ring_list_deleteitem_gc(NULL,pParser->pGenCode,ring_list_getsize(pParser->pGenCode));
		pParser->pActiveGenCodeList = ring_list_getlist(pParser->pGenCode,ring_list_getsize(pParser->pGenCode));
	}
}

void ring_parser_icg_duplicate ( Parser *pParser,int nStart,int nEnd )
{
	List *pList,*pList2  ;
	int x  ;
	if ( (nStart <= nEnd) && ( nEnd <= ring_list_getsize(pParser->pGenCode) ) ) {
		for ( x = nStart ; x <= nEnd ; x++ ) {
			pList = ring_list_newlist_gc(NULL,pParser->pGenCode);
			pList2 = ring_list_getlist(pParser->pGenCode,x);
			ring_list_copy_gc(NULL,pList,pList2);
		}
	}
}

int ring_parser_icg_newlabel2 ( Parser *pParser )
{
	ring_parser_icg_newoperation(pParser,ICO_NEWLABEL);
	return ring_list_getsize(pParser->pGenCode) + pParser->pRingState->nInstructionsCount ;
}

void ring_parser_icg_setopcode ( Parser *pParser ,List *pList , int nValue )
{
	ring_list_setint_gc(NULL,pList,RING_PARSER_ICG_OPERATIONCODE,nValue);
}

void ring_parser_icg_deleteoperand ( Parser *pParser , int nPos )
{
	ring_list_deleteitem_gc(NULL,pParser->pActiveGenCodeList,nPos);
}

void ring_parser_icg_loadfunction ( Parser *pParser,const char *cFunctionName )
{
	ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
	ring_parser_icg_newoperand(pParser,cFunctionName);
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
}

void ring_parser_icg_loadaddress ( Parser *pParser,const char *cVariableName )
{
	ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
	ring_parser_icg_newoperand(pParser,cVariableName);
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
}

void ring_parser_icg_loadaddressassignmentpos ( Parser *pParser,List *pLoadAPos,int nPos )
{
	ring_list_setint_gc(pParser->pRingState,pLoadAPos,RING_PARSER_ICG_LOADAASSIGNPOS,nPos);
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
	return ring_list_getstring(pParser->pActiveGenCodeList ,RING_PARSER_ICG_PARENTCLASSPOS) ;
}

char * ring_parser_icg_newpackagename ( Parser *pParser,List *pPos )
{
	return ring_list_getstring(pPos,RING_PARSER_ICG_PARA1) ;
}

void ring_parser_icg_pushn ( Parser *pParser,double nValue )
{
	int nLastOperation, lChange  ;
	/* Optimizations */
	lChange = 0 ;
	if ( pParser->pActiveGenCodeList != NULL ) {
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
/* General Blocks of ByteCode */

void ring_parser_icg_gencallbracemethod ( Parser *pParser,const char *cMethod,int lDuplicateStackValue )
{
	int nMark1  ;
	List *pMark  ;
	/* if ismethod(self,cMethod) cMethod() ok */
	ring_parser_icg_newoperation(pParser,ICO_CHECKBRACEMETHOD);
	ring_parser_icg_newoperand(pParser,cMethod);
	/* Jump */
	ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
	pMark = ring_parser_icg_getactiveoperation(pParser);
	ring_parser_icg_loadfunction(pParser,cMethod);
	/* Duplicate the value in the Stack */
	if ( lDuplicateStackValue == RING_TRUE ) {
		ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
	}
	ring_parser_icg_newoperation(pParser,ICO_CALL);
	ring_parser_icg_newoperation(pParser,ICO_NOOP);
	ring_parser_icg_newoperation(pParser,ICO_PUSHV);
	ring_parser_icg_freestack(pParser);
	nMark1 = ring_parser_icg_newlabel(pParser);
	ring_parser_icg_addoperandint(pParser,pMark,nMark1);
}

void ring_parser_icg_gencall ( Parser *pParser,int nCallMethod )
{
	/* Generate Code */
	ring_parser_icg_newoperation(pParser,ICO_CALL);
	if ( nCallMethod == 1 ) {
		/* Add 0 For Operator Overloading */
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		/* Add 1 so the call instruction move list from pBeforeObjState to pObjState */
		ring_parser_icg_newoperandint(pParser,RING_TRUE);
		ring_parser_icg_newoperation(pParser,ICO_AFTERCALLMETHOD);
	}
	else {
		/* Add 0 For Operator Overloading */
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		/*
		**  The No Operation Instruction may be converted to AfterCallMethod during runtime 
		**  This happens when we call method like functions inside object { } 
		*/
		ring_parser_icg_newoperation(pParser,ICO_NOOP);
	}
}

void ring_parser_icg_genfreetemplists ( Parser *pParser )
{
	/* Using the Free Temp Lists instruction */
	ring_parser_icg_newoperation(pParser,ICO_FREETEMPLISTS);
	/* The number of temp variables before calling the instruction for the first time */
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
	/*
	**  The Scope ID of the Current Function 
	**  Each time Ring VM call a function, we get a new Scope ID 
	**  We cache this Scope ID, If it's changed this means we have a new function call 
	**  In this case we refresh the number of temp. variables 
	*/
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
}

void ring_parser_icg_genppmm ( Parser *pParser,int nMode,int nValue )
{
	List *pMark  ;
	int nMark  ;
	pMark = ring_parser_icg_getactiveoperation(pParser);
	/* Code Generation */
	if ( (nMode == RING_PARSER_ICG_USEASSIGNMENT) || (nMode == RING_PARSER_ICG_USESETPROPERTY) ) {
		/* Code Generation */
		ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
		/* Duplicate the address two times, one for the assignment (x = x+1) and one to keep the value */
		ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
		ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
		ring_parser_icg_newoperation(pParser,ICO_PUSHV);
		ring_parser_icg_pushn(pParser,nValue);
		ring_parser_icg_newoperation(pParser,ICO_SUM);
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		ring_parser_icg_beforeequal(pParser,OP_EQUAL);
		if ( nMode == RING_PARSER_ICG_USEASSIGNMENT ) {
			nMark = ring_parser_icg_newlabel(pParser);
			ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
			ring_parser_icg_loadaddressassignmentpos(pParser,pMark,nMark);
		}
		else {
			ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
		}
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		/* Keep the value on the Stack (Maybe required in expressions) */
		ring_parser_icg_newoperation(pParser,ICO_PUSHV);
	}
	else if ( nMode == RING_PARSER_ICG_NORMALPP ) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_PLUSPLUS);
		ring_parser_icg_newoperation(pParser,ICO_PUSHV);
		RING_STATE_PRINTRULE(RING_RULE_PLUSPLUS) ;
	}
	else if ( nMode == RING_PARSER_ICG_NORMALMM ) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_MINUSMINUS);
		ring_parser_icg_newoperation(pParser,ICO_PUSHV);
		RING_STATE_PRINTRULE(RING_RULE_MINUSMINUS) ;
	}
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
			printf( "\n %6d  %18s  ", x , RING_IC_OP[ring_list_getint(pList,RING_PARSER_ICG_OPERATIONCODE)] ) ;
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
