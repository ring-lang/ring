/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Functions */

Scanner * ring_scanner_new ( RingState *pRingState )
{
    Scanner *pScanner  ;
    pScanner = (Scanner *) ring_state_malloc(pRingState,sizeof(Scanner));
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
    if ( pScanner->Tokens != NULL ) {
        pScanner->Tokens = ring_list_delete_gc(pScanner->pRingState,pScanner->Tokens);
    }
    pScanner->ActiveToken = ring_string_delete_gc(pScanner->pRingState,pScanner->ActiveToken);
    ring_state_free(pScanner->pRingState,pScanner);
    return NULL ;
}

void ring_scanner_readchar ( Scanner *pScanner,char c )
{
    char cStr[2]  ;
    List *pList  ;
    String *pString  ;
    int nTokenIndex  ;
    assert(pScanner != NULL);
    /* Set Variables */
    cStr[0] = c ;
    cStr[1] = '\0' ;
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
            if ( c != ' ' && c != '\n' && c != ';' && c != '\t' && c != '\"' && c != '\'' && c != '\r' && c != '`' ) {
                if ( ring_scanner_isoperator(pScanner,cStr) ) {
                    nTokenIndex = pScanner->nTokenIndex ;
                    ring_scanner_checktoken(pScanner);
                    ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
                    #if RING_SCANNEROUTPUT
                        printf( "\nTOKEN (Operator) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
                    #endif
                    /* Check Operator Then Operator */
                    if ( ring_scanner_lasttokentype(pScanner) ==SCANNER_TOKEN_OPERATOR ) {
                        /* Check Multiline Comment */
                        if ( strcmp(cStr,"*") == 0 ) {
                            pList = ring_list_getlist(pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
                            if ( strcmp(ring_list_getstring(pList,2),"/") == 0 ) {
                                ring_list_deleteitem_gc(pScanner->pRingState,pScanner->Tokens,ring_list_getsize(pScanner->Tokens));
                                pScanner->state = SCANNER_STATE_MLCOMMENT ;
                                ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"/*");
                                #if RING_SCANNEROUTPUT
                                    printf( "\nMultiline comments start, ignore /* \n" ) ;
                                #endif
                                return ;
                            }
                        }
                        /* Check comment using // */
                        if ( strcmp(cStr,"/") == 0 ) {
                            if ( strcmp("/",ring_scanner_lasttokenvalue(pScanner)) ==  0 ) {
                                RING_SCANNER_DELETELASTTOKEN ;
                                pScanner->state = SCANNER_STATE_COMMENT ;
                                ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"//");
                                return ;
                            }
                        }
                        /* Check << | >> operators */
                        if ( ( strcmp(cStr,"<") == 0 ) | ( strcmp(cStr,">") == 0 ) ) {
                            if ( strcmp(cStr,ring_scanner_lasttokenvalue(pScanner)) ==  0 ) {
                                if ( strcmp(cStr,"<") == 0 ) {
                                    RING_SCANNER_DELETELASTTOKEN ;
                                    ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"<<");
                                }
                                else {
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
                    }
                    pScanner->nTokenIndex = nTokenIndex ;
                    ring_scanner_addtoken(pScanner,SCANNER_TOKEN_OPERATOR);
                }
                else {
                    ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
                }
            }
            else {
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
                pScanner->nLiteralLine = pScanner->LinesCount ;
            }
            else if ( c == '\'' ) {
                pScanner->state = SCANNER_STATE_LITERAL ;
                pScanner->cLiteral = '\'' ;
                pScanner->nLiteralLine = pScanner->LinesCount ;
            }
            else if ( c == '`' ) {
                pScanner->state = SCANNER_STATE_LITERAL ;
                pScanner->cLiteral = '`' ;
                pScanner->nLiteralLine = pScanner->LinesCount ;
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
            }
            else {
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
                if ( pScanner->pRingState->lCommentsAsTokens ) {
                    ring_scanner_addtoken(pScanner,SCANNER_TOKEN_COMMENT);
                }
                ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
            }
            else {
                if ( pScanner->pRingState->lCommentsAsTokens ) {
                    ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
                }
            }
            break ;
        case SCANNER_STATE_MLCOMMENT :
            /* Check Multiline Comment */
            if ( pScanner->pRingState->lCommentsAsTokens ) {
                ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
            }
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
                        if ( pScanner->pRingState->lCommentsAsTokens ) {
                            ring_scanner_addtoken(pScanner,SCANNER_TOKEN_COMMENT);
                        }
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
            }
            else if ( c == '#' || ring_scanner_isoperator(pScanner,cStr) ) {
                pScanner->state = SCANNER_STATE_GENERAL ;
                ring_scanner_changekeyword(pScanner);
                ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
                /* Read the character again (Don't ignore the operator) */
                ring_scanner_readchar(pScanner,c);
            }
            else if ( (c == ' ') || (c == '\t') ) {
                ring_scanner_readtwoparameters(pScanner,cStr);
            }
            else {
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
            }
            else if ( (c == ' ') || (c == '\t') ) {
                ring_scanner_readtwoparameters(pScanner,cStr);
            }
            else {
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
            }
            else {
                ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
            }
            break ;
    }
    if ( c == '\n' ) {
        pScanner->LinesCount++ ;
    }
    if ( ( c == ';' || c == '\n' ) && ( pScanner->state == SCANNER_STATE_GENERAL ) ) {
        if ( (ring_scanner_lasttokentype(pScanner) != SCANNER_TOKEN_ENDLINE ) ) {
            ring_string_setfromint_gc(pScanner->pRingState,pScanner->ActiveToken,pScanner->LinesCount);
            ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
            #if RING_SCANNEROUTPUT
                printf( "\nTOKEN (ENDLINE)  \n" ) ;
            #endif
        }
        else {
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
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endif");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endfor");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endwhile");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endswitch");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endtry");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"function");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"endfunction");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"break");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"continue");
    /*
    **  The next keywords are sensitive to the order and keywords count 
    **  if you will add new keywords revise constants and ring_scanner_checktoken() 
    */
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"changeringkeyword");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"changeringoperator");
    ring_list_addstring_gc(pScanner->pRingState,pScanner->Keywords,"loadsyntax");
    ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Keywords);
}

