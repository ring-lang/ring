/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Remember, When we read from the stack LIFO 
**  If we have two parameters, we read the second parameter first 
*/
#include "ring.h"
/* Math */

void ring_vm_sum ( VM *pVM )
{
	String *cStr1,*cStr2  ;
	double nNum1,nNum2  ;
	char cStr3[100]  ;
	/*
	**  Description 
	**  We can sum string + number ---> string , number + string ---> number 
	**  string/number + nl ---> string 
	**  list + string/number ---> add item to the list 
	**  list1 + list2 ---> add list2 items to list 1 
	*/
	if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			cStr2 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
			ring_string_add2_gc(pVM->pRingState,cStr2,ring_string_get(cStr1),ring_string_size(cStr1));
			RING_VM_STACK_SETCVALUE2(ring_string_get(cStr2),ring_string_size(cStr2));
			ring_string_delete_gc(pVM->pRingState,cStr2);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
			if ( strcmp(ring_string_get(cStr1),"\n") == 0 ) {
				cStr2 = ring_string_new_gc(pVM->pRingState,"") ;
				ring_string_add_gc(pVM->pRingState,cStr2,ring_vm_numtostring(pVM,nNum2,cStr3));
				ring_string_add_gc(pVM->pRingState,cStr2,ring_string_get(cStr1));
				RING_VM_STACK_SETCVALUE(ring_string_get(cStr2));
				ring_string_delete_gc(pVM->pRingState,cStr2);
			} else {
				RING_VM_STACK_SETNVALUE(nNum2 + ring_vm_stringtonum(pVM,ring_string_get(cStr1)));
			}
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"+",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
			RING_VM_STACK_SETNVALUE(nNum1+nNum2);
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			cStr2 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC) ;
			ring_vm_numtostring(pVM,nNum1,cStr3);
			ring_string_add_gc(pVM->pRingState,cStr2,cStr3);
			RING_VM_STACK_SETCVALUE(ring_string_get(cStr2));
			ring_string_delete_gc(pVM->pRingState,cStr2);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"+",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"+");
		return ;
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
}

void ring_vm_sub ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"-",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"-",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"-");
		return ;
	}
	RING_VM_STACK_SETNVALUE(nNum2-nNum1);
}

void ring_vm_mul ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	char cStr2[100]  ;
	char cStr3[100]  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"*",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"*",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"*");
		return ;
	}
	/* Check Overflow */
	if ( ( strlen(ring_vm_numtostring(pVM,nNum1,cStr2)) >= 15 ) || (strlen(ring_vm_numtostring(pVM,nNum2,cStr3)) >= 15 ) ) {
		ring_vm_error(pVM,RING_VM_ERROR_NUMERICOVERFLOW);
		return ;
	}
	RING_VM_STACK_SETNVALUE(nNum1*nNum2);
}

void ring_vm_div ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	char cStr2[100]  ;
	char cStr3[100]  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( nNum1 == 0 ) {
			ring_vm_error(pVM,RING_VM_ERROR_DIVIDEBYZERO);
			return ;
		}
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"/",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"/",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"/");
		return ;
	}
	/* Check Overflow */
	if ( ( strlen(ring_vm_numtostring(pVM,nNum1,cStr2)) >= 15 ) || (strlen(ring_vm_numtostring(pVM,nNum2,cStr3)) >= 15 ) ) {
		ring_vm_error(pVM,RING_VM_ERROR_NUMERICOVERFLOW);
		return ;
	}
	RING_VM_STACK_SETNVALUE(nNum2/nNum1);
}

void ring_vm_mod ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	char cStr2[100]  ;
	char cStr3[100]  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( nNum1 == 0 ) {
			ring_vm_error(pVM,RING_VM_ERROR_DIVIDEBYZERO);
			return ;
		}
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"%",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE) ;
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"%",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"%");
		return ;
	}
	/* Check Overflow */
	if ( ( strlen(ring_vm_numtostring(pVM,nNum1,cStr2)) >= 15 ) || (strlen(ring_vm_numtostring(pVM,nNum2,cStr3)) >= 15 ) ) {
		ring_vm_error(pVM,RING_VM_ERROR_NUMERICOVERFLOW);
		return ;
	}
	RING_VM_STACK_SETNVALUE(fmod(nNum2 , nNum1));
}

