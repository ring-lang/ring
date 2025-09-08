/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"
load "tokenslib.ring"

# Global Variables (Customization)

cKeywordsStyle          = :lower    # Options :lower, :upper, :name
cIndentation            = :tabs     # Options :tabs, :spaces, :2spaces, :4spaces, :8spaces
cOutputType             = :print    # Just Print the output

# Global Variables (Control)

## Files and Tokens
aFilesToProcess         = []
aFileTokens             = []
nCurrentToken           = 0
cOutputBuffer           = ""
cCurrentFileName        = ""

## Spaces 
lSpaceBeforeToken       = False
lSpaceAfterToken        = False

## New Lines 
lNextNLisTwoNLs         = False
nLastLineNumber         = 0
nLastTokenInLastLine    = 0

## Tabs and Indentation
nTabsCount              = 0
nPackageTab             = 0
nClassTab               = 0
nFuncTab                = 0
nLastTabsCount          = 0

## Configuration Lists

aStartImportant         = [ :package, :class, :func, :def, :function			        ]
aEndImportant           = [ :endpackage, :endclass, :endfunc, :end, :endfunction		]

aStartTabs              = [ :for, :foreach, :while, :do, :if, :switch, :try			]
aEndTabs                = [ :next, :end, :again, :ok, :off, :done,
                            :endif, :endfor, :endswitch, :endtry, :endwhile			]

aStartNL                = [ :package, :else, :elseif, :but, :on, :case, :other, :catch	        ]

aOperatorSpaceBefore    = [ "=","?","{",
                            "+=","-=","*=","/=","%=",
                            "&=","|=","^=","<<=",">>=",
                            "<",">","<=",">=","!=","&&","||"				        ]
aOperatorSpaceAfter     = [ "=","?",",","!","{",
                            "+=","-=","*=","/=","%=",
                            "&=","|=","^=","<<=",">>=",
                            "<",">","<=",">=","!=","&&","||"				        ]

aOperatorSpaceBeforeVar = [ ")","]","}",'"',"'","`"                                             ]

aOperatorBeforeAnonFunc = [ "=", "(", "," ,"["                                                  ]

func main

	decimals(3)

	aPara      = AppArguments()

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
	# Convert to lower case
	cOption = lower(cOption)

	if cOption = "keywords:lower"       or cOption = "k:l"
		cKeywordsStyle	= :lower
	but cOption ="keywords:upper"       or cOption = "k:u"
		cKeywordsStyle	= :upper
	but cOption ="keywords:name"        or cOption = "k:n"
		cKeywordsStyle	= :name
	but cOption ="indentation:tabs"     or cOption = "i:t"
		cIndentation	= :tabs
	but cOption ="indentation:spaces"   or cOption = "i:s"
		cIndentation	= :spaces
	but cOption ="indentation:2spaces"  or cOption = "indentation:2" or cOption = "i:2"
		cIndentation	= :2spaces
	but cOption ="indentation:4spaces"  or cOption = "indentation:4" or cOption = "i:4"
		cIndentation	= :4spaces
	but cOption ="indentation:8spaces"  or cOption = "indentation:8" or cOption = "i:8"
		cIndentation	= :8spaces
	but cOption ="output:print"         or cOption = "o:p"
		cOutputType	= :print 
	but cOption ="output:write"         or cOption = "o:w"
		cOutputType	= :write 
	but cOption ="output:none"          or cOption = "o:n"
		cOutputType	= :none
	else
		return false
	ok	
	
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
		nClock1 = clock()
		processTokens(loadFileTokens(cFileName))
		line()	
		? "Processing Time: " + ((clock()-nClock1)/clocksPerSecond()) + " seconds."
		line()
	catch
		line()
		? "Error processing the file: " + cFileName
		? cCatchError 
		line()
	done
	chdir(cDir)

func loadFileTokens cFileName

	pState  = ring_state_new()
	aTokens = ring_state_stringtokens(pState,read(cFileName),False,True,True)
	if ring_state_scannererror(pState) 
		raise("Ring Scanner Error!")
	ok
	ring_state_delete(pState)

	cCurrentFileName = cFileName

	return aTokens	

func processTokens aTokens 

	aFileTokens   = aTokens
	resetVariables()
	for aToken in aFileTokens
		lSpaceBeforeToken   = False
		lSpaceAfterToken    = False
		cValue              = aToken[C_TOKENVALUE]
		cValue              = processToken(aToken,cValue)
		printToken(cValue)
		nCurrentToken++
	next

	if cOutputType = :print
		? cOutputBuffer
	but cOutputType = :write
		? "Write File: " + cCurrentFileName
		write(cCurrentFileName, cOutputBuffer)
	ok

