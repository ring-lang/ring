/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Load Functions */

RING_API void ring_vm_generallib_loadfunctions ( RingState *pRingState )
{
    /* General */
    RING_API_REGISTER("len",ring_vm_generallib_len);
    RING_API_REGISTER("clock",ring_vm_generallib_clock);
    RING_API_REGISTER("lower",ring_vm_generallib_lower);
    RING_API_REGISTER("upper",ring_vm_generallib_upper);
    RING_API_REGISTER("input",ring_vm_generallib_input);
    RING_API_REGISTER("ascii",ring_vm_generallib_ascii);
    RING_API_REGISTER("char",ring_vm_generallib_char);
    RING_API_REGISTER("date",ring_vm_generallib_date);
    RING_API_REGISTER("time",ring_vm_generallib_time);
    RING_API_REGISTER("filename",ring_vm_generallib_filename);
    RING_API_REGISTER("getchar",ring_vm_generallib_getchar);
    RING_API_REGISTER("random",ring_vm_generallib_random);
    RING_API_REGISTER("timelist",ring_vm_generallib_timelist);
    RING_API_REGISTER("adddays",ring_vm_generallib_adddays);
    RING_API_REGISTER("diffdays",ring_vm_generallib_diffdays);
    RING_API_REGISTER("version",ring_vm_generallib_version);
    RING_API_REGISTER("clockspersecond",ring_vm_generallib_clockspersecond);
    RING_API_REGISTER("prevfilename",ring_vm_generallib_prevfilename);
    RING_API_REGISTER("srandom",ring_vm_generallib_srandom);
    /* Check Data Type */
    RING_API_REGISTER("isstring",ring_vm_generallib_isstring);
    RING_API_REGISTER("isnumber",ring_vm_generallib_isnumber);
    RING_API_REGISTER("islist",ring_vm_generallib_islist);
    RING_API_REGISTER("type",ring_vm_generallib_type);
    RING_API_REGISTER("isnull",ring_vm_generallib_isnull);
    RING_API_REGISTER("isobject",ring_vm_generallib_isobject);
    RING_API_REGISTER("ispointer",ring_vm_generallib_ispointer);
    /* Conversion */
    RING_API_REGISTER("hex",ring_vm_generallib_hex);
    RING_API_REGISTER("dec",ring_vm_generallib_dec);
    RING_API_REGISTER("number",ring_vm_generallib_number);
    RING_API_REGISTER("string",ring_vm_generallib_string);
    RING_API_REGISTER("str2hex",ring_vm_generallib_str2hex);
    RING_API_REGISTER("hex2str",ring_vm_generallib_hex2str);
    RING_API_REGISTER("str2list",ring_vm_generallib_str2list);
    RING_API_REGISTER("list2str",ring_vm_generallib_list2str);
    RING_API_REGISTER("str2hexcstyle",ring_vm_generallib_str2hexcstyle);
    /* String */
    RING_API_REGISTER("left",ring_vm_generallib_left);
    RING_API_REGISTER("right",ring_vm_generallib_right);
    RING_API_REGISTER("trim",ring_vm_generallib_trim);
    RING_API_REGISTER("copy",ring_vm_generallib_copy);
    RING_API_REGISTER("substr",ring_vm_generallib_substr);
    RING_API_REGISTER("lines",ring_vm_generallib_lines);
    RING_API_REGISTER("strcmp",ring_vm_generallib_strcmp);
    /* Functional */
    RING_API_REGISTER("eval",ring_vm_generallib_eval);
    /* Error Handling */
    RING_API_REGISTER("raise",ring_vm_generallib_raise);
    RING_API_REGISTER("assert",ring_vm_generallib_assert);
    /* Check Characters */
    RING_API_REGISTER("isalnum",ring_vm_generallib_isalnum);
    RING_API_REGISTER("isalpha",ring_vm_generallib_isalpha);
    RING_API_REGISTER("iscntrl",ring_vm_generallib_iscntrl);
    RING_API_REGISTER("isdigit",ring_vm_generallib_isdigit);
    RING_API_REGISTER("isgraph",ring_vm_generallib_isgraph);
    RING_API_REGISTER("islower",ring_vm_generallib_islower);
    RING_API_REGISTER("isprint",ring_vm_generallib_isprint);
    RING_API_REGISTER("ispunct",ring_vm_generallib_ispunct);
    RING_API_REGISTER("isspace",ring_vm_generallib_isspace);
    RING_API_REGISTER("isupper",ring_vm_generallib_isupper);
    RING_API_REGISTER("isxdigit",ring_vm_generallib_isxdigit);
    /* Garbage Collector & Variable Pointer */
    RING_API_REGISTER("callgc",ring_vm_generallib_callgc);
    RING_API_REGISTER("varptr",ring_vm_generallib_varptr);
    RING_API_REGISTER("intvalue",ring_vm_generallib_intvalue);
    RING_API_REGISTER("object2pointer",ring_vm_generallib_object2pointer);
    RING_API_REGISTER("pointer2object",ring_vm_generallib_pointer2object);
    RING_API_REGISTER("nullpointer",ring_vm_generallib_nullpointer);
    RING_API_REGISTER("space",ring_vm_generallib_space);
    RING_API_REGISTER("ptrcmp",ring_vm_generallib_ptrcmp);
    RING_API_REGISTER("pointer2string",ring_vm_generallib_pointer2string);
    RING_API_REGISTER("setpointer",ring_vm_generallib_setpointer);
    RING_API_REGISTER("getpointer",ring_vm_generallib_getpointer);
    RING_API_REGISTER("memcpy",ring_vm_generallib_memcpy);
    RING_API_REGISTER("callgarbagecollector",ring_vm_generallib_callgc);
    RING_API_REGISTER("variablepointer",ring_vm_generallib_varptr);
    RING_API_REGISTER("obj2ptr",ring_vm_generallib_object2pointer);
    RING_API_REGISTER("ptr2obj",ring_vm_generallib_pointer2object);
    RING_API_REGISTER("nullptr",ring_vm_generallib_nullpointer);
    RING_API_REGISTER("pointercompare",ring_vm_generallib_ptrcmp);
    RING_API_REGISTER("ptr2str",ring_vm_generallib_pointer2string);
    RING_API_REGISTER("setptr",ring_vm_generallib_setpointer);
    RING_API_REGISTER("getptr",ring_vm_generallib_getpointer);
    RING_API_REGISTER("memorycopy",ring_vm_generallib_memcpy);
    /* Ring State */
    RING_API_REGISTER("ring_state_init",ring_vm_generallib_state_init);
    RING_API_REGISTER("ring_state_runcode",ring_vm_generallib_state_runcode);
    RING_API_REGISTER("ring_state_delete",ring_vm_generallib_state_delete);
    RING_API_REGISTER("ring_state_runfile",ring_vm_generallib_state_runfile);
    RING_API_REGISTER("ring_state_findvar",ring_vm_generallib_state_findvar);
    RING_API_REGISTER("ring_state_newvar",ring_vm_generallib_state_newvar);
    RING_API_REGISTER("ring_state_runobjectfile",ring_vm_generallib_state_runobjectfile);
    RING_API_REGISTER("ring_state_main",ring_vm_generallib_state_main);
    RING_API_REGISTER("ring_state_setvar",ring_vm_generallib_state_setvar);
    RING_API_REGISTER("ring_state_new",ring_vm_generallib_state_new);
    RING_API_REGISTER("ring_state_mainfile",ring_vm_generallib_state_mainfile);
    RING_API_REGISTER("ring_state_filetokens",ring_vm_generallib_state_filetokens);
    RING_API_REGISTER("ring_state_stringtokens",ring_vm_generallib_state_stringtokens);
    RING_API_REGISTER("ring_state_scannererror",ring_vm_generallib_state_scannererror);
    /* Performance */
    RING_API_REGISTER("checkoverflow",ring_vm_generallib_checkoverflow);
    RING_API_REGISTER("addsublistsbymove",ring_vm_generallib_addsublistsbymove);
    RING_API_REGISTER("addsublistsbyfastcopy",ring_vm_generallib_addsublistsbyfastcopy);
    /*
    **  Ring See and Give 
    **  We will use ringvm_see() and ringvm_give() to change the behavior of see and give 
    **  Also we can use ring_see() and ring_give() to use the original behavior when we redefine it 
    */
    RING_API_REGISTER("ringvm_see",ring_vm_generallib_see);
    RING_API_REGISTER("ringvm_give",ring_vm_generallib_give);
    RING_API_REGISTER("ring_see",ring_vm_generallib_see);
    RING_API_REGISTER("ring_give",ring_vm_generallib_give);
    RING_API_REGISTER("print",ring_vm_generallib_print);
    RING_API_REGISTER("print2str",ring_vm_generallib_print2str);
    RING_API_REGISTER("puts",ring_vm_generallib_puts);
    RING_API_REGISTER("getstring",ring_vm_generallib_give);
    RING_API_REGISTER("getnumber",ring_vm_generallib_getnumber);
}
/*
**  Library Functions 
**  General 
*/

