/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Grammar */

int ring_parser_class ( Parser *pParser )
{
    List *pList,*pList2,*pList3  ;
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
            ring_parser_icg_newoperation(pParser,ICO_RETNULL);
            ring_parser_icg_newoperation(pParser,ICO_NEWCLASS);
            ring_parser_icg_newoperand(pParser,pParser->TokenText);
            /* Add Class to Classes Table */
            pList = pParser->ClassesMap ;
            /* Check Class Redefinition */
            if ( ring_list_getsize(pList) > 0 ) {
                for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                    if ( strcmp(ring_list_getstring(ring_list_getlist(pList,x),1),pParser->TokenText) == 0 ) {
                        ring_parser_error(pParser,RING_PARSER_ERROR_CLASSREDEFINE);
                        return 0 ;
                    }
                }
            }
            pList = ring_list_newlist_gc(pParser->pRingState,pList);
            ring_list_addstring_gc(pParser->pRingState,pList,pParser->TokenText);
            ring_list_addint_gc(pParser->pRingState,pList,ring_list_getsize(pParser->GenCode));
            /* Add class pointer to generated code */
            ring_parser_icg_newoperandpointer(pParser,pList);
            ring_parser_nexttoken(pParser);
            /* [From Identifier] */
            if ( ring_parser_iskeyword(pParser,K_FROM) || ring_parser_isoperator2(pParser,OP_RANGE) || ring_parser_isoperator2(pParser,OP_LESS) ) {
                ring_parser_nexttoken(pParser);
                if ( ring_parser_namedotname(pParser) ) {
                    /* Generate Code */
                    pList3 = ring_parser_icg_getactiveoperation(pParser);
                    /* Check if parent class name = subclass name */
                    if ( strcmp(ring_list_getstring(pList,1),ring_list_getstring(pList3,4)) == 0 ) {
                        ring_parser_error(pParser,RING_PARSER_ERROR_PARENTLIKESUBCLASS);
                        return 0 ;
                    }
                    /* Set Parent Class Name in Classes Map */
                    ring_list_addstring_gc(pParser->pRingState,pList,ring_list_getstring(pList3,4));
                    #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : Statement  --> 'Class' Identifier 'From' [PackageName'.']Identifier");
                    #endif
                } else {
                    ring_parser_error(pParser,RING_PARSER_ERROR_PRENTCLASSNAME);
                    return 0 ;
                }
            } else {
                /* Set Parent Class Name In Classes Map */
                ring_list_addstring_gc(pParser->pRingState,pList,"");
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Statement  --> 'Class' Identifier ");
                #endif
            }
            /* Add Method/Functions List to Class in Class Table */
            pList2 = ring_list_newlist_gc(pParser->pRingState,pList);
            /* Add Flag ( IS Parent Class information collected  ) */
            ring_list_addint_gc(pParser->pRingState,pList,0);
            /* Set Active Functions List to be Class Methods */
            pParser->FunctionsMap = pList2 ;
            /* Make class visible using PackageName.ClassName if we have package */
            if ( pParser->ClassesMap != pParser->pRingState->pRingClassesMap ) {
                /* Get Package Name */
                pList3 = ring_list_getlist(pParser->pRingState->pRingPackagesMap,ring_list_getsize(pParser->pRingState->pRingPackagesMap));
                pString = ring_string_new_gc(pParser->pRingState,ring_list_getstring(pList3,1));
                /* Add pointer to the Package in the Class List */
                ring_list_addpointer_gc(pParser->pRingState,pList,pList3);
                /* Add List point to General Classes point to the class in the package */
                pList2 = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingClassesMap);
                ring_list_addstring_gc(pParser->pRingState,pList2,"");
                ring_list_addpointer_gc(pParser->pRingState,pList2,pList);
                /* Ignore Adding Pointer to File Name */
                ring_list_addpointer_gc(pParser->pRingState,pList2,NULL);
                /* Add Class Name to Package Name */
                ring_string_add_gc(pParser->pRingState,pString,".");
                ring_string_add_gc(pParser->pRingState,pString,ring_list_getstring(pList,1));
                ring_list_setstring_gc(pParser->pRingState,pList2,1,ring_string_get(pString));
                ring_string_delete_gc(pParser->pRingState,pString);
            } else {
                /* Add pointer to the Package in the Class List */
                ring_list_addpointer_gc(pParser->pRingState,pList,NULL);
            }
            pParser->nClassStart = 1 ;
            /* Create label to be used by Private */
            pParser->nClassMark = ring_parser_icg_newlabel2(pParser);
            pParser->nPrivateFlag = 0 ;
            /* Generate Code - Set The File Name */
            ring_parser_icg_newoperation(pParser,ICO_FILENAME);
            ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
            /* Set Global Scope */
            ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
            ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->aCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->aCustomGlobalScopeStack)));
            /* Support using { } around the class code and using 'end' after the content */
            return ring_parser_bracesandend(pParser,1,K_ENDCLASS) ;
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_CLASSNAME);
            return 0 ;
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
            ring_parser_icg_newoperation(pParser,ICO_RETNULL);
            ring_parser_icg_newoperation(pParser,ICO_NEWFUNC);
            ring_parser_icg_newoperand(pParser,pParser->TokenText);
            /* Add function to Functions Table */
            pList2 = pParser->FunctionsMap ;
            /* Check Function Redefinition */
            if ( ring_list_getsize(pList2) > 0 ) {
                for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
                    if ( strcmp(ring_list_getstring(ring_list_getlist(pList2,x),1),pParser->TokenText) == 0 ) {
                        ring_parser_error(pParser,RING_PARSER_ERROR_FUNCREDEFINE);
                        return 0 ;
                    }
                }
            }
            pList2 = ring_list_newlist_gc(pParser->pRingState,pList2);
            ring_list_addstring_gc(pParser->pRingState,pList2,pParser->TokenText);
            ring_list_addint_gc(pParser->pRingState,pList2,ring_list_getsize(pParser->GenCode));
            ring_list_addstring_gc(pParser->pRingState,pList2,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
            if ( pParser->nClassStart == 1 ) {
                ring_list_addint_gc(pParser->pRingState,pList2,pParser->nPrivateFlag);
            } else {
                ring_list_addint_gc(pParser->pRingState,pList2,0);
            }
            ring_parser_nexttoken(pParser);
            if ( ring_parser_isidentifier(pParser) || ring_parser_isoperator2(pParser,OP_FOPEN) ) {
                x = ring_parser_paralist(pParser);
            } else {
                x = 1 ;
            }
            /* Set Global Scope */
            ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
            ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->aCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->aCustomGlobalScopeStack)));
            if ( x ) {
                /* Support using { } around the function code and using 'end' after the content */
                return ring_parser_bracesandend(pParser,0,K_ENDFUNC) ;
            }
            #if RING_PARSERTRACE
            if ( x == 1 ) {
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Statement  --> 'Func' Identifier [ParaList]");
            }
            #endif
            return x ;
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_FUNCNAME);
            return 0 ;
        }
    }
    /* Statement --> Package Identifier { '.' Identifier } */
    if ( ring_parser_iskeyword(pParser,K_PACKAGE) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PACKAGE);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Package' Identifier{'.'identifier}");
        #endif
        if ( ring_parser_namedotname(pParser) ) {
            /* Add Package to Packages List */
            pList = ring_parser_icg_getactiveoperation(pParser);
            /* Check early definition of the package */
            for ( x = 1 ; x <= ring_list_getsize(pParser->pRingState->pRingPackagesMap) ; x++ ) {
                pList3 = ring_list_getlist(pParser->pRingState->pRingPackagesMap,x);
                if ( strcmp(ring_list_getstring(pList3,1),ring_list_getstring(pList,2)) == 0 ) {
                    pParser->ClassesMap = ring_list_getlist(pList3,2);
                    return 1 ;
                }
            }
            pList2 = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingPackagesMap);
            /* Add Package Name */
            ring_list_addstring_gc(pParser->pRingState,pList2,ring_list_getstring(pList,2));
            /* Add Package Classes List */
            pParser->ClassesMap = ring_list_newlist_gc(pParser->pRingState,pList2);
            /* Support using { } around the package code and using 'end' after the content */
            return ring_parser_bracesandend(pParser,1,K_ENDPACKAGE) ;
        } else {
            return 0 ;
        }
    }
    /* Statement --> Private */
    if ( ring_parser_iskeyword(pParser,K_PRIVATE) ) {
        ring_parser_nexttoken(pParser);
        if ( pParser->nClassStart == 1 ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_RETNULL);
            /* Change Label After Class to BlockFlag to Jump to Private */
            pList = ring_parser_icg_getoperationlist(pParser,pParser->nClassMark);
            ring_list_setint_gc(pParser->pRingState,pList,1,ICO_BLOCKFLAG);
            ring_list_addint_gc(pParser->pRingState,pList,ring_parser_icg_newlabel(pParser));
            ring_parser_icg_newoperation(pParser,ICO_PRIVATE);
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'Private'");
            #endif
            pParser->nPrivateFlag = 1 ;
            return 1 ;
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_NOCLASSDEFINED);
            return 0 ;
        }
    }
    return ring_parser_stmt(pParser) ;
}

