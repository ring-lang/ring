/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_codegen_h
#define ring_codegen_h
/* Intermediate Code */
typedef enum IC_OPERATIONS {
	/* General */
	ICO_NEWLINE = RING_ZERO,
	ICO_FILENAME,
	ICO_NEWCLASS,
	ICO_NEWFUNC,
	ICO_DUPLICATE,
	ICO_NEWOBJ,
	ICO_PRIVATE,
	ICO_NEWLABEL,
	/* Control Structure */
	ICO_JUMP,
	ICO_JUMPZERO,
	ICO_JUMPONE,
	ICO_JUMPFOR,
	ICO_JUMPZERO2,
	ICO_JUMPONE2,
	ICO_PUSHNULLTHENJUMP,
	ICO_PUSHNTHENJUMP,
	/* Variables */
	ICO_LOADADDRESS,
	ICO_ASSIGNMENT,
	ICO_LOADSUBADDRESS,
	ICO_LOADINDEXADDRESS,
	ICO_LOADAPUSHV,
	/* Comparison operators */
	ICO_EQUAL,
	ICO_LESS,
	ICO_GREATER,
	ICO_NOTEQUAL,
	ICO_LESSEQUAL,
	ICO_GREATEREQUAL,
	/* Data */
	ICO_PUSHC,
	ICO_PUSHNL,
	ICO_PUSHN,
	ICO_PUSH2N,
	ICO_PUSHV,
	ICO_PUSHP,
	ICO_PUSHPV,
	ICO_PUSHPLOCAL,
	ICO_PUSHARG,
	/* Arithmetic */
	ICO_SUM,
	ICO_SUB,
	ICO_MUL,
	ICO_DIV,
	ICO_MOD,
	ICO_NEG,
	ICO_INC,
	ICO_INCP,
	ICO_POW,
	ICO_SUMN,
	ICO_SUBN,
	ICO_MULN,
	ICO_DIVN,
	ICO_MODN,
	ICO_POWN,
	/* Functions/Methods */
	ICO_LOADFUNC,
	ICO_CALL,
	ICO_RETURN,
	ICO_RETNULL,
	ICO_RETFROMEVAL,
	ICO_RETITEMREF,
	ICO_RETURNN,
	/* Lists */
	ICO_LISTSTART,
	ICO_LISTITEM,
	ICO_LISTITEMN,
	ICO_LISTITEMC,
	ICO_LISTEND,
	/* Logic */
	ICO_AND,
	ICO_OR,
	ICO_NOT,
	/* Stack and Jump */
	ICO_FREESTACK,
	ICO_BLOCKFLAG,
	ICO_BYE,
	ICO_EXITMARK,
	ICO_POPEXITMARK,
	ICO_EXIT,
	ICO_INCJUMP,
	ICO_INCPJUMP,
	ICO_TRY,
	ICO_DONE,
	ICO_RANGE,
	ICO_LOADMETHOD,
	ICO_SETSCOPE,
	ICO_AFTERCALLMETHOD,
	ICO_BRACESTART,
	ICO_BRACEEND,
	ICO_LOADFUNCP,
	ICO_FREELOADASCOPE,
	/* Loop */
	ICO_LOOP,
	/* Loop optimization in functions (local scope) */
	ICO_INCLPJUMP,
	/* Packages */
	ICO_PACKAGE,
	ICO_IMPORT,
	/* Property */
	ICO_SETPROPERTY,
	ICO_NOOP,
	ICO_AFTERCALLMETHOD2,
	/* For-In References */
	ICO_SETREFERENCE,
	ICO_KILLREFERENCE,
	/* Assignment */
	ICO_ASSIGNMENTPOINTER,
	ICO_BEFOREEQUAL,
	/* Increment and Decrement */
	ICO_PLUSPLUS,
	ICO_MINUSMINUS,
	/* Bitwise Operators */
	ICO_BITAND,
	ICO_BITOR,
	ICO_BITNOT,
	ICO_BITXOR,
	ICO_BITSHL,
	ICO_BITSHR,
	/* For Loop Step */
	ICO_STEPNUMBER,
	ICO_STEPFROMREG,
	ICO_POPSTEP,
	ICO_LOADAFIRST,
	ICO_INCPJUMPSTEP1,
	ICO_INCLPJUMPSTEP1,
	/* Anonymous Functions */
	ICO_ANONYMOUS,
	/* Class Init */
	ICO_CALLCLASSINIT,
	/* Custom Global Scope */
	ICO_NEWGLOBALSCOPE,
	ICO_ENDGLOBALSCOPE,
	ICO_SETGLOBALSCOPE,
	/* Temp Lists */
	ICO_FREETEMPLISTS,
	/* Better Performance */
	ICO_LEN,
	ICO_SETOPCODE,
	ICO_CHECKBRACEMETHOD,
	/* Optional Loop */
	ICO_OPTIONALLOOP
} IC_OPERATIONS;
/* Operations Text (Array) */
static const char *RING_IC_OP[] = {"NewLine",
				   "FileName",
				   "Class",
				   "Func",
				   "Dup",
				   "New",
				   "Private",
				   "NewLabel",
				   "Jump",
				   "JumpZ",
				   "Jump1",
				   "JumpFor",
				   "JumpZero2",
				   "JumpOne2",
				   "PushNullThenJump",
				   "PushNThenJump",
				   "LoadA",
				   "Assignment",
				   "LoadSA",
				   "LoadIA",
				   "LoadAPushV",
				   "==",
				   "<",
				   ">",
				   "!=",
				   "<=",
				   ">=",
				   "PushC",
				   "PushNL",
				   "PushN",
				   "Push2N",
				   "PushV",
				   "PushP",
				   "PushPV",
				   "PushPLocal",
				   "PushArg",
				   "Sum",
				   "Sub",
				   "Mul",
				   "Div",
				   "Mod",
				   "Negative",
				   "Inc",
				   "IncP",
				   "Pow",
				   "SumN",
				   "SubN",
				   "MulN",
				   "DivN",
				   "ModN",
				   "PowN",
				   "LoadFunc",
				   "Call",
				   "Return",
				   "ReturnNull",
				   "RetFromEval",
				   "RetItemRef",
				   "ReturnN",
				   "ListStart",
				   "ListItem",
				   "ListItemN",
				   "ListItemC",
				   "ListEnd",
				   "And",
				   "Or",
				   "Not",
				   "FreeStack",
				   "BlockFlag",
				   "Bye",
				   "ExitMark",
				   "PopExitMark",
				   "Exit",
				   "IncJump",
				   "IncPJump",
				   "Try",
				   "Done",
				   "Range",
				   "LoadMethod",
				   "SetScope",
				   "AfterCallMethod",
				   "BraceStart",
				   "BraceEnd",
				   "LoadFuncP",
				   "FreeLoadAScope",
				   "Loop",
				   "IncLPJump",
				   "Package",
				   "Import",
				   "SetProperty",
				   "NoOperation",
				   "AfterCallMethod2",
				   "SetReference",
				   "KillReference",
				   "AssignmentPointer",
				   "BeforeEqual",
				   "++",
				   "--",
				   "BitAnd",
				   "BitOr",
				   "BitNot",
				   "BitXOr",
				   "BitShiftL",
				   "BitShiftR",
				   "StepNumber",
				   "StepFromReg",
				   "PopStep",
				   "LoadAFirst",
				   "IncPJumpStep1",
				   "IncLPJumpStep1",
				   "Anonymous",
				   "CallClassInit",
				   "NewGlobalScope",
				   "EndGlobalScope",
				   "SetGlobalScope",
				   "FreeTempLists",
				   "Len",
				   "SetOPCode",
				   "CheckBraceMethod",
				   "OptionalLoop"};
