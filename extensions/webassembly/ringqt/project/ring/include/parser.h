/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_parser_h
#define ring_parser_h
/* Data */
typedef struct Parser {
	RingState *pRingState;
	/* Tokens and Generated Code */
	List *pTokens;
	List *pGenCode;
	List *pActiveGenCodeList;
	/* Lists of Lists, Functions in Program or in Class */
	List *pFunctionsMap;
	/* Lists of Lists, Classes in Program or in Class */
	List *pClassesMap;
	/* List of Lists, Packages in the program */
	List *pPackagesMap;
	/* Required by (For In Loops) to kill the reference when we exit from many loops */
	List *pForInVars;
	/* Token Text */
	const char *cTokenText;
	/* Mark to class label to be used by Private */
	unsigned int nClassMark;
	/* Counter to know if we are inside { } or not */
	unsigned int nBracesCounter;
	/* Active Token */
	unsigned int nActiveToken;
	unsigned int nTokensCount;
	unsigned int nTokenIndex;
	/* Line Number */
	unsigned int nLineNumber;
	unsigned int nErrorLine;
	unsigned int nErrorsCount;
	/* Counter  - We started using braces {} in control structure - we have { */
	unsigned int nControlStructureBrace;
	/* Required for For-Step, insert instructions */
	unsigned int nInsertCounter;
	/*
	**  required in loops (for|while) for loop and exit commands
	**  Counter to know if we are inside a loop or not
	*/
	unsigned int nLoopCounter;
	/* To Know if the commands (Loop or Exit) are used */
	unsigned int lLoopOrExitCommand : 1;
	/* Enable|Disable checking Loop & Exit commands before storing Loop & Exit marks */
	unsigned int lCheckLoopAndExit : 1;
	/* Flag to tell { } that we are inside control structure (if/for/while/...) expression */
	unsigned int lControlStructureExpr : 1;
	/* Variable to select between = and == while using = only in the code */
	unsigned int lAssignmentFlag : 1;
	/* Variable to determine the start of the class definition */
	unsigned int lClassStart : 1;
	/* Private Flag */
	unsigned int lPrivateFlag : 1;
	/* required for using { } after using new object to avoid assignment */
	unsigned int lNewObject : 1;
	/* Object Init() Uses mixer for one purpose only( function call)  - don't continue to get braces { } */
	unsigned int lFuncCallOnly : 1;
	/* Using Self or This with LoadAddress */
	unsigned int lThisOrSelfLoadA : 1;
	unsigned int lThisLoadA : 1;
	/* Insert Flag */
	unsigned int lInsertFlag : 1;
	/* Token Type */
	unsigned int nTokenType : 3;
} Parser;
/* Error Messages */
#define RING_PARSER_ERROR_PARALIST "Error (C1) : Error in parameters list, expected identifier"
#define RING_PARSER_ERROR_CLASSNAME "Error (C2) : Error in class name"
#define RING_PARSER_ERROR_OK "Error (C3) : Unclosed control structure, 'ok' is missing"
#define RING_PARSER_ERROR_END "Error (C4) : Unclosed control structure, 'end' is missing"
#define RING_PARSER_ERROR_NEXT "Error (C5) : Unclosed control structure, next is missing"
#define RING_PARSER_ERROR_FUNCNAME "Error (C6) : Error in function name"
#define RING_PARSER_ERROR_LISTITEM "Error (C7) : Error in list items"
#define RING_PARSER_ERROR_MISSPARENTHESES "Error (C8) : Parentheses ')' is missing"
#define RING_PARSER_ERROR_MISSBRACKETS "Error (C9) : Brackets ']' is missing "
#define RING_PARSER_ERROR_PRENTCLASSNAME "Error (C10) : Error in parent class name"
#define RING_PARSER_ERROR_EXPROPERATOR "Error (C11) : Error in expression operator"
#define RING_PARSER_ERROR_NOCLASSDEFINED "Error (C12) :No class definition"
#define RING_PARSER_ERROR_VARNAME "Error (C13) : Error in variable name"
#define RING_PARSER_ERROR_NOCATCH "Error (C14) : Try/Catch miss the Catch keyword!"
#define RING_PARSER_ERROR_NODONE "Error (C15) : Try/Catch miss the Done keyword!"
#define RING_PARSER_ERROR_SWITCHEXPR "Error (C16) : Error in Switch statement expression!"
#define RING_PARSER_ERROR_SWITCHOFF "Error (C17) : Switch statement without OFF"
#define RING_PARSER_ERROR_BRACESNOTCLOSED "Error (C18) : Missing closing brace for the block opened!"
#define RING_PARSER_ERROR_NUMERICOVERFLOW "Error (C19) : Numeric Overflow!"
#define RING_PARSER_ERROR_PACKAGENAME "Error (C20) : Error in package name"
#define RING_PARSER_ERROR_AGAIN "Error (C21) : Unclosed control structure, 'again' is missing"
#define RING_PARSER_ERROR_FUNCREDEFINE "Error (C22) : Function redefinition, function is already defined!"
#define RING_PARSER_ERROR_USINGBRACTAFTERNUM "Error (C23) : Using '(' after number!"
#define RING_PARSER_ERROR_PARENTLIKESUBCLASS "Error (C24) : The parent class name is identical to the subclass name"
#define RING_PARSER_ERROR_ACCESSSELFREF "Error (C25) : Trying to access the self reference after the object name"
#define RING_PARSER_ERROR_CLASSREDEFINE "Error (C26) : Class redefinition, class is already defined!"
#define RING_PARSER_ERROR_SYNTAXERROR "Error (C27) : Syntax Error!"
#define RING_PARSER_ERROR_EXPRESSIONISEXPECTED "Error (C28) : Expression is expected!"
#define RING_PARSER_ERROR_BRACEISMISSINGTOSTARTANONFUNC "Error (C29) : Braces are missing to define anonymous function!"
#define RING_PARSER_ERROR_ARGREDEFINE "Error (C30) : Argument redefinition, argument is already defined!"
#define RING_PARSER_ERROR_EXPECTPARENTHESES "Error (C31) : Parentheses '(' is expected"
/* Constants */
#define RING_PARSER_NUMBERLENGTH 97
/* Packages List */
#define RING_PACKAGES_PACKAGENAME 1
#define RING_PACKAGES_CLASSESLIST 2
/* Classes List */
#define RING_CLASSES_CLASSNAME 1
/* Functions List */
#define RING_FUNCTIONS_FUNCNAME 1
/* Parsing Status */
#define RING_PARSER_OK 1
#define RING_PARSER_FAIL 0
/* Rules */
#define RING_RULE_LOAD "Rule : Statement  --> 'Load' Literal"
#define RING_RULE_IMPORT "Rule : Statement  --> 'Import' Identifier{'.'identifier}"
#define RING_RULE_PACKAGE "Rule : Statement  --> 'Package' Identifier{'.'identifier}"
#define RING_RULE_CLASS "Rule : Statement  --> 'Class' Identifier"
#define RING_RULE_CLASSFROM "Rule : Statement  --> 'Class' Identifier 'From' [PackageName'.']Identifier"
#define RING_RULE_PRIVATE "Rule : Statement  --> 'Private'"
#define RING_RULE_FUNCANDPARA "Rule : Statement  --> 'Func' Identifier [ParaList]"
#define RING_RULE_RETURN "Rule : Statement  --> 'Return'"
#define RING_RULE_SEEEXPR "Rule : Statement  --> 'See' Expr"
#define RING_RULE_QEXPR "Rule : Statement  --> '?' Expr"
#define RING_RULE_GIVE "Rule : Statement  --> 'Give' Identifier|ListItem|Object.Attribute"
#define RING_RULE_FORLOOP "Rule : Statement  --> 'For' Identifier '=' Expr to Expr ['step' Expr]"
#define RING_RULE_NEXT "Rule : Next --> 'Next'"
#define RING_RULE_FORINLOOP "Rule : Statement  --> 'For' Identifier 'in' Expr  ['step' Expr]"
#define RING_RULE_IFSTATEMENT "Rule : Statement  --> 'If' Expr {Statement} { But } [Else] Ok"
#define RING_RULE_BUT "Rule : But  --> 'But' Expr {Statement}"
#define RING_RULE_ELSE "Rule : Else  --> 'Else' {Statement}"
#define RING_RULE_OK "Rule : Ok  --> 'OK'"
#define RING_RULE_WHILELOOP "Rule : Statement  --> 'While' Expr {Statement} End"
#define RING_RULE_END "Rule : End --> 'End'"
#define RING_RULE_DOAGAINLOOP "Rule : Statement  --> 'Do' {Statement} Again"
#define RING_RULE_AGAINEXPR "Rule : Again  --> 'Again' Expr"
#define RING_RULE_TRYCATCHDONE "Rule : Statement  --> 'Try' {Statement} Catch Done"
#define RING_RULE_CATCH "Rule : Catch --> 'Catch' {Statement}"
#define RING_RULE_DONE "Rule : Done --> 'Done'"
#define RING_RULE_BYE "Rule : Statement  --> 'Bye'"
#define RING_RULE_EXIT "Rule : Statement  --> 'Exit'"
#define RING_RULE_LOOP "Rule : Statement  --> 'Loop'"
#define RING_RULE_SWITCH "Rule : Statement  --> 'Switch' Expr {ON} [Other] OFF"
#define RING_RULE_ONEXPR "Rule : ON --> 'on' Expr {Statement}"
#define RING_RULE_OTHER "Rule : Other --> 'Other' {Statement}"
#define RING_RULE_OFF "Rule : OFF --> 'Off'"
#define RING_RULE_EXPR "Rule : Statement  --> Expr"
#define RING_RULE_PARALISTEPSILON "Rule : ParaList --> Epsilon"
#define RING_RULE_PARALISTIDENTIFIER "Rule : ParaList --> Identifier {',' Identifier}"
#define RING_RULE_LIST "Rule : List --> '[' Expr { ',' Expr } ']'"
#define RING_RULE_EXPRISLOGICAND "Rule : Expr --> LogicAND"
#define RING_RULE_EXPRISLOGICNOT "Rule : Expr --> LogicNot"
#define RING_RULE_EXPRANDEXPR "Rule : Expr --> Expr 'And' Expr"
#define RING_RULE_EXPROREXPR "Rule : Expr --> Expr 'Or' Expr"
#define RING_RULE_LOGICNOTISNOT "Rule : LogicNot -> 'not' EqualOrNot"
#define RING_RULE_LOGICNOTISEQUALORNOT "Rule : LogicNot -> EqualOrNot"
#define RING_RULE_EQUALORNOTISCOMPARE "Rule : EqualOrNot --> Compare"
#define RING_RULE_NOTEQUAL "Rule : EqualOrNot --> EqualOrNot '!=' EqualOrNot"
#define RING_RULE_ISEQUAL "Rule : EqualOrNot --> EqualOrNot '=' EqualOrNot"
#define RING_RULE_COMPAREISBITORXOR "Rule : Compare --> BitOrXOR"
#define RING_RULE_LESSTHAN "Rule : Compare --> Compare '<' Compare"
#define RING_RULE_LESSTHANOREQUAL "Rule : Compare --> Compare '<=' Compare"
#define RING_RULE_GREATERTHAN "Rule : Compare --> Compare '>' Compare"
#define RING_RULE_GREATERTHANOREQUAL "Rule : Compare --> Compare '>=' Compare"
#define RING_RULE_BITORXORISBITAND "Rule : BitOrXOR -->  BitAnd"
#define RING_RULE_BITOR "Rule : BitOrXOR --> BitOrXOR '|' BitOrXOR"
#define RING_RULE_XOR "Rule : BitOrXOR --> BitOrXOR '^' BitOrXOR"
#define RING_RULE_BITANDISBITSHIFT "Rule : BitAnd --> BitShift"
#define RING_RULE_BITAND "Rule : BitAnd --> BitAnd '&' BitAnd"
#define RING_RULE_BITSHIFTISARITHMETIC "Rule : BitShift --> Arithmetic"
#define RING_RULE_SHIFTLEFT "Rule : BitShift --> BitShift '<<' BitShift"
#define RING_RULE_SHIFTRIGHT "Rule : BitShift --> BitShift '>>' BitShift"
#define RING_RULE_ARITHMETICISTERM "Rule : Arithmetic --> Term"
#define RING_RULE_PLUS "Rule : Arithmetic --> Arithmetic + Arithmetic"
#define RING_RULE_MINUS "Rule : Arithmetic --> Arithmetic - Arithmetic"
#define RING_RULE_TERMISRANGE "Rule : Term --> Range"
#define RING_RULE_MUL "Rule : Term --> Term * Term"
#define RING_RULE_MOD "Rule : Term --> Term % Term"
#define RING_RULE_POW "Rule : Term --> Term ** Term"
#define RING_RULE_DIV "Rule : Term --> Term / Term"
#define RING_RULE_RANGEISFACTOR "Rule : Range --> Factor"
#define RING_RULE_FACTORISIDENTIFIER "Rule : Factor --> Identifier [ {Mixer} | Assignment | PlusPlus | MinusMinus]"
#define RING_RULE_RANGE "Rule : Range --> Range : Range"
#define RING_RULE_ASSIGNMENT "Rule : Assignment -> '=' Expr"
#define RING_RULE_FACTORISNUMBER "Rule : Factor --> Number"
#define RING_RULE_FACTORISLITERAL "Rule : Factor --> Literal"
#define RING_RULE_HASHLIST "Rule : Literal --> ':' Identifier ['=' Expr]"
#define RING_RULE_NEGATIVE "Rule : Factor --> '-' Factor"
#define RING_RULE_BITNOT "Rule : Factor --> '~' Factor"
#define RING_RULE_FACTORISEMPTYGROUP "Rule : Factor --> '()'"
#define RING_RULE_FACTORISGROUP "Rule : Factor --> '(' Expr ')'"
#define RING_RULE_FACTORISLIST "Rule : Factor --> List"
#define RING_RULE_NEWOBJECT "Rule : Factor --> New [from] Identifier {'.' Identifier }"
#define RING_RULE_ANONFUNC "Rule : AnonymousFunction --> Func ParaList '{' Statement '}'"
#define RING_RULE_MIXERISLIST "Rule : Mixer -> '[' Expr ']'"
#define RING_RULE_MIXERISGROUP "Rule : Mixer -> '(' [Expr { ',' Expr} ] ')'"
#define RING_RULE_MIXERISBRACES "Rule : Mixer --> '{' {Statement} BraceEnd"
#define RING_RULE_BRACEEND "Rule : BraceEnd --> '}' "
#define RING_RULE_PLUSPLUS "Rule : PlusPlus --> '++'"
#define RING_RULE_MINUSMINUS "Rule : MinusMinus --> '--'"
#define RING_RULE_MIXERISDOT "Rule : Mixer -> '.' Identifier"
/* MACRO */
#define RING_PARSER_IGNORENEWLINE                                                                                      \
	while (ring_parser_epsilon(pParser))                                                                           \
		;
