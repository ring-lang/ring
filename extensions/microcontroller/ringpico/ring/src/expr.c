/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_parser_expr ( Parser *pParser )
{
	int x,nMark  ;
	List *pMark  ;
	/* Expr --> LogicNot { and|or LogicNot } */
	if ( ring_parser_logicnot(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_EXPRISLOGICNOT) ;
		while ( ring_parser_iskeyword(pParser,K_AND) || ring_parser_isoperator2(pParser,OP_LOGAND)  || ring_parser_iskeyword(pParser,K_OR) || ring_parser_isoperator2(pParser,OP_LOGOR) ) {
			if ( ring_parser_iskeyword(pParser,K_AND) || ring_parser_isoperator2(pParser,OP_LOGAND) ) {
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_JUMPZERO2);
				pMark = ring_parser_icg_getactiveoperation(pParser);
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_logicnot(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_AND);
				nMark = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark);
				RING_STATE_PRINTTWORULES(RING_RULE_EXPRISLOGICNOT,RING_RULE_EXPRANDEXPR) ;
			}
			else {
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_JUMPONE2);
				pMark = ring_parser_icg_getactiveoperation(pParser);
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_logicnot(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				RING_STATE_PRINTTWORULES(RING_RULE_EXPRISLOGICNOT,RING_RULE_EXPROREXPR) ;
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_OR);
				nMark = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark);
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_logicnot ( Parser *pParser )
{
	int x  ;
	/* LogicNot --> Not EqualOrNot */
	if ( ring_parser_iskeyword(pParser,K_NOT) || ring_parser_isoperator2(pParser,OP_NOT) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		x = ring_parser_equalornot(pParser);
		if ( x == RING_PARSER_OK ) {
			RING_STATE_PRINTRULE(RING_RULE_LOGICNOTISNOT) ;
		}
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_NOT);
		return x ;
	}
	x = ring_parser_equalornot(pParser);
	if ( x == RING_PARSER_OK ) {
		RING_STATE_PRINTRULE(RING_RULE_LOGICNOTISEQUALORNOT) ;
	}
	return x ;
}

