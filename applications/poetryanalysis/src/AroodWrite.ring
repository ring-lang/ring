load "aExpressions.ring"

TestingAroodWrite = false
#2
Haa_Dmh = ex.Haa + ex.Dammah
Haa_Dmh_EdgEx = new Expression(Haa_Dmh + ex.Edge, 1)
Haa_WawRep = Haa_Dmh + ex.Waw

#3
Haa_Ksrh = ex.Haa + ex.Kasrah
Haa_Ksrh_EdgEx = new Expression(Haa_Ksrh + ex.Edge, 1)
Haa_YaaRep = Haa_Ksrh + ex.Yaa

#4
Taa5_SokonEx = new Expression(ex.Taa5 + ex.Sokon, 1)
Haa_SokonRep = ex.Haa + ex.Sokon

#5
Taa5Ex = new Expression(ex.Taa5, 1)


#-------------------حالات الألف-----------------------
#6
maybeSokon = ex.Maybe(ex.Sokon)
WawGama3ah = ex.LookBack(1, "B4WawGama3ah") + 
		ex.Waw + maybeSokon + ex.Aleph + maybeSokon + ex.Edge
WawGama3ahEx = New Expression(WawGama3ah, 1)
WawGama3ahRep = ex.Waw + ex.Var(2)

#7
W_AEx = New Expression(ex.Waw + ex.Aleph + ex.Edge, 1)
W_Fat7a_ARep = ex.Waw + ex.Fat7ah + ex.Aleph

#8
A_SokonEx = new Expression(ex.Aleph + ex.Sokon + ex.Edge, 1)


Al_MaybeSokon = ex.AL + maybeSokon
shmsy = ex.Validate(1, "Shams")
shmsy_Shdh = shmsy + ex.Shaddah
Al_shmsy_Shdh = Al_MaybeSokon + shmsy_Shdh

#9
Edg_Al_shmsy_ShdhEx = new Expression(ex.Edge + Al_shmsy_Shdh, 1)
FkkShdhRep = ex.Expand(2)
A_FkkShdhRep = ex.Aleph + FkkShdhRep
AHmz_FkkShdhRep = ex.AlephHmz + FkkShdhRep

#10
Edg_Al_MaybeSokon = ex.Edge + Al_MaybeSokon
shmsyNoTaa = ex.Validate(1, "ShamsNoTaa")
Edg_AL_ShmsyNotTaaEx = new Expression(Edg_Al_MaybeSokon + shmsyNoTaa, 1)


#11
Al_shmsy_ShdhEx = new Expression(Al_shmsy_Shdh, 1)


#12
Al_SokonRep = ex.AL + ex.Sokon
maybeShdh = ex.Maybe(ex.Shaddah)
ShmsyMaybeShdh = shmsyNoTaa + maybeShdh
AL_Sokon_ShmsyEx = new Expression(Al_SokonRep + ShmsyMaybeShdh, 1)
FkkShmsyRep = ex.Expand(1)

#13
Edg_Al_MaybeSokonEx = new Expression(Edg_Al_MaybeSokon, 1)
L_Sokon = ex.Lam + ex.Sokon
AHmz_L_SokonRep = ex.AlephHmz + L_Sokon

#14
ifCanAddSokon = ex.LookForward(2, "CanAddSokon")
A_Hrf = ex.Aleph + ex.Any 
A_Hrf_NoTsh = A_Hrf + ifCanAddSokon
Edg_A_HrfEx = new Expression(ex.Edge + A_Hrf_NoTsh, 1)

HrfSakenRep = ex.var(1) + ex.Sokon
A_HrfSakenRep = ex.Aleph + HrfSakenRep
E_HrfSakenRep = ex.AlephMaksor + HrfSakenRep

#15
Edg_AEx = new Expression(ex.Edge + ex.Aleph, 1)


#-------------------حالات اللام-----------------------
#16
LL = ex.Lam + ex.Maybe([ex.Fat7ah, ex.Kasrah]) + ex.Lam
LL_Sokon_ShmsyEx = new Expression(LL + ex.Sokon + shmsy + maybeShdh, 1)
L_FkkShmsyRep = ex.Lam + ex.Expand(3)

