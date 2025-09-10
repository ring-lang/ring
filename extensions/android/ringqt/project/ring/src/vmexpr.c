/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_sum(VM *pVM) {
	String *pStr1, *pStr2;
	double nNum1, nNum2;
	char cStr3[RING_MEDIUMBUF];
	unsigned int x, nSize;
	char *cValue;
	/*
	**  Description
	**  We can sum string + number ---> string , number + string ---> number
	**  string/number + nl ---> string
	**  list + string/number ---> add item to the list
	**  list1 + list2 ---> add list2 items to list 1
	*/
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			pStr2 = RING_VM_STACK_GETSTRINGRAW;
			ring_string_add2_gc(pVM->pRingState, pStr2, ring_string_get(pStr1), ring_string_size(pStr1));
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			if (strcmp(ring_string_get(pStr1), "\n") == 0) {
				nSize = strlen(ring_vm_numtostring(pVM, nNum2, cStr3));
				/* Pre-allocated the stack string variable */
				RING_VM_STACK_SETCSIZE(nSize + 1);
				pStr2 = RING_VM_STACK_GETSTRINGRAW;
				/* Manual copy for the content */
				cValue = ring_string_get(pStr2);
				RING_MEMCPY(cValue, cStr3, nSize);
				cValue[nSize] = '\n';
			} else {
				nNum1 = ring_vm_stringtonum(pVM, ring_string_get(pStr1));
				RING_VM_RETURNIFACTIVECATCH;
				RING_VM_STACK_SETNVALUE(nNum1 + nNum2);
			}
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "+", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			RING_VM_STACK_SETNVALUE(nNum1 + nNum2);
		} else if (RING_VM_STACK_ISSTRING) {
			pStr2 = RING_VM_STACK_GETSTRINGRAW;
			ring_vm_numtostring(pVM, nNum1, cStr3);
			ring_string_add_gc(pVM->pRingState, pStr2, cStr3);
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "+", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "+");
		return;
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
		return;
	}
}

void ring_vm_sub(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "-", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "-", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "-");
		return;
	}
	RING_VM_STACK_SETNVALUE(nNum2 - nNum1);
}

void ring_vm_mul(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "*", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "*", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "*");
		return;
	}
	/* Check Overflow */
	RING_VM_CHECKOVERFLOW(nNum1, nNum2);
	RING_VM_STACK_SETNVALUE(nNum1 * nNum2);
}

void ring_vm_div(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "/", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "/", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "/");
		return;
	}
	/* Check Divide by Zero */
	if (nNum1 == 0) {
		ring_vm_error(pVM, RING_VM_ERROR_DIVIDEBYZERO);
		return;
	}
	/* Check Overflow */
	RING_VM_CHECKOVERFLOW(nNum1, nNum2);
	RING_VM_STACK_SETNVALUE(nNum2 / nNum1);
}

void ring_vm_mod(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (nNum1 == 0) {
			ring_vm_error(pVM, RING_VM_ERROR_DIVIDEBYZERO);
			return;
		}
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "%", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "%", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "%");
		return;
	}
	/* Check Overflow */
	RING_VM_CHECKOVERFLOW(nNum1, nNum2);
	RING_VM_STACK_SETNVALUE(fmod(nNum2, nNum1));
}

void ring_vm_neg(VM *pVM) {
	double nNum1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_STACK_SETNVALUE((RING_VM_STACK_READN) * (-1));
	} else if (RING_VM_STACK_ISSTRING) {
		nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
		RING_VM_RETURNIFACTIVECATCH;
		RING_VM_STACK_SETNVALUE((nNum1) * (-1));
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprnpoo(pVM, "neg", RING_NOVALUE);
	}
}

void ring_vm_pow(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "**", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "**", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "**");
		return;
	}
	/* Check Overflow */
	RING_VM_CHECKOVERFLOW(nNum1, nNum2);
	RING_VM_STACK_SETNVALUE(pow(nNum2, nNum1));
}

