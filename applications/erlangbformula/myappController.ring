#====================================================#
# Erlang B Formula
# 2020, Mahmoud Fayed <msfclipper@yahoo.com>
#====================================================#

load "myappView.ring"
load "functions.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:myappController)
		exec()
	}
}

class myappController from windowsControllerParent

	oView = new myappView

	# Set the Default Values
		oView {
			textN.setText("32")
			textAMin.setText("20")
			textAMax.setText("40")
			textStep.setText("1")
		}

	calculate()
		
	func calculate
		oView {
			# Get the Input
				N = Number( textN.text() )
				AMin = Number( textAMin.text() )
				AMax = Number( textAMax.text() )
				CounterStep = Number( textStep.text() )
			# Check the Input
				if N < 1 N=1 textN.setText("1") ok
				if CounterStep < 1 CounterStep=1 textStep.setText("1") ok
				if AMax < AMin AMax=AMin textAMax.setText(""+AMin) ok
			# Process 
				aData = Table_ABJKQ(N,AMin,AMax,CounterStep)
			# Display the Output
				TableWidget1.setrowcount(len(aData))
				for t=1 to len(aData)
					aRow = aData[t]
					for t2=1 to len(aRow)
						 item1 = new qtablewidgetitem(String(aRow[t2]))
	           TableWidget1.setitem(t,t2,item1)
					next
				next
			}
	
	func closeApp
		oView.win.close()