func resetVariables

	nCurrentToken       = 1
	cOutputBuffer       = ""
	lNextNLisTwoNLs     = False
	nLastLineNumber     = 0
	nTabsCount          = 0
	nPackageTab         = 0
	nClassTab           = 0
	nFuncTab            = 0	
	nLastTabsCount      = 0

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

	if lSpaceBeforeToken cOutputBuffer += " " ok
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
		nPackageTab = 1
		nClassTab   = 0
		nFuncTab    = 0
	but cKeyword    = :class
		nClassTab   = 1
		nFuncTab    = 0
	but find([:func,:def,:function],cKeyword) 
		if ! lastTokenIsOperator(aOperatorBeforeAnonFunc)
			nFuncTab = 1
		else
			# We have anonymous function
			lSpaceAfterToken = True
			return lower(cKeyword)
		ok
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

	lSpaceBeforeToken	= ! afterTabOrSpaceOrNLInBuffer()
	lSpaceAfterToken	= True

	return cKeyword

func lastTokenIsOperator aOperators

	aPrevToken = getPrevToken()
	if aPrevToken[C_TOKENTYPE] = C_OPERATOR 
		cOperator = aPrevToken[C_TOKENVALUE]
		return find(aOperators,cOperator)
	ok
	return False


func removeLastTabFromBuffer

	cTabChars     = getTabChars()
	nTabCharsSize = len(cTabChars)

	if ( len(cOutputBuffer) > nTabCharsSize ) and
		right(cOutputBuffer,nTabCharsSize) = cTabChars
			cOutputBuffer = left(cOutputBuffer, len(cOutputBuffer) - nTabCharsSize )
	ok

func afterTabOrSpaceOrNLInBuffer
	
	if cOutputBuffer 
		cLastChar = right(cOutputBuffer,1) 
		return cLastChar = Tab or cLastChar = " " or cLastChar = NL 
	ok

	return true

func processOperator cOperator

	if find(aOperatorSpaceBefore, cOperator) and ! afterTabOrSpaceOrNLInBuffer()
		lSpaceBeforeToken = True 
	ok

	if find(aOperatorSpaceAfter, cOperator)
		lSpaceAfterToken = True 
	ok

	if cOperator = ":"
		aNextToken = getNextToken()
		if aNextToken[C_TOKENTYPE] = C_KEYWORD
			del(aFileTokens,nCurrentToken+1)
			cValue	 = aNextToken[C_TOKENVALUE]
			nIndex   = 0 + cValue	
			cKeyword = lower(aKeywords[nIndex])	
			cOperator += cKeyword
		ok
	but cOperator = "{"
		lAddTabs = True
		# Take in mind writing conditions in many lines then using braces
		if nLastTokenInLastLine
			if aFileTokens[nLastTokenInLastLine][C_TOKENTYPE] = C_KEYWORD
				cKeyword = lower(aKeywords[0+aFileTokens[nLastTokenInLastLine][C_TOKENVALUE]])
				lAddTabs = ! ( cKeyword = "and" or cKeyword = "or" or cKeyword = "not" )
			ok
		ok
		if lAddTabs
			nTabsCount++ 
		ok
	but cOperator = "["
		nTabsCount++ 
	but cOperator = "}" or cOperator = "]"
		if nTabsCount nTabsCount-- ok
		removeLastTabFromBuffer()
	ok

	return cOperator

func getNextToken

	nNextToken = nCurrentToken+1
	if nNextToken <= len(aFileTokens)
		return aFileTokens[nNextToken]
	ok

	return [-1,-1,-1]

func getPrevToken

	if nCurrentToken > 1
		return aFileTokens[nCurrentToken-1]
	ok

	return [-1,-1,-1]

func processLiteral cLiteral

	addSpaceBeforeThisTokenIfThePrevTokenIsNumberOrLiteral()

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

	addSpaceBeforeThisTokenIfThePrevTokenIsNumberOrLiteral()

	return cNumber

func addSpaceBeforeThisTokenIfThePrevTokenIsNumberOrLiteral

	nType = getPrevToken()[C_TOKENTYPE]
	if (nType = C_NUMBER or nType = C_LITERAL) and ! afterTabOrSpaceOrNLInBuffer()
		lSpaceBeforeToken = True
	ok