void ring_vm_equal(VM *pVM) {
	String *pStr1, *pStr2;
	double nNum1, nNum2;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	pVM->lSubStringToNumError = 0;
	if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			pStr2 = RING_VM_STACK_GETSTRINGRAW;
			if ((ring_string_size(pStr1) == ring_string_size(pStr2)) &&
			    (memcmp(ring_string_get(pStr1), ring_string_get(pStr2), ring_string_size(pStr1)) == 0)) {
				RING_VM_STACK_TRUE;
			} else {
				RING_VM_STACK_FALSE;
			}
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum1 = RING_VM_STACK_READN;
			if ((ring_vm_stringtonum(pVM, ring_string_get(pStr1)) == nNum1) && pVM->lFullStringToNum) {
				/* Check whether zero is result of non decimal or hexadecimal value */
				if (nNum1 == 0 && ring_string_get(pStr1)[0] != '\0' &&
				    sscanf(ring_string_get(pStr1), "%lf", &nNum2) != 1) {
					RING_VM_STACK_FALSE;
				} else {
					RING_VM_STACK_TRUE;
				}
			} else {
				RING_VM_STACK_FALSE;
			}
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "=", ring_string_get(pStr1), ring_string_size(pStr1));
		}
	} else if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			if (nNum1 == nNum2) {
				RING_VM_STACK_TRUE;
			} else {
				RING_VM_STACK_FALSE;
			}
		} else if (RING_VM_STACK_ISSTRING) {
			if ((ring_vm_stringtonum(pVM, RING_VM_STACK_READC) == nNum1) && pVM->lFullStringToNum) {
				/* Check whether zero is result of non decimal or hexadecimal value */
				if (nNum1 == 0 && RING_VM_STACK_READC[0] != '\0' &&
				    sscanf(RING_VM_STACK_READC, "%lf", &nNum2) != 1) {
					RING_VM_STACK_FALSE;
				} else {
					RING_VM_STACK_TRUE;
				}
			} else {
				RING_VM_STACK_FALSE;
			}
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "=", nNum1);
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "=");
	}
	pVM->lSubStringToNumError = 1;
}

void ring_vm_lessequal(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "<=", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "<=", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "<=");
		return;
	}
	/* Compare */
	if (nNum2 <= nNum1) {
		RING_VM_STACK_TRUE;
	} else {
		RING_VM_STACK_FALSE;
	}
}

void ring_vm_less(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "<", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "<", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "<");
		return;
	}
	/* Compare */
	if (nNum2 < nNum1) {
		RING_VM_STACK_TRUE;
	} else {
		RING_VM_STACK_FALSE;
	}
}

void ring_vm_greater(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, ">", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, ">", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, ">");
		return;
	}
	/* Compare */
	if (nNum2 > nNum1) {
		RING_VM_STACK_TRUE;
	} else {
		RING_VM_STACK_FALSE;
	}
}

void ring_vm_greaterequal(VM *pVM) {
	double nNum1 = 0, nNum2 = 0;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, ">=", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, ">=", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, ">=");
		return;
	}
	/* Compare */
	if (nNum2 >= nNum1) {
		RING_VM_STACK_TRUE;
	} else {
		RING_VM_STACK_FALSE;
	}
}

void ring_vm_notequal(VM *pVM) {
	String *pStr1, *pStr2;
	double nNum1, nNum2;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	pVM->lSubStringToNumError = 0;
	if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISSTRING) {
			pStr2 = RING_VM_STACK_GETSTRINGRAW;
			/* Compare */
			if ((ring_string_size(pStr1) == ring_string_size(pStr2)) &&
			    (memcmp(ring_string_get(pStr1), ring_string_get(pStr2), ring_string_size(pStr1)) == 0)) {
				RING_VM_STACK_FALSE;
			} else {
				RING_VM_STACK_TRUE;
			}
		} else if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			nNum1 = ring_vm_stringtonum(pVM, ring_string_get(pStr1));
			/* Compare */
			if ((nNum1 == nNum2) && pVM->lFullStringToNum) {
				/* Check whether zero is result of non decimal or hexadecimal value */
				if (nNum1 == 0 && ring_string_get(pStr1)[0] != '\0' &&
				    sscanf(ring_string_get(pStr1), "%lf", &nNum2) != 1) {
					RING_VM_STACK_TRUE;
				} else {
					RING_VM_STACK_FALSE;
				}
			} else {
				RING_VM_STACK_TRUE;
			}
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "!=", ring_string_get(pStr1), ring_string_size(pStr1));
		}
	} else if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			/* Compare */
			if (nNum1 == nNum2) {
				RING_VM_STACK_FALSE;
			} else {
				RING_VM_STACK_TRUE;
			}
		} else if (RING_VM_STACK_ISSTRING) {
			pStr2 = RING_VM_STACK_GETSTRINGRAW;
			/* Compare */
			if ((ring_vm_stringtonum(pVM, ring_string_get(pStr2)) == nNum1) && pVM->lFullStringToNum) {
				/* Check whether zero is result of non decimal or hexadecimal value */
				if (nNum1 == 0 && ring_string_get(pStr2)[0] != '\0' &&
				    sscanf(ring_string_get(pStr2), "%lf", &nNum2) != 1) {
					RING_VM_STACK_TRUE;
				} else {
					RING_VM_STACK_FALSE;
				}
			} else {
				RING_VM_STACK_TRUE;
			}
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "!=", nNum1);
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "!=");
	}
	pVM->lSubStringToNumError = 1;
}