void ring_scanner_addtoken ( Scanner *pScanner,int nType )
{
    List *pList  ;
    assert(pScanner != NULL);
    pList = ring_list_newlist_gc(pScanner->pRingState,pScanner->Tokens);
    /* Add Token Type */
    ring_list_addint_gc(pScanner->pRingState,pList,nType);
    /* Add Token Text */
    ring_list_addstring_gc(pScanner->pRingState,pList,ring_scanner_processtoken(pScanner,nType));
    /* Add Token Index */
    ring_list_addint_gc(pScanner->pRingState,pList,pScanner->nTokenIndex);
    pScanner->nTokenIndex = 0 ;
    ring_scanner_floatmark(pScanner,nType);
    ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
}

void ring_scanner_checktoken ( Scanner *pScanner )
{
    int nResult  ;
    char cStr[5]  ;
    char *cActiveStr  ;
    /* This function determine if the TOKEN is a Keyword or Identifier or Number */
    assert(pScanner != NULL);
    /* Not Case Sensitive */
    if ( pScanner->pRingState->lNotCaseSensitive ) {
        ring_string_tolower(pScanner->ActiveToken);
        cActiveStr = ring_string_get(pScanner->ActiveToken) ;
        nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Keywords),cActiveStr);
    }
    else {
        cActiveStr = ring_string_strdup(pScanner->pRingState,ring_string_get(pScanner->ActiveToken));
        cActiveStr = ring_string_lower(cActiveStr);
        nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Keywords),cActiveStr);
        ring_state_free(pScanner->pRingState,cActiveStr);
    }
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
    }
    else {
        /* Add Identifier */
        if ( strcmp(ring_string_get(pScanner->ActiveToken),"") != 0 ) {
            if ( ring_scanner_isnumber(ring_string_get(pScanner->ActiveToken) ) == 0 ) {
                #if RING_SCANNEROUTPUT
                    printf( "\nTOKEN (Identifier) = %s  \n",ring_string_get(pScanner->ActiveToken) ) ;
                #endif
                ring_scanner_addtoken(pScanner,SCANNER_TOKEN_IDENTIFIER);
            }
            else {
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
    unsigned int x,x2,lHex  ;
    lHex = 0 ;
    for ( x = 0 ; x < strlen(cStr) ; x++ ) {
        /* Accept Hexadecimal values */
        if ( (x == 0) && (strlen(cStr) > 2) ) {
            if ( cStr[0] == '0' ) {
                x2 = x ;
                /* Support Many Zeros */
                while ( (cStr[x2] == '0') && x2 < strlen(cStr) - 1 ) {
                    x2++ ;
                }
                /* Support 0x */
                if ( (cStr[x2] == 'x') || (cStr[x2] == 'X') ) {
                    lHex = 1 ;
                    x = x2+1 ;
                    continue ;
                }
            }
        }
        if ( lHex ) {
            /* Support A-F & a-f */
            if ( (cStr[x] >= 97 && cStr[x] <= 102) || (cStr[x] >= 65 && cStr[x] <= 70) ) {
                continue ;
            }
        }
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
            if ( pScanner->pRingState->lCommentsAsTokens ) {
                ring_scanner_addtoken(pScanner,SCANNER_TOKEN_COMMENT);
            }
            return 1 ;
        }
    }
    if ( pScanner->state == SCANNER_STATE_LITERAL ) {
        if ( pScanner->pRingState->nOnlyTokens ) {
            pScanner->pRingState->nScannerError = 1 ;
            return 0 ;
        }
        ring_state_cgiheader(pScanner->pRingState);
        printf( "Error (S1) In file: %s \n",ring_list_getstring(pScanner->pRingState->pRingFilesList,ring_list_getsize(pScanner->pRingState->pRingFilesList)) ) ;
        printf( "In Line (%d) Literal not closed \n",pScanner->nLiteralLine ) ;
        if ( ring_list_getsize(pScanner->pRingState->pRingFilesList) > 1 ) {
            printf( "Called from other source code file" ) ;
        }
        return 0 ;
    }
    else if ( pScanner->state ==SCANNER_STATE_GENERAL ) {
        ring_scanner_checktoken(pScanner);
    }
    else if ( (pScanner->state == SCANNER_STATE_COMMENT) || (pScanner->state ==SCANNER_STATE_MLCOMMENT) ) {
        if ( pScanner->pRingState->lCommentsAsTokens ) {
            ring_scanner_addtoken(pScanner,SCANNER_TOKEN_COMMENT);
        }
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

const char * ring_scanner_lasttokenvalue ( Scanner *pScanner )
{
    int x  ;
    List *pList  ;
    assert(pScanner != NULL);
    x = ring_list_getsize(pScanner->Tokens);
    if ( x > 0 ) {
        pList = ring_list_getlist(pScanner->Tokens,x);
        return (const char *) ring_list_getstring(pList,2) ;
    }
    return "" ;
}

void ring_scanner_floatmark ( Scanner *pScanner,int nType )
{
    List *pList  ;
    String *pString  ;
    assert(pScanner != NULL);
    switch ( pScanner->FloatMark ) {
        case 0 :
            if ( nType == SCANNER_TOKEN_NUMBER ) {
                pScanner->FloatMark = 1 ;
            }
            break ;
        case 1 :
            if ( (nType == SCANNER_TOKEN_OPERATOR) && ( strcmp(ring_string_get(pScanner->ActiveToken) , "." ) == 0  ) ) {
                pScanner->FloatMark = 2 ;
            }
            else {
                pScanner->FloatMark = 0 ;
            }
            break ;
        case 2 :
            if ( nType == SCANNER_TOKEN_NUMBER ) {
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
    ring_general_printline();
    puts("Tokens - Generated by the Scanner");
    ring_general_printline();
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
    ring_general_printline();
}

const char * ring_scanner_getkeywordtext ( const char *cStr )
{
    return RING_KEYWORDS[atoi(cStr)-1] ;
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
        puts("Warning (W2) : The Compiler command  ChangeRingKeyword requires two words as parameters");
    }
    else {
        nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Keywords),ring_string_get(word1));
        if ( nResult > 0 ) {
            ring_list_setstring_gc(pScanner->pRingState,pScanner->Keywords,nResult,ring_string_get(word2));
            ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Keywords);
        }
        else {
            puts("Warning (W3) : Compiler command ChangeRingKeyword - Keyword not found !");
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
        puts("Warning (W4) : The Compiler command  ChangeRingOperator requires two words as parameters");
    }
    else {
        nResult = ring_hashtable_findnumber(ring_list_gethashtable(pScanner->Operators),ring_string_get(word1));
        if ( nResult > 0 ) {
            ring_list_setstring_gc(pScanner->pRingState,pScanner->Operators,nResult,ring_string_get(word2));
            ring_list_genhashtable_gc(pScanner->pRingState,pScanner->Operators);
        }
        else {
            puts("Warning (W5) : Compiler command ChangeRingOperator - Operator not found !");
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
    char cFileName2[RING_PATHSIZE]  ;
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
    if ( ring_general_fexists(cFileName) == 0 ) {
        ring_general_exefolder(cFileName2);
        strcat(cFileName2,cFileName);
        if ( ring_general_fexists(cFileName2) == 0 ) {
            /* Support ring/bin/load folder */
            ring_general_exefolder(cFileName2);
            strcat(cFileName2,"load/");
            strcat(cFileName2,cFileName);
            if ( ring_general_fexists(cFileName2) == 0 ) {
                strcpy(cFileName,cFileName2);
            }
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

void ring_scanner_readtwoparameters ( Scanner *pScanner,const char *cStr )
{
    int x,nSize,nSpaces  ;
    char *cString  ;
    /* Set Variables */
    x = 0 ;
    nSize = 0 ;
    nSpaces = 0 ;
    cString = ring_string_get(pScanner->ActiveToken) ;
    nSize = strlen(cString) ;
    if ( nSize > 0 ) {
        if ( (cString[nSize-1] != ' ') && (cString[nSize-1] != '\t') ) {
            nSpaces = 0 ;
            for ( x = 0 ; x < nSize ; x++ ) {
                if ( (cString[x] == ' ') || (cString[x] == '\t') ) {
                    nSpaces++ ;
                }
            }
            if ( nSpaces == 0 ) {
                ring_string_add_gc(pScanner->pRingState,pScanner->ActiveToken,cStr);
            }
            else {
                /* Consider it the end of the instruction */
                if ( pScanner->state == SCANNER_STATE_CHANGEKEYWORD ) {
                    pScanner->state = SCANNER_STATE_GENERAL ;
                    ring_scanner_changekeyword(pScanner);
                    ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
                }
                else if ( pScanner->state == SCANNER_STATE_CHANGEOPERATOR ) {
                    pScanner->state = SCANNER_STATE_GENERAL ;
                    ring_scanner_changeoperator(pScanner);
                    ring_string_set_gc(pScanner->pRingState,pScanner->ActiveToken,"");
                }
            }
        }
    }
}

const char * ring_scanner_processtoken ( Scanner *pScanner,int nType )
{
    char *pStart, *pChar  ;
    int t,nPos,nSize,lXExist  ;
    pStart = ring_string_get(pScanner->ActiveToken);
    if ( nType == SCANNER_TOKEN_NUMBER ) {
        /* Remove Many Zeros in the Start */
        pChar = pStart ;
        nSize = strlen(pChar) ;
        nPos = 0 ;
        if ( nSize > 0 ) {
            if ( pChar[0] == '0' ) {
                lXExist = 0 ;
                for ( t = 1 ; t < nSize ; t++ ) {
                    if ( ( pChar[t-1] == '0') && (pChar[t] == '0') ) {
                        nPos++ ;
                    }
                    if ( (pChar[t] == 'x' ) || (pChar[t] == 'X') ) {
                        lXExist = 1 ;
                        break ;
                    }
                }
                if ( lXExist ) {
                    pStart += nPos ;
                }
            }
        }
    }
    return pStart ;
}
