# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteLists 

	# Create a function to add Ring List to qStringList
	func AddItems aList,oList
		for Item in aList
			oList.Append(Item)
		next


	func DisplayFunctionsList
		oFunctionsList.clear()
		if oDockFunctionsList.isvisible() = false return ok
		aFunctionsPos = []	# Lines numbers for each function
		if cActiveFileName = NULL return ok
		cTempActiveFile = cActiveFileName
		# Set the font
			oTFont.fromstring(cFont)
			oFunctionsList.setFont(oTFont)
		StatusMessage(T_RINGNOTEPAD_CREATEFUNCTIONSLISTWAIT) # "Creating functions list ... Please Wait!"
		aFileContent = str2list(read(FileNameEncoding(cActiveFileName)))
		nLineNumber = 0
		for cLine in aFileContent
			nLineNumber++
			cLine = lower(trim(cLine))
			if ( substr(cLine,"func ") > 0 ) or ( substr(cLine,"def ") > 0 )
				cLine = substr(cLine,"("," (")
				aList = Split(cLine," ")
				if len(aList) >= 2
					cFuncName = lower(trim(aList[2]))
					cFuncNameWithoutSymbols = cFuncName
					for cChar in ["_","@","$"]
						cFuncNameWithoutSymbols = substr(cFuncNameWithoutSymbols,cChar,"")
					next 
					if isalnum(cFuncNameWithoutSymbols) and 
						( lower(trim(aList[1])) = "func" or lower(trim(aList[1])) = "def" )
						aFunctionsPos + [cFuncName+"()" , nLineNumber]
					ok
				ok
			ok
			if nLineNumber % 100 = 0 
				nOldCount = oFunctionsList.Count()
				oApp.ProcessEvents()
				if oFunctionsList.Count() != nOldCount 
					return
				ok
				# Check if the file is changed
				if not cTempActiveFile = cActiveFileName
					return 
				ok
			ok
		next
		aFunctionsPos = Sort(aFunctionsPos,1)
		for cFunc in aFunctionsPos
			oFunctionsList.addItem(cFunc[1])
		next
		oDockFunctionsList.setWindowTitle(T_RINGNOTEPAD_FUNCTIONSDOCKWINDOWTITLE+" ("+oFunctionsList.Count()+")")
		StatusMessage(T_RINGNOTEPAD_CREATEFUNCTIONSLISTDONE) # "Creating functions list ... Done!"

	func SelectFunction
		nIndex = oFunctionsList.currentrow() + 1
		nLine = aFunctionsPos[nIndex][2]
		gotoline(nLine)
		oDockSourceCode.Raise()

	func DisplayClassesList
		oClassesList.clear()
		if oDockClassesList.isvisible() = false return ok
		aClassesPos = []	# Lines numbers for each class
		if cActiveFileName = NULL return ok
		cTempActiveFile = cActiveFileName
		# Set the font
			oTFont.fromstring(cFont)
			oClassesList.setFont(oTFont)
		StatusMessage(T_RINGNOTEPAD_CREATECLASSESLISTWAIT) # "Creating Classes list ... Please Wait!"
		aFileContent = str2list(read(FileNameEncoding(cActiveFileName)))
		nLineNumber = 0
		for cLine in aFileContent
			nLineNumber++
			cLine = lower(trim(cLine))
			if substr(cLine,"class ") > 0
				aList = Split(cLine," ")
				if len(aList) >= 2
					cClassName = lower(trim(aList[2]))
					if lower(trim(aList[1])) = "class"
						aClassesPos + [cClassName , nLineNumber]
					ok
				ok
			ok
			if nLineNumber % 100 = 0 
				nOldCount = oClassesList.Count()
				oApp.ProcessEvents()
				if oClassesList.Count() != nOldCount 
					return 
				ok
				# Check if the file is changed
				if not cTempActiveFile = cActiveFileName
					return 
				ok
			ok
		next
		aClassesPos = Sort(aClassesPos,1)
		for cClass in aClassesPos
			oClassesList.addItem(cClass[1])
		next
		oDockClassesList.setWindowTitle(T_RINGNOTEPAD_CLASSESDOCKWINDOWTITLE+" ("+oClassesList.Count()+")")
		StatusMessage(T_RINGNOTEPAD_CREATECLASSESLISTDONE) # "Creating classes list ... Done!"

	func SelectClass
		nIndex = oClassesList.currentrow() + 1
		nLine = aClassesPos[nIndex][2]
		gotoline(nLine)
		oDockSourceCode.Raise()
