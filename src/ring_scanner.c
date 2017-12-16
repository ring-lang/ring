/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Keywords */
const char * RING_KEYWORDS[] = {"IF","TO","OR","AND","NOT","FOR","NEW","FUNC", 

"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","RETURN","BUT", 

"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF", 

"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL","ELSEIF", 

"PUT","GET","CASE","DEF","ENDFUNC","ENDCLASS","ENDPACKAGE", 

"CHANGERINGKEYWORD","CHANGERINGOPERATOR","LOADSYNTAX"} ;
/* Functions */

Scanner * ring_scanner_new ( RingState *pRingState )
{
	Scanner *pScanner  ;
	pScanner = (Scanner *) ring_state_malloc(pRingState,sizeof(Scanner));
	if ( pScanner == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	pScanner->pRingState = pRingState ;
	pScanner->state = SCANNER_STATE_GENERAL ;
	pScanner->ActiveToken = ring_string_new_gc(pRingState,"");
	pScanner->Tokens = ring_list_new_gc(pRingState,0);
	ring_scanner_keywords(pScanner);
	ring_scanner_operators(pScanner);
	pScanner->LinesCount = 1 ;
	pScanner->FloatMark = 0 ;
	pScanner->cMLComment = 0 ;
	pScanner->nTokenIndex = 0 ;
	return pScanner ;
}

Scanner * ring_scanner_delete ( Scanner *pScanner )
{
	assert(pScanner != NULL);
	pScanner->Keywords = ring_list_delete_gc(pScanner->pRingState,pScanner->Keywords);
	pScanner->Operators = ring_list_delete_gc(pScanner->pRingState,pScanner->Operators);
	pScanner->Tokens = ring_list_delete_gc(pScanner->pRingState,pScanner->Tokens);
	pScanner->ActiveToken = ring_string_delete_gc(pScanner->pRingState,pScanner->ActiveToken);
	ring_state_free(pScanner->pRingState,pScanner);
	return NULL ;
}

int ring_scanner_readfile ( RingState *pRingState,char *cFileName )
{
	RING_FILE fp  ;
	/* Must be signed char to work fine on Android, because it uses -1 as NULL instead of Zero */
	signed char c  ;
	Scanner *pScanner  ;
	VM *pVM  ;
	int nCont,nRunVM,nFreeFilesList = 0 ;
	char cStartup[30]  ;
	int x,nSize  ;
	char cFileName2[200]  ;
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState,0);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState,0);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		nFreeFilesList = 1 ;
	} else {
		if ( ring_list_findstring(pRingState->pRingFilesList,cFileName,0) == 0 ) {
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		} else {
			if ( pRingState->nWarning ) {
				printf( "\nWarning, Duplication in FileName, %s \n",cFileName ) ;
			}
			return 1 ;
		}
	}
	/* Switch To File Folder */
	strcpy(cFileName2,cFileName);
	fp = RING_OPENFILE(cFileName , "r");
	/* Avoid switching if it's the first file */
	if ( nFreeFilesList == 0 ) {
		ring_switchtofilefolder(cFileName2);
	}
	/* Read File */
	if ( fp==NULL ) {
		printf( "\nCan't open file %s \n",cFileName ) ;
		return 0 ;
	}
	RING_READCHAR(fp,c,nSize);
	pScanner = ring_scanner_new(pRingState);
	/* Check Startup file */
	if ( ring_fexists("startup.ring") && pScanner->pRingState->lStartup == 0 ) {
		pScanner->pRingState->lStartup = 1 ;
		strcpy(cStartup,"Load 'startup.ring'");
		/* Load "startup.ring" */
		for ( x = 0 ; x < 19 ; x++ ) {
			ring_scanner_readchar(pScanner,cStartup[x]);
		}
		/*
		**  Add new line 
		**  We add this here instead of using \n in load 'startup.ring' 
		**  To avoid increasing the line number of the code 
		**  so the first line in the source code file still the first line (not second line) 
		*/
		ring_string_setfromint_gc(pRingState,pScanner->ActiveToken,0);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
	}
	nSize = 1 ;
	while ( (c != EOF) && (nSize != 0) ) {
		ring_scanner_readchar(pScanner,c);
		RING_READCHAR(fp,c,nSize);
	}
	nCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	RING_CLOSEFILE(fp);
	/* Print Tokens */
	if ( pRingState->nPrintTokens ) {
		ring_scanner_printtokens(pScanner);
	}
	/* Call Parser */
	if ( nCont == 1 ) {
		#if RING_PARSERTRACE
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_print_line();
			puts("Grammar Rules Used by The Parser ");
			ring_print_line();
			printf( "\nRule : Program --> {Statement}\n\nLine 1\n" ) ;
		}
		#endif
		nRunVM = ring_parser_start(pScanner->Tokens,pRingState);
		#if RING_PARSERTRACE
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_print_line();
			printf( "\n" ) ;
		}
		#endif
	} else {
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		ring_scanner_delete(pScanner);
		return 0 ;
	}
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( nFreeFilesList ) {
		/* Generate the Object File */
		if ( pRingState->nGenObj ) {
			ring_objfile_writefile(pRingState);
		}
		/* Run the Program */
		#if RING_RUNVM
		if ( nRunVM == 1 ) {
			/* Add return to the end of the program */
			ring_scanner_addreturn(pRingState);
			if ( pRingState->nPrintIC ) {
				ring_parser_icg_showoutput(pRingState->pRingGenCode,1);
			}
			if ( ! pRingState->nRun ) {
				return 1 ;
			}
			pVM = ring_vm_new(pRingState);
			ring_vm_start(pRingState,pVM);
			if ( ! pRingState->nDontDeleteTheVM ) {
				ring_vm_delete(pVM);
			}
		}
		#endif
		/* Display Generated Code */
		if ( pRingState->nPrintICFinal ) {
			ring_parser_icg_showoutput(pRingState->pRingGenCode,2);
		}
	}
	return nRunVM ;
}

