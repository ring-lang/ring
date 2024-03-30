# Form/Window Controller - Source Code File

load "text2speechView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:text2speechController)
		exec()
	}
}

class text2speechController from windowsControllerParent

	oView = new text2speechView
	
	oView.LineEdit1.setText("Welcome to the Ring programming language")

	oView.TextEdit1.setText("The Ring is an innovative and practical general-purpose multi-paradigm language."+nl+
				"The supported programming paradigms are imperative, procedural, object-oriented,"+nl+
				"declarative using nested structures, functional, meta programming and natural programming.")

	func SayText 
		cText = oView.LineEdit1.text()
		Say(cText)
	
	func SayLongText
		cText = oView.TextEdit1.toPlainText()
		Say(cText)
	
	func say cText
		new qTextToSpeech(oView.win) {
			Say(cText)
		}
	
	func CloseApp
		oView.win.close()
