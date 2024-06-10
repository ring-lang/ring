C_FILENAME 	= "test_tokens.ring"
C_WIDTH		= 12

# write the file
	write(C_FILENAME,'
			see "Hello, World!"
			? 3*2+3
			Name = "Ring"
			? Name
')

# Token Type
	C_KEYWORD 	= 0
	C_OPERATOR 	= 1
	C_LITERAL 	= 2
	C_NUMBER 	= 3
	C_IDENTIFIER 	= 4
	C_ENDLINE 	= 5

# Keywords List
aKEYWORDS = ["IF","TO","OR","AND","NOT","FOR","FOREACH","NEW","FUNC", 
"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","RETURN","BUT", 
"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF", 
"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL","ELSEIF", 
"PUT","GET","CASE","DEF","ENDFUNC","ENDCLASS","ENDPACKAGE", 
"CHANGERINGKEYWORD","CHANGERINGOPERATOR","LOADSYNTAX"]

pState = ring_state_new()
aList = ring_state_filetokens(pState,C_FILENAME)
PrintTokens(aList)
ring_state_delete(pState)

func PrintTokens aList
	for aToken in aList
		switch aToken[1]
		on C_KEYWORD 
			? Width("Keyword",C_WIDTH) + ": "  + aKeywords[0+aToken[2]]
		on C_OPERATOR 
			? Width("Operator",C_WIDTH)  + ": " + aToken[2]
		on C_LITERAL 
			? Width("Literal",C_WIDTH)  + ": " + aToken[2]
		on C_NUMBER 
			? Width("Number",C_WIDTH)  + ": " + aToken[2]
		on C_IDENTIFIER 
			? Width("Identifier",C_WIDTH)  + ": " + aToken[2]
		on C_ENDLINE 
			? "EndLine"
		off
	next

func Width cText,nWidth
	return cText+copy(" ",nWidth-len(cText))
