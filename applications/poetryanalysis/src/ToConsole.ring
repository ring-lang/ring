Load "Analyzer.ring"


ToConsole("هلّا سألْت القوم يا ابنة مالكٍ
إن كنْت جاهلةً بما لمْ تعْلمي"
)
	

Func ToConsole(Qaseedah)
	new Analyzer(Qaseedah) {
		bCount = len(QBohor)
		n = 1
		bahrName = ""
		If bCount = 0
			see "لا يوجد بحر" + nl
		Else
			if bCount > 1
				see "البحور المحتملة:" + nl
				for i = bCount to 1 step -1
					bhr = QBohor[i]
					bId = bhr[1]
					? "" + n + "-" +  BohorInfo[bID][:Name] + 
						" (" + 100 * (bhr[2] / ShatraatCount) + "%)"
					n++
				next
		
				see "اكتب رقم البحر الذي تريد تقطيع القصيدة عليه، "
				see " أو اكتب نصا فارغا أو الرقم صفر لإنهاء البرنامج" + nl			
				n = GetANumber(bCount)
				if n = 0 return end
			EndIf
		
			i = bCount - n + 1
			bID = QBohor[i][1]
			
			bahrName = BohorInfo[bID][:Name]
			txt = "تقطيع القصيدة على البحر "
			? txt + bahrName
		EndIf
	
		for shInfo in ShataraatInfo

			txt = "الشطرة: "
			? txt + shInfo[:Shatrah].Text
			if bCount = 0 
				txt =  "الكتابة العروضية: "
				? txt + Join(shInfo[:AroodWrite], " ")
				Loop
			End

			tafs = GetTafs(shInfo[:Taqtee3], bID)
			if isNull(tafs)
				see "هذه الشطرة غير موزونة على بحر " + bahrName + nl
				txt =  "الكتابة العروضية: "
				? txt + Join(shInfo[:AroodWrite], " ")
			else
				txt = "التقطيع: "
				tafLens = tafs[:Lens]2
				shTaqtee3 = shInfo[:Romooz].Horoof(tafLens)
				? txt + Join(shTaqtee3, " - ")
				txt = "الرموز : "
				romooz = shInfo[:Romooz].Harakaat(tafLens)
				? txt + Join(romooz, " - ")
				txt = "التفعيلات: "
				? txt + Join(tafs[:Names], " - ")
			end
			? "---------------"
		next
	}
EndFunc

Func GetANumber(limit)
	while true
		Give n
		n = number(n)
		if n = 0
			put "تم إنهاء البرنامج" + nl
			return 0
		elseif n <= limit
			return n
		else
			see " أدخل عددا صحيحا بين 1 و" + limit + nl
		EndIf
	EndWhile
EndFunc