void ring_vm_and(VM *pVM) {
	double nNum1, nNum2;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE((nNum1 && (RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 && nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "and", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE((nNum1 && (RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 && nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "and", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "and");
	}
}

void ring_vm_or(VM *pVM) {
	double nNum1, nNum2;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE((nNum1 || (RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 || nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "or", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE((nNum1 || (RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
			RING_VM_STACK_SETNVALUE((nNum1 || nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "or", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "or");
	}
}

void ring_vm_not(VM *pVM) {
	double nNum1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		if (RING_VM_STACK_READN != 0) {
			RING_VM_STACK_SETNVALUE(0.0);
		} else {
			RING_VM_STACK_SETNVALUE(1.0);
		}
	} else if (RING_VM_STACK_ISSTRING) {
		nNum1 = (double)ring_vm_stringtologicvalue(pVM, RING_VM_STACK_READC);
		if (nNum1 == 1.0) {
			RING_VM_STACK_SETNVALUE(0.0);
		} else {
			RING_VM_STACK_SETNVALUE(1.0);
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprnpoo(pVM, "not", RING_NOVALUE);
		return;
	}
}

void ring_vm_bitand(VM *pVM) {
	double nNum1, nNum2;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE((RING_LONGLONG)nNum1 & (RING_LONGLONG)(RING_VM_STACK_READN));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 & (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "&", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 & (RING_LONGLONG)(RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 & (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "&", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "&");
	}
}

void ring_vm_bitor(VM *pVM) {
	double nNum1, nNum2;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 | (RING_LONGLONG)(RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 | (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "|", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 | (RING_LONGLONG)(RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 | (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "|", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "|");
	}
}

void ring_vm_bitshl(VM *pVM) { ring_vm_bitshift(pVM, "<<"); }

void ring_vm_bitshr(VM *pVM) { ring_vm_bitshift(pVM, ">>"); }

void ring_vm_bitshift(VM *pVM, const char *cOperator) {
	double nNum1, nNum2;
	String *pStr1;
	int lShift;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	lShift = RING_FALSE;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			lShift = RING_TRUE;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			lShift = RING_TRUE;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, cOperator, nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			nNum2 = RING_VM_STACK_READN;
			lShift = RING_TRUE;
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			lShift = RING_TRUE;
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, cOperator, ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, cOperator);
	}
	if (lShift) {
		if (nNum1 < 0) {
			ring_vm_error(pVM, RING_VM_ERROR_VALUEERROR);
		} else if (nNum1 == 0) {
			RING_VM_STACK_SETNVALUE(nNum2);
		} else if (nNum1 > (sizeof(RING_LONGLONG) * RING_BYTEBITS)) {
			RING_VM_STACK_SETNVALUE(0.0);
		} else {
			if (strcmp(cOperator, "<<") == 0) {
				RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum2 << (RING_LONGLONG)nNum1));
			} else {
				RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum2 >> (RING_LONGLONG)nNum1));
			}
		}
	}
}

void ring_vm_bitxor(VM *pVM) {
	double nNum1, nNum2;
	String *pStr1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		nNum1 = RING_VM_STACK_READN;
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 ^ (RING_LONGLONG)(RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 ^ (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprnpoo(pVM, "^", nNum1);
			return;
		}
	} else if (RING_VM_STACK_ISSTRING) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		if (!RING_VM_STACK_PREVISPOINTER) {
			nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
		}
		RING_VM_STACK_POP;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 ^ (RING_LONGLONG)(RING_VM_STACK_READN)));
		} else if (RING_VM_STACK_ISSTRING) {
			nNum2 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
			RING_VM_RETURNIFACTIVECATCH;
			RING_VM_STACK_SETNVALUE(((RING_LONGLONG)nNum1 ^ (RING_LONGLONG)nNum2));
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_vm_exprspoo(pVM, "^", ring_string_get(pStr1), ring_string_size(pStr1));
			return;
		}
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprppoo(pVM, "^");
	}
}

void ring_vm_bitnot(VM *pVM) {
	double nNum1;
	RING_LIST_CHECKOPERATIONONSUBLIST;
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_STACK_SETNVALUE(~(RING_LONGLONG)RING_VM_STACK_READN);
	} else if (RING_VM_STACK_ISSTRING) {
		nNum1 = ring_vm_stringtonum(pVM, RING_VM_STACK_READC);
		RING_VM_RETURNIFACTIVECATCH;
		RING_VM_STACK_SETNVALUE(~(RING_LONGLONG)nNum1);
	} else if (RING_VM_STACK_ISPOINTER) {
		ring_vm_exprnpoo(pVM, "~", RING_NOVALUE);
		return;
	}
}

RING_API char *ring_vm_numtostring(VM *pVM, double nNum1, char *cStr) {
	return ring_general_numtostring(nNum1, cStr, pVM->nDecimals);
}

RING_API double ring_vm_stringtonum(VM *pVM, const char *cStr) {
	double nResult;
	char *cEndStr;
	errno = 0;
	/* Assume that all of the string characters will be converted */
	pVM->lFullStringToNum = 1;
	/* Support converting NULL to Zero */
	if (strcmp(cStr, RING_CSTR_EMPTY) == 0) {
		return RING_ZEROF;
	}
	nResult = strtod(cStr, &cEndStr);
	if (nResult == 0 && (errno != 0)) {
		if (errno == ERANGE) {
			ring_vm_error(pVM, RING_VM_ERROR_NUMERICUNDERFLOW);
		} else {
			ring_vm_error(pVM, RING_VM_ERROR_NUMERICINVALID);
		}
		return RING_ZEROF;
	} else if ((nResult == HUGE_VAL || nResult == -HUGE_VAL) && (errno == ERANGE)) {
		ring_vm_error(pVM, RING_VM_ERROR_NUMERICOVERFLOW);
		return RING_ZEROF;
	} else if (cStr == cEndStr) {
		if (pVM->lSubStringToNumError) {
			ring_vm_error(pVM, RING_VM_ERROR_NUMERICINVALID);
		}
		return RING_ZEROF;
	} else if ((cEndStr > cStr) && (cEndStr < cStr + strlen(cStr))) {
		/* Check Content */
		if (!ring_general_looksempty(cEndStr, strlen(cEndStr))) {
			pVM->lFullStringToNum = 0;
		}
		if ((pVM->lSubStringToNumError) && (pVM->lFullStringToNum == 0)) {
			ring_vm_error(pVM, RING_VM_ERROR_NUMERICINVALID);
			return RING_ZEROF;
		}
	}
	return nResult;
}

int ring_vm_stringtologicvalue(VM *pVM, const char *cStr) { return (!(strcmp(cStr, RING_CSTR_EMPTY) == 0)); }

int ring_vm_listtologicvalue(VM *pVM, List *pList) {
	if (ring_list_getsize(pList) == RING_ZERO) {
		return RING_FALSE;
	}
	if (ring_list_iscpointerlist(pList)) {
		if (ring_list_getpointer(pList, RING_CPOINTER_POINTER) == NULL) {
			return RING_FALSE;
		}
	}
	return RING_TRUE;
}

void ring_vm_exprppoo(VM *pVM, const char *cStr) {
	List *pList, *pList2;
	Item *pItem;
	void *pPointer;
	String *pStr1;
	double nNum1;
	int nType, lCompare;
	char cNewOp[RING_SMALLBUF];
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		pList = ring_list_getlist(pList, RING_VAR_VALUE);
	} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VM_STACK_READP;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
		return;
	}
	/* Get Pointer Data */
	pPointer = RING_VM_STACK_READP;
	nType = RING_VM_STACK_OBJTYPE;
	RING_VM_STACK_POP;
	if (RING_VM_STACK_ISPOINTER) {
		if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
			pList2 = (List *)RING_VM_STACK_READP;
			pList2 = ring_list_getlist(pList2, RING_VAR_VALUE);
		} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
			pItem = (Item *)RING_VM_STACK_READP;
			pList2 = ring_item_getlist(pItem);
		} else {
			ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
			return;
		}
		/* We don't check and/or here because short circuit already converted them to logic values 1/0 */
		if (strcmp(cStr, "+") == 0) {
			if ((ring_vm_oop_isobject(pVM, pList2) == 0)) {
				ring_vm_addlisttolist(pVM, pList, pList2);
				return;
			}
		} else if ((strcmp(cStr, "=") == 0) || (strcmp(cStr, "!=") == 0)) {
			if (ring_list_iscpointerlist(pList) && ring_list_iscpointerlist(pList2)) {
				RING_VM_STACK_POP;
				if (ring_vm_api_cpointercmp(pVM, pList, pList2)) {
					if (strcmp(cStr, "=") == 0) {
						RING_VM_STACK_PUSHNVALUE(1.0);
					} else {
						RING_VM_STACK_PUSHNVALUE(0);
					}
				} else {
					if (strcmp(cStr, "=") == 0) {
						RING_VM_STACK_PUSHNVALUE(0);
					} else {
						RING_VM_STACK_PUSHNVALUE(1.0);
					}
				}
				return;
			}
			lCompare = 1;
			if (ring_vm_oop_isobject(pVM, pList2) == 1) {
				if (ring_vm_oop_ismethod(pVM, pList2, RING_CSTR_OPERATOR)) {
					lCompare = 0;
				}
			}
			if (lCompare) {
				RING_VM_STACK_POP;
				if (pList == pList2) {
					if (strcmp(cStr, "=") == 0) {
						RING_VM_STACK_PUSHNVALUE(1.0);
					} else {
						RING_VM_STACK_PUSHNVALUE(0);
					}
				} else {
					if (strcmp(cStr, "=") == 0) {
						RING_VM_STACK_PUSHNVALUE(0);
					} else {
						RING_VM_STACK_PUSHNVALUE(1.0);
					}
				}
				return;
			}
		}
		if (ring_vm_oop_isobject(pVM, pList2) == 1) {
			/* Operator Overloading */
			ring_vm_oop_operatoroverloading(pVM, pList2, cStr, RING_OOPARA_POINTER, RING_CSTR_EMPTY,
							RING_NOVALUE, pPointer, nType);
		} else {
			if (ring_vm_oop_isobject(pVM, pList) == 1) {
				/* Support Operator Overloading when the list comes first then the object */
				ring_vm_stackswap(pVM, pVM->nSP, pVM->nSP + 1);
				RING_VM_SP_INC;
				sprintf(cNewOp, "r%s", cStr);
				ring_vm_exprppoo(pVM, cNewOp);
			} else {
				ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
			}
		}
	} else if (RING_VM_STACK_ISNUMBER) {
		if (strcmp(cStr, "=") == 0) {
			RING_VM_STACK_SETNVALUE(0.0);
			return;
		} else if (strcmp(cStr, "!=") == 0) {
			RING_VM_STACK_SETNVALUE(1.0);
			return;
		} else if (strcmp(cStr, "and") == 0) {
			if (ring_vm_oop_isobject(pVM, pList) == 0) {
				RING_VM_STACK_SETNVALUE(
				    (double)((ring_vm_listtologicvalue(pVM, pList) != 0) && RING_VM_STACK_READN));
				return;
			} else {
				if (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR)) {
					RING_VM_STACK_SETNVALUE((double)(1 && RING_VM_STACK_READN));
					return;
				}
			}
		} else if (strcmp(cStr, "or") == 0) {
			if (ring_vm_oop_isobject(pVM, pList) == 0) {
				RING_VM_STACK_SETNVALUE(
				    (double)((ring_vm_listtologicvalue(pVM, pList) != 0) || RING_VM_STACK_READN));
				return;
			} else {
				if (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR)) {
					RING_VM_STACK_SETNVALUE(1.0);
					return;
				}
			}
		}
		/* Support Operator Overloading when the number comes first then the object */
		nNum1 = RING_VM_STACK_READN;
		ring_vm_stackswap(pVM, pVM->nSP, pVM->nSP + 1);
		sprintf(cNewOp, "r%s", cStr);
		ring_vm_exprnpoo(pVM, cNewOp, nNum1);
	} else if (RING_VM_STACK_ISSTRING) {
		if (strcmp(cStr, "=") == 0) {
			RING_VM_STACK_SETNVALUE(0.0);
			return;
		} else if (strcmp(cStr, "!=") == 0) {
			RING_VM_STACK_SETNVALUE(1.0);
			return;
		} else if (strcmp(cStr, "and") == 0) {
			if (ring_vm_oop_isobject(pVM, pList) == 0) {
				RING_VM_STACK_SETNVALUE(
				    (double)((ring_vm_listtologicvalue(pVM, pList) != 0) &&
					     (!(strcmp(RING_VM_STACK_READC, RING_CSTR_EMPTY) == 0))));
				return;
			} else {
				if (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR)) {
					RING_VM_STACK_SETNVALUE(
					    (double)(1 && (!(strcmp(RING_VM_STACK_READC, RING_CSTR_EMPTY) == 0))));
					return;
				}
			}
		} else if (strcmp(cStr, "or") == 0) {
			if (ring_vm_oop_isobject(pVM, pList) == 0) {
				RING_VM_STACK_SETNVALUE(
				    (double)((ring_vm_listtologicvalue(pVM, pList) != 0) ||
					     (!(strcmp(RING_VM_STACK_READC, RING_CSTR_EMPTY) == 0))));
				return;
			} else {
				if (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR)) {
					RING_VM_STACK_SETNVALUE(1.0);
					return;
				}
			}
		}
		/* Support Operator Overloading when the string comes first then the object */
		pStr1 = RING_VM_STACK_GETSTRINGRAW;
		ring_vm_stackswap(pVM, pVM->nSP, pVM->nSP + 1);
		sprintf(cNewOp, "r%s", cStr);
		ring_vm_exprspoo(pVM, cNewOp, ring_string_get(pStr1), ring_string_size(pStr1));
	}
}