void ring_scanner_readchar ( Scanner *pScanner,char c )
{
	char cStr[2]  ;
	List *pList  ;
	String *pString  ;
	int nTokenIndex  ;
	assert(pScanner != NULL);
	cStr[0] = c ;
	cStr[1] = '\0' ;
	#if RING_DEBUG
	printf("%c",c);
	printf( "\n State : %d \n  \n",pScanner->state ) ;
	#endif
	switch ( pScanner->state ) {
		case SCANNER_STATE_GENERAL :
			/* Check Unicode File */
			if ( ring_list_getsize(pScanner->Tokens) == 0 ) {
				/* UTF8 */
				if ( strcmp(ring_string_get(pScanner->ActiveToken),"\xEF\xBB\xBF") == 0 ) {
					ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
					/* Don't use reading so the new character can be scanned */
				}
			}
			/* Check Space/Tab/New Line */
			if ( c != ' ' && c != '\n' && c != '\t' && c != '\"' && c != '\'' && c != '\r' && c != '`' ) {
				if ( ring_scanner_isoperator(pScanner,cStr) ) {
					nTokenIndex = pScanner->nTokenIndex ;
					ring_scanner_checktoken(pScanner);
					ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
					#if RING_SCANNEROUTPUT
					printf( "\nTOKEN (Operator) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
					#endif
					/* Check Multiline Comment */
					if ( (strcmp(cStr,"*") == 0) && (ring_scanner_lasttokentype(pScanner) ==SCANNER_TOKEN_OPERATOR) ) {
						pList = ring_list_getlist(pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
						if ( strcmp(ring_list_getstring(pList,2),"/") == 0 ) {
							ring_list_deleteitem_gc(pScanner->pRingState,pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
							pScanner->state = SCANNER_STATE_MLCOMMENT ;
							#if RING_SCANNEROUTPUT
							printf( "\nMultiline comments start, ignore /* \n" ) ;
							#endif
							return ;
						}
					}
					/* Check comment using // */
					if ( strcmp(cStr,"/") == 0 ) {
						if ( ring_scanner_lasttokentype(pScanner) ==SCANNER_TOKEN_OPERATOR ) {
							if ( strcmp("/",ring_scanner_lasttokenvalue(pScanner)) ==  0 ) {
								RING_SCANNER_DELETELASTTOKEN ;
								pScanner->state = SCANNER_STATE_COMMENT ;
								return ;
							}
						}
					}
					/* Check << | >> operators */
					if ( ( strcmp(cStr,"<") == 0 ) | ( strcmp(cStr,">") == 0 ) ) {
						if ( strcmp(cStr,ring_scanner_lasttokenvalue(pScanner)) ==  0 ) {
							if ( strcmp(cStr,"<") == 0 ) {
								RING_SCANNER_DELETELASTTOKEN ;
								ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"<<");
							} else {
								RING_SCANNER_DELETELASTTOKEN ;
								ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,">>");
							}
							#if RING_SCANNEROUTPUT
							printf( "\nTOKEN (Operator) = %s , merge previous two operators in one \n",ring_string_get(pScanner->ActiveToken) ) ;
							#endif
							nTokenIndex += 100 ;
						}
					}
					/* Check += -= *= /= %= &= |= ^= <<= >>= */
					else if ( strcmp(cStr,"=") == 0 ) {
						nTokenIndex += 100 ;
						if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"+") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"+=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"-") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"-=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"*") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"*=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"/") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"/=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"%") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"%=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"&") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"&=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"|") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"|=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"^") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set(pScanner->ActiveToken,"^=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"<<") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"<<=");
						}
						else if ( strcmp(ring_scanner_lasttokenvalue(pScanner),">>") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,">>=");
						}
						else {
							nTokenIndex -= 100 ;
						}
					}
					/* Check ++ and -- */
					else if ( strcmp(cStr,"+") == 0 ) {
						if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"+") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"++");
							nTokenIndex += 100 ;
						}
					}
					else if ( strcmp(cStr,"-") == 0 ) {
						if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"-") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"--");
							nTokenIndex += 100 ;
						}
					}
					/* Check && and || */
					else if ( strcmp(cStr,"&") == 0 ) {
						if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"&") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"&&");
							nTokenIndex += 100 ;
						}
					}
					else if ( strcmp(cStr,"|") == 0 ) {
						if ( strcmp(ring_scanner_lasttokenvalue(pScanner),"|") == 0 ) {
							RING_SCANNER_DELETELASTTOKEN ;
							ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"||");
							nTokenIndex += 100 ;
						}
					}
					pScanner->nTokenIndex = nTokenIndex ;
					ring_scanner_addtoken(pScanner,SCANNER_TOKEN_OPERATOR);
				} else {
					ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
					#if RING_DEBUG
					printf( "\nActive Token = %s",ring_string_get(pScanner->ActiveToken) ) ;
					#endif
				}
			} else {
				if ( ring_scanner_isoperator(pScanner,ring_string_get(pScanner->ActiveToken)) ) {
					ring_scanner_addtoken(pScanner,SCANNER_TOKEN_OPERATOR);
				}
				else {
					ring_scanner_checktoken(pScanner);
				}
			}
			/* Switch State */
			if ( c == '"' ) {
				pScanner->state = SCANNER_STATE_LITERAL ;
				pScanner->cLiteral = '"' ;
			}
			else if ( c == '\'' ) {
				pScanner->state = SCANNER_STATE_LITERAL ;
				pScanner->cLiteral = '\'' ;
			}
			else if ( c == '`' ) {
				pScanner->state = SCANNER_STATE_LITERAL ;
				pScanner->cLiteral = '`' ;
			}
			else if ( c == '#' ) {
				pScanner->state = SCANNER_STATE_COMMENT ;
			}
			break ;
		case SCANNER_STATE_LITERAL :
			/* Switch State */
			if ( c == pScanner->cLiteral ) {
				pScanner->state = SCANNER_STATE_GENERAL ;
				#if RING_SCANNEROUTPUT
				printf( "\nTOKEN (Literal) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_addtoken(pScanner,SCANNER_TOKEN_LITERAL);
			} else {
				ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			}
			break ;
		case SCANNER_STATE_COMMENT :
			/* Switch State */
			if ( c == '\n' ) {
				pScanner->state = SCANNER_STATE_GENERAL ;
				#if RING_SCANNEROUTPUT
				printf( "\n Not TOKEN (Comment) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			} else {
				ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			}
			break ;
		case SCANNER_STATE_MLCOMMENT :
			/* Check Multiline Comment */
			switch ( pScanner->cMLComment ) {
				case 0 :
					if ( strcmp(cStr,"*") == 0 ) {
						pScanner->cMLComment = 1 ;
						return ;
					}
					break ;
				case 1 :
					if ( strcmp(cStr,"/") == 0 ) {
						pScanner->state = SCANNER_STATE_GENERAL ;
						#if RING_SCANNEROUTPUT
						printf( "\nMultiline comments end \n" ) ;
						#endif
						/* The next step is important to avoid storing * as identifier! */
						ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
					}
					pScanner->cMLComment = 0 ;
					return ;
			}
			break ;
		case SCANNER_STATE_CHANGEKEYWORD :
			/* Switch State */
			if ( c == '\n' ) {
				pScanner->state = SCANNER_STATE_GENERAL ;
				#if RING_SCANNEROUTPUT
				printf( "\n Change Keyword = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_changekeyword(pScanner);
				ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			} else {
				ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			}
			break ;
		case SCANNER_STATE_CHANGEOPERATOR :
			/* Switch State */
			if ( c == '\n' ) {
				pScanner->state = SCANNER_STATE_GENERAL ;
				#if RING_SCANNEROUTPUT
				printf( "\n Change operator = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_changeoperator(pScanner);
				ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			} else {
				ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			}
			break ;
		case SCANNER_STATE_LOADSYNTAX :
			/* Switch State */
			if ( c == '\n' ) {
				pScanner->state = SCANNER_STATE_GENERAL ;
				#if RING_SCANNEROUTPUT
				printf( "\n Load Syntax = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_loadsyntax(pScanner);
				ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			} else {
				ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			}
			break ;
	}
	if ( c == '\n' ) {
		pScanner->LinesCount++ ;
		#if RING_DEBUG
		printf( "Line Number : %d  \n",pScanner->LinesCount ) ;
		#endif
	}
	if ( ( c == ';' || c == '\n' ) && ( pScanner->state == SCANNER_STATE_GENERAL ) ) {
		if ( (ring_scanner_lasttokentype(pScanner) != SCANNER_TOKEN_ENDLINE ) ) {
			ring_string_setfromint_gc(pScanner->pRingState,pScanner->ActiveToken,pScanner->LinesCount);
			ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
			#if RING_SCANNEROUTPUT
			printf( "\nTOKEN (ENDLINE)  \n" ) ;
			#endif
		} else {
			pList = ring_list_getlist(pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
			pString = ring_string_new_gc(pScanner->pRingState,"");
			ring_string_setfromint_gc(pScanner->pRingState,pString,pScanner->LinesCount);
			ring_list_setstring_gc(pScanner->pRingState,pList,2,ring_string_get(pString));
			ring_string_delete_gc(pScanner->pRingState,pString);
		}
	}
}

void ring_scanner_keywords ( Scanner *pScanner )
{
	assert(pScanner != NULL);
	pScanner->Keywords = ring_list_new_gc(pScanner->pRingState,0);
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"if");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"to");
	/* Logic */
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"or");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"and");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"not");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"for");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"new");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"func");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"from");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"next");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"load");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"else");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"see");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"while");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"ok");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"class");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"return");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"but");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"end");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"give");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"bye");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"exit");
	/* Try-Catch-Done */
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"try");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"catch");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"done");
	/* Switch */
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"switch");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"on");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"other");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"off");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"in");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"loop");
	/* Packages */
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"package");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"import");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"private");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"step");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"do");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"again");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"call");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"elseif");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"put");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"get");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"case");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"def");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endfunc");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endclass");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endpackage");
	/*
	**  The next keywords are sensitive to the order and keywords count 
	**  if you will add new keywords revise constants and ring_scanner_checktoken() 
	*/
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"changeringkeyword");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"changeringoperator");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"loadsyntax");
	ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Keywords);
}

