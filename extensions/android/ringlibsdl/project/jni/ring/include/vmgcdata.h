/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmgcdata
    #define ring_vmgcdata
    typedef struct ItemGCData {
        void (*pFreeFunc)(void *,void *) ;
        unsigned int nReferenceCount  ;
    } ItemGCData ;
    typedef struct ListGCData {
        void *pContainer  ;
        unsigned int lCopyByRef: 1  ;
        unsigned int lNewRef: 1  ;
        unsigned int lDontDelete: 1  ;
        unsigned int lDeleteContainerVariable: 1  ;
        short int nReferenceCount  ;
    } ListGCData ;
#endif
