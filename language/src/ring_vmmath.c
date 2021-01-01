/* Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Functions */

void ring_vm_math_loadfunctions ( RingState *pRingState )
{
	ring_vm_funcregister("sin",ring_vm_math_sin);
	ring_vm_funcregister("cos",ring_vm_math_cos);
	ring_vm_funcregister("tan",ring_vm_math_tan);
	ring_vm_funcregister("asin",ring_vm_math_asin);
	ring_vm_funcregister("acos",ring_vm_math_acos);
	ring_vm_funcregister("atan",ring_vm_math_atan);
	ring_vm_funcregister("atan2",ring_vm_math_atan2);
	ring_vm_funcregister("sinh",ring_vm_math_sinh);
	ring_vm_funcregister("cosh",ring_vm_math_cosh);
	ring_vm_funcregister("tanh",ring_vm_math_tanh);
	ring_vm_funcregister("exp",ring_vm_math_exp);
	ring_vm_funcregister("log",ring_vm_math_log);
	ring_vm_funcregister("log10",ring_vm_math_log10);
	ring_vm_funcregister("ceil",ring_vm_math_ceil);
	ring_vm_funcregister("floor",ring_vm_math_floor);
	ring_vm_funcregister("fabs",ring_vm_math_fabs);
	ring_vm_funcregister("pow",ring_vm_math_pow);
	ring_vm_funcregister("sqrt",ring_vm_math_sqrt);
	ring_vm_funcregister("unsigned",ring_vm_math_unsigned);
	ring_vm_funcregister("decimals",ring_vm_math_decimals);
	ring_vm_funcregister("murmur3hash",ring_vm_math_murmur3hash);
}

void ring_vm_math_sin ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(sin(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_cos ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(cos(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_tan ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(tan(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_asin ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(asin(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_acos ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(acos(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_atan ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(atan(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_atan2 ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) {
		RING_API_RETNUMBER(atan2(RING_API_GETNUMBER(1),RING_API_GETNUMBER(2)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_sinh ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(sinh(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_cosh ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(cosh(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_tanh ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(tanh(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_exp ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(exp(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_log ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(log(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_log10 ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(log10(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_ceil ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(ceil(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_floor ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(floor(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_fabs ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(fabs(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_pow ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) {
		RING_API_RETNUMBER(pow(RING_API_GETNUMBER(1),RING_API_GETNUMBER(2)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_sqrt ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(sqrt(RING_API_GETNUMBER(1)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_unsigned ( void *pPointer )
{
	unsigned long nNum1,nNum2,nNum3  ;
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) && RING_API_ISSTRING(3) ) {
		nNum1 = (unsigned long) RING_API_GETNUMBER(1) ;
		nNum2 = (unsigned long) RING_API_GETNUMBER(2) ;
		cStr = RING_API_GETSTRING(3) ;
		if ( strcmp(cStr,">>") == 0 ) {
			nNum3 = nNum1 >> nNum2 ;
		}
		else if ( strcmp(cStr,"<<") == 0 ) {
			nNum3 = nNum1 << nNum2 ;
		}
		else if ( strcmp(cStr,"+") == 0 ) {
			nNum3 = nNum1 + nNum2 ;
		}
		else if ( strcmp(cStr,"-") == 0 ) {
			nNum3 = nNum1 - nNum2 ;
		}
		else if ( strcmp(cStr,"*") == 0 ) {
			nNum3 = nNum1 * nNum2 ;
		}
		else if ( strcmp(cStr,"/") == 0 ) {
			if ( nNum2 != 0 ) {
				nNum3 = nNum1 / nNum2 ;
			}
			else {
				RING_API_ERROR(RING_VM_ERROR_DIVIDEBYZERO);
				return ;
			}
		}
		else if ( strcmp(cStr,"^") == 0 ) {
			nNum3 = nNum1 ^ nNum2 ;
		}
		else if ( strcmp(cStr,"<") == 0 ) {
			nNum3 = nNum1 < nNum2 ;
		}
		else if ( strcmp(cStr,">") == 0 ) {
			nNum3 = nNum1 > nNum2 ;
		}
		else if ( strcmp(cStr,"<=") == 0 ) {
			nNum3 = nNum1 <= nNum2 ;
		}
		else if ( strcmp(cStr,">=") == 0 ) {
			nNum3 = nNum1 >= nNum2 ;
		}
		else if ( strcmp(cStr,"=") == 0 ) {
			nNum3 = nNum1 == nNum2 ;
		}
		else if ( strcmp(cStr,"!=") == 0 ) {
			nNum3 = nNum1 != nNum2 ;
		}
		else if ( strcmp(cStr,"&") == 0 ) {
			nNum3 = nNum1 & nNum2 ;
		}
		else if ( strcmp(cStr,"|") == 0 ) {
			nNum3 = nNum1 | nNum2 ;
		}
		else if ( strcmp(cStr,"~") == 0 ) {
			nNum3 = ~ nNum1 ;
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return ;
		}
		RING_API_RETNUMBER((double) nNum3);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_math_decimals ( void *pPointer )
{
	int nNum1  ;
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			nNum1 = (int) RING_API_GETNUMBER(1) ;
			if ( (nNum1 >= 0) && (nNum1 <= RING_VM_DECIMALSLIMIT) ) {
				((VM *) pPointer)->nDecimals = nNum1 ;
			}
			else {
				RING_API_ERROR(RING_VM_ERROR_BADDECIMALNUMBER);
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}
/* Hash */

void ring_vm_math_murmur3hash ( void *pPointer )
{
	unsigned int nResult  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISNUMBER(2) ) {
		nResult = ring_murmur3_32(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1),RING_API_GETNUMBER(2));
		RING_API_RETNUMBER(nResult);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
