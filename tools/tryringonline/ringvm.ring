#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

class RingVM 

	pState = NULL

	fpSyntaxErrors = NULL    

	cSyntaxErrorsFile = "programoutput.txt"

	prepareFiles()

	RING_VAR_VALUE = 3

	func prepareFiles()

		prepareStartFile()
		prepareOnlineRingFile()

	func prepareStartFile 

		write("start.ring",`load "onlinering.ring"`+nl+ `
			Try
				load "codetorun.ring" 
			catch 
				? cCatchError 
			done
		`)

	func prepareOnlineRingFile

		write("onlinering.ring",`

			cOutput     = ""
			lActiveGive = False

			func ringvm_see cData
				if isString(cData) 
				   cOutput += cData
				but isNumber(cData)
				   cData = "" + cData 
				   cOutput += cData
				but isList(cData) or isPointer(cData)
				   cOutput += processList(cData)
				but isObject(cData)
				   cOutput += processObj(cData)
				ok 
	 
			func processList aList 
				cData = "" 
				for item in aList
					if isString(item)
						cData += item 
						cData += nl
					but isnumber(item)
						cData += ""+item
						cData += nl
					but isList(item) 
						cData += processList(item)
					but isObject(item)
						cData += processObj(item)
					ok  			 
				next 
				return cData 

			func processObj oObj
				cData = "" 
 				for cAttr in attributes(oObj) 
					cValue = getAttribute(oObj,cAttr)
					cData += cAttr + ": "  
					if isString(cValue) 
					   cData += cValue
					but isNumber(cValue)
					   cValue = "" + cValue 
					   cData += cValue
					but isList(cValue) or isPointer(cValue)
					   cData += "[This Attribute Contains A List]"
					but isObject(cValue)
					   cData += "Object..."
					ok	
					cData += nl
				next
				return cData

			func ringvm_give
				lActiveGive = True 
				bye

			func getString 
				give thenewstring
				return thenewstring			

			func getNumber 
				give thenewnumber
				return 0+thenewnumber

			func shutdown 
				bye

		`)		

	func prepareSyntaxErrorsOutput

		remove(cSyntaxErrorsFile)
		fpSyntaxErrors = freopen(cSyntaxErrorsFile,"w+",stdout)

	func getSyntaxErrors oView

		fclose(fpSyntaxErrors)
		cError = read(cSyntaxErrorsFile)
		nPos = substr(cError,"start.ring Line")
		if nPos
			cError = left(cError,nPos-1) 
		ok
		oView.txtOutput.setText(cError)

	func run oView,cCode

		if pState 
			pState = ring_state_delete(pState)
		ok

		pState = ring_state_new()

		write("codetorun.ring",cCode+nl)

		prepareSyntaxErrorsOutput()
		if ring_state_mainfile(pState,"start.ring")
			return True
		ok 

		getSyntaxErrors(oView)

		return False 

	func getOutput 

		vVar = ring_state_findvar(pState,:cOutput)
		cOutput = vVar[RING_VAR_VALUE]
		ring_state_setvar(pState,:cOutput,"")

		return cOutput 

	func send cInput

		if ! pState 
			return :NoProgramIsRunning
		ok

		vVar = ring_state_findvar(pState,:lActiveGive)
		lActiveGive = vVar[RING_VAR_VALUE]
	
		if ! lActiveGive 
			return :NoInputIsRequired
		ok

		lActiveGive = False 
		ring_state_setvar(pState,:lActiveGive, False)

		ring_state_resume(pState,cInput,True)

		return :OutputIsReady
