/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_refmeta_extension_h
    #define ring_refmeta_extension_h
    /* Functions */

    void ring_vm_refmeta_loadfunctions ( RingState *pRingState ) ;
    /* Functions */

    void ring_vm_refmeta_locals ( void *pPointer ) ;

    void ring_vm_refmeta_globals ( void *pPointer ) ;

    void ring_vm_refmeta_functions ( void *pPointer ) ;

    void ring_vm_refmeta_cfunctions ( void *pPointer ) ;

    void ring_vm_refmeta_islocal ( void *pPointer ) ;

    void ring_vm_refmeta_isglobal ( void *pPointer ) ;

    void ring_vm_refmeta_isfunction ( void *pPointer ) ;

    void ring_vm_refmeta_iscfunction ( void *pPointer ) ;
    /* OOP */

    void ring_vm_refmeta_packages ( void *pPointer ) ;

    void ring_vm_refmeta_ispackage ( void *pPointer ) ;

    void ring_vm_refmeta_classes ( void *pPointer ) ;

    void ring_vm_refmeta_isclass ( void *pPointer ) ;

    void ring_vm_refmeta_packageclasses ( void *pPointer ) ;

    void ring_vm_refmeta_ispackageclass ( void *pPointer ) ;

    void ring_vm_refmeta_classname ( void *pPointer ) ;

    void ring_vm_refmeta_objectid ( void *pPointer ) ;

    void ring_vm_refmeta_attributes ( void *pPointer ) ;

    void ring_vm_refmeta_methods ( void *pPointer ) ;

    void ring_vm_refmeta_isattribute ( void *pPointer ) ;

    void ring_vm_refmeta_ismethod ( void *pPointer ) ;

    void ring_vm_refmeta_isprivateattribute ( void *pPointer ) ;

    void ring_vm_refmeta_isprivatemethod ( void *pPointer ) ;

    void ring_vm_refmeta_addattribute ( void *pPointer ) ;

    void ring_vm_refmeta_addmethod ( void *pPointer ) ;

    void ring_vm_refmeta_getattribute ( void *pPointer ) ;

    void ring_vm_refmeta_setattribute ( void *pPointer ) ;

    void ring_vm_refmeta_mergemethods ( void *pPointer ) ;

    void ring_vm_refmeta_packagename ( void *pPointer ) ;
    /* VM */

    void ring_vm_refmeta_ringvmfileslist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmcalllist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmmemorylist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmfunctionslist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmclasseslist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmpackageslist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmcfunctionslist ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmsettrace ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmtracedata ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmtraceevent ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmtracefunc ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmscopescount ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmevalinscope ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmpasserror ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmhideerrormsg ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmcallfunc ( void *pPointer ) ;

    void ring_vm_refmeta_ringvminfo ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmgenarray ( void *pPointer ) ;

    void ring_vm_refmeta_ringvmcodelist ( void *pPointer ) ;
#endif