/* Constants */
#define RING_PARSER_ICG_INSTRUCTIONSLISTTYPE List
#define RING_PARSER_ICG_OPERATIONCODE 1
#define RING_PARSER_ICG_PARA1 2
#define RING_PARSER_ICG_PARA2 3
#define RING_PARSER_ICG_PARENTCLASSPOS 4
#define RING_PARSER_ICG_LOADASETTERPOS 3
#define RING_PARSER_ICG_USEASSIGNMENT 1
#define RING_PARSER_ICG_USESETPROPERTY 2
#define RING_PARSER_ICG_NORMALPP 3
#define RING_PARSER_ICG_NORMALMM 4
#define RING_PARSER_ICG_ASSIGNPTRENABLEPOS 2
/* Macro */
#define RING_PARSER_ICG_GOTOLASTOP                                                                                     \
	pParser->pActiveGenCodeList = ring_list_getlist(pParser->pGenCode, ring_list_getsize(pParser->pGenCode))
#define RING_PARSER_ICG_NOOPERATION -1
#define ring_parser_icg_newlabel(pParser)                                                                              \
	(ring_list_getsize(pParser->pGenCode) + 1 + pParser->pRingState->nInstructionsCount)
#define ring_parser_icg_setlastoperation(pParser, nOPCode)                                                             \
	ring_list_setint_gc(pParser->pRingState, pParser->pActiveGenCodeList, RING_PARSER_ICG_OPERATIONCODE, nOPCode)