#17
LL_MayBeSokon = LL + ex.Maybe(ex.Sokon)
LL_shmsy_ShdhEx = new Expression(LL_MayBeSokon + shmsy_Shdh, 1)
L_FkkShdhRep = ex.Lam + ex.Expand(4)

#18
bwadee= ex.Maybe([ex.AlephHmz, ex.Faa, ex.Waw])
Edg_Atf_LL_shmsy = new Expression(ex.Edge + bwadee + 
		LL_MayBeSokon + ex.LookForward(2, "IsShamsy") + 
		ex.Any + maybeShdh, 1)

Atf_LRep = ex.var(1) + ex.var(2) + ex.var(3) + ex.Lam 
Atf_L_FkkShdhRep = Atf_LRep + ex.Expand(8)

#19
Edg_Atf_LLEx = new Expression(ex.Edge + bwadee + LL + ifCanAddSokon, 1)
Atf_LL_SokonRep = Atf_LRep + L_Sokon 

#------------------------------------------------------------
#20
Fat7ah_WawYaa = ex.Fat7ah + ex.OneOf([ex.Waw, ex.Yaa])
Fat7ah_WawYaaEx = New Expression(Fat7ah_WawYaa + ex.LookForward(1, "AfterWaw"), 1)
Fat7ah_WawYaaRep = ex.Fat7ah + ex.var(1) + ex.Sokon

#-----------------------حالات الا و للا--------------------------
#21
maybeA_L_Sokon = ex.Maybe(ex.Aleph) + L_Sokon
L_Sokon_A_Hrf = maybeA_L_Sokon + ex.Aleph + ex.Any
maybeA_L_Sokon_A_SakenEx = new Expression(L_Sokon_A_Hrf + ex.Sokon, 1)
L_Kasrah_HrfSakenRep = ex.Lam + ex.Kasrah + ex.Var(2) + ex.Sokon

#22
maybeA_L_Sokon_A_HrfEx = new Expression(L_Sokon_A_Hrf  + ifCanAddSokon, 1)

#------------------------------------------------------------
#23
Hrf_ShdhEx = New Expression(ex.Any + ex.Shaddah, 0)
Hrf_Sokon_HrfRep = ex.Expand(1)

#24
NotEdg_A_Saken_NotEdgEx = new Expression(ex.NotEdge + A_Hrf + ex.Sokon + ex.NotEdge, 0)


#--------------------------التنوين------------------------------
#25
tnwn_AlephEx = new Expression(ex.TanweenFat7 + ex.Aleph, 1)
Ft7h_Noon_SokonRep = ex.Fat7ah + ex.Noon + ex.Sokon

#26
Aleph_tnwnEx = new Expression(ex.Aleph + ex.TanweenFat7, 1)


#27
tnwn_LeenEx = new Expression(ex.TanweenFat7 + ex.AlephLeen, 1)

#28
Leen_tnwnEx = new Expression(ex.AlephLeen + ex.TanweenFat7, 1)

#29
tnwnFt7Ex = new Expression(ex.TanweenFat7, 1)

#30
tnwnDmEx = new Expression(ex.TanweenDamm, 1)
Dmh_Noon_SokonRep = ex.Dammah + ex.Noon + ex.Sokon

#31
tnwnKsrEx = new Expression(ex.TanweenKasr, 1)
Ksrh_Noon_SokonRep = ex.Kasrah + ex.Noon + ex.Sokon

#-------------------------------------------------

