/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Support for C Functions */

RING_API void ring_vm_funcregister2 ( RingState *pRingState,const char *cStr, void (*pFunc)(void *) )
{
	List *pList  ;
	if ( pRingState->pRingCFunctions == NULL ) {
		pRingState->pRingCFunctions = ring_list_new(0);
	}
	pList = ring_list_newlist(pRingState->pRingCFunctions);
	ring_list_addstring(pList,cStr);
	ring_list_addfuncpointer(pList,pFunc);
}

RING_API void ring_vm_loadcfunctions ( RingState *pRingState )
{
	/* General */
	ring_vm_funcregister("len",ring_vmlib_len);
	ring_vm_funcregister("add",ring_vmlib_add);
	ring_vm_funcregister("del",ring_vmlib_del);
	ring_vm_funcregister("get",ring_vmlib_get);
	ring_vm_funcregister("clock",ring_vmlib_clock);
	ring_vm_funcregister("lower",ring_vmlib_lower);
	ring_vm_funcregister("upper",ring_vmlib_upper);
	ring_vm_funcregister("input",ring_vmlib_input);
	ring_vm_funcregister("ascii",ring_vmlib_ascii);
	ring_vm_funcregister("char",ring_vmlib_char);
	ring_vm_funcregister("date",ring_vmlib_date);
	ring_vm_funcregister("time",ring_vmlib_time);
	ring_vm_funcregister("filename",ring_vmlib_filename);
	ring_vm_funcregister("getchar",ring_vmlib_getchar);
	ring_vm_funcregister("system",ring_vmlib_system);
	ring_vm_funcregister("random",ring_vmlib_random);
	ring_vm_funcregister("timelist",ring_vmlib_timelist);
	ring_vm_funcregister("adddays",ring_vmlib_adddays);
	ring_vm_funcregister("diffdays",ring_vmlib_diffdays);
	/* Check Data Type */
	ring_vm_funcregister("isstring",ring_vmlib_isstring);
	ring_vm_funcregister("isnumber",ring_vmlib_isnumber);
	ring_vm_funcregister("islist",ring_vmlib_islist);
	ring_vm_funcregister("type",ring_vmlib_type);
	ring_vm_funcregister("isnull",ring_vmlib_isnull);
	ring_vm_funcregister("isobject",ring_vmlib_isobject);
	/* Conversion */
	ring_vm_funcregister("hex",ring_vmlib_hex);
	ring_vm_funcregister("dec",ring_vmlib_dec);
	ring_vm_funcregister("number",ring_vmlib_number);
	ring_vm_funcregister("string",ring_vmlib_string);
	ring_vm_funcregister("str2hex",ring_vmlib_str2hex);
	ring_vm_funcregister("hex2str",ring_vmlib_hex2str);
	ring_vm_funcregister("str2list",ring_vmlib_str2list);
	ring_vm_funcregister("list2str",ring_vmlib_list2str);
	/* String */
	ring_vm_funcregister("left",ring_vmlib_left);
	ring_vm_funcregister("right",ring_vmlib_right);
	ring_vm_funcregister("trim",ring_vmlib_trim);
	ring_vm_funcregister("copy",ring_vmlib_copy);
	ring_vm_funcregister("substr",ring_vmlib_substr);
	ring_vm_funcregister("lines",ring_vmlib_lines);
	ring_vm_funcregister("strcmp",ring_vmlib_strcmp);
	/* Functional */
	ring_vm_funcregister("eval",ring_vmlib_eval);
	/* Error Handling */
	ring_vm_funcregister("raise",ring_vmlib_raise);
	ring_vm_funcregister("assert",ring_vmlib_assert);
	/* Check Characters */
	ring_vm_funcregister("isalnum",ring_vmlib_isalnum);
	ring_vm_funcregister("isalpha",ring_vmlib_isalpha);
	ring_vm_funcregister("iscntrl",ring_vmlib_iscntrl);
	ring_vm_funcregister("isdigit",ring_vmlib_isdigit);
	ring_vm_funcregister("isgraph",ring_vmlib_isgraph);
	ring_vm_funcregister("islower",ring_vmlib_islower);
	ring_vm_funcregister("isprint",ring_vmlib_isprint);
	ring_vm_funcregister("ispunct",ring_vmlib_ispunct);
	ring_vm_funcregister("isspace",ring_vmlib_isspace);
	ring_vm_funcregister("isupper",ring_vmlib_isupper);
	ring_vm_funcregister("isxdigit",ring_vmlib_isxdigit);
	/* Other Modules */
	ring_vm_extension(pRingState);
	/* Garbage Collector & Variable Pointer */
	ring_vm_funcregister("callgc",ring_vmlib_callgc);
	ring_vm_funcregister("varptr",ring_vmlib_varptr);
	ring_vm_funcregister("intvalue",ring_vmlib_intvalue);
}