#define RING_PARSER_PASSNEWLINE                                                                                        \
	while (ring_parser_passepsilon(pParser))                                                                       \
		;
#define RING_PARSER_CURRENTTOKEN pParser->nActiveToken
#define RING_PARSER_OPERATIONID ring_list_getsize(pParser->pGenCode) + pParser->pRingState->nInstructionsCount
#define RING_PARSER_ACCEPTSTATEMENTS                                                                                   \
	while (ring_parser_stmt(pParser))                                                                              \
		if (pParser->nActiveToken == pParser->nTokensCount)                                                    \
			break;
/* Functions */

int ring_parser_start(RingState *pRingState, List *pTokens);

Parser *ring_parser_new(RingState *pRingState, List *pTokens);

Parser *ring_parser_delete(Parser *pParser);
/* Check Token */

void ring_parser_loadtoken(Parser *pParser);

int ring_parser_nexttoken(Parser *pParser);

int ring_parser_iskeyword(Parser *pParser, SCANNER_KEYWORD nKeyword);

int ring_parser_isoperator(Parser *pParser, const char *cStr);

int ring_parser_isliteral(Parser *pParser);

int ring_parser_isnumber(Parser *pParser);

int ring_parser_isidentifier(Parser *pParser);

int ring_parser_isendline(Parser *pParser);

