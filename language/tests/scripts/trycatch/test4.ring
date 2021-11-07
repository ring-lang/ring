# This test is based on Ring Code written by Mohammad Hamdy Ghanem in 17/01/2021

Letters = new LetterNames
TestTarget = ""

AssertError(func(){x = 1/0}, 1, "index < 1")

str = new aString("Test")
AssertError(func(){str.Mid(0, 1).Text}, 2, "index < 1")

func SetTestTarget(targerName)
	TestTarget = targerName
	? "Testing " + targerName + ":"

func AssertEqual(testNum, value1, value2)
	If value1 != value2
		msg = "" + value1 + "' and '" + value2 + "' are not equal!"
		raise(TestTarget + " Test" + testNum + " failed: '" + nl + msg)
	end

	? "  Test" + testNum + " OK."


func AssertError(testCode, testNum, whenMsg)
	raisedErr = false
	try
		call testCode() 
	catch
		raisedErr = true
	end

	if raisedErr
	  	? "  Test" + testNum + " OK."
	else
		msg = "Must raise error when " + whenMsg
		raise(TestTarget + " Test" + testNum + " failed: " + nl + msg)
	end


func PassedTest()
	? ""
	? TestTarget + " passed all tests."
	? "---------"
	? ""

Func IsTashkeel(hrf)
	return strcmp(hrf,"ً") >= 0 and strcmp(hrf,"ْ") <= 0 


Func IsALetter(hrf)
	return (strcmp(hrf, "ء") >= 0 and strcmp(hrf, "غ") <= 0 ) or
		(strcmp(hrf, "ف") >= 0 and strcmp(hrf, "ي") <= 0 )
   

Func IsAChar(hrf)
	return IsALetter(hrf) or IsTashkeel(hrf)

func IsAString(obj)
	If type(obj) = "OBJECT" and classname(obj) = "astring"
		return true
	else
		return false
	end

