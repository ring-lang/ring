/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_parser_class ( Parser *pParser )
{
	List *pList,*pList2,*pList3,*pMark,*pNewClass  ;
	int x  ;
	String *pString  ;
	/* Statement --> Class Identifier  [ From Identifier ] */
	if ( ring_parser_iskeyword(pParser,K_CLASS) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isidentifier(pParser) ) {
			/*
			**  Generate Code 
			**  Return NULL 
			*/
			ring_parser_icg_retnull(pParser);
			ring_parser_icg_newoperation(pParser,ICO_NEWCLASS);
			ring_parser_icg_newoperand(pParser,pParser->cTokenText);
			pNewClass = ring_parser_icg_getactiveoperation(pParser) ;
			/* Add Class to Classes Table */
			pList = pParser->pClassesMap ;
			/* Check Class Redefinition */
			if ( ring_list_getsize(pParser->pClassesMap) ) {
				/* Generate the HashTable */
				if ( ring_list_gethashtable(pParser->pClassesMap) == NULL ) {
					ring_list_genhashtable2(pParser->pClassesMap);
				}
				if ( ring_hashtable_findpointer(ring_list_gethashtable(pParser->pClassesMap),pParser->cTokenText) != NULL ) {
					ring_parser_error(pParser,RING_PARSER_ERROR_CLASSREDEFINE);
					return RING_PARSER_FAIL ;
				}
			}
			pList = ring_list_newlist_gc(pParser->pRingState,pList);
			ring_list_addstring_gc(pParser->pRingState,pList,pParser->cTokenText);
			ring_list_addint_gc(pParser->pRingState,pList,ring_parser_icg_instructionscount(pParser));
			/* Add class pointer to generated code */
			ring_parser_icg_newoperandpointer(pParser,pList);
			/* Add the class to the HashTable */
			if ( ring_list_gethashtable(pParser->pClassesMap) != NULL ) {
				ring_hashtable_newpointer_gc(NULL,ring_list_gethashtable(pParser->pClassesMap),pParser->cTokenText,pList);
			}
			ring_parser_nexttoken(pParser);
			/* [From Identifier] */
			if ( ring_parser_iskeyword(pParser,K_FROM) || ring_parser_isoperator2(pParser,OP_RANGE) || ring_parser_isoperator2(pParser,OP_LESS) ) {
				ring_parser_nexttoken(pParser);
				if ( ring_parser_namedotname(pParser) ) {
					/*
					**  Generate Code 
					**  Check if parent class name = subclass name 
					*/
					if ( strcmp(ring_list_getstring(pList,RING_CLASSES_CLASSNAME),ring_parser_icg_parentclassname(pParser)) == 0 ) {
						ring_parser_error(pParser,RING_PARSER_ERROR_PARENTLIKESUBCLASS);
						return RING_PARSER_FAIL ;
					}
					/* Set Parent Class Name in Classes Map */
					ring_list_addstring_gc(pParser->pRingState,pList,ring_parser_icg_parentclassname(pParser));
					RING_STATE_PRINTRULE(RING_RULE_CLASSFROM) ;
					ring_parser_icg_deleteparentclassname(pParser);
				}
				else {
					ring_parser_error(pParser,RING_PARSER_ERROR_PRENTCLASSNAME);
					return RING_PARSER_FAIL ;
				}
			}
			else {
				/* Set Parent Class Name In Classes Map */
				ring_list_addstring_gc(pParser->pRingState,pList,RING_CSTR_EMPTY);
				RING_STATE_PRINTRULE(RING_RULE_CLASS) ;
			}
			/* Add Method/Functions List to Class in Class Table */
			pList2 = ring_list_newlist_gc(pParser->pRingState,pList);
			/* Add Flag ( IS Parent Class information collected  ) */
			ring_list_addint_gc(pParser->pRingState,pList,RING_FALSE);
			/* Set Active Functions List to be Class Methods */
			pParser->pFunctionsMap = pList2 ;
			/* Make class visible using PackageName.ClassName if we have package */
			if ( pParser->pClassesMap != pParser->pRingState->pRingClassesMap ) {
				/* Get Package Name */
				pList3 = ring_list_getlist(pParser->pRingState->pRingPackagesMap,ring_list_getsize(pParser->pRingState->pRingPackagesMap));
				pString = ring_string_new_gc(pParser->pRingState,ring_list_getstring(pList3,RING_PACKAGES_PACKAGENAME));
				/* Add pointer to the Package in the Class List */
				ring_list_addpointer_gc(pParser->pRingState,pList,pList3);
				/* Add List pointer to General Classes that point to the class in the package */
				pList2 = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingClassesMap);
				ring_list_addstring_gc(pParser->pRingState,pList2,RING_CSTR_EMPTY);
				ring_list_addpointer_gc(pParser->pRingState,pList2,pList);
				/* Ignore Adding Pointer to File Name */
				ring_list_addpointer_gc(pParser->pRingState,pList2,NULL);
				/* Add Class Name to Package Name */
				ring_string_add_gc(pParser->pRingState,pString,".");
				ring_string_add_gc(pParser->pRingState,pString,ring_list_getstring(pList,RING_CLASSES_CLASSNAME));
				ring_list_setstring_gc(pParser->pRingState,pList2,RING_CLASSES_CLASSNAME,ring_string_get(pString));
				/* Set the class name as PackageName.ClassName in the Generated Code */
				ring_list_setstring(pNewClass,RING_PARSER_ICG_PARA1,ring_string_get(pString));
				ring_string_delete_gc(pParser->pRingState,pString);
			}
			else {
				/* Add pointer to the Package in the Class List */
				ring_list_addpointer_gc(pParser->pRingState,pList,NULL);
			}
			pParser->lClassStart = 1 ;
			/* Create label to be used by Private */
			pParser->nClassMark = ring_parser_icg_newlabel2(pParser);
			pParser->lPrivateFlag = 0 ;
			/* Generate Code - Set The File Name */
			ring_parser_icg_newoperation(pParser,ICO_FILENAME);
			ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
			/* Set Global Scope */
			ring_parser_icg_gensetglobalscope(pParser);
			/* Support using { } around the class code and using 'end' after the content */
			return ring_parser_bracesandend(pParser,RING_TRUE,K_ENDCLASS) ;
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_CLASSNAME);
			return RING_PARSER_FAIL ;
		}
	}
	/* Statement --> Func|Def Identifier [PARALIST] */
	if ( ring_parser_iskeyword(pParser,K_FUNC) || ring_parser_iskeyword(pParser,K_FUNCTION) || ring_parser_iskeyword(pParser,K_DEF) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isidentifier(pParser) ) {
			/*
			**  Generate Code 
			**  Return NULL 
			*/
			ring_parser_icg_retnull(pParser);
			ring_parser_icg_newoperation(pParser,ICO_NEWFUNC);
			/*
			**  Add function to Functions Table 
			**  Check Function Redefinition 
			*/
			if ( ring_list_getsize(pParser->pFunctionsMap) ) {
				/* Generate the HashTable */
				if ( ring_list_gethashtable(pParser->pFunctionsMap) == NULL ) {
					ring_list_genhashtable2(pParser->pFunctionsMap);
				}
				if ( ring_hashtable_findpointer(ring_list_gethashtable(pParser->pFunctionsMap),pParser->cTokenText) != NULL ) {
					ring_parser_error(pParser,RING_PARSER_ERROR_FUNCREDEFINE);
					return RING_PARSER_FAIL ;
				}
			}
			pList2 = ring_list_newlist_gc(pParser->pRingState,pParser->pFunctionsMap);
			ring_list_addstring_gc(pParser->pRingState,pList2,pParser->cTokenText);
			ring_list_addint_gc(pParser->pRingState,pList2,ring_parser_icg_instructionscount(pParser));
			ring_list_addstring_gc(pParser->pRingState,pList2,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
			if ( pParser->lClassStart == 1 ) {
				ring_list_addint_gc(pParser->pRingState,pList2,pParser->lPrivateFlag);
			}
			else {
				ring_list_addint_gc(pParser->pRingState,pList2,RING_FALSE);
			}
			/* Add the function to the HashTable */
			if ( ring_list_gethashtable(pParser->pFunctionsMap) != NULL ) {
				ring_hashtable_newpointer_gc(NULL,ring_list_gethashtable(pParser->pFunctionsMap),pParser->cTokenText,pList2);
			}
			ring_parser_nexttoken(pParser);
			if ( ring_parser_isidentifier(pParser) || ring_parser_isoperator2(pParser,OP_FOPEN) ) {
				x = ring_parser_paralist(pParser);
			}
			else {
				x = RING_PARSER_OK ;
			}
			/* Set Global Scope */
			ring_parser_icg_gensetglobalscope(pParser);
			if ( x == RING_PARSER_OK ) {
				RING_STATE_PRINTRULE(RING_RULE_FUNCANDPARA) ;
				/* Support using { } around the function code and using 'end' after the content */
				return ring_parser_bracesandend(pParser,RING_FALSE,K_ENDFUNC) ;
			}
			return x ;
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_FUNCNAME);
			return RING_PARSER_FAIL ;
		}
	}
	/* Statement --> Package Identifier { '.' Identifier } */
	if ( ring_parser_iskeyword(pParser,K_PACKAGE) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_PACKAGE);
		RING_STATE_PRINTRULE(RING_RULE_PACKAGE) ;
		if ( ring_parser_namedotname(pParser) ) {
			/* Add Package to Packages List */
			pMark = ring_parser_icg_getactiveoperation(pParser);
			/* Check early definition of the package */
			for ( x = 1 ; x <= ring_list_getsize(pParser->pRingState->pRingPackagesMap) ; x++ ) {
				pList3 = ring_list_getlist(pParser->pRingState->pRingPackagesMap,x);
				if ( strcmp(ring_list_getstring(pList3,RING_PACKAGES_PACKAGENAME),ring_parser_icg_newpackagename(pParser,pMark)) == 0 ) {
					pParser->pClassesMap = ring_list_getlist(pList3,RING_PACKAGES_CLASSESLIST);
					return RING_PARSER_OK ;
				}
			}
			pList2 = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingPackagesMap);
			/* Add Package Name */
			ring_list_addstring_gc(pParser->pRingState,pList2,ring_parser_icg_newpackagename(pParser,pMark));
			/* Add Package Classes List */
			pParser->pClassesMap = ring_list_newlist_gc(pParser->pRingState,pList2);
			/* Support using { } around the package code and using 'end' after the content */
			return ring_parser_bracesandend(pParser,RING_TRUE,K_ENDPACKAGE) ;
		}
		else {
			return RING_PARSER_FAIL ;
		}
	}
	/* Statement --> Private */
	if ( ring_parser_iskeyword(pParser,K_PRIVATE) ) {
		ring_parser_nexttoken(pParser);
		if ( pParser->lClassStart == 1 ) {
			/* Generate Code */
			ring_parser_icg_retnull(pParser);
			/* Change Label After Class to BlockFlag to Jump to Private */
			pList = ring_parser_icg_getoperationlist(pParser,pParser->nClassMark);
			ring_parser_icg_setopcode(pParser,pList,ICO_BLOCKFLAG);
			ring_parser_icg_addoperandint(pParser,pList,ring_parser_icg_newlabel(pParser));
			ring_parser_icg_newoperation(pParser,ICO_PRIVATE);
			RING_STATE_PRINTRULE(RING_RULE_PRIVATE) ;
			pParser->lPrivateFlag = 1 ;
			return RING_PARSER_OK ;
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_NOCLASSDEFINED);
			return RING_PARSER_FAIL ;
		}
	}
	return ring_parser_stmt(pParser) ;
}