void ring_scanner_addtoken ( Scanner *pScanner,int type )
{
	List *pList  ;
	assert(pScanner != NULL);
	pList = ring_list_newlist_gc(pScanner->pRingState,pScanner->Tokens);
	/* Add Token Type */
	ring_list_addint_gc(pScanner->pRingState,pList,type);
	/* Add Token Text */
	ring_list_addstring_gc(pScanner->pRingState,pList,ring_string_get(pScanner->ActiveToken));
	/* Add Token Index */
	ring_list_addint_gc(pScanner->pRingState,pList,pScanner->nTokenIndex);
	pScanner->nTokenIndex = 0 ;
	ring_scanner_floatmark(pScanner,type);
	ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
}

void ring_scanner_checktoken ( Scanner *pScanner )
{
	int nResult  ;
	char cStr[5]  ;
	/* This function determine if the TOKEN is a Keyword or Identifier or Number */
	assert(pScanner != NULL);
	/* Not Case Sensitive */
	ring_string_tolower(pScanner->ActiveToken);
	nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Keywords),ring_string_get(pScanner->ActiveToken));
	if ( nResult > 0 ) {
		#if RING_SCANNEROUTPUT
		printf( "\nTOKEN (Keyword) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
		#endif
		if ( nResult < RING_SCANNER_CHANGERINGKEYWORD ) {
			sprintf( cStr , "%d" , nResult ) ;
			ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
			ring_scanner_addtoken(pScanner,SCANNER_TOKEN_KEYWORD);
		}
		else if ( nResult == RING_SCANNER_CHANGERINGOPERATOR ) {
			ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			pScanner->state = SCANNER_STATE_CHANGEOPERATOR ;
		}
		else if ( nResult == RING_SCANNER_LOADSYNTAX ) {
			ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			pScanner->state = SCANNER_STATE_LOADSYNTAX ;
		}
		else {
			ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
			pScanner->state = SCANNER_STATE_CHANGEKEYWORD ;
		}
	} else {
		/* Add Identifier */
		if ( strcmp(ring_string_get(pScanner->ActiveToken),"") != 0 ) {
			if ( ring_scanner_isnumber(ring_string_get(pScanner->ActiveToken) ) == 0 ) {
				#if RING_SCANNEROUTPUT
				printf( "\nTOKEN (Identifier) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_addtoken(pScanner,SCANNER_TOKEN_IDENTIFIER);
			} else {
				#if RING_SCANNEROUTPUT
				printf( "\nTOKEN (Number) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
				#endif
				ring_scanner_addtoken(pScanner,SCANNER_TOKEN_NUMBER);
			}
		}
	}
}

int ring_scanner_isnumber ( char *cStr )
{
	unsigned int x  ;
	unsigned int x2  ;
	for ( x = 0 ; x < strlen(cStr) ; x++ ) {
		/* Accept _ in the number */
		if ( (cStr[x] == '_') && (x > 0) && (x < strlen(cStr) - 1) ) {
			for ( x2 = x ; x2 < strlen(cStr) ; x2++ ) {
				cStr[x2] = cStr[x2+1] ;
			}
			x-- ;
			continue ;
		}
		/* Accept f in the end of the number */
		if ( (x > 0) && (x == strlen(cStr) - 1) && ( (cStr[x] == 'f') || (cStr[x] == 'F') ) ) {
			cStr[x] = '\0' ;
			return 1 ;
		}
		if ( (cStr[x] < 48 || cStr[x] > 57) ) {
			return 0 ;
		}
	}
	return 1 ;
}

int ring_scanner_checklasttoken ( Scanner *pScanner )
{
	assert(pScanner != NULL);
	if ( ring_list_getsize(pScanner->Tokens) == 0 ) {
		if ( pScanner->state == SCANNER_STATE_COMMENT ) {
			return 0 ;
		}
	}
	if ( pScanner->state == SCANNER_STATE_LITERAL ) {
		ring_state_cgiheader(pScanner->pRingState);
		printf( "Error in Line %d , Literal not closed expected \" in the end  ",pScanner->LinesCount ) ;
		return 0 ;
	}
	else if ( pScanner->state ==SCANNER_STATE_GENERAL ) {
		ring_scanner_checktoken(pScanner);
	}
	return 1 ;
}

int ring_scanner_isoperator ( Scanner *pScanner, const char *cStr )
{
	int nPos  ;
	assert(pScanner != NULL);
	nPos = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Operators),cStr) ;
	if ( nPos > 0 ) {
		pScanner->nTokenIndex = nPos ;
		return 1 ;
	}
	return 0 ;
}

