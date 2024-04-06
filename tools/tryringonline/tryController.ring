#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

load "tryView.ring"
load "samples.ring"
load "colors.ring"
load "ringvm.ring"

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

	oView.win.setStyleSheet("font-size:16pt;")

	oRingVM = new RingVM {
		prepareFiles()
	}

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

		oRingVM.prepareSyntaxErrorsOutput()
		if ring_state_mainfile(pState,"start.ring")
			clearOutput()
			showOutput()
		else 
			oRingVM.getSyntaxErrors(oView)
		ok

		oView.txtInput.setFocus(0)

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