void ring_vm_neg ( VM *pVM )
{
	double nNum1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE((RING_VM_STACK_READN)*(-1));
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_SETNVALUE((nNum1)*(-1));
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_npoo(pVM,"neg",0);
	}
}
/*
**  compare 
**  Here the conversion to string/number before comparing is not important 
**  Because the result is always logical (True/False) i.e. 1 or 0 
*/

void ring_vm_equal ( VM *pVM )
{
	String *cStr1,*cStr2  ;
	double nNum1,nNum2  ;
	char cStr3[100]  ;
	if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			cStr2 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
			if ( strcmp(ring_string_get(cStr1),ring_string_get(cStr2)) == 0 ) {
				RING_VM_STACK_TRUE ;
			} else {
				RING_VM_STACK_FALSE ;
			}
			ring_string_delete_gc(pVM->pRingState,cStr2);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum1 = RING_VM_STACK_READN ;
			ring_vm_numtostring(pVM,nNum1,cStr3);
			if ( strcmp(ring_string_get(cStr1),cStr3) == 0 ) {
				RING_VM_STACK_TRUE ;
			} else {
				RING_VM_STACK_FALSE ;
			}
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"=",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
			if ( nNum1 == nNum2 ) {
				RING_VM_STACK_TRUE ;
			} else {
				RING_VM_STACK_FALSE ;
			}
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			if ( ring_vm_stringtonum(pVM,RING_VM_STACK_READC) == nNum1 ) {
				RING_VM_STACK_TRUE ;
			} else {
				RING_VM_STACK_FALSE ;
			}
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"=",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"=");
	}
}

void ring_vm_lessequal ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"<=",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"<=",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"<=");
		return ;
	}
	/* Compare */
	if ( nNum2 <= nNum1 ) {
		RING_VM_STACK_TRUE ;
	} else {
		RING_VM_STACK_FALSE ;
	}
}

void ring_vm_less ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"<",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"<",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"<");
		return ;
	}
	/* Compare */
	if ( nNum2 < nNum1 ) {
		RING_VM_STACK_TRUE ;
	} else {
		RING_VM_STACK_FALSE ;
	}
}

void ring_vm_greater ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,">",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,">",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,">");
		return ;
	}
	/* Compare */
	if ( nNum2 > nNum1 ) {
		RING_VM_STACK_TRUE ;
	} else {
		RING_VM_STACK_FALSE ;
	}
}

void ring_vm_greaterequal ( VM *pVM )
{
	double nNum1=0,nNum2=0  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,">=",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,">=",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,">=");
		return ;
	}
	/* Compare */
	if ( nNum2 >= nNum1 ) {
		RING_VM_STACK_TRUE ;
	} else {
		RING_VM_STACK_FALSE ;
	}
}

void ring_vm_notequal ( VM *pVM )
{
	String *cStr1,*cStr2  ;
	double nNum1,nNum2  ;
	char cStr3[100]  ;
	if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISSTRING ) {
			cStr2 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
			/* Compare */
			if ( strcmp(ring_string_get(cStr1),ring_string_get(cStr2)) == 0 ) {
				RING_VM_STACK_FALSE ;
			} else {
				RING_VM_STACK_TRUE ;
			}
			ring_string_delete_gc(pVM->pRingState,cStr2);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
			nNum1 = ring_vm_stringtonum(pVM,ring_string_get(cStr1)) ;
			/* Compare */
			if ( nNum1 == nNum2 ) {
				RING_VM_STACK_FALSE ;
			} else {
				RING_VM_STACK_TRUE ;
			}
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"!=",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			nNum2 = RING_VM_STACK_READN ;
			/* Compare */
			if ( nNum1 == nNum2 ) {
				RING_VM_STACK_FALSE ;
			} else {
				RING_VM_STACK_TRUE ;
			}
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			cStr2 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
			ring_vm_numtostring(pVM,nNum1,cStr3);
			/* Compare */
			if ( strcmp(ring_string_get(cStr2),cStr3) == 0 ) {
				RING_VM_STACK_FALSE ;
			} else {
				RING_VM_STACK_TRUE ;
			}
			ring_string_delete_gc(pVM->pRingState,cStr2);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"!=",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"!=");
		return ;
	}
}
/* Logic */