Func AroodWrite(words)
	L = len(words)
	DoAroodWrite(words[1], 1)
	
	for i = 2 to L
		DoAroodWrite(words[i], 0)
		
		// Note: حالات التقاء ساكن في نهاية كلمة بساكن في بداية الكلمة التالية

		if words[i][1] = ex.Aleph
			lastWordId = i - 1
			lastWord = words[lastWordId]
			lastWordLen = lastWord.Length
			endOfLastWord = lastWord[lastWordLen]
			Harakah = ""

			switch endOfLastWord
				case ex.Waw
					if not (lastWordLen > 3 and lastWord.EndsWith("وْو"))
						Harakah = ex.Dammah
					end
				case ex.Yaa
					if not (lastWordLen > 3 and lastWord.EndsWith("يْي"))
						Harakah = ex.Kasrah
					end
				case ex.Aleph
					# Note يا الله
					if (lastWord.EndsWith("يا") or lastWord.EndsWith("يَا")) And words[i].StartsWith("الْلاه")
						words[i].SetCharAt(1, "أ")
						loop
					else
						Harakah = ex.Fat7ah
					end
				case ex.AlephLeen
					Harakah = ex.Fat7ah
				case ex.Sokon
					if lastWord = "مِنْ" or lastWord = "ومِنْ" or lastWord = "فمِنْ"
						Harakah = ex.Fat7ah
					elseif lastWord[lastWordLen - 1] = ex.Waw
						Harakah = ex.Dammah
					else
						Harakah = ex.Kasrah
					end
			EndSwitch

			if Harakah != ""
				//Note: لا نستطيع إضافة تشكيل بدلا من الواو أو الياء أو الألف لوجود تشكيل بالفعل على الحرف السابق
				if IsTashkeel(lastWord[lastWordLen - 1])
					words[lastWordId].Delete(lastWordLen, 1)
				else // تحويل الواو إلى ضمة والياء إلى كسرة والألف إلى فتحة
					words[lastWordId].SetCharAt(lastWordLen, Harakah)
				end
			end

			if words[i].Length = 1
				words[i].Delete(1, 1) // حذف الألف 
			else
				//Note نقل الحرف الساكن الذي يلي الألف إلى الكلمة السابقة
				words[lastWordId].Append(words[i].Mid(2, 2))
				words[i].Delete(1, 3) // حذف الألف والحرف الساكن الذي يليه
			end

		end
	next
EndFunc

Func DoAroodWrite(word, wordNum)
	If word = "و" 
 		word.Append(ex.Fat7ah)
		return word
	end
		
	CanHaveTanween = True
	// Note: إشباع الهاء
	if word[word.Length -1] = ex.Haa and
			(Haa_Dmh_EdgEx.Replace(word, Haa_WawRep) or 
			 Haa_Ksrh_EdgEx.Replace(word, Haa_YaaRep))
		CanHaveTanween = False	
	end

	// Note: التاء المربوطة
	if Taa5_SokonEx.Replace(word, Haa_SokonRep)			
		CanHaveTanween = False	
	else	
		Taa5Ex.Replace(word, ex.Taa)
	end

	if word.IndexOf(ex.Aleph, 1)
		if WawGama3ahEx.Replace(word, WawGama3ahRep)
			CanHaveTanween = False
		end

		// Note إضافة فتحة بعد الواو التي تليها ألف في نهاية الكلمة
		if W_AEx.Replace(word, W_Fat7a_ARep)
			CanHaveTanween = False
		end

		# Note ألف لا تنطق مثل أناْ
		A_SokonEx.Replace(word, ex.Fat7ah)
	
		//Note: حرف شمسي مشدد بعد أل 
		_A = Select(wordNum = 1, AHmz_FkkShdhRep, A_FkkShdhRep)
		if Edg_Al_shmsy_ShdhEx.Replace(word, _A)
			CanHaveTanween = False

		// Note الحروف الشمسيثة
		elseIf Edg_AL_ShmsyNotTaaEx.Replace(word, _A)
			CanHaveTanween = False

		// Note قد تسبق بعض البوادئ ال المشددة
		ElseIf Al_shmsy_ShdhEx.Replace(word, FkkShdhRep)
			CanHaveTanween = False

		
		//Note ال ساكنة تسبقها بوادئ بعدها حرف شمسي
		elseif AL_Sokon_ShmsyEx.Replace(word, FkkShmsyRep)
			CanHaveTanween = False

		// Note فك اللام القمرية في بداية الكلمة
		// Note الألف مفتوح
		else
			_AlRep = Select(wordNum = 1, AHmz_L_SokonRep, Al_SokonRep)
			if Edg_Al_MaybeSokonEx.Replace(word, _AlRep)
				CanHaveTanween = False
			else
				// Note إضافة سكون على أي حرف يلي الألف في بداية الكلمة
				// Note الألف مكسور
				_AlephRep = Select(wordNum = 1, E_HrfSakenRep, A_HrfSakenRep)
				if not Edg_A_HrfEx.Replace(word, _AlephRep)
					_A = Select(wordNum = 1, ex.AlephMaksor, ex.Aleph)
					// Note: تحويل الألف إلى همزة في بداية الكلمة لو كانت أول كلمة في الجملة
					Edg_AEx.Replace(word, _A)
				end
			end
		end
	end

	if word.IndexOf(ex.lam, 1) and
		( LL_Sokon_ShmsyEx.Replace(word, L_FkkShmsyRep) or
		  LL_shmsy_ShdhEx.Replace(word, L_FkkShdhRep) or
		  Edg_Atf_LL_shmsy.Replace(word, Atf_L_FkkShdhRep) or
		  Edg_Atf_LLEx.Replace(word, Atf_LL_SokonRep) )
		CanHaveTanween = False
	end

	Fat7ah_WawYaaEx.Replace(word, Fat7ah_WawYaaRep)



	// Note: لو كنا عالجنا حالات ال و لل فقد يليها ألف مثل الاستثناء
	// Note: سنكسر اللام ونضيف سكون على الحرف التالي لها إن لم يكن مشكلا
	If maybeA_L_Sokon_A_SakenEx.Replace(word, L_Kasrah_HrfSakenRep) Or
			maybeA_L_Sokon_A_HrfEx.Replace(word, L_Kasrah_HrfSakenRep)
		CanHaveTanween = False
	end

	Hrf_ShdhEx.Replace(word, Hrf_Sokon_HrfRep)

	// Note حذف أي ألف وسط الكلمة بعدها حرف ساكن
	NotEdg_A_Saken_NotEdgEx.Replace(word, HrfSakenRep)

	if CanHaveTanween
		if not ( Tnwn_AlephEx.Replace(word, Ft7h_Noon_SokonRep) or
				Aleph_TnwnEx.Replace(word, Ft7h_Noon_SokonRep) or
				Tnwn_LeenEx.Replace(word, Ft7h_Noon_SokonRep) or
				Leen_TnwnEx.Replace(word, Ft7h_Noon_SokonRep) or
				TnwnFt7Ex.Replace(word, Ft7h_Noon_SokonRep) or
				TnwnDmEx.Replace(word, Dmh_Noon_SokonRep) )
		
			TnwnKsrEx.Replace(word, Ksrh_Noon_SokonRep) 
		end
	end

	if TestingAroodWrite return word end