void ring_vm_generallib_len ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        RING_API_RETNUMBER(RING_API_GETSTRINGSIZE(1));
    }
    else if ( RING_API_ISLIST(1) ) {
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
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_clock ( void *pPointer )
{
    clock_t nNum1  ;
    nNum1 = clock();
    RING_API_RETNUMBER((double) nNum1);
}

void ring_vm_generallib_input ( void *pPointer )
{
    char *cLine  ;
    int nSize,nOutput  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        nSize = RING_API_GETNUMBER(1);
    }
    else if ( RING_API_ISSTRING(1) ) {
        nSize = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    if ( nSize > 0 ) {
        cLine = (char *) RING_API_MALLOC(nSize);
        /* Get Input From the User and save it in the variable */
        nOutput = RING_SETBINARY ;
        fread( cLine , sizeof(char) , nSize , stdin );
        /* Return String */
        RING_API_RETSTRING2(cLine,nSize);
        RING_API_FREE(cLine);
    }
    else {
        RING_API_ERROR("Error in first parameter,  input size < 1 !");
    }
}

void ring_vm_generallib_ascii ( void *pPointer )
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
        }
        else {
            RING_API_ERROR("Error in first parameter, the string size is not one letter !");
            return ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_char ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_date ( void *pPointer )
{
    time_t timer  ;
    char buffer[25]  ;
    struct tm*tm_info  ;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer,25,"%d/%m/%Y", tm_info);
    RING_API_RETSTRING(buffer);
}

void ring_vm_generallib_time ( void *pPointer )
{
    time_t timer  ;
    char buffer[25]  ;
    struct tm*tm_info  ;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer,25,"%H:%M:%S", tm_info);
    RING_API_RETSTRING(buffer);
}

void ring_vm_generallib_filename ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    int lFunctionCall,x  ;
    const char *cOldFile  ;
    const char *cFile  ;
    pVM = (VM *) pPointer ;
    /* Get the current file name */
    cOldFile = NULL ;
    cFile = NULL ;
    lFunctionCall = 0 ;
    for ( x = ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
        pList = ring_list_getlist(pVM->pFuncCallList,x);
        /*
        **  If we have ICO_LoadFunc but not ICO_CALL then we need to pass 
        **  ICO_LOADFUNC is executed, but still ICO_CALL is not executed! 
        */
        if ( ring_list_getsize(pList) < RING_FUNCCL_CALLERPC ) {
            cOldFile = (const char *) ring_list_getpointer(pList,RING_FUNCCL_FILENAME) ;
            continue ;
        }
        if ( ring_list_getint(pList,RING_FUNCCL_TYPE) == RING_FUNCTYPE_SCRIPT ) {
            lFunctionCall = 1 ;
        }
    }
    if ( lFunctionCall ) {
        cFile = ring_list_getstring(pVM->pRingState->pRingFilesList,1) ;
    }
    else {
        if ( pVM->nInClassRegion ) {
            cFile = pVM->cFileNameInClassRegion ;
        }
        else {
            if ( cOldFile == NULL ) {
                cFile = pVM->cFileName ;
            }
            else {
                cFile = cOldFile ;
            }
        }
    }
    RING_API_RETSTRING(cFile);
}

void ring_vm_generallib_getchar ( void *pPointer )
{
    char cStr[2]  ;
    int nOutput  ;
    nOutput = RING_SETBINARY ;
    cStr[0] = getchar() ;
    RING_API_RETSTRING2(cStr,1);
}
/* 31 bit thread unsafe random generator using the seed (srand) */