Class aString
	Length
	Text
	
	func init(str)
		L = len(str)
		if IsAString(str)
			For i = 1 to L
				LstText + str.LstText[i]
			next
		else			
			For i = 1 to L
				c = str[i]
				if ascii(c) < 128
					LstText + c
				else
					i++
					LstText + (C + str[i])
				end
			next
		end
	
	func GetLength()
		return len(LstText)


	func setText(str)
		LstText = []
		init(str)


	func getText()   
		return SubStr(1, len(LstText))

	func ToString()
		return getText()

	func Append(str)
		init(str)

	func AppendFrom(str, stratAt, endAt)
		if IsAString(str)
			newStr = str
		else			
			newStr = new aString(str)
		end

		For i = stratAt to endAt
			LstText + newStr.LstText[i]
		next


	func Right(charCount)
		if charCount = 0 return new aString end
		AssertPos("charCount", charCount)
		newS = 	new aString
		L = len(LstText)
		CopyTo(newS.LstText	,  L - charCount + 1, L)
		return newS


	func RightStr(charCount)
		if charCount = 0 return "" end
		AssertPos("charCount", charCount)
		L = len(LstText)
		return SubStr(L - charCount + 1, charCount)


	func Left(charCount)
		if charCount = 0 return new aString end
		AssertPos("charCount", charCount)
		newS = 	new aString
		CopyTo(newS.LstText	, 1, charCount)
		return newS

	
	func LeftStr(charCount)
		if charCount = 0 return "" end
		AssertPos("charCount", charCount)
		return SubStr(1, charCount)


	func RemoveFirst(charCount)
		return Right(Len(LstText) - charCount)


	func RemoveFirstStr(charCount)
		return RightStr(Len(LstText) - charCount)

	func RemoveLast(charCount)
		return Left(Len(LstText) - charCount)

	func RemoveLastStr(charCount)
		return LeftStr(Len(LstText) - charCount)

	Func RemoveAt(startAt, charCount)
		L = Len(LstText)
		st2 = startAt + charCount
		if StartAt = 1
			return Right(L - charCount)
		elseif st2 > L
			return Left(startAt - 1)				
		else
			newS = new aString
			CopyTo(newS.LstText, 1, startAt - 1)
			CopyTo(newS.LstText, st2, L)
			return newS
		end

	 Func RemoveAtStr(startAt, charCount)
		L = Len(LstText)
		st2 = startAt + charCount
		if StartAt = 1
			return SubStr(charCount + 1, L - charCount)
		elseif st2 > L
			return SubStr(1, startAt - 1)				
		else
			newS = new aString
			CopyTo(newS.LstText, 1, startAt - 1)
			CopyTo(newS.LstText, st2, L - st2 + 1)
			return newS.SubStr(1, L - charCount)
		end


	Func Remove(str)
		If IsAString(str)
			s = str
		else
			s = new aString(str)
		end

		n = len(s.LstText)
		L = Len(LstText)
		pos = 1
		newS = new aString

		while True
			i =  indexOf(s, pos)	
			if i = 0 
			CopyTo(newS.LstText, pos, L)               
			return newS 
		end

		if i > pos { CopyTo(newS.LstText, pos, i - 1)}
			pos = i + n
			if pos > L return newS end
		end


	Func RemoveStr(str)
		return Remove(str).Text


	func ReplaceAt(startAt, charCount, repWith)
		newS = new aString
		L = Len(LstText)
 		st2 = startAt + charCount
		if StartAt = 1
			newS.Append(repWith)
			CopyTo(newS.LstText, St2, L)
		elseif st2 > L
			CopyTo(newS.LstText, 1, startAt - 1)
			newS.Append(repWith)				
		else
			CopyTo(newS.LstText, 1, startAt - 1)
			newS.Append(repWith)
			CopyTo(newS.LstText, st2, L)
		end	
	
		return newS


	func ReplaceAtStr(startAt, charCount, repWith)		
		return ReplaceAt(startAt, charCount, repWith).Text


	func Insert(str, pos)
		If IsAString(str)
			s = str
		else
			s = new aString(str)
		end
            
		L = Len(LstText)
		newS = new aString

		if pos = L + 1 
			newS.LstText = LstText
			newS.Append(s) 
		elseif pos = 1
			newS.Append(s)
			CopyTo(newS.LstText, 1, L)
		else
			AssertPos("pos", pos)
			CopyTo(newS.LstText, 1, pos -1) 
			newS.Append(s)
			CopyTo(newS.LstText, pos, L)
		end
		return newS

	func InsertStr(str, pos)
		return Insert(str, pos).Text


	func SetCharAt(index, chr)
		AssertPos("index", index)
		newS = new aString(self)		
		if IsAString(chr) 
			if chr.Length != 1 
				Raise("you can set exactly one char only.") 
			end
			newS.LstText[index] = chr.LstText[1]
		else
			L = len(chr)
			if L = 0 or L > 2 or ascii(chr[1]) < 128 
				Raise("you can set exactly one char only.") 
			end
			newS.LstText[index] = chr
		End
		return newS


	func SetCharAtStr(index, chr)
		return SetCharAt(index, chr).Text


	func Mid(startAt, charCount)
		AssertPos("startAt", startAt)
		AssertPos("charCount", charCount)
		if startAt + charCount - 1 > Len(LstText)
		raise("The sub string exceeds the str length")
		end
		newS = new aString
		CopyTo(newS.LstText, startAt, startAt + charCount - 1)
		return newS

	func MidStr(startAt, charCount)
		AssertPos("startAt", startAt)
		AssertPos("charCount", charCount)
		if startAt + charCount - 1 > len(LstText)
		raise("The sub string exceeds the str length")
		end
		return SubStr(startAt, charCount)
	
	func IndexOf(str, startAt)
		AssertPos("startAt", startAt)     
		if IsAString(str) 
			s = str
		else
			s = new aString(str)
		end
		n = len(s.LstText)
		L = Len(LstText) 
		if n > L or n = 0 return 0 end
		L = L - n + 1
		For i = startAt to L
			found = 0
			For j = 1 to n
				if LstText[i + j - 1] = s.LstText[j]
					found += 1
				else
					Exit
				end
			Next

			if found = n return i end
		Next
		return 0
			

	func IndexOfAny(lstStr, startAt)
		L = len(lstStr)
		for i = 1 to L
			result = IndexOf(lstStr[i], startAt)
			if result return result end
		next
		return 0


	func operator(op, param)
		switch op
			case "[]"
				if not type(param) = "NUMBER"
					 param = Number(param)
					 If isNull(param)
					    raise("Index must be a number")
					 end
				 end
		 		 AssertPos("index", param)
				 return LstText[param]

			case "len"
				return len(LstText)

			case "+"
				newS = new aString
				newS.LstText = LstText
				newS.append(param)
				return newS

			case "="
				return CompareTo(param) = 0
			case "!="
				return CompareTo(param) != 0
			case "<"
				return CompareTo(param) < 0
			case "<="
				return CompareTo(param) < 1
			case ">"
				return CompareTo(param) > 0
			case ">="
				return CompareTo(param) > -1
		end


	func CompareTo(str)
		if IsAString(str) 
			s = str
		else
			s = new aString(str)
		end
		L1 = Len(LstText)
		L2 = len(s.LstText)
		L = min(L1, L2)
		For i = 1 to L
			v = strcmp(LstText[i], s.LstText[i])
			if v != 0 return v end
		Next
		if L1 = L2 
			return 0
		elseIf L1 > L2
			return 1
		else
			return -1
		end