int ring_vm_api_islist ( void *pPointer,int x )
{
	int nType  ;
	if ( RING_API_ISPOINTER(x) ) {
		nType = RING_API_GETPOINTERTYPE(x);
		if ( nType == RING_OBJTYPE_VARIABLE || nType == RING_OBJTYPE_LISTITEM ) {
			return 1 ;
		}
	}
	return 0 ;
}

RING_API List * ring_vm_api_getlist ( void *pPointer,int x )
{
	int nType  ;
	Item *pItem  ;
	List *pList  ;
	if ( RING_API_ISPOINTER(x) ) {
		nType = RING_API_GETPOINTERTYPE(x);
		if ( nType == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_API_GETPOINTER(x) ;
			return ring_list_getlist(pList,3) ;
		}
		else if ( nType == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_API_GETPOINTER(x) ;
			return ring_item_getlist(pItem) ;
		}
	}
	return NULL ;
}

RING_API void ring_vm_api_retlist ( void *pPointer,List *pList )
{
	List *pList2,*pList3  ;
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	pList2 = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1);
	pList3 = ring_vm_newvar2(RING_TEMP_VARIABLE,pList2);
	ring_list_setint(pList3,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pList3,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList3,RING_VAR_VALUE);
	/* Copy the list */
	ring_list_copy(pList2,pList);
	RING_API_PUSHPVALUE(pList3);
	RING_API_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}

RING_API List * ring_vm_api_newlist ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_newlist(pVM->pActiveMem);
	return pList ;
}

RING_API void ring_vm_api_retcpointer ( void *pPointer,void *pGeneral,const char *cType )
{
	List *pList  ;
	/* Create the list */
	pList = RING_API_NEWLIST ;
	/* The variable value will be a list contains the pointer */
	ring_list_addpointer(pList,pGeneral);
	/* Add the pointer type */
	ring_list_addstring(pList,cType);
	/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
	ring_list_addint(pList,2);
	RING_API_RETLIST(pList);
}

RING_API void * ring_vm_api_getcpointer ( void *pPointer,int x,const char *cType )
{
	List *pList, *pList2  ;
	int y  ;
	if ( RING_API_ISLIST(x) ) {
		pList = RING_API_GETLIST(x) ;
		if ( ring_list_ispointer(pList,1) ) {
			if ( ring_list_getpointer(pList,1) != NULL ) {
				if ( (strcmp(ring_list_getstring(pList,2),cType) == 0) || (((VM *) pPointer)->nIgnoreCPointerTypeCheck==1) ) {
					/*
					**  Check if the pointer is copied or not 
					**  We check for 2 (not assigned) also, happens when f1 ( x , f2() ) and f2 return C pointer 
					*/
					if ( (ring_list_getint(pList,3) == 0) || (ring_list_getint(pList,3) == 2) ) {
						return ring_list_getpointer(pList,1) ;
					}
					pList2 = ((VM *) pPointer)->aCPointers ;
					if ( ring_list_getsize(pList2) > 0 ) {
						for ( y = 1 ; y <= ring_list_getsize(pList2) ; y++ ) {
							if ( ring_list_getpointer(pList,1) == ring_list_getpointer(pList2,y) ) {
								return ring_list_getpointer(pList,1) ;
							}
						}
					}
					ring_list_setpointer(pList,1,NULL);
					RING_API_ERROR(RING_API_NULLPOINTER);
					return NULL ;
				}
				RING_API_ERROR(RING_API_BADPARATYPE);
				return NULL ;
			}
			RING_API_ERROR(RING_API_NULLPOINTER);
			return NULL ;
		}
	}
	RING_API_ERROR(RING_API_NOTPOINTER);
	return NULL ;
}

void ring_vm_api_setcpointernull ( void *pPointer,int x )
{
	List *pList, *pList2  ;
	int y  ;
	pList = (List *) RING_API_GETLIST(x) ;
	/* Check pointer status ( 0 = copied , 1 = Not copied ) */
	if ( ring_list_getint(pList,3) == 0 ) {
		ring_list_setpointer(pList,1,NULL);
		return ;
	}
	pList2 = ((VM *) pPointer)->aCPointers ;
	if ( ring_list_getsize(pList2) > 0 ) {
		for ( y = 1 ; y <= ring_list_getsize(pList2) ; y++ ) {
			if ( ring_list_getpointer(pList,1) == ring_list_getpointer(pList2,y) ) {
				ring_list_deleteitem(pList2,y);
				ring_list_setpointer(pList,1,NULL);
			}
		}
	}
}