void ring_vm_generallib_random ( void *pPointer )
{
    int nNum1,nNum2  ;
    nNum1 = rand() ;
    #ifdef _MSC_VER
        rand_s(&nNum2);
        nNum1 |= ( nNum2 & 0xFFFF ) << 15 ;
    #endif
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

void ring_vm_generallib_timelist ( void *pPointer )
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
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* full weekday name */
    strftime(buffer,25,"%A", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* abbreviated month name */
    strftime(buffer,25,"%b", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* full month name */
    strftime(buffer,25,"%B", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Date & Time */
    strftime(buffer,25,"%c", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Day of the month */
    strftime(buffer,25,"%d", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Hour (24) */
    strftime(buffer,25,"%H", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Hour (12) */
    strftime(buffer,25,"%I", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Day of the year */
    strftime(buffer,25,"%j", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Month of the year */
    strftime(buffer,25,"%m", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Minutes after hour */
    strftime(buffer,25,"%M", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* AM or PM */
    strftime(buffer,25,"%p", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Seconds after the hour */
    strftime(buffer,25,"%S", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* Week of the year (sun-sat) */
    strftime(buffer,25,"%U", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* day of the week */
    strftime(buffer,25,"%w", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* date */
    strftime(buffer,25,"%x", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* time */
    strftime(buffer,25,"%X", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* year of the century */
    strftime(buffer,25,"%y", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* year */
    strftime(buffer,25,"%Y", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* time zone */
    strftime(buffer,25,"%Z", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    /* percent sign */
    strftime(buffer,25,"%%", tm_info);
    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
    RING_API_RETLIST(pList);
}

void ring_vm_generallib_adddays ( void *pPointer )
{
    const unsigned char *cStr  ;
    char buffer[25]  ;
    int x,nDay,nMonth,nYear,nDaysInMonth  ;
    int aDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( ! (RING_API_ISSTRING(1) && RING_API_ISNUMBER(2)) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    cStr = (const unsigned char *) RING_API_GETSTRING(1) ;
    if ( (RING_API_GETSTRINGSIZE(1) == 10) ) {
        if ( isalnum(cStr[0]) && isalnum(cStr[1]) && isalnum(cStr[3]) && isalnum(cStr[4]) && isalnum(cStr[6]) && isalnum(cStr[7]) && isalnum(cStr[8]) && isalnum(cStr[9]) ) {
            sprintf( buffer , "%c%c" , cStr[0],cStr[1] ) ;
            nDay = atoi(buffer) + ((int) RING_API_GETNUMBER(2)) ;
            sprintf( buffer , "%c%c" , cStr[3],cStr[4] ) ;
            nMonth = atoi(buffer) ;
            sprintf( buffer , "%c%c%c%c" , cStr[6],cStr[7],cStr[8],cStr[9] ) ;
            nYear = atoi(buffer) ;
            /* Fix Day Number */
            nDaysInMonth = aDaysInMonth[nMonth-1] ;
            /* Fix Leap Year */
            if ( (nMonth == 2) && (ring_vm_generallib_adddays_isleapyear(nYear)) ) {
                nDaysInMonth = 29 ;
            }
            while ( nDay > nDaysInMonth ) {
                nDay = nDay - nDaysInMonth ;
                nMonth++ ;
                if ( nMonth == 13 ) {
                    nMonth = 1 ;
                    nYear++ ;
                }
                nDaysInMonth = aDaysInMonth[nMonth-1] ;
                /* Fix Leap Year */
                if ( (nMonth == 2) && (ring_vm_generallib_adddays_isleapyear(nYear)) ) {
                    nDaysInMonth = 29 ;
                }
            }
            while ( nDay < 1 ) {
                nMonth-- ;
                if ( nMonth == 0 ) {
                    nMonth = 12 ;
                    nYear-- ;
                }
                nDaysInMonth = aDaysInMonth[nMonth-1] ;
                /* Fix Leap Year */
                if ( (nMonth == 2) && (ring_vm_generallib_adddays_isleapyear(nYear)) ) {
                    nDaysInMonth = 29 ;
                }
                nDay = nDaysInMonth - abs(nDay) ;
            }
            sprintf(buffer,"%2d/%2d/%4d", nDay,nMonth,nYear);
            for ( x = 0 ; x <= 9 ; x++ ) {
                if ( buffer[x] == ' ' ) {
                    buffer[x] = '0' ;
                }
            }
            RING_API_RETSTRING(buffer);
            return ;
        }
    }
    RING_API_ERROR(RING_API_BADPARATYPE);
    return ;
}

void ring_vm_generallib_diffdays ( void *pPointer )
{
    const unsigned char *cStr, *cStr2  ;
    struct tm tm_info,tm_info2  ;
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
    cStr = (const unsigned char *) RING_API_GETSTRING(1) ;
    cStr2 = (const unsigned char *) RING_API_GETSTRING(2) ;
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
                tm_info2.tm_hour = 0 ;
                tm_info2.tm_min = 0 ;
                tm_info2.tm_sec = 0 ;
                sprintf( buffer , "%c%c" , cStr2[0],cStr2[1] ) ;
                tm_info2.tm_mday = atoi(buffer) ;
                sprintf( buffer , "%c%c" , cStr2[3],cStr2[4] ) ;
                tm_info2.tm_mon = atoi(buffer)-1 ;
                sprintf( buffer , "%c%c%c%c" , cStr2[6],cStr2[7],cStr2[8],cStr2[9] ) ;
                tm_info2.tm_year = atoi(buffer) - 1900 ;
                timer2 = mktime(&tm_info2);
                if ( tm_info2.tm_year > 1097 ) {
                    /*
                    **  1097 + 1900 = 2997 
                    **  Values over limit may cause crash 
                    */
                    RING_API_ERROR(RING_API_BADPARARANGE);
                    return ;
                }
                nResult = difftime(timer,timer2);
                nResult  = ceil(ceil(nResult) / 86400 ) ;
                RING_API_RETNUMBER(nResult);
                return ;
            }
        }
    }
    RING_API_ERROR(RING_API_BADPARATYPE);
    return ;
}

void ring_vm_generallib_version ( void *pPointer )
{
    RING_API_RETSTRING(RING_STATE_VERSION);
}

void ring_vm_generallib_clockspersecond ( void *pPointer )
{
    RING_API_RETNUMBER(CLOCKS_PER_SEC);
}

void ring_vm_generallib_prevfilename ( void *pPointer )
{
    RING_API_RETSTRING(((VM *) pPointer)->cPrevFileName);
}

int ring_vm_generallib_adddays_isleapyear ( int nYear )
{
    if ( nYear%400 == 0 ) {
        return 1 ;
    }
    if ( nYear%100 == 0 ) {
        return 0 ;
    }
    return nYear % 4 == 0 ;
}

void ring_vm_generallib_srandom ( void *pPointer )
{
    int nNum1  ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISNUMBER(1) ) {
            nNum1 = RING_API_GETNUMBER(1) ;
            if ( nNum1 >= 0 ) {
                srand(nNum1);
            }
            else {
                RING_API_ERROR(RING_API_BADPARARANGE);
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
/* Check Data Type */

void ring_vm_generallib_isstring ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        RING_API_RETNUMBER(1);
    }
    else {
        RING_API_RETNUMBER(0);
    }
}

void ring_vm_generallib_isnumber ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        RING_API_RETNUMBER(1);
    }
    else {
        RING_API_RETNUMBER(0);
    }
}

void ring_vm_generallib_islist ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        if ( (ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 0) && (RING_API_ISCPOINTER(1) == 0) ) {
            RING_API_RETNUMBER(1);
            return ;
        }
    }
    RING_API_RETNUMBER(0);
}

void ring_vm_generallib_type ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    /* The order of checking C Pointer and OBJECT before List is important because the list can be both of */
    if ( RING_API_ISSTRING(1) ) {
        RING_API_RETSTRING("STRING");
    }
    else if ( RING_API_ISNUMBER(1) ) {
        RING_API_RETSTRING("NUMBER");
    }
    else if ( RING_API_ISCPOINTER(1) ) {
        pList = RING_API_GETLIST(1) ;
        RING_API_RETSTRING(ring_list_getstring(pList,RING_CPOINTER_TYPE));
    }
    else if ( RING_API_ISOBJECT(1) ) {
        RING_API_RETSTRING("OBJECT");
    }
    else if ( RING_API_ISLIST(1) ) {
        RING_API_RETSTRING("LIST");
    }
    else {
        RING_API_RETSTRING("UNKNOWN");
    }
}

void ring_vm_generallib_isnull ( void *pPointer )
{
    char *cStr  ;
    RING_API_IGNORECPOINTERTYPE ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        if ( strcmp(RING_API_GETSTRING(1),"") == 0 ) {
            RING_API_RETNUMBER(1);
            return ;
        }
        else if ( RING_API_GETSTRINGSIZE(1) == 4 ) {
            cStr = RING_API_GETSTRING(1) ;
            if ( (cStr[0] == 'n' || cStr[0] == 'N') && (cStr[1] == 'u' || cStr[1] == 'U') && (cStr[2] == 'l' || cStr[2] == 'L') && (cStr[3] == 'l' || cStr[3] == 'L') ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
    }
    else if ( RING_API_ISCPOINTER(1) ) {
        if ( ring_list_getpointer(RING_API_GETLIST(1),RING_CPOINTER_POINTER) == NULL ) {
            RING_API_RETNUMBER(1);
            return ;
        }
    }
    RING_API_RETNUMBER(0);
}

void ring_vm_generallib_isobject ( void *pPointer )
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

void ring_vm_generallib_ispointer ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        if ( RING_API_ISCPOINTER(1) ) {
            RING_API_RETNUMBER(1);
            return ;
        }
    }
    RING_API_RETNUMBER(0);
}
/* Conversion */

void ring_vm_generallib_hex ( void *pPointer )
{
    char cStr[100]  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        sprintf( cStr , RING_UNSIGNEDLONGLONG_FORMAT , (RING_UNSIGNEDLONGLONG) RING_API_GETNUMBER(1) ) ;
        RING_API_RETSTRING(cStr);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_dec ( void *pPointer )
{
    RING_UNSIGNEDLONGLONG x  ;
    int nOutput  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        nOutput = sscanf(RING_API_GETSTRING(1),RING_UNSIGNEDLONGLONG_FORMAT,&x);
        /* Display error if nOutput is Zero which means that sscanf() function failed to convert any character */
        if ( (nOutput == EOF) || (nOutput == 0) ) {
            RING_API_ERROR(RING_SSCANFERROR);
            return ;
        }
        RING_API_RETNUMBER(x);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_number ( void *pPointer )
{
    double x  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        x = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
        RING_API_RETNUMBER(x);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_string ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_str2hex ( void *pPointer )
{
    unsigned char *cString  ;
    int x,nMax  ;
    char *cString2  ;
    unsigned char bVal  ;
    static const char cHexChars[] = "0123456789abcdef" ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        cString = (unsigned char *) RING_API_GETSTRING(1) ;
        nMax = RING_API_GETSTRINGSIZE(1) ;
        /* Pre-allocated the return value on the stack */
        RING_API_RETSTRINGSIZE(nMax*2);
        cString2 = ring_string_get(RING_API_GETSTRINGRAW);
        for ( x = 1 ; x <= nMax ; x++ ) {
            bVal = cString[x-1] ;
            cString2[(x-1)*2] = cHexChars[bVal >> 4] ;
            cString2[((x-1)*2)+1] = cHexChars[bVal & 0x0F] ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

unsigned char ring_vm_generallib_hex2str_hex2nibble ( char cVal )
{
    unsigned char bVal = 0 ;
    if ( cVal >= '0' && cVal <= '9' ) {
        bVal = cVal - '0' ;
    }
    else if ( cVal >= 'a' && cVal <= 'f' ) {
        bVal = cVal - 'a' + 10 ;
    }
    else if ( cVal >= 'A' && cVal <= 'F' ) {
        bVal = cVal - 'A' + 10 ;
    }
    else {
        bVal = 0xFF ;
    }
    return bVal ;
}

void ring_vm_generallib_hex2str ( void *pPointer )
{
    char cStr[3]  ;
    const char *cString  ;
    char *cString2  ;
    int x,i,nMax  ;
    unsigned char bVal, bNibble  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        cString = RING_API_GETSTRING(1) ;
        nMax = RING_API_GETSTRINGSIZE(1) ;
        /* Check the String Size (The implementation expects even number of characters) */
        if ( nMax % 2 != 0 ) {
            RING_API_ERROR(RING_API_BADPARALENGTH);
            return ;
        }
        /* Pre-allocated the return value on the stack */
        RING_API_RETSTRINGSIZE(nMax/2);
        cString2 = ring_string_get(RING_API_GETSTRINGRAW);
        i = 0 ;
        for ( x = 0 ; x < nMax ; x+=2 ) {
            bNibble = ring_vm_generallib_hex2str_hex2nibble(cString[x]);
            if ( bNibble != 0xFF ) {
                bVal = bNibble ;
                if ( cString[x+1]   != ' ' ) {
                    bNibble = ring_vm_generallib_hex2str_hex2nibble(cString[x+1]);
                    if ( bNibble != 0xFF ) {
                        bVal = (bVal << 4) + bNibble ;
                    }
                }
            }
            if ( bNibble == 0xFF ) {
                RING_API_ERROR(RING_API_BADPARAVALUE);
                return ;
            }
            cString2[i] = (char) bVal ;
            i++ ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_str2list ( void *pPointer )
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
                    if ( cStr[x-1] == '\r' ) {
                        ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,x-nStart-1);
                    }
                    else {
                        ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,x-nStart);
                    }
                }
                else {
                    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,"");
                }
                nStart = x+1 ;
            }
        }
        if ( nSize > nStart ) {
            ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,nSize-nStart);
        }
        RING_API_RETLIST(pList);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_list2str ( void *pPointer )
{
    List *pList  ;
    String *pString  ;
    int x  ;
    char cStr[100]  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        pString = ring_string_new_gc(((VM *) pPointer)->pRingState,"");
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            if ( ring_list_isstring(pList,x) ) {
                if ( x != 1 ) {
                    ring_string_add_gc(((VM *) pPointer)->pRingState,pString,"\n");
                }
                ring_string_add_gc(((VM *) pPointer)->pRingState,pString,ring_list_getstring(pList,x));
            }
            else if ( ring_list_isnumber(pList,x) ) {
                if ( x != 1 ) {
                    ring_string_add_gc(((VM *) pPointer)->pRingState,pString,"\n");
                }
                ring_vm_numtostring((VM *) pPointer,ring_list_getdouble(pList,x) ,cStr);
                ring_string_add_gc(((VM *) pPointer)->pRingState,pString,cStr);
            }
        }
        RING_API_RETSTRING(ring_string_get(pString));
        ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_str2hexcstyle ( void *pPointer )
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
        cString2 = (char *) RING_API_MALLOC(nMax*5);
        for ( x = 1 ; x <= nMax ; x++ ) {
            sprintf( cStr , "%x" , (unsigned char) cString[x-1] ) ;
            /* Separator */
            cString2[(x-1)*5] = ',' ;
            cString2[(x-1)*5+1] = '0' ;
            cString2[(x-1)*5+2] = 'x' ;
            cString2[(x-1)*5+3] = cStr[0] ;
            if ( cStr[1] != '\0' ) {
                cString2[((x-1)*5)+4] = cStr[1] ;
            }
            else {
                cString2[((x-1)*5)+4] = ' ' ;
            }
        }
        /* Pass the first letter to avoid the first comma */
        cString2++ ;
        RING_API_RETSTRING2(cString2,nMax*5-1);
        /* When we call free() we use the original pointer */
        cString2-- ;
        RING_API_FREE(cString2);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
/* String */

void ring_vm_generallib_left ( void *pPointer )
{
    double nNum1  ;
    const char *cStr  ;
    int x,nNewSize  ;
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
                nNewSize = (int) nNum1 ;
                /* Pre-allocated the return value on the stack */
                RING_API_RETSTRINGSIZE(nNewSize);
                pString = ring_string_get(RING_API_GETSTRINGRAW);
                RING_MEMCPY(pString,cStr,nNewSize);
            }
        }
        else {
            RING_API_ERROR("Error in second parameter, Function requires number !");
            return ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_right ( void *pPointer )
{
    double nNum1  ;
    const char *cStr  ;
    int x,nSize,nNewSize  ;
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
                nNewSize = (int) nNum1 ;
                /* Pre-allocated the return value on the stack */
                RING_API_RETSTRINGSIZE(nNewSize);
                pString = ring_string_get(RING_API_GETSTRINGRAW);
                RING_MEMCPY(pString,cStr+(nSize-nNewSize),nNewSize);
            }
        }
        else {
            RING_API_ERROR("Error in second parameter, Function requires number !");
            return ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_trim ( void *pPointer )
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
        if ( nSize == 0 ) {
            RING_API_RETSTRING("");
            return ;
        }
        /* Get Limits */
        nPos1 = 0 ;
        nPos2 = nSize-1 ;
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
        if ( (nPos1 == 0) && (nPos2 == nSize-1) && (cStr[0] == ' ') ) {
            RING_API_RETSTRING("");
            return ;
        }
        /* Pre-allocated the return value on the stack */
        RING_API_RETSTRINGSIZE(nPos2-nPos1+1);
        cNewStr = ring_string_get(RING_API_GETSTRINGRAW);
        if ( nPos2-nPos1+1 < RING_LOOP_THRESHOLD ) {
            for ( x = nPos1 ; x <= nPos2 ; x++ ) {
                cNewStr[x-nPos1] = cStr[x] ;
            }
        }
        else {
            memcpy(cNewStr,cStr+nPos1, nPos2-nPos1+1);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_copy ( void *pPointer )
{
    const char *cStr  ;
    int x,nSize,nStrSize,nPos,i  ;
    char *cRetStr  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        if ( RING_API_ISNUMBER(2) ) {
            cStr = RING_API_GETSTRING(1) ;
            nStrSize = RING_API_GETSTRINGSIZE(1) ;
            nSize = RING_API_GETNUMBER(2) ;
            if ( nSize > 0 ) {
                /* Pre-allocated the return value on the stack */
                RING_API_RETSTRINGSIZE(nSize * nStrSize);
                cRetStr = ring_string_get(RING_API_GETSTRINGRAW);
                nPos = 0 ;
                /* Copy the input string nSize times */
                for ( i = 1 ; i <= nSize ; i++ ) {
                    RING_MEMCPY(cRetStr+nPos,cStr,nStrSize);
                    nPos += nStrSize ;
                }
            }
        }
        else {
            RING_API_ERROR("Error in second parameter, Function requires number !");
            return ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_substr ( void *pPointer )
{
    char *cStr,*cStr2,*cStr3,*cString  ;
    double nNum1,nNum2  ;
    unsigned int nParaCount,x,nPos,nMark,nSize,nTransform,nSize2  ;
    String *pString  ;
    /*
    **  Usage 
    **  Substr(str,10) get substring from 10 to end 
    **  Substr(str,"nice") get position of "nice" inside str 
    **  Substr(str,10,15) get substring from 10 , get 15 characters 
    **  Substr(str,"nice","good") replace "nice" with "good" 
    **  Substr(str,"nice","good",true) replace "nice" with "good" - not case sensitive 
    **  Parameters Count 
    */
    nParaCount = RING_API_PARACOUNT ;
    /* If parameter no. 4 is not True, Treat the case as we get 3 paramters only */
    if ( nParaCount == 4 ) {
        if ( RING_API_ISNUMBER(4) ) {
            if ( RING_API_GETNUMBER(4)  == 0.0 ) {
                nParaCount = 3 ;
            }
        }
    }
    /* Get String  (First Parameter) */
    if ( RING_API_ISSTRING(1) ) {
        cStr = RING_API_GETSTRING(1) ;
        nSize = RING_API_GETSTRINGSIZE(1) ;
    }
    else {
        RING_API_ERROR("Error in first parameter, Function requires string !");
        return ;
    }
    /* Process */
    nTransform = 0 ;
    if ( nParaCount == 2 ) {
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
                nNum1 = (RING_LONGLONG) ( 1 + (cStr3 - cStr) ) ;
            }
            else {
                nNum1 = 0.0 ;
            }
            RING_API_RETNUMBER(nNum1);
        }
        else {
            RING_API_ERROR("Error in second parameter type!");
            return ;
        }
    }
    else if ( nParaCount == 3 ) {
        if ( RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) ) {
            nNum1 = RING_API_GETNUMBER(2) ;
            nNum2 = RING_API_GETNUMBER(3) ;
            if ( (nNum1 > 0) && ( nNum1 <= nSize ) ) {
                if ( (nNum2 > 0) && ( (nNum1+nNum2-1) <= nSize ) ) {
                    cString = (char *) RING_API_MALLOC(nNum2);
                    for ( x = 0 ; x < nNum2 ; x++ ) {
                        cString[x] = cStr[((int) nNum1) + x - 1 ] ;
                    }
                    RING_API_RETSTRING2(cString,nNum2);
                    RING_API_FREE(cString);
                }
            }
        }
        else if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
            nTransform = 1 ;
        }
        else {
            RING_API_ERROR("Error in parameters type!");
            return ;
        }
    }
    else if ( nParaCount == 4 ) {
        if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) && RING_API_ISNUMBER(4) ) {
            if ( RING_API_GETNUMBER(4)  == 1.0 ) {
                nTransform = 2 ;
            }
        }
        else {
            RING_API_ERROR("Error in parameters type!");
            return ;
        }
    }
    else {
        RING_API_ERROR("Error in parameters count!");
    }
    /* Transform/Replace */
    if ( nTransform > 0 ) {
        cStr2 = RING_API_GETSTRING(2) ;
        nSize2 = RING_API_GETSTRINGSIZE(2) ;
        if ( nSize2 == 0 ) {
            RING_API_ERROR("Error in second parameter value!");
            return ;
        }
        /* Search */
        if ( nTransform == 1 ) {
            cString = ring_string_find2(cStr,nSize,cStr2,nSize2) ;
        }
        else {
            cString = ring_string_find3(cStr,nSize,cStr2,nSize2) ;
        }
        if ( cString == NULL ) {
            RING_API_RETSTRING(cStr);
            return ;
        }
        cStr3 = RING_API_GETSTRING(3) ;
        nMark = 0 ;
        pString = ring_string_new_gc(((VM *) pPointer)->pRingState,"");
        while ( cString != NULL ) {
            nPos = (RING_LONGLONG)( 1 + (cString - cStr) ) ;
            /* Add SubString to pString */
            ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr+nMark,nPos-1-nMark);
            ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr3,RING_API_GETSTRINGSIZE(3));
            nMark = nPos + nSize2 -1 ;
            /* Search */
            if ( nTransform == 1 ) {
                cString = ring_string_find2(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
            }
            else {
                cString = ring_string_find3(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
            }
            if ( cString == NULL ) {
                /* Add SubString to pString */
                ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr+nMark,nSize-nMark);
            }
        }
        RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
        ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
    }
}

void ring_vm_generallib_lower ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        RING_API_RETSTRING2(ring_string_lower2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_upper ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        RING_API_RETSTRING2(ring_string_upper2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_lines ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_strcmp ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
        RING_API_RETNUMBER(strcmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
/* Functional */

void ring_vm_generallib_eval ( void *pPointer )
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
        if ( pVM->lInsideEval == 0 ) {
            pVM->nRetEvalDontDelete = 0 ;
        }
        if ( ring_vm_eval(pVM,cStr) == 0 ) {
            pVM->nEvalCalledFromRingCode = 0 ;
        }
        /*
        **  The CALL instruction will check nEvalCalledFromRingCode to execute the main loop again 
        **  Before executing the main loop again, The CALL instruction will set nEvalCalledFromRingCode to 0 
        */
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
/* Error Handling */

void ring_vm_generallib_raise ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        RING_API_ERROR(RING_API_GETSTRING(1));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_assert ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
/* Check Characters */

void ring_vm_generallib_isfunc ( void *pPointer,int (*pFunc)(int) )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_isalnum ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isalnum);
}

void ring_vm_generallib_isalpha ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isalpha);
}

void ring_vm_generallib_iscntrl ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,iscntrl);
}

void ring_vm_generallib_isdigit ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isdigit);
}

void ring_vm_generallib_isgraph ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isgraph);
}

