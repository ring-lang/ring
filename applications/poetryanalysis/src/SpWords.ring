Load "aString.ring"

prefixes = [
   ["و", "ف", "أ", "ب", "ك", "ل"], 
   ["فو", "وأ", "وب", "وك", "ول", "فأ", "فب", "فك", "فل", "أو", "أف", "أب", "أك", "أل"], 
   ["أفب", "أفك", "أفل", "أوب", "أوك", "أول"]  
]

Suffixes = [
["ي", "هُ", "ك"],
["نا", "همْ", "هنّ", "كمْ", "كنّ"],
["هما", "كما"]
]

AbsSuffixes = [
["ي", "ه", "ك"],
["نا", "هم", "هن", "كم", "كن"],
["هما", "كما"]
]

RelativeSuffixes = [
["يّ", "ىّ"],
["يّة", "يّا", "يُّو", "يّي"],
["يّان", "يّون", "يّين", "يّتا", "يّتَيْ", "يّات"],
["يّتان", "يّتَيْن"]
]

AbsRelativeSuffixes = [
["ي", "ى"],
["ية", "يا", "يو", "يي"],
["يان", "يون", "يين", "يتا", "يتي", "يات"],
["يتان", "يتين"]
]

_sp1 = ["لذ",
   [False, "الذي", "الْلذي"],
   [False, "الذى", "الْلذي"],
   [False, "الذين", "الْلذين"]
]

_sp2 = ["لت",
   [False, "التي", "الْلتي"],
   [False, "التى", "الْلتي"]
]

_sp3 = ["لله",
   [False, "الله", "الْلاه"],
   [False, "اللهم", "الْلاهمّ"]
]

_sp4 = ["أول",
   [False, "أولئك" ,"أُلائِك"],
   [False, "أولئكم" ,"أُلائِكمْ"],
   [False, "أولاء", "أُلاء"],
   [False, "أولات", "أُلات"],
   [False, "أولو", "أُلو"],
   [False, "أولي", "أُلي"]
]

_sp5 = ["هذ",
   [False, "هذا", "هاذا"],
   [False, "هذه", "هاذِهِ"],
   [False, "هذان", "هاذان"],
   [False, "هذين", "هَاذَيْن"],
   [False, "هذي", "هَاذِي"]
]

_sp6 = ["ذلك",
   [False, "ذلك", "ذَالِك"],
   [False, "ذلكما", "ذَالِكما"],
   [False, "ذلكم", "ذَالِكمْ"],
   [False, "ذلكن", "ذَالِكنّ"]
]

_sp7 = ["هأن",
   [False, "هأنا", "ها أنا"],
   [False, "هأنذا", "ها أَنَذا"]
]

_sp8 = ["لكن",
	   [False, "لكنا", "لاكِنّا"],
	   [False, "لكنني", "لاكِنّني"],
	   [False, "لكن", "لاكِنْ"],
	   [True, "لكن", "لاكِنّ"]
	]

_sp9 = ["",
   [False, "طه", "طاها"],
   [False, "عمرو", "عَمْر"],
   [False, "هؤلاء", "هاؤلاء"]
]

_sp10 = ["",
   [False, "داود", "دَاوُود"],
   [True, "طاوس", "طَاوُوس"],
   [False, "الطاوس", "اطْطَاوُوس"],
   [True, "إله", "إلاه"],
   [False, "الإله", "الْإلاه"],
   [False, "رحمن", "رَحْمان"],
   [False, "الرحمن", "ارْرحْمان"]
]

SpWords = [_sp1, _sp2, _sp3, _sp4, _sp5,  _sp6,  _sp7,  _sp8,  _sp9,  _sp10]

NotLaken = ["لْ","لِ","لُ","لّ","كْ","كَ","كُ","كّ","نَ","نُ"]
HoaHea = ["أهي", "أهو", "فهي", "فهو", "وهي", "وهو", "هي", "هو"]
Twos = ["لم", "أب", "دم", "أخ", "حم", "يك", "ىك", "مع"]

Func FixSpWords(words)
	L = len(words)
	for i = 1 to L 
		words[i] = FixSpWord(words[i])
	next
Endfunc

