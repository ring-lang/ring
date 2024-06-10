load "aString.ring"
load "SpWords.ring"
load "AroodWrite.ring"
load "Romooz.ring"
load "Taqtee3.ring"


Class Analyzer
	ShatraatCount = 0
	ShataraatInfo = []
	QBohor = []
	
	
	func init(strQaseedah)
		if isaString(strQaseedah)
			Qaseedah = strQaseedah
		else
			Qaseedah = new aString(strQaseedah)
		end

		shataraat = Qaseedah.GetLines()
		ShatraatCount = Len(shataraat)
		if ShatraatCount = 0 return End

		ShataraatInfo = list(ShatraatCount)
		for i = 1 to ShatraatCount		
			shatrah = shataraat[i]
			words = shatrah.GetWords()
			FixSpWords(words)
			AroodWrite(words)
			shatrahRomooz = new Romooz(words, true)
			TaqTee3 = GetTaqtee3(shatrahRomooz.ToString())
	
			ShataraatInfo[i] = [
				:Shatrah = shatrah,
				:AroodWrite = words,
				:Romooz = shatrahRomooz,
				:TaqTee3 = TaqTee3
			]
		next
	
		AnalyzeBohor()
		Return Self
	EndFunc


	Func GetTafs(shInfo, bahrId)
		for taqtee3 in shInfo
			bId = Find(taqtee3[:Bohor], bahrId)
			if bId > 0
				TafLens = []
				TafNames = []
				For tafId in taqtee3[:Tafs]
					TafLens + len(TafsInfo[tafId][1])
					TafNames + TafsInfo[tafId][:Name] 
				next
				Return [:Lens = TafLens, :Names = TafNames]
			end		
		next
	EndFunc
	

private
	Func AnalyzeBohor()
		for shInfo in ShataraatInfo
			shBohor = GetShBohor(shInfo)
			for bahr in shBohor
				index = find(QBohor, bahr, 1)
				if index = 0
					QBohor + [bahr, 1]
				else
					QBohor[index][2] += 1
				end
			next 
		next shInfo
	
		QBohor = sort(QBohor, 2)
	EndFunc

	
	Func GetShBohor(shInfo)
			shBohor = []
			for taqtee3 in shInfo[:Taqtee3]
				for bahr in taqtee3[:Bohor]
					if not find(shBohor, bahr)
						shBohor + bahr
					end
				next
			next
			return shBohor
	EndFunc
EndClass