func processIdentifier cIdentifier

	if ( find(aOperatorSpaceBeforeVar, getLastCharInBuffer()) OR
		getPrevToken()[C_TOKENTYPE] = C_NUMBER ) and ! afterTabOrSpaceOrNLInBuffer()
		lSpaceBeforeToken = True
	ok

	if getNextToken()[C_TOKENTYPE] != C_OPERATOR
		lSpaceAfterToken = True
	ok

	return cIdentifier

func getLastCharInBuffer

	if cOutputBuffer
		return right(cOutputBuffer,1)
	ok

	return NULL

func processEndLine cEndLine

	nLastTokenInLastLine	= nCurrentToken - 1
	cValue			= NL

	# Check if we have many new lines 
	if nLastLineNumber and ( (0 + cEndLine) - nLastLineNumber > 1 ) and ! lNextNLisTwoNLs
		cValue += cValue
	ok

	nLastLineNumber = 0 + cEndLine

	if lNextNLisTwoNLs
		lNextNLisTwoNLs = False
		cValue += cValue
	ok

	lSpaceAfterToken = False

	# We can use braces to access objects or in control structures 
	# Using braces in controls structures increase nTabsCount multiple times 
	# Here we adjust the nTabsCount 

	if nTabsCount > nLastTabsCount and nTabsCount != nLastTabsCount+1
		nTabsCount = nLastTabsCount+1
	but nTabsCount < nLastTabsCount and nTabsCount != nLastTabsCount-1
		nTabsCount = nLastTabsCount-1
	ok

	# Take in mind that we can write an if-statement in one line (using braces)
	# Example: if condition { }
	# This will lead to increasing the nTabsCount!

	if nTabsCount = nLastTabsCount+1 and 
		aFileTokens[nLastTokenInLastLine][C_TOKENTYPE] = C_OPERATOR and
		aFileTokens[nLastTokenInLastLine][C_TOKENVALUE] = "}"
		nTabsCount = nLastTabsCount
	ok 

	nLastTabsCount = nTabsCount

	return cValue + getTabs()

func processComment cComment

	# Add new line before/after multi-line comments
	if substr(cComment,nl) 
		nTabsCount = nPackageTab + nClassTab 
		# Remove /* and */
		cComment   = subStr(cComment,3,len(cComment)-4)	 
		# Remove Spaces, Tabs and New Lines
		while (left(cComment,1)   = Tab) or (left(cComment,1) = " ") or 
			(left(cComment,1) = char(13)) or (left(cComment,1) = char(10))
			cComment = substr(cComment,2)
		end
		while (right(cComment,1)   = Tab) or (right(cComment,1) = " ") or 
			(right(cComment,1) = char(13)) or (right(cComment,1) = char(10))
			cComment = left(cComment,len(cComment)-1)
		end	
		# Convert the string to list
		aList = str2List(cComment)
		# Process each line
		for cLine in aList
			while left(cLine,1) = Tab or left(cLine,1) = " "
				cLine = substr(cLine,2)
			end
			if left(cLine,2) = "**"
				cLine = getNTabs(nTabsCount) + cLine
			else
				cLine = getNTabs(nTabsCount+1) + cLine
			ok
		next
		# Convert the list to string
		cComment = list2Str(aList)
		# Get the final comment after formatting
		cComment = getNTabs(nTabsCount) + "/*" + nl + cComment + nl + getNTabs(nTabsCount) + "*/"
		cComment = nl + cComment + nl
	else
		if ! afterTabOrSpaceOrNLInBuffer()
			cComment = " " + cComment 
		ok
	ok

	lSpaceAfterToken = False

	return cComment

func showhelp

	line()
	? "RingFmt (Source code formatter and beautifier)"
	line()
	? "2025, Mahmoud Fayed <msfclipper@yahoo.com>"
	? "Prototyping: Bert Mariani & Azzeddine Remmal"
	line()
	? "Usage: ringfmt filename.ring [Options]"
	line()
	? "-keywords:lower   (-k:l): Convert all keywords to lowercase (default)"
	? "-keywords:upper   (-k:u): Convert all keywords to UPPERCASE"
	? "-keywords:name    (-k:n): Convert keywords to NameCase (e.g., Class, From)"
	? "-indentation:tabs (-i:t): Use tab characters for indentation (default)"
	? "-indentation:2    (-i:2): Use 2 spaces per indentation level"
	? "-indentation:4    (-i:4): Use 4 spaces per indentation level"
	? "-indentation:8    (-i:8): Use 8 spaces per indentation level"
	? "-output:print     (-o:p): Print formatted output (default)"
	? "-output:write     (-o:w): Overwrite the source file with formatted output"
	? "-output:none      (-o:n): No output"
	line()

func line

	? copy("=",75)