void ring_vm_and ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE((nNum1 && (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 && nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"and",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE((nNum1 && (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 && nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"and",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"and");
	}
}

void ring_vm_or ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE((nNum1 || (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 || nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"or",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE((nNum1 || (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 || nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"or",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"or");
	}
}

void ring_vm_not ( VM *pVM )
{
	double nNum1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN != 0 ) {
			RING_VM_STACK_SETNVALUE(0.0);
		} else {
			RING_VM_STACK_SETNVALUE(1.0);
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		if ( nNum1 == 1.0 ) {
			RING_VM_STACK_SETNVALUE(0.0);
		} else {
			RING_VM_STACK_SETNVALUE(1.0);
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_npoo(pVM,"not",0);
		return ;
	}
}
/* Bitwise */

void ring_vm_bitand ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE((int) nNum1 &  (int) (RING_VM_STACK_READN));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 & (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"&",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(((int) nNum1 & (int) (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 & (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"&",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"&");
	}
}

void ring_vm_bitor ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(((int) nNum1 | (int) (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 | (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"|",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(((int) nNum1 | (int) (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 | (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"|",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"|");
	}
}

void ring_vm_bitshl ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(( (int) (RING_VM_STACK_READN) << (int) nNum1 ));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum2 << (int) nNum1));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"<<",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(( (int) (RING_VM_STACK_READN) << (int) nNum1 ));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum2 << (int) nNum1));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"<<",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"<<");
	}
}

void ring_vm_bitshr ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(( (int) (RING_VM_STACK_READN) >> (int) nNum1 ));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum2 >> (int) nNum1));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,">>",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(( (int) (RING_VM_STACK_READN) >> (int) nNum1 ));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum2 >> (int) nNum1));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,">>",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,">>");
	}
}

void ring_vm_bitxor ( VM *pVM )
{
	double nNum1,nNum2  ;
	String *cStr1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(((int) nNum1 ^ (int) (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 ^ (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_npoo(pVM,"^",nNum1);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISNUMBER ) {
			RING_VM_STACK_SETNVALUE(((int) nNum1 ^ (int) (RING_VM_STACK_READN)));
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			nNum2 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE(((int) nNum1 ^ (int) nNum2));
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_expr_spoo(pVM,"^",ring_string_get(cStr1),ring_string_size(cStr1));
			ring_string_delete_gc(pVM->pRingState,cStr1);
			return ;
		}
		ring_string_delete_gc(pVM->pRingState,cStr1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_ppoo(pVM,"^");
	}
}

void ring_vm_bitnot ( VM *pVM )
{
	double nNum1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE(~ (int) RING_VM_STACK_READN);
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_SETNVALUE(~ (int) nNum1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		ring_vm_expr_npoo(pVM,"~",0);
		return ;
	}
}
/* Conversion */

char * ring_vm_numtostring ( VM *pVM,double nNum1,char *cStr )
{
	char cOptions[10]  ;
	if ( nNum1 == (int) nNum1 ) {
		sprintf( cStr , "%.0f" , nNum1 ) ;
	}
	else {
		sprintf( cOptions , "%s%df" , "%.",pVM->nDecimals ) ;
		sprintf( cStr , cOptions , nNum1 ) ;
	}
	return cStr ;
}

double ring_vm_stringtonum ( VM *pVM,const char *cStr )
{
	double nResult  ;
	if ( strlen(cStr) <= 15 ) {
		nResult = atof(cStr);
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_NUMERICOVERFLOW);
		return 0.0 ;
	}
	return nResult ;
}
/*
**  Operator Overloading 
**  Stack Pointer then Stack Pointer - Operator Overloading 
*/

void ring_vm_expr_ppoo ( VM *pVM,const char *cStr )
{
	List *pList,*pList2  ;
	Item *pItem  ;
	void *pPointer  ;
	int nType  ;
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		pList = ring_list_getlist(pList,RING_VAR_VALUE);
	}
	else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
		pItem = (Item *) RING_VM_STACK_READP ;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
	/* Get Pointer Data */
	pPointer = RING_VM_STACK_READP ;
	nType = RING_VM_STACK_OBJTYPE ;
	RING_VM_STACK_POP ;
	if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList2 = (List *) RING_VM_STACK_READP ;
			pList2 = ring_list_getlist(pList2,RING_VAR_VALUE);
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList2 = ring_item_getlist(pItem);
		} else {
			ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
			return ;
		}
		if ( strcmp(cStr,"+") == 0 ) {
			if ( (ring_vm_oop_isobject(pList2) == 0) ) {
				ring_vm_addlisttolist(pVM,pList,pList2);
				return ;
			}
		}
		else if ( strcmp(cStr,"=") == 0 ) {
			if ( ring_vm_api_iscpointerlist(pList) && ring_vm_api_iscpointerlist(pList2) ) {
				RING_VM_STACK_POP ;
				if ( ring_vm_api_cpointercmp(pList,pList2) ) {
					RING_VM_STACK_PUSHNVALUE(1.0) ;
				}
				else {
					RING_VM_STACK_PUSHNVALUE(0) ;
				}
				return ;
			}
		}
		if ( ring_vm_oop_isobject(pList2) == 1 ) {
			/* Operator Overloading */
			ring_vm_oop_operatoroverloading(pVM,pList2,cStr,RING_OOPARA_POINTER,"",0,pPointer,nType);
			RING_VM_STACK_POP ;
		} else {
			ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		}
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
	}
}
/* Stack Number then Stack Pointer - Operator Overloading */