int ring_parser_stmt ( Parser *pParser )
{
    int x,nMark1,nMark2,nMark3,nStart,nEnd,nPerformanceLocations,nFlag,nLoadPackage,nLoopOrExitCommand,nLoadAgain,nForInVarsCount,nVar  ;
    String *pString  ;
    List *pMark,*pMark2,*pMark3,*pList2  ;
    double nNum1  ;
    char cStr[50]  ;
    char cFileName[RING_PATHSIZE]  ;
    char cCurrentDir[RING_PATHSIZE]  ;
    nPerformanceLocations = 0 ;
    nLoadPackage = 0 ;
    nLoopOrExitCommand = 0 ;
    nLoadAgain = 0 ;
    assert(pParser != NULL);
    /* Statement --> Load Literal */
    if ( ring_parser_iskeyword(pParser,K_LOAD) ) {
        ring_parser_nexttoken(pParser);
        /* Load Package Command */
        if ( ring_parser_iskeyword(pParser,K_PACKAGE) ) {
            ring_parser_nexttoken(pParser);
            nLoadPackage = 1 ;
            pParser->pRingState->nCustomGlobalScopeCounter++ ;
            ring_list_addint_gc(pParser->pRingState,pParser->pRingState->aCustomGlobalScopeStack,pParser->pRingState->nCustomGlobalScopeCounter);
        }
        else if ( ring_parser_iskeyword(pParser,K_AGAIN) ) {
            ring_parser_nexttoken(pParser);
            nLoadAgain = 1 ;
            pParser->pRingState->nLoadAgain++ ;
        }
        if ( ring_parser_isliteral(pParser) ) {
            /* Check File in the Ring/bin folder */
            strcpy(cFileName,pParser->TokenText);
            if ( ring_general_fexists(pParser->TokenText) == 0 ) {
                ring_general_exefolder(cFileName);
                strcat(cFileName,pParser->TokenText);
                if ( ring_general_fexists(cFileName) == 0 ) {
                    /* Try ring/bin/load folder */
                    ring_general_exefolder(cFileName);
                    strcat(cFileName,"load/");
                    strcat(cFileName,pParser->TokenText);
                    if ( ring_general_fexists(cFileName) == 0 ) {
                        strcpy(cFileName,pParser->TokenText);
                    }
                }
            }
            else {
                /* Add the current folder to the file name */
                ring_general_currentdir(cFileName);
                /* Be Sure that we don't already have the current folder in the file name */
                if ( ring_general_folderexistinfilename(cFileName,pParser->TokenText) ) {
                    strcpy(cFileName,"");
                }
                else {
                    ring_general_addosfileseparator(cFileName);
                }
                strcat(cFileName,pParser->TokenText);
                /*
                **  Check if we have the file after adding the folder - because we may have the file in a parent directory 
                **  Like we are in myapp/myapp2 and the file exist in myapp folder 
                */
                if ( ring_general_fexists(cFileName) == 0 ) {
                    strcpy(cFileName,pParser->TokenText);
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
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'Load' Literal");
            #endif
            /* Set Global Scope */
            ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
            ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->aCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->aCustomGlobalScopeStack)));
            /* No package at the start of the file */
            pParser->ClassesMap = pParser->pRingState->pRingClassesMap ;
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
            ring_parser_icg_newoperation(pParser,ICO_RETNULL);
            nMark1 = ring_parser_icg_newlabel(pParser);
            ring_parser_icg_addoperandint(pParser,pMark,nMark1);
            /* Load Package - End Global Scope */
            if ( nLoadPackage ) {
                ring_parser_icg_newoperation(pParser,ICO_ENDGLOBALSCOPE);
                ring_list_deletelastitem_gc(pParser->pRingState,pParser->pRingState->aCustomGlobalScopeStack);
                /* Set Global Scope */
                ring_parser_icg_newoperation(pParser,ICO_SETGLOBALSCOPE);
                ring_parser_icg_newoperandint(pParser,ring_list_getint(pParser->pRingState->aCustomGlobalScopeStack,ring_list_getsize(pParser->pRingState->aCustomGlobalScopeStack)));
            }
            /* Set Active File */
            ring_parser_icg_newoperation(pParser,ICO_FILENAME);
            ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
            ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
            ring_parser_nexttoken(pParser);
            return x ;
        }
        return 0 ;
    }
    /* Statement --> See|Put Expr */
    if ( ring_parser_iskeyword(pParser,K_SEE) | ring_parser_iskeyword(pParser,K_PUT) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        #if RING_USESEEFUNCTION
        /* Generate code to use the SEE function */
        x = ring_parser_gencallringvmsee(pParser);
        #else
        /*
        **  Generate code using the SEE Command Instruction 
        **  Generate Code 
        */
        ring_parser_icg_newoperation(pParser,ICO_FUNCEXE);
        pParser->nAssignmentFlag = 0 ;
        x = ring_parser_expr(pParser);
        pParser->nAssignmentFlag = 1 ;
        if ( x == 0 ) {
            ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
            return 0 ;
        }
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PRINT);
        #endif
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'See' Expr");
        #endif
        return x ;
    }
    /* Statement --> ? Expr */
    if ( ring_parser_isoperator(pParser,"?") ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        #if RING_USESEEFUNCTION
        /*
        **  Generate code to use the See function 
        **  Print the Expression 
        */
        x = ring_parser_gencallringvmsee(pParser);
        /* Print the New Line */
        ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
        ring_parser_icg_newoperand(pParser,"ringvm_see");
        /* Parameters */
        ring_parser_icg_newoperation(pParser,ICO_PUSHC);
        ring_parser_icg_newoperand(pParser,"\n");
        ring_parser_icg_newoperation(pParser,ICO_CALL);
        ring_parser_icg_newoperandint(pParser,0);
        ring_parser_icg_newoperation(pParser,ICO_NOOP);
        ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
        #else
        /*
        **  Generate Code using the See common instructions 
        **  Generate Code 
        */
        ring_parser_icg_newoperation(pParser,ICO_FUNCEXE);
        pParser->nAssignmentFlag = 0 ;
        x = ring_parser_expr(pParser);
        pParser->nAssignmentFlag = 1 ;
        if ( x == 0 ) {
            ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
            return 0 ;
        }
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PRINT);
        /* Print New Line */
        ring_parser_icg_newoperation(pParser,ICO_PUSHC);
        ring_parser_icg_newoperand(pParser,"\n");
        ring_parser_icg_newoperation(pParser,ICO_PRINT);
        #endif
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> '?' Expr");
        #endif
        return x ;
    }
    /* Statement --> Give|Get Identifier */
    if ( ring_parser_iskeyword(pParser,K_GIVE) | ring_parser_iskeyword(pParser,K_GET) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        if ( ring_parser_isidentifier(pParser) ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
            ring_parser_icg_newoperand(pParser,pParser->TokenText);
            ring_parser_nexttoken(pParser);
            x = ring_parser_mixer(pParser);
            if ( x == 0 ) {
                return 0 ;
            }
            /* Generate Code */
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'Give' Identifier|ListItem|Object.Attribute");
            #endif
            #if RING_USEGIVEFUNCTION
            /* Generate code to use the GIVE function */
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
            ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
            ring_parser_icg_newoperand(pParser,"ringvm_give");
            ring_parser_icg_newoperation(pParser,ICO_CALL);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_NOOP);
            ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
            #else
            ring_parser_icg_newoperation(pParser,ICO_GIVE);
            #endif
            return 1 ;
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_VARNAME);
            return 0 ;
        }
    }
    /* Statement --> For Identifier = Expr to Expr {Statement} Next  |  For Identifier in Expr {Statement } */
    if ( ring_parser_iskeyword(pParser,K_FOR) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        if ( ring_parser_isidentifier(pParser) ) {
            pString = ring_string_new_gc(pParser->pRingState,pParser->TokenText);
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
                pParser->nAssignmentFlag = 0 ;
                if ( ring_parser_expr(pParser) ) {
                    /*
                    **  Generate Code 
                    **  Before Equal ( = ) not += , -= ,... etc 
                    */
                    ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
                    ring_parser_icg_newoperandint(pParser,0);
                    ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
                    nMark1 = ring_parser_icg_newlabel(pParser);
                    ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
                    ring_parser_icg_newoperand(pParser,ring_string_get(pString));
                    if ( ring_parser_iskeyword(pParser,K_TO) ) {
                        ring_parser_nexttoken(pParser);
                        RING_PARSER_IGNORENEWLINE ;
                        pParser->nAssignmentFlag = 0 ;
                        if ( ring_parser_csexpr(pParser) ) {
                            pParser->nAssignmentFlag = 1 ;
                            /* Generate Code */
                            if ( (ring_parser_icg_getlastoperation(pParser) == ICO_PUSHN) && (ring_parser_icg_newlabel(pParser) == (nMark1+2)) ) {
                                /*
                                **  We check nMark2+2 to avoid executing next instructions when we have expr 
                                **  for example for x = 1 to 10+5 
                                */
                                nNum1 = ring_list_getdouble(pParser->ActiveGenCodeList,2) ;
                                ring_parser_icg_deletelastoperation(pParser);
                                ring_parser_icg_setlastoperation(pParser,ICO_JUMPVARLENUM);
                                ring_parser_icg_newoperanddouble(pParser,nNum1);
                                /* Add Locations Needed for Instruction change for performance */
                                nPerformanceLocations = 1 ;
                            } else {
                                ring_parser_icg_newoperation(pParser,ICO_JUMPFOR);
                            }
                            pMark = ring_parser_icg_getactiveoperation(pParser);
                            /* Step <expr> */
                            x = ring_parser_step(pParser,&nMark1);
                            if ( x == 0 ) {
                                ring_string_delete_gc(pParser->pRingState,pString);
                                return 0 ;
                            }
                            #if RING_PARSERTRACE
                            RING_STATE_CHECKPRINTRULES 
                            
                            puts("Rule : Statement  --> 'For' Identifier '=' Expr to Expr ['step' Expr]");
                            #endif
                            /* Save Loop|Exit commands status */
                            nLoopOrExitCommand = pParser->nLoopOrExitCommand ;
                            pParser->nLoopFlag++ ;
                            /* Free Temp Lists */
                            ring_parser_genfreetemplists(pParser);
                            RING_PARSER_ACCEPTSTATEMENTS ;
                            pParser->nLoopFlag-- ;
                            if ( ring_parser_iskeyword(pParser,K_NEXT) || ring_parser_iskeyword(pParser,K_ENDFOR) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
                                /* Generate Code */
                                nMark3 = ring_parser_icg_newlabel(pParser);
                                /* Increment Jump */
                                ring_parser_icg_newoperation(pParser,ICO_INCJUMP);
                                ring_parser_icg_newoperand(pParser,ring_string_get(pString));
                                ring_parser_icg_newoperandint(pParser,nMark1);
                                /* Add Locations needed for instruction change for performance */
                                ring_parser_icg_newoperandint(pParser,0);
                                ring_parser_icg_newoperandint(pParser,0);
                                nMark2 = ring_parser_icg_newlabel(pParser);
                                ring_parser_icg_addoperandint(pParser,pMark,nMark2);
                                /* Performance Locations */
                                if ( nPerformanceLocations ) {
                                    /* Add Locations Needed for Instruction JUMPVARLENUM change for performance */
                                    ring_parser_icg_addoperandint(pParser,pMark,0);
                                    ring_parser_icg_addoperandint(pParser,pMark,0);
                                }
                                /* Restore Loop|Exit Commands Status */
                                if ( pParser->nLoopOrExitCommand || ! pParser->nCheckLoopAndExit ) {
                                    /* Set Exit Mark */
                                    ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
                                    /* Set Loop Mark */
                                    ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
                                    /* End Loop (Remove Exit Mark) */
                                    ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
                                }
                                else {
                                    ring_list_setint_gc(pParser->pRingState,pMark3,1,ICO_NOOP);
                                }
                                if ( pParser->nLoopFlag == 0 ) {
                                    pParser->nLoopOrExitCommand = nLoopOrExitCommand ;
                                }
                                /* POP Step */
                                ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
                                /* Be more sure that (For-Loop) execution doesn't have any effects on the state */
                                ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
                                ring_parser_nexttoken(pParser);
                                #if RING_PARSERTRACE
                                RING_STATE_CHECKPRINTRULES 
                                
                                puts("Rule : Next --> 'Next'");
                                #endif
                                ring_string_delete_gc(pParser->pRingState,pString);
                                return 1 ;
                            } else {
                                ring_parser_error(pParser,RING_PARSER_ERROR_NEXT);
                            }
                        }
                    }
                }
            }
            else if ( ring_parser_iskeyword(pParser,K_IN) ) {
                /* Add the reference to the (For-In Loop) variables */
                nForInVarsCount = ring_list_getsize(pParser->pForInVars) + 1 ;
                ring_list_addstring(pParser->pForInVars,ring_string_get(pString));
                /* Generate Code */
                sprintf( cStr , "n_sys_var_%d" , ring_parser_icg_instructionscount(pParser) ) ;
                /* Mark for Exit command to go to outside the loop */
                ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
                pMark3 = ring_parser_icg_getactiveoperation(pParser);
                ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
                ring_parser_icg_newoperand(pParser,cStr);
                ring_parser_icg_newoperation(pParser,ICO_PUSHN);
                ring_parser_icg_newoperanddouble(pParser,1.0);
                /* Before Equal ( = ) not += , -= ,... etc */
                ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
                ring_parser_icg_newoperandint(pParser,0);
                ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
                /* Generate Code */
                nMark1 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
                ring_parser_icg_newoperand(pParser,cStr);
                ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
                ring_parser_icg_newoperand(pParser,"len");
                nStart = ring_parser_icg_instructionscount(pParser) + 1 ;
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                pParser->nAssignmentFlag = 0 ;
                if ( ring_parser_csexpr(pParser) ) {
                    pParser->nAssignmentFlag = 1 ;
                    /* Generate Code */
                    nEnd = ring_parser_icg_instructionscount(pParser) ;
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
                    ring_parser_icg_newoperation(pParser,ICO_CALL);
                    /* Generate 0 For Operator OverLoading */
                    ring_parser_icg_newoperandint(pParser,0);
                    ring_parser_icg_newoperation(pParser,ICO_JUMPFOR);
                    pMark = ring_parser_icg_getactiveoperation(pParser);
                    ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
                    ring_parser_icg_newoperand(pParser,ring_string_get(pString));
                    ring_parser_icg_duplicate(pParser,nStart,nEnd);
                    ring_parser_icg_newoperation(pParser,ICO_LOADAPUSHV);
                    ring_parser_icg_newoperand(pParser,cStr);
                    ring_parser_icg_newoperation(pParser,ICO_LOADINDEXADDRESS);
                    /* Generate 0 For Operator OverLoading */
                    ring_parser_icg_newoperandint(pParser,0);
                    /* Item by reference */
                    ring_parser_icg_newoperation(pParser,ICO_SETREFERENCE);
                    /* Step <expr> */
                    x = ring_parser_step(pParser,&nMark1);
                    if ( x == 0 ) {
                        ring_string_delete_gc(pParser->pRingState,pString);
                        return 0 ;
                    }
                    #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : Statement  --> 'For' Identifier 'in' Expr  ['step' Expr]");
                    #endif
                    /* Save Loop|Exit commands status */
                    nLoopOrExitCommand = pParser->nLoopOrExitCommand ;
                    pParser->nLoopFlag++ ;
                    /* Free Temp Lists */
                    ring_parser_genfreetemplists(pParser);
                    RING_PARSER_ACCEPTSTATEMENTS ;
                    pParser->nLoopFlag-- ;
                    if ( ring_parser_iskeyword(pParser,K_NEXT) || ring_parser_iskeyword(pParser,K_ENDFOR) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
                        ring_parser_nexttoken(pParser);
                        /* Generate Code */
                        nMark3 = ring_parser_icg_newlabel(pParser);
                        /* Increment Jump */
                        ring_parser_icg_newoperation(pParser,ICO_INCJUMP);
                        ring_parser_icg_newoperand(pParser,cStr);
                        ring_parser_icg_newoperandint(pParser,nMark1);
                        /* Add Locations needed for instruction change for performance */
                        ring_parser_icg_newoperandint(pParser,0);
                        ring_parser_icg_newoperandint(pParser,0);
                        nMark2 = ring_parser_icg_newlabel(pParser);
                        ring_parser_icg_addoperandint(pParser,pMark,nMark2);
                        /* Restore Loop|Exit Commands Status */
                        if ( pParser->nLoopOrExitCommand || ! pParser->nCheckLoopAndExit ) {
                            /* Set Exit Mark */
                            ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
                            /* Set Loop Mark */
                            ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
                            /* End Loop (Remove Exit Mark) */
                            ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
                        }
                        else {
                            ring_list_setint_gc(pParser->pRingState,pMark3,1,ICO_NOOP);
                        }
                        if ( pParser->nLoopFlag == 0 ) {
                            pParser->nLoopOrExitCommand = nLoopOrExitCommand ;
                        }
                        /* POP Step */
                        ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
                        /* Remove Reference Value */
                        for ( nVar = nForInVarsCount ; nVar <= ring_list_getsize(pParser->pForInVars) ; nVar++ ) {
                            ring_parser_icg_newoperation(pParser,ICO_LOADAFIRST);
                            ring_parser_icg_newoperand(pParser,ring_list_getstring(pParser->pForInVars,nVar));
                            ring_parser_icg_newoperation(pParser,ICO_KILLREFERENCE);
                        }
                        if ( nForInVarsCount == 1 ) {
                            ring_list_deleteallitems(pParser->pForInVars);
                        }
                        /* Be more sure that (For-Loop) execution doesn't have any effects on the state */
                        ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
                        #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        puts("Rule : Next --> 'Next'");
                        #endif
                        ring_string_delete_gc(pParser->pRingState,pString);
                        return 1 ;
                    } else {
                        ring_parser_error(pParser,RING_PARSER_ERROR_NEXT);
                    }
                }
            }
            ring_string_delete_gc(pParser->pRingState,pString);
        }
        return 0 ;
    }
    /* Statement --> IF Expr Statements OK */
    if ( ring_parser_iskeyword(pParser,K_IF) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        pParser->nAssignmentFlag = 0 ;
        if ( ring_parser_csexpr(pParser) ) {
            pParser->nAssignmentFlag = 1 ;
            /*
            **  First Condition 
            **  Generate Code 
            */
            ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
            pMark = ring_parser_icg_getactiveoperation(pParser);
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'If' Expr {Statement} { But } [Else] Ok");
            #endif
            RING_PARSER_ACCEPTSTATEMENTS ;
            /* Generate Code */
            pList2 = ring_list_new_gc(pParser->pRingState,0);
            ring_parser_icg_newoperation(pParser,ICO_JUMP);
            ring_list_addpointer_gc(pParser->pRingState,pList2,ring_parser_icg_getactiveoperation(pParser));
            /* { 'But' Statements } 'Else' Statements */
            while ( ring_parser_iskeyword(pParser,K_BUT) || ring_parser_iskeyword(pParser,K_ELSEIF) ) {
                /* Generate Code */
                nMark1 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark,nMark1);
                ring_parser_nexttoken(pParser);
                pParser->nAssignmentFlag = 0 ;
                if ( ring_parser_expr(pParser) ) {
                    pParser->nAssignmentFlag = 1 ;
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
                    pMark = ring_parser_icg_getactiveoperation(pParser);
                    #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : But  --> 'But' Expr {Statement}");
                    #endif
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
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Else  --> 'Else' {Statement} ");
                #endif
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
                        ring_parser_icg_addoperandint(pParser,((List *) ring_list_getpointer(pList2,x)),nMark1);
                    }
                }
                ring_list_delete_gc(pParser->pRingState,pList2);
                ring_parser_nexttoken(pParser);
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Ok  --> 'OK'");
                #endif
                return 1 ;
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_OK);
                ring_list_delete_gc(pParser->pRingState,pList2);
            }
        }
        return 0 ;
    }
    /* Statement --> WHILE Expr Statements END */
    if ( ring_parser_iskeyword(pParser,K_WHILE) ) {
        /*
        **  Generate Code 
        **  Set Step Number - Since We have Exit/Loop commands controls a mix of (For/While/... loops) 
        */
        ring_parser_icg_newoperation(pParser,ICO_PUSHN);
        ring_parser_icg_newoperanddouble(pParser,0.0);
        ring_parser_icg_newoperation(pParser,ICO_STEPNUMBER);
        /* Mark for Exit command to go to outsize the loop */
        ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
        pMark3 = ring_parser_icg_getactiveoperation(pParser);
        nMark1 = ring_parser_icg_newlabel(pParser);
        /* Free Temp Lists */
        ring_parser_genfreetemplists(pParser);
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        pParser->nAssignmentFlag = 0 ;
        if ( ring_parser_csexpr(pParser) ) {
            pParser->nAssignmentFlag = 1 ;
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
            pMark = ring_parser_icg_getactiveoperation(pParser);
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'While' Expr {Statement} End");
            #endif
            /* Save Loop|Exit commands status */
            nLoopOrExitCommand = pParser->nLoopOrExitCommand ;
            pParser->nLoopFlag++ ;
            RING_PARSER_ACCEPTSTATEMENTS ;
            pParser->nLoopFlag-- ;
            if ( ring_parser_iskeyword(pParser,K_END) || ring_parser_iskeyword(pParser,K_ENDWHILE) || ring_parser_csbraceend(pParser) ) {
                /* Generate Code */
                nMark3 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_newoperation(pParser,ICO_JUMP);
                ring_parser_icg_newoperandint(pParser,nMark1);
                nMark2 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark,nMark2);
                /* Restore Loop|Exit Commands Status */
                if ( pParser->nLoopOrExitCommand || ! pParser->nCheckLoopAndExit ) {
                    /* Set Exit Mark */
                    ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
                    /* Set Loop Mark */
                    ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
                    /* End Loop (Remove Exit Mark) */
                    ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
                }
                else {
                    ring_list_setint_gc(pParser->pRingState,pMark3,1,ICO_NOOP);
                }
                if ( pParser->nLoopFlag == 0 ) {
                    pParser->nLoopOrExitCommand = nLoopOrExitCommand ;
                }
                /* POP Step */
                ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
                ring_parser_nexttoken(pParser);
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : End --> 'End'");
                #endif
                return 1 ;
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_END);
            }
        }
        return 0 ;
    }
    /* Statement --> DO Statements AGAIN Expr */
    if ( ring_parser_iskeyword(pParser,K_DO) ) {
        /*
        **  Generate Code 
        **  Set Step Number - Since We have Exit/Loop commands controls a mix of (For/While/... loops) 
        */
        ring_parser_icg_newoperation(pParser,ICO_PUSHN);
        ring_parser_icg_newoperanddouble(pParser,0.0);
        ring_parser_icg_newoperation(pParser,ICO_STEPNUMBER);
        /* Mark for Exit command to go to outsize the loop */
        ring_parser_icg_newoperation(pParser,ICO_EXITMARK);
        pMark3 = ring_parser_icg_getactiveoperation(pParser);
        nMark1 = ring_parser_icg_newlabel(pParser);
        /* Free Temp Lists */
        ring_parser_genfreetemplists(pParser);
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Do' {Statement} Again");
        #endif
        /* Save Loop|Exit commands status */
        nLoopOrExitCommand = pParser->nLoopOrExitCommand ;
        pParser->nLoopFlag++ ;
        RING_PARSER_ACCEPTSTATEMENTS ;
        pParser->nLoopFlag-- ;
        if ( ring_parser_iskeyword(pParser,K_AGAIN) ) {
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
            pParser->nAssignmentFlag = 0 ;
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
                if ( pParser->nLoopOrExitCommand || ! pParser->nCheckLoopAndExit ) {
                    /* Set Exit Mark */
                    ring_parser_icg_addoperandint(pParser,pMark3,nMark2);
                    /* Set Loop Mark */
                    ring_parser_icg_addoperandint(pParser,pMark3,nMark1);
                    /* End Loop (Remove Exit Mark) */
                    ring_parser_icg_newoperation(pParser,ICO_POPEXITMARK);
                }
                else {
                    ring_list_setint_gc(pParser->pRingState,pMark3,1,ICO_NOOP);
                }
                if ( pParser->nLoopFlag == 0 ) {
                    pParser->nLoopOrExitCommand = nLoopOrExitCommand ;
                }
                /* POP Step */
                ring_parser_icg_newoperation(pParser,ICO_POPSTEP);
                pParser->nAssignmentFlag = 1 ;
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Again  --> 'Again' Expr");
                #endif
                return 1 ;
            }
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_AGAIN);
        }
        return 0 ;
    }
    /* Statement --> Return Expr */
    if ( ring_parser_iskeyword(pParser,K_RETURN) ) {
        ring_parser_nexttoken(pParser);
        x = 1 ;
        if ( ring_parser_isendline(pParser) == 0 ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_FREELOADASCOPE);
            ring_parser_icg_newoperation(pParser,ICO_FUNCEXE);
            pParser->nAssignmentFlag = 0 ;
            x = ring_parser_expr(pParser);
            pParser->nAssignmentFlag = 1 ;
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_ENDFUNCEXE);
            if ( x ) {
                ring_parser_icg_newoperation(pParser,ICO_RETURN);
            }
            else {
                ring_parser_icg_newoperation(pParser,ICO_RETNULL);
            }
        } else {
            /*
            **  Generate Code 
            **  Return NULL 
            */
            ring_parser_icg_newoperation(pParser,ICO_RETNULL);
        }
        #if RING_PARSERTRACE
        if ( x == 1 ) {
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'Return'");
        }
        #endif
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
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Try' {Statement} Catch Done");
        #endif
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
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Catch --> 'Catch' {Statement}");
            #endif
            RING_PARSER_ACCEPTSTATEMENTS ;
            if ( ring_parser_iskeyword(pParser,K_DONE) || ring_parser_iskeyword(pParser,K_ENDTRY) || ring_parser_iskeyword(pParser,K_END) || ring_parser_csbraceend(pParser) ) {
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Done --> 'Done'");
                #endif
                ring_parser_nexttoken(pParser);
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_JUMP);
                pMark3 = ring_parser_icg_getactiveoperation(pParser);
                nMark2 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark2,nMark2);
                ring_parser_icg_newoperation(pParser,ICO_DONE);
                nMark3 = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark3,nMark3);
                return 1 ;
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_NODONE);
            }
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_NOCATCH);
        }
    }
    /* Statement --> Bye (Close the Program) */
    if ( ring_parser_iskeyword(pParser,K_BYE) ) {
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Bye' ");
        #endif
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_BYE);
        return 1 ;
    }
    /* Statement --> Exit (Go to outside the loop) */
    if ( ring_parser_iskeyword(pParser,K_EXIT) || ring_parser_iskeyword(pParser,K_BREAK) ) {
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Exit' ");
        #endif
        /* Check usage outside loops */
        if ( ! pParser->nLoopFlag ) {
            if ( pParser->pRingState->nWarning ) {
                puts(RING_PARSER_WARNING_EXITOUTSIDELOOP);
            }
        }
        /* Check Number  (Exit from more than one loop) */
        if ( ring_parser_isnumber(pParser) || ring_parser_isidentifier(pParser) ) {
            if ( ! ring_parser_expr(pParser) ) {
                return 0 ;
            }
        }
        else {
            ring_parser_icg_newoperation(pParser,ICO_PUSHN);
            ring_parser_icg_newoperanddouble(pParser,1.0);
        }
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_EXIT);
        pParser->nLoopOrExitCommand = 1 ;
        return 1 ;
    }
    /* Statement --> Loop (Continue) */
    if ( ring_parser_iskeyword(pParser,K_LOOP) || ring_parser_iskeyword(pParser,K_CONTINUE) ) {
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Loop'");
        #endif
        /* Check usage outside loops */
        if ( ! pParser->nLoopFlag ) {
            if ( pParser->pRingState->nWarning ) {
                puts(RING_PARSER_WARNING_LOOPOUTSIDELOOP);
            }
        }
        /* Check Number  (Continue from more than one loop) */
        if ( ring_parser_isnumber(pParser) || ring_parser_isidentifier(pParser) ) {
            if ( ! ring_parser_expr(pParser) ) {
                return 0 ;
            }
        }
        else {
            ring_parser_icg_newoperation(pParser,ICO_PUSHN);
            ring_parser_icg_newoperanddouble(pParser,1.0);
        }
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_LOOP);
        pParser->nLoopOrExitCommand = 1 ;
        return 1 ;
    }
    /* Statement --> Switch  Expr { ON|CASE Expr {Statement} } OFF */
    if ( ring_parser_iskeyword(pParser,K_SWITCH) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        pParser->nAssignmentFlag = 0 ;
        if ( ring_parser_csexpr(pParser) ) {
            pParser->nAssignmentFlag = 1 ;
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Statement  --> 'Switch' Expr {ON} [Other] OFF");
            #endif
            RING_PARSER_IGNORENEWLINE ;
            /* ON|CASE Statements */
            pList2 = ring_list_new_gc(pParser->pRingState,0);
            pMark = NULL ;
            while ( ring_parser_iskeyword(pParser,K_ON) || ring_parser_iskeyword(pParser,K_CASE) ) {
                ring_parser_nexttoken(pParser);
                /* Generate Code */
                nMark1 = ring_parser_icg_newlabel(pParser);
                if ( pMark != NULL ) {
                    ring_parser_icg_addoperandint(pParser,pMark,nMark1);
                }
                ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
                pParser->nAssignmentFlag = 0 ;
                if ( ring_parser_expr(pParser) ) {
                    pParser->nAssignmentFlag = 1 ;
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_EQUAL);
                    ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
                    pMark = ring_parser_icg_getactiveoperation(pParser);
                    ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
                    #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : ON --> 'on' Expr {Statement}");
                    #endif
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
                ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Other --> 'Other' {Statement}");
                #endif
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
                        ring_parser_icg_addoperandint(pParser,((List *) ring_list_getpointer(pList2,x)),nMark1);
                    }
                }
                ring_list_delete_gc(pParser->pRingState,pList2);
                ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
                #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : OFF --> 'Off'");
                #endif
                return 1 ;
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_SWITCHOFF);
            }
        } else {
            ring_parser_error(pParser,RING_PARSER_ERROR_SWITCHEXPR);
        }
    }
    /* Statement --> Import Identifier { '.' Identifier } */
    if ( ring_parser_iskeyword(pParser,K_IMPORT) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_IMPORT);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> 'Import' Identifier{'.'identifier}");
        #endif
        return ring_parser_namedotname(pParser) ;
    }
    /* Statement --> epsilon */
    if ( ring_parser_epsilon(pParser) ) {
        return 1 ;
    }
    /* Statement --> Expr */
    if ( ring_parser_expr(pParser) ) {
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : Statement  --> Expr ");
        #endif
        /*
        **  Generate Code 
        **  Call expreval() if we are inside { } 
        */
        if ( pParser->nBraceFlag ) {
            /* if ismethod(self,"braceexpreval") braceexpreval() ok */
            ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
            ring_parser_icg_newoperand(pParser,"ismethod");
            ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
            ring_parser_icg_newoperand(pParser,"self");
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            ring_parser_icg_newoperation(pParser,ICO_PUSHC);
            ring_parser_icg_newoperand(pParser,"braceexpreval");
            ring_parser_icg_newoperation(pParser,ICO_CALL);
            ring_parser_icg_newoperation(pParser,ICO_NOOP);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            /* Jump */
            ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
            pMark = ring_parser_icg_getactiveoperation(pParser);
            ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
            ring_parser_icg_newoperand(pParser,"braceexpreval");
            /* Duplicate Stack */
            ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
            ring_parser_icg_newoperation(pParser,ICO_CALL);
            ring_parser_icg_newoperation(pParser,ICO_NOOP);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
            nMark1 = ring_parser_icg_newlabel(pParser);
            ring_parser_icg_addoperandint(pParser,pMark,nMark1);
        }
        ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
        return 1 ;
    }
    return 0 ;
}

