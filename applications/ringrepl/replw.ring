# Application  : Read-Eval-Print-Loop (REPL) - GUI Application
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

load "guilib.ring"

oProcess = NULL

new qApp  {

			StyleFusionBlack()

			oProcessWindow = new qWidget()  {

				setwindowtitle("RingREPL (Read - Eval - Print - Loop)")
				resize(600,500)

				oProcessLabel = new qLabel(oProcessWindow) {
					setText("Input :")
				}
				oProcessText = new qlineEdit(oProcessWindow) {
					setreturnPressedEvent("pSendProcessData()")
				}

				oProcessbtnSend = new qpushbutton(oProcessWindow) {
					setText("Send")
					setClickEvent("pSendProcessData()")
				}

				oProcessLayout1 = new qhboxlayout() {
					AddWidget(oProcessLabel)
					AddWidget(oProcessText)
					Addwidget(oProcessbtnSend)
				}

				oProcessEditbox = new qPlaintextedit(oProcessWindow) 
	
				oProcessLayout2 = new qvboxlayout() {
					addWidget(oProcesseditbox)
					addlayout(oProcesslayout1)
				}

				setlayout(oProcessLayout2)

				show()
			}

	exec()
}

func pSendProcessData