void ring_vm_exprnpoo(VM *pVM, const char *cStr, double nNum1) {
	List *pList;
	Item *pItem;
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		pList = ring_list_getlist(pList, RING_VAR_VALUE);
	} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VM_STACK_READP;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
		return;
	}
	if (strcmp(cStr, "+") == 0) {
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			ring_list_adddouble_gc(pVM->pRingState, pList, nNum1);
			return;
		}
	} else if (strcmp(cStr, "not") == 0) {
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			RING_VM_STACK_SETNVALUE((double)(ring_vm_listtologicvalue(pVM, pList) == 0));
			return;
		} else {
			if (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR)) {
				RING_VM_STACK_SETNVALUE(RING_FALSEF);
				return;
			}
		}
	} else if (strcmp(cStr, "and") == 0) {
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			RING_VM_STACK_SETNVALUE((double)((ring_vm_listtologicvalue(pVM, pList) != 0) && nNum1));
			return;
		}
	} else if (strcmp(cStr, "or") == 0) {
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			RING_VM_STACK_SETNVALUE((double)((ring_vm_listtologicvalue(pVM, pList) != 0) || nNum1));
			return;
		}
	} else if (strcmp(cStr, "=") == 0) {
		if ((ring_vm_oop_isobject(pVM, pList) == 0) ||
		    (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR))) {
			RING_VM_STACK_SETNVALUE(0.0);
			return;
		}
	} else if (strcmp(cStr, "!=") == 0) {
		if ((ring_vm_oop_isobject(pVM, pList) == 0) ||
		    (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR))) {
			RING_VM_STACK_SETNVALUE(1.0);
			return;
		}
	}
	if (ring_vm_oop_isobject(pVM, pList) == 1) {
		/* Operator Overloading */
		ring_vm_oop_operatoroverloading(pVM, pList, cStr, RING_OOPARA_NUMBER, RING_CSTR_EMPTY, nNum1, NULL,
						RING_OBJTYPE_NOTYPE);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
	}
}

