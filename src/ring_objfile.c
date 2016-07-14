/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Define Functions */

void ring_objfile_writefile ( RingState *pRingState )
{
	FILE *fObj;
	char cFileName[400]  ;
	/* Create File */
	sprintf( cFileName , "%so" , ring_list_getstring(pRingState->pRingFilesList,1) ) ;
	fObj = fopen(cFileName , "w+b" );
	fprintf( fObj , "# Ring Object File\n"  ) ;
	fprintf( fObj , "# Version 1.1\n"  ) ;
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
	int x,x2,x3  ;
	char *cString  ;
	char cKey[11]  ;
	strcpy(cKey,"ringstring");
	fprintf( fObj , "{\n"  ) ;
	/* Write List Items */
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList2 = ring_list_getlist(pList,x);
		fprintf( fObj , "[T]\n"  ) ;
		for ( x2 = 1 ; x2 <= ring_list_getsize(pList2) ; x2++ ) {
			if ( ring_list_isstring(pList2,x2) ) {
				fprintf( fObj , "[S][%d]" , ring_list_getstringsize(pList2,x2) ) ;
				/* Encrypt String */
				cString = ring_list_getstring(pList2,x2) ;
				ring_objfile_xorstring(cString,ring_list_getstringsize(pList2,x2),cKey,10);
				fwrite( ring_list_getstring(pList2,x2) , 1 , ring_list_getstringsize(pList2,x2) , fObj );
				/* Decrypt String */
				ring_objfile_xorstring(cString,ring_list_getstringsize(pList2,x2),cKey,10);
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

int ring_objfile_readfile ( const char *cFileName,RingState *pRingState )
{
	FILE *fObj;
	signed char c  ;
	List *pListFunctions, *pListClasses, *pListPackages, *pListCode, *pList, *pListStack  ;
	int nActiveList,nValue,nBraceEnd,x3  ;
	double dValue  ;
	char *cString  ;
	char cKey[11]  ;
	strcpy(cKey,"ringstring");
	char cFileType[100]  ;
	/* Create Lists */
	pListFunctions = ring_list_new(0);
	pListClasses = ring_list_new(0);
	pListPackages = ring_list_new(0);
	pListCode = ring_list_new(0);
	pListStack = ring_list_new(0);
	/* Set Active List (1=functions 2=classes 3=packages 4=code) */
	nActiveList = 0 ;
	nBraceEnd = 0 ;
	/* Open File */
	fObj = fopen(cFileName , "rb" );
	if ( fObj==NULL ) {
		printf( "Can't open file %s \n  ",cFileName ) ;
		return 0 ;
	}
	fread( cFileType , 1 , 18 , fObj );
	cFileType[18] = '\0' ;
	if ( strcmp(cFileType,"# Ring Object File") != 0 ) {
		printf( "The file type is not correct - the VM expect a ring object file \n  ",cFileName ) ;
		return 0 ;
	}
	c = getc(fObj);
	fread( cFileType , 1 , 13 , fObj );
	cFileType[13] = '\0' ;
	if ( strcmp(cFileType,"# Version 1.1") != 0 ) {
		printf( "The file version is not correct - the VM expect a ring object file version 1.1 \n  ",cFileName ) ;
		return 0 ;
	}
	/* Process File */
	c = getc(fObj);
	while ( c != EOF ) {
		/* Check Char */
		switch ( c ) {
			case '#' :
				/* Read Line */
				while ( c != '\n' ) {
					c = getc(fObj);
					#ifdef DEBUG_OBJFILE
					printf( "%c  ",c ) ;
					#endif
				}
				#ifdef DEBUG_OBJFILE
				puts("Read Comment ! ");
				#endif
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
						c = getc(fObj);
						fscanf( fObj , "[%d]" , &nValue ) ;
						cString = (char *) malloc(nValue+1) ;
						fread( cString , 1 , nValue , fObj );
						cString[nValue] = '\0' ;
						/* Decrypt String */
						ring_objfile_xorstring(cString,nValue,cKey,10);
						ring_list_addstring2(pList,cString,nValue);
						free( cString ) ;
						#ifdef DEBUG_OBJFILE
						printf( "Read String %s Size %d \n",cString,nValue ) ;
						#endif
						break ;
					case 'I' :
						c = getc(fObj);
						fscanf( fObj , "%d" , &nValue ) ;
						ring_list_addint(pList,nValue);
						#ifdef DEBUG_OBJFILE
						printf( "Read Number %d \n  ",nValue ) ;
						#endif
						break ;
					case 'D' :
						c = getc(fObj);
						fscanf( fObj , "%lf" , &dValue ) ;
						ring_list_adddouble(pList,dValue);
						#ifdef DEBUG_OBJFILE
						printf( "Read Double %d  \n",dValue ) ;
						#endif
						break ;
					case 'P' :
						ring_list_addpointer(pList,NULL);
						/* Read Line */
						while ( c != '\n' ) {
							c = getc(fObj);
						}
						#ifdef DEBUG_OBJFILE
						puts("Read Pointer ");
						#endif
						break ;
					case 'T' :
						ring_list_addpointer(pListStack,pList);
						pList = ring_list_newlist(pList);
						/* Read Line */
						while ( c != '\n' ) {
							c = getc(fObj);
						}
						#ifdef DEBUG_OBJFILE
						puts("Read T ");
						#endif
						break ;
					case 'E' :
						pList = (List *) ring_list_getpointer(pListStack,ring_list_getsize(pListStack)) ;
						ring_list_deletelastitem(pListStack);
						/* Read Line */
						while ( c != '\n' ) {
							c = getc(fObj);
						}
						#ifdef DEBUG_OBJFILE
						puts("Read E ");
						#endif
						break ;
					case 'L' :
						/* Read Until { */
						while ( c != '{' ) {
							c = getc(fObj);
						}
						ring_list_addpointer(pListStack,pList);
						pList = ring_list_newlist(pList);
						nBraceEnd = 1 ;
						#ifdef DEBUG_OBJFILE
						puts("Read L ");
						#endif
						break ;
				}
				break ;
			case '}' :
				if ( nBraceEnd ) {
					pList = (List *) ring_list_getpointer(pListStack,ring_list_getsize(pListStack)) ;
					ring_list_deletelastitem(pListStack);
					nBraceEnd = 0 ;
					#ifdef DEBUG_OBJFILE
					puts("Read } ");
					#endif
				}
				break ;
		}
		c = getc(fObj);
	}
	/* Close File */
	fclose( fObj ) ;
	ring_list_delete(pListStack);
	/* Update Ring State */
	#ifdef DEBUG_OBJFILE
	puts("Old Code List ");
	ring_list_print(pRingState->pRingGenCode);
	#endif
	/* Update Lists */
	pRingState->pRingFunctionsMap = pListFunctions ;
	pRingState->pRingClassesMap = pListClasses ;
	pRingState->pRingPackagesMap = pListPackages ;
	pRingState->pRingGenCode = pListCode ;
	#ifdef DEBUG_OBJFILE
	puts("Update Done! ");
	puts("New Code List ");
	ring_list_print(pRingState->pRingGenCode);
	#endif
	/* Update Classes Pointers */
	ring_objfile_updateclassespointers(pRingState);
	return 1 ;
}

void ring_objfile_updateclassespointers ( RingState *pRingState )
{
	int x,x2,x3,x4,lFound  ;
	List *pList, *pList2, *pList3  ;
	const char *cString  ;
	char cPackageName[400]  ;
	char cClassName[400]  ;
	/* Update Class Pointer in Code */
	lFound = 0 ;
	for ( x = 1 ; x <= ring_list_getsize(pRingState->pRingGenCode) ; x++ ) {
		pList = ring_list_getlist(pRingState->pRingGenCode,x);
		if ( ring_list_getint(pList,1) == ICO_NEWCLASS ) {
			cString = ring_list_getstring(pList,2);
			for ( x2 = 1 ; x2 <= ring_list_getsize(pRingState->pRingClassesMap) ; x2++ ) {
				pList2 = ring_list_getlist(pRingState->pRingClassesMap,x2);
				if ( strcmp(cString,ring_list_getstring(pList2,1)) == 0 ) {
					lFound = 0 ;
					ring_list_setpointer(pList,3,pList2);
					#ifdef DEBUG_OBJFILE
					puts("Pointer Updated ");
					#endif
					break ;
				}
			}
			/* If we can't find the list (the class is inside a package) */
			if ( lFound == 0 ) {
				ring_list_setpointer(pList,3,NULL);
			}
		}
	}
	/*
	**  Update Class Pointers in Classes Map when the class belong to a Package 
	**  This updates works when the class name is : packagename.classname 
	*/
	for ( x = 1 ; x <= ring_list_getsize(pRingState->pRingClassesMap) ; x++ ) {
		pList = ring_list_getlist(pRingState->pRingClassesMap,x);
		cString = ring_list_getstring(pList,1);
		if ( ring_list_getstringsize(pList,1)  > 400 ) {
			/* Avoid large names - we have limits (400 letters per package name - 400 letters for class name) */
			continue ;
		}
		for ( x2 = ring_list_getstringsize(pList,1) - 1 ; x2 >= 0 ; x2-- ) {
			if ( cString[x2] == '.' ) {
				/*
				**  Now we have a class name stored as packagename.classname 
				**  Get Package Name 
				*/
				for ( x3 = 0 ; x3 < x2 ; x3++ ) {
					cPackageName[x3] = cString[x3] ;
				}
				cPackageName[x2] = '\0' ;
				#ifdef DEBUG_OBJFILE
				printf( "Package Name %s \n  ",cPackageName ) ;
				#endif
				/* Get Class Name */
				for ( x3 = x2+1 ; x3 <= ring_list_getstringsize(pList,1) - 1 ; x3++ ) {
					cClassName[x3-x2-1] = cString[x3] ;
				}
				cClassName[ring_list_getstringsize(pList,1) - 1 - x2] = '\0' ;
				#ifdef DEBUG_OBJFILE
				printf( "Class Name %s \n  ",cClassName ) ;
				#endif
				/* Get The Package List */
				for ( x3 = 1 ; x3 <= ring_list_getsize(pRingState->pRingPackagesMap) ; x3++ ) {
					pList2 = ring_list_getlist(pRingState->pRingPackagesMap,x3);
					if ( strcmp(ring_list_getstring(pList2,1),cPackageName) == 0 ) {
						/* Get The Class List */
						pList2 = ring_list_getlist(pList2,2);
						for ( x4 = 1 ; x4 <= ring_list_getsize(pList2) ; x4++ ) {
							pList3 = ring_list_getlist(pList2,x4);
							if ( strcmp(ring_list_getstring(pList3,1),cClassName) == 0 ) {
								/* Now We have the Class - Update Pointer */
								ring_list_setpointer(pList,2,(void *) pList3);
								break ;
							}
						}
						break ;
					}
				}
			}
		}
	}
}

void ring_objfile_xorstring ( char *cString,int nStringSize,char *cKey,int nKeySize )
{
	int x  ;
	for ( x = 1 ; x <= nStringSize ; x++ ) {
		cString[x-1] = cString[x-1] ^ cKey[(x-1)%nKeySize] ;
	}
}