int ring_parser_paralist ( Parser *pParser )
{
    int nStart  ;
    const char *cToken  ;
    /* Check ( */
    nStart = 0 ;
    if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
        ring_parser_nexttoken(pParser);
        nStart = 1 ;
    }
    /* ParaList --> epsilon */
    if ( ring_parser_isendline(pParser) || (nStart && ring_parser_isoperator2(pParser,OP_FCLOSE) ) ) {
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : ParaList --> Epsilon ");
        #endif
        return 1 ;
    }
    /* ParaList --> [ Identifier { , Identifier }  ] */
    if ( ring_parser_isidentifier(pParser) ) {
        cToken = pParser->TokenText ;
        ring_parser_nexttoken(pParser);
        /* Support Type Identifier */
        if ( nStart && ring_parser_isidentifier(pParser) ) {
            cToken = pParser->TokenText ;
            ring_parser_nexttoken(pParser);
        }
        /* Generate Code */
        ring_parser_icg_newoperand(pParser,cToken);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : ParaList --> Identifier {',' Identifier}");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
            if ( ring_parser_isidentifier(pParser) ) {
                cToken = pParser->TokenText ;
                ring_parser_nexttoken(pParser);
                /* Support Type Identifier */
                if ( nStart && ring_parser_isidentifier(pParser) ) {
                    cToken = pParser->TokenText ;
                    ring_parser_nexttoken(pParser);
                }
                /* Generate Code */
                ring_parser_icg_newoperand(pParser,cToken);
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_PARALIST);
                return 0 ;
            }
        }
        if ( nStart && ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
            ring_parser_nexttoken(pParser);
        }
        return 1 ;
    } else {
        ring_parser_error(pParser,RING_PARSER_ERROR_PARALIST);
        return 0 ;
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
            #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : List --> '[' Expr { ',' Expr } ']' ");
            #endif
            return 1 ;
        }
        while ( 1 ) {
            pParser->nAssignmentFlag = 0 ;
            if ( ring_parser_expr(pParser) ) {
                /* Generate Code */
                if ( ring_parser_icg_getlastoperation(pParser) != ICO_LISTEND ) {
                    ring_parser_icg_newoperation(pParser,ICO_LISTITEM);
                }
                pParser->nAssignmentFlag = 1 ;
                RING_PARSER_IGNORENEWLINE ;
                if ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
                    ring_parser_nexttoken(pParser);
                }
                else if ( ring_parser_isoperator2(pParser,OP_LCLOSE) ) {
                    ring_parser_nexttoken(pParser);
                    #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : List --> '[' Expr { ',' Expr } ']' ");
                    #endif
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_LISTEND);
                    return 1 ;
                } else {
                    ring_parser_error(pParser,RING_PARSER_ERROR_LISTITEM);
                    return 0 ;
                }
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_LISTITEM);
                return 0 ;
            }
            RING_PARSER_IGNORENEWLINE ;
        }
    }
    return 0 ;
}