int ring_parser_stmt ( Parser *pParser )
{
	int x,nMark1,nMark2,nMark3,nStart,nEnd,nDiff,lFastLen,nFlag,nLoadPackage,lLoopOrExitCommand,nLoadAgain,nForInVarsCount,nVar,nLine,nLine2  ;
	String *pString  ;
	List *pMark,*pMark2,*pMark3,*pMark4,*pList2  ;
	double nNum1  ;
	char cStr[RING_MEDIUMBUF]  ;
	char cFileName[RING_PATHSIZE]  ;
	char cCurrentDir[RING_PATHSIZE]  ;
	nLoadPackage = 0 ;
	lLoopOrExitCommand = 0 ;
	nLoadAgain = 0 ;
	nLine2 = 0 ;
	/* Statement --> Load Literal */
	if ( ring_parser_iskeyword(pParser,K_LOAD) ) {
		ring_parser_nexttoken(pParser);
		/* Load Package Command */
		if ( ring_parser_iskeyword(pParser,K_PACKAGE) ) {
			ring_parser_nexttoken(pParser);
			nLoadPackage = 1 ;
			pParser->pRingState->nCustomGlobalScopeCounter++ ;
			ring_list_addint_gc(pParser->pRingState,pParser->pRingState->pCustomGlobalScopeStack,pParser->pRingState->nCustomGlobalScopeCounter);
		}
		else if ( ring_parser_iskeyword(pParser,K_AGAIN) ) {
			ring_parser_nexttoken(pParser);
			nLoadAgain = 1 ;
			pParser->pRingState->nLoadAgain++ ;
		}
		if ( ring_parser_isliteral(pParser) ) {
			/* Check File in the Ring/bin folder */
			strcpy(cFileName,pParser->cTokenText);
			if ( ring_general_fexists(pParser->cTokenText) == 0 ) {
				ring_general_exefolder(cFileName);
				strcat(cFileName,pParser->cTokenText);
				if ( ring_general_fexists(cFileName) == 0 ) {
					/* Try ring/bin/load folder */
					ring_general_exefolder(cFileName);
					strcat(cFileName,"load/");
					strcat(cFileName,pParser->cTokenText);
					if ( ring_general_fexists(cFileName) == 0 ) {
						strcpy(cFileName,pParser->cTokenText);
					}
				}
			}
			else {
				/* Add the current folder to the file name */
				ring_general_currentdir(cFileName);
				/* Be Sure that we don't already have the current folder in the file name */
				if ( ring_general_folderexistinfilename(cFileName,pParser->cTokenText) ) {
					strcpy(cFileName,RING_CSTR_EMPTY);
				}
				else {
					ring_general_addosfileseparator(cFileName);
				}
				strcat(cFileName,pParser->cTokenText);
				/*
				**  Check if we have the file after adding the folder - because we may have the file in a parent directory 
				**  Like we are in myapp/myapp2 and the file exist in myapp folder 
				*/
				if ( ring_general_fexists(cFileName) == 0 ) {
					strcpy(cFileName,pParser->cTokenText);
				}
			}
			/*
			**  Generate Code 
			**  Load Package - New Global Scope 
			*/
			if ( nLoadPackage ) {
				ring_parser_icg_newoperation(pParser,ICO_NEWGLOBALSCOPE);
			}
			ring_parser_icg_newoperation(pParser,ICO_FILENAME);
			ring_parser_icg_newoperand(pParser,cFileName);
			ring_parser_icg_newoperation(pParser,ICO_BLOCKFLAG);
			pMark = ring_parser_icg_getactiveoperation(pParser);
			RING_STATE_PRINTRULE(RING_RULE_LOAD ) ;
			/* Set Global Scope */
			ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
			ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->pCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->pCustomGlobalScopeStack)));
			/* No package at the start of the file */
			pParser->pClassesMap = pParser->pRingState->pRingClassesMap ;
			/* Save the Current Directory */
			ring_general_currentdir(cCurrentDir);
			/* Read The File */
			x = ring_state_runfile(pParser->pRingState,cFileName);
			/* Restore the Current Directory */
			ring_general_chdir(cCurrentDir);
			/* Restore Load Again status */
			if ( nLoadAgain ) {
				pParser->pRingState->nLoadAgain-- ;
			}
			/*
			**  Generate Code 
			**  Return NULL 
			*/
			ring_parser_icg_retnull(pParser);
			nMark1 = ring_parser_icg_newlabel(pParser);
			ring_parser_icg_addoperandint(pParser,pMark,nMark1);
			/* Load Package - End Global Scope */
			if ( nLoadPackage ) {
				ring_parser_icg_newoperation(pParser,ICO_ENDGLOBALSCOPE);
				ring_list_deletelastitem_gc(pParser->pRingState,pParser->pRingState->pCustomGlobalScopeStack);
				/* Set Global Scope */
				ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
				ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->pCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->pCustomGlobalScopeStack)));
			}
			/* Set Active File */
			ring_parser_icg_newoperation(pParser,ICO_FILENAME);
			ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
			ring_parser_icg_freestack(pParser);
			ring_parser_nexttoken(pParser);
			return x ;
		}
		return RING_PARSER_FAIL ;
	}
	/* Statement --> See|Put Expr */
	if ( ring_parser_iskeyword(pParser,K_SEE) | ring_parser_iskeyword(pParser,K_PUT) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/* Generate code to use the SEE function */
		x = ring_parser_ringvmsee(pParser);
		RING_STATE_PRINTRULE(RING_RULE_SEEEXPR) ;
		return x ;
	}
	/* Statement --> ? Expr */
	if ( ring_parser_isoperator2(pParser,OP_QUES) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/*
		**  Generate code to use the See function 
		**  Print the Expression 
		*/
		x = ring_parser_ringvmsee(pParser);
		/* Print the New Line */
		ring_parser_icg_loadfunction(pParser,RING_CSTR_RINGVMSEE);
		/* Parameters */
		ring_parser_icg_newoperation(pParser,ICO_PUSHNL);
		ring_parser_icg_newoperation(pParser,ICO_CALL);
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		ring_parser_icg_newoperation(pParser,ICO_NOOP);
		ring_parser_icg_freestack(pParser);
		RING_STATE_PRINTRULE(RING_RULE_QEXPR) ;
		return x ;
		/*
		**  Generate code to use the See function 
		**  Print the Expression 
		*/
		x = ring_parser_ringvmsee(pParser);
		/* Print the New Line */
		ring_parser_icg_loadfunction(pParser,RING_CSTR_RINGVMSEE);
		/* Parameters */
		ring_parser_icg_newoperation(pParser,ICO_PUSHNL);
		ring_parser_icg_newoperation(pParser,ICO_CALL);
		ring_parser_icg_newoperandint(pParser,RING_ZERO);
		ring_parser_icg_newoperation(pParser,ICO_NOOP);
		ring_parser_icg_freestack(pParser);
	}
	/* Statement --> Give|Get Identifier */
	if ( ring_parser_iskeyword(pParser,K_GIVE) | ring_parser_iskeyword(pParser,K_GET) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isidentifier(pParser) ) {
			/* Generate Code */
			ring_parser_icg_loadaddress(pParser,pParser->cTokenText);
			ring_parser_nexttoken(pParser);
			x = ring_parser_mixer(pParser);
			if ( x == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
			/* Generate Code */
			RING_STATE_PRINTRULE(RING_RULE_GIVE) ;
			/* Generate code to use the GIVE function */
			ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
			ring_parser_icg_loadfunction(pParser,RING_CSTR_RINGVMGIVE);
			ring_parser_icg_newoperation(pParser,ICO_CALL);
			ring_parser_icg_newoperandint(pParser,RING_ZERO);
			ring_parser_icg_newoperation(pParser,ICO_NOOP);
			ring_parser_icg_beforeequal(pParser,OP_EQUAL);
			ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
			ring_parser_icg_freestack(pParser);
			return RING_PARSER_OK ;
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_VARNAME);
			return RING_PARSER_FAIL ;
		}
	}
	/* Statement --> For Identifier = Expr to Expr {Statement} Next  |  For Identifier in Expr {Statement } */
	if ( ring_parser_iskeyword(pParser,K_FOR) || ring_parser_iskeyword(pParser,K_FOREACH) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isidentifier(pParser) ) {
			/* Mark for SETOPCODE command */
			ring_parser_icg_newoperation(pParser,ICO_SETOPCODE);
			ring_parser_icg_newoperandint(pParser,ICO_INCJUMP);
			pMark4 = ring_parser_icg_getactiveoperation(pParser);
			pString = ring_string_new_gc(pParser->pRingState,pParser->cTokenText);
			ring_parser_nexttoken(pParser);
			if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
				/*
				**  Generate Code 
				**  Mark for Exit command to go to outside the loop 
				*/
				ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
				pMark3 = ring_parser_icg_getactiveoperation(pParser);
				ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
				ring_parser_icg_newoperand(pParser,ring_string_get(pString));
				ring_parser_nexttoken(pParser);
				pParser->lAssignmentFlag = 0 ;
				if ( ring_parser_expr(pParser) ) {
					/*
					**  Generate Code 
					**  Before Equal ( = ) not += , -= ,... etc 
					*/
					ring_parser_icg_beforeequal(pParser,OP_EQUAL);
					ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
					nLine2 = pParser->nLineNumber ;
					ring_parser_icg_newline(pParser,pParser->nLineNumber);
					nMark1 = ring_parser_icg_newlabel(pParser);
					ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
					ring_parser_icg_newoperand(pParser,ring_string_get(pString));
					if ( ring_parser_iskeyword(pParser,K_TO) ) {
						ring_parser_nexttoken(pParser);
						RING_PARSER_IGNORENEWLINE ;
						pParser->lAssignmentFlag = 0 ;
						if ( ring_parser_csexpr(pParser) ) {
							pParser->lAssignmentFlag = 1 ;
							/* Generate Code */
							nLine = 0 ;
							if ( (ring_parser_icg_getlastoperation(pParser) == ICO_NEWLINE) && (ring_parser_icg_newlabel(pParser) == (nMark1+3)) ) {
								nLine = ring_parser_icg_getoperandint(pParser,RING_PARSER_ICG_PARA1) ;
								ring_parser_icg_deletelastoperation(pParser);
							}
							/* Generate ICO_JUMPFOR */
							if ( ring_parser_icg_getlastoperation(pParser) == ICO_NEWLINE ) {
								nLine = ring_parser_icg_getoperandint(pParser,RING_PARSER_ICG_PARA1) ;
								ring_parser_icg_deletelastoperation(pParser);
							}
							ring_parser_icg_newoperation(pParser,ICO_JUMPFOR);
							pMark = ring_parser_icg_getactiveoperation(pParser);
							if ( nLine != 0 ) {
								ring_parser_icg_newline(pParser,nLine);
							}
							/* Step <expr> */
							x = ring_parser_step(pParser,&nMark1);
							if ( x == RING_PARSER_FAIL ) {
								ring_string_delete_gc(pParser->pRingState,pString);
								return RING_PARSER_FAIL ;
							}
							RING_STATE_PRINTRULE(RING_RULE_FORLOOP) ;
							/* Save Loop|Exit commands status */
							lLoopOrExitCommand = pParser->lLoopOrExitCommand ;
							pParser->nLoopCounter++ ;
							RING_PARSER_ACCEPTSTATEMENTS ;
							pParser->nLoopCounter-- ;
							if ( ring_parser_iskeyword(pParser,K_NEXT) || ring_parser_iskeyword(pParser,K_ENDFOR) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
								/* Generate Code */
								nMark3 = ring_parser_icg_newlabel(pParser);
								/* Increment Jump */
								ring_parser_icg_newoperation(pParser,ICO_INCJUMP);
								ring_parser_icg_newoperand(pParser,ring_string_get(pString));
								ring_parser_icg_newoperandint(pParser,nMark1+1);
								nMark2 = ring_parser_icg_newlabel(pParser);
								ring_parser_icg_newoperation(pParser,ICO_NOOP);
								ring_parser_icg_newoperandint(pParser,nLine2);
								/* Complete JumpFor instruction */
								ring_parser_icg_addoperandint(pParser,pMark,nMark2);
								/*
								**  The ICO_FREETEMPLISTS will be called by ICO_JUMPFOR 
								**  Complete SETOPCODE instruction 
								*/
								ring_parser_icg_addoperandint(pParser,pMark4,nMark2-1);
								/* Restore Loop|Exit Commands Status */
								if ( pParser->lLoopOrExitCommand || ! pParser->lCheckLoopAndExit ) {
									/* Set Exit Mark */
									ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
									/* Set Loop Mark */
									ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
									/* End Loop (Remove Exit Mark) */
									ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
								}
								else {
									ring_parser_icg_setopcode(pParser,pMark3,ICO_NOOP);
								}
								if ( pParser->nLoopCounter == 0 ) {
									pParser->lLoopOrExitCommand = lLoopOrExitCommand ;
								}
								/* POP Step */
								ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
								ring_parser_nexttoken(pParser);
								RING_STATE_PRINTRULE(RING_RULE_NEXT) ;
								ring_string_delete_gc(pParser->pRingState,pString);
								return RING_PARSER_OK ;
							}
							else {
								ring_parser_error(pParser,RING_PARSER_ERROR_NEXT);
							}
						}
					}
				}
			}
			else if ( ring_parser_iskeyword(pParser,K_IN) ) {
				/* Add the reference to the (For-In Loop) variables */
				nForInVarsCount = ring_list_getsize(pParser->pForInVars) + 1 ;
				ring_list_addstring_gc(pParser->pRingState,pParser->pForInVars,ring_string_get(pString));
				/* If the Loop Variable is already a reference, Set it to  NULL with ICO_KILLREFERENCE and parameter (1) */
				ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
				ring_parser_icg_newoperand(pParser,ring_string_get(pString));
				ring_parser_icg_newoperation(pParser,ICO_KILLREFERENCE);
				ring_parser_icg_newoperandint(pParser,RING_TRUE);
				/* Generate Code */
				sprintf( cStr , "n_sys_var_%d" , ring_parser_icg_instructionscount(pParser) ) ;
				/* Mark for Exit command to go to outside the loop */
				ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
				pMark3 = ring_parser_icg_getactiveoperation(pParser);
				ring_parser_icg_loadaddress(pParser,cStr);
				ring_parser_icg_pushn(pParser,RING_ONEF);
				/* Before Equal ( = ) not += , -= ,... etc */
				ring_parser_icg_beforeequal(pParser,OP_EQUAL);
				ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
				/* Generate Code */
				nLine2 = pParser->nLineNumber ;
				ring_parser_icg_newline(pParser,pParser->nLineNumber);
				nMark1 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
				ring_parser_icg_newoperand(pParser,cStr);
				nStart = ring_parser_icg_instructionslistsize(pParser) + 1 ;
				ring_parser_nexttoken(pParser);
				RING_PARSER_IGNORENEWLINE ;
				pParser->lAssignmentFlag = 0 ;
				nLine = pParser->nLineNumber ;
				if ( ring_parser_csexpr(pParser) ) {
					pParser->lAssignmentFlag = 1 ;
					/* Generate Code */
					nEnd = ring_parser_icg_instructionslistsize(pParser) ;
					/* Check if we can avoid pushing the Variable to the Stack and avoid string copy */
					lFastLen = 0 ;
					nDiff = nEnd - nStart ;
					lFastLen = (nDiff==1) && (ring_parser_icg_getoperationatpos(pParser,nStart) == ICO_LOADADDRESS) && (ring_parser_icg_getoperationatpos(pParser,nEnd) == ICO_PUSHV) ;
					lFastLen = lFastLen || ( (nDiff==2) && (ring_parser_icg_getoperationatpos(pParser,nStart) == ICO_LOADADDRESS) && (ring_parser_icg_getoperationatpos(pParser,nStart+1) == ICO_PUSHV) ) ;
					/* Note (nEnd-1) , -1 to remove instruction PushV (avoid error with for x in string) */
					switch ( ring_parser_icg_getlastoperation(pParser) ) {
						case ICO_PUSHV :
							nEnd-- ;
							break ;
						case ICO_NEWLINE :
							/* Check the instruction before ICO_NEWLINE - It could be ICO_PUSHV */
							if ( ring_parser_icg_getoperationbeforelastoperation(pParser) == ICO_PUSHV ) {
								nEnd -= 2 ;
							}
							break ;
					}
					/* Generate ICO_LEN */
					ring_parser_icg_newline(pParser,nLine);
					ring_parser_icg_newoperation(pParser,ICO_LEN);
					/* Disable PUSHV if we have FastLen */
					if ( lFastLen ) {
						ring_parser_icg_setoperationatpos(pParser,nStart+1,ICO_NOOP);
					}
					ring_parser_icg_newoperation(pParser,ICO_JUMPFOR);
					pMark = ring_parser_icg_getactiveoperation(pParser);
					ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
					ring_parser_icg_newoperand(pParser,ring_string_get(pString));
					ring_parser_icg_duplicate(pParser,nStart,nEnd);
					ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
					ring_parser_icg_newoperand(pParser,cStr);
					ring_parser_icg_newoperation(pParser,ICO_LOADINDEXADDRESS);
					/* Item by reference */
					ring_parser_icg_newoperation(pParser,ICO_SETREFERENCE);
					/* Step <expr> */
					x = ring_parser_step(pParser,&nMark1);
					if ( x == RING_PARSER_FAIL ) {
						ring_string_delete_gc(pParser->pRingState,pString);
						return RING_PARSER_FAIL ;
					}
					RING_STATE_PRINTRULE(RING_RULE_FORINLOOP) ;
					/* Save Loop|Exit commands status */
					lLoopOrExitCommand = pParser->lLoopOrExitCommand ;
					pParser->nLoopCounter++ ;
					RING_PARSER_ACCEPTSTATEMENTS ;
					pParser->nLoopCounter-- ;
					if ( ring_parser_iskeyword(pParser,K_NEXT) || ring_parser_iskeyword(pParser,K_ENDFOR) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
						ring_parser_nexttoken(pParser);
						/* Generate Code */
						nMark3 = ring_parser_icg_newlabel(pParser);
						/* Increment Jump */
						ring_parser_icg_newoperation(pParser,ICO_INCJUMP);
						ring_parser_icg_newoperand(pParser,cStr);
						ring_parser_icg_newoperandint(pParser,nMark1+1);
						nMark2 = ring_parser_icg_newlabel(pParser);
						ring_parser_icg_newoperation(pParser,ICO_NOOP);
						ring_parser_icg_newoperandint(pParser,nLine2);
						/* Complete SETOPCODE instruction */
						ring_parser_icg_addoperandint(pParser,pMark4,nMark2-1);
						/* Complete JumpFor instruciton */
						ring_parser_icg_addoperandint(pParser,pMark,nMark2);
						/*
						**  The ICO_FREETEMPLISTS will be called by ICO_JUMPFOR 
						**  Restore Loop|Exit Commands Status 
						*/
						if ( pParser->lLoopOrExitCommand || ! pParser->lCheckLoopAndExit ) {
							/* Set Exit Mark */
							ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
							/* Set Loop Mark */
							ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
							/* End Loop (Remove Exit Mark) */
							ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
						}
						else {
							ring_parser_icg_setopcode(pParser,pMark3,ICO_NOOP);
						}
						if ( pParser->nLoopCounter == 0 ) {
							pParser->lLoopOrExitCommand = lLoopOrExitCommand ;
						}
						/* POP Step */
						ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
						/* Remove Reference Value */
						for ( nVar = nForInVarsCount ; nVar <= ring_list_getsize(pParser->pForInVars) ; nVar++ ) {
							ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
							ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pForInVars,nVar));
							ring_parser_icg_newoperation(pParser,ICO_KILLREFERENCE);
						}
						ring_parser_icg_newoperation(pParser,ICO_OPTIONALLOOP);
						if ( nForInVarsCount == 1 ) {
							ring_list_deleteallitems_gc(pParser->pRingState,pParser->pForInVars);
						}
						/* Print the rule */
						RING_STATE_PRINTRULE(RING_RULE_NEXT) ;
						ring_string_delete_gc(pParser->pRingState,pString);
						return RING_PARSER_OK ;
					}
					else {
						ring_parser_error(pParser,RING_PARSER_ERROR_NEXT);
					}
				}
			}
			ring_string_delete_gc(pParser->pRingState,pString);
		}
		return RING_PARSER_FAIL ;
	}
	/* Statement --> IF Expr Statements OK */
	if ( ring_parser_iskeyword(pParser,K_IF) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		pParser->lAssignmentFlag = 0 ;
		if ( ring_parser_csexpr(pParser) ) {
			pParser->lAssignmentFlag = 1 ;
			/*
			**  First Condition 
			**  Generate Code 
			*/
			ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
			pMark = ring_parser_icg_getactiveoperation(pParser);
			RING_STATE_PRINTRULE(RING_RULE_IFSTATEMENT) ;
			RING_PARSER_ACCEPTSTATEMENTS ;
			/* Generate Code */
			pList2 = ring_list_new_gc(pParser->pRingState,RING_ZERO);
			ring_parser_icg_newoperation(pParser,ICO_JUMP);
			ring_list_addpointer_gc(pParser->pRingState,pList2,ring_parser_icg_getactiveoperation(pParser));
			/* { 'But' Statements } 'Else' Statements */
			while ( ring_parser_iskeyword(pParser,K_BUT) || ring_parser_iskeyword(pParser,K_ELSEIF) ) {
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark1);
				ring_parser_nexttoken(pParser);
				pParser->lAssignmentFlag = 0 ;
				if ( ring_parser_expr(pParser) ) {
					pParser->lAssignmentFlag = 1 ;
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
					pMark = ring_parser_icg_getactiveoperation(pParser);
					RING_STATE_PRINTRULE(RING_RULE_BUT) ;
					RING_PARSER_ACCEPTSTATEMENTS ;
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_JUMP);
					ring_list_addpointer_gc(pParser->pRingState,pList2,ring_parser_icg_getactiveoperation(pParser));
				}
			}
			if ( ring_parser_iskeyword(pParser,K_ELSE) || ring_parser_iskeyword(pParser,K_OTHER) ) {
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark1);
				pMark = NULL ;
				ring_parser_nexttoken(pParser);
				RING_STATE_PRINTRULE(RING_RULE_ELSE) ;
				RING_PARSER_ACCEPTSTATEMENTS ;
			}
			if ( ring_parser_iskeyword(pParser,K_OK) || ring_parser_iskeyword(pParser,K_ENDIF)  || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				if ( pMark != NULL ) {
					ring_parser_icg_addoperandint(pParser,pMark,nMark1);
				}
				if ( ring_list_getsize(pList2) > 0 ) {
					for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
						ring_parser_icg_addoperandint(pParser,((RING_PARSER_ICG_INSTRUCTIONSLISTTYPE *) ring_list_getpointer(pList2,x)),nMark1);
					}
				}
				ring_list_delete_gc(pParser->pRingState,pList2);
				ring_parser_nexttoken(pParser);
				RING_STATE_PRINTRULE(RING_RULE_OK) ;
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_OK);
				ring_list_delete_gc(pParser->pRingState,pList2);
			}
		}
		return RING_PARSER_FAIL ;
	}
	/* Statement --> WHILE Expr Statements END */
	if ( ring_parser_iskeyword(pParser,K_WHILE) ) {
		/*
		**  Generate Code 
		**  Set Step Number - Since We have Exit/Loop commands controls a mix of (For/While/... loops) 
		*/
		ring_parser_icg_newoperation(pParser,ICO_STEPFROMREG);
		ring_parser_icg_newoperanddouble(pParser,RING_ZEROF);
		/* Mark for Exit command to go to outsize the loop */
		ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
		pMark3 = ring_parser_icg_getactiveoperation(pParser);
		nMark1 = ring_parser_icg_newlabel(pParser);
		ring_parser_icg_newline(pParser,pParser->nLineNumber);
		/* Free Temp Lists */
		ring_parser_icg_genfreetemplists(pParser);
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		pParser->lAssignmentFlag = 0 ;
		if ( ring_parser_csexpr(pParser) ) {
			pParser->lAssignmentFlag = 1 ;
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
			pMark = ring_parser_icg_getactiveoperation(pParser);
			RING_STATE_PRINTRULE(RING_RULE_WHILELOOP) ;
			/* Save Loop|Exit commands status */
			lLoopOrExitCommand = pParser->lLoopOrExitCommand ;
			pParser->nLoopCounter++ ;
			RING_PARSER_ACCEPTSTATEMENTS ;
			pParser->nLoopCounter-- ;
			if ( ring_parser_iskeyword(pParser,K_END) || ring_parser_iskeyword(pParser,K_ENDWHILE) || ring_parser_csbraceend(pParser) ) {
				/* Generate Code */
				nMark3 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_newoperation(pParser,ICO_JUMP);
				ring_parser_icg_newoperandint(pParser,nMark1);
				nMark2 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark2);
				/* Restore Loop|Exit Commands Status */
				if ( pParser->lLoopOrExitCommand || ! pParser->lCheckLoopAndExit ) {
					/* Set Exit Mark */
					ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
					/* Set Loop Mark */
					ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
					/* End Loop (Remove Exit Mark) */
					ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
				}
				else {
					ring_parser_icg_setopcode(pParser,pMark3,ICO_NOOP);
				}
				if ( pParser->nLoopCounter == 0 ) {
					pParser->lLoopOrExitCommand = lLoopOrExitCommand ;
				}
				/* POP Step */
				ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
				ring_parser_nexttoken(pParser);
				RING_STATE_PRINTRULE(RING_RULE_END) ;
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_END);
			}
		}
		return RING_PARSER_FAIL ;
	}
	/* Statement --> DO Statements AGAIN Expr */
	if ( ring_parser_iskeyword(pParser,K_DO) ) {
		/*
		**  Generate Code 
		**  Set Step Number - Since We have Exit/Loop commands controls a mix of (For/While/... loops) 
		*/
		ring_parser_icg_newoperation(pParser,ICO_STEPFROMREG);
		ring_parser_icg_newoperanddouble(pParser,RING_ZEROF);
		/* Mark for Exit command to go to outsize the loop */
		ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
		pMark3 = ring_parser_icg_getactiveoperation(pParser);
		nMark1 = ring_parser_icg_newlabel(pParser);
		/* Free Temp Lists */
		ring_parser_icg_genfreetemplists(pParser);
		RING_STATE_PRINTRULE(RING_RULE_DOAGAINLOOP) ;
		ring_parser_nexttoken(pParser);
		/* Save Loop|Exit commands status */
		lLoopOrExitCommand = pParser->lLoopOrExitCommand ;
		pParser->nLoopCounter++ ;
		RING_PARSER_ACCEPTSTATEMENTS ;
		pParser->nLoopCounter-- ;
		if ( ring_parser_iskeyword(pParser,K_AGAIN) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			pParser->lAssignmentFlag = 0 ;
			if ( ring_parser_expr(pParser) ) {
				/* Generate Code (Test Condition) */
				ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
				pMark = ring_parser_icg_getactiveoperation(pParser);
				/* Generate Code */
				nMark3 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_newoperation(pParser,ICO_JUMP);
				ring_parser_icg_newoperandint(pParser,nMark1);
				nMark2 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark,nMark2);
				/* Restore Loop|Exit Commands Status */
				if ( pParser->lLoopOrExitCommand || ! pParser->lCheckLoopAndExit ) {
					/* Set Exit Mark */
					ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
					/* Set Loop Mark */
					ring_parser_icg_addoperandint(pParser,pMark3,nMark1);
					/* End Loop (Remove Exit Mark) */
					ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
				}
				else {
					ring_parser_icg_setopcode(pParser,pMark3,ICO_NOOP);
				}
				if ( pParser->nLoopCounter == 0 ) {
					pParser->lLoopOrExitCommand = lLoopOrExitCommand ;
				}
				/* POP Step */
				ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
				pParser->lAssignmentFlag = 1 ;
				RING_STATE_PRINTRULE(RING_RULE_AGAINEXPR) ;
				return RING_PARSER_OK ;
			}
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_AGAIN);
		}
		return RING_PARSER_FAIL ;
	}
	/* Statement --> Return Expr */
	if ( ring_parser_iskeyword(pParser,K_RETURN) ) {
		ring_parser_nexttoken(pParser);
		x = RING_PARSER_OK ;
		if ( ring_parser_isendline(pParser) == 0 ) {
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_FREELOADASCOPE);
			pParser->lAssignmentFlag = 0 ;
			x = ring_parser_expr(pParser);
			pParser->lAssignmentFlag = 1 ;
			/* Generate Code */
			if ( x == RING_PARSER_OK ) {
				ring_parser_icg_returnn(pParser);
			}
			else {
				/*
				**  Generate Code 
				**  Return NULL 
				*/
				ring_parser_icg_retnull(pParser);
			}
		}
		else {
			/*
			**  Generate Code 
			**  Return NULL 
			*/
			ring_parser_icg_retnull(pParser);
		}
		if ( x == RING_PARSER_OK ) {
			RING_STATE_PRINTRULE(RING_RULE_RETURN) ;
		}
		return x ;
	}
	/* Statement --> Try {Statement} Catch {Statement} Done */
	if ( ring_parser_iskeyword(pParser,K_TRY) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
			ring_parser_nexttoken(pParser);
			pParser->nControlStructureBrace++ ;
		}
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_TRY);
		pMark = ring_parser_icg_getactiveoperation(pParser);
		RING_STATE_PRINTRULE(RING_RULE_TRYCATCHDONE) ;
		RING_PARSER_ACCEPTSTATEMENTS ;
		if ( ring_parser_iskeyword(pParser,K_CATCH) ) {
			ring_parser_nexttoken(pParser);
			/*
			**  Generate Code 
			**  Jump from end of try block to label after done 
			*/
			ring_parser_icg_newoperation(pParser,ICO_JUMP);
			pMark2 = ring_parser_icg_getactiveoperation(pParser);
			nMark1 = ring_parser_icg_newlabel(pParser);
			ring_parser_icg_addoperandint(pParser,pMark,nMark1);
			RING_STATE_PRINTRULE(RING_RULE_CATCH) ;
			RING_PARSER_ACCEPTSTATEMENTS ;
			if ( ring_parser_iskeyword(pParser,K_DONE) || ring_parser_iskeyword(pParser,K_ENDTRY) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
				RING_STATE_PRINTRULE(RING_RULE_DONE) ;
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				ring_parser_icg_newoperation(pParser,ICO_JUMP);
				pMark3 = ring_parser_icg_getactiveoperation(pParser);
				nMark2 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark2,nMark2);
				ring_parser_icg_newoperation(pParser,ICO_DONE);
				nMark3 = ring_parser_icg_newlabel(pParser);
				ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_NODONE);
			}
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_NOCATCH);
		}
	}
	/* Statement --> Bye (Close the Program) */
	if ( ring_parser_iskeyword(pParser,K_BYE) ) {
		ring_parser_nexttoken(pParser);
		RING_STATE_PRINTRULE(RING_RULE_BYE) ;
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_BYE);
		return RING_PARSER_OK ;
	}
	/* Statement --> Exit (Go to outside the loop) */
	if ( ring_parser_iskeyword(pParser,K_EXIT) || ring_parser_iskeyword(pParser,K_BREAK) ) {
		ring_parser_nexttoken(pParser);
		RING_STATE_PRINTRULE(RING_RULE_EXIT) ;
		/* Check usage outside loops */
		if ( ! pParser->nLoopCounter ) {
			if ( pParser->pRingState->lWarning ) {
				puts(RING_WARNING_EXITOUTSIDELOOP);
			}
		}
		/* Check Number  (Exit from more than one loop) */
		if ( ring_parser_isnumber(pParser) || ring_parser_isidentifier(pParser) ) {
			if ( ring_parser_expr(pParser) == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
		}
		else {
			ring_parser_icg_pushn(pParser,RING_ONEF);
		}
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_EXIT);
		pParser->lLoopOrExitCommand = 1 ;
		return RING_PARSER_OK ;
	}
	/* Statement --> Loop (Continue) */
	if ( ring_parser_iskeyword(pParser,K_LOOP) || ring_parser_iskeyword(pParser,K_CONTINUE) ) {
		ring_parser_nexttoken(pParser);
		RING_STATE_PRINTRULE(RING_RULE_LOOP) ;
		/* Check usage outside loops */
		if ( ! pParser->nLoopCounter ) {
			if ( pParser->pRingState->lWarning ) {
				puts(RING_WARNING_LOOPOUTSIDELOOP);
			}
		}
		/* Check Number  (Continue from more than one loop) */
		if ( ring_parser_isnumber(pParser) || ring_parser_isidentifier(pParser) ) {
			if ( ring_parser_expr(pParser) == RING_PARSER_FAIL ) {
				return RING_PARSER_FAIL ;
			}
		}
		else {
			ring_parser_icg_pushn(pParser,RING_ONEF);
		}
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_LOOP);
		pParser->lLoopOrExitCommand = 1 ;
		return RING_PARSER_OK ;
	}
	/* Statement --> Switch  Expr { ON|CASE Expr {Statement} } OFF */
	if ( ring_parser_iskeyword(pParser,K_SWITCH) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		pParser->lAssignmentFlag = 0 ;
		if ( ring_parser_csexpr(pParser) ) {
			pParser->lAssignmentFlag = 1 ;
			RING_STATE_PRINTRULE(RING_RULE_SWITCH) ;
			RING_PARSER_IGNORENEWLINE ;
			/* ON|CASE Statements */
			pList2 = ring_list_new_gc(pParser->pRingState,RING_ZERO);
			pMark = NULL ;
			while ( ring_parser_iskeyword(pParser,K_ON) || ring_parser_iskeyword(pParser,K_CASE) ) {
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				if ( pMark != NULL ) {
					ring_parser_icg_addoperandint(pParser,pMark,nMark1);
				}
				ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
				pParser->lAssignmentFlag = 0 ;
				if ( ring_parser_expr(pParser) ) {
					pParser->lAssignmentFlag = 1 ;
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_EQUAL);
					ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
					pMark = ring_parser_icg_getactiveoperation(pParser);
					ring_parser_icg_freestack(pParser);
					RING_STATE_PRINTRULE(RING_RULE_ONEXPR) ;
					RING_PARSER_ACCEPTSTATEMENTS ;
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_JUMP);
					ring_list_addpointer_gc(pParser->pRingState,pList2,ring_parser_icg_getactiveoperation(pParser));
				}
			}
			/* Other */
			if ( ring_parser_iskeyword(pParser,K_OTHER) || ring_parser_iskeyword(pParser,K_ELSE) ) {
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				if ( pMark != NULL ) {
					ring_parser_icg_addoperandint(pParser,pMark,nMark1);
					pMark = NULL ;
				}
				ring_parser_icg_freestack(pParser);
				RING_STATE_PRINTRULE(RING_RULE_OTHER) ;
				RING_PARSER_ACCEPTSTATEMENTS ;
			}
			/* OFF */
			if ( ring_parser_iskeyword(pParser,K_OFF) || ring_parser_iskeyword(pParser,K_ENDSWITCH) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
				ring_parser_nexttoken(pParser);
				/* Generate Code */
				nMark1 = ring_parser_icg_newlabel(pParser);
				if ( pMark != NULL ) {
					ring_parser_icg_addoperandint(pParser,pMark,nMark1);
				}
				if ( ring_list_getsize(pList2) > 0 ) {
					for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
						ring_parser_icg_addoperandint(pParser,((RING_PARSER_ICG_INSTRUCTIONSLISTTYPE *) ring_list_getpointer(pList2,x)),nMark1);
					}
				}
				ring_list_delete_gc(pParser->pRingState,pList2);
				ring_parser_icg_freestack(pParser);
				RING_STATE_PRINTRULE(RING_RULE_OFF) ;
				return RING_PARSER_OK ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_SWITCHOFF);
			}
		}
		else {
			ring_parser_error(pParser,RING_PARSER_ERROR_SWITCHEXPR);
		}
	}
	/* Statement --> Import Identifier { '.' Identifier } */
	if ( ring_parser_iskeyword(pParser,K_IMPORT) ) {
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_IMPORT);
		RING_STATE_PRINTRULE(RING_RULE_IMPORT) ;
		return ring_parser_namedotname(pParser) ;
	}
	/* Statement --> epsilon */
	if ( ring_parser_epsilon(pParser) ) {
		return RING_PARSER_OK ;
	}
	/* Statement --> Expr */
	if ( ring_parser_expr(pParser) ) {
		RING_STATE_PRINTRULE(RING_RULE_EXPR) ;
		/*
		**  Generate Code 
		**  Call expreval() if we are inside { } 
		*/
		if ( pParser->nBracesCounter ) {
			/* if ismethod(self,"braceexpreval") braceexpreval() ok */
			ring_parser_icg_gencallbracemethod(pParser,RING_CSTR_BRACEEXPREVAL,RING_TRUE);
		}
		ring_parser_icg_freestack(pParser);
		return RING_PARSER_OK ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_paralist ( Parser *pParser )
{
	int nStart, nParaCount, lDuplication  ;
	const char *cToken, *cArguments  ;
	char *cPos  ;
	char cChar  ;
	/* Check ( */
	nStart = 0 ;
	nParaCount = 0 ;
	if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
		ring_parser_nexttoken(pParser);
		nStart = 1 ;
	}
	/* ParaList --> epsilon */
	if ( ring_parser_isendline(pParser) || (nStart && ring_parser_isoperator2(pParser,OP_FCLOSE) ) ) {
		ring_parser_nexttoken(pParser);
		RING_STATE_PRINTRULE(RING_RULE_PARALISTEPSILON) ;
		return RING_PARSER_OK ;
	}
	/* ParaList --> [ Identifier { , Identifier }  ] */
	if ( ring_parser_isidentifier(pParser) ) {
		cToken = pParser->cTokenText ;
		ring_parser_nexttoken(pParser);
		/* Support Type Identifier */
		if ( nStart && ring_parser_isidentifier(pParser) ) {
			cToken = pParser->cTokenText ;
			ring_parser_nexttoken(pParser);
		}
		/* Generate Code */
		ring_parser_icg_newoperand(pParser,cToken);
		RING_STATE_PRINTRULE(RING_RULE_PARALISTIDENTIFIER) ;
		nParaCount++ ;
		while ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
			ring_parser_nexttoken(pParser);
			RING_PARSER_IGNORENEWLINE ;
			if ( ring_parser_isidentifier(pParser) ) {
				cToken = pParser->cTokenText ;
				ring_parser_nexttoken(pParser);
				/* Support Type Identifier */
				if ( nStart && ring_parser_isidentifier(pParser) ) {
					cToken = pParser->cTokenText ;
					ring_parser_nexttoken(pParser);
				}
				/* Check Duplication */
				cArguments = ring_parser_icg_getlaststring(pParser) ;
				lDuplication = (strcmp(cToken,cArguments) == 0) ;
				if ( ! lDuplication ) {
					cPos = ring_string_find3_gc(pParser->pRingState,(char *) cArguments,strlen(cArguments),(char *) cToken,strlen(cToken)) ;
					if ( cPos != NULL ) {
						cChar = cPos[strlen(cToken)] ;
						/* We must get space after the argument or \0 character */
						if ( (cChar == ' ' ) || (cChar == '\0') ) {
							if ( cPos == cArguments ) {
								lDuplication = 1 ;
							}
							else {
								/* We must have space before the argument (We already know it's not the first) */
								cPos-- ;
								if ( cPos[0] == ' ' ) {
									lDuplication = 1 ;
								}
							}
						}
					}
				}
				if ( lDuplication ) {
					ring_parser_error(pParser,RING_PARSER_ERROR_ARGREDEFINE);
					return RING_PARSER_FAIL ;
				}
				/* Generate Code */
				ring_parser_icg_addtooperand(pParser," ");
				ring_parser_icg_addtooperand(pParser,cToken);
				nParaCount++ ;
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_PARALIST);
				return RING_PARSER_FAIL ;
			}
		}
		if ( nStart && ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
			ring_parser_nexttoken(pParser);
		}
		ring_parser_icg_newoperandint(pParser,nParaCount);
		return RING_PARSER_OK ;
	}
	else {
		ring_parser_error(pParser,RING_PARSER_ERROR_PARALIST);
		return RING_PARSER_FAIL ;
	}
}