int ring_parser_equalornot ( Parser *pParser )
{
	int x  ;
	/* EqualOrNot --> Compare { =|!= Compare } */
	if ( ring_parser_compare(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_EQUALORNOTISCOMPARE) ;
		while ( ring_parser_isoperator2(pParser,OP_EQUAL) || ring_parser_isoperator2(pParser,OP_NOT) ) {
			if ( ring_parser_isoperator2(pParser,OP_NOT) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
					ring_parser_nexttoken(pParser);
					RING_PARSER_IGNORENEWLINE ;
					x = ring_parser_compare(pParser);
					if ( x == RING_PARSER_FAIL ) {
						return RING_PARSER_FAIL ;
					}
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_NOTEQUAL);
					RING_STATE_PRINTTWORULES(RING_RULE_EQUALORNOTISCOMPARE,RING_RULE_NOTEQUAL) ;
				}
				else {
					ring_parser_error(pParser,RING_PARSER_ERROR_EXPROPERATOR);
					return RING_PARSER_FAIL ;
				}
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_compare(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_EQUAL);
				RING_STATE_PRINTTWORULES(RING_RULE_EQUALORNOTISCOMPARE,RING_RULE_ISEQUAL) ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_compare ( Parser *pParser )
{
	int x,nEqual  ;
	/* Compare --> BitORXOR { <|>|<=|>= BITORXOR } */
	if ( ring_parser_bitorxor(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_COMPAREISBITORXOR) ;
		while ( ring_parser_isoperator2(pParser,OP_LESS) || ring_parser_isoperator2(pParser,OP_GREATER) ) {
			nEqual = 0 ;
			if ( ring_parser_isoperator2(pParser,OP_LESS) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
					nEqual = 1 ;
					ring_parser_nexttoken(pParser);
				}
				x = ring_parser_bitorxor(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				if ( nEqual == 0 ) {
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_LESS);
					RING_STATE_PRINTTWORULES(RING_RULE_COMPAREISBITORXOR,RING_RULE_LESSTHAN) ;
				}
				else {
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_LESSEQUAL);
					RING_STATE_PRINTTWORULES(RING_RULE_COMPAREISBITORXOR,RING_RULE_LESSTHANOREQUAL) ;
				}
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
					nEqual = 1 ;
					ring_parser_nexttoken(pParser);
					RING_PARSER_IGNORENEWLINE ;
				}
				x = ring_parser_bitorxor(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				if ( nEqual == 0 ) {
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_GREATER);
					RING_STATE_PRINTTWORULES(RING_RULE_COMPAREISBITORXOR,RING_RULE_GREATERTHAN) ;
				}
				else {
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_GREATEREQUAL);
					RING_STATE_PRINTTWORULES(RING_RULE_COMPAREISBITORXOR,RING_RULE_GREATERTHANOREQUAL) ;
				}
			}
			/* Check <> */
			if ( x == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_bitorxor ( Parser *pParser )
{
	int x  ;
	/* BitOrXOR --> BitAnd { | | ^ BitAnd } */
	if ( ring_parser_bitand(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_BITORXORISBITAND) ;
		while ( ring_parser_isoperator2(pParser,OP_BITOR) || ring_parser_isoperator2(pParser,OP_XOR) ) {
			if ( ring_parser_isoperator2(pParser,OP_BITOR) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_bitand(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_BITOR);
				RING_STATE_PRINTTWORULES(RING_RULE_BITORXORISBITAND,RING_RULE_BITOR) ;
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_bitand(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_BITXOR);
				RING_STATE_PRINTTWORULES(RING_RULE_BITORXORISBITAND,RING_RULE_XOR) ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_bitand ( Parser *pParser )
{
	int x  ;
	/* BitAnd --> BitShift { & BitShift } */
	if ( ring_parser_bitshift(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_BITANDISBITSHIFT) ;
		while ( ring_parser_isoperator2(pParser,OP_BITAND) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			x = ring_parser_bitshift(pParser);
			if ( x == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_BITAND);
			RING_STATE_PRINTTWORULES(RING_RULE_BITANDISBITSHIFT,RING_RULE_BITAND) ;
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_bitshift ( Parser *pParser )
{
	int x  ;
	/* BitShift --> Arith { << | >>  Arith } */
	if ( ring_parser_arithmetic(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_BITSHIFTISARITHMETIC) ;
		while ( ring_parser_isoperator2(pParser,OP_SHL) || ring_parser_isoperator2(pParser,OP_SHR) ) {
			if ( ring_parser_isoperator2(pParser,OP_SHL) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_arithmetic(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_BITSHL);
				RING_STATE_PRINTTWORULES(RING_RULE_BITSHIFTISARITHMETIC,RING_RULE_SHIFTLEFT) ;
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_arithmetic(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_BITSHR);
				RING_STATE_PRINTTWORULES(RING_RULE_BITSHIFTISARITHMETIC,RING_RULE_SHIFTRIGHT) ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_arithmetic ( Parser *pParser )
{
	int x  ;
	/* Arithmetic --> Term { +|- Term } */
	if ( ring_parser_term(pParser) ) {
		RING_STATE_PRINTRULE(RING_RULE_ARITHMETICISTERM) ;
		x = 1 ;
		while ( ring_parser_isoperator2(pParser,OP_PLUS) || ring_parser_isoperator2(pParser,OP_MINUS) ) {
			if ( ring_parser_isoperator2(pParser,OP_PLUS) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_term(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_SUM,ICO_SUMN);
				RING_STATE_PRINTTWORULES(RING_RULE_ARITHMETICISTERM,RING_RULE_PLUS) ;
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_term(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_SUB,ICO_SUBN);
				RING_STATE_PRINTTWORULES(RING_RULE_ARITHMETICISTERM,RING_RULE_MINUS) ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_term ( Parser *pParser )
{
	int x  ;
	/* Term --> Range { *|/|%|** Range } */
	if ( ring_parser_range(pParser) ) {
		x = 1 ;
		RING_STATE_PRINTRULE(RING_RULE_TERMISRANGE) ;
		while ( ring_parser_isoperator2(pParser,OP_MUL) || ring_parser_isoperator2(pParser,OP_DIV) || ring_parser_isoperator2(pParser,OP_MOD) || ring_parser_isoperator2(pParser,OP_POW) ) {
			if ( ring_parser_isoperator2(pParser,OP_MUL) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				RING_STATE_PRINTTWORULES(RING_RULE_TERMISRANGE,RING_RULE_MUL) ;
				x = ring_parser_range(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_MUL,ICO_MULN);
			}
			else if ( ring_parser_isoperator2(pParser,OP_MOD) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_range(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_MOD,ICO_MODN);
				RING_STATE_PRINTTWORULES(RING_RULE_TERMISRANGE,RING_RULE_MOD) ;
			}
			else if ( ring_parser_isoperator2(pParser,OP_POW) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_range(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_POW,ICO_POWN);
				RING_STATE_PRINTTWORULES(RING_RULE_TERMISRANGE,RING_RULE_POW) ;
			}
			else {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_range(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_math(pParser,ICO_DIV,ICO_DIVN);
				RING_STATE_PRINTTWORULES(RING_RULE_TERMISRANGE,RING_RULE_DIV) ;
			}
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_range ( Parser *pParser )
{
	int x,nFlag  ;
	/* Range --> Factor : Factor */
	if ( ring_parser_factor(pParser,&nFlag) ) {
		x = 1 ;
		/* Print Rules */
		if ( nFlag ) {
			RING_STATE_PRINTRULE(RING_RULE_FACTORISIDENTIFIER) ;
		}
		RING_STATE_PRINTRULE(RING_RULE_RANGEISFACTOR) ;
		if ( ring_parser_isoperator2(pParser,OP_RANGE) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			x = ring_parser_factor(pParser,&nFlag);
			if ( x == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_RANGE);
			if ( nFlag ) {
				RING_STATE_PRINTRULE(RING_RULE_FACTORISIDENTIFIER) ;
			}
			RING_STATE_PRINTTWORULES(RING_RULE_RANGEISFACTOR,RING_RULE_RANGE) ;
		}
		return x ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_factor ( Parser *pParser,int *nFlag )
{
	int x,x2,x3,nLastOperation,nCount,nNOOP,nToken,nMark,nFlag2,lThisOrSelfLoadA,lThisLoadA,lNewFrom,lAfterListEnd  ;
	List *pLoadAPos, *pLoadAMark,*pList, *pMark,*pAssignmentPointerPos  ;
	char lSetProperty,lequal,nBeforeEqual,lNewAfterEqual  ;
	char cFuncName[RING_MEDIUMBUF]  ;
	char cKeyword[RING_MEDIUMBUF]  ;
	/* Set Identifier Flag - is 1 when we have Factor -->Identifier */
	*nFlag = 0 ;
	pAssignmentPointerPos = NULL ;
	/* Factor --> Identifier  {mixer} [ '=' Expr ] */
	if ( ring_parser_isidentifier(pParser) ) {
		/* Generate Code */
		ring_parser_icg_loadaddress(pParser,pParser->cTokenText);
		/* Check Loading Self or This */
		pParser->lThisLoadA = 0 ;
		if ( strcmp(pParser->cTokenText ,RING_CSTR_THIS) == 0 ) {
			pParser->lThisLoadA = 1 ;
		}
		pParser->lThisOrSelfLoadA = 0 ;
		if ( strcmp(pParser->cTokenText,RING_CSTR_SELF) == 0 || pParser->lThisLoadA ) {
			pParser->lThisOrSelfLoadA = 1 ;
		}
		ring_parser_nexttoken(pParser);
		/* Set Identifier Flag */
		*nFlag = 1 ;
		nToken = RING_PARSER_CURRENTTOKEN ;
		RING_PARSER_PASSNEWLINE ;
		/* Back if we don't have { */
		if ( (RING_PARSER_CURRENTTOKEN > nToken ) ) {
			if ( ! ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
				ring_parser_settoken(pParser,nToken);
			}
		}
		/* Array Index & Object Dot */
		x = ring_parser_mixer(pParser);
		if ( x == RING_PARSER_FAIL ) {
			return RING_PARSER_FAIL ;
		}
		/*
		**  [ [ = Expr  ] 
		**  Save State before changes by Check Operator 
		*/
		nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
		pLoadAMark = ring_parser_icg_getactiveoperation(pParser) ;
		/* Check Operator */
		lequal = 1 ;
		if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
			nBeforeEqual = OP_EQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_PLUSEQUAL) ) {
			nBeforeEqual = OP_PLUSEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_MINUSEQUAL) ) {
			nBeforeEqual = OP_MINUSEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_MULEQUAL) ) {
			nBeforeEqual = OP_MULEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_DIVEQUAL) ) {
			nBeforeEqual = OP_DIVEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_MODEQUAL) ) {
			nBeforeEqual = OP_MODEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_BITANDEQUAL) ) {
			nBeforeEqual = OP_BITANDEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_BITOREQUAL) ) {
			nBeforeEqual = OP_BITOREQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_BITXOREQUAL) ) {
			nBeforeEqual = OP_BITXOREQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_SHLEQUAL) ) {
			nBeforeEqual = OP_SHLEQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_SHREQUAL) ) {
			nBeforeEqual = OP_SHREQUAL ;
		}
		else if ( ring_parser_isoperator2(pParser,OP_POWEQUAL) ) {
			nBeforeEqual = OP_POWEQUAL ;
		}
		else {
			lequal = 0 ;
			nBeforeEqual = OP_EQUAL ;
		}
		if ( (lequal == 1 ) && (pParser->lAssignmentFlag == 1) ) {
			ring_parser_nexttoken(pParser);
			/* Check if the Assignment after object attribute name */
			lThisOrSelfLoadA = pParser->lThisOrSelfLoadA ;
			lThisLoadA = pParser->lThisLoadA ;
			pLoadAPos = NULL ;
			if ( nLastOperation == ICO_LOADSUBADDRESS ) {
				lSetProperty = 1 ;
			}
			else {
				lSetProperty = 0 ;
				/* When the assignment is after LoadAddress */
				if ( nLastOperation == ICO_LOADADDRESS ) {
					pLoadAPos = pLoadAMark ;
				}
			}
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
			ring_parser_icg_newoperandint(pParser,RING_FALSE);
			pAssignmentPointerPos = ring_parser_icg_getactiveoperation(pParser) ;
			RING_PARSER_IGNORENEWLINE ;
			pParser->lNewObject = 0 ;
			pParser->lAssignmentFlag = 0 ;
			lNewAfterEqual = ring_parser_iskeyword(pParser,K_NEW) ;
			x = ring_parser_expr(pParser);
			pParser->lAssignmentFlag = 1 ;
			/* Check New Object and this.property or self.property to disable set property */
			if ( pParser->lNewObject && lSetProperty ) {
				if ( lThisLoadA || ( lThisOrSelfLoadA && (pParser->nBracesCounter == 0) ) ) {
					lSetProperty = 0 ;
				}
			}
			if ( x == RING_PARSER_OK ) {
				RING_STATE_PRINTRULE(RING_RULE_ASSIGNMENT) ;
			}
			/* Generate Code */
			if ( pParser->lNewObject==0 ) {
				/*
				**  We don't need assignment after ListEnd, because lists directly stored in the Variable 
				**  We do this when we are not inside Brace 
				*/
				nNOOP = 0 ;
				lAfterListEnd = (ring_parser_icg_getlastoperation(pParser) == ICO_NEWLINE) && ring_parser_icg_getoperationbeforelastoperation(pParser) == ICO_LISTEND ;
				lAfterListEnd = lAfterListEnd || (ring_parser_icg_getlastoperation(pParser) == ICO_LISTEND) ;
				if ( lAfterListEnd && (pParser->nBracesCounter == 0) ) {
					if ( (lSetProperty == 0) || pParser->lThisOrSelfLoadA ) {
						return x ;
					}
					/* Disable Assignment Pointer */
					ring_parser_icg_setoperandint(pParser,pAssignmentPointerPos,RING_PARSER_ICG_ASSIGNPTRENABLEPOS,RING_TRUE);
				}
				else if ( lAfterListEnd && (pParser->nBracesCounter >= 1) ) {
					nNOOP = 1 ;
					/*
					**  No Assignment is required but we add ICO_NOOP instead 
					**  ICO_NOOP can be converted to Set Property when we access object attributes inside {} 
					*/
					if ( lSetProperty == 1 ) {
						/* Disable Assignment Pointer */
						ring_parser_icg_setoperandint(pParser,pAssignmentPointerPos,RING_PARSER_ICG_ASSIGNPTRENABLEPOS,RING_TRUE);
					}
				}
				/*
				**  Before Equal 
				**  Generate Code 
				*/
				ring_parser_icg_beforeequal(pParser,nBeforeEqual);
				if ( lSetProperty == 0 ) {
					if ( nNOOP == 0 ) {
						ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
					}
					else {
						ring_parser_icg_newoperation(pParser,ICO_NOOP);
					}
				}
				else {
					ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
				}
				/* Add Assignment position to the LoadAddress Instruction */
				if ( pAssignmentPointerPos != NULL ) {
					ring_parser_icg_addoperandint(pParser,pAssignmentPointerPos,ring_parser_icg_instructionscount(pParser));
				}
			}
			else {
				/* In this case we have (New Object) */
				pParser->lNewObject = 0 ;
				/*
				**  Before Equal 
				**  Generate Code 
				*/
				ring_parser_icg_beforeequal(pParser,nBeforeEqual);
				if ( lSetProperty == 0 ) {
					ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
					if ( ! lNewAfterEqual ) {
						/* Disable Assignment Pointer */
						ring_parser_icg_setoperandint(pParser,pAssignmentPointerPos,RING_PARSER_ICG_ASSIGNPTRENABLEPOS,RING_TRUE);
					}
				}
				else {
					ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
					/* Disable Assignment Pointer */
					ring_parser_icg_setoperandint(pParser,pAssignmentPointerPos,RING_PARSER_ICG_ASSIGNPTRENABLEPOS,RING_TRUE);
				}
				/* Add Assignment position to the LoadAddress Instruction */
				if ( pAssignmentPointerPos != NULL ) {
					ring_parser_icg_addoperandint(pParser,pAssignmentPointerPos,ring_parser_icg_instructionscount(pParser));
				}
			}
			return x ;
		}
		/* ++ & -- */
		if ( ring_parser_ppmm(pParser) ) {
			return RING_PARSER_OK ;
		}
		/* Generate Code */
		if ( (ring_parser_icg_getlastoperation(pParser) != ICO_CALL) && (ring_parser_icg_getlastoperation(pParser) != ICO_BRACEEND) ) {
			ring_parser_icg_newoperation(pParser,ICO_PUSHV);
		}
		return RING_PARSER_OK ;
	}
	/* Factor --> Number */
	if ( ring_parser_isnumber(pParser) ) {
		/* Generate Code */
		if ( strlen(pParser->cTokenText) <= RING_PARSER_NUMBERLENGTH ) {
			ring_parser_icg_pushn(pParser,atof(pParser->cTokenText));
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_NUMERICOVERFLOW);
			ring_parser_nexttoken(pParser);
			return RING_PARSER_FAIL ;
		}
		RING_STATE_PRINTRULE(RING_RULE_FACTORISNUMBER) ;
		ring_parser_nexttoken(pParser);
		/* If we have condition - pass new lines */
		if ( pParser->lControlStructureExpr ) {
			RING_PARSER_IGNORENEWLINE ;
		}
		/* ++ and -- */
		if ( ring_parser_ppmm(pParser) ) {
			return RING_PARSER_OK ;
		}
		/* Check using '(' after number */
		if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
			ring_parser_error(pParser,RING_PARSER_ERROR_USINGBRACTAFTERNUM);
			return RING_PARSER_FAIL ;
		}
		return RING_PARSER_OK ;
	}
	/* Factor --> Literal */
	if ( ring_parser_isliteral(pParser) ) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_PUSHC);
		ring_parser_icg_newoperand(pParser,pParser->cTokenText);
		RING_STATE_PRINTRULE(RING_RULE_FACTORISLITERAL) ;
		ring_parser_nexttoken(pParser);
		/* If we have condition - pass new lines */
		if ( pParser->lControlStructureExpr ) {
			RING_PARSER_IGNORENEWLINE ;
		}
		return RING_PARSER_OK ;
	}
	/* Factor --> Literal --> ':' Identifier */
	if ( ring_parser_isoperator2(pParser,OP_RANGE) ) {
		ring_parser_nexttoken(pParser);
		if ( ring_parser_isidentifier(pParser) || ring_parser_isanykeyword(pParser) || ring_parser_isnumber(pParser) ) {
			nCount = ring_parser_icg_instructionslistsize(pParser);
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_PUSHC);
			if ( ring_parser_isanykeyword(pParser) ) {
				strcpy(cKeyword,ring_scanner_getkeywordtext(pParser->cTokenText));
				ring_string_lower(cKeyword);
				ring_parser_icg_newoperand(pParser,cKeyword);
			}
			else {
				ring_parser_icg_newoperand(pParser,pParser->cTokenText);
			}
			RING_STATE_PRINTTWORULES(RING_RULE_HASHLIST,RING_RULE_FACTORISLITERAL) ;
			ring_parser_nexttoken(pParser);
			/* Hash --> '=' Expression */
			if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				ring_parser_icg_listitem(pParser);
				ring_parser_icg_insertoperation(pParser,nCount,ICO_LISTSTART);
				/* Go to last operation, because insert change the active operation */
				RING_PARSER_ICG_GOTOLASTOP ;
				if ( ring_parser_expr(pParser) ) {
					/* Generate Code */
					ring_parser_icg_listitem(pParser);
					ring_parser_icg_newoperation(pParser, ICO_LISTEND);
					return RING_PARSER_OK ;
				}
				return RING_PARSER_FAIL ;
			}
			return RING_PARSER_OK ;
		}
	}
	/* Factor --> Negative (-) Factor */
	if ( ring_parser_isoperator2(pParser,OP_MINUS) ) {
		ring_parser_nexttoken(pParser);
		x = ring_parser_factor(pParser,&nFlag2);
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_NEG);
		RING_STATE_PRINTRULE(RING_RULE_NEGATIVE) ;
		return x ;
	}
	else if ( ring_parser_isoperator2(pParser,OP_BITNOT) ) {
		/* bitnot (~) Expr */
		ring_parser_nexttoken(pParser);
		x = ring_parser_expr(pParser);
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_BITNOT);
		RING_STATE_PRINTRULE(RING_RULE_BITNOT) ;
		return x ;
	}
	/* Factor --> & */
	else if ( ring_parser_isoperator2(pParser,OP_BITAND) ) {
		ring_parser_nexttoken(pParser);
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_RETITEMREF);
		if ( ring_parser_expr(pParser) ) {
			return RING_PARSER_OK ;
		}
	}
	/* Factor --> ( Expr ) */
	if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
		ring_parser_nexttoken(pParser);
		if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			RING_STATE_PRINTRULE(RING_RULE_FACTORISEMPTYGROUP) ;
			return RING_PARSER_OK ;
		}
		x = pParser->lAssignmentFlag ;
		pParser->lAssignmentFlag = 0 ;
		if ( ring_parser_expr(pParser) ) {
			pParser->lAssignmentFlag = x ;
			if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				RING_STATE_PRINTRULE(RING_RULE_FACTORISGROUP) ;
				/* '(' Expression ')' then Dot Operator to access an object */
				if ( ring_parser_isoperator2(pParser,OP_DOT) || ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
					/* Remove PUSHV */
					if ( ring_parser_icg_getlastoperation(pParser)  == ICO_PUSHV ) {
						ring_parser_icg_deletelastoperation(pParser);
					}
					x = ring_parser_mixer(pParser);
					if ( x == RING_PARSER_FAIL ) {
						return RING_PARSER_FAIL ;
					}
					/* Add PUSHV */
					ring_parser_icg_newoperation(pParser,ICO_PUSHV);
				}
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_MISSPARENTHESES);
				return RING_PARSER_FAIL ;
			}
		}
		return RING_PARSER_FAIL ;
	}
	/* Factor --> List */
	if ( ring_parser_isoperator2(pParser,OP_LOPEN) ) {
		x = ring_parser_list(pParser) ;
		RING_STATE_PRINTRULE(RING_RULE_FACTORISLIST) ;
		return x ;
	}
	/* Factor --> New Identifier */
	if ( ring_parser_iskeyword(pParser,K_NEW) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/* Check creating new object from variable */
		lNewFrom = 0 ;
		if ( ring_parser_iskeyword(pParser,K_FROM) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			lNewFrom = 1 ;
		}
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_NEWOBJ);
		RING_STATE_PRINTRULE(RING_RULE_NEWOBJECT) ;
		if ( ring_parser_namedotname(pParser) ) {
			/* Generate Code */
			ring_parser_icg_newoperandint(pParser,lNewFrom);
			ring_parser_icg_newoperation(pParser,ICO_SETSCOPE);
			RING_PARSER_IGNORENEWLINE ;
			if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
				x = ring_parser_mixer(pParser);
				pParser->lNewObject = 1 ;
				return x ;
			}
			else if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
				/*
				**  Calling the init method using { } 
				**  Generate Code (Start Brace) 
				*/
				ring_parser_icg_newoperation(pParser,ICO_PUSHV);
				ring_parser_icg_newoperation(pParser,ICO_BRACESTART);
				ring_parser_icg_newoperation(pParser,ICO_CALLCLASSINIT);
				ring_parser_icg_newoperandint(pParser,RING_TRUE);
				/* Generate Code ( Call Function ) */
				ring_parser_icg_loadaddress(pParser,RING_CSTR_INIT);
				/* Function Parameters */
				pParser->lFuncCallOnly = 1 ;
				ring_parser_mixer(pParser);
				pParser->lFuncCallOnly = 0 ;
				/* Generate Code (End Brace) */
				ring_parser_icg_newoperation(pParser,ICO_CALLCLASSINIT);
				ring_parser_icg_newoperandint(pParser,RING_ZERO);
				RING_PARSER_IGNORENEWLINE ;
				x = ring_parser_mixer(pParser);
				ring_parser_icg_newoperation(pParser,ICO_BRACEEND);
				pParser->lNewObject = 1 ;
				return x ;
			}
			pParser->lNewObject = 1 ;
			return RING_PARSER_OK ;
		}
	}
	/* Factor --> Anonymous Function */
	if ( ring_parser_iskeyword(pParser,K_FUNC) || ring_parser_iskeyword(pParser,K_FUNCTION) || ring_parser_iskeyword(pParser,K_DEF) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_PASSNEWLINE ;
		/*
		**  Generate Code 
		**  Push Function Name, then jump after the function code 
		*/
		ring_parser_icg_newoperation(pParser,ICO_PUSHC);
		/* Note : the function name must be in lower case */
		sprintf( cFuncName , "%s%d" , RING_CSTR_ANONFUNC,RING_PARSER_OPERATIONID ) ;
		ring_parser_icg_newoperand(pParser,cFuncName);
		ring_parser_icg_newoperation(pParser,ICO_JUMP);
		pMark = ring_parser_icg_getactiveoperation(pParser);
		/* Define the Function - as public (not related to any class) */
		pList = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingFunctionsMap);
		ring_list_addstring_gc(pParser->pRingState,pList,cFuncName);
		/* Note +1 because instruction ICO_NEWFUNC will come next */
		ring_list_addint_gc(pParser->pRingState,pList,RING_PARSER_OPERATIONID+1);
		ring_list_addstring_gc(pParser->pRingState,pList,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
		ring_list_addint_gc(pParser->pRingState,pList,RING_FALSE);
		ring_parser_icg_newoperation(pParser,ICO_NEWFUNC);
		/* Get Function Parameters */
		if ( ring_parser_isidentifier(pParser) || ring_parser_isoperator2(pParser,OP_FOPEN) ) {
			if (! ring_parser_paralist(pParser)) return RING_PARSER_FAIL ;
		}
		RING_PARSER_PASSNEWLINE ;
		/* Get Function Code */
		if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
			ring_parser_nexttoken(pParser);
			x = pParser->lAssignmentFlag ;
			x2 = pParser->lNewObject ;
			x3 = pParser->nBracesCounter ;
			pParser->lAssignmentFlag = 1 ;
			pParser->nBracesCounter = 0 ;
			RING_PARSER_ACCEPTSTATEMENTS ;
			pParser->lAssignmentFlag = x ;
			pParser->lNewObject = x2 ;
			pParser->nBracesCounter = x3 ;
			if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				ring_parser_icg_retnull(pParser);
				nMark = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark);
				RING_STATE_PRINTRULE(RING_RULE_ANONFUNC) ;
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_BRACESNOTCLOSED);
				return RING_PARSER_FAIL ;
			}
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_BRACEISMISSINGTOSTARTANONFUNC);
			return RING_PARSER_FAIL ;
		}
	}
	/* Factor --> Call Identifier ( parameters ) */
	if ( ring_parser_iskeyword(pParser,K_CALL) ) {
		ring_parser_nexttoken(pParser);
		if ( ring_parser_isidentifier(pParser) ) {
			/* Generate Code */
			ring_parser_icg_loadaddress(pParser,pParser->cTokenText);
			ring_parser_nexttoken(pParser);
			/* Object Attributes */
			if ( ring_parser_objattributes(pParser) == 0 ) {
				return RING_PARSER_FAIL ;
			}
			ring_parser_icg_newoperation(pParser,ICO_PUSHV);
			ring_parser_icg_newoperation(pParser,ICO_ANONYMOUS);
			if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
				if ( ! ring_parser_mixer(pParser) ) {
					ring_parser_error(pParser,RING_PARSER_ERROR_SYNTAXERROR);
					return RING_PARSER_FAIL ;
				}
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_EXPECTPARENTHESES);
				return RING_PARSER_FAIL ;
			}
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_VARNAME);
			return RING_PARSER_FAIL ;
		}
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_mixer ( Parser *pParser )
{
	int x,nCallMethod,nStatus,nFlag,nNew  ;
	/*
	**  { . Identifier } 
	**  Object Attributes 
	*/
	if ( ring_parser_objattributes(pParser) == 0 ) {
		return RING_PARSER_FAIL ;
	}
	/* [Index]  to access array element, Index = Expression */
	if ( ring_parser_isoperator2(pParser,OP_LOPEN) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_expr(pParser) ) {
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_LOADINDEXADDRESS);
			if ( ring_parser_isoperator2(pParser,OP_LCLOSE) ) {
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				RING_STATE_PRINTRULE(RING_RULE_MIXERISLIST) ;
				x = ring_parser_mixer(pParser);
				if ( x == RING_PARSER_FAIL ) {
					return RING_PARSER_FAIL ;
				}
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_MISSBRACKETS);
				return RING_PARSER_FAIL ;
			}
		}
		else {
			return RING_PARSER_FAIL ;
		}
	}
	/* |  [ ( [ Expr { , Expr } ] ) ]  ] */
	if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
		/* Generate Code */
		nCallMethod = 0 ;
		if ( ring_parser_icg_getlastoperation(pParser) == ICO_LOADADDRESS ) {
			ring_parser_icg_loadaddresstoloadfunction(pParser);
		}
		else if ( ring_parser_icg_getlastoperation(pParser) == ICO_LOADSUBADDRESS ) {
			ring_parser_icg_setlastoperation(pParser,ICO_LOADMETHOD);
			/* Delete Locations for Setter/Getter */
			ring_parser_icg_deleteoperand(pParser,RING_PARSER_ICG_LOADASETTERPOS);
			nCallMethod = 1 ;
		}
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
			ring_parser_nexttoken(pParser);
			/* Generate Code */
			ring_parser_icg_gencall(pParser,nCallMethod);
			RING_STATE_PRINTRULE(RING_RULE_MIXERISGROUP) ;
			RING_PARSER_IGNORENEWLINE ;
			x = ring_parser_mixer(pParser);
			return x ;
		}
		while ( 1 ) {
			nFlag = pParser->lAssignmentFlag ;
			nNew = pParser->lNewObject ;
			pParser->lAssignmentFlag = 0 ;
			if ( ring_parser_expr(pParser) ) {
				pParser->lAssignmentFlag = nFlag ;
				pParser->lNewObject = nNew ;
				RING_PARSER_IGNORENEWLINE ;
				if ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
					ring_parser_nexttoken(pParser);
				}
				else if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
					RING_STATE_PRINTRULE(RING_RULE_MIXERISGROUP) ;
					ring_parser_nexttoken(pParser);
					/* Generate Code */
					ring_parser_icg_gencall(pParser,nCallMethod);
					RING_PARSER_IGNORENEWLINE ;
					x = ring_parser_mixer(pParser);
					return x ;
				}
				else {
					ring_parser_error(pParser,RING_PARSER_ERROR_MISSPARENTHESES);
					return RING_PARSER_FAIL ;
				}
			}
			else {
				return RING_PARSER_FAIL ;
			}
			RING_PARSER_IGNORENEWLINE ;
		}
	}
	/* Function Call Only */
	if ( pParser->lFuncCallOnly == 1 ) {
		return RING_PARSER_OK ;
	}
	/* '{' {Statement} '}' */
	if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) && pParser->lControlStructureExpr == 0 ) {
		pParser->nBracesCounter++ ;
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_PUSHV);
		ring_parser_icg_newoperation(pParser,ICO_BRACESTART);
		RING_STATE_PRINTRULE(RING_RULE_MIXERISBRACES) ;
		/* if ismethod(self,"bracestart") bracestart() ok */
		ring_parser_icg_gencallbracemethod(pParser,RING_CSTR_BRACESTART,RING_FALSE);
		ring_parser_nexttoken(pParser);
		nStatus = pParser->lAssignmentFlag ;
		pParser->lAssignmentFlag = 1 ;
		RING_PARSER_ACCEPTSTATEMENTS ;
		pParser->lAssignmentFlag = nStatus ;
		if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
			pParser->nBracesCounter-- ;
			/*
			**  Generate Code 
			**  if ismethod(self,"braceend") braceend() ok 
			*/
			ring_parser_icg_gencallbracemethod(pParser,RING_CSTR_BRACEEND,RING_FALSE);
			ring_parser_icg_newoperation(pParser,ICO_BRACEEND);
			RING_STATE_PRINTRULE(RING_RULE_BRACEEND) ;
			ring_parser_nexttoken(pParser);
			x = ring_parser_mixer(pParser);
			return x ;
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_BRACESNOTCLOSED);
		}
	}
	/* This function return RING_PARSER_OK because the mixer is optional and comes after identifier */
	return RING_PARSER_OK ;
}

