/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_items_h
    #define ring_items_h
    /* Data */
    typedef struct Items {
        struct Item *pValue  ;
        struct Items *pNext  ;
        struct Items *pPrev  ;
    } Items ;
    /* Functions */

    Items * ring_items_new_gc ( void *pState ) ;

    Items * ring_items_delete_gc ( void *pState,Items *pItems ) ;

    void ring_items_print ( Items *pItems ) ;
    /* Functions without State pointer */

    Items * ring_items_new ( void ) ;

    Items * ring_items_delete ( Items *pItems ) ;
#endif