int ring_parser_list ( Parser *pParser )
{
	/* "["  [ Expr { , Expr } ] "]" */
	if ( ring_parser_isoperator2(pParser,OP_LOPEN) ) {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_LISTSTART);
		ring_parser_nexttoken(pParser);
		RING_PARSER_IGNORENEWLINE ;
		if ( ring_parser_isoperator2(pParser,OP_LCLOSE) ) {
			ring_parser_nexttoken(pParser);
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_LISTEND);
			RING_STATE_PRINTRULE(RING_RULE_LIST) ;
			return RING_PARSER_OK ;
		}
		while ( 1 ) {
			pParser->lAssignmentFlag = 0 ;
			if ( ring_parser_expr(pParser) ) {
				/* Generate Code */
				ring_parser_icg_listitem(pParser);
				pParser->lNewObject = 0 ;
				pParser->lAssignmentFlag = 1 ;
				RING_PARSER_IGNORENEWLINE ;
				if ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
					ring_parser_nexttoken(pParser);
				}
				else if ( ring_parser_isoperator2(pParser,OP_LCLOSE) ) {
					ring_parser_nexttoken(pParser);
					RING_STATE_PRINTRULE(RING_RULE_LIST) ;
					/* Generate Code */
					ring_parser_icg_newoperation(pParser,ICO_LISTEND);
					return RING_PARSER_OK ;
				}
				else {
					ring_parser_error(pParser,RING_PARSER_ERROR_LISTITEM);
					return RING_PARSER_FAIL ;
				}
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_LISTITEM);
				return RING_PARSER_FAIL ;
			}
			RING_PARSER_IGNORENEWLINE ;
		}
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_epsilon ( Parser *pParser )
{
	if ( ring_parser_isendline(pParser) ) {
		pParser->nLineNumber = atoi(pParser->cTokenText) ;
		/* Generate Code */
		ring_parser_icg_newline(pParser,pParser->nLineNumber);
		RING_STATE_CHECKPRINTRULES
		printf( "\nLine %d \n",pParser->nLineNumber ) ;
		if ( ring_parser_nexttoken(pParser) ) {
			return RING_PARSER_OK ;
		}
		if ( pParser->nTokensCount == 1 ) {
			return RING_PARSER_OK ;
		}
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_passepsilon ( Parser *pParser )
{
	/* used after factor - identifier to allow {  } in new line */
	if ( ring_parser_isendline(pParser) ) {
		pParser->nLineNumber = atoi(pParser->cTokenText) ;
		if ( ring_parser_nexttoken(pParser) ) {
			return RING_PARSER_OK ;
		}
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_namedotname ( Parser *pParser )
{
	String *pString  ;
	if ( ring_parser_isidentifier(pParser) ) {
		/* Get Token Text */
		pString = ring_string_new_gc(pParser->pRingState,pParser->cTokenText);
		ring_parser_nexttoken(pParser);
		while ( ring_parser_isoperator2(pParser,OP_DOT) ) {
			ring_parser_nexttoken(pParser);
			ring_string_add_gc(pParser->pRingState,pString,".");
			if ( ring_parser_isidentifier(pParser) ) {
				ring_string_add_gc(pParser->pRingState,pString,pParser->cTokenText);
				ring_parser_nexttoken(pParser);
			}
			else {
				ring_parser_error(pParser,RING_PARSER_ERROR_PACKAGENAME);
				ring_string_delete_gc(pParser->pRingState,pString);
				return RING_PARSER_FAIL ;
			}
		}
		/* Generate Code */
		ring_parser_icg_newoperand(pParser,ring_string_get(pString));
		ring_string_delete_gc(pParser->pRingState,pString);
		return RING_PARSER_OK ;
	}
	else {
		ring_parser_error(pParser,RING_PARSER_ERROR_PACKAGENAME);
		return RING_PARSER_FAIL ;
	}
}

int ring_parser_step ( Parser *pParser,int *nMark1 )
{
	/* Step <expr> */
	pParser->lInsertFlag = 1 ;
	pParser->nInsertCounter = *nMark1 - 1 - pParser->pRingState->nInstructionsCount ;
	if ( ring_parser_iskeyword(pParser,K_STEP) ) {
		ring_parser_nexttoken(pParser);
		pParser->lAssignmentFlag = 0 ;
		if ( ring_parser_csexpr(pParser) ) {
			pParser->lAssignmentFlag = 1 ;
			/* Generate Code */
			ring_parser_icg_newoperation(pParser,ICO_STEPNUMBER);
		}
		else {
			return RING_PARSER_FAIL ;
		}
	}
	else {
		/* Generate Code */
		ring_parser_icg_newoperation(pParser,ICO_STEPFROMREG);
		ring_parser_icg_newoperanddouble(pParser,RING_ONEF);
	}
	*nMark1 = pParser->nInsertCounter + 1 + pParser->pRingState->nInstructionsCount ;
	pParser->lInsertFlag = 0 ;
	pParser->nInsertCounter = 0 ;
	return RING_PARSER_OK ;
}

int ring_parser_csexpr ( Parser *pParser )
{
	int nOutput  ;
	pParser->lControlStructureExpr = 1 ;
	nOutput = ring_parser_expr(pParser);
	if ( nOutput == 0 ) {
		ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
	}
	pParser->lControlStructureExpr = 0 ;
	RING_PARSER_IGNORENEWLINE ;
	if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
		ring_parser_nexttoken(pParser);
		pParser->nControlStructureBrace++ ;
	}
	return nOutput ;
}

int ring_parser_csbraceend ( Parser *pParser )
{
	if ( (pParser->nControlStructureBrace >= 1) && ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
		pParser->nControlStructureBrace-- ;
		return RING_PARSER_OK ;
	}
	return RING_PARSER_FAIL ;
}

int ring_parser_bracesandend ( Parser *pParser,int lClass,SCANNER_KEYWORD nKeyword )
{
	/*
	**  This function is used to support braces { } around packages/classes/functions 
	**  Also support using 'end' after packages/classes/functions 
	**  IF The Parameter : lClass = True we call ring_parser_class() instead of ring_parser_stmt() 
	**  When we support braces { } 
	**  But the support for 'end' always uses ring_parser_class() 
	**  Support using { } 
	*/
	RING_PARSER_IGNORENEWLINE ;
	if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
		ring_parser_nexttoken(pParser);
		if ( lClass ) {
			while ( ring_parser_class(pParser) ) {
				if ( pParser->nActiveToken == pParser->nTokensCount ) {
					break ;
				}
			}
		}
		else {
			RING_PARSER_ACCEPTSTATEMENTS ;
		}
		if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
			ring_parser_nexttoken(pParser);
			return RING_PARSER_OK ;
		}
		return RING_PARSER_FAIL ;
	}
	/* Support using End */
	while ( ring_parser_class(pParser) ) {
		if ( pParser->nActiveToken == pParser->nTokensCount ) {
			break ;
		}
	}
	if ( ring_parser_iskeyword(pParser,K_END) || ring_parser_iskeyword(pParser,nKeyword) || ( (nKeyword == K_ENDFUNC) && ring_parser_iskeyword(pParser,K_ENDFUNCTION)) ) {
		ring_parser_nexttoken(pParser);
		RING_STATE_PRINTRULE(RING_RULE_END) ;
	}
	return RING_PARSER_OK ;
}

int ring_parser_ringvmsee ( Parser *pParser )
{
	int x,nFlag  ;
	/* Generate code to use the SEE function */
	ring_parser_icg_loadfunction(pParser,RING_CSTR_RINGVMSEE);
	/* Parameters */
	nFlag = pParser->lAssignmentFlag ;
	pParser->lAssignmentFlag = 0 ;
	x = ring_parser_expr(pParser);
	pParser->lAssignmentFlag = nFlag ;
	if ( x == RING_PARSER_FAIL ) {
		ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
		return RING_PARSER_FAIL ;
	}
	ring_parser_icg_newoperation(pParser,ICO_CALL);
	ring_parser_icg_newoperandint(pParser,RING_ZERO);
	ring_parser_icg_newoperation(pParser,ICO_NOOP);
	ring_parser_icg_freestack(pParser);
	return x ;
}
