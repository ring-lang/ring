#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

load "tryView.ring"
load "samples.ring"
load "colors.ring"
load "ringvm.ring"

import System.GUI

if IsMainSourceFile() {
	oApp = new App {
		StyleFusionBlack()
		openWindow(:tryController)
		exec()
	}
}

class tryController from windowsControllerParent

	oView = new tryView

	oView.win.setStyleSheet("font-size:16pt;")

	oRingVM = new RingVM
		
	nActiveExample = 1
	loadExamples()
	setExample(nActiveExample)


	oSyntaxColors = new SyntaxColors { 
		setStyleColors(:Black) 
		ApplySyntaxColors(this.oView.txtCode)  
	}

	func run 

		cCode = oView.txtCode.toPlaintext()
		
		if oRingVM.run(cCode)
			clearOutput()
			showOutput()
			oView.txtInput.setFocus(0)
		ok

	func showOutput
 
		oView.txtOutput.setText(oView.txtOutput.toPlainText() + oRingVM.getOutput())

		# Move to the End of the output 
			oCursor = oView.txtOutput.textcursor()
			nPos = max(len(oView.txtOutput.toplaintext())-1,0)
			oCursor.setPosition(nPos,QTextCursor_KeepAnchor)
			oCursor.setPosition(nPos,QTextCursor_MoveAnchor)
			oView.txtOutput.setTextCursor(oCursor)

	func send 
	
		cInput = oView.txtInput.text()
		oView.txtOutput.setText(oView.txtOutput.toPlainText()+cInput+nl)

		nRes = oRingVM.send(cInput)

		switch nRes
		on 1 
			oView.txtOutput.setText("Please run the program first!")
			return
		on 2 
			oView.txtOutput.setText("No input is required!")
			return 
		off

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
