load "aString.ring"

Then = 0

class Romooz
	Harakaat = []
	Horoof = []	

	Func init(words, eshbaa3)
		L = len(Words)
		hL = 0

		For i = 1 To L
			word = Words[i]
			wordLen = Len(word)
			hrf = ""
			nextHrf = word[1]								
				
			For j = 1 To wordLen
				prevHrf = hrf
				hrf = nextHrf
				if j = wordLen
					nextHrf = ""
				else
					nextHrf = word[j + 1]
				end

				If hrf = Letters.HamzetMadd
					Horoof + hrf + ""
					Harakaat + "|" + "0"

				ElseIf hrf = Letters.Fat7ah or hrf = Letters.Kasrah or hrf = Letters.Dammah or hrf = Letters.Sokon
					n = Len(Horoof)
					Horoof[n] += hrf
						 
				ElseIf hrf = Letters.Aleph or NextHrf = Letters.Sokon
					Horoof + hrf
					Harakaat + "0"

				ElseIf hrf = Letters.AlephLeen or hrf = Letters.Yaa or hrf = Letters.Waw
					Horoof + hrf
					If j = 1 or Harakaat[Len(Harakaat)] = "0" or
						nextHrf = Letters.Fat7ah or nextHrf = Letters.Dammah or nextHrf = Letters.Kasrah or nextHrf = Letters.Aleph or nextHrf = Letters.Waw or nextHrf = Letters.Yaa or nextHrf = Letters.AlephLeen
						Harakaat + "|"

					ElseIf j < WordLen - 1 and Word[j + 2] = Letters.Sokon
						If i = L And j + 2 = Wordlen
							Harakaat + "0"
						Else
							Harakaat + "|"
						End

					Else
						Harakaat + "0"
					End

				Else
					Horoof + hrf
					Harakaat + "|"                   
				End
			Next j

			Horoof + " "
			Harakaat + " "

			hL2 = len(Harakaat)
			originalLengths + (hL2 - hL - 1)
			hL = hL2
		Next i

		del (Horoof, Len(Horoof))
		L = Len(Harakaat)
		del (Harakaat, L)
		L--

		//Note إشباع الحركة الأخيرة
		If eshbaa3 and Harakaat[L] = "|"
			Switch hrf
				case Letters.Fat7ah 
					Horoof + "ا"
				case Letters.Kasrah 
					Horoof + "ي"
				case Letters.Dammah
					Horoof + "و"
				else
					Horoof + ""
			EndSwitch
			Harakaat + "0"
		End
	EndFunc

	Func Horoof(lengthes)
		return split(Horoof, lengthes)
	EndFunc

	func Harakaat(lengthes)
		return split(Harakaat, lengthes)
	EndFunc

	Func GetOrgHarakaat( )
	   return split(Harakaat, originalLengths)
	EndFunc

	Func ToString()
		result = ""
		L = len(Harakaat)
		for i = 1 to L
			h = Harakaat[i]
			if h != " " 
				result += h
			end
		next
		return result
	EndFunc

Private
	originalLengths = []

	func Split(list, parts)
		L = len(list)
		partsCount = Len(parts)
		result = []
		i = 1

		for j = 1 to partsCount
			count = 1
			part = ""
			partLen = parts[j]

			While count <= partLen
				if i > L 
					if item != ""
						result + part
					end
					exit 2
				end
								
				if list[i] = " "
					if count > 1
						part += list[i] 
					end
				else
					part += list[i]
					count++
				end
				i++
			EndWhile

			if part != ""
				result + part	
			end
		next

		return result 
	EndFunc
EndClass
