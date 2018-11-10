/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func Width cString,nWidth
	# Accept String or Number (Will be converted to a String)
		if isNumber(cString) cString = "" + cString  ok
	# Add Spaces
		nMax = len(cString)
		if nMax < nWidth
			cString += Copy(" ",nWidth-nMax)
		ok
	return cString 

func Line 
	Line90()

func Line90
	see Copy("=",90) + nl

func Line70
	? copy("=",70)

func style cText,nStyle
	switch nStyle
		on :WhiteBlue
			cc_print(CC_FG_WHITE  | CC_BG_BLUE, cText)
		on :YellowBlack
			cc_print(CC_FG_YELLOW | CC_BG_BLACK, cText)
		on :WhiteRed
			cc_print(CC_FG_WHITE  | CC_BG_RED, cText)
	off