void ring_vm_exprspoo(VM *pVM, const char *cStr, const char *pStr2, unsigned int nStrSize) {
	List *pList;
	Item *pItem;
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		pList = ring_list_getlist(pList, RING_VAR_VALUE);
	} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VM_STACK_READP;
		pList = ring_item_getlist(pItem);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
		return;
	}
	if (strcmp(cStr, "+") == 0) {
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			ring_list_addstring2_gc(pVM->pRingState, pList, pStr2, nStrSize);
			return;
		}
	} else if (strcmp(cStr, "=") == 0) {
		if ((ring_vm_oop_isobject(pVM, pList) == 0) ||
		    (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR))) {
			RING_VM_STACK_SETNVALUE(0.0);
			return;
		}
	} else if (strcmp(cStr, "!=") == 0) {
		if ((ring_vm_oop_isobject(pVM, pList) == 0) ||
		    (!ring_vm_oop_ismethod(pVM, pList, RING_CSTR_OPERATOR))) {
			RING_VM_STACK_SETNVALUE(1.0);
			return;
		}
	}
	if (ring_vm_oop_isobject(pVM, pList) == 1) {
		/* Operator Overloading */
		ring_vm_oop_operatoroverloading(pVM, pList, cStr, RING_OOPARA_STRING, pStr2, RING_NOVALUE, NULL,
						RING_OBJTYPE_NOTYPE);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADVALUES);
	}
}

