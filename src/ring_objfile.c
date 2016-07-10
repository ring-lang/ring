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
	fprintf( fObj , "# Ring Object File\n"  ) ;
	fprintf( fObj , "# Version 1.0\n"  ) ;
	/* Write Functions Lists */
	fprintf( fObj , "# Functions List\n"  ) ;
	ring_objfile_writelist(pRingState->pRingFunctionsMap,fObj);
	/* Write Classes List */
	fprintf( fObj , "# Classes List\n"  ) ;
	ring_objfile_writelist(pRingState->pRingClassesMap,fObj);
	/* Write Packages */
	fprintf( fObj , "# Packages List\n"  ) ;
	ring_objfile_writelist(pRingState->pRingPackagesMap,fObj);
	/* Write Code */
	fprintf( fObj , "# Program Code\n"  ) ;
	ring_objfile_writelist(pRingState->pRingGenCode,fObj);
	/* Close File */
	fprintf( fObj , "# End of File\n"  ) ;
	fclose( fObj ) ;
}

void ring_objfile_writelist ( List *pList,FILE *fObj )
{
	List *pList2  ;
	int x,x2  ;
	fprintf( fObj , "{\n"  ) ;
	/* Write List Items */
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList2 = ring_list_getlist(pList,x);
		fprintf( fObj , "[T]\n"  ) ;
		for ( x2 = 1 ; x2 <= ring_list_getsize(pList2) ; x2++ ) {
			if ( ring_list_isstring(pList2,x2) ) {
				fprintf( fObj , "[S][%d]" , ring_list_getstringsize(pList2,x2) ) ;
				fwrite( ring_list_getstring(pList2,x2) , 1 , ring_list_getstringsize(pList2,x2) , fObj );
				fprintf( fObj , "\n"  ) ;
			}
			else if ( ring_list_isint(pList2,x2) ) {
				fprintf( fObj , "[I]%d\n" , ring_list_getint(pList2,x2) ) ;
			}
			else if ( ring_list_isdouble(pList2,x2) ) {
				fprintf( fObj , "[D]%f\n" , ring_list_getdouble(pList2,x2) ) ;
			}
			else if ( ring_list_ispointer(pList2,x2) ) {
				fprintf( fObj , "[P]%p\n" , (void *) ring_list_getpointer(pList2,x2) ) ;
			}
			else if ( ring_list_islist(pList2,x2) ) {
				fprintf( fObj , "[L]\n"  ) ;
				ring_objfile_writelist(ring_list_getlist(pList2,x2) ,fObj);
			}
		}
		fprintf( fObj , "[E]\n"  ) ;
	}
	fprintf( fObj , "}\n"  ) ;
}

void ring_objfile_readfile ( RingState *pRingState )
{
	FILE *fObj;
	signed char c  ;
	List *pListFunctions, *pListClasses, *pListPackages, *pListCode, *pList, *pList2  ;
	int nActiveList,nValue  ;
	double dValue  ;
	/* Create Lists */
	pListFunctions = ring_list_new(0);
	pListClasses = ring_list_new(0);
	pListPackages = ring_list_new(0);
	pListCode = ring_list_new(0);
	/* Set Active List (1=functions 2=classes 3=packages 4=code) */
	nActiveList = 0 ;
	/* Open File */
	fObj = fopen("program.ringo" , "rb" );
	/* Process File */
	c = getc(fObj);
	while ( c != EOF ) {
		/* Check Char */
		switch ( c ) {
			case '#' :
				/* Read Line */
				while ( c != '\n' ) {
					c = getc(fObj);
				}
				break ;
			case '{' :
				nActiveList++ ;
				switch ( nActiveList ) {
					case 1 :
						pList = pListFunctions ;
						break ;
					case 2 :
						pList = pListClasses ;
						break ;
					case 3 :
						pList = pListPackages ;
						break ;
					case 4 :
						pList = pListCode ;
						break ;
				}
				break ;
			case '[' :
				c = getc(fObj);
				switch ( c ) {
					case 'S' :
						break ;
					case 'I' :
						c = getc(fObj);
						fscanf( fObj , "%d" , &nValue ) ;
						ring_list_addint(pList,nValue);
						break ;
					case 'D' :
						c = getc(fObj);
						fscanf( fObj , "%f" , &dValue ) ;
						ring_list_adddouble(pList,dValue);
						break ;
					case 'P' :
						break ;
					case 'T' :
						pList2 = pList ;
						pList = ring_list_newlist(pList);
						/* Read Line */
						while ( c != '\n' ) {
							c = getc(fObj);
						}
						break ;
					case 'E' :
						pList = pList2 ;
						/* Read Line */
						while ( c != '\n' ) {
							c = getc(fObj);
						}
					case 'L' :
						break ;
				}
				break ;
		}
		c = getc(fObj);
	}
	/* Close File */
	fclose( fObj ) ;
}
