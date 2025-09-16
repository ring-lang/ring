/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_parser_icg_newoperation(Parser *pParser, IC_OPERATIONS nOPCode) {
	if (pParser->lInsertFlag == RING_TRUE) {
		ring_parser_icg_insertoperation(pParser, pParser->nInsertCounter, nOPCode);
		pParser->nInsertCounter++;
		return;
	}
	pParser->pActiveGenCodeList = ring_list_newlist_gc(NULL, pParser->pGenCode);
	ring_list_addint_gc(NULL, pParser->pActiveGenCodeList, nOPCode);
}

void ring_parser_icg_insertoperation(Parser *pParser, int nPos, IC_OPERATIONS nOPCode) {
	pParser->pActiveGenCodeList = ring_list_insertlist(pParser->pGenCode, nPos);
	ring_list_addint_gc(NULL, pParser->pActiveGenCodeList, nOPCode);
}

void ring_parser_icg_newoperand(Parser *pParser, const char *cStr) {
	ring_list_addstring_gc(NULL, pParser->pActiveGenCodeList, cStr);
}

void ring_parser_icg_addtooperand(Parser *pParser, const char *cStr) {
	String *pString;
	pString = ring_item_getstring(ring_list_getitem_gc(pParser->pRingState, pParser->pActiveGenCodeList,
							   ring_list_getsize(pParser->pActiveGenCodeList)));
	ring_string_add_gc(NULL, pString, cStr);
}

void ring_parser_icg_newoperandint(Parser *pParser, int nValue) {
	ring_list_addint_gc(NULL, pParser->pActiveGenCodeList, nValue);
}

void ring_parser_icg_newoperanddouble(Parser *pParser, double nValue) {
	ring_list_adddouble_gc(NULL, pParser->pActiveGenCodeList, nValue);
}

void ring_parser_icg_newoperandpointer(Parser *pParser, void *pValue) {
	ring_list_addpointer_gc(NULL, pParser->pActiveGenCodeList, pValue);
}

List *ring_parser_icg_getactiveoperation(Parser *pParser) { return pParser->pActiveGenCodeList; }

void ring_parser_icg_addoperand(Parser *pParser, List *pList, const char *cStr) {
	ring_list_addstring_gc(NULL, pList, cStr);
}

void ring_parser_icg_addoperandint(Parser *pParser, List *pList, int nValue) {
	ring_list_addint_gc(NULL, pList, nValue);
}

void ring_parser_icg_addoperandpointer(Parser *pParser, List *pList, void *pValue) {
	ring_list_addpointer_gc(NULL, pList, pValue);
}

void ring_parser_icg_deletelastoperation(Parser *pParser) {
	if (ring_list_getsize(pParser->pGenCode)) {
		ring_list_deleteitem_gc(NULL, pParser->pGenCode, ring_list_getsize(pParser->pGenCode));
		pParser->pActiveGenCodeList =
		    ring_list_getlist(pParser->pGenCode, ring_list_getsize(pParser->pGenCode));
	}
}

void ring_parser_icg_duplicate(Parser *pParser, unsigned int nStart, unsigned int nEnd) {
	List *pList, *pList2;
	unsigned int x;
	if ((nStart <= nEnd) && (nEnd <= ring_list_getsize(pParser->pGenCode))) {
		for (x = nStart; x <= nEnd; x++) {
			pList = ring_list_newlist_gc(NULL, pParser->pGenCode);
			pList2 = ring_list_getlist(pParser->pGenCode, x);
			ring_list_copy_gc(NULL, pList, pList2);
		}
	}
}

int ring_parser_icg_newlabel2(Parser *pParser) {
	ring_parser_icg_newoperation(pParser, ICO_NEWLABEL);
	return ring_list_getsize(pParser->pGenCode) + pParser->pRingState->nInstructionsCount;
}

void ring_parser_icg_setopcode(Parser *pParser, List *pList, int nValue) {
	ring_list_setint_gc(NULL, pList, RING_PARSER_ICG_OPERATIONCODE, nValue);
}

void ring_parser_icg_deleteoperand(Parser *pParser, int nPos) {
	ring_list_deleteitem_gc(NULL, pParser->pActiveGenCodeList, nPos);
}

const char *ring_parser_icg_getlaststring(Parser *pParser) {
	return ring_list_getstring(pParser->pActiveGenCodeList, ring_list_getsize(pParser->pActiveGenCodeList));
}

void ring_parser_icg_setoperandint(Parser *pParser, List *pList, int nPos, int nValue) {
	ring_list_setint_gc(NULL, pList, nPos, nValue);
}