EndFunc

Func ShamsNoTaa(str)
	hrf = str.Text	
	// Note: استثناء التاء لمراعاة صيغة افتعل مثل التبس والتمس
	return hrf != "ت" And find(ex.shamsiah, hrf)
EndFunc

Func Shams(str)
	return find(ex.shamsiah, str.Text)
EndFunc

func IsShamsy(str)
	L = str.Length
	if L < 2 // اللام أو الحرف التالي لها  آخر حرف في الكلمة
		return false
	elseif IsTashkeel(str[1])  // تشكيل على اللام غير السكون
		return false
	elseIf str[2] = ex.Shaddah // حرف شمسي عليه شدة
		return find(ex.shamsiah, str[1])
	elseIf IsTashkeel(str[2]) // حرف شمسي عليه تشكيل آخر، يشير إلى أن اللام حرف أصلي في الكلمة وليست للتعريف
		return False
	else // الآن نحن متأكدون أننا نتعامل مع حرفين على الأقل بعد لل، وأن كلا منهما ليس تشكيلا
		return find(ex.shamsiah, str[1])
	end	
EndFunc

Func CanAddSokon(str)
	L = str.Length
	if L = 0
		return true
	elseif IsTashkeel(str[1])
		return false
	elseIf L = 1
		return true
	elseIf str[2] = ex.Sokon or str[2] = ex.Shaddah
		return False
	else
		return true
	end	
EndFunc

Func B4WawGama3ah(str)
	if str = "" return false end
	
	hrf = str[1]
	if hrf = ex.Kasrah or hrf = ex.Sokon
		return false
	else
		return true
	end
EndFunc

Func AfterWaw(str)
	if str = "" return true end
	
	hrf = str[1]
	If hrf = ex.Aleph or IsTashkeel(hrf)
		return false
	else
		return true
	end
EndFunc