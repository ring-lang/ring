# Application  : Read-Eval-Print-Loop (REPL) - GUI Application
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

load "guilib.ring"

# Get Command Line Parameters
	nStyle = 0
	if len(sysargv) >= 3 {
		nStyle = sysargv[3]
	}


oProcess = NULL

oApp = new qApp  {
	switch nStyle {
		
		case 1
			StyleFusion()
		case 2 
			StyleFusionBlack()
	}
	oProcessWindow = new qWidget()  {
		setwindowflags(Qt_WindowStaysOnTopHint)
		setwindowtitle("RingREPL (Read - Eval - Print - Loop)")
		resize(600,500)
		setwinicon(self,"source.png")
		oProcessLabel = new qLabel(oProcessWindow) {
			setText("Ring :")
		}
		oProcessText = new qLineEdit(oProcessWindow) {
			setreturnPressedEvent("pSendProcessData()")
		}
		oProcessbtnHistory = new qpushbutton(oProcessWindow) {
			setText("History")
			setClickEvent("pHistory()")
		}
		oProcessLayout1 = new qhboxlayout() {
			AddWidget(oProcessLabel)
			AddWidget(oProcessText)
			Addwidget(oProcessbtnHistory)
		}
		oProcessEditbox = new qPlaintextedit(oProcessWindow) 
		oCommandsEditbox = new qPlaintextedit(oProcessWindow) 
		oProcessLayout2 = new qvboxlayout() {
			addWidget(oProcesseditbox)
			addlayout(oProcesslayout1)
			addWidget(oCommandseditbox)
		}
		setlayout(oProcessLayout2)
		oCommandsEditbox.hide()
		oProcessText.setfocus(0)
		show()
	}
	oProcess = pRunProcess(exefolder()+"ring","replwscript.ring","pGetProcessData()")
	exec()
}

func pSendProcessData
	if ISNULL(oProcess) { return }
	oCommandsEditbox.insertplaintext(oProcessText.text()+nl)
	oCursor = oCommandsEditbox.textcursor()
	oCursor.setposition(len(oCommandsEditbox.toplaintext()),0)
	oCommandsEditbox.settextcursor(oCursor)
	switch lower(trim(oProcessText.text())) {
		case "exit"
			oApp.Quit()
		case "clear"
			oProcessEditbox.clear()		
			oProcessText.setText(NULL)
			return 
	}
	cText = oProcessText.text() + windowsnl()
	oProcess.write(cText ,len(cText))
	oProcessText.setText(NULL)

func pRunProcess cProgram,cArg,cGetDataFunc
	oStringList = new qStringlist() {
		append(cArg)
	}
	oProcess = new qprocess(NULL) {
		setprogram( cProgram)
		setarguments(ostringlist)
		setreadyreadstandardoutputevent("pGetProcessData()")
		start_3(  QIODevice_ReadWrite )
	}
	return oProcess

func pGetProcessData 
	if ISNULL(oProcess) { return }
	cText = oProcess.readallstandardoutput().data()
	oProcessEditbox.insertplaintext(cText)
	oCursor = oProcessEditbox.textcursor()
	oCursor.setposition(len(oProcessEditbox.toplaintext()),0)
	oProcessEditbox.settextcursor(oCursor)

func pHistory
	if oCommandsEditbox.isvisible()  {
		oCommandsEditbox.hide()
	else 
		oCommandsEditbox.show()
	}