#---------Arabic Methods---------------	
	Func RemoveTashkeel()
		newS = new aString
		L = Len(LstText)
	
		For i = 1 to L 
			a = LstText[i]
			If not IsTashkeel(a)
				newS.Append(a)
			end
		Next
		Return newS
	
	
	Func AddTashKeel(fromWazn)
		if IsAString(fromWazn)
			Wazn = fromWazn
		else
			Wazn = new AString(fromWazn)
		end

		word = new AString
		AbsWazn = Wazn.RemoveTashkeel()
		L = Len(Wazn.LstText)
		L2 = Len(LstText)
	
		start = 1
		n = 1
		For i = 2 To L
			tsh = Wazn.LstText[i]
			If IsTashkeel(tsh)
				if n > 0
					s = mid(start, n)
					n = 0
					word.append(s)	           
					start += Len(s.LstText)
				end
				Word.append(tsh)
				if start > L2 Exit End
			else
				n += 1	
			End
		Next
	
		If L2 > start
			word.append(Right(L - start + 1))
		end

	Return Word
	   

	Func GetLines()
		Lines = []
	        line = new aString
        	Lf = char(10)
	        Cr = char(13)
		L = Len(LstText)
		For i = 1 to L
			c = LstText[i]
			If c != Lf and c != Cr and c != "="
				line.Append(c)
			Elseif len(line.LstText) > 0 
			If Line.HasAnyAChr()
				lines + Line
              		end
              		line.LstText = []
            	End
        Next

	If len(line.LstText) > 0
		If Line.HasAnyAChr()
			lines + Line
		end
        End
        return lines
	

	Func GetWords()
        	words = []
        	word = new aString
		L = Len(LstText)
		For i = 1 to L
			c = LstText[i]
			If IsAChar(c)
				word.Append(c)
			ElseIf c != Letters.Kashida and len(word.LstText) > 0
			words + word
			word.LstText = []
		End
        Next

	If len(word.LstText) > 0
		words + word
        End
        return words

	func HasAnyAChr()
        	L = Len(LstText)
        	For i = 1 to L
			if IsAChar(LstText[i]) return true end
		next
        	return false

	private
		
		LstText = []
	
	func SetLength()

	func CopyTo(lst2, startAt, stopAt)
		for i = startAt to stopAt
			lst2 + LstText[i]
		next

	func SubStr(startAt, charCount)
		L = 0
		L1 = startAt + charCount - 1
		for i = startAt to L1
			L += len(LstText[i])
		next

		_str = space(L)
		idx = 0

		for j = startAt To L1
			x = LstText[j]
			L2 = len(x)
			for i = 1 to L2
				idx++
				_str[idx] = x[i]
			next
		next
		return _str
		

	func AssertPos(paramName, value)
		if value < 1
			raise(paramName + " must be > 0")
		end
	
		if value > Len(LstText)
			raise(paramName + " must not exceed the string Length")
		end

class LetterNames
	Kashida = "ـ"
	Sokon = "ْ"
	Shaddah = "ّ"
	Fat7ah = "َ"
	TanweenFat7 = "ً"
	Dammah = "ُ"
	TanweenDamm = "ٌ"
	Kasrah = "ِ"
	TanweenKasr = "ٍ"
	Aleph = "أ"
	AlephMadd = "ا"
	AlephLayyenah = "ى"
	AlephMaksor = "إ"
	HamzetMadd = "آ"
	Waw = "و"
	Yaa = "ي"
	Lam = "ل"
	Hamzah = "ء"
	Haa = "ه"
	Noon = "ن"
