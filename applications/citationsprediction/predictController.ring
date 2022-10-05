#=====================================================#
# Citations Prediction Application
# 2022, Mahmoud Fayed <msfclipper@yahoo.com>
#=====================================================#

load "lightguilib.ring"
load "predictView.ring"
load "datasetController.ring"
load "azure.ring"

import System.GUI

if IsMainSourceFile() { 
	oApp = new App
	{
		StyleFusion()
		openWindow(:predictController)
		exec()
	}
} 

class predictController from windowsControllerParent

	oView = new predictView

	func closeApp  { 
		oView {
			win.close()
		}
	} 

	func predict  { 
		cOutput = ""
		oView {
			txtOutput.setText("Please wait...")
			oApp.processevents()
			# Get Input
				cTitle = txtTitle.text()
				cAuthors = txtAuthors.text()
				cAbstract = txtAbstract.toplaintext()
			# Prepare Output.
				cOutput += "Prediction Results:"+nl
				new Azure
				{
					C_MINSIZE = 5
					decimals(0)
					if len(trim(cTitle)) >= C_MINSIZE { 
						cOutput += "Prediction using title : " + setPaperTitle(cTitle) + " citations " + nl
						else 
							cOutput += "No Paper Title!"+ nl
					}
					if len(trim(cAuthors)) >= C_MINSIZE { 
						cOutput += "Prediction using Authors : " + setPaperAuthors(cAuthors)  + " citations " +nl
						else 
							cOutput += "No Paper Authors!"+ nl
					}
					if len(trim(cAbstract)) >= C_MINSIZE { 
						cOutput += "Prediction using Abstract : " + setPaperAbstract(cAbstract)  + " citations " + nl
						else 
							cOutput += "No Paper Abstract!"+ nl
					}
				}
			txtOutput.setText(cOutput)
		}
	} 

	func select  { 
		openWindowAndLink(:DataSetController,self)
	} 

	func clear  { 
		oView {
			txtAbstract.setText("")
			txtOutput.setText("")
			txtTitle.settext("")
			txtAuthors.settext("")
		}
	} 
