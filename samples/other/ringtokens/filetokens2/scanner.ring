/*
**	Date   : 2020.02.15
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

class Scanner 

	cFileName
	aTokens = []

	func setFileName cFile 
		cFileName = cFile

	func Start 
		pState = ring_state_new()
		aTokens = ring_state_filetokens(pState,cFileName)
		ring_state_delete(pState)
	
	func GetTokens
		return aTokens

	func PrintTokens 
		for aToken in aTokens {
			switch aToken[C_TOKENTYPE] {
			case C_KEYWORD 
				? Width("Keyword",C_WIDTH) + ": "  +
				 aKeywords[0+aToken[C_TOKENVALUE]]
			case C_OPERATOR 
				? Width("Operator",C_WIDTH)  + ": " +
				 aToken[C_TOKENVALUE] + " (" +
				 aToken[C_TOKENINDEX] + ")"
			case C_LITERAL 
				? Width("Literal",C_WIDTH)  + ": " +
				 aToken[C_TOKENVALUE]
			case C_NUMBER 
				? Width("Number",C_WIDTH)  + ": " +
				 aToken[C_TOKENVALUE]
			case C_IDENTIFIER 
				? Width("Identifier",C_WIDTH)  + ": " +
				 aToken[C_TOKENVALUE]
			case C_ENDLINE 
				? "EndLine"	
			}
		}
	
	
	
