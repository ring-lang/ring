/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_parser_start ( List *pTokens,RingState *pRingState )
{
	Parser *pParser  ;
	int nResult,nRingActiveFile  ;
	pParser = ring_parser_new(pTokens,pRingState);
	/* Parse Tokens */
	ring_parser_nexttoken(pParser);
	do {
		nResult = ring_parser_class(pParser);
		if ( nResult == 0 ) {
			ring_parser_error(pParser,RING_CSTR_EMPTY);
			/* Important check to avoid missing the line number counter */
			if ( ring_parser_isendline(pParser) == 0 ) {
				/* Move next trying to avoid the error */
				ring_parser_nexttoken(pParser);
			}
		}
	} while (pParser->nActiveToken !=pParser->nTokensCount)  ;
	/* Display Errors Count */
	nRingActiveFile = ring_list_getsize(pParser->pRingState->pRingFilesStack);
	if ( pParser->nErrorsCount == 0 ) {
		ring_parser_delete(pParser);
		return RING_PARSER_OK ;
	}
	else {
		printf( "\n%s errors count : %d \n",ring_list_getstring(pParser->pRingState->pRingFilesStack,nRingActiveFile),pParser->nErrorsCount ) ;
	}
	ring_parser_delete(pParser);
	return RING_PARSER_FAIL ;
}

Parser * ring_parser_new ( List *pTokens,RingState *pRingState )
{
	Parser *pParser  ;
	pParser = (Parser *) ring_state_malloc(pRingState,sizeof(Parser));
	/* Ring State */
	pParser->pRingState = pRingState ;
	pParser->pTokens = pTokens ;
	pParser->nActiveToken = 0 ;
	pParser->nTokensCount = ring_list_getsize(pParser->pTokens) ;
	pParser->nTokenIndex = 0 ;
	pParser->nLineNumber = 1 ;
	pParser->nErrorLine = 0 ;
	pParser->nErrorsCount = 0 ;
	if ( pRingState->pRingGenCode == NULL ) {
		pRingState->pRingGenCode = ring_list_new(RING_ZERO);
		pRingState->pRingFunctionsMap = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingClassesMap = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingPackagesMap = ring_list_new_gc(pRingState,RING_ZERO);
	}
	pParser->pGenCode = pRingState->pRingGenCode ;
	pParser->pFunctionsMap = pRingState->pRingFunctionsMap ;
	pParser->pActiveGenCodeList = NULL ;
	pParser->lAssignmentFlag = 1 ;
	pParser->lClassStart = 0 ;
	pParser->pClassesMap = pRingState->pRingClassesMap ;
	pParser->pPackagesMap = pRingState->pRingPackagesMap ;
	pParser->nClassMark = 0 ;
	pParser->lPrivateFlag = 0 ;
	pParser->nBracesCounter = 0 ;
	pParser->lInsertFlag = 0 ;
	pParser->nInsertCounter = 0 ;
	pParser->lNewObject = 0 ;
	pParser->lFuncCallOnly = 0 ;
	pParser->lControlStructureExpr = 0 ;
	pParser->nControlStructureBrace = 0 ;
	pParser->lThisOrSelfLoadA = 0 ;
	pParser->lThisLoadA = 0 ;
	pParser->lLoopOrExitCommand = 0 ;
	pParser->lCheckLoopAndExit = 1 ;
	pParser->nLoopCounter = 0 ;
	pParser->pForInVars = ring_list_new_gc(pRingState,RING_ZERO);
	return pParser ;
}

Parser * ring_parser_delete ( Parser *pParser )
{
	pParser->pForInVars = ring_list_delete_gc(pParser->pRingState,pParser->pForInVars);
	ring_state_free(pParser->pRingState,pParser);
	return NULL ;
}
/* Check Token */

