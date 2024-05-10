load "lightguilib.ring"
load "MergeView.ring"

import System.GUI

if isMainSourceFile() { 
	new App
	{
		StyleFusion()
		openWindow(:MergeController)
		exec()
	}
}

class MergeController from WindowsControllerParent

	oView = new MergeView

	oView {
		txtFile1.setenabled(False)
		txtFile2.setenabled(False)
	}

	func SelectFirst  { 
		new QFileDialog(this.oView.win) {
		cFile = getOpenFileName(this.oView.win,"Select the First File"," ","*.txt")
		}
		try { 
			cString = read(cFile)
			oView {
				txtFile1.setText(cFile)
				txtFile1Content.setText(cString )
			}
		Catch 
		} 
	} 

	func SelectSecond  { 
		new QFileDialog(this.oView.win) {
		cFile = getOpenFileName(this.oView.win,"Select the Second File"," ","*.txt")
		}
		try { 
			cString = read(cFile)
			oView {
				txtFile2.setText(cFile)
				txtFile2Content.setText(cString )
			}
		Catch 
		} 
	} 

	func Merge  { 
		oView {
			cOutput = ""
			cFile1 = txtFile1Content.toPlainText()
			cFile2 = txtFile2Content.toPlainText()
			aFile1 = str2list(cFile1)
			aFile2 = str2list(cFile2)
			for t = 1 to len(aFile1) step 1 { 
				cOutput += aFile1[t]+WindowsNL()
				if t < len(aFile2) { 
					cOutput += aFile2[t]+WindowsNL()
				}
			}
			txtMerge.setText(cOutput)
		}
	} 

	func savethefile  { 
		oView {
			cOutput = txtMerge.toPlainText()
			new QFileDialog(this.oView.win) {
			cFileName = getSaveFileName(this.oView.win,"Save File"," ","*.txt")
			}
			if trim(cFileName) != NULL { 
				write(cFileName,cOutput)
				msginfo("Great","Operation done!")
			}
		}
	} 

	func CloseApp  { 
		oView {
			win.close()
		}
	} 
