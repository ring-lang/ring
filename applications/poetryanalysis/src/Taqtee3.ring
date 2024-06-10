load "AroodInfo/TafsInfo.ring"
load "AroodInfo/BohorInfo.ring"

func GetTaqtee3(strHarakaat)
	t = new Taqtee3Class(strHarakaat)
	return t.Taqtee3
EndFunc


Class Taqtee3Class
	Taqtee3 = []

	func init(strHarakaat)
		harakaat = strHarakaat
		hL = len(harakaat)
		GetTafs(1)
	EndFunc

		
 private 

	harakaat
	hL
	Tafs = []
	probBohor = []


	func GetTafs(startAt)
		minTafLen = 4
		maxTafLen = hL - startAt + 1
		if maxTafLen > 9
			maxTafLen = 7
		elseif maxTafLen < 4
			minTafLen = maxTafLen
		end

		for TafLen = minTafLen to maxTafLen
			endAt = startAt + TafLen - 1
			if endAt < hL and harakaat[endAt + 1] = "0" Loop End

			rmz = subStr(harakaat, startAt, TafLen)
			tafID = find(TafsInfo, rmz, 1)
			if tafID = 0 Loop End

			lastTaf = (endAt = hL)
			tafPos = len(Tafs) + 1
			if not lastTaf
				if tafID = 47 
					if tafPos > 1 Loop end
				elseif tafID > 24
					Loop
				end
			end

			if not HasBahr(tafID, tafPos, lastTaf) Loop End
		
			Tafs + tafID
			if lastTaf
				Taqtee3 + [
								:Tafs = Tafs, 
								:Bohor = probBohor[Len(probBohor)]
							 ]
			else
				GetTafs(endAt + 1)
			end

			del(Tafs, tafPos)
			del(probBohor, Len(probBohor))
		next

	EndFunc
				

	func HasBahr(tafID, tafPos, lastTaf)
		probBohor + []
		L = Len(probBohor)

		if tafID < 25
			Intersect(TafsInfo[tafID], tafPos, L)
		end

		if lasttaf
			//Note: قد تكون التفعيلة العادية ناتجة عن علة
			CheckEllaTafs(TafsInfo[tafID][:EllaOf], tafpos, L)				
		end

		//Note التفعيلة الأةلى قد تكون أيضا الأخيرة لهذا فالشرطان غير مرتبطين
		if tafPos = 1
		    kharmTaf = TafsInfo[tafID][:KharmOf]
		    if kharmTaf!= ""
		        Intersect(TafsInfo[kharmTaf], 1, L)
		    end
		end

		if len(probBohor[L]) = 0
			del(probBohor, L)
			return false
		else
			return true
		end
	EndFunc


	func CheckEllaTafs(ellaTafs, tafpos, L)
		tL = len(ellaTafs)
		for i = 1 to tL
			ellaTaf = ellaTafs[i]
			Intersect(TafsInfo[ellaTaf], tafPos, L)
		next
	EndFunc


	func Intersect(TafInfo, tafPos, L)
		AddToProbBohor(TafInfo[:BahrAllN], L)

		If TafPos % 2 = 1
			AddToProbBohor(TafInfo[:BahrN21], L)
		Else
			AddToProbBohor(TafInfo[:BahrN20], L)
		EndIf
	
		Switch TafPos % 3
			Case 1
				AddToProbBohor(TafInfo[:BahrN31], L)
			Case 2
				AddToProbBohor(TafInfo[:BahrN32], L)
			Else
				AddToProbBohor(TafInfo[:BahrN30], L)
			EndSwitch
	EndFunc


	func AddToProbBohor(bohor, L)
		bL = len(bohor)
		for i = 1 to bL
			bahr = bohor[i]
			if (L = 1 or Find(probBohor[L - 1], bahr) > 0) and 
				Find(probBohor[L], bahr) = 0
					probBohor[L] + bahr
			end
		next
	EndFunc


	func ShowResults()
		L = len(Tafs)
		result = ""
		for i = 1 to L
			result += TafsInfo[Tafs[i]][:Name] + " "
		next
		? result

		bohor = probBohor[Len(probBohor)]
		for bahrId in bohor
			? BohorInfo[bahrId][:Name]
		next
		? "------------"
	EndFunc