int ring_parser_epsilon ( Parser *pParser )
{
    if ( ring_parser_isendline(pParser) ) {
        /* Generate Code */
        if ( pParser->pRingState->lNoLineNumber == 0 ) {
            ring_parser_icg_newoperation(pParser,ICO_NEWLINE);
            ring_parser_icg_newoperandint(pParser,atoi(pParser->TokenText));
        }
        pParser->nLineNumber = atoi(pParser->TokenText) ;
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        printf( "\nLine %d \n",pParser->nLineNumber ) ;
        #endif
        if ( ring_parser_nexttoken(pParser) ) {
            return 1 ;
        }
        if ( pParser->TokensCount == 1 ) {
            return 1 ;
        }
    }
    return 0 ;
}

int ring_parser_passepsilon ( Parser *pParser )
{
    /* used after factor - identifier to allow {  } in new line */
    if ( ring_parser_isendline(pParser) ) {
        pParser->nLineNumber = atoi(pParser->TokenText) ;
        if ( ring_parser_nexttoken(pParser) ) {
            return 1 ;
        }
    }
    return 0 ;
}

int ring_parser_namedotname ( Parser *pParser )
{
    String *pString  ;
    if ( ring_parser_isidentifier(pParser) ) {
        /* Get Token Text */
        pString = ring_string_new_gc(pParser->pRingState,pParser->TokenText);
        ring_parser_nexttoken(pParser);
        while ( ring_parser_isoperator2(pParser,OP_DOT) ) {
            ring_parser_nexttoken(pParser);
            ring_string_add_gc(pParser->pRingState,pString,".");
            if ( ring_parser_isidentifier(pParser) ) {
                ring_string_add_gc(pParser->pRingState,pString,pParser->TokenText);
                ring_parser_nexttoken(pParser);
            } else {
                ring_parser_error(pParser,RING_PARSER_ERROR_PACKAGENAME);
                ring_string_delete_gc(pParser->pRingState,pString);
                return 0 ;
            }
        }
        /* Generate Code */
        ring_parser_icg_newoperand(pParser,ring_string_get(pString));
        ring_string_delete_gc(pParser->pRingState,pString);
        return 1 ;
    } else {
        ring_parser_error(pParser,RING_PARSER_ERROR_PACKAGENAME);
        return 0 ;
    }
}