void ring_parser_loadtoken ( Parser *pParser )
{
	List *pList  ;
	pList = ring_list_getlist(pParser->pTokens,pParser->nActiveToken);
	pParser->nTokenType = ring_list_getint(pList,RING_SCANNER_TOKENTYPE) ;
	pParser->cTokenText = ring_list_getstring(pList,RING_SCANNER_TOKENVALUE) ;
	pParser->nTokenIndex = ring_list_getint(pList,RING_SCANNER_TOKENINDEX) ;
}

int ring_parser_nexttoken ( Parser *pParser )
{
	if ( pParser->nActiveToken < pParser->nTokensCount ) {
		pParser->nActiveToken++ ;
		ring_parser_loadtoken(pParser);
		return RING_TRUE ;
	}
	return RING_FALSE ;
}

int ring_parser_iskeyword ( Parser *pParser,SCANNER_KEYWORD nKeyword )
{
	if ( pParser->nTokenType == SCANNER_TOKEN_KEYWORD ) {
		if ( ((unsigned int) atoi(pParser->cTokenText)) == ((unsigned int) nKeyword) ) {
			return RING_TRUE ;
		}
	}
	return RING_FALSE ;
}

int ring_parser_isoperator ( Parser *pParser,const char *cStr )
{
	return (pParser->nTokenType == SCANNER_TOKEN_OPERATOR) && (strcmp( pParser->cTokenText,cStr) == 0 ) ;
}

int ring_parser_isliteral ( Parser *pParser )
{
	return (pParser->nTokenType == SCANNER_TOKEN_LITERAL) ;
}

int ring_parser_isnumber ( Parser *pParser )
{
	return (pParser->nTokenType ==SCANNER_TOKEN_NUMBER) ;
}

int ring_parser_isidentifier ( Parser *pParser )
{
	return (pParser->nTokenType ==SCANNER_TOKEN_IDENTIFIER) ;
}

int ring_parser_isendline ( Parser *pParser )
{
	return (pParser->nTokenType == SCANNER_TOKEN_ENDLINE) ;
}

int ring_parser_settoken ( Parser *pParser,int nToken )
{
	if ( (nToken >= 1) && (nToken <= pParser->nTokensCount) ) {
		pParser->nActiveToken = nToken ;
		ring_parser_loadtoken(pParser);
		return RING_TRUE ;
	}
	return RING_FALSE ;
}

int ring_parser_isanykeyword ( Parser *pParser )
{
	return (pParser->nTokenType == SCANNER_TOKEN_KEYWORD) ;
}

int ring_parser_isoperator2 ( Parser *pParser,SCANNER_OPERATOR nType )
{
	return (pParser->nTokenType == SCANNER_TOKEN_OPERATOR) && ( pParser->nTokenIndex == (int) nType ) ;
}
/* Display Errors */

void ring_parser_error ( Parser *pParser,const char *cStr )
{
	int nRingActiveFile  ;
	ring_state_cgiheader(pParser->pRingState);
	nRingActiveFile = ring_list_getsize(pParser->pRingState->pRingFilesStack);
	if ( pParser->nErrorLine != pParser->nLineNumber ) {
		pParser->nErrorLine = pParser->nLineNumber ;
		printf( "\n%s Line (%d) ",ring_list_getstring(pParser->pRingState->pRingFilesStack,nRingActiveFile),pParser->nLineNumber ) ;
		pParser->nErrorsCount++ ;
		if ( strcmp(cStr,RING_CSTR_EMPTY) != 0 ) {
			printf( "%s",cStr ) ;
		}
		else {
			printf( RING_PARSER_ERROR_SYNTAXERROR ) ;
		}
		printf( "\n" ) ;
		return ;
	}
	else if ( strcmp(cStr,RING_CSTR_EMPTY) != 0 ) {
		pParser->nErrorsCount++ ;
	}
	if ( strcmp(cStr,RING_CSTR_EMPTY) != 0 ) {
		printf( "\n%s Line (%d) ",ring_list_getstring(pParser->pRingState->pRingFilesStack,nRingActiveFile),pParser->nLineNumber ) ;
		printf( "%s\n",cStr ) ;
	}
}
