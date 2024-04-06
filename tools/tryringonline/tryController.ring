#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

load "tryView.ring"
load "samples.ring"
load "style.ring"
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

	oStyle = new Style

	oAllEvents = NULL
	prepareUI()

	oRingVM = new RingVM
		
	nActiveExample = 1
	loadExamples()
	setExample(nActiveExample)

		

	func prepareUI

		winCode    = new QWidget() { setLayout(this.oView.LayoutGroup1) }
		winOutput  = new QWidget() { setLayout(this.oView.LayoutGroup2) }
		oSplitter  = new QSplitter(oView.win) { addWidget(winCode) addWidget(winOutput) }
		LayoutMain = new QHBoxLayout() {
			addWidget(oSplitter)			
		}

		oMWLayoutWidget = new qWidget() { setLayout(LayoutMain) }
		oView.win.setCentralWidget(oMWLayoutWidget) 
		oView.win.show()

		changeFontSize()

		oStyle { 
			setStyleColors(:Black) 
			ApplySyntaxColors(this.oView.txtCode)  
		}

		nMaxWidth = oView.btnSend.width()*3
		oView.btnClearOutput.setMaximumWidth(nMaxWidth)
		oView.btnClearSourceCode.setMaximumWidth(nMaxWidth)
		oView.btnRun.setMaximumWidth(nMaxWidth)

		oView.lblFontSize.setSizePolicy(0,1)
		oView.comboFontSize.setSizePolicy(0,1)
		oView.lblStyle.setSizePolicy(0,1)
		oView.comboStyle.setSizePolicy(0,1)

		// Since setTabChangesFocus(False) doesn't work in Qt for WASM
		// We Change the behavior using an Event Filter		
		oAllEvents = new QAllevents(oView.win) {
			setKeypressevent(Method(:CodeKeyPress))
		}
		oView.txtCode.installEventFilter(oAllEvents)

	func codeKeyPress

		nKeyCode = oAllEvents.getKeyCode() 
		if nKeyCode = Qt_Key_Tab
			oView.txtCode.textcursor().insertText(Char(9))
			oAllEvents.setEventOutput(True)
			return
		ok
		oAllEvents.setEventOutput(False)

	func run 

		cCode = oView.txtCode.toPlaintext()
		
		if oRingVM.run(oView,cCode)
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
		on :NoProgramIsRunning 
			oView.txtOutput.setText("Please run the program first!")
			return
		on :NoInputIsRequired 
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
			cFontSize = comboFontSize.currentText()	
			win { 
				setStyleSheet("font-size:"+cFontSize+"pt;")
				show()
			}
		}

	func changeStyle

		cStyle = oView.comboStyle.currentText()
		oStyle.style(oApp,oView.win,oView.txtCode,cStyle) 		

	func changeSample

		nIndex = oView.comboSample.currentIndex()
		setExample(nIndex)