#define ring_parser_icg_instructionscount(pParser)                                                                     \
	ring_list_getsize(pParser->pGenCode) + pParser->pRingState->nInstructionsCount
#define ring_parser_icg_instructionslistsize(pParser) ring_list_getsize(pParser->pGenCode)
#define ring_parser_icg_getoperationlist(pParser, nIndex) ring_list_getlist(pParser->pGenCode, nIndex)
#define ring_parser_icg_getoperationatpos(pParser, nIndex)                                                             \
	ring_list_getint(ring_parser_icg_getoperationlist(pParser, nIndex), RING_PARSER_ICG_OPERATIONCODE)
#define ring_parser_icg_getoperandint(pParser, nPos) ring_list_getint(pParser->pActiveGenCodeList, nPos)
#define ring_parser_icg_getoperanddouble(pParser, nPos) ring_list_getdouble(pParser->pActiveGenCodeList, nPos)
#define ring_parser_icg_setoperationatpos(pParser, nIndex, nOPCode)                                                    \
	ring_list_setint(ring_parser_icg_getoperationlist(pParser, nIndex), RING_PARSER_ICG_OPERATIONCODE, nOPCode)
/* Generate Intermediate Code */

void ring_parser_icg_newoperation(Parser *pParser, IC_OPERATIONS nOPCode);

void ring_parser_icg_newoperand(Parser *pParser, const char *cStr);

void ring_parser_icg_addtooperand(Parser *pParser, const char *cStr);

void ring_parser_icg_newoperandint(Parser *pParser, int nValue);

void ring_parser_icg_newoperanddouble(Parser *pParser, double nValue);

void ring_parser_icg_newoperandpointer(Parser *pParser, void *pValue);

List *ring_parser_icg_getactiveoperation(Parser *pParser);

void ring_parser_icg_addoperand(Parser *pParser, List *pList, const char *cStr);

void ring_parser_icg_addoperandint(Parser *pParser, List *pList, int nValue);

void ring_parser_icg_addoperandpointer(Parser *pParser, List *pList, void *pValue);

void ring_parser_icg_deletelastoperation(Parser *pParser);

void ring_parser_icg_duplicate(Parser *pParser, unsigned int nStart, unsigned int nEnd);

int ring_parser_icg_newlabel2(Parser *pParser);

void ring_parser_icg_insertoperation(Parser *pParser, int nPos, IC_OPERATIONS nOPCode);

void ring_parser_icg_setopcode(Parser *pParser, List *pList, int nValue);

void ring_parser_icg_deleteoperand(Parser *pParser, int nPos);

const char *ring_parser_icg_getlaststring(Parser *pParser);

void ring_parser_icg_setoperandint(Parser *pParser, List *pList, int nPos, int nValue);

int ring_parser_icg_getlastoperation(Parser *pParser);

int ring_parser_icg_getoperationbeforelastoperation(Parser *pParser);
/* Specific Instructions */

void ring_parser_icg_loadfunction(Parser *pParser, const char *cFunctionName);

void ring_parser_icg_loadaddress(Parser *pParser, const char *cVariableName);

void ring_parser_icg_loadaddresstoloadfunction(Parser *pParser);

void ring_parser_icg_freestack(Parser *pParser);

void ring_parser_icg_newline(Parser *pParser, int nLine);

char *ring_parser_icg_parentclassname(Parser *pParser);

void ring_parser_icg_deleteparentclassname(Parser *pParser);

char *ring_parser_icg_newpackagename(Parser *pParser, List *pPos);

void ring_parser_icg_pushn(Parser *pParser, double nValue);

void ring_parser_icg_beforeequal(Parser *pParser, int nBeforeEqual);

void ring_parser_icg_retnull(Parser *pParser);

void ring_parser_icg_listitem(Parser *pParser);

void ring_parser_icg_gensetglobalscope(Parser *pParser);

void ring_parser_icg_math(Parser *pParser, IC_OPERATIONS nOPCode, IC_OPERATIONS nOPCodeV);

void ring_parser_icg_returnn(Parser *pParser);
/* General Blocks of ByteCode */

void ring_parser_icg_gencallbracemethod(Parser *pParser, const char *cMethod, int lDuplicateStackValue);

void ring_parser_icg_gencall(Parser *pParser, int nCallMethod);

void ring_parser_icg_genfreetemplists(Parser *pParser);

void ring_parser_icg_genppmm(Parser *pParser, int nMode, int nValue);
/* Show the Intermediate Code */

void ring_parser_icg_showoutput(RingState *pRingState);
#endif