int ring_parser_step ( Parser *pParser,int *nMark1 )
{
    /* Step <expr> */
    pParser->nInsertFlag = 1 ;
    pParser->nInsertCounter = *nMark1-1 ;
    if ( ring_parser_iskeyword(pParser,K_STEP) ) {
        ring_parser_nexttoken(pParser);
        pParser->nAssignmentFlag = 0 ;
        if ( ring_parser_csexpr(pParser) ) {
            pParser->nAssignmentFlag = 1 ;
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_STEPNUMBER);
        } else {
            return 0 ;
        }
    } else {
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PUSHN);
        ring_parser_icg_newoperanddouble(pParser,1.0);
        ring_parser_icg_newoperation(pParser,ICO_STEPNUMBER);
    }
    *nMark1 = pParser->nInsertCounter + 1 ;
    pParser->nInsertFlag = 0 ;
    pParser->nInsertCounter = 0 ;
    return 1 ;
}

int ring_parser_csexpr ( Parser *pParser )
{
    int nOutput  ;
    pParser->nControlStructureExpr = 1 ;
    nOutput = ring_parser_expr(pParser);
    if ( nOutput == 0 ) {
        ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
    }
    pParser->nControlStructureExpr = 0 ;
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
        return 1 ;
    }
    return 0 ;
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
                if ( pParser->ActiveToken == pParser->TokensCount ) {
                    break ;
                }
            }
        }
        else {
            RING_PARSER_ACCEPTSTATEMENTS ;
        }
        if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
            ring_parser_nexttoken(pParser);
            return 1 ;
        }
        return 0 ;
    }
    /* Support using End */
    while ( ring_parser_class(pParser) ) {
        if ( pParser->ActiveToken == pParser->TokensCount ) {
            break ;
        }
    }
    if ( ring_parser_iskeyword(pParser,K_END) || ring_parser_iskeyword(pParser,nKeyword) || ( (nKeyword == K_ENDFUNC) && ring_parser_iskeyword(pParser,K_ENDFUNCTION)) ) {
        ring_parser_nexttoken(pParser);
        #if RING_PARSERTRACE
        RING_STATE_CHECKPRINTRULES 
        
        puts("Rule : End --> 'End'");
        #endif
    }
    return 1 ;
}

