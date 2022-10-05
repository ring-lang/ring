/*
**	TokensLib Library
**	Mahmoud Fayed <msfclipper@yahoo.com>
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
		"ENDIF","ENDFOR","ENDWHILE","ENDSWITCH","ENDTRY",
		"FUNCTION","ENDFUNCTION","BREAK","CONTINUE", 
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
	K_ENDIF			= 47
	K_ENDFOR		= 48
	K_ENDWHILE		= 49
	K_ENDSWITCH		= 50
	K_ENDTRY		= 51
	K_FUNCTION		= 52
	K_ENDFUNCTION		= 53
	K_BREAK			= 54
	K_CONTINUE		= 55
	K_CHANGERINGKEYWORD 	= 56
	K_CHANGERINGOPERATOR 	= 57
	K_LOADSYNTAX 		= 58

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