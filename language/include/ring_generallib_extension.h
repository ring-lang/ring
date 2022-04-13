/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_generallib_extension_h
    #define ring_generallib_extension_h
    #ifndef _WIN32
        #include <stdint.h>
    #endif

    RING_API void ring_vm_generallib_loadfunctions ( RingState *pRingState ) ;
    /*
    **  Library Functions 
    **  General 
    */

    void ring_vm_generallib_len ( void *pPointer ) ;

    void ring_vm_generallib_clock ( void *pPointer ) ;

    void ring_vm_generallib_lower ( void *pPointer ) ;

    void ring_vm_generallib_upper ( void *pPointer ) ;

    void ring_vm_generallib_input ( void *pPointer ) ;

    void ring_vm_generallib_ascii ( void *pPointer ) ;

    void ring_vm_generallib_char ( void *pPointer ) ;

    void ring_vm_generallib_date ( void *pPointer ) ;

    void ring_vm_generallib_time ( void *pPointer ) ;

    void ring_vm_generallib_filename ( void *pPointer ) ;

    void ring_vm_generallib_getchar ( void *pPointer ) ;

    void ring_vm_generallib_random ( void *pPointer ) ;

    void ring_vm_generallib_timelist ( void *pPointer ) ;

    void ring_vm_generallib_adddays ( void *pPointer ) ;

    void ring_vm_generallib_diffdays ( void *pPointer ) ;

    void ring_vm_generallib_version ( void *pPointer ) ;

    void ring_vm_generallib_clockspersecond ( void *pPointer ) ;

    void ring_vm_generallib_prevfilename ( void *pPointer ) ;

    int ring_vm_generallib_adddays_isleapyear ( int nYear ) ;

    void ring_vm_generallib_srandom ( void *pPointer ) ;
    /* Check Data Type */

    void ring_vm_generallib_isstring ( void *pPointer ) ;

    void ring_vm_generallib_isnumber ( void *pPointer ) ;

    void ring_vm_generallib_islist ( void *pPointer ) ;

    void ring_vm_generallib_type ( void *pPointer ) ;

    void ring_vm_generallib_isnull ( void *pPointer ) ;

    void ring_vm_generallib_isobject ( void *pPointer ) ;

    void ring_vm_generallib_ispointer ( void *pPointer ) ;
    /* Conversion */

    void ring_vm_generallib_hex ( void *pPointer ) ;

    void ring_vm_generallib_dec ( void *pPointer ) ;

    void ring_vm_generallib_number ( void *pPointer ) ;

    void ring_vm_generallib_string ( void *pPointer ) ;

    void ring_vm_generallib_str2hex ( void *pPointer ) ;

    void ring_vm_generallib_hex2str ( void *pPointer ) ;

    void ring_vm_generallib_str2list ( void *pPointer ) ;

    void ring_vm_generallib_list2str ( void *pPointer ) ;

    void ring_vm_generallib_str2hexcstyle ( void *pPointer ) ;
    /* String */

    void ring_vm_generallib_left ( void *pPointer ) ;

    void ring_vm_generallib_right ( void *pPointer ) ;

    void ring_vm_generallib_trim ( void *pPointer ) ;

    void ring_vm_generallib_copy ( void *pPointer ) ;

    void ring_vm_generallib_substr ( void *pPointer ) ;

    void ring_vm_generallib_lines ( void *pPointer ) ;

    void ring_vm_generallib_strcmp ( void *pPointer ) ;
    /* Functional */

    void ring_vm_generallib_eval ( void *pPointer ) ;
    /* Error Handling */

    void ring_vm_generallib_raise ( void *pPointer ) ;

    void ring_vm_generallib_assert ( void *pPointer ) ;
    /* Check Characters */

    void ring_vm_generallib_isfunc ( void *pPointer,int (*pFunc)(int) ) ;

    void ring_vm_generallib_isalnum ( void *pPointer ) ;

    void ring_vm_generallib_isalpha ( void *pPointer ) ;

    void ring_vm_generallib_iscntrl ( void *pPointer ) ;

    void ring_vm_generallib_isdigit ( void *pPointer ) ;

    void ring_vm_generallib_isgraph ( void *pPointer ) ;

    void ring_vm_generallib_islower ( void *pPointer ) ;

    void ring_vm_generallib_isprint ( void *pPointer ) ;

    void ring_vm_generallib_ispunct ( void *pPointer ) ;

    void ring_vm_generallib_isspace ( void *pPointer ) ;

    void ring_vm_generallib_isupper ( void *pPointer ) ;

    void ring_vm_generallib_isxdigit ( void *pPointer ) ;
    /* Garbage Collector & Variable Pointer */

    void ring_vm_generallib_callgc ( void *pPointer ) ;

    void ring_vm_generallib_varptr ( void *pPointer ) ;

    void ring_vm_generallib_intvalue ( void *pPointer ) ;

    void ring_vm_generallib_object2pointer ( void *pPointer ) ;

    void ring_vm_generallib_pointer2object ( void *pPointer ) ;

    void ring_vm_generallib_nullpointer ( void *pPointer ) ;

    void ring_vm_generallib_space ( void *pPointer ) ;

    void ring_vm_generallib_ptrcmp ( void *pPointer ) ;

    void ring_vm_generallib_pointer2string ( void *pPointer ) ;

    void ring_vm_generallib_setpointer ( void *pPointer ) ;

    void ring_vm_generallib_getpointer ( void *pPointer ) ;

    void ring_vm_generallib_memcpy ( void *pPointer ) ;
    /* Ring State */

    void ring_vm_generallib_state_init ( void *pPointer ) ;

    void ring_vm_generallib_state_runcode ( void *pPointer ) ;

    void ring_vm_generallib_state_delete ( void *pPointer ) ;

    void ring_vm_generallib_state_runfile ( void *pPointer ) ;

    void ring_vm_generallib_state_findvar ( void *pPointer ) ;

    void ring_vm_generallib_state_newvar ( void *pPointer ) ;

    void ring_vm_generallib_state_runobjectfile ( void *pPointer ) ;

    void ring_vm_generallib_state_main ( void *pPointer ) ;

    void ring_vm_generallib_state_setvar ( void *pPointer ) ;

    void ring_vm_generallib_state_new ( void *pPointer ) ;

    void ring_vm_generallib_state_mainfile ( void *pPointer ) ;

    void ring_vm_generallib_state_filetokens ( void *pPointer ) ;

    void ring_vm_generallib_state_stringtokens ( void *pPointer ) ;

    void ring_vm_generallib_state_scannererror ( void *pPointer ) ;
    /* Ring See and Give */

    void ring_vm_generallib_see ( void *pPointer ) ;

    void ring_vm_generallib_give ( void *pPointer ) ;

    void ring_vm_generallib_print ( void *pPointer ) ;

    void ring_vm_generallib_print2str ( void *pPointer ) ;

    void ring_vm_generallib_puts ( void *pPointer ) ;

    void ring_vm_generallib_getnumber ( void *pPointer ) ;
    /* Performance */

    void ring_vm_generallib_checkoverflow ( void *pPointer ) ;

    void ring_vm_generallib_addsublistsbymove ( void *pPointer ) ;

    void ring_vm_generallib_addsublistsbyfastcopy ( void *pPointer ) ;
    /* Constants */
    #define C_EXPRCODESIZE 200
#endif
