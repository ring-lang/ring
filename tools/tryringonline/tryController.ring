#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

load "tryView.ring"
load "samples.ring"
load "colors.ring"

import System.GUI

RING_VAR_VALUE = 3

if IsMainSourceFile() {
	oApp = new App {
		StyleFusionBlack()
		openWindow(:tryController)
		exec()
	}
}

class tryController from windowsControllerParent

	oView = new tryView

	pState   = NULL

	fpSyntaxErrors    = NULL
	cSyntaxErrorsFile = "programoutput.txt"

	oView.win.setStyleSheet("font-size:16pt;")

	prepareFiles()

	nActiveExample = 1
	loadExamples()
	setExample(nActiveExample)


	oSyntaxColors = new SyntaxColors { 
		setStyleColors(:Black) 
		ApplySyntaxColors(this.oView.txtCode)  
	}

	func run 

		if pState 
			pState = ring_state_delete(pState)
		ok

		pState = ring_state_new()

		cCode = oView.txtCode.toPlaintext()

		write("codetorun.ring",cCode+nl)

		prepareSyntaxErrorsOutput()
		if ring_state_mainfile(pState,"start.ring")
			clearOutput()
			showOutput()
		else 
			getSyntaxErrors()
		ok

		oView.txtInput.setFocus(0)

	func prepareSyntaxErrorsOutput

		remove(cSyntaxErrorsFile)
		fpSyntaxErrors = freopen(cSyntaxErrorsFile,"w+",stdout)

	func getSyntaxErrors

		fclose(fpSyntaxErrors)
		cError = read(cSyntaxErrorsFile)
		nPos = substr(cError,"start.ring Line")
		if nPos
			cError = left(cError,nPos-1) 
		ok
		oView.txtOutput.setText(cError)

	func showOutput
 
		vVar = ring_state_findvar(pState,:cOutput)
		cOutput = vVar[RING_VAR_VALUE]
		oView.txtOutput.setText(oView.txtOutput.toPlainText() + cOutput)
		ring_state_setvar(pState,:cOutput,"")

		# Move to the End of the output 
		oCursor = oView.txtOutput.textcursor()
		nPos = max(len(oView.txtOutput.toplaintext())-1,0)
		oCursor.setPosition(nPos,QTextCursor_KeepAnchor)
		oCursor.setPosition(nPos,QTextCursor_MoveAnchor)
		oView.txtOutput.setTextCursor(oCursor)

	func send 

		if ! pState 
			oView.txtOutput.setText("Please run the program first!")
			return
		ok

		vVar = ring_state_findvar(pState,:lActiveGive)
		lActiveGive = vVar[RING_VAR_VALUE]
	
		if ! lActiveGive 
			oView.txtOutput.setText("No input is required!")
			return 
		ok

		lActiveGive = False 
		ring_state_setvar(pState,:lActiveGive, False)

		cInput = oView.txtInput.text()
		oView.txtOutput.setText(oView.txtOutput.toPlainText()+cInput+nl)
		ring_state_runcodeatins(pState,0,cInput)
		oView.txtInput.setText("")

		showOutput()

		oView.txtInput.setFocus(0)

	func formatSample cCode 

		cCode = substr(cCode,2)
		cCode = substr(cCode,Tab,"")
		return cCode 

	func loadExamples 

		oView.comboSample {
			for item in aSamples
				addItem(item[C_SAMPLENAME],0) 
			next 
			setCurrentIndex(this.nActiveExample)
		}

	func setExample nIndex

		cCode = formatSample(aSamples[nIndex][C_SAMPLECODE])

		oView.txtCode.setText(cCode)

	func prepareFiles()

		prepareOnlineRingFile()
		prepareStartFile()

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

		`)		

	func prepareStartFile 

		write("start.ring",`load "onlinering.ring"`+nl+ `
			Try
				load "codetorun.ring" 
			catch 
				? cCatchError 
			done
		`)


	func clearSourceCode

		oView.txtCode.setText("")

	func clearOutput

		oView.txtOutput.setText("")

	func ChangeFontSize

		oView {
			cFontSize = comboFont.currentText()	
			win { 
				setStyleSheet("font-size:"+cFontSize+"pt;")
				show()
			}
		}

	func changeStyle

		cStyle = oView.comboStyle.currentText()
		oSyntaxColors.style(oApp,oView.win,oView.txtCode,cStyle) 		

	func changeSample

		nIndex = oView.comboSample.currentIndex()
		setExample(nIndex)
