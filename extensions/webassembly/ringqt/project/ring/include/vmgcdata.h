/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmgcdata
    #define ring_vmgcdata
    typedef struct GCData {
        void (*pFreeFunc)(void *,void *) ;
        unsigned int nReferenceCount  ;
    } GCData ;
#endif
