/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_math_loadfunctions(RingState *pRingState) {
	RING_API_REGISTER("sin", ring_vm_math_sin);
	RING_API_REGISTER("cos", ring_vm_math_cos);
	RING_API_REGISTER("tan", ring_vm_math_tan);
	RING_API_REGISTER("asin", ring_vm_math_asin);
	RING_API_REGISTER("acos", ring_vm_math_acos);
	RING_API_REGISTER("atan", ring_vm_math_atan);
	RING_API_REGISTER("atan2", ring_vm_math_atan2);
	RING_API_REGISTER("sinh", ring_vm_math_sinh);
	RING_API_REGISTER("cosh", ring_vm_math_cosh);
	RING_API_REGISTER("tanh", ring_vm_math_tanh);
	RING_API_REGISTER("exp", ring_vm_math_exp);
	RING_API_REGISTER("log", ring_vm_math_log);
	RING_API_REGISTER("log10", ring_vm_math_log10);
	RING_API_REGISTER("ceil", ring_vm_math_ceil);
	RING_API_REGISTER("floor", ring_vm_math_floor);
	RING_API_REGISTER("fabs", ring_vm_math_fabs);
	RING_API_REGISTER("pow", ring_vm_math_pow);
	RING_API_REGISTER("sqrt", ring_vm_math_sqrt);
	RING_API_REGISTER("unsigned", ring_vm_math_unsigned);
	RING_API_REGISTER("decimals", ring_vm_math_decimals);
	RING_API_REGISTER("murmur3hash", ring_vm_math_murmur3hash);
	RING_API_REGISTER("random", ring_vm_math_random);
	RING_API_REGISTER("srandom", ring_vm_math_srandom);
	RING_API_REGISTER("checkoverflow", ring_vm_math_checkoverflow);
}