RING_API void * ring_vm_api_varptr ( void *pPointer,const char  *cStr,const char *cStr2 )
{
	VM *pVM  ;
	List *pList  ;
	Item *pItem  ;
	/*
	**  Usage 
	**  To get pointer to a ring variable value (pointer to double or int) i.e. int * or double * 
	**  We need this because some C Functions get int * or double * as parameter 
	*/
	pVM = (VM *) pPointer ;
	if ( ring_vm_findvar(pVM, cStr ) == 0 ) {
		RING_API_ERROR(RING_VM_ERROR_NOTVARIABLE);
		return NULL ;
	}
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_NUMBER ) {
		pItem = ring_list_getitem(pList,RING_VAR_VALUE);
		if ( strcmp(cStr2,"double") == 0 ) {
			return &(pItem->data.dNumber) ;
		}
		else if ( strcmp(cStr2,"int") == 0 ) {
			return &(pItem->data.iNumber) ;
		}
	}
	return NULL ;
}

RING_API void ring_vm_api_intvalue ( void *pPointer,const char  *cStr )
{
	VM *pVM  ;
	List *pList  ;
	Item *pItem  ;
	/*
	**  Usage 
	**  Convert the variable value from int to double 
	**  When we pass int * for Ring Variable Value to a C Function 
	**  We need to convert again from int to double, because Ring uses double 
	*/
	pVM = (VM *) pPointer ;
	if ( ring_vm_findvar(pVM, cStr ) == 0 ) {
		RING_API_ERROR(RING_VM_ERROR_NOTVARIABLE);
		return ;
	}
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_NUMBER ) {
		pItem = ring_list_getitem(pList,RING_VAR_VALUE);
		pItem->data.dNumber = (double) pItem->data.iNumber ;
	}
}
/*
**  Library 
**  General 
*/