void ring_vm_generallib_islower ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,islower);
}

void ring_vm_generallib_isprint ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isprint);
}

void ring_vm_generallib_ispunct ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,ispunct);
}

void ring_vm_generallib_isspace ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isspace);
}

void ring_vm_generallib_isupper ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isupper);
}

void ring_vm_generallib_isxdigit ( void *pPointer )
{
    ring_vm_generallib_isfunc(pPointer,isxdigit);
}
/* Garbage Collector & Variable Pointer */

void ring_vm_generallib_callgc ( void *pPointer )
{
    ring_vm_gc_deletetemplists((VM *) pPointer);
}

void ring_vm_generallib_varptr ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_intvalue ( void *pPointer )
{
    const char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        cStr = RING_API_GETSTRING(1);
        ring_vm_api_intvalue(pPointer,cStr);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_object2pointer ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( ! RING_API_ISLIST(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
    pList = RING_API_GETLIST(1) ;
    RING_API_RETCPOINTER((void *) pList,"OBJECTPOINTER");
}

void ring_vm_generallib_pointer2object ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( ! RING_API_ISPOINTER(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
    RING_API_RETLIST((List *) RING_API_GETCPOINTER(1,"OBJECTPOINTER"));
}

void ring_vm_generallib_nullpointer ( void *pPointer )
{
    RING_API_RETCPOINTER(NULL,"NULLPOINTER");
}

void ring_vm_generallib_space ( void *pPointer )
{
    char *pString  ;
    unsigned int nStrSize  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        if ( RING_API_GETNUMBER(1) < 1.0 ) {
            RING_API_ERROR(RING_API_BADPARARANGE);
            return ;
        }
        nStrSize = (unsigned int) RING_API_GETNUMBER(1) ;
        pString = (char *) RING_API_MALLOC(nStrSize);
        memset(pString,' ',nStrSize);
        RING_API_RETSTRING2(pString,nStrSize);
        RING_API_FREE(pString);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_ptrcmp ( void *pPointer )
{
    List *pList, *pList2  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISCPOINTER(1) && RING_API_ISCPOINTER(2) ) {
        pList = RING_API_GETLIST(1) ;
        pList2 = RING_API_GETLIST(2) ;
        RING_API_RETNUMBER(ring_vm_api_cpointercmp(pList,pList2));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_pointer2string ( void *pPointer )
{
    RING_API_IGNORECPOINTERTYPE ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return ;
    }
    if ( ! ( RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
    RING_API_RETSTRING2(((const char *) RING_API_GETCPOINTER(1,"OBJECTPOINTER"))+((int) RING_API_GETNUMBER(2)),(int) RING_API_GETNUMBER(3));
}

void ring_vm_generallib_setpointer ( void *pPointer )
{
    List *pList  ;
    RING_UNSIGNEDINTEGERPOINTER nNum  ;
    RING_API_IGNORECPOINTERTYPE ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( ! ( RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    pList = RING_API_GETLIST(1) ;
    /* Pointer even address can fit into 2^53-2^54 range of the double */
    #if RING_ANSI_C
    #else
        if ( RING_API_GETNUMBER(2) > ( RING_LONGLONG_HIGHVALUE * 2 ) ) {
            RING_API_ERROR(RING_API_BADPARARANGE);
            return ;
        }
    #endif
    nNum = RING_API_GETNUMBER(2) ;
    ring_list_setpointer(pList,RING_CPOINTER_POINTER,(void *) nNum);
}

void ring_vm_generallib_getpointer ( void *pPointer )
{
    List *pList  ;
    RING_UNSIGNEDINTEGERPOINTER nNum  ;
    RING_API_IGNORECPOINTERTYPE ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( ! ( RING_API_ISCPOINTER(1) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    pList = RING_API_GETLIST(1) ;
    nNum = (RING_UNSIGNEDINTEGERPOINTER) ring_list_getpointer(pList,RING_CPOINTER_POINTER) ;
    RING_API_RETNUMBER(nNum);
}

void ring_vm_generallib_memcpy ( void *pPointer )
{
    void *dest  ;
    const void *src  ;
    size_t num  ;
    List *pList  ;
    RING_API_IGNORECPOINTERTYPE ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return ;
    }
    if ( ( ! ( RING_API_ISCPOINTER(1) || RING_API_ISSTRING(1)) ) || ( ! ( RING_API_ISCPOINTER(2) || RING_API_ISSTRING(2)) ) || ( ! RING_API_ISNUMBER(3)) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    /* Get Parameters */
    if ( RING_API_ISSTRING(1) ) {
        dest = (void *) RING_API_GETSTRING(1) ;
    }
    if ( RING_API_ISCPOINTER(1) ) {
        pList = RING_API_GETLIST(1) ;
        dest = (void *) ring_list_getpointer(pList,RING_CPOINTER_POINTER) ;
    }
    if ( RING_API_ISSTRING(2) ) {
        src = (const void *) RING_API_GETSTRING(2) ;
    }
    if ( RING_API_ISCPOINTER(2) ) {
        pList = RING_API_GETLIST(2) ;
        src = (const void *) ring_list_getpointer(pList,RING_CPOINTER_POINTER) ;
    }
    num = (size_t) RING_API_GETNUMBER(3) ;
    /* Call Function */
    memcpy(dest,src,num);
}
/* Ring State */

void ring_vm_generallib_state_init ( void *pPointer )
{
    RingState *pState  ;
    pState = ring_state_init();
    pState->nRingInsideRing = 1 ;
    RING_API_RETCPOINTER((void *) pState,"RINGSTATE");
}

void ring_vm_generallib_state_runcode ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    ring_state_runcode((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vm_generallib_state_delete ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    ring_state_delete((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"));
}

void ring_vm_generallib_state_runfile ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    ring_state_runfile((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vm_generallib_state_findvar ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    pList = ring_state_findvar((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
    RING_API_RETLIST(pList);
}

void ring_vm_generallib_state_newvar ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    pList = ring_state_newvar((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
    RING_API_RETLIST(pList);
}

void ring_vm_generallib_state_runobjectfile ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    ring_state_runobjectfile((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vm_generallib_state_main ( void *pPointer )
{
    char *cStr  ;
    int argc  ;
    char *argv[2]  ;
    argv[0] = (char *) RING_API_MALLOC(100);
    argv[1] = (char *) RING_API_MALLOC(100);
    cStr = RING_API_GETSTRING(1);
    argc = 2 ;
    strcpy(argv[0],"ring");
    strcpy(argv[1],cStr);
    ring_state_execute(cStr,0,1,0,0,0,0,0,0,0,0,argc,argv);
    RING_API_FREE(argv[0]);
    RING_API_FREE(argv[1]);
}

void ring_vm_generallib_state_setvar ( void *pPointer )
{
    List *pList, *pList2, *pList3  ;
    VM *pVM  ;
    RingState *pRingSubState  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return ;
    }
    /*
    **  It's very important to use pRingSubState instead of pRingState when using the Garbage Collector func 
    **  Because the Sub Ring State will own the memory values and will try to delete it in the end of the pr 
    **  So we must create it with the Garbage Collector of this sub state 
    */
    pRingSubState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
    pList = ring_state_findvar(pRingSubState,RING_API_GETSTRING(2));
    /* Check Variable before usage */
    if ( pList==NULL ) {
        RING_API_ERROR("Variable doesn't exist!");
        return ;
    }
    if ( RING_API_ISSTRING(3) ) {
        ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_STRING);
        ring_list_setstring2_gc(pRingSubState,pList, RING_VAR_VALUE , RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
    }
    else if ( RING_API_ISNUMBER(3) ) {
        ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_NUMBER);
        ring_list_setdouble_gc(pRingSubState,pList, RING_VAR_VALUE ,RING_API_GETNUMBER(3));
    }
    else if ( RING_API_ISLIST(3) ) {
        pList2 = RING_API_GETLIST(3) ;
        ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_LIST);
        ring_list_setlist_gc(pRingSubState,pList, RING_VAR_VALUE);
        pList3 = ring_list_getlist(pList,RING_VAR_VALUE);
        ring_vm_list_copy(pRingSubState->pVM,pList3,pList2);
    }
}

void ring_vm_generallib_state_new ( void *pPointer )
{
    RingState *pState  ;
    pState = ring_state_new();
    pState->nRingInsideRing = 1 ;
    RING_API_RETCPOINTER((void *) pState,"RINGSTATE");
}

void ring_vm_generallib_state_mainfile ( void *pPointer )
{
    RingState *pRingState  ;
    char *cStr  ;
    int argc  ;
    char *argv[2]  ;
    argv[0] = (char *) RING_API_MALLOC(100);
    argv[1] = (char *) RING_API_MALLOC(100);
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    pRingState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
    cStr = RING_API_GETSTRING(2);
    argc = 2 ;
    strcpy(argv[0],"ring");
    strcpy(argv[1],cStr);
    pRingState->argc = argc ;
    pRingState->argv = argv ;
    /*
    **  Don't Delete the VM after execution 
    **  We may run GUI app from GUI app 
    **  In this case the caller already called qApp.Exec() 
    **  Deleting the VM in sub program after execution 
    **  Will lead to crash when we execute events (like button click) in the sub program 
    **  So we keep the VM to avoid the Crash 
    */
    pRingState->nDontDeleteTheVM = 1 ;
    ring_state_runfile(pRingState,cStr);
}

void ring_vm_generallib_state_filetokens ( void *pPointer )
{
    RingState *pState  ;
    char *cFile  ;
    List *pList  ;
    int lCase,lComments  ;
    if ( RING_API_PARACOUNT < 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    pState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
    cFile = RING_API_GETSTRING(2);
    /* Check the (Not Case Sensitive) feature */
    lCase = 1 ;
    if ( RING_API_PARACOUNT >= 3 ) {
        if ( RING_API_ISNUMBER(3) ) {
            lCase = (int) RING_API_GETNUMBER(3) ;
        }
    }
    pState->lNotCaseSensitive = lCase ;
    pState->nOnlyTokens = 1 ;
    /* Check the (Comments As Tokens) feature */
    lComments = 0 ;
    if ( RING_API_PARACOUNT == 4 ) {
        if ( RING_API_ISNUMBER(4) ) {
            lComments = (int) RING_API_GETNUMBER(4) ;
        }
    }
    pState->lCommentsAsTokens = lComments ;
    ring_state_runfile(pState,cFile);
    pState->lNotCaseSensitive = 1 ;
    pState->nOnlyTokens = 0 ;
    pState->lCommentsAsTokens = 0 ;
    /* Copy The List */
    pList = RING_API_NEWLIST ;
    ring_list_copy_tohighlevel_gc(((VM *) pPointer)->pRingState,pList,pState->pRingFileTokens);
    RING_API_RETLIST(pList);
    pState->pRingFileTokens = ring_list_delete_gc(pState,pState->pRingFileTokens);
}

void ring_vm_generallib_state_stringtokens ( void *pPointer )
{
    RingState *pState  ;
    char *cString  ;
    List *pList  ;
    int lCase,lComments  ;
    if ( RING_API_PARACOUNT < 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    pState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
    cString = RING_API_GETSTRING(2);
    /* Check the (Not Case Sensitive) feature */
    lCase = 1 ;
    if ( RING_API_PARACOUNT >= 3 ) {
        if ( RING_API_ISNUMBER(3) ) {
            lCase = (int) RING_API_GETNUMBER(3) ;
        }
    }
    pState->lNotCaseSensitive = lCase ;
    pState->nOnlyTokens = 1 ;
    /* Check the (Comments As Tokens) feature */
    lComments = 0 ;
    if ( RING_API_PARACOUNT == 4 ) {
        if ( RING_API_ISNUMBER(4) ) {
            lComments = (int) RING_API_GETNUMBER(4) ;
        }
    }
    pState->lCommentsAsTokens = lComments ;
    ring_state_runstring(pState,cString);
    pState->lNotCaseSensitive = 1 ;
    pState->nOnlyTokens = 0 ;
    pState->lCommentsAsTokens = 0 ;
    /* Copy The List */
    pList = RING_API_NEWLIST ;
    ring_list_copy_tohighlevel_gc(((VM *) pPointer)->pRingState,pList,pState->pRingFileTokens);
    RING_API_RETLIST(pList);
    pState->pRingFileTokens = ring_list_delete_gc(pState,pState->pRingFileTokens);
}

void ring_vm_generallib_state_scannererror ( void *pPointer )
{
    RingState *pState  ;
    if ( RING_API_PARACOUNT < 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    pState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
    RING_API_RETNUMBER(pState->nScannerError);
}
/* Ring See and Give */

void ring_vm_generallib_see ( void *pPointer )
{
    char *cString  ;
    int x  ;
    char cStr[100]  ;
    List *pList  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_ISSTRING(1) ) {
        cString = RING_API_GETSTRING(1) ;
        if ( strlen(cString) != (unsigned int) RING_API_GETSTRINGSIZE(1) ) {
            for ( x = 0 ; x < RING_API_GETSTRINGSIZE(1) ; x++ ) {
                printf( "%c",cString[x] ) ;
            }
        }
        else {
            printf( "%s",cString ) ;
        }
    }
    else if ( RING_API_ISNUMBER(1) ) {
        ring_vm_numtostring(pVM,RING_API_GETNUMBER(1),cStr);
        printf( "%s",cStr ) ;
    }
    else if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1);
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_oop_printobj(pVM,pList);
        }
        else {
            ring_list_print2(pList, ((VM *)pPointer)->nDecimals);
        }
    }
    fflush(stdout);
}

void ring_vm_generallib_give ( void *pPointer )
{
    int x  ;
    char cLine[256]  ;
    /* Get Input From the User and save it in the variable */
    fgets(cLine , 256 , stdin );
    /* Remove New Line */
    for ( x = 0 ; x <= 255 ; x++ ) {
        if ( cLine[x] == '\n' ) {
            cLine[x] = '\0' ;
            break ;
        }
    }
    RING_API_RETSTRING(cLine);
}

void ring_vm_generallib_print ( void *pPointer )
{
    List *pList  ;
    char cStr[100]  ;
    char *cString  ;
    int x,nSize,nPos  ;
    char cCode[256]  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        ring_vm_numtostring(pVM,RING_API_GETNUMBER(1),cStr);
        printf( "%s",cStr ) ;
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1);
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_oop_printobj(pVM,pList);
        }
        else {
            ring_list_print2(pList, ((VM *)pPointer)->nDecimals);
        }
        return ;
    }
    if ( ! RING_API_ISSTRING(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    cString = RING_API_GETSTRING(1) ;
    nSize = RING_API_GETSTRINGSIZE(1) ;
    for ( x = 0 ; x < nSize ; x++ ) {
        if ( x != nSize-1 ) {
            switch ( cString[x] ) {
                case '\\' :
                    switch ( cString[x+1] ) {
                        case 'r' :
                            printf( "\r" ) ;
                            x++ ;
                            continue ;
                        case 'n' :
                            printf( "\n" ) ;
                            x++ ;
                            continue ;
                        case 't' :
                            printf( "\t" ) ;
                            x++ ;
                            continue ;
                        case '\\' :
                            printf( "\\" ) ;
                            x++ ;
                            continue ;
                        case '#' :
                            printf( "#" ) ;
                            x++ ;
                            continue ;
                    }
                    break ;
                case '#' :
                    if ( cString[x+1] == '{' ) {
                        strcpy(cCode,"see ");
                        x += 2 ;
                        nPos = 4 ;
                        while ( (x < nSize) && (cString[x] != '}') && (nPos <= C_EXPRCODESIZE ) ) {
                            cCode[nPos] = cString[x] ;
                            nPos++ ;
                            x++ ;
                        }
                        if ( nPos > C_EXPRCODESIZE ) {
                            RING_API_ERROR("The Expression is too large, The size must be <= 200 characters!");
                            return ;
                        }
                        cCode[nPos] = '\0' ;
                        /* Evaluate the Expression */
                        ring_vm_runcode(pVM,cCode);
                        continue ;
                    }
                    break ;
            }
        }
        printf( "%c",cString[x] ) ;
    }
}

void ring_vm_generallib_print2str ( void *pPointer )
{
    char cStr[100]  ;
    int x,nSize,nPos  ;
    char cCode[256]  ;
    char *cString  ;
    String *pRingCode  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        ring_vm_numtostring(pVM,RING_API_GETNUMBER(1),cStr);
        RING_API_RETSTRING(cStr);
        return ;
    }
    if ( ! RING_API_ISSTRING(1) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    cString = RING_API_GETSTRING(1) ;
    nSize = RING_API_GETSTRINGSIZE(1) ;
    pRingCode = ring_string_new_gc(pVM->pRingState,"return ''");
    for ( x = 0 ; x < nSize ; x++ ) {
        if ( x != nSize-1 ) {
            switch ( cString[x] ) {
                case '\\' :
                    switch ( cString[x+1] ) {
                        case 'r' :
                            ring_string_add_gc(pVM->pRingState,pRingCode,"+'\r'");
                            x++ ;
                            continue ;
                        case 'n' :
                            ring_string_add_gc(pVM->pRingState,pRingCode,"+'\n'");
                            x++ ;
                            continue ;
                        case 't' :
                            ring_string_add_gc(pVM->pRingState,pRingCode,"+'\t'");
                            x++ ;
                            continue ;
                        case '\\' :
                            ring_string_add_gc(pVM->pRingState,pRingCode,"+'\\'");
                            x++ ;
                            continue ;
                        case '#' :
                            ring_string_add_gc(pVM->pRingState,pRingCode,"+'#'");
                            x++ ;
                            continue ;
                    }
                    break ;
                case '#' :
                    if ( cString[x+1] == '{' ) {
                        strcpy(cCode,"");
                        x += 2 ;
                        nPos = 0 ;
                        while ( (x < nSize) && (cString[x] != '}') && (nPos <= C_EXPRCODESIZE ) ) {
                            cCode[nPos] = cString[x] ;
                            nPos++ ;
                            x++ ;
                        }
                        if ( nPos > C_EXPRCODESIZE ) {
                            RING_API_ERROR("The Expression is too large, The size must be <= 200 characters!");
                            ring_string_delete_gc(pVM->pRingState,pRingCode);
                            return ;
                        }
                        cCode[nPos] = '\0' ;
                        ring_string_add_gc(pVM->pRingState,pRingCode,"+(");
                        ring_string_add_gc(pVM->pRingState,pRingCode,cCode);
                        ring_string_add_gc(pVM->pRingState,pRingCode,")");
                        continue ;
                    }
                    break ;
            }
        }
        ring_string_add_gc(pVM->pRingState,pRingCode,"+'");
        cStr[0] = cString[x] ;
        cStr[1] = '\0' ;
        ring_string_add_gc(pVM->pRingState,pRingCode,cStr);
        ring_string_add_gc(pVM->pRingState,pRingCode,"'");
    }
    /* Evaluate the code */
    pVM->nEvalCalledFromRingCode = 1 ;
    if ( pVM->lInsideEval == 0 ) {
        pVM->nRetEvalDontDelete = 0 ;
    }
    if ( ring_vm_eval(pVM,ring_string_get(pRingCode) ) == 0 ) {
        pVM->nEvalCalledFromRingCode = 0 ;
    }
    ring_string_delete_gc(pVM->pRingState,pRingCode);
}

void ring_vm_generallib_puts ( void *pPointer )
{
    ring_vm_generallib_print(pPointer);
    printf( "\n" ) ;
}

void ring_vm_generallib_getnumber ( void *pPointer )
{
    int x  ;
    char cLine[256]  ;
    double nNum  ;
    fgets(cLine , 256 , stdin );
    for ( x = 0 ; x <= 255 ; x++ ) {
        if ( cLine[x] == '\n' ) {
            cLine[x] = '\0' ;
            break ;
        }
    }
    nNum = ring_vm_stringtonum((VM *) pPointer,cLine);
    RING_API_RETNUMBER(nNum);
}
/* Performance */

void ring_vm_generallib_checkoverflow ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        if ( RING_API_GETNUMBER(1) == 1 ) {
            ((VM *) pPointer)->lCheckOverFlow = 1 ;
        }
        else {
            ((VM *) pPointer)->lCheckOverFlow = 0 ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_addsublistsbymove ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        if ( RING_API_GETNUMBER(1) == 1 ) {
            ((VM *) pPointer)->lAddSubListsByMove = 1 ;
        }
        else {
            ((VM *) pPointer)->lAddSubListsByMove = 0 ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_generallib_addsublistsbyfastcopy ( void *pPointer )
{
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        if ( RING_API_GETNUMBER(1) == 1 ) {
            ((VM *) pPointer)->lAddSubListsByFastCopy = 1 ;
        }
        else {
            ((VM *) pPointer)->lAddSubListsByFastCopy = 0 ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