int ring_parser_ppmm ( Parser *pParser )
{
	int nLastOperation,nMode,nValue  ;
	nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
	/* ++ & -- */
	if ( ring_parser_isoperator2(pParser,OP_INC) ) {
		nMode = RING_PARSER_ICG_NORMALPP ;
		nValue = 1.0 ;
	}
	else if ( ring_parser_isoperator2(pParser,OP_DEC) ) {
		nMode = RING_PARSER_ICG_NORMALMM ;
		nValue = -1.0 ;
	}
	else {
		return RING_PARSER_FAIL ;
	}
	ring_parser_nexttoken(pParser);
	/* Code Generation */
	switch ( nLastOperation ) {
		case ICO_LOADADDRESS :
			if ( pParser->nBracesCounter ) {
				nMode = RING_PARSER_ICG_USEASSIGNMENT ;
			}
			break ;
		case ICO_LOADSUBADDRESS :
			nMode = RING_PARSER_ICG_USESETPROPERTY ;
			break ;
	}
	ring_parser_icg_genppmm(pParser,nMode,nValue);
	return RING_PARSER_OK ;
}

int ring_parser_objattributes ( Parser *pParser )
{
	/* { . Identifier } */
	while ( ring_parser_isoperator2(pParser,OP_DOT) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/* we support literal to be able to call methods contains operators in the name */
		if ( ring_parser_isidentifier(pParser) || ring_parser_isliteral(pParser) ) {
			/* Prevent Accessing the self reference from outside the object */
			if ( strcmp(pParser->cTokenText,RING_CSTR_SELF) == 0 ) {
				ring_parser_error(pParser,RING_PARSER_ERROR_ACCESSSELFREF);
				return RING_PARSER_FAIL ;
			}
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_LOADSUBADDRESS);
			ring_parser_icg_newoperand(pParser,pParser->cTokenText);
			/* Generate Location for nPC of Getter - When we access object attribute using { } */
			ring_parser_icg_newoperandint(pParser,RING_ZERO);
			RING_STATE_PRINTRULE(RING_RULE_MIXERISDOT) ;
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
		}
		else {
			return RING_PARSER_FAIL ;
		}
	}
	return RING_PARSER_OK ;
}