void ring_vm_math_sin(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(sin(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_cos(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(cos(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_tan(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(tan(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_asin(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(asin(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_acos(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(acos(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_atan(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(atan(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_atan2(void *pPointer) {
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
		RING_API_RETNUMBER(atan2(RING_API_GETNUMBER(1), RING_API_GETNUMBER(2)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_sinh(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(sinh(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_cosh(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(cosh(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_tanh(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(tanh(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_exp(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(exp(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_log(void *pPointer) {
	if ((RING_API_PARACOUNT != 1) && (RING_API_PARACOUNT != 2)) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISNUMBER(1)) {
			RING_API_RETNUMBER(log(RING_API_GETNUMBER(1)));
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	if (RING_API_PARACOUNT == 2) {
		if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
			RING_API_RETNUMBER(log10(RING_API_GETNUMBER(1)) / log10(RING_API_GETNUMBER(2)));
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
}

void ring_vm_math_log10(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(log10(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_ceil(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(ceil(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_floor(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(floor(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_fabs(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(fabs(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_pow(void *pPointer) {
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
		RING_API_RETNUMBER(pow(RING_API_GETNUMBER(1), RING_API_GETNUMBER(2)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_sqrt(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		RING_API_RETNUMBER(sqrt(RING_API_GETNUMBER(1)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_unsigned(void *pPointer) {
	RING_UNSIGNEDLONGLONG nNum1, nNum2, nNum3;
	const char *cStr;
	if (RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return;
	}
	if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) && RING_API_ISSTRING(3)) {
		nNum1 = (RING_UNSIGNEDLONGLONG)RING_API_GETNUMBER(1);
		nNum2 = (RING_UNSIGNEDLONGLONG)RING_API_GETNUMBER(2);
		cStr = RING_API_GETSTRING(3);
		if (strcmp(cStr, ">>") == 0) {
			if (nNum2 < 0) {
				RING_API_ERROR(RING_VM_ERROR_VALUEERROR);
				return;
			}
			nNum3 = nNum1 >> nNum2;
		} else if (strcmp(cStr, "<<") == 0) {
			if (nNum2 < 0) {
				RING_API_ERROR(RING_VM_ERROR_VALUEERROR);
				return;
			}
			nNum3 = nNum1 << nNum2;
		} else if (strcmp(cStr, "+") == 0) {
			nNum3 = nNum1 + nNum2;
		} else if (strcmp(cStr, "-") == 0) {
			nNum3 = nNum1 - nNum2;
		} else if (strcmp(cStr, "*") == 0) {
			nNum3 = nNum1 * nNum2;
		} else if (strcmp(cStr, "/") == 0) {
			if (nNum2 != 0) {
				nNum3 = nNum1 / nNum2;
			} else {
				RING_API_ERROR(RING_VM_ERROR_DIVIDEBYZERO);
				return;
			}
		} else if (strcmp(cStr, "^") == 0) {
			nNum3 = nNum1 ^ nNum2;
		} else if (strcmp(cStr, "<") == 0) {
			nNum3 = nNum1 < nNum2;
		} else if (strcmp(cStr, ">") == 0) {
			nNum3 = nNum1 > nNum2;
		} else if (strcmp(cStr, "<=") == 0) {
			nNum3 = nNum1 <= nNum2;
		} else if (strcmp(cStr, ">=") == 0) {
			nNum3 = nNum1 >= nNum2;
		} else if (strcmp(cStr, "=") == 0) {
			nNum3 = nNum1 == nNum2;
		} else if (strcmp(cStr, "!=") == 0) {
			nNum3 = nNum1 != nNum2;
		} else if (strcmp(cStr, "&") == 0) {
			nNum3 = nNum1 & nNum2;
		} else if (strcmp(cStr, "|") == 0) {
			nNum3 = nNum1 | nNum2;
		} else if (strcmp(cStr, "~") == 0) {
			nNum3 = ~nNum1;
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
		RING_API_RETNUMBER((double)nNum3);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_decimals(void *pPointer) {
	int nNum1;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISNUMBER(1)) {
			nNum1 = (int)RING_API_GETNUMBER(1);
			if ((nNum1 >= 0) && (nNum1 <= RING_VM_DECIMALSLIMIT)) {
				((VM *)pPointer)->nDecimals = nNum1;
			} else {
				RING_API_ERROR(RING_VM_ERROR_BADDECIMALNUMBER);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vm_math_murmur3hash(void *pPointer) {
	unsigned int nResult;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISSTRING(1) && RING_API_ISNUMBER(2)) {
		nResult =
		    ring_hashlib_murmurthree32(RING_API_GETSTRING(1), RING_API_GETSTRINGSIZE(1), RING_API_GETNUMBER(2));
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* 31 bit thread unsafe random generator using the seed (srand) */

void ring_vm_math_random(void *pPointer) {
	int nNum1, nNum2;
	nNum1 = rand();
#ifdef _MSC_VER
	#ifdef rand_s
	rand_s(&nNum2);
	nNum1 |= (nNum2 & 0xFFFF) << 15;
	#endif
#endif
	if (RING_API_PARACOUNT == 0) {
		RING_API_RETNUMBER(nNum1);
	} else if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISNUMBER(1)) {
			nNum2 = RING_API_GETNUMBER(1);
			if (nNum2 > 0) {
				RING_API_RETNUMBER(nNum1 % ++nNum2);
			} else if (nNum2 == 0) {
				RING_API_RETNUMBER(RING_ZEROF);
			} else {
				nNum2 = -1 * nNum2;
				nNum2++;
				nNum2 = nNum1 % nNum2;
				RING_API_RETNUMBER(-1 * nNum2);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vm_math_srandom(void *pPointer) {
	int nNum1;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISNUMBER(1)) {
			nNum1 = RING_API_GETNUMBER(1);
			if (nNum1 >= 0) {
				srand(nNum1);
			} else {
				RING_API_ERROR(RING_API_BADPARARANGE);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vm_math_checkoverflow(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		if (RING_API_GETNUMBER(1) == 1) {
			((VM *)pPointer)->lCheckOverFlow = 1;
		} else {
			((VM *)pPointer)->lCheckOverFlow = 0;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