int ring_parser_settoken(Parser *pParser, unsigned int nToken);

int ring_parser_isanykeyword(Parser *pParser);

int ring_parser_isoperator2(Parser *pParser, SCANNER_OPERATOR nType);
/* Display Errors */

void ring_parser_error(Parser *pParser, const char *cStr);
/* Grammar */

int ring_parser_class(Parser *pParser);

int ring_parser_stmt(Parser *pParser);

int ring_parser_step(Parser *pParser, unsigned int *nMark1);

int ring_parser_paralist(Parser *pParser);

int ring_parser_expr(Parser *pParser);

int ring_parser_logicand(Parser *pParser);

int ring_parser_logicnot(Parser *pParser);

int ring_parser_equalornot(Parser *pParser);

int ring_parser_compare(Parser *pParser);

int ring_parser_bitorxor(Parser *pParser);

int ring_parser_bitand(Parser *pParser);

int ring_parser_bitshift(Parser *pParser);

int ring_parser_arithmetic(Parser *pParser);

int ring_parser_term(Parser *pParser);

int ring_parser_range(Parser *pParser);

int ring_parser_factor(Parser *pParser, int *nFlag);

int ring_parser_mixer(Parser *pParser);

int ring_parser_list(Parser *pParser);

int ring_parser_epsilon(Parser *pParser);

int ring_parser_passepsilon(Parser *pParser);

int ring_parser_namedotname(Parser *pParser);

int ring_parser_ppmm(Parser *pParser);

int ring_parser_csexpr(Parser *pParser);

int ring_parser_csbraceend(Parser *pParser);

int ring_parser_objattributes(Parser *pParser);

int ring_parser_bracesandend(Parser *pParser, int lClass, SCANNER_KEYWORD nKeyword);

int ring_parser_ringvmsee(Parser *pParser);
#endif