void ring_vm_expr_npoo ( VM *pVM,const char *cStr,double nNum1 )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		pList = ring_list_getlist(pList,RING_VAR_VALUE);
	}
	else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
		pItem = (Item *) RING_VM_STACK_READP ;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
	if ( strcmp(cStr,"+") == 0 ) {
		if ( ring_vm_oop_isobject(pList) == 0 ) {
			ring_list_adddouble_gc(pVM->pRingState,pList,nNum1);
			return ;
		}
	}
	if ( ring_vm_oop_isobject(pList) == 1 ) {
		/* Operator Overloading */
		ring_vm_oop_operatoroverloading(pVM,pList,cStr,RING_OOPARA_NUMBER,"",nNum1,NULL,0);
		RING_VM_STACK_POP ;
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
	}
}
/* Stack String then Stack Pointer - Operator Overloading */

void ring_vm_expr_spoo ( VM *pVM,const char *cStr,const char *cStr2,int nSize )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		pList = ring_list_getlist(pList,RING_VAR_VALUE);
	}
	else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
		pItem = (Item *) RING_VM_STACK_READP ;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
	if ( strcmp(cStr,"+") == 0 ) {
		if ( ring_vm_oop_isobject(pList) == 0 ) {
			ring_list_addstring2_gc(pVM->pRingState,pList,cStr2,nSize);
			return ;
		}
	}
	if ( ring_vm_oop_isobject(pList) == 1 ) {
		/* Operator Overloading */
		ring_vm_oop_operatoroverloading(pVM,pList,cStr,RING_OOPARA_STRING,cStr2,0,NULL,0);
		RING_VM_STACK_POP ;
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
	}
}
/* Add List to List */

void ring_vm_addlisttolist ( VM *pVM,List *pList,List *pList2 )
{
	List *pList3, *pList4  ;
	/*
	**  Here we are going to copy the list pList to the list pList2 
	**  We will copy to a temp list first (pList4) 
	**  So we can add the Self object for example to an attribute in this object 
	*/
	pList4 = ring_list_new_gc(pVM->pRingState,0);
	ring_vm_list_copy(pVM,pList4,pList);
	pList3 = ring_list_newlist_gc(pVM->pRingState,pList2);
	ring_vm_list_copy(pVM,pList3,pList4);
	ring_list_delete_gc(pVM->pRingState,pList4);
	if ( (ring_vm_oop_isobject(pList3) == 1)  && (pVM->pBraceObject == pList) ) {
		pVM->pBraceObject = pList3 ;
		/*
		**  The copied object was created in Temp. memory that will be deleted 
		**  The object contains the self property that contains a pointer to the object in memory 
		**  We need to modify the pointer that point to the old location in Temp. Memory 
		**  The pointer will be changed to point to the new location in the array 
		**  The array maybe global or related to the object state and may stay longer than the Temp. Memory 
		**  Without this modification using self may lead to crash or using corrupted memory 
		*/
		ring_vm_oop_updateselfpointer(pVM,pList3,RING_OBJTYPE_LISTITEM,ring_list_getitem(pList2,ring_list_getsize(pList2)));
	}
	else if ( (ring_vm_oop_isobject(pList3) == 1)  && (pVM->pBraceObject != pList) ) {
		/*
		**  in ring code if we used mylist + new obj() the init method will be called 
		**  the pVM->pBraceObject will not == pList but we have to update the self pointer! 
		*/
		ring_vm_oop_updateselfpointer(pVM,pList3,RING_OBJTYPE_LISTITEM,ring_list_getitem(pList2,ring_list_getsize(pList2)));
	}
}