int ring_parser_icg_getlastoperation(Parser *pParser) {
	if ((pParser->pActiveGenCodeList == NULL) || (ring_list_getsize(pParser->pActiveGenCodeList) < RING_ONE)) {
		return RING_PARSER_ICG_NOOPERATION;
	}
	return ring_list_getint(pParser->pActiveGenCodeList, RING_PARSER_ICG_OPERATIONCODE);
}

int ring_parser_icg_getoperationbeforelastoperation(Parser *pParser) {
	if (ring_list_getsize(pParser->pGenCode) <= RING_ONE) {
		return RING_PARSER_ICG_NOOPERATION;
	}
	return ring_list_getint(
	    ring_parser_icg_getoperationlist(pParser, ring_list_getsize(pParser->pGenCode) - RING_ONE),
	    RING_PARSER_ICG_OPERATIONCODE);
}

void ring_parser_icg_loadfunction(Parser *pParser, const char *cFunctionName) {
	ring_parser_icg_newoperation(pParser, ICO_LOADFUNC);
	ring_parser_icg_newoperand(pParser, cFunctionName);
}

void ring_parser_icg_loadaddress(Parser *pParser, const char *cVariableName) {
	ring_parser_icg_newoperation(pParser, ICO_LOADADDRESS);
	ring_parser_icg_newoperand(pParser, cVariableName);
}

void ring_parser_icg_loadaddresstoloadfunction(Parser *pParser) {
	ring_parser_icg_setlastoperation(pParser, ICO_LOADFUNC);
}

void ring_parser_icg_freestack(Parser *pParser) { ring_parser_icg_newoperation(pParser, ICO_FREESTACK); }

void ring_parser_icg_newline(Parser *pParser, int nLine) {
	if (pParser->pRingState->lNoLineNumber) {
		return;
	}
	if ((pParser->pActiveGenCodeList != NULL) && (ring_parser_icg_getlastoperation(pParser) == ICO_NEWLINE)) {
		ring_parser_icg_setoperandint(pParser, pParser->pActiveGenCodeList, RING_PARSER_ICG_PARA1, nLine);
		return;
	}
	ring_parser_icg_newoperation(pParser, ICO_NEWLINE);
	ring_parser_icg_newoperandint(pParser, nLine);
}

char *ring_parser_icg_parentclassname(Parser *pParser) {
	/* This function assume that the current instruction define new class and return the parent class name */
	return ring_list_getstring(pParser->pActiveGenCodeList, RING_PARSER_ICG_PARENTCLASSPOS);
}

void ring_parser_icg_deleteparentclassname(Parser *pParser) {
	/* This function assume that the current instruction define new class and have the parent class name */
	if (ring_list_getsize(pParser->pActiveGenCodeList) >= RING_PARSER_ICG_PARENTCLASSPOS) {
		ring_list_deleteitem_gc(NULL, pParser->pActiveGenCodeList, RING_PARSER_ICG_PARENTCLASSPOS);
	}
}

char *ring_parser_icg_newpackagename(Parser *pParser, List *pPos) {
	return ring_list_getstring(pPos, RING_PARSER_ICG_PARA1);
}

void ring_parser_icg_pushn(Parser *pParser, double nValue) {
	int nLastOperation, lChange;
	/* Optimizations */
	lChange = RING_FALSE;
	if (pParser->pActiveGenCodeList != NULL) {
		nLastOperation = ring_parser_icg_getlastoperation(pParser);
		if (nLastOperation == ICO_PUSHN) {
			ring_parser_icg_setlastoperation(pParser, ICO_PUSH2N);
			lChange = RING_TRUE;
		}
	}
	if (!lChange) {
		ring_parser_icg_newoperation(pParser, ICO_PUSHN);
	}
	ring_parser_icg_newoperanddouble(pParser, nValue);
}

void ring_parser_icg_beforeequal(Parser *pParser, int nBeforeEqual) {
	if (nBeforeEqual == OP_EQUAL) {
		return;
	}
	ring_parser_icg_newoperation(pParser, ICO_BEFOREEQUAL);
	ring_parser_icg_newoperandint(pParser, nBeforeEqual);
}

void ring_parser_icg_retnull(Parser *pParser) {
	if ((pParser->pActiveGenCodeList != NULL) && (ring_parser_icg_getlastoperation(pParser) == ICO_RETURN)) {
		return;
	}
	ring_parser_icg_newoperation(pParser, ICO_RETNULL);
}