void ring_scanner_operators ( Scanner *pScanner )
{
	assert(pScanner != NULL);
	pScanner->Operators = ring_list_new_gc(pScanner->pRingState,0);
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"+");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"-");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"*");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"/");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"%");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,".");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"(");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,")");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"=");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,",");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"!");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,">");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"<");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"[");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"]");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,":");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"{");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"}");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"&");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"|");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"~");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"^");
	ring_list_addstring_gc(pScanner->pRingState,pScanner->Operators,"?");
	ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Operators);
}

int ring_scanner_lasttokentype ( Scanner *pScanner )
{
	int x  ;
	List *pList  ;
	assert(pScanner != NULL);
	x = ring_list_getsize(pScanner->Tokens);
	if ( x > 0 ) {
		pList = ring_list_getlist(pScanner->Tokens,x);
		return ring_list_getint(pList,1) ;
	}
	return SCANNER_TOKEN_NOTOKEN ;
}

char * ring_scanner_lasttokenvalue ( Scanner *pScanner )
{
	int x  ;
	List *pList  ;
	assert(pScanner != NULL);
	x = ring_list_getsize(pScanner->Tokens);
	if ( x > 0 ) {
		pList = ring_list_getlist(pScanner->Tokens,x);
		return ring_list_getstring(pList,2) ;
	}
	return (char *) "" ;
}

