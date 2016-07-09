/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Define Functions */

void ring_objfile_writefile ( RingState *pRingState )
{
	FILE *fObj;
	/* Create File */
	fObj = fopen("program.ringo" , "w+" );
	/* Write Functions Lists */
	ring_objfile_writelist(pRingState->pRingFunctionsMap,fObj);
	/* Write Classes List */
	ring_objfile_writelist(pRingState->pRingClassesMap,fObj);
	/* Write Packages */
	ring_objfile_writelist(pRingState->pRingPackagesMap,fObj);
	/* Write Code */
	ring_objfile_writelist(pRingState->pRingGenCode,fObj);
	/* Close File */
	fclose( fObj ) ;
}

void ring_objfile_writelist ( List *pList,FILE *fObj )
{
	fprintf( fObj , "{\n"  ) ;
	/* Write List Items */
	fprintf( fObj , "}\n"  ) ;
}