void ring_parser_icg_listitem(Parser *pParser) {
	int nLastOperation;
	if (pParser->pActiveGenCodeList != NULL) {
		nLastOperation = ring_parser_icg_getlastoperation(pParser);
		if (nLastOperation == ICO_LISTEND) {
			return;
		} else if (nLastOperation == ICO_PUSHN) {
			ring_parser_icg_setlastoperation(pParser, ICO_LISTITEMN);
			return;
		} else if (nLastOperation == ICO_PUSHC) {
			ring_parser_icg_setlastoperation(pParser, ICO_LISTITEMC);
			return;
		}
	}
	ring_parser_icg_newoperation(pParser, ICO_LISTITEM);
}

void ring_parser_icg_gensetglobalscope(Parser *pParser) {
	int nGlobalScope;
	/* Note: ICO_NEWFUNC and ICO_NEWCLASS set the current global scope to zero */
	nGlobalScope = ring_list_getint(pParser->pRingState->pCustomGlobalScopeStack,
					ring_list_getsize(pParser->pRingState->pCustomGlobalScopeStack));
	if (nGlobalScope != RING_ZERO) {
		ring_parser_icg_newoperation(pParser, ICO_SETGLOBALSCOPE);
		ring_parser_icg_newoperandint(pParser, nGlobalScope);
	}
}

void ring_parser_icg_math(Parser *pParser, IC_OPERATIONS nOPCode, IC_OPERATIONS nOPCodeV) {
	if ((pParser->pActiveGenCodeList != NULL) && (ring_parser_icg_getlastoperation(pParser) == ICO_PUSHN)) {
		ring_parser_icg_setlastoperation(pParser, nOPCodeV);
		return;
	}
	ring_parser_icg_newoperation(pParser, nOPCode);
}

void ring_parser_icg_returnn(Parser *pParser) {
	if ((pParser->pActiveGenCodeList != NULL) && (ring_parser_icg_getlastoperation(pParser) == ICO_PUSHN)) {
		ring_parser_icg_setlastoperation(pParser, ICO_RETURNN);
		return;
	}
	ring_parser_icg_newoperation(pParser, ICO_RETURN);
}
/* General Blocks of ByteCode */

void ring_parser_icg_gencallbracemethod(Parser *pParser, const char *cMethod, int lDuplicateStackValue) {
	int nMark1;
	List *pMark;
	/* if ismethod(self,cMethod) cMethod() ok */
	ring_parser_icg_newoperation(pParser, ICO_CHECKBRACEMETHOD);
	ring_parser_icg_newoperand(pParser, cMethod);
	/* Jump */
	ring_parser_icg_newoperation(pParser, ICO_JUMPZERO);
	pMark = ring_parser_icg_getactiveoperation(pParser);
	ring_parser_icg_loadfunction(pParser, cMethod);
	/* Duplicate the value in the Stack */
	if (lDuplicateStackValue == RING_TRUE) {
		ring_parser_icg_newoperation(pParser, ICO_DUPLICATE);
	}
	ring_parser_icg_newoperation(pParser, ICO_CALL);
	ring_parser_icg_newoperation(pParser, ICO_NOOP);
	ring_parser_icg_newoperation(pParser, ICO_PUSHV);
	nMark1 = ring_parser_icg_newlabel(pParser);
	ring_parser_icg_addoperandint(pParser, pMark, nMark1);
}

void ring_parser_icg_gencall(Parser *pParser, int nCallMethod) {
	/* Generate Code */
	ring_parser_icg_newoperation(pParser, ICO_CALL);
	if (nCallMethod == RING_ONE) {
		/* Add 0 For Operator Overloading */
		ring_parser_icg_newoperandint(pParser, RING_ZERO);
		/* Add 1 so the call instruction move list from pBeforeObjState to pObjState */
		ring_parser_icg_newoperandint(pParser, RING_TRUE);
		ring_parser_icg_newoperation(pParser, ICO_AFTERCALLMETHOD);
	} else {
		/* Add 0 For Operator Overloading */
		ring_parser_icg_newoperandint(pParser, RING_ZERO);
		/*
		**  The No Operation Instruction may be converted to AfterCallMethod during runtime
		**  This happens when we call method like functions inside object { }
		*/
		ring_parser_icg_newoperation(pParser, ICO_NOOP);
	}
}

