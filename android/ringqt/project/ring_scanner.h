/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_scanner_h
#define ring_scanner_h
/* Data */
typedef struct Scanner {
	char state  ;
	List *Keywords  ;
	List *Operators  ;
	List *Tokens  ;
	String *ActiveToken  ;
	int LinesCount  ;
	/* Float Identification (0 = Start 1 = Number  2 = Number Dot  3 = Number Dot Number ) */
	char FloatMark  ;
	/* Literal Type "  or ' */
	char cLiteral  ;
	/* Multiline comment end ( 0 = start  1 = * ) */
	char cMLComment  ;
	/* Ring State */
	RingState *pRingState  ;
} Scanner ;
/* Keywords */
typedef enum SCANNER_KEYWORD {
	K_IF=1 ,
	K_TO ,
	/* Logic */
	K_OR ,
	K_AND ,
	K_NOT ,
	K_FOR ,
	K_NEW ,
	K_FUNC ,
	K_FROM ,
	K_NEXT ,
	K_LOAD ,
	K_ELSE ,
	K_SEE ,
	K_WHILE ,
	K_OK ,
	K_CLASS ,
	K_BREAK ,
	K_RETURN ,
	K_BUT ,
	K_END ,
	K_GIVE ,
	K_BYE ,
	K_EXIT ,
	K_TRY ,
	K_CATCH ,
	K_DONE ,
	/* Switch */
	K_SWITCH ,
	K_ON ,
	K_OTHER ,
	K_OFF ,
	K_IN ,
	K_LOOP ,
	/* Packages */
	K_PACKAGE ,
	K_IMPORT ,
	K_PRIVATE ,
	K_STEP ,
	K_DO ,
	K_AGAIN ,
	K_CALL 
} SCANNER_KEYWORD ;
/* Functions */

Scanner * ring_scanner_new ( RingState *pRingState ) ;

Scanner * ring_scanner_delete ( Scanner *pScanner ) ;

void ring_scanner_readfile ( const char *cFileName,RingState *pRingState ) ;

void ring_scanner_readchar ( char c ,Scanner *pScanner ) ;

void ring_scanner_keywords ( Scanner *pScanner ) ;

void ring_scanner_addtoken ( Scanner *pScanner,int type ) ;

void ring_scanner_checktoken ( Scanner *pScanner ) ;

int ring_scanner_isnumber ( const char *cStr ) ;

int ring_scanner_checklasttoken ( Scanner *pScanner ) ;

int ring_scanner_isoperator ( Scanner *pScanner,const char *cStr ) ;

void ring_scanner_operators ( Scanner *pScanner ) ;

int ring_scanner_lasttokentype ( Scanner *pScanner ) ;

char * ring_scanner_lasttokenvalue ( Scanner *pScanner ) ;

void ring_scanner_floatmark ( Scanner *pScanner,int type ) ;

void ring_scanner_endofline ( Scanner *pScanner ) ;

void ring_scanner_addreturn ( RingState *pRingState ) ;

void ring_scanner_addreturn2 ( RingState *pRingState ) ;

void ring_scanner_addreturn3 ( RingState *pRingState,int aPara[3] ) ;

void ring_scanner_printtokens ( Scanner *pScanner ) ;

RING_API void ring_execute ( const char *cFileName, int nISCGI,int nRun,int nPrintIC,int nPrintICFinal,int nTokens,int nRules,int nIns,int argc,char *argv[] ) ;

const char * ring_scanner_getkeywordtext ( const char *cStr ) ;
/* MACRO */
#define RING_SCANNER_DELETELASTTOKEN ring_list_deleteitem(pScanner->Tokens,ring_list_getsize(pScanner->Tokens))
/*
**  Constants 
**  General 
*/
#define RING_SCANNER_TOKENTYPE 1
#define RING_SCANNER_TOKENVALUE 2
/* Scanner Tokens Types */
#define SCANNER_TOKEN_KEYWORD 0
#define SCANNER_TOKEN_OPERATOR 1
#define SCANNER_TOKEN_LITERAL 2
#define SCANNER_TOKEN_NUMBER 3
#define SCANNER_TOKEN_IDENTIFIER 4
#define SCANNER_TOKEN_ENDLINE 5
#define SCANNER_TOKEN_NOTOKEN 6
/* Scanner States */
#define SCANNER_STATE_GENERAL 0
#define SCANNER_STATE_LITERAL 1
#define SCANNER_STATE_COMMENT 2
#define SCANNER_STATE_MLCOMMENT 3
#endif
