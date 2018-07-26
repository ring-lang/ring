# Form/Window Controller - Source Code File

load "unicodecharView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:unicodecharController)
		exec()
	}
}

class unicodecharController from windowsControllerParent

	oView = new unicodecharView

	func printchar
		cText = oView.LineEdit1.text()
		# Create the string object 
			oString = new qString()
		# Add the character to the string 
			oString.append(cText)
		# Get unicode value (As QChar)
			cUniCode = oString.Unicode()
			nUniCode = cUniCode.unicode()
		# Convert QChar to Numeric Value (Decimal)
			? "Unicode Character (Decimal Value) : " + nUniCode
			? "Unicode Character (Hex. Value)    : " + oString.number(nUniCode,16)
			? "Unicode Character (Bin. Value)    : " + oString.number(nUniCode,2)
