/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_refmeta_extension_h
	#define ring_refmeta_extension_h

	void ring_vm_refmeta_loadfunctions ( RingState *pRingState ) ;

	void ring_vm_refmeta_locals ( void *pPointer ) ;

	void ring_vm_refmeta_globals ( void *pPointer ) ;

	void ring_vm_refmeta_functions ( void *pPointer ) ;

	void ring_vm_refmeta_cfunctions ( void *pPointer ) ;

	void ring_vm_refmeta_islocal ( void *pPointer ) ;

	void ring_vm_refmeta_isglobal ( void *pPointer ) ;

	void ring_vm_refmeta_isfunction ( void *pPointer ) ;

	void ring_vm_refmeta_iscfunction ( void *pPointer ) ;

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

	void ring_vm_refmeta_importpackage ( void *pPointer ) ;

	void ring_vm_refmeta_parentclassname ( void *pPointer ) ;
#endif