void ring_vm_addlisttolist(VM *pVM, List *pList, List *pList2) {
	List *pList3, *pList4;
	Item *pItem;
	/*
	**  Here we are going to copy the list pList to the list pList2
	**  We will copy to a temp list first (pList4)
	**  So we can add the Self object for example to an attribute in this object
	**  Check if we have a Reference
	*/
	if (ring_list_isref_gc(pVM->pRingState, pList)) {
		ring_list_insertlist(pList2, ring_list_getsize(pList2));
		pItem = ring_list_getitem_gc(pVM->pRingState, pList2, ring_list_getsize(pList2));
		ring_list_assignreftoitem_gc(pVM->pRingState, pList, pItem);
		return;
	}
	pList4 = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	ring_vm_listcopy(pVM, pList4, pList);
	pList3 = ring_list_newlist_gc(pVM->pRingState, pList2);
	ring_vm_listcopy(pVM, pList3, pList4);
	ring_list_delete_gc(pVM->pRingState, pList4);
	if ((ring_vm_oop_isobject(pVM, pList3) == 1) && (pVM->pBraceObject == pList)) {
		pVM->pBraceObject = pList3;
		/*
		**  The copied object was created in Temp. memory that will be deleted
		**  The object contains the self property that contains a pointer to the object in memory
		**  We need to modify the pointer that point to the old location in Temp. Memory
		**  The pointer will be changed to point to the new location in the array
		**  The array maybe global or related to the object state and may stay longer than the Temp. Memory
		**  Without this modification using self may lead to crash or using corrupted memory
		*/
		ring_vm_oop_updateselfpointer(pVM, pList3, RING_OBJTYPE_LISTITEM,
					      ring_list_getitem_gc(pVM->pRingState, pList2, ring_list_getsize(pList2)));
	} else if ((ring_vm_oop_isobject(pVM, pList3) == 1) && (pVM->pBraceObject != pList)) {
		/*
		**  in ring code if we used mylist + new obj() the init method will be called
		**  the pVM->pBraceObject will not == pList but we have to update the self pointer!
		*/
		ring_vm_oop_updateselfpointer(pVM, pList3, RING_OBJTYPE_LISTITEM,
					      ring_list_getitem_gc(pVM->pRingState, pList2, ring_list_getsize(pList2)));
	}
}

int ring_vm_checkoverflow(VM *pVM, double nNum1, double nNum2) {
	char cStr1[RING_MEDIUMBUF];
	char cStr2[RING_MEDIUMBUF];
	if (pVM->lCheckOverFlow) {
		/* We check the lCheckOverFlow flag first because the next operations decrease performance when we deal
		 * with millions of numbers */
		if ((strlen(ring_vm_numtostring(pVM, nNum1, cStr1)) >= RING_VM_MAXDIGITSINNUMBER) ||
		    (strlen(ring_vm_numtostring(pVM, nNum2, cStr2)) >= RING_VM_MAXDIGITSINNUMBER)) {
			ring_vm_error(pVM, RING_VM_ERROR_NUMERICOVERFLOW);
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}