Func FixSpWord(aWord)
	//Note: تصحيح خطأ إملائي شائع
	if aWord.EndsWith("انا")
		L = len(aWord)
		if L = 3
			aWord.SetCharAt(1, "أ")
			return aWord
		elseif L = 4 and aWord.Startswith("و") Or aWord.Startswith("ف")
			aWord.SetCharAt(2, "أ")
			return aWord
		EndIf
	EndIf

	pos = aWord.IndexOf("مائ", 1) 
   if pos > 0 and pos < aWord.Length - 2
		hrf = aWord[pos + 3]
      if hrf = "ة" or hrf = "ت" return aWord.RemoveAt(pos + 1, 1) end
	end

   if find(HoaHea, aWord.Text) > 0 return aWord + Letters.Fat7ah end 
      
   n = LastTashkeelLength(aWord)
   word = aWord.RemoveTashkeel()
	wordLength = word.Length

	if word = "طه" return new aString("طاها") end

   if not word.EndsWith("آ")
      if n = 0 and wordLength = 2 
	      if find(Twos, word.Text) > 0 
	         return aWord
	      elseif word = "هو" or word = "هي"
	         return word + Letters.Fat7ah
	      elseIf not word.EndsWithAny(["ا", "ى", "ي", "و"])
	         return word + Letters.Sokon
	      end 
	   elseif wordLength = 1 or (wordLength = 3 and find(HoaHea, word.Text) > 0)
      	return aWord
      end		        
   end

	spGroupsCount = len(SpWords)
	lastTashk = aWord.Right(n)

	for gpIdx = 1 to spGroupsCount
		SpGroup = SpWords[gpIdx]
		if gpIdx < 9 
			if word.IndexOf(SpGroup[1], 1) = 0 Loop end
			if gpIdx = 6 
				if aWord.IndexOfAny(["ذْ", "لّ"], 1) > 0 return aWord end
			ElseIf gpIdx = 8 
				k = aWord.Right(2)
				if k = "كَ" or k = "كِ"
					pos = aWord.RemoveLast(2).IndexOfAny(NotLaken, 1)				
				else
					pos = aWord.IndexOfAny(NotLaken, 1)
				end
				if pos > 0 return aWord end
			end
		end

		spCount = len(SpGroup)
		for idx = 2 to spCount
			spInfo = SpGroup[idx]
			canHasSuffex = spInfo[1]
		   spWord = new aString(spInfo[2])
		   spWordLength = spWord.Length 
		   newWord =  new aString(spInfo[3])
		      
		   pos = word.IndexOf(spWord, 1)
		       
			if pos > 0
		      pfxLen = pos - 1
		      if pfxLen > 3 Loop end

			   pfx = Word.Left(pfxLen)
		      if pfxLen > 0 and find(prefixes[pfxLen], pfx.Text) = 0 Loop End

		      sfxLen = wordLength - spWordLength - pfxLen
		      if sfxLen = 0 
		         return AddlastTashkeel(pfx + newWord, lastTashk)
		      Elseif sfxLen < 5
					sfx = Word.RightStr(sfxLen)
					if canHasSuffex = True and sfxLen < 4
						j = find(AbsSuffixes[sfxLen], sfx)
						if j > 0 
							w = pfx + newWord + Suffixes[sfxLen][j]
							return AddlastTashkeel(w, lastTashk) 
						end
					end
					if gpIdx = spGroupsCount
						j = find(AbsRelativeSuffixes[sfxLen], sfx)
						if j > 0 
							w = pfx + newWord + RelativeSuffixes[sfxLen][j]
							return AddlastTashkeel(w, lastTashk) 
						end
					end
		      end 
		    elseif gpIdx < 4 or (gpIdx = 10 and spWord.left(1) = "ا")
				 Result = LamOrMadd(word, SpWord)
				 pos = Result[1]
		       if pos < 1 or pos > 3 Loop End

				 first = word[pos]
				 if (first != "ل" and first != "آ") Loop end

			    pfx = Word.Left(pos)
		       if first = "آ" 
		          w2 = pfx.RemoveLastStr(1) + "أ"
					 i = find(prefixes[pos], w2)
		       else
					 i = find(prefixes[pos], pfx.Text)
		       end

		       if i > 0
					 sfxLen = wordLength - (spwordLength - Result[2]) - pos
					 if sfxLen = 0
						 return AddlastTashkeel(pfx + newWord.RemoveFirst(1), lastTashk) 
					 elseif gpIdx = spGroupsCount and sfxLen < 5
						 sfx = Word.RightStr(sfxLen)
						 j = find(AbsRelativeSuffixes[sfxLen], sfx)
						 w = pfx + newWord.RemoveFirst(1) + RelativeSuffixes[sfxLen][j]
						 if j > 0 return AddlastTashkeel(w, lastTashk) end
					 end
		       end
		    end
		Next
		if gpIdx < 9 return aWord end  
	Next
	return aWord
EndFunc

func LastTashkeelLength(aWord)
    L = len(aWord)
    n = 0
    for i = L to 1 step -1
        if IsTashkeel(aWord[i])
            n++
        else
            return n
        end
   next
EndFunc

func LamOrMadd(word, spWord)
	madd = spWord.ReplaceAt(1, 1, "آ")
	pos = word.IndexOf(madd, 1)
	if pos return [pos, 1] end

	if spWord = "الله"
		pos = word.IndexOf(spWord.RemoveFirst(2), 1) 
		if pos return [pos - 1, 2] end
	end

	pos = word.IndexOf(spWord.RemoveFirst(1), 1) 	// لام
	return [pos - 1, 1] 
EndFunc

func AddlastTashkeel(word, lastTashk)
   if lastTashk = "" or word.Right(1) = "ا"
      return word
   elseif IsTashkeel(word.RightStr(1))
		return word.RemoveLast(1) + lastTashk
	else
		return word + lastTashk
	end
EndFunc