void ring_scanner_floatmark ( Scanner *pScanner,int type )
{
	List *pList  ;
	String *pString  ;
	assert(pScanner != NULL);
	switch ( pScanner->FloatMark ) {
		case 0 :
			if ( type == SCANNER_TOKEN_NUMBER ) {
				pScanner->FloatMark = 1 ;
			}
			break ;
		case 1 :
			if ( (type == SCANNER_TOKEN_OPERATOR) && ( strcmp(ring_string_get(pScanner->ActiveToken) , "." ) == 0  ) ) {
				pScanner->FloatMark = 2 ;
			} else {
				pScanner->FloatMark = 0 ;
			}
			break ;
		case 2 :
			if ( type == SCANNER_TOKEN_NUMBER ) {
				pList = ring_list_getlist(pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
				pString = ring_string_new_gc(pScanner->pRingState,ring_list_getstring(pList,2)) ;
				ring_list_deleteitem_gc(pScanner->pRingState,pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
				ring_list_deleteitem_gc(pScanner->pRingState,pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
				pList = ring_list_getlist(pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
				ring_string_add_gc(pScanner->pRingState,ring_item_getstring(ring_list_getitem(pList,2)),".");
				ring_string_add_gc(pScanner->pRingState,ring_item_getstring(ring_list_getitem(pList,2)),ring_string_get(pString));
				ring_string_delete_gc(pScanner->pRingState,pString);
				#if RING_SCANNEROUTPUT
				printf( "\nFloat Found, Removed 2 tokens from the end, update value to float ! \n" ) ;
				printf( "\nFloat Value = %s  \n",ring_list_getstring(pList,2) ) ;
				#endif
			}
			pScanner->FloatMark = 0 ;
			break ;
	}
}

void ring_scanner_endofline ( Scanner *pScanner )
{
	/* Add Token "End of Line" to the end of any program */
	if ( ring_scanner_lasttokentype(pScanner) != SCANNER_TOKEN_ENDLINE ) {
		ring_string_setfromint_gc(pScanner->pRingState,pScanner->ActiveToken,pScanner->LinesCount);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
		#if RING_SCANNEROUTPUT
		printf( "\nTOKEN (ENDLINE)  \n" ) ;
		#endif
	}
}

void ring_scanner_addreturn ( RingState *pRingState )
{
	List *pList  ;
	/* Add return to the end of the program */
	pList = ring_list_newlist_gc(pRingState,pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState,pList,ICO_RETNULL);
}

void ring_scanner_addreturn2 ( RingState *pRingState )
{
	List *pList  ;
	/* Add return to the end of the program */
	pList = ring_list_newlist_gc(pRingState,pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState,pList,ICO_RETURN);
}

void ring_scanner_addreturn3 ( RingState *pRingState, int aPara[3] )
{
	List *pList  ;
	/* Add return from eval to the end of the eval() code */
	pList = ring_list_newlist_gc(pRingState,pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState,pList,ICO_RETFROMEVAL);
	ring_list_addint_gc(pRingState,pList,aPara[0]);
	ring_list_addint_gc(pRingState,pList,aPara[1]);
	ring_list_addint_gc(pRingState,pList,aPara[2]);
}

void ring_scanner_printtokens ( Scanner *pScanner )
{
	int x,nType,nPos  ;
	List *pList  ;
	char *cString  ;
	ring_print_line();
	puts("Tokens - Generated by the Scanner");
	ring_print_line();
	printf( "\n" ) ;
	for ( x = 1 ; x <= ring_list_getsize(pScanner->Tokens) ; x++ ) {
		pList = ring_list_getlist(pScanner->Tokens,x);
		nType = ring_list_getint(pList,RING_SCANNER_TOKENTYPE) ;
		cString = ring_list_getstring(pList,RING_SCANNER_TOKENVALUE) ;
		switch ( nType ) {
			case SCANNER_TOKEN_KEYWORD :
				nPos = atoi(cString) ;
				printf( "%10s : %s \n","Keyword",RING_KEYWORDS[nPos-1] ) ;
				break ;
			case SCANNER_TOKEN_OPERATOR :
				printf( "%10s : %s \n","Operator",cString ) ;
				break ;
			case SCANNER_TOKEN_NUMBER :
				printf( "%10s : %s \n","Number",cString ) ;
				break ;
			case SCANNER_TOKEN_IDENTIFIER :
				printf( "%10s : %s \n","Identifier",cString ) ;
				break ;
			case SCANNER_TOKEN_LITERAL :
				printf( "%10s : %s \n","Literal",cString ) ;
				break ;
			case SCANNER_TOKEN_ENDLINE :
				printf( "%10s\n","EndLine" ) ;
				break ;
		}
	}
	printf( "\n" ) ;
	ring_print_line();
}

RING_API void ring_execute ( char *cFileName, int nISCGI,int nRun,int nPrintIC,int nPrintICFinal,int nTokens,int nRules,int nIns,int nGenObj,int nWarn,int argc,char *argv[] )
{
	RingState *pRingState  ;
	pRingState = ring_state_new();
	pRingState->nISCGI = nISCGI ;
	pRingState->nRun = nRun ;
	pRingState->nPrintIC = nPrintIC ;
	pRingState->nPrintICFinal = nPrintICFinal ;
	pRingState->nPrintTokens = nTokens ;
	pRingState->nPrintRules = nRules ;
	pRingState->nPrintInstruction = nIns ;
	pRingState->nGenObj = nGenObj ;
	pRingState->nWarning = nWarn ;
	pRingState->argc = argc ;
	pRingState->argv = argv ;
	if ( ring_issourcefile(cFileName) ) {
		ring_scanner_readfile(pRingState,cFileName);
	}
	else {
		ring_scanner_runobjfile(pRingState,cFileName);
	}
	ring_state_delete(pRingState);
}

const char * ring_scanner_getkeywordtext ( const char *cStr )
{
	return RING_KEYWORDS[atoi(cStr)-1] ;
}

void ring_scanner_runobjfile ( RingState *pRingState,char *cFileName )
{
	/* Files List */
	pRingState->pRingFilesList = ring_list_new_gc(pRingState,0);
	pRingState->pRingFilesStack = ring_list_new_gc(pRingState,0);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
	if ( ring_objfile_readfile(pRingState,cFileName) ) {
		ring_scanner_runprogram(pRingState);
	}
}

void ring_scanner_runobjstring ( RingState *pRingState,char *cString,const char *cFileName )
{
	/* Files List */
	pRingState->pRingFilesList = ring_list_new_gc(pRingState,0);
	pRingState->pRingFilesStack = ring_list_new_gc(pRingState,0);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
	if ( ring_objfile_readstring(pRingState,cString) ) {
		ring_scanner_runprogram(pRingState);
	}
}

void ring_scanner_runprogram ( RingState *pRingState )
{
	VM *pVM  ;
	/* Add return to the end of the program */
	ring_scanner_addreturn(pRingState);
	if ( pRingState->nPrintIC ) {
		ring_parser_icg_showoutput(pRingState->pRingGenCode,1);
	}
	if ( ! pRingState->nRun ) {
		return ;
	}
	pVM = ring_vm_new(pRingState);
	ring_vm_start(pRingState,pVM);
	ring_vm_delete(pVM);
	/* Display Generated Code */
	if ( pRingState->nPrintICFinal ) {
		ring_parser_icg_showoutput(pRingState->pRingGenCode,2);
	}
}

void ring_scanner_changekeyword ( Scanner *pScanner )
{
	char *cStr  ;
	int x,nResult  ;
	String *word1, *word2, *activeword  ;
	char cStr2[2]  ;
	cStr2[1] = '\0' ;
	/* Create Strings */
	word1 = ring_string_new_gc(pScanner->pRingState,"");
	word2 = ring_string_new_gc(pScanner->pRingState,"");
	cStr = ring_string_get(pScanner->ActiveToken) ;
	activeword = word1 ;
	for ( x = 0 ; x < ring_string_size(pScanner->ActiveToken) ; x++ ) {
		if ( (cStr[x] == ' ') || (cStr[x] == '\t') ) {
			if ( (activeword == word1) && (ring_string_size(activeword) >= 1) ) {
				activeword = word2 ;
			}
		}
		else {
			cStr2[0] = cStr[x] ;
			ring_string_add_gc(pScanner->pRingState,activeword,cStr2);
		}
	}
	/* To Lower Case */
	ring_string_lower(ring_string_get(word1));
	ring_string_lower(ring_string_get(word2));
	/* Change Keyword */
	if ( (strcmp(ring_string_get(word1),"") == 0) || (strcmp(ring_string_get(word2),"") == 0) ) {
		puts("Warning : The Compiler command  ChangeRingKeyword required two words");
	}
	else {
		nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Keywords),ring_string_get(word1));
		if ( nResult > 0 ) {
			ring_list_setstring_gc(pScanner->pRingState,pScanner->Keywords,nResult,ring_string_get(word2));
			ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Keywords);
		}
		else {
			puts("Warning : Compiler command ChangeRingKeyword - Keyword not found !");
			printf( "Keyword :  %s\n",ring_string_get(word1) ) ;
		}
	}
	/* Delete Strings */
	ring_string_delete_gc(pScanner->pRingState,word1);
	ring_string_delete_gc(pScanner->pRingState,word2);
}

void ring_scanner_changeoperator ( Scanner *pScanner )
{
	char *cStr  ;
	int x,nResult  ;
	String *word1, *word2, *activeword  ;
	char cStr2[2]  ;
	cStr2[1] = '\0' ;
	/* Create Strings */
	word1 = ring_string_new_gc(pScanner->pRingState,"");
	word2 = ring_string_new_gc(pScanner->pRingState,"");
	cStr = ring_string_get(pScanner->ActiveToken) ;
	activeword = word1 ;
	for ( x = 0 ; x < ring_string_size(pScanner->ActiveToken) ; x++ ) {
		if ( (cStr[x] == ' ') || (cStr[x] == '\t') ) {
			if ( (activeword == word1) && (ring_string_size(activeword) >= 1) ) {
				activeword = word2 ;
			}
		}
		else {
			cStr2[0] = cStr[x] ;
			ring_string_add_gc(pScanner->pRingState,activeword,cStr2);
		}
	}
	/* To Lower Case */
	ring_string_lower(ring_string_get(word1));
	ring_string_lower(ring_string_get(word2));
	/* Change Operator */
	if ( (strcmp(ring_string_get(word1),"") == 0) || (strcmp(ring_string_get(word2),"") == 0) ) {
		puts("Warning : The Compiler command  ChangeRingOperator requires two words");
	}
	else {
		nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Operators),ring_string_get(word1));
		if ( nResult > 0 ) {
			ring_list_setstring_gc(pScanner->pRingState,pScanner->Operators,nResult,ring_string_get(word2));
			ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Operators);
		}
		else {
			puts("Warning : Compiler command ChangeRingOperator - Operator not found !");
			printf( "Operator :  %s\n",ring_string_get(word1) ) ;
		}
	}
	/* Delete Strings */
	ring_string_delete_gc(pScanner->pRingState,word1);
	ring_string_delete_gc(pScanner->pRingState,word2);
}

