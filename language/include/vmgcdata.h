/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

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
		/* Prevent Assignment through Ring Code but Don't prevent deleting the List */
		unsigned int lErrorOnAssignment2: 1  ;
		unsigned int lCheckBeforeAssignmentDone: 1  ;
		unsigned int lDeletedByParent: 1  ;
		unsigned int lDontRefAgain: 1  ;
		/* Track Variable List contains Pointer to List Item */
		unsigned int lTrackedList: 1  ;
		unsigned int lArgCache: 1  ;
		unsigned int nListType: 3  ;
	} ListGCData ;
#endif
