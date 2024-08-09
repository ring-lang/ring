/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_scanner_h
	#define ring_scanner_h
	typedef struct Scanner {
		RingState *pRingState  ;
		List *pKeywords  ;
		List *pOperators  ;
		List *pTokens  ;
		String *pActiveToken  ;
		unsigned int nTokenIndex  ;
		unsigned int nLiteralLine  ;
		unsigned int nLinesCount  ;
		char cState  ;
		/* Float Identification (0 = Start 1 = Number  2 = Number Dot  3 = Number Dot Number ) */
		char nFloatMark  ;
		/* Literal Type "  or ' */
		char cLiteral  ;
		/* Multiline comment end ( 0 = start  1 = * ) */
		char nMLComment  ;
		/* Support comments that starts with hash */
		char lHashComments  ;
		/* Multi-Character Operators */
		char lMultiCharOperators  ;
	} Scanner ;
	typedef enum SCANNER_KEYWORD {
		K_IF=1 ,
		K_TO ,
		/* Logic */
		K_OR ,
		K_AND ,
		K_NOT ,
		K_FOR ,
		K_FOREACH ,
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
		K_CALL ,
		K_ELSEIF ,
		K_PUT ,
		K_GET ,
		K_CASE ,
		K_DEF ,
		K_ENDFUNC ,
		K_ENDCLASS ,
		K_ENDPACKAGE ,
		K_ENDIF ,
		K_ENDFOR ,
		K_ENDWHILE ,
		K_ENDSWITCH ,
		K_ENDTRY ,
		K_FUNCTION ,
		K_ENDFUNCTION ,
		K_BREAK ,
		K_CONTINUE ,
		K_CHANGERINGKEYWORD ,
		K_CHANGERINGIOPERATOR ,
		K_LOADSYNTAX ,
		K_ENABLEHASHCOMMENTS ,
		K_DISABLEHASHCOMMENTS 
	} SCANNER_KEYWORD ;
	/*
	**  The keywords starting from ChangeRingKeyword are sensitive to the order and keywords count 
	**  if you will add new keywords revise constants and ring_scanner_checktoken() 
	*/
	static const char * RING_KEYWORDS[] = {"IF","TO","OR","AND","NOT","FOR","FOREACH","NEW","FUNC",
	"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","RETURN","BUT",
	"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF",
	"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL","ELSEIF",
	"PUT","GET","CASE","DEF","ENDFUNC","ENDCLASS","ENDPACKAGE",
	"ENDIF","ENDFOR","ENDWHILE","ENDSWITCH","ENDTRY",
	"FUNCTION","ENDFUNCTION","BREAK","CONTINUE",
	"CHANGERINGKEYWORD","CHANGERINGOPERATOR","LOADSYNTAX",
	"ENABLEHASHCOMMENTS","DISABLEHASHCOMMENTS"} ;
	#define RING_SCANNER_KEYWORDSCOUNT 61
	typedef enum SCANNER_OPERATOR {
		OP_PLUS = 1 ,
		OP_MINUS ,
		OP_MUL ,
		OP_DIV ,
		OP_MOD ,
		OP_DOT ,
		OP_FOPEN ,
		OP_FCLOSE ,
		OP_EQUAL ,
		OP_COMMA ,
		OP_NOT ,
		OP_GREATER ,
		OP_LESS ,
		OP_LOPEN ,
		OP_LCLOSE ,
		OP_RANGE ,
		OP_BRACEOPEN ,
		OP_BRACECLOSE ,
		OP_BITAND ,
		OP_BITOR ,
		OP_BITNOT ,
		OP_XOR ,
		OP_QUES ,
		OP_INC ,
		OP_DEC ,
		OP_LOGAND ,
		OP_LOGOR ,
		OP_POW ,
		OP_SHL ,
		OP_SHR ,
		OP_PLUSEQUAL ,
		OP_MINUSEQUAL ,
		OP_MULEQUAL ,
		OP_DIVEQUAL ,
		OP_MODEQUAL ,
		OP_BITANDEQUAL ,
		OP_BITOREQUAL ,
		OP_BITXOREQUAL ,
		OP_SHLEQUAL ,
		OP_SHREQUAL ,
		OP_POWEQUAL 
	} SCANNER_OPERATOR ;
	/* Operators Array */
	static const char * RING_OPERATORS[] = {"+","-","*","/","%",".","(",")","=",
	",","!",">","<","[","]",":","{","}","&","|","~","^","?"} ;
	#define RING_SCANNER_OPERATORSCOUNT 23
	#define RING_SCANNER_TOKENTYPE 1
	#define RING_SCANNER_TOKENVALUE 2
	#define RING_SCANNER_TOKENINDEX 3
	#define SCANNER_TOKEN_KEYWORD 0
	#define SCANNER_TOKEN_OPERATOR 1
	#define SCANNER_TOKEN_LITERAL 2
	#define SCANNER_TOKEN_NUMBER 3
	#define SCANNER_TOKEN_IDENTIFIER 4
	#define SCANNER_TOKEN_ENDLINE 5
	#define SCANNER_TOKEN_COMMENT 6
	#define SCANNER_TOKEN_NOTOKEN 7
	#define SCANNER_STATE_GENERAL 0
	#define SCANNER_STATE_LITERAL 1
	#define SCANNER_STATE_COMMENT 2
	#define SCANNER_STATE_MLCOMMENT 3
	#define SCANNER_STATE_CHANGEKEYWORD 4
	#define SCANNER_STATE_CHANGEOPERATOR 5
	#define SCANNER_STATE_LOADSYNTAX 6
	#define RING_SCANNER_CHANGERINGKEYWORD 57
	#define RING_SCANNER_CHANGERINGOPERATOR 58
	#define RING_SCANNER_LOADSYNTAX 59
	#define RING_SCANNER_ENABLEHASHCOMMENTS 60
	#define RING_SCANNER_DISABLEHASHCOMMENTS 61
	#define SCANNER_FLOATMARK_START 0
	#define SCANNER_FLOATMARK_NUMBER 1
	#define SCANNER_FLOATMARK_NUMBERDOT 2
	#define RING_SCANNER_DELETELASTTOKEN ring_list_deleteitem_gc(pScanner->pRingState,pScanner->pTokens,ring_list_getsize(pScanner->pTokens))

	Scanner * ring_scanner_new ( RingState *pRingState ) ;

	Scanner * ring_scanner_delete ( Scanner *pScanner ) ;

	void ring_scanner_readchar ( Scanner *pScanner,char c ) ;

	void ring_scanner_keywords ( Scanner *pScanner ) ;

	void ring_scanner_addtoken ( Scanner *pScanner,int nType ) ;

	void ring_scanner_checktoken ( Scanner *pScanner ) ;

	int ring_scanner_isnumber ( char *cStr ) ;

	int ring_scanner_checklasttoken ( Scanner *pScanner ) ;

	int ring_scanner_isoperator ( Scanner *pScanner,const char *cStr ) ;

	void ring_scanner_operators ( Scanner *pScanner ) ;

	int ring_scanner_lasttokentype ( Scanner *pScanner ) ;

	const char * ring_scanner_lasttokenvalue ( Scanner *pScanner ) ;

	void ring_scanner_floatmark ( Scanner *pScanner,int nType ) ;

	void ring_scanner_endofline ( Scanner *pScanner ) ;

	void ring_scanner_addreturn ( RingState *pRingState ) ;

	void ring_scanner_addreturn2 ( RingState *pRingState ) ;

	void ring_scanner_addreturn3 ( RingState *pRingState,int aPara[2] ) ;

	void ring_scanner_printtokens ( Scanner *pScanner ) ;

	const char * ring_scanner_getkeywordtext ( const char *cStr ) ;

	void ring_scanner_changekeyword ( Scanner *pScanner ) ;

	void ring_scanner_changeoperator ( Scanner *pScanner ) ;

	void ring_scanner_loadsyntax ( Scanner *pScanner ) ;

	void ring_scanner_readtwoparameters ( Scanner *pScanner,const char *cStr ) ;

	const char * ring_scanner_processtoken ( Scanner *pScanner,int nType ) ;

	void ring_scanner_setandgenendofline ( Scanner *pScanner,int nLine ) ;
#endif
