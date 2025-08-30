/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"
load "tokenslib.ring"

# Global Variables (Control)

aFilesToProcess  = []
lSpaceAfterToken = False

# Global Variables (Customization)

cKeywordsStyle	 = :lower	# Options :lower, :upper & :name

func main

	aPara	   = AppArguments()

	nParaCount = len(aPara)
	if ! nParaCount showHelp() return ok

	processArguments(aPara)

	processFiles()

func processArguments aPara 

	for cArg in aPara 
		if processOptions(cArg) loop ok
		if fexists(cArg)
			aFilesToProcess + cArg
		else 
			aList = getListOfFiles(cArg)
			if aList
				for cFile in aList aPara + prepareFileName(cFile) next
			else
				? "Unknown argument: " + cArg
			ok
		ok
	next

func processFiles

	for cFile in aFilesToProcess
		processFile(cFile)  
	next

func getListOfFiles cArg

	aList = []
	try
		cFolder = justFilePath(cArg)
		if      ! cFolder cFolder = currentDir() ok
		aList   = listAllFiles(cFolder,justFileName(cArg))
	catch
	done

	return aList

func processOptions cOption

	switch lower(cOption)
	on "keywords:lower"
		cKeywordsStyle = :lower
	on "keywords:upper"
		cKeywordsStyle = :upper
	on "keywords:name"
		cKeywordsStyle = :name
	other
		return false
	off	
	
	return True

func prepareFileName cFileName
	
	if isWindows()
		cFileName = substr(cFileName,"/","\")
	else
		cFileName = substr(cFileName,"\","/")
	ok
	return cFileName

func processFile cFileName

	line()	
	? "Process file: " + cFileName
	line()
	cDir     = currentDir()
	cFileDir = justFilePath(cFileName)
	if cFileDir chdir(cFileDir) ok
	try
		processTokens(loadFileTokens(cFileName))
	catch
		line()
		? "Error processing the file: " + cFileName
		? cCatchError 
		line()
	done
	chdir(cDir)

func loadFileTokens cFileName

	pState  = ring_state_new()
	aTokens = ring_state_stringtokens(pState,read(cFileName),False,True)
	if ring_state_scannererror(pState) 
		raise("Ring Scanner Error!")
	ok
	ring_state_delete(pState)
	return aTokens	

func processTokens aTokens 

	for aToken in aTokens
		lSpaceAfterToken = True
		cValue		 = aToken[C_TOKENVALUE]
		cValue 		 = processToken(aToken,cValue)
		printToken(cValue)
	next

func processToken aToken, cValue

	switch aToken[C_TOKENTYPE] 
		on C_KEYWORD 
			cValue = processKeyword    (cValue) 
		on C_OPERATOR 
			cValue = processOperator   (cValue)
		on C_LITERAL 
			cValue = processLiteral    (cValue)
		on C_NUMBER 
			cValue = processNumber     (cValue)
		on C_IDENTIFIER 
			cValue = processIdentifier (cValue)
		on C_ENDLINE
			cValue = processEndLine    (cValue)
		on C_COMMENT
			cValue = processComment    (cValue)
	off

	return cValue

func printToken cValue

	see cValue
	if lSpaceAfterToken see " " ok

func processKeyword cValue

	nIndex   = 0 + cValue	
	cKeyword = aKeywords[nIndex] 

	# Apply the required keyword style
	switch cKeywordsStyle
	on :lower
		cKeyword = lower(cKeyword)
	on :upper
		cKeyword = upper(cKeyword)
	on :name
		cKeyword = upper(left(cKeyword,1)) + lower(substr(cKeyword,2))
	off

	# Add new lines before important keywords
	if find(["package","class","func","def","function","private"],lower(cKeyword))
		cKeyword = nl + cKeyword
	ok

	return cKeyword

func processOperator cOperator

	return cOperator

func processLiteral cLiteral

	if  ! substr(cLiteral,'"')
		return '"' + cLiteral + '"'
	but ! substr(cLiteral,"'")
		return "'" + cLiteral + "'"
	but ! substr(cLiteral,"`")
		return "`" + cLiteral + "`"
	else 
		raise("Unexpected literal content: " + cLiteral)
	ok

func processNumber cNumber

	return cNumber

func processIdentifier cIdentifier
	
	return cIdentifier

func processEndLine cEndLine

	if isWindows()
		cValue   = WindowsNL()
	else
		cValue   = NL
	ok

	lSpaceAfterToken = False

	return cValue

func processComment cComment

	# Add new line after multi-line comments
	if substr(cComment,nl) cComment += nl ok

	lSpaceAfterToken = False

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
