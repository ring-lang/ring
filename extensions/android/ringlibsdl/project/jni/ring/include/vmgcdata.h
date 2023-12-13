/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmgcdata
    #define ring_vmgcdata
    #define RING_VM_BITSFORREFCOUNT 24
    typedef struct ListGCData {
        void *pContainer  ;
        int nReferenceCount: RING_VM_BITSFORREFCOUNT  ;
        int nTempRC: RING_VM_BITSFORREFCOUNT  ;
        unsigned int lCopyByRef: 1  ;
        unsigned int lNewRef: 1  ;
        unsigned int lDontDelete: 1  ;
        unsigned int lDeleteContainerVariable: 1  ;
        unsigned int lDontRef: 1  ;
        unsigned int lErrorOnAssignment: 1  ;
        unsigned int lDeletedByParent: 1  ;
        unsigned int lDontRefAgain: 1  ;
    } ListGCData ;
#endif
