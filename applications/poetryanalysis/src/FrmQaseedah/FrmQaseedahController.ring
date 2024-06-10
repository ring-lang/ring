# Form/Window Controller - Source Code File

load "FrmQaseedahView.ring"
load "../Analyzer.ring"

import System.GUI

if IsMainSourceFile()
	ShowfrmQaseedah()
EndIf


Func ShowfrmQaseedah()
	new App {
		StyleFusion()
		openWindow(:frmQaseedahController)
		exec()
	}
EndFunc


class frmQaseedahController from windowsControllerParent

	oView = new frmQaseedahView
	win = oView.win
	txtQaseedah = oView.txtqaseedah
	cmbBohoor = oView.cmbBohoor
	lstShataraat = oView.lstShataraat
	txtDetails = oView.txtDetails
	results

	win.setlayoutdirection(1)

	txtQaseedah.setText("هلّا سألْت القوم يا ابنة مالكٍ"+nl+"إن كنْت جاهلةً بما لمْ تعْلمي")

	Func btnExecute_Click()
		results = new Analyzer(txtQaseedah.ToPlainText())	
		cmbBohoor.Clear()
		lstShataraat.Clear()
		txtDetails.Clear()

		bCount = len(results.QBohor)
		if bCount = 0
			cmbBohoor.AddItem("لا يوجد بحر", 0)		
		else
			for i = bCount to 1 step -1
				bhr = results.QBohor[i]
				bId = bhr[1]
				cmbBohoor.AddItem(BohorInfo[bID][:Name] + 
					" (" + 100 * (bhr[2] / results.ShatraatCount) + "%)", 0)
			next
		
		EndIf
	EndFunc


	Func cmbBohoor_IndexChanged()		
		lstShataraat.Clear()
		txtDetails.Clear()

		if cmbBohoor.currentIndex() < 0 return end		

		for shInfo in Results.ShataraatInfo
			lstShataraat.AddItem(Join(shInfo[:AroodWrite], " "))			
		next
		lstShataraat.SetCurrentRow(0, 0)
	EndFunc


	Func lstShataraat_ItemChanged()
		txtDetails.Clear()
		index = lstShataraat.CurrentRow() + 1
		if index < 1 return end
		shInfo = results.ShataraatInfo[index]

		bCount = len(results.QBohor)
		if bCount = 0
			txtDetails.SetText("هذه الشطرة غير موزونة على أي بحر " +
				 nl + "الرموز : " +
				Join(shInfo[:Romooz].GetOrgHarakaat(), " ")
			)
			return
		EndIf

		i = bCount - cmbBohoor.currentIndex()
		bID = results.QBohor[i][1]


		tafs = results.GetTafs(shInfo[:Taqtee3], bID)
		if isNull(tafs)
			txtDetails.SetText("هذه الشطرة غير موزونة على بحر " +
				BohorInfo[bID][:Name] + nl + "الرموز : " +
				Join(shInfo[:Romooz].GetOrgHarakaat(), " ")
			)
		else
			shTaqtee3 = shInfo[:Romooz].Horoof(tafs[:Lens])
			txtDetails.Append("التقطيع: " + Join(shTaqtee3, " - "))

			romooz = shInfo[:Romooz].Harakaat(tafs[:Lens])
			txtDetails.Append("الرموز : " + Join(romooz, " - "))

			txtDetails.Append("التفعيلات: " + Join(tafs[:Names], " - "))
		end		
	EndFunc

EndClass
