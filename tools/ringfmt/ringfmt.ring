/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"
load "tokenslib.ring"

func main

	aPara	   = AppArguments()

	nParaCount = len(aPara)
	if ! nParaCount showHelp() return ok

	processArguments(aPara)

func processArguments aPara 

	for cArg in aPara 
		if fexists(cArg)
			processFile(cArg)
		else 
			? "Unknown argument: " + cArg
		ok
	next  

func processFile cFileName
	
	? "Process file: " + cFileName
	oTokens = new RingTokens { fromFile(cFileName) }
	processTokens(oTokens.aTokens)

func processTokens aTokens 
	for aToken in aTokens
		switch aToken[C_TOKENTYPE] 
			on C_KEYWORD 
				cValue = aKeywords[0+aToken[C_TOKENVALUE]] 
			on C_OPERATOR 
				cValue = aToken[C_TOKENVALUE]
			on C_LITERAL 
				cValue = processLiteral(aToken[C_TOKENVALUE])
   			on C_NUMBER 
				cValue = aToken[C_TOKENVALUE]
			on C_IDENTIFIER 
				cValue = aToken[C_TOKENVALUE]
			on C_ENDLINE 
				cValue = NL
		off
		see cValue + " "
	next

func processLiteral cLiteral
	if ! substr(cLiteral,'"')
		return '"' + cLiteral + '"'
	but ! substr(cLiteral,"'")
		return "'" + cLiteral + "'"
	but ! substr(cLiteral,"`")
		return "`" + cLiteral + "`"
	else 
		? "Unexpected literal content: " + cLiteral
		bye
	ok

func showhelp

	line ()
	? "RingFmt (Source code formatter and beautifier)"
	line ()
	? "2025, Mahmoud Fayed <msfclipper@yahoo.com>"
	? "Prototyping: Bert Mariani & Azzeddine Remmal"
	line ()
	? "Usage: ringfmt <filename.ring>"
	line ()

func line

	? copy("=",75)