void ring_parser_icg_genfreetemplists(Parser *pParser) {
	/* Using the Free Temp Lists instruction */
	ring_parser_icg_newoperation(pParser, ICO_FREETEMPLISTS);
	/*
	**  Ring VM will use extra registers for this instruction
	**  To store the number of temp variables before calling the instruction for the first time
	**  And store the Scope ID of the Current Function
	**  Each time Ring VM call a function, we get a new Scope ID
	**  We cache this Scope ID, If it's changed this means we have a new function call
	**  In this case we refresh the number of temp. variables
	*/
}

void ring_parser_icg_genppmm(Parser *pParser, int nMode, int nValue) {
	List *pMark;
	int nMark;
	/* Code Generation */
	if ((nMode == RING_PARSER_ICG_USEASSIGNMENT) || (nMode == RING_PARSER_ICG_USESETPROPERTY)) {
		/* Code Generation */
		ring_parser_icg_newoperation(pParser, ICO_ASSIGNMENTPOINTER);
		ring_parser_icg_newoperandint(pParser, RING_FALSE);
		pMark = ring_parser_icg_getactiveoperation(pParser);
		/* Duplicate the address two times, one for the assignment (x = x+1) and one to keep the value */
		ring_parser_icg_newoperation(pParser, ICO_DUPLICATE);
		if (nMode == RING_PARSER_ICG_USESETPROPERTY) {
			ring_parser_icg_newoperandint(pParser, RING_PARSER_ICG_USESETPROPERTY);
		} else {
			ring_parser_icg_newoperandint(pParser, RING_ONE);
		}
		ring_parser_icg_newoperation(pParser, ICO_DUPLICATE);
		ring_parser_icg_newoperation(pParser, ICO_PUSHV);
		ring_parser_icg_pushn(pParser, nValue);
		ring_parser_icg_newoperation(pParser, ICO_SUM);
		ring_parser_icg_newoperandint(pParser, RING_ZERO);
		ring_parser_icg_beforeequal(pParser, OP_EQUAL);
		if (nMode == RING_PARSER_ICG_USEASSIGNMENT) {
			nMark = ring_parser_icg_newlabel(pParser);
			ring_parser_icg_newoperation(pParser, ICO_ASSIGNMENT);
			ring_parser_icg_addoperandint(pParser, pMark, nMark);
		} else {
			ring_parser_icg_newoperation(pParser, ICO_SETPROPERTY);
		}
		/* Keep the value on the Stack (Maybe required in expressions) */
		ring_parser_icg_newoperation(pParser, ICO_PUSHV);
	} else if (nMode == RING_PARSER_ICG_NORMALPP) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser, ICO_PLUSPLUS);
		ring_parser_icg_newoperation(pParser, ICO_PUSHV);
		RING_STATE_PRINTRULE(RING_RULE_PLUSPLUS);
	} else if (nMode == RING_PARSER_ICG_NORMALMM) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser, ICO_MINUSMINUS);
		ring_parser_icg_newoperation(pParser, ICO_PUSHV);
		RING_STATE_PRINTRULE(RING_RULE_MINUSMINUS);
	}
}

void ring_parser_icg_showoutput(RingState *pRingState) {
	int x, y, nCount, nCount2;
	List *pList, *pListGenCode;
	pListGenCode = pRingState->pRingGenCode;
	/* Header */
	printf("\n\n");
	ring_general_printline();
	puts(" Byte Code - Before Execution by the VM");
	ring_general_printline();
	nCount = ring_list_getsize(pListGenCode);
	if (nCount > RING_ZERO) {
		printf("\n %6s  %18s  %19s %19s\n", "PC", "OPCode", "Reg1", "Reg2");
		for (x = RING_ONE; x <= nCount; x++) {
			pList = ring_list_getlist(pListGenCode, x);
			nCount2 = ring_list_getsize(pList);
			printf("\n %6d  %18s  ", x, RING_IC_OP[ring_list_getint(pList, RING_PARSER_ICG_OPERATIONCODE)]);
			if (nCount2 > RING_ONE) {
				for (y = 2; y <= nCount2; y++) {
					if (ring_list_isstring(pList, y)) {
						printf(" %18s ", ring_list_getstring(pList, y));
					} else if (ring_list_isnumber(pList, y)) {
						if (ring_list_isdouble(pList, y)) {
							printf(" %18f", ring_list_getdouble(pList, y));
						} else {
							printf(" %18d ", ring_list_getint(pList, y));
						}
					} else {
						printf(" %18p ", ring_list_getpointer(pList, y));
					}
				}
			}
		}
		printf("\n");
	}
	/* End */
	puts(RING_CSTR_EMPTY);
	ring_general_printline();
	puts(RING_CSTR_EMPTY);
}
