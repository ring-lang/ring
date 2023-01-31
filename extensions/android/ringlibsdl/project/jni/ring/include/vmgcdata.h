/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmgcdata
    #define ring_vmgcdata
    typedef struct ItemGCData {
        void (*pFreeFunc)(void *,void *) ;
        unsigned int nReferenceCount  ;
    } ItemGCData ;
    typedef struct ListGCData {
        void *pContainer  ;
        int nReferenceCount  ;
        int nTempRC  ;
        unsigned int lCopyByRef: 1  ;
        unsigned int lNewRef: 1  ;
        unsigned int lDontDelete: 1  ;
        unsigned int lDeleteContainerVariable: 1  ;
        unsigned int lDontRef: 1  ;
    } ListGCData ;
#endif
