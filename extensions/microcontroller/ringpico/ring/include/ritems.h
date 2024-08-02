/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_items_h
	#define ring_items_h
	typedef struct Items {
		struct Item *pValue  ;
		struct Items *pNext  ;
		struct Items *pPrev  ;
		unsigned char lDelete  ;
	} Items ;

	Items * ring_items_new_gc ( void *pState ) ;

	Items * ring_items_delete_gc ( void *pState,Items *pItems ) ;

	void ring_items_print ( Items *pItems ) ;

	Items * ring_items_new ( void ) ;

	Items * ring_items_delete ( Items *pItems ) ;
#endif