void ring_vmlib_len ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1)) == 0 ) {
			RING_API_RETNUMBER(ring_list_getsize(RING_API_GETLIST(1)));
		}
		else {
			RING_VM_STACK_PUSHPVALUE(RING_API_GETPOINTER(1));
			RING_VM_STACK_OBJTYPE = RING_API_GETPOINTERTYPE(1) ;
			ring_vm_expr_npoo(pVM,"len",0);
			pVM->nIgnoreNULL = 1 ;
		}
	}
	else if ( RING_API_ISSTRING(1) ) {
		RING_API_RETNUMBER(RING_API_GETSTRINGSIZE(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_add ( void *pPointer )
{
	List *pList,*pList2, *pList3  ;
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1) ;
		if ( RING_API_ISSTRING(2) ) {
			ring_list_addstring2(pList,RING_API_GETSTRING(2),RING_API_GETSTRINGSIZE(2));
			RING_API_RETSTRING2(RING_API_GETSTRING(2),RING_API_GETSTRINGSIZE(2));
		}
		else if ( RING_API_ISNUMBER(2) ) {
			ring_list_adddouble(pList,RING_API_GETNUMBER(2));
			RING_API_RETNUMBER(RING_API_GETNUMBER(2));
		}
		else if ( RING_API_ISLIST(2) ) {
			pList2 = ring_list_newlist(pList);
			pList3 = RING_API_GETLIST(2) ;
			ring_list_copy(pList2,pList3);
			if ( (ring_vm_oop_isobject(pList3) == 1)  && (pVM->pBraceObject == pList3) ) {
				pVM->pBraceObject = pList2 ;
				ring_vm_oop_updateselfpointer(pList2,RING_OBJTYPE_LISTITEM,ring_list_getitem(pList,ring_list_getsize(pList)));
			}
			else if ( (ring_vm_oop_isobject(pList3) == 1)  && (pVM->pBraceObject != pList3) ) {
				ring_vm_oop_updateselfpointer(pList2,RING_OBJTYPE_LISTITEM,ring_list_getitem(pList,ring_list_getsize(pList)));
			}
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_del ( void *pPointer )
{
	List *pList  ;
	double nNum1  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1) ;
		if ( RING_API_ISNUMBER(2) ) {
			nNum1 = RING_API_GETNUMBER(2) ;
			if ( ( nNum1 < 1 ) || ( nNum1 > ring_list_getsize(pList) ) ) {
				RING_API_ERROR("Error in second parameter, item number outside the list size range!");
				return ;
			}
			ring_list_deleteitem(pList,nNum1);
		} else {
			RING_API_ERROR("Error in second parameter, Function requires number!");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_get ( void *pPointer )
{
	char *pData  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		pData = getenv(RING_API_GETSTRING(1));
		if ( pData != NULL ) {
			RING_API_RETSTRING(pData);
		} else {
			RING_API_RETSTRING("");
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_clock ( void *pPointer )
{
	clock_t nNum1  ;
	nNum1 = clock();
	RING_API_RETNUMBER((double) nNum1);
}

void ring_vmlib_input ( void *pPointer )
{
	char *cLine  ;
	int nSize  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nSize = RING_API_GETNUMBER(1);
	}
	else if ( RING_API_ISSTRING(1) ) {
		nSize = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( nSize > 0 ) {
		cLine = (char *) malloc(nSize) ;
		if ( cLine == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		/* Get Input From the User and save it in the variable */
		RING_SETBINARY ;
		fread( cLine , sizeof(char) , nSize , stdin );
		/* Return String */
		RING_API_RETSTRING2(cLine,nSize);
		free( cLine ) ;
	} else {
		RING_API_ERROR("Error in first parameter,  input size < 1 !");
	}
}

void ring_vmlib_ascii ( void *pPointer )
{
	int x  ;
	unsigned char *cString  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_GETSTRINGSIZE(1) == 1 ) {
			cString = (unsigned char *) RING_API_GETSTRING(1) ;
			x = (int) cString[0] ;
			RING_API_RETNUMBER(x);
		} else {
			RING_API_ERROR("Error in first parameter, the string size is not one letter !");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_char ( void *pPointer )
{
	int x  ;
	char cStr[2]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		x = RING_API_GETNUMBER(1) ;
		cStr[0] = (char) x ;
		cStr[1] = '\0' ;
		RING_API_RETSTRING2(cStr,1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_date ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,25,"%d/%m/%Y", tm_info);
	RING_API_RETSTRING(buffer);
}

void ring_vmlib_time ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,25,"%H:%M:%S", tm_info);
	RING_API_RETSTRING(buffer);
}

void ring_vmlib_filename ( void *pPointer )
{
	RING_API_RETSTRING(((VM *) pPointer)->cFileName);
}

void ring_vmlib_getchar ( void *pPointer )
{
	char cStr[2]  ;
	RING_SETBINARY ;
	cStr[0] = getchar() ;
	RING_API_RETSTRING2(cStr,1);
}

void ring_vmlib_system ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		system(RING_API_GETSTRING(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_random ( void *pPointer )
{
	int nNum1,nNum2  ;
	nNum1 = rand() ;
	if ( RING_API_PARACOUNT == 0 ) {
		RING_API_RETNUMBER(nNum1);
	}
	else if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			nNum2 = RING_API_GETNUMBER(1) ;
			if ( nNum2 > 0 ) {
				RING_API_RETNUMBER(nNum1 % ++nNum2);
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

void ring_vmlib_timelist ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	List *pList  ;
	pList = RING_API_NEWLIST ;
	time(&timer);
	tm_info = localtime(&timer);
	/*
	**  Add List Items 
	**  abbreviated weekday name 
	*/
	strftime(buffer,25,"%a", tm_info);
	ring_list_addstring(pList,buffer);
	/* full weekday name */
	strftime(buffer,25,"%A", tm_info);
	ring_list_addstring(pList,buffer);
	/* abbreviated month name */
	strftime(buffer,25,"%b", tm_info);
	ring_list_addstring(pList,buffer);
	/* full month name */
	strftime(buffer,25,"%B", tm_info);
	ring_list_addstring(pList,buffer);
	/* Date & Time */
	strftime(buffer,25,"%c", tm_info);
	ring_list_addstring(pList,buffer);
	/* Day of the month */
	strftime(buffer,25,"%d", tm_info);
	ring_list_addstring(pList,buffer);
	/* Hour (24) */
	strftime(buffer,25,"%H", tm_info);
	ring_list_addstring(pList,buffer);
	/* Hour (12) */
	strftime(buffer,25,"%I", tm_info);
	ring_list_addstring(pList,buffer);
	/* Day of the year */
	strftime(buffer,25,"%j", tm_info);
	ring_list_addstring(pList,buffer);
	/* Month of the year */
	strftime(buffer,25,"%m", tm_info);
	ring_list_addstring(pList,buffer);
	/* Minutes after hour */
	strftime(buffer,25,"%M", tm_info);
	ring_list_addstring(pList,buffer);
	/* AM or PM */
	strftime(buffer,25,"%p", tm_info);
	ring_list_addstring(pList,buffer);
	/* Seconds after the hour */
	strftime(buffer,25,"%S", tm_info);
	ring_list_addstring(pList,buffer);
	/* Week of the year (sun-sat) */
	strftime(buffer,25,"%U", tm_info);
	ring_list_addstring(pList,buffer);
	/* day of the week */
	strftime(buffer,25,"%w", tm_info);
	ring_list_addstring(pList,buffer);
	/* date */
	strftime(buffer,25,"%x", tm_info);
	ring_list_addstring(pList,buffer);
	/* time */
	strftime(buffer,25,"%X", tm_info);
	ring_list_addstring(pList,buffer);
	/* year of the century */
	strftime(buffer,25,"%y", tm_info);
	ring_list_addstring(pList,buffer);
	/* year */
	strftime(buffer,25,"%Y", tm_info);
	ring_list_addstring(pList,buffer);
	/* time zone */
	strftime(buffer,25,"%Z", tm_info);
	ring_list_addstring(pList,buffer);
	/* percent sign */
	strftime(buffer,25,"%%", tm_info);
	ring_list_addstring(pList,buffer);
	RING_API_RETLIST(pList);
}

void ring_vmlib_adddays ( void *pPointer )
{
	const char *cStr  ;
	struct tm tm_info  ;
	char buffer[25]  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! (RING_API_ISSTRING(1) && RING_API_ISNUMBER(2)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cStr = RING_API_GETSTRING(1);
	if ( (RING_API_GETSTRINGSIZE(1) == 10) ) {
		if ( isalnum(cStr[0]) && isalnum(cStr[1]) && isalnum(cStr[3]) && isalnum(cStr[4]) && isalnum(cStr[6]) && isalnum(cStr[7]) && isalnum(cStr[8]) && isalnum(cStr[9]) ) {
			tm_info.tm_hour = 0 ;
			tm_info.tm_min = 0 ;
			tm_info.tm_sec = 0 ;
			sprintf( buffer , "%c%c" , cStr[0],cStr[1] ) ;
			tm_info.tm_mday = atoi(buffer) ;
			sprintf( buffer , "%c%c" , cStr[3],cStr[4] ) ;
			tm_info.tm_mon = atoi(buffer)-1 ;
			sprintf( buffer , "%c%c%c%c" , cStr[6],cStr[7],cStr[8],cStr[9] ) ;
			tm_info.tm_year = atoi(buffer) - 1900 ;
			mktime(&tm_info);
			tm_info.tm_mday  += RING_API_GETNUMBER(2) ;
			mktime(&tm_info);
			if ( tm_info.tm_year > 1097 ) {
				/*
				**  1097 + 1900 = 2997 
				**  Values over limit may cause crash 
				*/
				RING_API_ERROR(RING_API_BADPARARANGE);
				return ;
			}
			strftime(buffer,25,"%d/%m/%Y", &tm_info);
			RING_API_RETSTRING(buffer);
			return ;
		}
	}
	RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
}

void ring_vmlib_diffdays ( void *pPointer )
{
	const char *cStr, *cStr2  ;
	struct tm tm_info  ;
	time_t timer,timer2  ;
	char buffer[5]  ;
	double nResult  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! (RING_API_ISSTRING(1) && RING_API_ISSTRING(2)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cStr = RING_API_GETSTRING(1);
	cStr2 = RING_API_GETSTRING(2);
	if ( (RING_API_GETSTRINGSIZE(1) == 10) && (RING_API_GETSTRINGSIZE(2) == 10) ) {
		if ( isalnum(cStr[0]) && isalnum(cStr[1]) && isalnum(cStr[3]) && isalnum(cStr[4]) && isalnum(cStr[6]) && isalnum(cStr[7]) && isalnum(cStr[8]) && isalnum(cStr[9]) ) {
			tm_info.tm_hour = 0 ;
			tm_info.tm_min = 0 ;
			tm_info.tm_sec = 0 ;
			sprintf( buffer , "%c%c" , cStr[0],cStr[1] ) ;
			tm_info.tm_mday = atoi(buffer) ;
			sprintf( buffer , "%c%c" , cStr[3],cStr[4] ) ;
			tm_info.tm_mon = atoi(buffer)-1 ;
			sprintf( buffer , "%c%c%c%c" , cStr[6],cStr[7],cStr[8],cStr[9] ) ;
			tm_info.tm_year = atoi(buffer) - 1900 ;
			timer = mktime(&tm_info);
			if ( tm_info.tm_year > 1097 ) {
				/*
				**  1097 + 1900 = 2997 
				**  Values over limit may cause crash 
				*/
				RING_API_ERROR(RING_API_BADPARARANGE);
				return ;
			}
			if ( isalnum(cStr2[0]) && isalnum(cStr2[1]) && isalnum(cStr2[3]) && isalnum(cStr2[4]) && isalnum(cStr2[6]) && isalnum(cStr2[7]) && isalnum(cStr2[8]) && isalnum(cStr2[9]) ) {
				tm_info.tm_hour = 0 ;
				tm_info.tm_min = 0 ;
				tm_info.tm_sec = 0 ;
				sprintf( buffer , "%c%c" , cStr2[0],cStr2[1] ) ;
				tm_info.tm_mday = atoi(buffer) ;
				sprintf( buffer , "%c%c" , cStr2[3],cStr2[4] ) ;
				tm_info.tm_mon = atoi(buffer)-1 ;
				sprintf( buffer , "%c%c%c%c" , cStr2[6],cStr2[7],cStr2[8],cStr2[9] ) ;
				tm_info.tm_year = atoi(buffer) - 1900 ;
				timer2 = mktime(&tm_info);
				if ( tm_info.tm_year > 1097 ) {
					/*
					**  1097 + 1900 = 2997 
					**  Values over limit may cause crash 
					*/
					RING_API_ERROR(RING_API_BADPARARANGE);
					return ;
				}
				nResult = difftime(timer,timer2);
				nResult  /= 86400 ;
				RING_API_RETNUMBER(nResult);
				return ;
			}
		}
	}
	RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
}
/* Check Data Type */

void ring_vmlib_isstring ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETNUMBER(1);
	} else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vmlib_isnumber ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(1);
	} else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vmlib_islist ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 0 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}

void ring_vmlib_type ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING("STRING");
	}
	else if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETSTRING("NUMBER");
	}
	else if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 0 ) {
			RING_API_RETSTRING("LIST");
		}
		else {
			RING_API_RETSTRING("OBJECT");
		}
	}
	else if ( RING_API_ISPOINTER(1) ) {
		RING_API_RETSTRING(ring_list_getstring(RING_API_GETLIST(1),RING_CPOINTER_TYPE));
	} else {
		RING_API_RETSTRING("UNKNOWN");
	}
}

void ring_vmlib_isnull ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		if ( RING_API_GETPOINTER(1) == NULL ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	else if ( RING_API_ISSTRING(1) ) {
		if ( strcmp(RING_API_GETSTRING(1),"") == 0 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
		else if ( strcmp(RING_API_GETSTRING(1),"NULL") == 0 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}

void ring_vmlib_isobject ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 1 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}
/* Conversion */

void ring_vmlib_hex ( void *pPointer )
{
	char cStr[100]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		sprintf( cStr , "%x" , (int) RING_API_GETNUMBER(1) ) ;
		RING_API_RETSTRING(cStr);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_dec ( void *pPointer )
{
	unsigned int x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		sscanf(RING_API_GETSTRING(1),"%x",&x);
		RING_API_RETNUMBER(x);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_number ( void *pPointer )
{
	double x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		x = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
		RING_API_RETNUMBER(x);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_string ( void *pPointer )
{
	double nNum1  ;
	char cStr[100]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nNum1 = RING_API_GETNUMBER(1);
		ring_vm_numtostring((VM *) pPointer, nNum1,cStr);
		RING_API_RETSTRING(cStr);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_str2hex ( void *pPointer )
{
	char cStr[3]  ;
	unsigned char *cString  ;
	int x,nMax  ;
	char *cString2  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cString = (unsigned char *) RING_API_GETSTRING(1) ;
		nMax = RING_API_GETSTRINGSIZE(1) ;
		cString2 = (char *) malloc(nMax*2) ;
		if ( cString2 == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		for ( x = 1 ; x <= nMax ; x++ ) {
			sprintf( cStr , "%x" , (unsigned int) cString[x-1] ) ;
			cString2[(x-1)*2] = cStr[0] ;
			if ( cStr[1] != '\0' ) {
				cString2[((x-1)*2)+1] = cStr[1] ;
			} else {
				cString2[((x-1)*2)+1] = ' ' ;
			}
		}
		RING_API_RETSTRING2(cString2,nMax*2);
		free( cString2 ) ;
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_hex2str ( void *pPointer )
{
	char cStr[3]  ;
	const char *cString  ;
	char *cString2  ;
	int x,i,nMax  ;
	unsigned int y  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cString = RING_API_GETSTRING(1) ;
		nMax = RING_API_GETSTRINGSIZE(1) ;
		cString2 = (char *) malloc((nMax/2)+1) ;
		if ( cString2 == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		i = 0 ;
		for ( x = 0 ; x < nMax ; x+=2 ) {
			cStr[0] = cString[x] ;
			if ( cString[x+1]   != ' ' ) {
				cStr[1] = cString[x+1] ;
				cStr[2] = '\0' ;
			} else {
				cStr[1] = '\0' ;
			}
			sscanf(cStr,"%x",&y);
			cString2[i] = y ;
			i++ ;
		}
		RING_API_RETSTRING2(cString2,nMax/2);
		free( cString2 ) ;
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_str2list ( void *pPointer )
{
	char *cStr  ;
	int x,nSize,nStart  ;
	List *pList  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		nStart = 0 ;
		pList = RING_API_NEWLIST ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] == '\n' ) {
				if ( x > nStart ) {
					ring_list_addstring2(pList,cStr+nStart,x-nStart);
				} else {
					ring_list_addstring(pList,"");
				}
				nStart = x+1 ;
			}
		}
		if ( nSize > nStart ) {
			ring_list_addstring2(pList,cStr+nStart,nSize-nStart);
		}
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_list2str ( void *pPointer )
{
	List *pList  ;
	String *pString  ;
	int x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1) ;
		pString = ring_string_new("");
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			if ( ring_list_isstring(pList,x) ) {
				if ( x != 1 ) {
					ring_string_add(pString,"\n");
				}
				ring_string_add(pString,ring_list_getstring(pList,x));
				if ( x == ring_list_getsize(pList) ) {
					ring_string_add(pString,"\n");
				}
			}
		}
		RING_API_RETSTRING(ring_string_get(pString));
		ring_string_delete(pString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* String */

void ring_vmlib_left ( void *pPointer )
{
	double nNum1  ;
	const char *cStr  ;
	int x  ;
	char *pString  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			nNum1 = RING_API_GETNUMBER(2) ;
			if ( (nNum1 > 0 ) && (nNum1 <= RING_API_GETSTRINGSIZE(1) ) ) {
				pString = (char *) malloc(nNum1+1) ;
				if ( pString == NULL ) {
					RING_API_ERROR(RING_OOM);
					return ;
				}
				for ( x = 0 ; x < nNum1 ; x++ ) {
					pString[x] = cStr[x] ;
				}
				pString[(int) nNum1] = '\0' ;
				RING_API_RETSTRING2(pString,nNum1);
				free( pString ) ;
			}
		} else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_right ( void *pPointer )
{
	double nNum1  ;
	const char *cStr  ;
	int x,nSize  ;
	char *pString  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			nNum1 = RING_API_GETNUMBER(2) ;
			nSize = RING_API_GETSTRINGSIZE(1) ;
			if ( (nNum1 > 0 ) && (nNum1 <= nSize ) ) {
				pString = (char *) malloc(nNum1+1) ;
				if ( pString == NULL ) {
					RING_API_ERROR(RING_OOM);
					return ;
				}
				/* We start from 0 to copy the NULL character '\0' from the end */
				for ( x = 0 ; x <= nNum1 ; x++ ) {
					pString[((int)nNum1)-x] = cStr[nSize-x] ;
				}
				RING_API_RETSTRING2(pString,nNum1);
				free( pString ) ;
			}
		} else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_trim ( void *pPointer )
{
	const char *cStr  ;
	int x,nSize,nPos1,nPos2  ;
	char *cNewStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		/* Get Limits */
		nPos1 = 0 ;
		nPos2 = nSize ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] != ' ' ) {
				nPos1 = x ;
				break ;
			}
		}
		for ( x = nSize-1 ; x  >= 0 ; x-- ) {
			if ( cStr[x] != ' ' ) {
				nPos2 = x ;
				break ;
			}
		}
		if ( nPos1 == nPos2 ) {
			RING_API_RETSTRING2(cStr,nSize);
			return ;
		}
		/* Create New String */
		cNewStr = (char *) malloc(nPos2-nPos1+1) ;
		for ( x = nPos1 ; x <= nPos2 ; x++ ) {
			cNewStr[x-nPos1] = cStr[x] ;
		}
		RING_API_RETSTRING2(cNewStr,nPos2-nPos1+1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_copy ( void *pPointer )
{
	const char *cStr  ;
	String *pString  ;
	int x,nSize  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			pString = ring_string_new("");
			nSize = RING_API_GETNUMBER(2) ;
			for ( x = 1 ; x <= nSize ; x++ ) {
				ring_string_add2(pString,cStr,RING_API_GETSTRINGSIZE(1));
			}
			RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
			ring_string_delete(pString);
		} else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_substr ( void *pPointer )
{
	char *cStr,*cStr2,*cStr3,*cString  ;
	double nNum1,nNum2  ;
	unsigned int x,nPos,nMark,nSize,nTransform,nSize2  ;
	String *pString  ;
	char cTempStr[2]  ;
	/*
	**  Usage 
	**  Substr(str,10) get substring from 10 to end 
	**  Substr(str,"nice") get position of "nice" inside str 
	**  Substr(str,10,15) get substring from 10 , get 15 characters 
	**  Substr(str,"nice","good") replace "nice" with "good" 
	**  Substr(str,"nice","good",true) replace "nice" with "good" - not case sensitive 
	**  Get String  (First Parameter) 
	*/
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
	} else {
		RING_API_ERROR("Error in first parameter, Function requires string !");
		return ;
	}
	/* Process */
	nTransform = 0 ;
	if ( RING_API_PARACOUNT == 2 ) {
		if ( RING_API_ISNUMBER(2) ) {
			nNum1 = RING_API_GETNUMBER(2) ;
			if ( nNum1 > 0 && nNum1 <= nSize ) {
				cStr2 = cStr + ( (int) nNum1 ) - 1 ;
				RING_API_RETSTRING2(cStr2,nSize-nNum1+1);
				return ;
			}
		}
		else if ( RING_API_ISSTRING(2) ) {
			cStr2 = RING_API_GETSTRING(2) ;
			nSize2 = RING_API_GETSTRINGSIZE(2) ;
			cStr3 = ring_string_find2(cStr,nSize,cStr2,nSize2);
			if ( cStr3 != NULL ) {
				nNum1 = ((int) cStr3) - ((int) cStr) + 1 ;
			} else {
				nNum1 = 0.0 ;
			}
			RING_API_RETNUMBER(nNum1);
		} else {
			RING_API_ERROR("Error in second parameter type!");
			return ;
		}
	}
	else if ( RING_API_PARACOUNT == 3 ) {
		if ( RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) ) {
			nNum1 = RING_API_GETNUMBER(2) ;
			nNum2 = RING_API_GETNUMBER(3) ;
			if ( (nNum1 > 0) && ( (nNum1+nNum2-1) <= nSize ) ) {
				cString = (char *) malloc(nNum2) ;
				if ( cString == NULL ) {
					RING_API_ERROR(RING_OOM);
					return ;
				}
				for ( x = 0 ; x < nNum2 ; x++ ) {
					cString[x] = cStr[((int) nNum1) + x - 1 ] ;
				}
				RING_API_RETSTRING2(cString,nNum2);
				free( cString ) ;
			}
		}
		else if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
			nTransform = 1 ;
		} else {
			RING_API_ERROR("Error in parameters type!");
			return ;
		}
	}
	else if ( RING_API_PARACOUNT == 4 ) {
		if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) && RING_API_ISNUMBER(4) ) {
			if ( RING_API_GETNUMBER(4)  == 1.0 ) {
				nTransform = 2 ;
			}
		} else {
			RING_API_ERROR("Error in parameters type!");
			return ;
		}
	} else {
		RING_API_ERROR("Error in parameters count!");
	}
	/* Transform/Replace */
	if ( nTransform > 0 ) {
		cStr2 = RING_API_GETSTRING(2) ;
		nSize2 = RING_API_GETSTRINGSIZE(2) ;
		/* Search */
		if ( nTransform == 1 ) {
			cString = ring_string_find2(cStr,nSize,cStr2,nSize2) ;
		} else {
			cString = ring_string_find3(cStr,nSize,cStr2,nSize2) ;
		}
		if ( cString == NULL ) {
			RING_API_RETSTRING(cStr);
			return ;
		}
		cStr3 = RING_API_GETSTRING(3) ;
		nMark = 0 ;
		cTempStr[1] = '\0' ;
		pString = ring_string_new("");
		while ( cString != NULL ) {
			nPos = ((int) cString) - ((int) cStr) + 1 ;
			for ( x = nMark ; x < nPos-1 ; x++ ) {
				cTempStr[0] = cStr[x] ;
				ring_string_add2(pString,cTempStr,1);
			}
			ring_string_add2(pString,cStr3,RING_API_GETSTRINGSIZE(3));
			nMark = nPos + nSize2 -1 ;
			/* Search */
			if ( nTransform == 1 ) {
				cString = ring_string_find2(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
			} else {
				cString = ring_string_find3(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
			}
			if ( cString == NULL ) {
				for ( x = nMark ; x < nSize ; x++ ) {
					cTempStr[0] = cStr[x] ;
					ring_string_add2(pString,cTempStr,1);
				}
			}
		}
		RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
		ring_string_delete(pString);
	}
}

void ring_vmlib_lower ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING2(ring_string_lower2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_upper ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING2(ring_string_upper2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_lines ( void *pPointer )
{
	const char *cStr  ;
	int x,nSize,nCount  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		nCount = 1 ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] == '\n' ) {
				nCount++ ;
			}
		}
		RING_API_RETNUMBER(nCount);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_strcmp ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
		RING_API_RETNUMBER(strcmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Functional */

void ring_vmlib_eval ( void *pPointer )
{
	const char *cStr  ;
	VM *pVM  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1);
		pVM = (VM *) pPointer ;
		pVM->nEvalCalledFromRingCode = 1 ;
		ring_vm_eval(pVM,cStr);
		/*
		**  The CALL instruction will check nEvalCalledFromRingCode to execute the main loop again 
		**  Before executing the main loop again, The CALL instruction will set nEvalCalledFromRingCode to 0 
		*/
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Error Handling */

void ring_vmlib_raise ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_GETSTRING(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_assert ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) != 1 ) {
			RING_API_ERROR("Assertion Failed!");
			return ;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Check Characters */

void ring_vmlib_isfunc ( void *pPointer,int (*pFunc)(int) )
{
	char *cStr  ;
	int nSize,x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( ! (*pFunc)(cStr[x]) ) {
				RING_API_RETNUMBER(0);
				return ;
			}
		}
		RING_API_RETNUMBER(1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_isalnum ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isalnum);
}

void ring_vmlib_isalpha ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isalpha);
}

void ring_vmlib_iscntrl ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,iscntrl);
}

void ring_vmlib_isdigit ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isdigit);
}

void ring_vmlib_isgraph ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isgraph);
}

void ring_vmlib_islower ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,islower);
}

void ring_vmlib_isprint ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isprint);
}

void ring_vmlib_ispunct ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,ispunct);
}

void ring_vmlib_isspace ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isspace);
}

void ring_vmlib_isupper ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isupper);
}

void ring_vmlib_isxdigit ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isxdigit);
}
/* Garbage Collector & Variable Pointer */

void ring_vmlib_callgc ( void *pPointer )
{
	ring_vm_gc_deletetemplists((VM *) pPointer);
}

void ring_vmlib_varptr ( void *pPointer )
{
	const char *cStr , *cStr2  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
		cStr = RING_API_GETSTRING(1);
		cStr2 = RING_API_GETSTRING(2);
		RING_API_RETCPOINTER(ring_vm_api_varptr(pPointer,cStr,cStr2),cStr2);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_intvalue ( void *pPointer )
{
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1);
		ring_vm_api_intvalue(pPointer,cStr);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
