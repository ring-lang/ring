# Form/Window Controller - Source Code File

load "moneyView.ring"
load "stdlibcore.ring"

import System.GUI

if IsMainSourceFile() {
	oApp = new App {
		StyleFusionBlack()
		openWindow(:moneyController)
		exec()
	}
}

class moneyController from windowsControllerParent

	oView = new moneyView

	CenterWindow()

	oView.txtMoney.SetEnabled(False)
	oView.txtPackages.SetEnabled(False)
	oView.txtStatus.SetEnabled(False)
	oView.txtAmount.SetEnabled(False)

	aMoney = [0,5,10,15,25,50,75,100,150,
		  175,200,250,300,400,475,
		  500,1000,1200,2000]

	aMoney = RandomList(aMoney)

	nMoney 		
	nPackages 	
	cStatus 	

	nAmount		
	nOpened		

	aButtons = [
		oView.button1,
		oView.button2,
		oView.button3,
		oView.button4,
		oView.button5,
		oView.button6,
		oView.button7,
		oView.button8,
		oView.button9,
		oView.button10,
		oView.button11,
		oView.button12,
		oView.button13,
		oView.button14,
		oView.button15,
		oView.button16,
		oView.button17,
		oView.button18,
		oView.button19
	]

	NewGame()
	
	func CenterWindow 
		oDesktop = new QDesktopWidget() {
			nX = ( Width()-this.oView.win.Width() ) / 2
			nY = ( Height()-this.oView.win.Height() ) / 2
		}
		oView.win.move(nX,nY)

	func DisplayStatus
		oView.txtMoney.SetText(""+nMoney)
		oView.txtPackages.SetText(""+nPackages)
		oView.txtStatus.SetText(cStatus)
		oView.txtAmount.SetText(""+nAmount)

	func MoneyCase nIndex

		if nOpened >= nPackages return ok

		aButtons[nIndex].setStyleSheet("background-color:green;")
		aButtons[nIndex].blocksignals(True)

		nValue = aMoney[nIndex]
		DisplayVideo(nValue)
		nAmount += nValue 
		nOpened ++

		if nAmount >= nMoney 
			cStatus 	= "You Win"
		else 
			if nOpened = nPackages 
				cStatus 	= "Game Over"
			ok
		ok
	
		DisplayStatus()

	func DisplayVideo nValue 

		cFile = "video/m"+nValue+".avi"

		if fexists(cFile)
			oView.playerVideoWidget1 {
				setmedia(new qurl(cFile))
				play()
			}
		ok

	func NewGame
		aMoney 		= RandomList(aMoney)
		nMoney 		= 1200 + random(12)*100
		nPackages 	= 3 + random(4) 
		cStatus 	= "Playing"
		nAmount		= 0
		nOpened		= 0
		DisplayStatus()
		for oButton in aButtons
			oButton { 
				setStyleSheet("")
				BlockSignals(False)
			}
		next 
		oView.playerVideoWidget1 {
			setmedia(new qurl("video/start.avi"))
			play()
		}

	func CloseApp
		oView.playerVideoWidget1.stop()
		oView.win.close()
		oApp.Quit()