void ring_scanner_loadsyntax ( Scanner *pScanner )
{
	char *cFileName  ;
	RING_FILE fp  ;
	/* Must be signed char to work fine on Android, because it uses -1 as NULL instead of Zero */
	signed char c  ;
	int nSize  ;
	char cFileName2[200]  ;
	unsigned int x  ;
	cFileName = ring_string_get(pScanner->ActiveToken) ;
	/* Remove Spaces and " " from file name */
	x = 0 ;
	while ( ( (cFileName[x] == ' ') || (cFileName[x] == '"') ) && (x <= strlen(cFileName)) ) {
		cFileName++ ;
	}
	x = strlen(cFileName) ;
	while ( ( (cFileName[x-1] == ' ') || (cFileName[x-1] == '"') ) && (x >= 1) ) {
		cFileName[x-1] = '\0' ;
		x-- ;
	}
	/* Support File Location in Ring/bin Folder */
	strcpy(cFileName2,cFileName);
	if ( ring_fexists(cFileName) == 0 ) {
		ring_exefolder(cFileName2);
		strcat(cFileName2,cFileName);
		if ( ring_fexists(cFileName2) == 0 ) {
			strcpy(cFileName,cFileName2);
		}
	}
	fp = RING_OPENFILE(cFileName2 , "r");
	if ( fp==NULL ) {
		printf( "\nCan't open file %s \n",cFileName ) ;
		return ;
	}
	nSize = 1 ;
	ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
	RING_READCHAR(fp,c,nSize);
	while ( (c != EOF) && (nSize != 0) ) {
		ring_scanner_readchar(pScanner,c);
		RING_READCHAR(fp,c,nSize);
	}
	RING_CLOSEFILE(fp);
	ring_scanner_readchar(pScanner,'\n');
}
