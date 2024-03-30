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
		new qfiledialog(this.oView.win) {
		cFile = getopenfilename(this.oView.win,"Select the First File"," ","*.txt")
		}
		try { 
			cString = read(cFile)
			oView {
				txtFile1.settext(cFile)
				txtFile1Content.settext(cString )
			}
		Catch 
		} 
	} 

	func SelectSecond  { 
		new qfiledialog(this.oView.win) {
		cFile = getopenfilename(this.oView.win,"Select the Second File"," ","*.txt")
		}
		try { 
			cString = read(cFile)
			oView {
				txtFile2.settext(cFile)
				txtFile2Content.settext(cString )
			}
		Catch 
		} 
	} 

	func Merge  { 
		oView {
			cOutput = ""
			cFile1 = txtFile1Content.toplaintext()
			cFile2 = txtFile2Content.toplaintext()
			aFile1 = str2list(cFile1)
			aFile2 = str2list(cFile2)
			for t = 1 to len(aFile1) step 1 { 
				cOutput += aFile1[t]+WindowsNL()
				if t < len(aFile2) { 
					cOutput += aFile2[t]+WindowsNL()
				}
			}
			txtMerge.settext(cOutput)
		}
	} 

	func savethefile  { 
		oView {
			cOutput = txtMerge.toplaintext()
			new qfiledialog(this.oView.win) {
			cFileName = getsavefilename(this.oView.win,"Save File"," ","*.txt")
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