int ring_parser_gencallringvmsee ( Parser *pParser )
{
    int x,nFlag  ;
    /* Generate code to use the SEE function */
    ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
    ring_parser_icg_newoperand(pParser,"ringvm_see");
    /* Parameters */
    nFlag = pParser->nAssignmentFlag ;
    pParser->nAssignmentFlag = 0 ;
    x = ring_parser_expr(pParser);
    pParser->nAssignmentFlag = nFlag ;
    if ( x == 0 ) {
        ring_parser_error(pParser,RING_PARSER_ERROR_EXPRESSIONISEXPECTED);
        return 0 ;
    }
    ring_parser_icg_newoperation(pParser,ICO_CALL);
    ring_parser_icg_newoperandint(pParser,0);
    ring_parser_icg_newoperation(pParser,ICO_NOOP);
    ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
    return x ;
}

void ring_parser_genfreetemplists ( Parser *pParser )
{
    /* Using the Free Temp Lists instruction */
    ring_parser_icg_newoperation(pParser,ICO_FREETEMPLISTS);
    /* The number of temp variables before calling the instruction for the first time */
    ring_parser_icg_newoperandint(pParser,0);
    /*
    **  The Scope ID of the Current Function 
    **  Each time Ring VM call a function, we get a new Scope ID 
    **  We cache this Scope ID, If it's changed this means we have a new function call 
    **  In this case we refresh the number of temp. variables 
    */
    ring_parser_icg_newoperandint(pParser,0);
}
