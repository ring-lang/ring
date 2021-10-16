/*
**	Date   : 2020.02.15
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Tokens Table 
	C_TOKENTYPE 	= 1
	C_TOKENVALUE	= 2
	C_TOKENINDEX	= 3

# Token Type
	C_KEYWORD 	= 0
	C_OPERATOR 	= 1
	C_LITERAL 	= 2
	C_NUMBER 	= 3
	C_IDENTIFIER 	= 4
	C_ENDLINE 	= 5

# Keywords List
	aKEYWORDS = [
		"IF","TO","OR","AND","NOT","FOR","NEW","FUNC", 
		"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK",
		"CLASS","RETURN","BUT", 
		"END","GIVE","BYE","EXIT","TRY","CATCH","DONE",
		"SWITCH","ON","OTHER","OFF", 
		"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO",
		"AGAIN","CALL","ELSEIF", 
		"PUT","GET","CASE","DEF","ENDFUNC","ENDCLASS","ENDPACKAGE", 
		"CHANGERINGKEYWORD","CHANGERINGOPERATOR","LOADSYNTAX"
	]

# Keywords Constants 	
	K_IF 			= 1
	K_TO 			= 2
	K_OR 			= 3
	K_AND 			= 4
	K_NOT 			= 5
	K_FOR 			= 6
	K_NEW 			= 7
	K_FUNC 			= 8
	K_FROM 			= 9
	K_NEXT 			= 10
	K_LOAD 			= 11
	K_ELSE 			= 12
	K_SEE 			= 13
	K_WHILE 		= 14
	K_OK 			= 15
	K_CLASS 		= 16
	K_RETURN 		= 17
	K_BUT 			= 18
	K_END 			= 19
	K_GIVE 			= 20
	K_BYE 			= 21
	K_EXIT 			= 22
	K_TRY 			= 23
	K_CATCH 		= 24
	K_DONE 			= 25
	K_SWITCH 		= 26
	K_ON 			= 27
	K_OTHER			= 28
	K_OFF 			= 29
	K_IN 			= 30
	K_LOOP 			= 31
	K_PACKAGE 		= 32
	K_IMPORT 		= 33
	K_PRIVATE 		= 34
	K_STEP 			= 35
	K_DO 			= 36
	K_AGAIN 		= 37
	K_CALL 			= 38
	K_ELSEIF 		= 39
	K_PUT 			= 40
	K_GET 			= 41
	K_CASE 			= 42
	K_DEF 			= 43
	K_ENDFUNC 		= 44
	K_ENDCLASS 		= 45
	K_ENDPACKAGE 		= 46
	K_CHANGERINGKEYWORD 	= 47
	K_CHANGERINGOPERATOR 	= 48
	K_LOADSYNTAX 		= 49

# Operators 

	OP_PLUS 	= 1 
	OP_MINUS 	= 2
	OP_MUL 		= 3
	OP_DIV 		= 4
	OP_REM 		= 5
	OP_DOT 		= 6
	OP_FOPEN 	= 7
	OP_FCLOSE 	= 8
	OP_EQUAL 	= 9
	OP_COMMA 	= 10
	OP_NOT 		= 11
	OP_GREATER 	= 12
	OP_LESS 	= 13
	OP_LOPEN 	= 14
	OP_LCLOSE 	= 15
	OP_RANGE 	= 16
	OP_BRACEOPEN 	= 17
	OP_BRACECLOSE 	= 18
	OP_BITAND 	= 19
	OP_BITOR 	= 20
	OP_BITNOT 	= 21
	OP_XOR 		= 22

# Error Messages (Parser)	
	ERROR_PARALIST = "Error (C1) : Error in parameters list, expected identifier"
	ERROR_CLASSNAME = "Error (C2) : Error in class name"
	ERROR_OK = "Error (C3) : Unclosed control structure, 'ok' is missing"
	ERROR_END = "Error (C4) : Unclosed control structure, 'end' is missing"
	ERROR_NEXT = "Error (C5) : Unclosed control structure, next is missing"
	ERROR_FUNCNAME = "Error (C6) : Error in function name"
	ERROR_LISTITEM = "Error (C7) : Error in list items"
	ERROR_MISSPARENTHESES = "Error (C8) : Parentheses ')' is missing "
	ERROR_MISSBRACKETS = "Error (C9) : Brackets ']' is missing "
	ERROR_PRENTCLASSNAME = "Error (C10) : Error in parent class name"
	ERROR_EXPROPERATOR = "Error (C11) : Error in expression operator"
	ERROR_NOCLASSDEFINED = "Error (C12) :No class definition"
	ERROR_VARNAME = "Error (C13) : Error in variable name"
	ERROR_NOCATCH = "Error (C14) : Try/Catch miss the Catch keyword!"
	ERROR_NODONE = "Error (C15) : Try/Catch miss the Done keyword!"
	ERROR_SWITCHEXPR = "Error (C16) : Error in Switch statement expression!"
	ERROR_SWITCHOFF = "Error (C17) : Switch statement without OFF"
	ERROR_BRACESNOTCLOSED = "Error (C18) : Missing closing brace for the block opened!"
	ERROR_NUMERICOVERFLOW = "Error (C19) : Numeric Overflow!"
	ERROR_PACKAGENAME = "Error (C20) : Error in package name"
	ERROR_AGAIN = "Error (C21) : Unclosed control structure, 'again' is missing"
	ERROR_FUNCREDEFINE = "Error (C22) : Function redefinition, function is already defined!"
	ERROR_USINGBRACTAFTERNUM = "Error (C23) : Using '(' after number!"
	ERROR_PARENTLIKESUBCLASS = "Error (C24) : The parent class name is identical to the subclass name"
	ERROR_ACCESSSELFREF = "Error (C25) : Trying to access the self reference after the object name"
	ERROR_CLASSREDEFINE = "Error (C26) : Class redefinition, class is already defined!"
	RING_PARSER_WARNING_EXITOUTSIDELOOP = "Warning (W6) : Using the EXIT command outside loop!"
	RING_PARSER_WARNING_LOOPOUTSIDELOOP = "Warning (W7) : Using the LOOP command outside loop"
