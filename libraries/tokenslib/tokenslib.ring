/*
**	TokensLib Library
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "globals.ring"

class RingTokens

	cFileName
	aTokens = []

	func fromFile cFile 
		cFileName = cFile
		pState = ring_state_new()
		aTokens = ring_state_filetokens(pState,cFileName)
		ring_state_delete(pState)

	func fromString cStr
		pState = ring_state_new()
		aTokens = ring_state_stringtokens(pState,cStr)
		ring_state_delete(pState)
	
	func GetTokens
		return aTokens

	func PrintTokens
		printTokensList(aTokens)

	func PrintTokensList aList 
		for aToken in aList {
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

	private

		C_WIDTH	= 12

		func Width cText,nWidth
			return cText+Copy(" ",nWidth-len(cText))