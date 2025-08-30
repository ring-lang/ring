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
	try
		processTokens(loadFileTokens(cFileName))
	catch
		line()
		? "Error processing the file: " + cFileName
		? cCatchError 
		line()
	done

func loadFileTokens cFileName

	pState = ring_state_new()
	aTokens = ring_state_stringtokens(pState,read(cFileName),False,True)
	if ring_state_scannererror(pState) 
		raise("Ring Scanner Error!")
	ok
	ring_state_delete(pState)
	return aTokens	

func processTokens aTokens 

	for aToken in aTokens
		lSpaceAfterToken = True
		switch aToken[C_TOKENTYPE] 
			on C_KEYWORD 
				cValue = processKeyword(0+aToken[C_TOKENVALUE]) 
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
				lSpaceAfterToken = False
			on C_COMMENT
				cValue = processComment(aToken[C_TOKENVALUE])
		off
		see cValue
		if lSpaceAfterToken see " " ok
	next

func processKeyword nIndex
	
	cKeyword = lower(aKeywords[nIndex]) 

	# Add new lines before important keywords
	if find(["package","class","func","def","function","private"],cKeyword)
		cKeyword = nl + cKeyword
	ok

	return cKeyword

func processLiteral cLiteral

	if ! substr(cLiteral,'"')
		return '"' + cLiteral + '"'
	but ! substr(cLiteral,"'")
		return "'" + cLiteral + "'"
	but ! substr(cLiteral,"`")
		return "`" + cLiteral + "`"
	else 
		raise("Unexpected literal content: " + cLiteral)
	ok

func processComment cComment

	# Add new line after multi-line comments
	if substr(cComment,nl) cComment += nl ok

	return cComment

func showhelp

	line()
	? "RingFmt (Source code formatter and beautifier)"
	line()
	? "2025, Mahmoud Fayed <msfclipper@yahoo.com>"
	? "Prototyping: Bert Mariani & Azzeddine Remmal"
	line()
	? "Usage: ringfmt <filename.ring>"
	line()

func line

	? copy("=",75)
