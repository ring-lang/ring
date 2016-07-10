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
	fObj = fopen("program.ringo" , "w+b" );
	fprintf( fObj , "# Ring Object File\r\n"  ) ;
	fprintf( fObj , "# Version 1.0\r\n"  ) ;
	/* Write Functions Lists */
	fprintf( fObj , "# Functions List\r\n"  ) ;
	ring_objfile_writelist(pRingState->pRingFunctionsMap,fObj);
	/* Write Classes List */
	fprintf( fObj , "# Classes List\r\n"  ) ;
	ring_objfile_writelist(pRingState->pRingClassesMap,fObj);
	/* Write Packages */
	fprintf( fObj , "# Packages List\r\n"  ) ;
	ring_objfile_writelist(pRingState->pRingPackagesMap,fObj);
	/* Write Code */
	fprintf( fObj , "# Program Code\r\n"  ) ;
	ring_objfile_writelist(pRingState->pRingGenCode,fObj);
	/* Close File */
	fprintf( fObj , "# End of File\r\n"  ) ;
	fclose( fObj ) ;
}

void ring_objfile_writelist ( List *pList,FILE *fObj )
{
	List *pList2  ;
	int x,x2  ;
	fprintf( fObj , "{\r\n"  ) ;
	/* Write List Items */
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList2 = ring_list_getlist(pList,x);
		fprintf( fObj , "[LI];\r\n"  ) ;
		for ( x2 = 1 ; x2 <= ring_list_getsize(pList2) ; x2++ ) {
			if ( ring_list_isstring(pList2,x2) ) {
				fprintf( fObj , "[S][%d]" , ring_list_getstringsize(pList2,x2) ) ;
				fwrite( ring_list_getstring(pList2,x2) , 1 , ring_list_getstringsize(pList2,x2) , fObj );
				fprintf( fObj , ";"  ) ;
			}
			else if ( ring_list_isint(pList2,x2) ) {
				fprintf( fObj , "[I]%d;" , ring_list_getint(pList2,x2) ) ;
			}
			else if ( ring_list_isdouble(pList2,x2) ) {
				fprintf( fObj , "[D]%f;" , ring_list_getdouble(pList2,x2) ) ;
			}
			else if ( ring_list_ispointer(pList2,x2) ) {
				fprintf( fObj , "[P]%p;" , (void *) ring_list_getpointer(pList2,x2) ) ;
			}
			else if ( ring_list_islist(pList2,x2) ) {
				fprintf( fObj , "[L]\r\n"  ) ;
				ring_objfile_writelist(ring_list_getlist(pList2,x2) ,fObj);
			}
		}
		fprintf( fObj , "\r\n"  ) ;
	}
	fprintf( fObj , "}\r\n"  ) ;
}
