/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"
load "tokenslib.ring"

# Global Variables (Customization)

cKeywordsStyle		= :lower	# Options :lower, :upper, :name
cIndentation 		= :tabs		# Options :tabs, :spaces, :2spaces, :4spaces, :8spaces

# Global Variables (Control)

aFilesToProcess		= []
aFileTokens		= []
nCurrentToken		= 0
cOutputBuffer		= ""
lSpaceAfterToken	= False
lNextNLisTwoNLs		= False
nTabsCount		= 0
nPackageTab		= 0
nClassTab		= 0
nFuncTab		= 0
aStartImportant		= [	:package, :class, :func, :def, :function			]
aEndImportant		= [	:endpackage, :endclass, :endfunc, :end, :endfunction		]
aStartTabs		= [	:for, :foreach, :while, :do, :if, :switch, :try, "{"		]
aEndTabs		= [	:next, :again, :ok, :off, :done,
				:endif, :endfor, :endswitch, :endtry, :endwhile, "}"		]
aStartNL		= [	:load, :package, :import, :break, :continue, :exit, :loop, 
				:else, :elseif, :but, :on, :case, :other, :catch, :bye,
				:put, :get, :see, :give						]
aOperatorNoSpace	= [	"[",":","("							]

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
	
	# Pass dash '-' at the start of any option
	if left(cOption,1) = "-" cOption = substr(cOption,2) ok

	switch lower(cOption)
	on "keywords:lower"
		cKeywordsStyle	= :lower
	on "keywords:upper"
		cKeywordsStyle	= :upper
	on "keywords:name"
		cKeywordsStyle	= :name
	on "indentation:tabs"
		cIndentation	= :tabs
	on "indentation:spaces"
		cIndentation	= :spaces
	on "indentation:2spaces"
		cIndentation	= :2spaces
	on "indentation:4spaces"
		cIndentation	= :4spaces
	on "indentation:8spaces"
		cIndentation	= :8spaces
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

	aFileTokens   = aTokens
	resetVariables()
	for aToken in aFileTokens
		lSpaceAfterToken = True
		cValue		 = aToken[C_TOKENVALUE]
		cValue 		 = processToken(aToken,cValue)
		printToken(cValue)
		nCurrentToken++
	next
	? cOutputBuffer

func resetVariables

	nCurrentToken	= 1
	cOutputBuffer	= ""
	nTabsCount	= 0
	nPackageTab	= 0
	nClassTab	= 0
	nFuncTab	= 0	

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

	cOutputBuffer += cValue
	if lSpaceAfterToken cOutputBuffer += " " ok

func getTabs

	return getNTabs(nTabsCount)

func getNTabs nCount

	return copy(getTabChars(),nCount)

func getTabChars

	cTabChars = Tab
	switch cIndentation 
		on :spaces
			cTabChars = Copy(" ",8)
		on :2spaces
			cTabChars = Copy(" ",2)
		on :4spaces
			cTabChars = Copy(" ",4)
		on :8spaces
			cTabChars = Copy(" ",8)
	off
	return cTabChars

func processKeyword cValue

	nIndex   = 0 + cValue	
	cKeyword = lower(aKeywords[nIndex]) 

	# Apply tabs for important sections (package, class & function)
	lImportantSection	= True
	if cKeyword = :package
		nPackageTab	= 1
	but cKeyword = :class
		nClassTab	= 1
	but find([:func,:def,:function],cKeyword)
		nFuncTab	= 1
	else
		lImportantSection = False
	ok
	if lImportantSection
		nTabsCount = nPackageTab + nClassTab + nFuncTab
	ok

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
	if find(aStartTabs,lower(cKeyword))
		nTabsCount++ 
	but find(aEndTabs,lower(cKeyword))
		if nTabsCount nTabsCount-- ok
		removeLastTabFromBuffer()
	but find(aStartImportant,lower(cKeyword))
		cKeyword = nl + getNTabs(nTabsCount-1) + cKeyword
		lNextNLisTwoNLs = True
	but find(aEndImportant,lower(cKeyword))
		cKeyword += nl + getNTabs(nTabsCount-1)
	but find(aStartNL,lower(cKeyword))
		removeLastTabFromBuffer()
	ok

	return cKeyword

func removeLastTabFromBuffer

	cTabChars	= getTabChars()
	nTabCharsSize	= len(cTabChars)

	if ( len(cOutputBuffer) > nTabCharsSize ) and
		right(cOutputBuffer,nTabCharsSize) = cTabChars
			cOutputBuffer = left(cOutputBuffer, len(cOutputBuffer) - nTabCharsSize )
	ok

func processOperator cOperator

	if find(aOperatorNoSpace, cOperator)
		lSpaceAfterToken = False 
	ok

	if cOperator = ":"
		nNextToken = nCurrentToken+1
		if nNextToken < len(aFileTokens)
			aNextToken = aFileTokens[nCurrentToken+1]
			if aNextToken[C_TOKENTYPE] = C_KEYWORD
				del(aFileTokens,nNextToken)
				cValue	 = aNextToken[C_TOKENVALUE]
				nIndex   = 0 + cValue	
				cKeyword = lower(aKeywords[nIndex])	
				cOperator += cKeyword
			ok
		ok
	ok

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

	if lNextNLisTwoNLs
		lNextNLisTwoNLs = False
		cValue += cValue
	ok

	lSpaceAfterToken = False

	return cValue + getTabs()

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
